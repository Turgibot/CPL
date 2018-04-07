%{
#include <malloc.h>
#include <stdio.h>
#include "shared.h"
#include "errors.h"
#include "symboles.h"
#include "code_gen.h"
extern int yylex();
extern int yyparse();
char *myout;
%}

%union {

	struct parserTree{
		char *code;
		int type;
		char *head;
		char* label;
	}Ptree;

	struct declTree{
		char *code;
		int type;
		int count;
		char *label;
	}Dtree;

	struct number{
		int type;
		union {
			int ival;
			float fval;
		}val;
	}num;

	char sign1;
	char sign2 [3];	
	char sign3 [4];	
	char *strVal;
}

%token <num> num// type int or float
%token <sign1> addop mulop
%token <sign2> orop andop assignop relop 
%token <sign3> toop
%token <strVal> sentence id
%token CASE CONST DEFAULT READ ELSE FOR IF STEPOP INT PROGRAM LOOP PRINT _BEGIN STRING FLOAT SWITCH END VAR WHILE WHEN BREAK  
%start PROGRAM_BLOCK
%type <Ptree> FACTOR DECLARATIONS TERM EXPRESSION CHOICE CASES STEP SWITCH_ROLL READ_STMT BOOLFACTOR BOOLTERM BOOLEXPR STMTLIST STMT ASSIGNMENT_STMT CONTROL_STMT WRITE_STMT STMT_BLOCK
%type <Dtree> PROGRAM_BLOCK TYPE DECL DECLARLIST CDECL

%%
PROGRAM_BLOCK : PROGRAM id DECLARATIONS _BEGIN STMTLIST END 
{
	FILE* file;
	char names[] = "Guy Tordjman and Shimon Genish";
	
	freeAllSymbol();
	if(eCount==1)
	{
		file=fopen(myout,"w");
		fprintf(file,"#%s\n\n",names);
		fprintf(file,".data\n%s\n",$3.code);
		fprintf(file,"%s\n.text \n%s\n",$5.head,$5.code);
		printf("Compilation Complete Succesfuly.\n");
		fclose(file);
	}
	else
	{
		printf("Compilation Complete With %d Errors.\n",eCount-1);
	}

	eCount=0;
	free($3.code);
	free($5.code);
};

DECLARATIONS: VAR DECLARLIST CDECL 
{
	$$.code=StringCat($2.code,$3.code);
	free($2.code);
	free($3.code);
}
| 
{
	$$.code=strdup("");
};

/*--------------------------------------------------------------------------------------------*/
/*
	the rule can throw exception if:
	1. var is already defined.
	2. there is a syntax, paring or semantic error.
*/
DECLARLIST: DECLARLIST id DECL
{
	sym* s=findSym($2);
	char inst[100];
	if(s==NULL)
	{
		add2Sym($2,$3.type,$3.count,$3.label,0);
		sprintf(inst,"%s : .space %d\n",$3.label,($3.count+1)*4);												
	}
	else
	{
		s->used=0;
		sprintf(inst,"'%s' is already defined.", $2);
		SemanticError(inst);	
		sprintf(inst,"%s : .space %d\n",$3.label,($3.count)*4);
	}
	$$.code = StringCat($1.code,inst);
	free($1.code);
	free($3.label);
} 
| id DECL 
{
	sym* s=findSym($1);
	char inst[100];
	if(s==NULL)
	{
		add2Sym($1,$2.type,$2.count,$2.label,0);
		sprintf(inst,"%s : .space %d\n",$2.label,($2.count+1)*4);
		$$.code = strdup(inst);
		free($2.label);

	}
	else
	{
		s->used=0;
		sprintf(inst,"'%s' is already defined.", $1);
		SemanticError(inst);	
		sprintf(inst,"%s : .space %d\n",$2.label,($2.count)*4);
		$$.code = strdup(inst);
		free($2.label);
	}
}; 

/*--------------------------------------------------------------------------------------------*/

/*
	the rule can throw exception if:
	1. var is already defined.
	2. there is a syntax, paring or semantic error.
*/
DECL : ',' id DECL 
{
	sym* s=findSym($2);
	char inst[100];
	if(s==NULL)
	{
		add2Sym($2,$3.type,$3.count,$3.label,0);
		$$.label=$3.label;
		$$.count=$3.count+1;
		$$.type=$3.type;
	}
	else
	{
		s->used=0;
		$$.label=$3.label;
		$$.count=$3.count;
		$$.type=$3.type;
		sprintf(inst,"%s is already defined", $2);
		SemanticError(inst);	
	}
}
| ':' TYPE ';' 
{
	$$.type=$2.type;
	$$.count=0;
	$$.label=$2.label
}
| {ParsingError("expected ':'.");} error ';' 
{
	$$.type=strdup("");
	$$.count=0;
	$$.label=strdup("")
}; 

/*--------------------------------------------------------------------------------------------*/
 
TYPE : INT 
{
	$$.label = newLabel();
	$$.type = int_;
	$$.count = 0;
}
| FLOAT
{
	$$.label = newLabel();
	$$.type = float_;
	$$.count = 0;
}
| STRING {
	$$.label = newLabel();
	$$.type = string;
	$$.count = 0;
} 
| { ParsingError("type is incorrect");} error 
{
	$$.label = strdup("");
	$$.type = -1;
	$$.count = 0;
}; 

/*--------------------------------------------------------------------------------------------*/

CDECL:  CONST TYPE id assignop num ';' CDECL
{ 
	sym* s;
	char inst[100];
	$$.code=strdup("");
	if($2.type!=string)//string cant be const
	{
		s=findSym($3);
		if(s==NULL)//check if it already exist
		{
			//if exist in sym table			
			if($5.type==int_ && $2.type==int_)
			{
				sprintf(inst,"%s : .word %d\n",$2.label,$5.val.ival);
				s= add2Sym($3,$2.type,$2.count,$2.label,1);
			}
			else if($5.type==int_ && $2.type==float_)
			{
				sprintf(inst,"%s : .float %d\n",$2.label,$5.val.ival);
				s= add2Sym($3,$2.type,$2.count,$2.label,1);
			}
			else if($5.type==float_ && $2.type==float_)
			{
				sprintf(inst,"%s : .float %f\n",$2.label,$5.val.fval);
				s= add2Sym($3,$2.type,$2.count,$2.label,1);
			}
			else
			{
				SemanticError("can't assign float into int var");
				sprintf(inst,"");
			}
			if(s!=NULL)
			{
				s->haveVal=1;
				s->used=0;
				free($$.code);
				$$.code=StringCat(inst,$7.code);
			}
		}
		else
		{
			sprintf(inst,"%s is already defined", $3);
			SemanticError(inst);
		}
	}
	else
	{
		SemanticError("string can't be const");
	}
	free($2.label);
}
| CONST TYPE id assignop num {ParsingError("expected: ';'");} error  CDECL
{
	$$.code=strdup("");
}
| 
{
	$$.code =strdup("");
};

/*--------------------------------------------------------------------------------------------*/

STMTLIST: STMTLIST STMT 
{
	$$.code=StringCat($1.code,$2.code);
	$$.head=StringCat($1.head,$2.head);
	free($1.head);
	free($1.code);
	free($2.head);
	free($2.code);
}
| 
{
$$.code=strdup("");
$$.head=strdup("");
};

/*--------------------------------------------------------------------------------------------*/

STMT:ASSIGNMENT_STMT 
{
	$$.code = $1.code;
	$$.head=$1.head;
}
| id assignop sentence ';' 
{
	sym* s=findSym($1);
	char inst[200];
	char *label;
	$$.head=strdup("");
	$$.code=strdup("");
	if(s!=NULL)
	{
		if(s->type==string)
		{
			free($$.head);free($$.code);
			label=newLabel();
			sprintf(inst,"%s: .asciiz \"%s\"\n",label,$3);
			$$.head=strdup(inst);
			sprintf(inst,"la $s0,%s\nla $s1,%s\nsw $s0,%d($s1)\n",label,s->label,s->index*4);
			$$.code=strdup(inst);
			free(label);
			s->haveVal=1;
		}
		else
		{
			sprintf(inst,"%s is a number, can't assign string in it",$1);
			SemanticError(inst);
			
		}
	}
}
| id assignop sentence {ParsingError("expected: ';'");} error
{
	$$.head=strdup("");
	$$.code=strdup("");
}
| id  error {ParsingError("expected: ':='");} sentence ';'
{
	$$.head=strdup("");
	$$.code=strdup("");
}
| CONTROL_STMT 
{
	$$.code = $1.code;
	$$.head=$1.head;
}
| READ_STMT 
{
	$$.code = $1.code;
	$$.head=$1.head;
}
| WRITE_STMT 
{
	$$.code = $1.code;
	$$.head=$1.head;
}
| STMT_BLOCK 
{
	$$.code = $1.code;
	$$.head=$1.head;
};

/*--------------------------------------------------------------------------------------------*/

WRITE_STMT: PRINT '(' EXPRESSION ')' ';' 
{
	char inst[200];
	if($3.type==int_)
		sprintf(inst,"li $v0,1\nmove $a0,$t2\n syscall\n");
	else if ($3.type==float_)
		sprintf(inst,"li $v0,2\nmov.s $f12,$f2\n syscall\n");
	else if($3.type==string)
		sprintf(inst,"li $v0,4\nmove $a0,$t2\nsyscall\n");
	$$.code=StringCat($3.code,inst);
	free($3.code);
	$$.head=$3.head;
}
| PRINT  error {ParsingError("expected '('.");} EXPRESSION ')' ';'
{
	$$.code = strdup("");
	$$.head=strdup("");
}
| PRINT '(' EXPRESSION error {ParsingError("expected ')'.");}  ';'
{
	$$.code = strdup("");
	$$.head=strdup("");
}
| PRINT '(' EXPRESSION ')'  error {ParsingError("expected ';'.");}
{
	$$.code = strdup("");
	$$.head=strdup("");
}
| PRINT '(' sentence ')' ';' 
{
	char inst[200];
	char* label = newLabel();
	sprintf(inst,"%s: .asciiz \"%s\"\n",label,$3);
	$$.head=strdup(inst);
	sprintf(inst,"li $v0,4\nla $a0,%s\nsyscall\n",label);
	$$.code=strdup(inst);
	free(label);
};

/*--------------------------------------------------------------------------------------------*/

READ_STMT: READ '(' id ')' ';'
{
	char inst[100];
	char* str,*tmp;
	int x=0;
	sym* s=findSym($3);
	if(s!=NULL)
	{
		if(!s->constant)
		{
			if(s->type==int_)
				x=5;
			else if(s->type==float_)
				x=6;
			else
			{
				sprintf(inst,"'%s' is string type, can't read string from user!",$3);
				SemanticError(inst);	
			}
		}
		else
		{
			sprintf(inst,"'%s' is constant variable, can't change his value!",$3);
			SemanticError(inst);	
		}
		if(x)
		{
			s->haveVal = 1;
		}
	}
	if(x)
	{
		sprintf(inst,"li $v0,%d\nsyscall\n",x);
		tmp=StringCat("la $s0,",s->label);
		str=StringCat(inst,tmp);
		free(tmp);
		if(x==5)
			sprintf(inst,"\nsw $v0,%d($s0)\n",s->index*4);
		else if(x==6)
			sprintf(inst,"\nswc1 $f0,%d($s0)\n",s->index*4);
		tmp=str;
		str = StringCat(str,inst);
		free(tmp);
		$$.code =str;
	}
	else
		$$.code=strdup("");
	$$.head=strdup("");
}
| READ {ParsingError("expected '('.");} error id ')' ';'
{
	$$.code = strdup("");
	$$.head=strdup("");
}
| READ '(' {ParsingError("expected id.");} error  ')' ';'
{
	$$.code = strdup("");
	$$.head=strdup("");
}
| READ '(' id {ParsingError("expected ')'.");} error ';'
{
	$$.code = strdup("");
	$$.head=strdup("");
}
| READ '(' id ')' {ParsingError("expected ';'.");} error
{
	$$.code = strdup("");
	$$.head=strdup("");
};

/*--------------------------------------------------------------------------------------------*/

ASSIGNMENT_STMT: id assignop EXPRESSION ';'
{
	//check if id exist and not const and set that have value
	char inst[100];
	char* str,*tmp;
	sym* s=findSym($1);
	if(s!=NULL)
	{
		if(!s->constant)
		{
			if(s->type==$3.type)
			{
				str= StringCat("la $s0,",s->label);
				if(s->type==float_)
					sprintf(inst,"\nswc1 $f2,%d($s0)\n",s->index*4);	
				else
					sprintf(inst,"\nsw $t2,%d($s0)\n",s->index*4);
				tmp = StringCat(str,inst);
				$$.code=StringCat($3.code,tmp);
				free(tmp);free(str);
				s->haveVal=1;
			}
			else if (s->type==float_) //first id float, second id int
			{
				str= StringCat("la $s0,",s->label);		
				sprintf(inst,"\nmtc1 $t2, $f2\ncvt.s.w $f2, $f2\nswc1 $f2,%d($s0)\n",s->index*4);
				tmp = StringCat(str,inst);
				$$.code=StringCat($3.code,tmp);
				free(tmp);free(str);
				s->haveVal=1;
			}
			else if(s->type==int_ && $3.type==float_)
			{
				sprintf(inst,"cannot assign (float) to identifier '%s'(int).", s->name);
				SemanticError(inst);	
				$$.code=StringCat($3.code,"");
			}
			else
			{
				sprintf(inst,"cannot assign to identifier '%s', types are not match.", s->name);
				SemanticError(inst);	
				$$.code=StringCat($3.code,"");
			}
		}
		else
		{
			sprintf(inst,"%s is declared as const, and cannot be override.",$1);
			SemanticError(inst);
		}
	}
	else
	{
		sprintf(inst,"\nSemantic Error: identifier '%s' is undefined.", $1);
		yyerror(inst);	
		$$.code=StringCat($3.code,"");
	}
	free($3.code);
	$$.head=$3.head;
}| id error {ParsingError("expected ':='.");}  EXPRESSION ';'
{
	$$.code = strdup("");
	$$.head=strdup("");
}
| id assignop EXPRESSION error {ParsingError("expected ';'.");}
{
	$$.code = strdup("");
	$$.head=strdup("");
};

/*--------------------------------------------------------------------------------------------*/

CONTROL_STMT: IF '(' BOOLEXPR ')' STMT ELSE STMT 
{
	char *str,*tmp;
	char* labelFalse=newLabel();
	char* labelOut=newLabel();		
	char inst[100];
	sprintf(inst,"beq $t1,$0,%s\n",labelFalse);
	str=StringCat(inst,$5.code);
	sprintf(inst,"j %s\n%s: ",labelOut,labelFalse);
	tmp=StringCat(str,inst);
	free(str);
	str=StringCat(tmp,$7.code);
	free(tmp);
	sprintf(inst,"%s:\n",labelOut);
	$$.code=StringCat(str,inst);
	free(str);
	str=StringCat($3.code,$$.code);
	free($$.code);
	free($3.code);
	$$.code=str;
	free($5.code);
	free($7.code);
	str=StringCat($5.head,$7.head);
	free($7.head);
	free($5.head);
	$$.head=StringCat($3.head,str);
	free($3.head);
	free(str);
	free(labelFalse);
	free(labelOut);
}
|  IF {ParsingError("expected '('.");} error ')' STMT ELSE STMT 
{
	$$.code=strdup("");
	$$.head=strdup("");
	free($5.code);
	free($7.code);
	free($5.head);
	free($7.head);
}
|  IF '('  error {ParsingError("IF statment expected an boolean expression.");} ')' STMT ELSE STMT 
{
	$$.code=strdup("");
	$$.head=strdup("");
	free($6.code);
	free($6.head);
	free($8.code);
	free($8.head);
}
|  IF '(' BOOLEXPR {ParsingError("expected ')'.");} error STMT ELSE STMT 
{
	$$.code=strdup("");
	$$.head=strdup("");
	free($6.code);
	free($8.code);
	free($6.head);
	free($8.head);
	free($3.code);
	free($3.head);
}
|  IF '(' BOOLEXPR ')' {ParsingError("IF statement expected statement.");} error 
{
	$$.code=strdup("");
	$$.head=strdup("");
	free($3.code);
	free($3.head);
}
| WHILE '(' BOOLEXPR ')' STMT_BLOCK 
{
	char* loop=newLabel();
	char* out=newLabel();
	char* str,*tmp;
	char inst[100];
	sprintf(inst,"beq $t1,$0,%s\n",out);
	str=StringCat($3.code,inst);
	free($3.code);
	sprintf(inst,"%s: ",loop);
	tmp=StringCat(inst,str);
	free(str);
	str=StringCat(tmp,$5.code);
	free(tmp);
	free($5.code);
	sprintf(inst,"j %s\n%s: \n",loop,out);
	$$.code=StringCat(str,inst);
	free(str);
	$$.head=StringCat($3.head,$5.head);
	free($3.head);
	free($5.head);
}
| WHILE {ParsingError("expected '('.");} error BOOLEXPR ')' STMT_BLOCK 
{
	$$.code=strdup("");
	$$.head=strdup("");
	free($4.head);
	free($4.code);
	free($6.head);
	free($6.code);
}
| WHILE '(' error {ParsingError("WHILE statment expected an boolean expression.");} ')' STMT_BLOCK 
{
	$$.code=strdup("");
	$$.head=strdup("");
	free($6.head);
	free($6.code);
} 
| WHILE '(' BOOLEXPR {ParsingError("expected ')'.");} error STMT_BLOCK 
{
	$$.code=strdup("");
	$$.head=strdup("");
	free($3.head);
	free($3.code);
	free($6.head);
	free($6.code);
}	
| FOR '(' ASSIGNMENT_STMT ';' BOOLEXPR ';' STEP ')' STMT
{
	char* loop=newLabel();
	char* out=newLabel();
	char* str,*tmp;
	char inst[100];
	sprintf(inst,"beq $t1,$0,%s\n",out);
	str=StringCat($5.code,inst);free($5.code);
	sprintf(inst,"%s: ",loop);
	tmp=StringCat(inst,str);free(str);
	str=StringCat(tmp,$9.code);
	free(tmp);
	free($9.code);
	tmp=StringCat(str,$7.code);free($7.code);free(str);
	sprintf(inst,"j %s\n%s: \n",loop,out);
	str=StringCat(tmp,inst);free(tmp);
	$$.code=StringCat($3.code,str);
	free(str);
	free($3.code);
	str=StringCat($3.head,$5.head);
	free($3.head);
	free($5.head);
	tmp=StringCat($7.head,$9.head);
	free($7.head);
	free($9.head);
	$$.head=StringCat(str,tmp);
	free(str);
	free(tmp);
}
| FOR {ParsingError("expected '('.");} error ASSIGNMENT_STMT ';' BOOLEXPR ';' STEP ')' STMT
{
	free($4.code);
	free($6.code);
	free($8.code);
	free($10.code);
	free($4.head);
	free($6.head);
	free($8.head);
	free($10.head);
	$$.code=strdup("");
	$$.head=strdup("");
}
| FOR '(' ASSIGNMENT_STMT {ParsingError("expected ';'.");} error  BOOLEXPR ';' STEP ')' STMT
{
	free($3.code);
	free($6.code);
	free($8.code);
	free($10.code);
	free($3.head);
	free($6.head);
	free($8.head);
	free($10.head);
	$$.code=strdup("");
	$$.head=strdup("");
}
| FOR '(' ASSIGNMENT_STMT ';' BOOLEXPR {ParsingError("expected ';'.");} error  STEP ')' STMT
{
	free($3.code);
	free($5.code);
	free($8.code);
	free($10.code);
	free($3.head);
	free($5.head);
	free($8.head);
	free($10.head);
	$$.code=strdup("");
	$$.head=strdup("");
}	
| FOR '(' ASSIGNMENT_STMT ';' BOOLEXPR ';' STEP {ParsingError("expected ')'.");} error STMT
{
	free($3.code);
	free($5.code);
	free($7.code);
	free($10.code);
	free($3.head);
	free($5.head);
	free($7.head);
	free($10.head);
	$$.code=strdup("");
	$$.head=strdup("");
}
todo
1. take free register and inster first num
2. check condition 
3. run statement block 
4. run STEP
5. jump back to check


1. load symbol of id
2. initialize(store) the first num
3. loop label : condition: a. if $5 > $7 than check that id <= $7 ---> otherwise ----> go to out
4. STMT_BLOCK
5. step : update num
 
	1	2	3	4		5	6	7		8	9	10	11	
| LOOP '(' id assignop num toop num STEPOP num ')' STMT_BLOCK 
{ 
	char* loop=newLabel();
	char* out=newLabel();
	char* str,*tmp;
	char inst[100];
	
	sprintf(inst,"beq $t1,$0,%s\n",out);
	str=StringCat($4.code,inst);free($4.code);
	sprintf(inst,"%s: ",loop);
	tmp=StringCat(inst,str);free(str);
	str=StringCat(tmp,$7.code);
	free(tmp);
	free($7.code);
	tmp=StringCat(str,$5.code);free($5.code);free(str);
	sprintf(inst,"j %s\n%s: \n",loop,out);
	str=StringCat(tmp,inst);free(tmp);
	$$.code=StringCat($3.code,str);
	free(str);
	free($3.code);
	str=StringCat($3.head,$4.head);
	free($3.head);
	free($4.head);
	tmp=StringCat($5.head,$7.head);
	free($5.head);
	free($7.head);
	$$.head=StringCat(str,tmp);
	free(str);
	free(tmp);
}
| LOOP {ParsingError("expected '('.");} error ASSIGNMENT_STMT BOOLEXPR STEP ')' STMT
{
	free($4.code);
	free($5.code);
	free($6.code);
	free($8.code);
	free($4.head);
	free($5.head);
	free($6.head);
	free($8.head);
	$$.code=strdup("");
	$$.head=strdup("");
}
| LOOP '(' ASSIGNMENT_STMT BOOLEXPR STEP {ParsingError("expected ')'.");} error STMT
{
	free($3.code);
	free($4.code);
	free($5.code);
	free($8.code);
	free($3.head);
	free($4.head);
	free($5.head);
	free($8.head);
	$$.code=strdup("");
	$$.head=strdup("");
}
| SWITCH_ROLL 
{
	$$.code=$1.code;
	$$.head=$1.head;
};

/*--------------------------------------------------------------------------------------------*/

STMT_BLOCK: '{' STMTLIST '}' 
{
	$$.code =$2.code;
	$$.head=$2.head;
}
 //thats make 1 shift reduce!!
| {ParsingError("expected '{'.");} error STMTLIST '}' 
{
	free($3.code);
	free($3.head);
	$$.code = strdup("");
	$$.head = strdup("");
}
 //thats make 1 shift reduce!!
| '{' STMTLIST error {ParsingError("expected '}'.");}
{
	free($2.code);
	free($2.head);
	$$.code = strdup("");
	$$.head = strdup("");
};

/*--------------------------------------------------------------------------------------------*/

SWITCH_ROLL: SWITCH '(' CHOICE ')' '{' CASES '}' 
{
	$$.code=StringCat($3.code,$6.code);
	free($3.code);
	free($6.code);
	$$.head = StringCat($3.head,$6.head);
	free($3.head);
	free($6.head);
	free($6.label);
}
| SWITCH {ParsingError("expected '('.");} error  CHOICE ')' '{' CASES '}' 
{
	free($4.code);
	free($7.code);
	free($4.head);
	free($7.head);
	$$.code = strdup("");
	$$.head = strdup("");
}
| SWITCH '(' CHOICE {ParsingError("expected ')'.");} error  '{' CASES '}' 
{
	free($3.code);
	free($7.code);
	free($3.head);
	free($7.head);
	$$.code = strdup("");
	$$.head = strdup("");
}
| SWITCH '(' CHOICE ')' {ParsingError("expected '{'.");}  error CASES '}' 
{
	free($3.code);
	free($7.code);
	free($3.head);
	free($7.head);
	$$.code = strdup("");
	$$.head = strdup("");
};


/*--------------------------------------------------------------------------------------------*/

CHOICE: id 
{	
	sym* s = findSym($1);
	char inst[150];
	sprintf(inst,"");
	if(s!=NULL)
	{
		if(s->haveVal)
		{
			if(s->type==int_)
				sprintf(inst,"la $s0,%s\nlw $s1,%d($s0)\n",s->label,s->index*4);
			else
				SemanticError("swicth choice can't be only int");
		}
		else
		{
			sprintf(inst,"'%s' has no value.",$1);
			SemanticError(inst);
			sprintf(inst,"");
		}
		
		
	}
	else
	{
		sprintf(inst,"'%s' has not define.",$1);
		SemanticError(inst);
		sprintf(inst,"");
	}
	free($1);
	$$.code=strdup(inst);
	$$.head=strdup("");
}
| num 
{
	char inst[100];
	if($1.type==int_)
		sprintf(inst,"li $s1,%d\n",$1.val.ival);
	else
	{
		sprintf(inst,"");
		SemanticError("swicth choice can't be only int");
	}
	$$.code = strdup(inst);
	$$.head=strdup("");
}
| error
{
	ParsingError("expected id or number.");
	$$.code=strdup("");
	$$.head=strdup("");
};


/*--------------------------------------------------------------------------------------------*/

CASES: CASE num ':' STMTLIST BREAK ';' CASES 
{ 
	char* str,*tmp;
	char inst[100];
	char* next=newLabel();
	char* out=$7.label;
	$$.label=out;
	if($2.type==int_)
	{
		sprintf(inst,"li $t1,%d\nbne $s1,$t1,%s\n",$2.val.ival,next);
		str=StringCat(inst,$4.code);
		free($4.code);
		sprintf(inst,"j %s\n%s: ",out,next);
		tmp=StringCat(str,inst);
		free(str);
		$$.code=StringCat(tmp,$7.code);
		free($7.code);
		free(tmp);
	}
	else
	{
		SemanticError("case works only with int numbers");
	}
	free(next);
	$$.head=StringCat($4.head,$7.head);
	free($4.head);
	free($7.head);
}
| CASE error {ParsingError("expected num.");} ':' STMTLIST BREAK ';' CASES 
{
	free($5.code);
	free($8.code);
	free($5.head);
	free($8.head);
	$$.code = strdup("");
	$$.head = strdup("");
	$$.label=strdup("");
}
| CASE num error {ParsingError("expected ':'.");} STMTLIST BREAK ';' CASES 
{
	free($5.code);
	free($8.code);
	free($5.head);
	free($8.head);
	$$.code = strdup("");
	$$.head = strdup("");
	$$.label=strdup("");
}
| CASE num ':' STMTLIST error {ParsingError("expected 'break'.");} ';' CASES 
{
	free($4.code);
	free($8.code);
	free($4.head);
	free($8.head);
	$$.code = strdup("");
	$$.head = strdup("");
	$$.label=strdup("");
}
| CASE num ':' STMTLIST BREAK error {ParsingError("expected ';'.");} CASES 
{
	free($4.code);
	free($8.code);
	free($4.head);
	free($8.head);
	$$.code = strdup("");
	$$.head = strdup("");
	$$.label=strdup("");
}
| DEFAULT ':' STMTLIST 
{
	char* out=newLabel();
	char* str=StringCat($3.code,out);
	free($3.code);
	$$.code = StringCat(str,": \n");
	free(str);
	$$.label=out;
	$$.head=$3.head;
}
| DEFAULT error {ParsingError("expected ':'.");} STMTLIST 
{
	free($4.code);
	free($4.head);
	$$.code = strdup("");
	$$.head = strdup("");
	$$.label=strdup("");
}
| error
{
	ParsingError("switch case must have default case.");
	$$.code = strdup("");
	$$.head = strdup("");
	$$.label=strdup("");
};

/*--------------------------------------------------------------------------------------------*/
//here we have all the check that we had in the expression and assignment

STEP: id assignop id addop num 
{
	sym* s1=findSym($1);
	sym* s2=findSym($3);
	char inst[200];
	char* str,*tmp,*head;
	char* label;
	$$.head=strdup("");
	$$.code=strdup("");
	if(s1!=NULL)//check if id2 has a value and id1 not a const
	{
		if(s2!=NULL)
		{
			if(!s1->constant)
			{
				if(s2->haveVal)
				{
					if(s2->type!=string)//0 has the value of the number
					{
						if(s1->type!=string)
						{
							 label=newLabel();
							 
							 sprintf(inst,"la $s0,%s\n",s2->label);
							 if($5.type==float_)
							 {
							 	sprintf(inst,"%s: .float %f\n",label,$5.val.fval);
							 	free($$.head);$$.head=strdup(inst);
							 	sprintf(inst,"l.s $f0,%s\n",label);
								
							 }
							 else
							 {
							 	sprintf(inst,"li $t0,%d\n",$5.val.ival);
								
							 }
							 $$.type=float_;
							 str=strdup(inst);
							 if(s2->type==float_)
							 {
							 	sprintf(inst,"lwc1 $f1,%d($s0)\n",s2->index*4);
							 	tmp=StringCat(str,inst);free(str);
							 	sprintf(inst,"");
							 	if($5.type==int_)
							 	{
							 		sprintf(inst,"mtc1 $t0, $f0\ncvt.s.w $f0, $f0");
							 	}
							 	str=StringCat(tmp,inst);free(tmp);
							 	tmp=StringCat(str,"add.s $f2,$f1,$f0\n");free(str);
							 }
							 else
							 {
							 	sprintf(inst,"lw $t1,%d($s0)\n",s2->index*4);
							 	tmp=StringCat(str,inst);free(str);
							 	sprintf(inst,"");
							 	if($5.type==float_)
							 	{
							 		sprintf(inst,"mtc1 $t1, $f1\ncvt.s.w $f1, $f1");
							 		str=StringCat(tmp,inst);free(tmp);
							 		tmp=StringCat(str,"add.s $f2,$f1,$f0\n");free(str);
							 	}
							 	else
							 	{
									$$.type=int_;
							 		str=StringCat(tmp,"add $t2,$t1,$t0\n");free(tmp);
							 		tmp=str;
							 	}
							}
							sprintf(inst,"la $s0,%s\n",s1->label);
							str=StringCat(tmp,inst);free(tmp);
							if(s1->type==float_)
							{
								if($$.type==int_)
									sprintf(inst,"mtc1 $t2, $f2\ncvt.s.w $f2, $f2");
								else
									sprintf(inst,"");
								tmp=StringCat(str,inst);free(str);
								sprintf(inst,"swc1 $f2,%d($s0)\n",s2->index*4);
								free($$.code);
								$$.code=StringCat(tmp,inst);
							}
							else
							{
								tmp=str;
								if($$.type==int_)
								{
									sprintf(inst,"sw $t2,%d($s0)\n",s2->index*4);
									free($$.code);
									$$.code=StringCat(tmp,inst);
								}
								else
									SemanticError("Can't assign float expretion in int value");
								
							}
							free(tmp);
						}
						else
						{
							sprintf(inst,"'%s' is string,can't make math on strings.",$1);
							SemanticError(inst);
						}
					}
					else
					{
						sprintf(inst,"'%s' is string,can't make math on strings.",$3);
						SemanticError(inst);
					}
				}
				else
				{
					sprintf(inst,"'%s' was not initialized.",$3);
					SemanticError(inst);
				}
			}
			else
			{
				sprintf(inst,"'%s' is declerd const and can not be override.",$1);
				SemanticError(inst);
			}
		}
		else
		{
			sprintf(inst,"'%s' is undefined",$3);
			SemanticError(inst);
		}
	}
	else
	{
		sprintf(inst,"'%s' is undefined",$1);
		SemanticError(inst);
	}
	free($1);
	free($3);
};

/*--------------------------------------------------------------------------------------------*/

/* $t1 has 1 of the bool expr is true else 0
 if the left side is false continue to the right side else return false
 didnt execute the right side if the left side is true */
BOOLEXPR: BOOLEXPR orop BOOLTERM 
{
	char inst[200];
	char* labelTrue=newLabel();
	char* labelOut=newLabel();
	char* str1;
	char* str2=StringCat("\nbne $t2,$0,",labelTrue);
	sprintf(inst,"bne $t1,$0,%s\n",labelTrue);
	$$.code=StringCat($1.code,inst);
	free($1.code);
	str1=$$.code;
	$$.code=StringCat(str1,$3.code);
	free(str1);free($3.code);
	str1=$$.code;
	$$.code=StringCat(str1,str2);
	free(str1);free(str2);
	str1=$$.code;
	sprintf(inst,"\nli $t1,0\nj %s\n%s: li $t1,1\n%s:\n",labelOut,labelTrue,labelOut);
	$$.code=StringCat(str1,inst);
	free(str1);
	$$.head=StringCat($1.head,$3.head);
	free($3.head);
}
| BOOLTERM 
{
	Code c={$1.code,int_,$1.head};
	c = moveCode(c,2,1);
	$$.code=c.code;
	$$.type=c.type;
	$$.head=c.head;
};

/*--------------------------------------------------------------------------------------------*/
/* $t2 has 1 of the bool expr is true else 0
 if the left side is true continue to the right side else return false
 didnt execute the right side if the left side is false */
BOOLTERM: BOOLTERM andop BOOLFACTOR 
{
	char inst[200];
	char* labelFalse=newLabel();
	char* labelOut=newLabel();
	char* str1=StringCat("beq $t2,$0,",labelFalse);
	str1=StringCat(str1,"\n");
	char* str2=StringCat("\nbeq $t3,$0,",labelFalse);
	$$.code=StringCat($1.code,str1);
	free($1.code);
	free(str1);
	str1=$$.code;
	$$.code=StringCat(str1,$3.code);
	free(str1);
	free($3.code);
	str1=$$.code;
	$$.code=StringCat(str1,str2);
	free(str1);free(str2);
	str1=$$.code;
	sprintf(inst,"\nli $t2,1\nj %s\n%s: li $t2,0\n%s:\n",labelOut,labelFalse,labelOut);
	$$.code=StringCat(str1,inst);
	free(str1);
	$$.head=StringCat($1.head,$3.head);
	free($3.head);
}
|BOOLFACTOR 
{
	Code c={$1.code,int_,$1.head};
	c = moveCode(c,3,2);
	$$.code=c.code;
	$$.type=c.type;
	$$.head=c.head;
};

/*--------------------------------------------------------------------------------------------*/
/* $t3 has 0 of the bool expr is true else 1 */
BOOLFACTOR:  '!' '(' BOOLFACTOR ')'
{
	$$.code=StringCat($3.code,"li $t2,1\nsub $t3,$t2,$t3\n"); // $t3 =1- $t3
	free($3.code);
	$$.head=$3.head;
}

|EXPRESSION  relop  EXPRESSION  
{
	//add string case and float case
	char* str,*tmp;
	char* labelTrue,*labelOut;
	char inst[150];
	labelTrue=newLabel();
	labelOut=newLabel();
	if($1.type==int_ && $3.type==int_)
	{
		str=strdup("move $t3,$t2\n");
		tmp=StringCat($1.code,str);
		free(str);
		str=StringCat(tmp,$3.code);
		free(tmp);
		//t3 has the value of $1, t2 has the value of $3
		if(strcmp($2,"<")==0)
			tmp=strdup("slt $t2,$t3,$t2\nbgtz $t2,");
		else if(strcmp($2,">")==0)
			tmp=strdup("slt $t2,$t2,$t3\nbgtz $t2,");
		else if(strcmp($2,"<=")==0)
			tmp=strdup("sub $t2,$t2,$t3\nbgez $t2,");
		else if(strcmp($2,">=")==0)
			tmp=strdup("sub $t2,$t3,$t2\nbgez $t2,");
		else if(strcmp($2,"==")==0)
			tmp=strdup("beq $t3,$t2,");
		else if(strcmp($2,"!=")==0)
			tmp=strdup("bne $t3,$t2,");
		sprintf(inst,"%s\nli $t3,0\nj %s\n%s: li $t3,1\n%s:\n",labelTrue,labelOut,labelTrue,labelOut);
		$$.code=tmp;
		tmp=StringCat(tmp,inst);
		free($$.code);
		$$.code=StringCat(str,tmp);
		free(str);free(tmp);
	}
	else if($1.type==string || $3.type==string)
	{
		if($1.type==$3.type)
		{
			str=strdup("move $t3,$t2\n");
			tmp=StringCat($1.code,str);
			free(str);
			str=StringCat(tmp,$3.code);
			free(tmp);
			//t3 has the value of $1, t2 has the value of $3	
			if(strcmp($2,"==")==0)
				tmp=StringCat("beq $t3,$t2,",labelTrue);
			else if(strcmp($2,"!=")==0)
				tmp=StringCat("bne $t3,$t2,",labelTrue);
			else
			{
				sprintf(inst,"can't make %s between string",$2);
				SemanticError(inst);
				sprintf(inst,"");
				tmp=strdup("");
				$$.code=strdup("");
			}
			//can not check string for the other relop
			sprintf(inst,"\nli $t3,0\nj %s\n%s: li $t3,1\n%s:\n",labelOut,labelTrue,labelOut);
			$$.code=tmp;
			tmp=StringCat(tmp,inst);
			free($$.code);
			$$.code=StringCat(str,tmp);
			free(str);free(tmp);
		}
		else
		{
			SemanticError("can't compare number with string");
			$$.code=strdup("");
		}
	}
	else if($1.type==float_ || $3.type==float_)
	{
		if($1.type==float_)
			str=strdup("mov.s $f3,$f2\n");
		else //int
			str=strdup("mtc1 $t2,$f3\n");
		tmp=StringCat($1.code,str);
		free(str);
		str=StringCat(tmp,$3.code);
		free(tmp);
		if($3.type==int_)
		{
			tmp=str;
			str=StringCat(str,"mtc1 $t2,$f2\n");
			free(tmp);
		}
		//str code,temp free
		//f3 has the value of $1, f2 has the value of $2
		if(strcmp($2,"<")==0)
			tmp=strdup("c.lt.s $f3,$f2\nbc1t ");
		else if(strcmp($2,">")==0)
			tmp=strdup("c.lt.s $f2,$f3\nbc1t ");
		else if(strcmp($2,"<=")==0)
			tmp=strdup("c.le.s $f3,$f2\nbc1t ");
		else if(strcmp($2,">=")==0)
			tmp=strdup("c.le.s $f2,$f3\nbc1t ");
		else if(strcmp($2,"==")==0)
			tmp=strdup("c.eq.s $f3,$f2\nbc1t ");
		else if(strcmp($2,"!=")==0)
			tmp=strdup("c.eq.s $f3,$f2\nbc1f ");
		sprintf(inst,"%s\nli $t3,0\nj %s\n%s: li $t3,1\n%s:\n",labelTrue,labelOut,labelTrue,labelOut);
		$$.code=tmp;
		tmp=StringCat(tmp,inst);
		free($$.code);
		$$.code=StringCat(str,tmp);
		free(str);free(tmp);
	}
	$$.head=StringCat($1.head,$3.head);
	free($1.head);free($3.head);
	free($1.code);free($3.code);
	free(labelTrue);
	free(labelOut);
};

/*--------------------------------------------------------------------------------------------*/
/*
	expression will be in reg num 2,t2 in case of int,f2 incase of float
	we add reg #2 + reg #2, and put in reg #2 
*/
EXPRESSION: EXPRESSION  addop  TERM
{
	char* str,*tmp;
	if($1.type==int_ && $3.type==int_ )
	{
		if($2 =='+')
			str=strdup("add $t2,$t2,$t1\n");
		else
			str=strdup("sub $t2,$t2,$t1\n");
		$$.type= $1.type;
	}
	else if ($1.type==float_ && $3.type==float_)//two floats
	{
		if($2 =='+')
			str=strdup("add.s $f2,$f2,$f1\n");
		else
			str=strdup("sub.s $f2,$f2,$f1\n");
		$$.type=$1.type;
	}
	else if($1.type==float_ && $3.type==int_)
	{
		if($2 =='+')
			str=strdup("mtc1 $t1, $f1\ncvt.s.w $f1, $f1\nadd.s $f2,$f1,$f2\n");
		else
			str=strdup("mtc1 $t1, $f1\ncvt.s.w $f1, $f1\nsub.s $f2,$f2,$f1\n");
		$$.type=$1.type;
		
	}
	else if($1.type==int_ && $3.type==float_)
	{ 
		if($2 =='+')
			str=strdup("mtc1 $t2, $f2\ncvt.s.w $f2, $f2\nadd.s $f2,$f2,$f1\n");
		else
			str=strdup("mtc1 $t2, $f2\ncvt.s.w $f2, $f2\nsub.s $f2,$f2,$f1\n");
		$$.type=$3.type;
	}
	else
	{
		SemanticError("cannot calculate");
		str=strdup("");
		$$.type=string;
	}
	tmp = StringCat($1.code,$3.code);
	$$.code = StringCat(tmp,str);
	free(tmp);
	free(str);
	free($1.code);
	free($3.code);
	$$.head=StringCat($1.head,$3.head);
	free($1.head);
	free($3.head);
}
| TERM 
{
	Code c={$1.code,$1.type,$1.head};
	c= moveCode(c,1,2);
	$$.code=c.code;
	$$.type=c.type;
	$$.head=c.head;
};

/*--------------------------------------------------------------------------------------------*/
/*
	term will be in reg num 1,t1 in case of int,f1 in case of float
	we mul reg #1 * reg #0, and put in reg #1 
*/
TERM: TERM mulop FACTOR 
{
	char* str,*tmp;
	if($1.type==int_ && $3.type==int_ )
	{
		if($2 =='*')
			str=strdup("mul $t1,$t1,$t0\n");
		else
			str=strdup("div $t1,$t0\nmflo $t1\n");
		$$.type= $1.type;
	}
	else if ($1.type==float_ && $3.type==float_)
	{
		if($2 =='*')
			str=strdup("mul.s $f1,$f1,$f0\n");
		else
			str=strdup("div.s $f1,$f1,$f0\n");
		$$.type=$1.type;
	}
	else if($1.type==float_ && $3.type==int_)
	{
		if($2 =='*')
			str=strdup("mtc1 $t0, $f2\ncvt.s.w $f2, $f2\nmul.s $f1,$f0,$f2\n");
		else
			str=strdup("mtc1 $t0, $f2\ncvt.s.w $f2, $f2\ndiv.s $f1,$f0,$f2\n");
		$$.type=$1.type;
	}
	else if($1.type==int_ && $3.type==float_)
	{
		if($2 =='*')
			str=strdup("mtc1 $t1, $f2\ncvt.s.w $f2, $f2\nmul.s $f1,$f2,$f0\n");
		else
			str=strdup("mtc1 $t1, $f2\ncvt.s.w $f2, $f2\ndiv.s $f1,$f2,$f0\n");
		$$.type=$3.type;
	}
	else
	{
		SemanticError("cannot make multiplay string");
		str=strdup("");
		$$.type=string;
	}
	tmp = StringCat($1.code,$3.code);
	$$.code = StringCat(tmp,str);
	free(tmp);
	free(str);
	free($1.code);
	free($3.code);
	$$.head=StringCat($1.head,$3.head);
	free($1.head);
	free($3.head);
}  
| FACTOR 
{
	Code c={$1.code,$1.type,$1.head};
	c = moveCode(c,0,1);
	$$.code=c.code;
	$$.type=c.type;
	$$.head=c.head;
};

/*--------------------------------------------------------------------------------------------*/
/*
	factor will be in reg num 0; t0 in case of int and string, f0 in case of float
*/
FACTOR: '(' EXPRESSION ')'
{	
	Code c={$2.code,$2.type,$2.head};
	c = moveCode(c,2,0);
	$$.code=c.code;
	$$.type=c.type;
	$$.head=c.head;
}
| id 
{
	Code c=idCode($1);
	$$.code = c.code;
	$$.head = c.head;
	$$.type =c.type;	
}
| num 
{
	Number n ={$1.type,$1.val.ival};
	Code c= numberCode(n);
	$$.code = c.code;
	$$.head = c.head;
	$$.type =c.type;	
};
%%
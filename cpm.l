letter[a-zA-Z]
digit[0-9]
space[ \t]
%{
#include "cpm.tab.h"
#include "shared.h"
FILE* yyout;
int eCount=1;
int line=1;
int scolumn=1;
int ecolumn=1;
extern int atoi (const char *);
extern float atof (const char *);
void lexicalError(const char* s);
void setPosAndPrint();
%}
%%
\"[a-zA-Z0-9\?\.!, ]*\" {setPosAndPrint(); int len = strlen(yytext);
						yylval.strVal=(char*)malloc(len-1);
						strncpy(yylval.strVal,yytext+1,len-2);
						yylval.strVal[len-2]='\0';
						return sentence;}

\".*\" {setPosAndPrint();
		yylval.strVal=strdup("");
		lexicalError("incorrect sentence");
		return sentence;}

"program" {setPosAndPrint(); return PROGRAM;}
"case" {setPosAndPrint(); return CASE;}
"default" {setPosAndPrint(); return DEFAULT;}
"else" {setPosAndPrint(); return ELSE;}
"for" {setPosAndPrint(); return FOR;}
"if" {setPosAndPrint(); return IF;}
"int" {setPosAndPrint(); return INT;}
"print" {setPosAndPrint(); return PRINT;}
"float" {setPosAndPrint(); return FLOAT;}
"read" {setPosAndPrint(); return READ;}
"step" {setPosAndPrint(); return STEPOP;}
"begin" {setPosAndPrint(); return _BEGIN;}
"string" {setPosAndPrint(); return STRING;}
"switch" {setPosAndPrint(); return SWITCH;}
"end" {setPosAndPrint(); return END;}
"var" {setPosAndPrint(); return VAR;}
"while" {setPosAndPrint(); return WHILE;}
"when" {setPosAndPrint(); return WHEN;}
"break" {setPosAndPrint(); return BREAK;}
"loop" {setPosAndPrint(); return LOOP;}
"const" {setPosAndPrint(); return CONST;}

{letter}[a-zA-Z0-9]* {
	
	 setPosAndPrint(); 
	 yylval.strVal = strdup(yytext);
	 if(yyleng-1>9)
		lexicalError("Invalid input - must be less than 10 characters long");
	 return id;
	
}
":=" {setPosAndPrint(); strcpy(yylval.sign2,yytext); return assignop; }

"..." {setPosAndPrint(); strcpy(yylval.sign3,yytext); return toop;}

"("|")"|"{"|"}"|","|":"|";"|"!" {setPosAndPrint(); return yytext[0];}

{digit}+"."{digit}* {setPosAndPrint();yylval.num.type=float_; yylval.num.val.fval=atof(yytext);return num;}

{digit}+ {setPosAndPrint();yylval.num.type=int_; yylval.num.val.ival=atoi(yytext);return num;}

"=="|"!="|"<"|">"|">="|"<=" {setPosAndPrint(); strcpy(yylval.sign2,yytext); return relop; }

"+"|"-" {setPosAndPrint(); yylval.sign1=yytext[0]; return addop; }

"*"|"/" {setPosAndPrint(); yylval.sign1=yytext[0]; return mulop; }

"||" {setPosAndPrint(); strcpy(yylval.sign2,yytext); return orop; }

"&&" {setPosAndPrint(); strcpy(yylval.sign2,yytext); return andop;}

{space}+ {setPosAndPrint(); fprintf(yyout,"%c",yytext[0]);}

[\n]*EOF {}

[\n]+ {line++;fprintf(yyout,"\n%d. ",line);ecolumn=1;}

"/*".*"*/"	 {setPosAndPrint(); fprintf(yyout,"%s",yytext);}

.  {setPosAndPrint(); lexicalError("Invalid character");}
%%

int yywrap()
{
return 1;
}
void lexicalError(const char* s)
{
	char err[200];
	sprintf(err,"Lexical error: %s, %s",s,yytext);
	yyerror(err);
}
void setPosAndPrint()
{
	scolumn=ecolumn;
	ecolumn += yyleng;
	fprintf(yyout,"%s",yytext);
}

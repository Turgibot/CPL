#ifndef __CODE_H
#define __CODE_H
#define _CRT_SECURE_NO_WARNINGS
typedef struct _number Number;
typedef struct _number {
	int type;
	union {
		int ival;
		float fval;
	}val;
};
typedef struct _code
{
	char* code;
	int type;
	char* head;
}Code;
char* getRegister();							 // Returns a available register to be used in the MIPS code
char* getFPRegister();							 // Returns a available float register to be used in the MIPS code
char* StringCat(const char* dis, const char* source);
char* newLabel();
int labelCount = 0;
Code numberCode(Number num);

char* registerT[10] = {"$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7","$t8","$t9",};	// The list of available MIPS registers
char* registerFP[10] = {"$f0","$f1","$f2","$f3","$f4","$f5","$f6","$f7","$f8","$f9"}; // The list of available MIPS float registers
int indexT=0;
int indexF=0;

char* StringCat(const char* first, const char* second)
{
	char* str = (char*)malloc(strlen(first) + 1 + strlen(second));
	if (str == NULL)
	{
		printf("Fail to alloc");
		return NULL;
	}
	str[0] = '\0';
	strcat(str, first);
	strcat(str, second);
	return str;
}

char* newLabel()
{
	char str[10];
	sprintf(str, "Label%d", labelCount++);
	return strdup(str);
}

char* getRegister()
{
	char* res;
	res = registerT[indexT];
	indexT = (indexT+1)%10;

	return res;
}
char* getFPRegister()
{
	char* res;
	res = registerFP[indexF];
	indexF = (indexF+1)%10;
	return res;
}
/////////////////////////////////////
//get a number and put his value in t0 if it int,f0 if it float
Code numberCode(Number num)
{
	Code c;
	char inst[100];
	c.head = strdup("");
	char* label;
	char* regT = getRegister();
	char* regF = getFPRegister();
	if (num.type == int_)
		sprintf(inst, "li %s,%d\n",regT, num.val.ival);
	else
	{
		label = newLabel();
		sprintf(inst, "%s: .float %f\n", label, num.val.fval);
		free(c.head); c.head = strdup(inst);
		sprintf(inst, "l.s %s,%s\n",regF, label);
	}
	c.code = strdup(inst);
	c.type = num.type;
	return c;
}
//get an id and put his value in t0 if it int,f0 if it float
Code idCode(char* name)
{
	Code c;
	sym* s = findSym(name);
	char inst[150];
	char* str;
	c.code = strdup("");
	char* regT = getRegister();
	char* regF = getFPRegister();
	if (s != NULL)//check if exist
	{
		if (s->haveVal)//check if have a value
		{
			str = StringCat("la $s0,", s->label);
			if (s->type==float_)
				sprintf(inst, "\nlwc1 %s,%d($s0)\n",regF, s->index * 4);
			else
				sprintf(inst, "\nlw %s,%d($s0)\n",regT, s->index * 4);
			free(c.code);
			c.code = StringCat(str, inst);
			free(str);
		}
		else
		{
			sprintf(inst, "'%s' was not initialized.", name);
			SemanticError(inst);
		}
		c.type = s->type;
	}
	else
	{
		sprintf(inst, "'%s' is undefined.", name);
		SemanticError(inst);
		c.type = -1;
	}
	c.head = strdup("");
	free(name);
	return c;
}
//move value from source to dis
Code moveCode(Code c,char* source,char* dest)
{
	Code c1;
	char str[100];
	sprintf(str,"mov.s %s,%s\n",dest,source);
	c1.code = StringCat(c.code, str);
	c1.type = c.type;
	free(c.code);
	c1.head = c.head;
	return c1;
}
#endif // !__CODE_H

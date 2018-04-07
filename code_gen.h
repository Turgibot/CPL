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

char* StringCat(char* dis, char* source);
char* newLabel();
int labelCount = 0;
Code numberCode(Number num);
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

/////////////////////////////////////
//get a number and put his value in t0 if it int,f0 if it float 
Code numberCode(Number num)
{
	Code c;
	char inst[100];
	c.head = strdup("");
	char* label;
	if (num.type == int_)
		sprintf(inst, "li $t0,%d\n", num.val.ival);
	else
	{
		label = newLabel();
		sprintf(inst, "%s: .float %f\n", label, num.val.fval);
		free(c.head); c.head = strdup(inst);
		sprintf(inst, "l.s $f0,%s\n", label);
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
	if (s != NULL)//check if exist
	{
		if (s->haveVal)//check if have a value
		{
			str = StringCat("la $s0,", s->label);
			if (s->type==float_)
				sprintf(inst, "\nlwc1 $f0,%d($s0)\n", s->index * 4);
			else
				sprintf(inst, "\nlw $t0,%d($s0)\n", s->index * 4);
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
Code moveCode(Code c,int source,int dis)
{
	Code c1;
	char str[100];
	if (c.type==float_)
		sprintf(str,"mov.s $f%d,$f%d\n",dis,source);
	else
		sprintf(str,"move $t%d,$t%d\n", dis, source);
	c1.code = StringCat(c.code, str);
	c1.type = c.type;
	free(c.code);
	c1.head = c.head;
	return c1;
}
#endif // !__CODE_H
#ifndef __SYMBOLS
#define __SYMBOLS
/*struct that hold the symbol*/
typedef struct symbol {
	char * name;
	char type;
	int constant;
	int haveVal;
	char* label;
	int index;
	int used;
	struct symbol* next;
}sym;
void  freeAllSymbol();
sym* findSym(char* name);
sym* add2Sym(char* name, char* type, int index, char* label, int cons);

sym* variables = NULL;//a list of symbols, hold the symbols in complation time
/*free the symbol table*/
void freeAllSymbol()
{
	sym* s;
	char err[100];
	while (variables != NULL)
	{
		s = variables;
		variables = variables->next;
		if (!s->used)
		{
			sprintf(err, "'%s' was declered but it's unused.", s->name);
			Warning(err);
		}
		free(s->name);
		free(s->label);
	}
}
/*add symbol to the symbols table*/
sym* add2Sym(char* name, char* type, int index, char* label, int cons)
{
	sym* s = (sym*)malloc(sizeof(sym));
	s->name = strdup(name);
	s->type = type;
	s->index = index;
	s->label = strdup(label);
	s->constant = cons;
	s->haveVal = 0;
	s->used = 0;
	s->next = NULL;
	if (variables != NULL)//add to first
		s->next = variables;
	variables = s;;
	return s;
}
/*find the symbol by name, else return NULL*/
sym* findSym(char* name)
{
	sym* s = variables;
	while (s != NULL)
	{
		if (strcmp(s->name, name) == 0)
		{
			s->used = 1;
			return s;
		}
		s = s->next;
	}
	return NULL;
}
#endif

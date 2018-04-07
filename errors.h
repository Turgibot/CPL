#ifndef __ERRORS_H
#define __ERRORS_H
#define _CRT_SECURE_NO_WARNINGS

void Warning(const char* s);
void yyerror(char *s);
void ParsingError(const char* s);
void SemanticError(const char* s);

typedef struct errorNode {
	char* error;
	struct errorNode* next;
}eNode;

void addError(const char*);
void freeErrors();
//the error and the Warning list.
eNode* errors = NULL;
//pointer to the last elemnt in the list of the errors
eNode* lastError = NULL;
//thorw parsing error
void ParsingError(const char* s)
{
	char err[200];
	sprintf(err, "Parsing Error, %s", s, yytext);
	yyerror(err);
}
//throw warning, program with warnings pass the compilation.
void Warning(const char* s)
{
	char err[300];
	sprintf(err, "Warning: %s\n", s);
	printf("%s", err);
	addError(err);
}
//throw sematic errors
void SemanticError(const char* s)
{
	char err[200];
	sprintf(err, "Semantic Error, %s", s);
	yyerror(err);
}
//add the errors to the errors list
void yyerror(const char *s)
{
	char err[300];
	if (eCount == 1)
	{
		sprintf(err, "\n\nlist of errors:\n");
		errors = (eNode*)malloc(sizeof(eNode));
		errors->error = strdup(err);
		errors->next = NULL;
		lastError = errors;


	}
	sprintf(err, "Error %d) line %d column %d: %s\n", eCount, line, scolumn, s);
	addError(err);
	eCount++;
}
//add errors to the list
void addError(const char* s)
{
	eNode* e = (eNode*)malloc(sizeof(eNode));
	e->error = strdup(s);
	if (errors == NULL)
		errors = e;
	else
		lastError->next = e;
	e->next = NULL;
	lastError = e;
}
//free the errors list
void freeErrors()
{
	eNode* e;
	while (errors != NULL)
	{
		e = errors;
		errors = e->next;
		fprintf(yyout, "%s", e->error);
		free(e->error);
		free(e);
	}
}
#endif

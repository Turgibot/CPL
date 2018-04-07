#ifndef __SHARED
#define __SHARED
#define _CRT_SECURE_NO_WARNINGS
typedef enum { int_, float_, string } Type;
extern int scolumn;
extern int ecolumn;
extern char *yytext;
extern int yyleng;
extern int eCount;
extern int line;
extern FILE* yyout;
extern FILE* yyin;
extern char* myout;
#endif // !__SHARED
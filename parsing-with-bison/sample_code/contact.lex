%{
	#include "contact.tab.h"
	#include <stdlib.h>
%}

%option noyywrap

%%

[0-9]+				{ yylval.i = atoi(yytext); return NUMBER; }
(Mr|Ms|Mrs|Dr)\.		{ yylval.str = strdup(yytext); return SALUTATION; }
\.(com|edu|gov)			{ yylval.str = strdup(yytext); return DOMAIN; }
\([0-9]{3}+\)[0-9]{3}-[0-9]{4}	{ yylval.str = strdup(yytext); return PHONE; }
(Drive|Street|Avenue)		{ yylval.str = strdup(yytext); return ROAD_TYPE; }
[A-Za-z]+			{ yylval.str = strdup(yytext); return STRING; }
@				{ return AT_SYMBOL; }
,				{ return SEPARATOR; }
[ \t\n]				;

%%

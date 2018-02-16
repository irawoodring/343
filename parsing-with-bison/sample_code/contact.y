%{
	#include <stdio.h>
	void yyerror(const char* msg);
	int yylex();
	int num_contacts = 0;
%}

%error-verbose
%start contact_list

%union { int i; char* str; }

%token SEPARATOR
%token AT_SYMBOL
%token DOMAIN
%token NUMBER
%token EMAIL
%token PHONE
%token SALUTATION
%token STRING
%token ROAD_TYPE

%type<i> NUMBER
%type<str> DOMAIN
%type<str> EMAIL
%type<str> PHONE
%type<str> SALUTATION
%type<str> STRING
%type<str> ROAD_TYPE

%%
contact_list:	contact
	|	contact contact_list
;

contact:	name SEPARATOR address SEPARATOR PHONE SEPARATOR email
		{ printf("\n----------\n"); ++num_contacts; }
;

name:		SALUTATION STRING STRING 
		{ printf("%s %s %s\n", $1, $2, $3);	}
;

address:	NUMBER STRING ROAD_TYPE STRING STRING NUMBER 
		{ printf("%d %s %s\n%s, %s %d\n", $1, $2, $3, $4, $5, $6); }
;

email:		STRING AT_SYMBOL STRING DOMAIN
		{ printf("%s@%s%s", $1, $3, $4); }
%%

int main(int argc, char** argv){
	printf("\n==========\n");
	yyparse();
	printf("\n\n==========\nFound %d contacts.\n\n", num_contacts);
	return 0;
}

void yyerror(const char* msg){
	fprintf(stderr, "ERROR! %s\n", msg);
}

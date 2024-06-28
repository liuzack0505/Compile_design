%{
    #include<stdio.h>
    #include<string.h>
    #include "y.tab.h"

    void rm_space(char *s) {
        char* tem = (char*)malloc(sizeof(char) * strlen(s));
        for(int i = 0, j = 0; i < strlen(s); i++) {
            if(s[i] != ' ') {
                tem[j] = s[i];
                j++;
            }
        }
        strcpy(s, tem);
    }
%}

type (("const"(" ")+)?("signed"(" ")+|"unsigned"(" ")+)?("long long"(" ")+|"long"(" ")+|"short"(" ")+)?"int")|(("const"(" ")+)?("signed"(" ")+|"unsigned"(" ")+)?("long long"|"long"|"short"|"char"))|(("const"(" ")+)?("signed"|"unsigned"|"float"|"double"|"void"))|"const"
id [a-zA-Z_][a-zA-Z0-9_]*
integer [0-9]+
float [0-9]+\.[0-9]*|[0-9]*\.[0-9]+
string \"([^\n\\\"]|\\[^ \n\"]*|\\\")*\"
char \'([^\n\'\\\']|\\[^ \n\']*|\\\')\'
space " "|"\t"

%%

"NULL" {
    yylval.stringVal = 0;
    return NUM;
}

"if" { return IF; }
"else" { return ELSE; }
"switch" { return SWITCH; }
"case" { return CASE; }
"default" { return DEFAULT; }
"while" { return WHILE; }
"do" { return DO; }
"for" { return FOR; }
"return" { return RETURN; }
"break" { return BREAK; }
"continue" { return CONTINUE; }

"," { return COMMA; }
";" { return SEMICOLON; }
":" { return COLON; }
"=" { return ASSIGN; }
"[" { return L_BRACKET; }
"]" { return R_BRACKET; }
"{" { return L_BRACE; }
"}" { return R_BRACE; }
"(" { return L_PARENTHESE; }
")" { return R_PARENTHESE; }

"&&" { return AND; }
"||" { return OR; }
"&" { return AND_OP; }
"^" { return XOR_OP; }
"|" { return OR_OP; }
"==" { return EQUAL; }
"!=" { return NOT_EQUAL; }
"<" { return LESS; }
">" { return GREATER; }
"<=" { return LESS_EQUAL; }
">=" { return GREATER_EQUAL; }
"<<" { return L_SHIFT; }
">>" { return R_SHIFT; }
"+" { return PLUS; }
"-" { return MINUS; }
"*" { return MUL; }
"/" { return DIV; }
"%" { return PERCENT; }
"++" { return INCREMENT; }
"--" { return DECREMENT; }
"!" { return NOT; }
"~" { return NOT_OP; }

{type} {
    rm_space(yytext);
    yylval.stringVal = strdup(yytext);
    return TYPE;
}

{id} {
    yylval.stringVal = strdup(yytext);
    return ID;
}

{integer} {
    yylval.intVal = atoi(yytext);
    return NUM;
}

{float} {
    yylval.doubleVal = atof(yytext);
    return FLOAT;
}

{char} {
    yylval.stringVal = strdup(yytext);
    return CHAR;
}

{string} {
    yylval.stringVal = strdup(yytext);
    return STRING;
}

{space} {}
"\n" {}
%%
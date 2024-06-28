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

%x COMMENT
%x MULTICOMMENTS

type (("const"(" ")+)?("signed"(" ")+|"unsigned"(" ")+)?("long long"(" ")+|"long"(" ")+|"short"(" ")+)?"int")|(("const"(" ")+)?("signed"(" ")+|"unsigned"(" ")+)?("long long"|"long"|"short"|"char"))|(("const"(" ")+)?("signed"|"unsigned"|"float"|"double"|"void"))|"const"|"uint32_t"
id [a-zA-Z_][a-zA-Z0-9_]*
integer [0-9]+
float [0-9]+\.[0-9]*|[0-9]*\.[0-9]+
string \"([^\n\\\"]|\\[^ \n\"]*|\\\")*\"
char \'([^\n\'\\\']|\\[^ \n\']*|\\\')\'
space " "|"\t"

%%

"/*" {
    BEGIN MULTICOMMENTS;
}

<MULTICOMMENTS>. {

} 
<MULTICOMMENTS>"*/" {
    BEGIN 0;
}

"//" {
    BEGIN COMMENT;
}

<COMMENT>"\n" {
    BEGIN 0;
}

<COMMENT>[^\n] {}

"NULL" {
    yylval.stringVal = 0;
    return NUM;
}

"if" { return IF; }
"else" { return ELSE; }
"while" { return WHILE; }
"do" { return DO; }
"for" { return FOR; }
"return" { return RETURN; }
"break" { return BREAK; }

"," { return COMMA; }
";" { return SEMICOLON; }
"=" { return ASSIGN; }
"[" { return L_BRACKET; }
"]" { return R_BRACKET; }
"{" { return L_BRACE; }
"}" { return R_BRACE; }
"(" { return L_PARENTHESE; }
")" { return R_PARENTHESE; }



"==" { return EQUAL; }
"!=" { return NOT_EQUAL; }
"<" { return LESS; }
">" { return GREATER; }
"<=" { return LESS_EQUAL; }
">=" { return GREATER_EQUAL; }
"+" { return PLUS; }
"-" { return MINUS; }
"*" { return MUL; }
"/" { return DIV; }
"&" {return AND_OP; }
"++" { return INCREMENT; }
"--" { return DECREMENT; }
"!" { return NOT; }
"~" { return NOT_OP; }

"__rv__ukadd8" {
    return UKADD;
}

"__rv__cmpeq8" {
    return CMPEQ;
}

"__rv__ucmplt8" {
    return UCMPLT;
}

"__rv__uksub8" {
    return UKSUB;
}

"HIGH" {
    yylval.intVal = 1;
    return NUM;
}
"LOW" {
    yylval.intVal = 1;
    return NUM;
}

"digitalWrite" {
    return DIGITALWRITE;
}

"delay" {
    return DELAY;
}

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
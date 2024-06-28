%{
    #include<stdio.h>
    #include<string.h>

    int current_line = 1;
    int pragma_source = 1;
    int pragma_token = 1;
    char current_line_text[299];

    void print_line(){
        if (pragma_source) {
            printf("%d:%s", current_line, current_line_text);
        }
        current_line++;
        memset(current_line_text, 0, sizeof(current_line_text));
    }
%}

%option noyywrap
keywords "for"|"do"|"while"|"break"|"continue"|"if"|"else"|"return"|"struct"|"switch"|"case"|"default"|"void"|"int"|"double"|"float"|"char"|"const"|"signed"|"unsigned"|"short"|"long"
Macros "NULL"|"__COUNTER__"|"__LINE__"|"INT_MAX"|"INT_MIN"|"CHAR_MAX"|"CHAR_MIN"|"MAX"|"MIN"
Operators "+"|"-"|"*"|"/"|"%"|"++"|"--"|"<"|"<="|">"|">="|"=="|"!="|"="|"&&"|"||"|"!"|"&"|"|"
Punctuation ":"|";"|","|"."|"["|"]"|"("|")"|"{"|"}"

%x COMMENT

%%

{keywords} {
    if (pragma_token) {
        printf("#key:%s\n", yytext);
    }
    
    strcat(current_line_text, yytext);
}

{Macros} {
    if (pragma_token) {
        printf("#macro:%s\n", yytext);
    }
    strcat(current_line_text, yytext);
}

{Operators} {
    if (pragma_token) {
        printf("#op:%s\n", yytext);
    }
    strcat(current_line_text, yytext);
}

{Punctuation} {
    if (pragma_token) {
        printf("#punc:%s\n", yytext);
    }
    strcat(current_line_text, yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* {
    if (pragma_token) {
        printf("#id:%s\n", yytext);
    }
    strcat(current_line_text, yytext);
}

[-+]?[0-9]+ {
    if (pragma_token) {
        printf("#integer:%s\n", yytext);
    }
    strcat(current_line_text, yytext);
}

[-+]?([0-9]+\.[0-9]*|[0-9]*\.[0-9]+)? {
    if (pragma_token) {
        printf("#float:%s\n", yytext);
    }
    strcat(current_line_text, yytext);
}

\'([^\n\'\\]|\\[^ \n]*)\'  {
    if (pragma_token) {
        printf("#char:%s\n", yytext);
    }
    strcat(current_line_text, yytext);
}

\"([^\n\\]|\\[^ \n]*)*\"  {
    if (pragma_token) {
        printf("#string:%s\n", yytext);
    }
    strcat(current_line_text, yytext);
}

[\t|" "] {
    strcat(current_line_text, yytext);
}

\n {
    strcat(current_line_text, yytext);
    print_line();
}

"//".*[\n] {
    strcat(current_line_text, yytext);
    print_line();
}

"/*" {
    BEGIN COMMENT;
    strcat(current_line_text, yytext);
}

#pragma[ \t]+source[ \t]+on {
    pragma_source = 1;
    strcat(current_line_text, yytext);
}

#pragma[ \t]+source[ \t]+off {
    pragma_source = 0;
    strcat(current_line_text, yytext);
}

#pragma[ \t]+token[ \t]+on {
    pragma_token = 1;
    strcat(current_line_text, yytext);
}

#pragma[ \t]+token[ \t]+off {
    pragma_token = 0;
    strcat(current_line_text, yytext);
}

<COMMENT>\n {
    strcat(current_line_text, yytext);
    print_line();
}

<COMMENT>"*/" {
    BEGIN 0;
    strcat(current_line_text, yytext);
}

<COMMENT>. {
    strcat(current_line_text, yytext);
}


%%

int main(){
    yylex();
    return 0;
}
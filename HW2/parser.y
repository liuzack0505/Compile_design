%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    #define SCALAR_TAG 27
    #define ARRAY_TAG 25
    #define FUNC_DECL_TAG 23
    #define FUNC_DEF_TAG 21
    #define EXPR_TAG 13
    #define STMT_TAG 13

    char* int_to_string(int num){
        int len = 1;
        int tem = num;
        while (tem >= 10) {
            tem = tem / 10;
            len++;
        }
        char* str = (char*)malloc(sizeof(char) * (len + 1));
        sprintf(str, "%d", num);
        return str;
    } 
    char* double_to_string(double d){
        char* str = (char*)malloc(sizeof(char) * 33);
        sprintf(str, "%f", d);
        return str;
    }
    int yylex();

    int lineNo;
%}
%union{
    int intVal;
    double doubleVal;
    char* stringVal;
}

%token <intVal> NUM
%token <doubleVal> FLOAT
%token <stringVal> CHAR STRING
%token <stringVal> TYPE ID
%token <stringVal> IF ELSE SWITCH CASE DEFAULT WHILE DO FOR RETURN BREAK CONTINUE
// symbol
%token <stringVal> COMMA SEMICOLON COLON ASSIGN R_BRACKET L_BRACKET R_BRACE L_BRACE R_PARENTHESE L_PARENTHESE 
%token <stringVal> AND OR AND_OP XOR_OP OR_OP EQUAL NOT_EQUAL LESS GREATER LESS_EQUAL GREATER_EQUAL L_SHIFT R_SHIFT PLUS MINUS MUL DIV PERCENT INCREMENT DECREMENT NOT NOT_OP

%start program
%type <stringVal> program_blocks program_block
%type <stringVal> scalar_decl ident ident_front idents assign_expr exprs
%type <stringVal> array_decl arrs arr arr_def arr_content arr_dim
%type <stringVal> func_decl func_def parameters parameter compound_stmt stmts stmt
%type <stringVal> if_else_stmt switch_stmt switch_clauses switch_clause while_stmt for_stmt for_cond for_last_cond return_stmt break_stmt continue_stmt
%type <stringVal> or_expr and_expr or_op_expr xor_op_expr and_op_expr equal_expr comp_expr shift_op_expr add_sub_expr mul_div_rem_expr pre_expr post_expr end_expr arr_expr

%nonassoc UPLUS UMINUS POINTER ADDRESS_Of
%nonassoc POST_INC POST_DEC

%%
program : program_blocks {
    printf("%s", $1);
}

program_blocks : program_blocks program_block {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($2) + 1));
    strcpy(tem, $1);
    strcat(tem, $2);
    $$ = tem;
}
| program_block {
    $$ = $1;
}

program_block : scalar_decl {
    $$ = $1;
}
| array_decl {
    $$ = $1;
}
| func_decl {
    $$ = $1;
}
| func_def {
    $$ = $1;
}

//scalar
scalar_decl : TYPE idents SEMICOLON{
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($2) + SCALAR_TAG + 2));
    strcpy(tem, "<scalar_decl>");
    strcat(tem, $1);
    strcat(tem, $2);
    strcat(tem, ";");
    strcat(tem, "</scalar_decl>");
    $$ = tem;
}

idents : ident {
    $$ = $1;
}
| idents COMMA ident{
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + 2));
    strcpy(tem, $1);
    strcat(tem, ",");
    strcat(tem, $3);
    $$ = tem;
}

ident : ident_front ASSIGN assign_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + 2));
    strcpy(tem, $1);
    strcat(tem, "=");
    strcat(tem, $3);
    $$ = tem;
}
| ident_front {
    $$ = $1;
}

ident_front : ID {
    $$ = $1;
}
| MUL ID {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + 2));
    strcpy(tem, "*");
    strcat(tem, $2);
    $$ = tem;
}

//array
array_decl : TYPE arrs SEMICOLON {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($2) + ARRAY_TAG + 2));
    strcpy(tem, "<array_decl>");
    strcat(tem, $1);
    strcat(tem, $2);
    strcat(tem, ";");
    strcat(tem, "</array_decl>");
    $$ = tem;
}

arrs : arr {
    $$ = $1;
}
| arrs COMMA arr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + 2));
    strcpy(tem, $1);
    strcat(tem, ",");
    strcat(tem, $3);
    $$ = tem;
}

arr : arr_def ASSIGN L_BRACE arr_content R_BRACE {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($4) + 4));
    strcpy(tem, $1);
    strcat(tem, "=");
    strcat(tem, "{");
    strcat(tem, $4);
    strcat(tem, "}");
    $$ = tem;
}
| arr_def {
    $$ = $1;
}

arr_def : ID arr_dim {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($2) + 1));
    strcpy(tem, $1);
    strcat(tem, $2);
    $$ = tem;
}

arr_dim : arr_dim L_BRACKET assign_expr R_BRACKET {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + 3));
    strcpy(tem, $1);
    strcat(tem, "[");
    strcat(tem, $3);
    strcat(tem, "]");
    $$ = tem;
}
| L_BRACKET assign_expr R_BRACKET {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + 3));
    strcpy(tem, "[");
    strcat(tem, $2);
    strcat(tem, "]");
    $$ = tem;
}

arr_content : L_BRACE arr_content R_BRACE {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + 3));
    strcpy(tem, "{");
    strcat(tem, $2);
    strcat(tem, "}");
    $$ = tem;
}
| arr_content COMMA L_BRACE arr_content R_BRACE {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1)+ strlen($4) + 4));
    strcpy(tem, $1);
    strcat(tem, ",");
    strcat(tem, "{");
    strcat(tem, $4);
    strcat(tem, "}");
    $$ = tem;
}
| arr_content COMMA assign_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1)+ strlen($3) + 4));
    strcpy(tem, $1);
    strcat(tem, ",");
    strcat(tem, $3);
    $$ = tem;
}
| assign_expr {
    $$ = $1;
}

//function declare
func_decl : TYPE ID L_PARENTHESE parameters R_PARENTHESE SEMICOLON {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($2) + strlen($4) + FUNC_DECL_TAG + 4));
    strcpy(tem, "<func_decl>");
    strcat(tem, $1);
    strcat(tem, $2);
    strcat(tem, "(");
    strcat(tem, $4);
    strcat(tem, ")");
    strcat(tem, ";");
    strcat(tem, "</func_decl>");
    $$ = tem;
}
| TYPE ID L_PARENTHESE R_PARENTHESE SEMICOLON {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($2) + FUNC_DECL_TAG + 4));
    strcpy(tem, "<func_decl>");
    strcat(tem, $1);
    strcat(tem, $2);
    strcat(tem, "(");
    strcat(tem, ")");
    strcat(tem, ";");
    strcat(tem, "</func_decl>");
    $$ = tem;
}
| TYPE MUL ID L_PARENTHESE parameters R_PARENTHESE SEMICOLON {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + strlen($5) + FUNC_DECL_TAG + 5));
    strcpy(tem, "<func_decl>");
    strcat(tem, $1);
    strcat(tem, "*");
    strcat(tem, $3);
    strcat(tem, "(");
    strcat(tem, $5);
    strcat(tem, ")");
    strcat(tem, ";");
    strcat(tem, "</func_decl>");
    $$ = tem;
}
| TYPE MUL ID L_PARENTHESE R_PARENTHESE SEMICOLON {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + FUNC_DECL_TAG + 5));
    strcpy(tem, "<func_decl>");
    strcat(tem, $1);
    strcat(tem, "*");
    strcat(tem, $3);
    strcat(tem, "(");
    strcat(tem, ")");
    strcat(tem, ";");
    strcat(tem, "</func_decl>");
    $$ = tem;
}

parameters : parameters COMMA parameter {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + 2));
    strcpy(tem, $1);
    strcat(tem, ",");
    strcat(tem, $3);
    $$ = tem;
}
| parameter {
    $$ = $1;
}

parameter : TYPE ID {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($2) + 1));
    strcpy(tem, $1);
    strcat(tem, $2);
    $$ = tem;
}
| TYPE MUL ID {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + 2));
    strcpy(tem, $1);
    strcat(tem, "*");
    strcat(tem, $3);
    $$ = tem;
}

//function definition
func_def : TYPE ID L_PARENTHESE parameters R_PARENTHESE compound_stmt {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($2) + strlen($4) + strlen($6) + FUNC_DEF_TAG + 3));
    strcpy(tem, "<func_def>");
    strcat(tem, $1);
    strcat(tem, $2);
    strcat(tem, "(");
    strcat(tem, $4);
    strcat(tem, ")");
    strcat(tem, $6);
    strcat(tem, "</func_def>");
    $$ = tem;
}
| TYPE ID L_PARENTHESE R_PARENTHESE compound_stmt {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($2) + strlen($5) + FUNC_DEF_TAG + 3));
    strcpy(tem, "<func_def>");
    strcat(tem, $1);
    strcat(tem, $2);
    strcat(tem, "(");
    strcat(tem, ")");
    strcat(tem, $5);
    strcat(tem, "</func_def>");
    $$ = tem;
}
| TYPE MUL ID L_PARENTHESE parameters R_PARENTHESE compound_stmt {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + strlen($5) + strlen($7) + FUNC_DEF_TAG + 4));
    strcpy(tem, "<func_def>");
    strcat(tem, $1);
    strcat(tem, "*");
    strcat(tem, $3);
    strcat(tem, "(");
    strcat(tem, $5);
    strcat(tem, ")");
    strcat(tem, $7);
    strcat(tem, "</func_def>");
    $$ = tem;
}
| TYPE MUL ID L_PARENTHESE R_PARENTHESE compound_stmt {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + strlen($6) + FUNC_DEF_TAG + 4));
    strcpy(tem, "<func_def>");
    strcat(tem, $1);
    strcat(tem, "*");
    strcat(tem, $3);
    strcat(tem, "(");
    strcat(tem, ")");
    strcat(tem, $6);
    strcat(tem, "</func_def>");
    $$ = tem;
}

//compound statement
compound_stmt : L_BRACE stmts R_BRACE {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + 3));
    strcpy(tem, "{");
    strcat(tem, $2);
    strcat(tem, "}");
    $$ = tem;
}
| L_BRACE R_BRACE {
    char *tem = (char*)malloc(sizeof(char) * 3);
    strcpy(tem, "{");
    strcat(tem, "}");
    $$ = tem;
}

stmts : stmts stmt {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($2) + 1));
    strcpy(tem, $1);
    strcat(tem, $2);
    $$ = tem;
}
| stmt {
    $$ = $1;
}

stmt : if_else_stmt {
    $$ = $1;
}
| switch_stmt {
    $$ = $1;
}
| while_stmt {
    $$ = $1;
}
| for_stmt {
    $$ = $1;
}
| return_stmt {
    $$ = $1;
}
| break_stmt {
    $$ = $1;
}
| continue_stmt {
    $$ = $1;
}
| compound_stmt {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + STMT_TAG + 1));
    strcpy(tem, "<stmt>");
    strcat(tem, $1);
    strcat(tem, "</stmt>");
    $$ = tem;
}
| scalar_decl {
    $$ = $1;
}
| array_decl {
    $$ = $1;
}
| assign_expr SEMICOLON {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + STMT_TAG + 2));
    strcpy(tem, "<stmt>");
    strcat(tem, $1);
    strcat(tem, ";");
    strcat(tem, "</stmt>");
    $$ = tem;
}

//if else
if_else_stmt : IF L_PARENTHESE assign_expr R_PARENTHESE compound_stmt {
    char *tem = (char*)malloc(sizeof(char) * (strlen($3) + strlen($5) + STMT_TAG + 5));
    strcpy(tem, "<stmt>");
    strcat(tem, "if");
    strcat(tem, "(");
    strcat(tem, $3);
    strcat(tem, ")");
    strcat(tem, $5);
    strcat(tem, "</stmt>");
    $$ = tem;
}
| IF L_PARENTHESE assign_expr R_PARENTHESE compound_stmt ELSE compound_stmt {
    char *tem = (char*)malloc(sizeof(char) * (strlen($3) + strlen($5) + strlen($7) + STMT_TAG + 9));
    strcpy(tem, "<stmt>");
    strcat(tem, "if");
    strcat(tem, "(");
    strcat(tem, $3);
    strcat(tem, ")");
    strcat(tem, $5);
    strcat(tem, "else");
    strcat(tem, $7);
    strcat(tem, "</stmt>");
    $$ = tem;
}

//switch

switch_stmt : SWITCH L_PARENTHESE assign_expr R_PARENTHESE L_BRACE switch_clauses R_BRACE {
    char *tem = (char*)malloc(sizeof(char) * (strlen($3) + strlen($6) + STMT_TAG + 11));
    strcpy(tem, "<stmt>");
    strcat(tem, "switch");
    strcat(tem, "(");
    strcat(tem, $3);
    strcat(tem, ")");
    strcat(tem, "{");
    strcat(tem, $6);
    strcat(tem, "}");
    strcat(tem, "</stmt>");
    $$ = tem;
} 
| SWITCH L_PARENTHESE assign_expr R_PARENTHESE L_BRACE R_BRACE {
    char *tem = (char*)malloc(sizeof(char) * (strlen($3) + STMT_TAG + 11));
    strcpy(tem, "<stmt>");
    strcat(tem, "switch");
    strcat(tem, "(");
    strcat(tem, $3);
    strcat(tem, ")");
    strcat(tem, "{");
    strcat(tem, "}");
    strcat(tem, "</stmt>");
    $$ = tem;
}

switch_clauses : switch_clauses switch_clause {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($2) + 1));
    strcpy(tem, $1);
    strcat(tem, $2);
    $$ = tem;
}
| switch_clause {
    $$ = $1;
}

switch_clause : CASE assign_expr COLON stmts {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + strlen($4) + 6));
    strcpy(tem, "case");
    strcat(tem, $2);
    strcat(tem, ":");
    strcat(tem, $4);
    $$ = tem;
}
| CASE assign_expr COLON {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + 6));
    strcpy(tem, "case");
    strcat(tem, $2);
    strcat(tem, ":");
    $$ = tem;
}
| DEFAULT COLON stmts {
    char *tem = (char*)malloc(sizeof(char) * (strlen($3) + 9));
    strcpy(tem, "default");
    strcat(tem, ":");
    strcat(tem, $3);
    $$ = tem;
}
| DEFAULT COLON {
    char *tem = (char*)malloc(sizeof(char) * 9);
    strcpy(tem, "default");
    strcat(tem, ":");
    $$ = tem;
}

//while 
while_stmt : WHILE L_PARENTHESE assign_expr R_PARENTHESE stmt {
    char *tem = (char*)malloc(sizeof(char) * (strlen($3) + strlen($5) + STMT_TAG + 8));
    strcpy(tem, "<stmt>");
    strcat(tem, "while");
    strcat(tem, "(");
    strcat(tem, $3);
    strcat(tem, ")");
    strcat(tem, $5);
    strcat(tem, "</stmt>");
    $$ = tem;
}
| DO stmt WHILE L_PARENTHESE assign_expr R_PARENTHESE SEMICOLON {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + strlen($5) + STMT_TAG + 11));
    strcpy(tem, "<stmt>");
    strcat(tem, "do");
    strcat(tem, $2);
    strcat(tem, "while");
    strcat(tem, "(");
    strcat(tem, $5);
    strcat(tem, ")");
    strcat(tem, ";");
    strcat(tem, "</stmt>");
    $$ = tem;
}

//for 
for_stmt : FOR L_PARENTHESE for_cond for_cond for_last_cond stmt {
    char *tem = (char*)malloc(sizeof(char) * (strlen($3) + strlen($4) + strlen($5) + strlen($6) + STMT_TAG + 5));
    strcpy(tem, "<stmt>");
    strcat(tem, "for");
    strcat(tem, "(");
    strcat(tem, $3);
    strcat(tem, $4);
    strcat(tem, $5);
    strcat(tem, $6);
    strcat(tem, "</stmt>");
    $$ = tem;
}

for_cond : assign_expr SEMICOLON {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + 2));
    strcpy(tem, $1);
    strcat(tem, ";");
    $$ = tem;
}
| SEMICOLON {
    char *tem = (char*)malloc(sizeof(char)*2);
    strcpy(tem, ";");
    $$ = tem;
}

for_last_cond : assign_expr R_PARENTHESE {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + 2));
    strcpy(tem, $1);
    strcat(tem, ")");
    $$ = tem;
}
| R_PARENTHESE {
    char *tem = (char*)malloc(sizeof(char)*2);
    strcpy(tem, ")");
    $$ = tem;
}

//return break continue

return_stmt : RETURN assign_expr SEMICOLON {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + STMT_TAG + 8));
    strcpy(tem, "<stmt>");
    strcat(tem, "return");
    strcat(tem, $2);
    strcat(tem, ";");
    strcat(tem, "</stmt>");
    $$ = tem;
}
| RETURN SEMICOLON {
    char *tem = (char*)malloc(sizeof(char) * (STMT_TAG + 8));
    strcpy(tem, "<stmt>");
    strcat(tem, "return;");
    strcat(tem, "</stmt>");
    $$ = tem;
}

break_stmt : BREAK SEMICOLON {
    char *tem = (char*)malloc(sizeof(char) * (STMT_TAG + 7));
    strcpy(tem, "<stmt>");
    strcat(tem, "break;");
    strcat(tem, "</stmt>");
    $$ = tem;
}

continue_stmt : CONTINUE SEMICOLON {
    char *tem = (char*)malloc(sizeof(char) * (STMT_TAG + 10));
    strcpy(tem, "<stmt>");
    strcat(tem, "continue;");
    strcat(tem, "</stmt>");
    $$ = tem;
}

//epxr

exprs : exprs COMMA assign_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + 2));
    strcpy(tem, $1);
    strcat(tem, ",");
    strcat(tem, $3);
    $$ = tem;
}
| assign_expr {
    $$ = $1;
}

// =
assign_expr : or_expr ASSIGN assign_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "=");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
} 
| or_expr {
    $$ = $1;
}

// ||
or_expr : or_expr OR and_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "||");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
} 
| and_expr {
    $$ = $1;
}

// &&
and_expr : and_expr AND or_op_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "&&");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| or_op_expr {
    $$ = $1;
}

// | 
or_op_expr : or_op_expr OR_OP xor_op_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "|");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| xor_op_expr {
    $$ = $1;
}

// ^
xor_op_expr : xor_op_expr XOR_OP and_op_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "^");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}  
| and_op_expr {
    $$ = $1;
}

// &
and_op_expr : and_op_expr AND_OP equal_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "&");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| equal_expr {
    $$ = $1;
}

// != ==
equal_expr : equal_expr EQUAL comp_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "==");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| equal_expr NOT_EQUAL comp_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "!=");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| comp_expr {
    $$ = $1;
}

// >= <= < >
comp_expr : comp_expr LESS shift_op_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "<");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| comp_expr GREATER shift_op_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, ">");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| comp_expr LESS_EQUAL shift_op_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "<=");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| comp_expr GREATER_EQUAL shift_op_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, ">=");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| shift_op_expr {
    $$ = $1;
}

// >> <<
shift_op_expr : shift_op_expr L_SHIFT add_sub_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "<<");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| shift_op_expr R_SHIFT add_sub_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, ">>");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| add_sub_expr {
    $$ = $1;
}

// + -
add_sub_expr : add_sub_expr PLUS mul_div_rem_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "+");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| add_sub_expr MINUS mul_div_rem_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "-");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| mul_div_rem_expr {
    $$ = $1;
}

// * / %
mul_div_rem_expr : mul_div_rem_expr MUL pre_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "*");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| mul_div_rem_expr DIV pre_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "/");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| mul_div_rem_expr PERCENT pre_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "%");
    strcat(tem, $3);
    strcat(tem, "</expr>");
    $$ = tem;
}
| pre_expr {
    $$ = $1;
}

// ++ -- + -(unary) ! ~ (type) (*type) *ident &ident

pre_expr : INCREMENT pre_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, "++");
    strcat(tem, $2);
    strcat(tem, "</expr>");
    $$ = tem;
}
| DECREMENT pre_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, "--");
    strcat(tem, $2);
    strcat(tem, "</expr>");
    $$ = tem;
}
| PLUS pre_expr %prec UPLUS {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, "+");
    strcat(tem, $2);
    strcat(tem, "</expr>");
    $$ = tem;
}
| MINUS pre_expr %prec UMINUS {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, "-");
    strcat(tem, $2);
    strcat(tem, "</expr>");
    $$ = tem;
} 
| NOT pre_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, "!");
    strcat(tem, $2);
    strcat(tem, "</expr>");
    $$ = tem;
}
| NOT_OP pre_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, "~");
    strcat(tem, $2);
    strcat(tem, "</expr>");
    $$ = tem;
}
| L_PARENTHESE TYPE R_PARENTHESE pre_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + strlen($4) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, "(");
    strcat(tem, $2);
    strcat(tem, ")");
    strcat(tem, $4);
    strcat(tem, "</expr>");
    $$ = tem;
}
| L_PARENTHESE TYPE MUL R_PARENTHESE pre_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + strlen($5) + EXPR_TAG + 4));
    strcpy(tem, "<expr>");
    strcat(tem, "(");
    strcat(tem, $2);
    strcat(tem, "*");
    strcat(tem, ")");
    strcat(tem, $5);
    strcat(tem, "</expr>");
    $$ = tem;
}
| MUL pre_expr %prec POINTER {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, "*");
    strcat(tem, $2);
    strcat(tem, "</expr>");
    $$ = tem;
}
| AND_OP pre_expr %prec ADDRESS_Of {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, "&");
    strcat(tem, $2);
    strcat(tem, "</expr>");
    $$ = tem;
}
| post_expr {
    $$ = $1;
}

// expr++ expr-- function() 
post_expr : post_expr INCREMENT %prec POST_INC {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "++");
    strcat(tem, "</expr>");
    $$ = tem;
}
| post_expr DECREMENT %prec POST_DEC {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "--");
    strcat(tem, "</expr>");
    $$ = tem;
}
| post_expr L_PARENTHESE R_PARENTHESE {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "(");
    strcat(tem, ")");
    strcat(tem, "</expr>");
    $$ = tem;
}
| post_expr L_PARENTHESE exprs R_PARENTHESE {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "(");
    strcat(tem, $3);
    strcat(tem, ")");
    strcat(tem, "</expr>");
    $$ = tem;
}
| end_expr {
    $$ = $1;
}

// id array interger float char string NULL (expr)

end_expr : ID arr_expr {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($2) + EXPR_TAG + 1));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, $2);
    strcat(tem, "</expr>");
    $$ = tem;
}
| ID {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + EXPR_TAG + 1));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "</expr>");
    $$ = tem;
}
| NUM {
    char *str = int_to_string($1);
    char *tem = (char*)malloc(sizeof(char) * (strlen(str) + EXPR_TAG + 1));
    strcpy(tem, "<expr>");
    strcat(tem, str);
    strcat(tem, "</expr>");
    $$ = tem;
}
| FLOAT {
    char *str = double_to_string($1);
    char *tem = (char*)malloc(sizeof(char) * (strlen(str) + EXPR_TAG + 1));
    strcpy(tem, "<expr>");
    strcat(tem, str);
    strcat(tem, "</expr>");
    $$ = tem;
}
| CHAR {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + EXPR_TAG + 1));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "</expr>");
    $$ = tem;
}
| STRING {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + EXPR_TAG + 1));
    strcpy(tem, "<expr>");
    strcat(tem, $1);
    strcat(tem, "</expr>");
    $$ = tem;
}
| L_PARENTHESE assign_expr R_PARENTHESE {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, "(");
    strcat(tem, $2);
    strcat(tem, ")");
    strcat(tem, "</expr>");
    $$ = tem;
}

arr_expr : arr_expr L_BRACKET assign_expr R_BRACKET {
    char *tem = (char*)malloc(sizeof(char) * (strlen($1) + strlen($3) + 3));
    strcpy(tem, $1);
    strcat(tem, "[");
    strcat(tem, $3);
    strcat(tem, "]");
    $$ = tem;
}
| L_BRACKET assign_expr R_BRACKET {
    char *tem = (char*)malloc(sizeof(char) * (strlen($2) + 3));
    strcpy(tem, "[");
    strcat(tem, $2);
    strcat(tem, "]");
    $$ = tem;
}

%%

void yyerror(char *msg) {
    fprintf(stderr, "Error at line %d: %s\n", lineNo, msg);
}

int main(void) {
    yydebug = 1;
    yyparse();
    return 0;
}





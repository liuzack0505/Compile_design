%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "util.h"

    
    int yylex();

    int lineNo;
    int cur_arg_cont = 0; // util in function call
    // util in function def
    int cur_para_cont = 0; 
    char* para_record[10];
    // util for loop
    int loop_index = 0;
    int loop_i = -1;
    int loop_record[10];
    // util for if-else
    int if_index = 0;
    int if_i = -1;
    int if_record[10];
    int branch_count = 0; //util for <= >= < > != ==
    int yydebug = 0;
    extern FILE* f_asm;

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
    char* copy(char *s) {
        char *n = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(n, s);
        return n;
    }
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
%token <stringVal> IF ELSE WHILE DO FOR RETURN BREAK
%token <stringVal> DIGITALWRITE DELAY
%token <stringVal> UKADD CMPEQ UCMPLT UKSUB
// symbol
%token <stringVal> COMMA SEMICOLON ASSIGN R_BRACKET L_BRACKET R_BRACE L_BRACE R_PARENTHESE L_PARENTHESE 
%token <stringVal> AND_OP EQUAL NOT_EQUAL LESS GREATER LESS_EQUAL GREATER_EQUAL PLUS MINUS MUL DIV INCREMENT DECREMENT NOT NOT_OP

%start program
%type <stringVal> program_blocks program_block
%type <stringVal> scalar_decl ident ident_front idents assign_expr
%type <stringVal> array_decl arrs arr arr_def arr_content arr_dim
%type <stringVal> func_decl func_def parameter compound_stmt stmts stmt
%type <stringVal> if_else_stmt if_stmt else_stmt while_stmt for_stmt for_cond for_last_cond return_stmt break_stmt digitalwrite_stmt delay_stmt
%type <stringVal> equal_expr comp_expr add_sub_expr mul_div_rem_expr pre_expr post_expr end_expr arr_expr

%nonassoc UPLUS UMINUS POINTER ADDRESS_Of
%nonassoc POST_INC POST_DEC

%%

program : program_blocks {
}

program_blocks : program_blocks program_block {
    
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
    $$ = $1;
}

idents : ident {
    $$ = $1;
}
| idents COMMA ident{
    $$ = NULL;
}

ident : ident_front ASSIGN assign_expr {
    int i =look_up_symbol($1);
    fprintf(f_asm, "  // store in %s space in stack\n", $1);
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  sw t0, %d(s0)\n", table[i].offset * (-8));
    fprintf(f_asm, "  addi sp, sp, 8\n");
    $$ = NULL;
}
| ident_front {
    $$ = $1;
}

ident_front : ID {
    install_symbol($1, "int", 1);
    fprintf(f_asm, "  // declare id %s and create its space in stack\n", $1);
    fprintf(f_asm, "  addi sp, sp, -8\n");
    $$ = $1;
}
| MUL ID {
    install_symbol($2, "int", 1);
    fprintf(f_asm, "  // declare id %s and create its space in stack\n", $2);
    fprintf(f_asm, "  addi sp, sp, -8\n");
    $$ = $2;
}

//array
array_decl : TYPE arrs SEMICOLON {
    
}

arrs : arr {
    $$ = $1;
}
| arrs COMMA arr {
   
}

arr : arr_def ASSIGN L_BRACE arr_content R_BRACE {
    
}
| arr_def {
   
}

arr_def : ID arr_dim {
    int size = atoi($2);
    install_symbol($1, "array", size);
    fprintf(f_asm, "  // pop %s to decide the arr space and create space in stack\n", $2);
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  li t0, %d\n", size*8);
    fprintf(f_asm, "  sub sp, sp, t0\n");
    $$ = NULL;
}

arr_dim : L_BRACKET assign_expr R_BRACKET {
    $$ = $2;
}

arr_content : L_BRACE arr_content R_BRACE {
   
}
| arr_content COMMA L_BRACE arr_content R_BRACE {
    
}
| arr_content COMMA assign_expr {
   
}
| assign_expr {
    $$ = $1;
}

//function declare
func_decl : TYPE ID L_PARENTHESE parameter COMMA parameter R_PARENTHESE SEMICOLON {
    fprintf(f_asm, ".global %s\n", $2);
    cur_para_cont = 0;
}
| TYPE ID L_PARENTHESE R_PARENTHESE SEMICOLON {
    fprintf(f_asm, ".global %s\n", $2);
}

parameter : TYPE ID {
    $$ = $2;
}
| TYPE MUL ID {
    $$ = $3;
}

//function definition
func_def : TYPE ID L_PARENTHESE parameter COMMA parameter R_PARENTHESE {
    cur_scope++;
    install_symbol($4, "arguement1", 0);
    install_symbol($6, "arguement2", 0);
    code_gen_func_header($2);
}compound_stmt {
    cur_scope--;
    $$ = NULL;
}
| TYPE ID L_PARENTHESE R_PARENTHESE {
    cur_scope++;
    code_gen_func_header($2);
} compound_stmt {
    cur_scope--;
    code_gen_at_end_of_function_body();
    $$ = NULL;
}

//compound statement
compound_stmt : L_BRACE stmts R_BRACE {
    
}
| L_BRACE R_BRACE {
    
}

stmts : stmts stmt {}
| stmt {
    $$ = $1;
}

stmt : if_else_stmt {
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
| compound_stmt {
    
}
| scalar_decl {
    $$ = $1;
}
| array_decl {
    $$ = $1;
}
| assign_expr SEMICOLON {
    
}
| digitalwrite_stmt {

}
| delay_stmt {

}

// digitalwrite
digitalwrite_stmt : DIGITALWRITE L_PARENTHESE assign_expr COMMA assign_expr R_PARENTHESE SEMICOLON{
    fprintf(f_asm, "  // pop two to execute the function digitalwrite\n");
    fprintf(f_asm, "  lw a1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw a0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  // store the ra and jump to digitalWrite\n");
    fprintf(f_asm, "  sw ra, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    fprintf(f_asm, "  jal ra, digitalWrite\n");
    fprintf(f_asm, "  lw ra, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  \n");
}

//delay
delay_stmt : DELAY L_PARENTHESE assign_expr R_PARENTHESE SEMICOLON{
    fprintf(f_asm, "  // pop one to execute the function delay\n");
    fprintf(f_asm, "  lw a0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  // store the ra and jump to delay\n");
    fprintf(f_asm, "  sw ra, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    fprintf(f_asm, "  jal ra, delay\n");
    fprintf(f_asm, "  lw ra, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  \n");
}

//if else
if_else_stmt : if_stmt else_stmt{}

if_stmt : IF L_PARENTHESE {
    cur_scope++;
    if_index++;
    if_i++;
    if_record[if_i] = if_index;
    fprintf(f_asm, "/* if%d start---------------------*/\n", if_record[if_i]);
} assign_expr R_PARENTHESE {
    fprintf(f_asm, "  // test whether to ignore if \n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  beq t0, zero, else%d\n", if_record[if_i]);
    fprintf(f_asm, "  j if%d\n", if_record[if_i]);
    fprintf(f_asm, "if%d:\n", if_record[if_i]);
} compound_stmt {
    fprintf(f_asm, "  j if%d_end\n", if_record[if_i]);
    $$ = NULL;
}

else_stmt : ELSE {
    fprintf(f_asm, "else%d:\n", if_record[if_i]);
} compound_stmt {
    fprintf(f_asm, "  j if%d_end\n", if_record[if_i]);
    fprintf(f_asm, "if%d_end:\n", if_record[if_i]);
    cur_scope--;
    if_i--;
}
| /*empty*/ {
    fprintf(f_asm, "else%d:\n", if_record[if_i]);
    fprintf(f_asm, "if%d_end:\n", if_record[if_i]);
    cur_scope--;
    if_i--;
    $$ = NULL;
}

//while 
while_stmt : WHILE L_PARENTHESE {
    cur_scope++;
    loop_index++;
    loop_i++;
    loop_record[loop_i] = loop_index;
    fprintf(f_asm, "/* loop%d(while) start------------*/\n", loop_record[loop_i]);
    fprintf(f_asm, "  j loop%d_cond\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d_cond:\n", loop_record[loop_i]);
} assign_expr {
    fprintf(f_asm, "  // test whether to jump out the while loop\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  beq t0, zero, loop%d_end\n", loop_record[loop_i]);
    fprintf(f_asm, "  j loop%d\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d:\n", loop_record[loop_i]);
} R_PARENTHESE compound_stmt {
    fprintf(f_asm, "  j loop%d_cond\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d_end:\n", loop_record[loop_i]);
    cur_scope--;
    loop_i--;
    $$ = NULL;
}
| DO {
    cur_scope++;
    loop_index++;
    loop_i++;
    loop_record[loop_i] = loop_index;
    fprintf(f_asm, "/* loop%d(do-while) start---------*/\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d:\n", loop_record[loop_i]);
} compound_stmt WHILE L_PARENTHESE {
    fprintf(f_asm, "  j loop%d_cond\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d_cond:\n", loop_record[loop_i]);
} assign_expr R_PARENTHESE SEMICOLON {
    fprintf(f_asm, "  // test whether to jump out the while loop\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  beq t0, zero, loop%d_end\n", loop_record[loop_i]);
    fprintf(f_asm, "  j loop%d\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d_end:\n", loop_record[loop_i]);
    cur_scope--;
    loop_i--;
}

//for 
for_stmt : FOR L_PARENTHESE {
    loop_index++;
    loop_i++;
    loop_record[loop_i] = loop_index;
    cur_scope++;
    fprintf(f_asm, "/* loop%d(for) start-------------*/\n", loop_record[loop_i]);

}for_cond {
    fprintf(f_asm, "  j loop%d\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d_cond:\n", loop_record[loop_i]);
}for_cond {
    // pop to the first to see 1 or 0
    fprintf(f_asm, "  // test whether to jump out the for loop\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  beq t0, zero, loop%d_end\n", loop_record[loop_i]);
    fprintf(f_asm, "  j loop%d\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d_last_cond:\n", loop_record[loop_i]);
}for_last_cond {
    fprintf(f_asm, "  j loop%d_cond\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d:\n", loop_record[loop_i]);
}compound_stmt {
    fprintf(f_asm, "  j loop%d_last_cond\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d_end:\n", loop_record[loop_i]);
    cur_scope--;
    loop_i--;
    $$ = NULL;
}

for_cond : assign_expr SEMICOLON {
    
}
| SEMICOLON {
    
}

for_last_cond : assign_expr R_PARENTHESE {
    
}
| R_PARENTHESE {
    
}

//return break continue

return_stmt : RETURN assign_expr SEMICOLON {
    fprintf(f_asm, "  // pop first one to return\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi a0, t0, 0\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    code_gen_at_end_of_function_body();
}


break_stmt : BREAK SEMICOLON {
    fprintf(f_asm, "  // break the cur loop\n");
    fprintf(f_asm, "  j loop%d_end\n", loop_record[loop_i]);
}

// =
assign_expr : equal_expr ASSIGN assign_expr {
    fprintf(f_asm, "  // pop first two to assign(t0 is value, t1 is offset)\n");
    //pop first, but the second isn't necessary
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 4(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    //calculate the absolute address
    fprintf(f_asm, "  li t2, -8\n");
    fprintf(f_asm, "  mul t1, t1, t2\n");
    fprintf(f_asm, "  add t1, t1, s0\n");
    fprintf(f_asm, "  sw t0, 0(t1)\n");
    $$ = NULL;
} 
| equal_expr {
    $$ = $1;
}

// != ==
equal_expr : equal_expr EQUAL comp_expr {
    branch_count++;
    fprintf(f_asm, "  // pop two to compare equal\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  beq t1, t0, branch%d_true\n", branch_count);
    fprintf(f_asm, "  li t0, 0\n");
    fprintf(f_asm, "  j branch%d_result\n", branch_count);
    fprintf(f_asm, "branch%d_true:\n", branch_count);
    fprintf(f_asm, "  li t0, 1\n");
    fprintf(f_asm, "  j branch%d_result\n", branch_count);
    fprintf(f_asm, "branch%d_result:\n", branch_count);
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    $$ = NULL;
}
| equal_expr NOT_EQUAL comp_expr {
    branch_count++;
    fprintf(f_asm, "  // pop two to compare equal\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  bne t1, t0, branch%d_true\n", branch_count);
    fprintf(f_asm, "  li t0, 0\n");
    fprintf(f_asm, "  j branch%d_result\n", branch_count);
    fprintf(f_asm, "branch%d_true:\n", branch_count);
    fprintf(f_asm, "  li t0, 1\n");
    fprintf(f_asm, "  j branch%d_result\n", branch_count);
    fprintf(f_asm, "branch%d_result:\n", branch_count);
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    $$ = NULL;
}
| comp_expr {
    $$ = $1;
}

// >= <= < >
comp_expr : comp_expr LESS add_sub_expr {
    branch_count++;
    fprintf(f_asm, "  // pop two to compare less\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  blt t1, t0, branch%d_true\n", branch_count);
    fprintf(f_asm, "  li t0, 0\n");
    fprintf(f_asm, "  j branch%d_result\n", branch_count);
    fprintf(f_asm, "branch%d_true:\n", branch_count);
    fprintf(f_asm, "  li t0, 1\n");
    fprintf(f_asm, "  j branch%d_result\n", branch_count);
    fprintf(f_asm, "branch%d_result:\n", branch_count);
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    $$ = NULL;
}
| comp_expr GREATER add_sub_expr {
    branch_count++;
    fprintf(f_asm, "  // pop two to compare greater\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  blt t1, t0, branch%d_true\n", branch_count);
    fprintf(f_asm, "  li t0, 0\n");
    fprintf(f_asm, "  j branch%d_result\n", branch_count);
    fprintf(f_asm, "branch%d_true:\n", branch_count);
    fprintf(f_asm, "  li t0, 1\n");
    fprintf(f_asm, "  j branch%d_result\n", branch_count);
    fprintf(f_asm, "branch%d_result:\n", branch_count);
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    $$ = NULL;
}
| comp_expr LESS_EQUAL add_sub_expr {
    branch_count++;
    fprintf(f_asm, "  // pop two to compare less_equal\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  ble t1, t0, branch%d_true\n", branch_count);
    fprintf(f_asm, "  li t0, 0\n");
    fprintf(f_asm, "  j branch%d_result\n", branch_count);
    fprintf(f_asm, "branch%d_true:\n", branch_count);
    fprintf(f_asm, "  li t0, 1\n");
    fprintf(f_asm, "  j branch%d_result\n", branch_count);
    fprintf(f_asm, "branch%d_result:\n", branch_count);
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    $$ = NULL;
}
| comp_expr GREATER_EQUAL add_sub_expr {
    branch_count++;
    fprintf(f_asm, "  // pop two to compare greater_equal\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  bge t1, t0, branch%d_true\n", branch_count);
    fprintf(f_asm, "  li t0, 0\n");
    fprintf(f_asm, "  j branch%d_result\n", branch_count);
    fprintf(f_asm, "branch%d_true:\n", branch_count);
    fprintf(f_asm, "  li t0, 1\n");
    fprintf(f_asm, "  j branch%d_result\n", branch_count);
    fprintf(f_asm, "branch%d_result:\n", branch_count);
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    $$ = NULL;
}
| add_sub_expr {
    $$ = $1;
}

// + -
add_sub_expr : add_sub_expr PLUS mul_div_rem_expr {
    fprintf(f_asm, "  // pop first two to add\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  add t0, t0, t1\n");
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    $$ = NULL;
}
| add_sub_expr MINUS mul_div_rem_expr {
    fprintf(f_asm, "  // pop first two to sub\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  sub t0, t1, t0\n");
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    $$ = NULL;
}
| mul_div_rem_expr {
    $$ = $1;
}

// * / 
mul_div_rem_expr : mul_div_rem_expr MUL pre_expr {
    fprintf(f_asm, "  // pop first two to mul\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  mul t0, t0, t1\n");
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    $$ = NULL;
}
| mul_div_rem_expr DIV pre_expr {
    fprintf(f_asm, "  // pop first two to div\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  div t0, t1, t0\n");
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    $$ = NULL;
}
| pre_expr {
    $$ = $1;
}

// ++ -- + -(unary) ! ~ (type) (*type) *ident &ident

pre_expr : INCREMENT pre_expr {
    
}
| DECREMENT pre_expr {
    
}
| PLUS pre_expr %prec UPLUS {
   
}
| MINUS pre_expr %prec UMINUS {
    fprintf(f_asm, "  // pop id then push -id into stack\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  sub t0, zero, t0\n");
    fprintf(f_asm, "  sw t0, 0(sp)\n");
    $$ = NULL;
} 
| NOT pre_expr {
    
}
| NOT_OP pre_expr {
    
}
| L_PARENTHESE TYPE R_PARENTHESE pre_expr {
    
}
| L_PARENTHESE TYPE MUL R_PARENTHESE pre_expr {
    
}
| MUL pre_expr %prec POINTER {
    fprintf(f_asm, "  // pop id then push *id into stack\n");
    // load the value (that address) and save as address
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  sw t0, 4(sp)\n");
    // save the value at that address
    fprintf(f_asm, "  li t1, -8\n");
    fprintf(f_asm, "  mul t0, t0, t1\n");
    fprintf(f_asm, "  add t0, t0, s0\n");
    fprintf(f_asm, "  lw t1, 0(t0)\n");
    fprintf(f_asm, "  sw t1, 0(sp)\n");
    $$ = NULL;
    
}
| AND_OP pre_expr %prec ADDRESS_Of {
    fprintf(f_asm, "  // pop id then push &id into stack\n");
    // get address and save the address as value
    fprintf(f_asm, "  lw t0, 4(sp)\n");
    fprintf(f_asm, "  sw t0, 0(sp)\n");
    $$ = NULL;
}
| post_expr {
    $$ = $1;
}

// expr++ expr-- function() 
post_expr : post_expr INCREMENT %prec POST_INC {
    
}
| post_expr DECREMENT %prec POST_DEC {
    
}
| post_expr L_PARENTHESE assign_expr COMMA assign_expr R_PARENTHESE {}
| UKADD L_PARENTHESE assign_expr COMMA assign_expr R_PARENTHESE {
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  ukadd8 t0, t0, t1\n");
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
}
| CMPEQ L_PARENTHESE assign_expr COMMA assign_expr R_PARENTHESE {
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  cmpeq8 t2, t1, t0\n");
    fprintf(f_asm, "  sw t2, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
}
| UCMPLT L_PARENTHESE assign_expr COMMA assign_expr R_PARENTHESE {
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  ucmplt8 t2, t1, t0\n");
    fprintf(f_asm, "  sw t2, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
}
| UKSUB L_PARENTHESE assign_expr COMMA assign_expr R_PARENTHESE {
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  uksub8 t0, t1, t0\n");
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
}
| end_expr {
    $$ = $1;
}

// id array interger float char string NULL (expr)

end_expr : ID arr_expr {
    int i = look_up_symbol($1);
    fprintf(f_asm, "  // pop the index and push array element value\n");
    fprintf(f_asm, "  li t0, %d\n", table[i].offset);
    // pop index to calculate
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  add t0, t1, t0\n");
    // save the offset
    fprintf(f_asm, "  sw t0, -4(sp)\n");
    // calculate the absolute address
    fprintf(f_asm, "  li t1, -8\n");
    fprintf(f_asm, "  mul t2, t0, t1\n");
    fprintf(f_asm, "  add t3, t2, s0\n");
    // save the value
    fprintf(f_asm, "  lw t0, 0(t3)\n");
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    $$ = NULL;
}
| ID {
    int i = look_up_symbol($1);
    if (i >= 0) {
        if (strcmp(table[i].type, "int") == 0) {
            fprintf(f_asm, "  // push value %s into stack\n", $1);
            // save the offset
            fprintf(f_asm, "  li t0, %d\n", table[i].offset);
            fprintf(f_asm, "  sw t0, -4(sp)\n");
            // if is int, save the value
            fprintf(f_asm, "  lw t0, %d(s0)\n", table[i].offset * (-8));
            fprintf(f_asm, "  sw t0, -8(sp)\n");
            fprintf(f_asm, "  addi sp, sp, -8\n");
        } else if (strcmp(table[i].type, "arguement1") == 0){
            // if is argument1 get from a0
            fprintf(f_asm, "  // push value %s into stack\n", $1);
            fprintf(f_asm, "  addi t0, a0, 0\n");
            fprintf(f_asm, "  sw t0, -8(sp)\n");
            fprintf(f_asm, "  addi sp, sp, -8\n");
        } else if (strcmp(table[i].type, "arguement2") == 0){
            // if is argument2 get from a1
            fprintf(f_asm, "  // push value %s into stack\n", $1);
            fprintf(f_asm, "  addi t0, a1, 0\n");
            fprintf(f_asm, "  sw t0, -8(sp)\n");
            fprintf(f_asm, "  addi sp, sp, -8\n");
        } else {
            fprintf(f_asm, "  // push value %s into stack\n", $1);
            // save the offset
            fprintf(f_asm, "  li t0, %d\n", table[i].offset);
            fprintf(f_asm, "  sw t0, -4(sp)\n");
            // if is array, save the offset
            fprintf(f_asm, "  sw t0, -8(sp)\n");
            fprintf(f_asm, "  addi sp, sp, -8\n");
        }
    }
    $$ = $1;
}
| NUM {
    fprintf(f_asm, "  // push %d into stack\n", $1);
    // save the value
    fprintf(f_asm, "  li t0, %d\n", $1);
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    char* tem = int_to_string($1);
    $$ = tem;
}
| CHAR {}
| STRING {}
| FLOAT {}
| L_PARENTHESE assign_expr R_PARENTHESE {}

arr_expr : L_BRACKET assign_expr R_BRACKET {
    $$ = $2;
}


%%

int main (void) {
    if ((f_asm = fopen(FILENAME, "w")) == NULL) {
        perror("Error at opening file");
    }
    init();
    yyparse();
    fclose(f_asm);
}

void yyerror(char *msg) {
    fprintf(stderr, "Error at line %d:%s\n", lineNo, msg);
}
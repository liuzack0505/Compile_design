#include <stdio.h>
#include <stdlib.h>
#define MAX_TABLE_SIZE 5000
#define FILENAME "codegen.S"
struct symbol_entry {
    char *name;
    char *type;
    int scope;
    int offset;
    int size;
};

void init();
char *install_symbol(char*, char*, int);
int look_up_symbol(char*);
void pop_up_symbol(int);
void code_gen_func_header(char*);
void code_gen_at_end_of_function_body();
void code_gen_branch_label();

extern FILE* f_asm;
extern int cur_scope;
extern int cur_counter;
extern int cur_label;
extern struct symbol_entry table[MAX_TABLE_SIZE];
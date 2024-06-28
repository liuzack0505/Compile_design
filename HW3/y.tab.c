/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "util.h"

    
    int yylex();

    int lineNo;
    int cur_arg_cont = 0; /* util in function call*/
    /* util in function def*/
    int cur_para_cont = 0; 
    char* para_record[10];
    /* util for loop*/
    int loop_index = 0;
    int loop_i = -1;
    int loop_record[10];
    /* util for if-else*/
    int if_index = 0;
    int if_i = -1;
    int if_record[10];
    int branch_count = 0; /*util for <= >= < > != ==*/
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
#line 44 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
    int intVal;
    double doubleVal;
    char* stringVal;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 76 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NUM 257
#define FLOAT 258
#define CHAR 259
#define STRING 260
#define TYPE 261
#define ID 262
#define IF 263
#define ELSE 264
#define WHILE 265
#define DO 266
#define FOR 267
#define RETURN 268
#define BREAK 269
#define DIGITALWRITE 270
#define DELAY 271
#define UKADD 272
#define CMPEQ 273
#define UCMPLT 274
#define UKSUB 275
#define COMMA 276
#define SEMICOLON 277
#define ASSIGN 278
#define R_BRACKET 279
#define L_BRACKET 280
#define R_BRACE 281
#define L_BRACE 282
#define R_PARENTHESE 283
#define L_PARENTHESE 284
#define AND_OP 285
#define EQUAL 286
#define NOT_EQUAL 287
#define LESS 288
#define GREATER 289
#define LESS_EQUAL 290
#define GREATER_EQUAL 291
#define PLUS 292
#define MINUS 293
#define MUL 294
#define DIV 295
#define INCREMENT 296
#define DECREMENT 297
#define NOT 298
#define NOT_OP 299
#define UPLUS 300
#define UMINUS 301
#define POINTER 302
#define ADDRESS_Of 303
#define POST_INC 304
#define POST_DEC 305
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    2,    3,    6,    6,
    4,    4,    5,    5,    8,    9,    9,   10,   10,   11,
   13,   12,   12,   12,   12,   14,   14,   16,   16,   39,
   15,   40,   15,   17,   17,   18,   18,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   29,   30,
   20,   41,   42,   21,   43,   22,   22,   44,   45,   23,
   46,   47,   23,   48,   49,   50,   51,   24,   25,   25,
   26,   26,   27,   28,    7,    7,   31,   31,   31,   32,
   32,   32,   32,   32,   33,   33,   33,   34,   34,   34,
   35,   35,   35,   35,   35,   35,   35,   35,   35,   35,
   35,   36,   36,   36,   36,   36,   36,   36,   36,   37,
   37,   37,   37,   37,   37,   37,   38,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    1,    1,    1,    1,    3,    1,    3,
    3,    1,    1,    2,    3,    1,    3,    5,    1,    2,
    3,    3,    5,    3,    1,    8,    5,    2,    3,    0,
    9,    0,    6,    3,    2,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    2,    1,    1,    7,    5,
    2,    0,    0,    7,    0,    3,    0,    0,    0,    7,
    0,    0,    9,    0,    0,    0,    0,   10,    2,    1,
    2,    1,    3,    2,    3,    1,    3,    3,    1,    3,
    3,    3,    3,    1,    3,    3,    1,    3,    3,    1,
    2,    2,    2,    2,    2,    2,    4,    5,    2,    2,
    1,    2,    2,    6,    6,    6,    6,    6,    1,    2,
    1,    1,    1,    1,    1,    3,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    3,    4,    5,    6,    7,    0,    0,
    9,    0,    0,    0,   16,    0,    2,    0,    0,   20,
   14,    0,    0,    8,    0,   15,    0,  112,  115,  113,
  114,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   90,    0,  109,    0,    0,    0,   11,   13,   10,    0,
   17,    0,    0,  110,    0,    0,    0,    0,    0,    0,
  100,   93,   94,   99,   91,   92,   95,   96,   21,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  102,  103,   28,    0,   27,    0,    0,    0,   25,
    0,    0,    0,    0,    0,    0,    0,    0,  116,   75,
    0,    0,    0,    0,    0,    0,    0,    0,   88,   89,
    0,   29,    0,   33,    0,    0,    0,   18,  117,    0,
    0,    0,    0,   97,    0,    0,    0,    0,    0,   61,
    0,    0,    0,    0,    0,   35,   44,    0,   45,   43,
    0,   37,   38,    0,   39,   40,   41,   42,   47,   48,
    0,   22,    0,   24,    0,    0,    0,    0,   98,    0,
    0,   52,   58,    0,   64,    0,   74,    0,    0,   46,
   34,   36,   55,   51,   26,    0,    0,  105,  106,  107,
  108,  104,    0,    0,    0,    0,   73,    0,    0,    0,
   31,   23,    0,   59,    0,   70,    0,   65,    0,    0,
   56,   53,    0,   62,   69,    0,    0,   50,    0,    0,
    0,   66,    0,   54,   60,    0,    0,   49,    0,   72,
    0,   67,   63,   71,    0,   68,
};
static const YYINT yydgoto[] = {                          2,
    3,    4,    5,   11,   12,   13,  100,    6,   14,   15,
   16,  101,   20,    7,    8,   56,  150,  151,  152,  153,
  154,  184,  155,  156,  208,  232,  157,  158,  159,  160,
   47,   48,   49,   50,   51,   52,   53,   64,  186,   97,
  193,  219,  200,  194,  213,  174,  221,  196,  216,  227,
  235,
};
static const YYINT yysindex[] = {                      -243,
 -260,    0, -243,    0,    0,    0,    0,    0, -256, -211,
    0, -238, -216, -205,    0, -223,    0,  184, -245,    0,
    0,  184, -248,    0, -204,    0, -215,    0,    0,    0,
    0, -189, -209, -197, -183, -168, -130,  184,  184,  184,
  184,  184,  184,  184,  184, -210, -255, -212, -257, -191,
    0, -267,    0, -242, -188, -159,    0,    0,    0, -157,
    0,   68,  184,    0,  184,  184,  184,  184, -261, -147,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  184,
  184,  184,  184,  184,  184,  184,  184,  184,  184,  184,
  184,    0,    0,    0, -125,    0, -144, -122,   68,    0,
 -239, -139, -129, -128, -127, -126,  184, -137,    0,    0,
 -212, -212, -257, -257, -257, -257, -191, -191,    0,    0,
 -124,    0,  -47,    0, -132, -237,   97,    0,    0,  184,
  184,  184,  184,    0,  184,  184, -241, -131, -119,    0,
 -114,  184, -121, -113, -112,    0,    0, -120,    0,    0,
   -4,    0,    0, -106,    0,    0,    0,    0,    0,    0,
 -118,    0,   68,    0, -109, -100,  -96,  -95,    0,  -91,
 -157,    0,    0, -144,    0, -104,    0,  184,  184,    0,
    0,    0,    0,    0,    0, -144, -222,    0,    0,    0,
    0,    0,  184,  184,  -88,  126,    0,  -83,  -81, -144,
    0,    0,  -77,    0,  -99,    0,  -70,    0,  184,  -69,
    0,    0,  -66,    0,    0,  126,  -54,    0, -144, -144,
  184,    0,  -46,    0,    0,  -53,  155,    0,  -45,    0,
  -50,    0,    0,    0, -144,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  200,    0,    0,    0,    0,    0, -251,    0,
    0, -195,    0,    0,    0, -169,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  208,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -213,  -97,  286, -193,
    0,  230,    0,    0,  -43,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -82,  366,  302,  318,  334,  350,  250,  268,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   39,    0,    0,    0,    0,    0,    0,
  -42,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -251,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  233, -110,  218,    0,    0,  -18, -108,    0,  217,
    0,  -98,    0,    0,    0,  145,  -94,    0,   93,    0,
    0,    0,    0,    0,   32,    0,    0,    0,    0,    0,
    0,   29,   36,   47,  -33,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
#define YYTABLESIZE 653
static const YYINT yytable[] = {                         46,
  126,    9,  124,   57,   71,   72,   73,   74,   75,   76,
   77,   78,  147,   58,  149,   54,   91,    1,   70,   94,
  171,  107,   80,   18,   13,   13,   13,   19,   92,   93,
   81,   82,  108,   10,   87,   88,  127,   55,  127,   22,
  147,  128,  149,  162,  102,   10,  103,  104,  105,  106,
   21,   95,   10,  127,   27,  119,  120,   60,  202,   23,
   24,  110,   76,   76,  187,   76,   62,   76,   79,   76,
   25,   26,  121,  134,   65,   83,   84,   85,   86,  195,
   12,   12,   87,   87,   87,   87,   66,   87,   96,   87,
   63,  201,   87,   87,   87,   87,   87,   87,   87,   87,
   67,  169,   89,   90,  148,  211,   19,   19,  164,  111,
  112,  165,  166,  167,  168,   68,   98,  170,  113,  114,
  115,  116,   18,  176,  224,  225,   28,   29,   30,   31,
   69,   32,  148,  117,  118,  109,  122,  123,   54,  129,
  236,   33,   34,   35,   36,  135,  130,  131,  132,  133,
  161,  136,  172,   37,   38,  177,  180,  183,  185,  198,
  199,   39,   40,   41,  173,   42,   43,   44,   45,  175,
  178,  179,  197,  188,  203,  204,  205,  207,   79,   79,
   79,   79,  189,   79,  214,   79,  190,  191,   79,   79,
  217,  192,  209,   77,   77,   77,   77,  207,   77,    1,
   77,  210,  226,   77,   77,  212,  215,  218,  231,   28,
   29,   30,   31,  137,   32,  138,  220,  139,  140,  141,
  142,  143,  144,  145,   33,   34,   35,   36,  223,  229,
  228,  233,  234,  146,  123,   17,   37,   38,   32,   30,
   59,   61,  125,  182,   39,   40,   41,  222,   42,   43,
   44,   45,   28,   29,   30,   31,  137,   32,  138,    0,
  139,  140,  141,  142,  143,  144,  145,   33,   34,   35,
   36,    0,    0,    0,    0,    0,  181,  123,    0,   37,
   38,    0,    0,    0,    0,    0,    0,   39,   40,   41,
    0,   42,   43,   44,   45,   57,   57,   57,   57,   57,
   57,   57,    0,   57,   57,   57,   57,   57,   57,   57,
   57,   57,   57,   57,    0,    0,    0,    0,    0,   57,
   57,    0,   57,   57,   28,   29,   30,   31,    0,   32,
   57,   57,   57,    0,   57,   57,   57,   57,    0,   33,
   34,   35,   36,    0,    0,    0,    0,    0,    0,   99,
    0,   37,   38,   28,   29,   30,   31,    0,   32,   39,
   40,   41,    0,   42,   43,   44,   45,    0,   33,   34,
   35,   36,    0,    0,    0,    0,    0,    0,  163,    0,
   37,   38,   28,   29,   30,   31,    0,   32,   39,   40,
   41,    0,   42,   43,   44,   45,    0,   33,   34,   35,
   36,    0,  206,    0,    0,    0,    0,    0,    0,   37,
   38,   28,   29,   30,   31,    0,   32,   39,   40,   41,
    0,   42,   43,   44,   45,    0,   33,   34,   35,   36,
    0,    0,    0,    0,    0,    0,    0,  230,   37,   38,
   28,   29,   30,   31,    0,   32,   39,   40,   41,    0,
   42,   43,   44,   45,    0,   33,   34,   35,   36,    0,
    0,    0,    0,    0,    0,    0,    0,   37,   38,    0,
    0,    0,    0,    0,    0,   39,   40,   41,    0,   42,
   43,   44,   45,  111,  111,  111,  111,    0,  111,    0,
  111,  111,    0,  111,  111,  111,  111,  111,  111,  111,
  111,  111,  111,  111,  111,  101,  101,  101,  101,    0,
  101,    0,  101,    0,    0,  101,  101,  101,  101,  101,
  101,  101,  101,  101,  101,   85,   85,   85,   85,    0,
   85,    0,   85,    0,    0,   85,   85,   85,   85,   85,
   85,   85,   85,   86,   86,   86,   86,    0,   86,    0,
   86,    0,    0,   86,   86,   86,   86,   86,   86,   86,
   86,   84,   84,   84,   84,    0,   84,    0,   84,    0,
    0,   84,   84,   84,   84,   84,   84,   80,   80,   80,
   80,    0,   80,    0,   80,    0,    0,   80,   80,   80,
   80,   80,   80,   81,   81,   81,   81,    0,   81,    0,
   81,    0,    0,   81,   81,   81,   81,   81,   81,   82,
   82,   82,   82,    0,   82,    0,   82,    0,    0,   82,
   82,   82,   82,   82,   82,   83,   83,   83,   83,    0,
   83,    0,   83,    0,    0,   83,   83,   83,   83,   83,
   83,   78,   78,   78,   78,    0,   78,    0,   78,    0,
    0,   78,   78,
};
static const YYINT yycheck[] = {                         18,
   99,  262,   97,   22,   38,   39,   40,   41,   42,   43,
   44,   45,  123,  262,  123,  261,  284,  261,   37,  262,
  262,  283,  278,  280,  276,  277,  278,  284,  296,  297,
  286,  287,  294,  294,  292,  293,  276,  283,  276,  278,
  151,  281,  151,  281,   63,  294,   65,   66,   67,   68,
  262,  294,  294,  276,  278,   89,   90,  262,  281,  276,
  277,   80,  276,  277,  163,  279,  282,  281,  279,  283,
  276,  277,   91,  107,  284,  288,  289,  290,  291,  174,
  276,  277,  276,  277,  278,  279,  284,  281,  277,  283,
  280,  186,  286,  287,  288,  289,  290,  291,  292,  293,
  284,  135,  294,  295,  123,  200,  276,  277,  127,   81,
   82,  130,  131,  132,  133,  284,  276,  136,   83,   84,
   85,   86,  280,  142,  219,  220,  257,  258,  259,  260,
  261,  262,  151,   87,   88,  283,  262,  282,  261,  279,
  235,  272,  273,  274,  275,  283,  276,  276,  276,  276,
  283,  276,  284,  284,  285,  277,  277,  264,  277,  178,
  179,  292,  293,  294,  284,  296,  297,  298,  299,  284,
  284,  284,  277,  283,  193,  194,  265,  196,  276,  277,
  278,  279,  283,  281,  284,  283,  283,  283,  286,  287,
  209,  283,  276,  276,  277,  278,  279,  216,  281,    0,
  283,  283,  221,  286,  287,  283,  277,  277,  227,  257,
  258,  259,  260,  261,  262,  263,  283,  265,  266,  267,
  268,  269,  270,  271,  272,  273,  274,  275,  283,  283,
  277,  277,  283,  281,  282,    3,  284,  285,  282,  282,
   23,   25,   98,  151,  292,  293,  294,  216,  296,  297,
  298,  299,  257,  258,  259,  260,  261,  262,  263,   -1,
  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,
  275,   -1,   -1,   -1,   -1,   -1,  281,  282,   -1,  284,
  285,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,  294,
   -1,  296,  297,  298,  299,  257,  258,  259,  260,  261,
  262,  263,   -1,  265,  266,  267,  268,  269,  270,  271,
  272,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,  281,
  282,   -1,  284,  285,  257,  258,  259,  260,   -1,  262,
  292,  293,  294,   -1,  296,  297,  298,  299,   -1,  272,
  273,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,
   -1,  284,  285,  257,  258,  259,  260,   -1,  262,  292,
  293,  294,   -1,  296,  297,  298,  299,   -1,  272,  273,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,   -1,
  284,  285,  257,  258,  259,  260,   -1,  262,  292,  293,
  294,   -1,  296,  297,  298,  299,   -1,  272,  273,  274,
  275,   -1,  277,   -1,   -1,   -1,   -1,   -1,   -1,  284,
  285,  257,  258,  259,  260,   -1,  262,  292,  293,  294,
   -1,  296,  297,  298,  299,   -1,  272,  273,  274,  275,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  283,  284,  285,
  257,  258,  259,  260,   -1,  262,  292,  293,  294,   -1,
  296,  297,  298,  299,   -1,  272,  273,  274,  275,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  284,  285,   -1,
   -1,   -1,   -1,   -1,   -1,  292,  293,  294,   -1,  296,
  297,  298,  299,  276,  277,  278,  279,   -1,  281,   -1,
  283,  284,   -1,  286,  287,  288,  289,  290,  291,  292,
  293,  294,  295,  296,  297,  276,  277,  278,  279,   -1,
  281,   -1,  283,   -1,   -1,  286,  287,  288,  289,  290,
  291,  292,  293,  294,  295,  276,  277,  278,  279,   -1,
  281,   -1,  283,   -1,   -1,  286,  287,  288,  289,  290,
  291,  292,  293,  276,  277,  278,  279,   -1,  281,   -1,
  283,   -1,   -1,  286,  287,  288,  289,  290,  291,  292,
  293,  276,  277,  278,  279,   -1,  281,   -1,  283,   -1,
   -1,  286,  287,  288,  289,  290,  291,  276,  277,  278,
  279,   -1,  281,   -1,  283,   -1,   -1,  286,  287,  288,
  289,  290,  291,  276,  277,  278,  279,   -1,  281,   -1,
  283,   -1,   -1,  286,  287,  288,  289,  290,  291,  276,
  277,  278,  279,   -1,  281,   -1,  283,   -1,   -1,  286,
  287,  288,  289,  290,  291,  276,  277,  278,  279,   -1,
  281,   -1,  283,   -1,   -1,  286,  287,  288,  289,  290,
  291,  276,  277,  278,  279,   -1,  281,   -1,  283,   -1,
   -1,  286,  287,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 305
#define YYUNDFTOKEN 359
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NUM","FLOAT","CHAR","STRING",
"TYPE","ID","IF","ELSE","WHILE","DO","FOR","RETURN","BREAK","DIGITALWRITE",
"DELAY","UKADD","CMPEQ","UCMPLT","UKSUB","COMMA","SEMICOLON","ASSIGN",
"R_BRACKET","L_BRACKET","R_BRACE","L_BRACE","R_PARENTHESE","L_PARENTHESE",
"AND_OP","EQUAL","NOT_EQUAL","LESS","GREATER","LESS_EQUAL","GREATER_EQUAL",
"PLUS","MINUS","MUL","DIV","INCREMENT","DECREMENT","NOT","NOT_OP","UPLUS",
"UMINUS","POINTER","ADDRESS_Of","POST_INC","POST_DEC",0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : program_blocks",
"program_blocks : program_blocks program_block",
"program_blocks : program_block",
"program_block : scalar_decl",
"program_block : array_decl",
"program_block : func_decl",
"program_block : func_def",
"scalar_decl : TYPE idents SEMICOLON",
"idents : ident",
"idents : idents COMMA ident",
"ident : ident_front ASSIGN assign_expr",
"ident : ident_front",
"ident_front : ID",
"ident_front : MUL ID",
"array_decl : TYPE arrs SEMICOLON",
"arrs : arr",
"arrs : arrs COMMA arr",
"arr : arr_def ASSIGN L_BRACE arr_content R_BRACE",
"arr : arr_def",
"arr_def : ID arr_dim",
"arr_dim : L_BRACKET assign_expr R_BRACKET",
"arr_content : L_BRACE arr_content R_BRACE",
"arr_content : arr_content COMMA L_BRACE arr_content R_BRACE",
"arr_content : arr_content COMMA assign_expr",
"arr_content : assign_expr",
"func_decl : TYPE ID L_PARENTHESE parameter COMMA parameter R_PARENTHESE SEMICOLON",
"func_decl : TYPE ID L_PARENTHESE R_PARENTHESE SEMICOLON",
"parameter : TYPE ID",
"parameter : TYPE MUL ID",
"$$1 :",
"func_def : TYPE ID L_PARENTHESE parameter COMMA parameter R_PARENTHESE $$1 compound_stmt",
"$$2 :",
"func_def : TYPE ID L_PARENTHESE R_PARENTHESE $$2 compound_stmt",
"compound_stmt : L_BRACE stmts R_BRACE",
"compound_stmt : L_BRACE R_BRACE",
"stmts : stmts stmt",
"stmts : stmt",
"stmt : if_else_stmt",
"stmt : while_stmt",
"stmt : for_stmt",
"stmt : return_stmt",
"stmt : break_stmt",
"stmt : compound_stmt",
"stmt : scalar_decl",
"stmt : array_decl",
"stmt : assign_expr SEMICOLON",
"stmt : digitalwrite_stmt",
"stmt : delay_stmt",
"digitalwrite_stmt : DIGITALWRITE L_PARENTHESE assign_expr COMMA assign_expr R_PARENTHESE SEMICOLON",
"delay_stmt : DELAY L_PARENTHESE assign_expr R_PARENTHESE SEMICOLON",
"if_else_stmt : if_stmt else_stmt",
"$$3 :",
"$$4 :",
"if_stmt : IF L_PARENTHESE $$3 assign_expr R_PARENTHESE $$4 compound_stmt",
"$$5 :",
"else_stmt : ELSE $$5 compound_stmt",
"else_stmt :",
"$$6 :",
"$$7 :",
"while_stmt : WHILE L_PARENTHESE $$6 assign_expr $$7 R_PARENTHESE compound_stmt",
"$$8 :",
"$$9 :",
"while_stmt : DO $$8 compound_stmt WHILE L_PARENTHESE $$9 assign_expr R_PARENTHESE SEMICOLON",
"$$10 :",
"$$11 :",
"$$12 :",
"$$13 :",
"for_stmt : FOR L_PARENTHESE $$10 for_cond $$11 for_cond $$12 for_last_cond $$13 compound_stmt",
"for_cond : assign_expr SEMICOLON",
"for_cond : SEMICOLON",
"for_last_cond : assign_expr R_PARENTHESE",
"for_last_cond : R_PARENTHESE",
"return_stmt : RETURN assign_expr SEMICOLON",
"break_stmt : BREAK SEMICOLON",
"assign_expr : equal_expr ASSIGN assign_expr",
"assign_expr : equal_expr",
"equal_expr : equal_expr EQUAL comp_expr",
"equal_expr : equal_expr NOT_EQUAL comp_expr",
"equal_expr : comp_expr",
"comp_expr : comp_expr LESS add_sub_expr",
"comp_expr : comp_expr GREATER add_sub_expr",
"comp_expr : comp_expr LESS_EQUAL add_sub_expr",
"comp_expr : comp_expr GREATER_EQUAL add_sub_expr",
"comp_expr : add_sub_expr",
"add_sub_expr : add_sub_expr PLUS mul_div_rem_expr",
"add_sub_expr : add_sub_expr MINUS mul_div_rem_expr",
"add_sub_expr : mul_div_rem_expr",
"mul_div_rem_expr : mul_div_rem_expr MUL pre_expr",
"mul_div_rem_expr : mul_div_rem_expr DIV pre_expr",
"mul_div_rem_expr : pre_expr",
"pre_expr : INCREMENT pre_expr",
"pre_expr : DECREMENT pre_expr",
"pre_expr : PLUS pre_expr",
"pre_expr : MINUS pre_expr",
"pre_expr : NOT pre_expr",
"pre_expr : NOT_OP pre_expr",
"pre_expr : L_PARENTHESE TYPE R_PARENTHESE pre_expr",
"pre_expr : L_PARENTHESE TYPE MUL R_PARENTHESE pre_expr",
"pre_expr : MUL pre_expr",
"pre_expr : AND_OP pre_expr",
"pre_expr : post_expr",
"post_expr : post_expr INCREMENT",
"post_expr : post_expr DECREMENT",
"post_expr : post_expr L_PARENTHESE assign_expr COMMA assign_expr R_PARENTHESE",
"post_expr : UKADD L_PARENTHESE assign_expr COMMA assign_expr R_PARENTHESE",
"post_expr : CMPEQ L_PARENTHESE assign_expr COMMA assign_expr R_PARENTHESE",
"post_expr : UCMPLT L_PARENTHESE assign_expr COMMA assign_expr R_PARENTHESE",
"post_expr : UKSUB L_PARENTHESE assign_expr COMMA assign_expr R_PARENTHESE",
"post_expr : end_expr",
"end_expr : ID arr_expr",
"end_expr : ID",
"end_expr : NUM",
"end_expr : CHAR",
"end_expr : STRING",
"end_expr : FLOAT",
"end_expr : L_PARENTHESE assign_expr R_PARENTHESE",
"arr_expr : L_BRACKET assign_expr R_BRACKET",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 805 "parser.y"

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
#line 615 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 74 "parser.y"
	{
}
break;
case 2:
#line 77 "parser.y"
	{
    
}
break;
case 3:
#line 80 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 4:
#line 84 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 5:
#line 87 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 6:
#line 90 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 7:
#line 93 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 8:
#line 98 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[-2].stringVal;
}
break;
case 9:
#line 102 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 10:
#line 105 "parser.y"
	{
    yyval.stringVal = NULL;
}
break;
case 11:
#line 109 "parser.y"
	{
    int i =look_up_symbol(yystack.l_mark[-2].stringVal);
    fprintf(f_asm, "  // store in %s space in stack\n", yystack.l_mark[-2].stringVal);
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  sw t0, %d(s0)\n", table[i].offset * (-8));
    fprintf(f_asm, "  addi sp, sp, 8\n");
    yyval.stringVal = NULL;
}
break;
case 12:
#line 117 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 13:
#line 121 "parser.y"
	{
    install_symbol(yystack.l_mark[0].stringVal, "int", 1);
    fprintf(f_asm, "  // declare id %s and create its space in stack\n", yystack.l_mark[0].stringVal);
    fprintf(f_asm, "  addi sp, sp, -8\n");
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 14:
#line 127 "parser.y"
	{
    install_symbol(yystack.l_mark[0].stringVal, "int", 1);
    fprintf(f_asm, "  // declare id %s and create its space in stack\n", yystack.l_mark[0].stringVal);
    fprintf(f_asm, "  addi sp, sp, -8\n");
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 15:
#line 135 "parser.y"
	{
    
}
break;
case 16:
#line 139 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 17:
#line 142 "parser.y"
	{
   
}
break;
case 18:
#line 146 "parser.y"
	{
    
}
break;
case 19:
#line 149 "parser.y"
	{
   
}
break;
case 20:
#line 153 "parser.y"
	{
    int size = atoi(yystack.l_mark[0].stringVal);
    install_symbol(yystack.l_mark[-1].stringVal, "array", size);
    fprintf(f_asm, "  // pop %s to decide the arr space and create space in stack\n", yystack.l_mark[0].stringVal);
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  li t0, %d\n", size*8);
    fprintf(f_asm, "  sub sp, sp, t0\n");
    yyval.stringVal = NULL;
}
break;
case 21:
#line 163 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[-1].stringVal;
}
break;
case 22:
#line 167 "parser.y"
	{
   
}
break;
case 23:
#line 170 "parser.y"
	{
    
}
break;
case 24:
#line 173 "parser.y"
	{
   
}
break;
case 25:
#line 176 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 26:
#line 181 "parser.y"
	{
    fprintf(f_asm, ".global %s\n", yystack.l_mark[-6].stringVal);
    cur_para_cont = 0;
}
break;
case 27:
#line 185 "parser.y"
	{
    fprintf(f_asm, ".global %s\n", yystack.l_mark[-3].stringVal);
}
break;
case 28:
#line 189 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 29:
#line 192 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 30:
#line 197 "parser.y"
	{
    cur_scope++;
    install_symbol(yystack.l_mark[-3].stringVal, "arguement1", 0);
    install_symbol(yystack.l_mark[-1].stringVal, "arguement2", 0);
    code_gen_func_header(yystack.l_mark[-5].stringVal);
}
break;
case 31:
#line 202 "parser.y"
	{
    cur_scope--;
    yyval.stringVal = NULL;
}
break;
case 32:
#line 206 "parser.y"
	{
    cur_scope++;
    code_gen_func_header(yystack.l_mark[-2].stringVal);
}
break;
case 33:
#line 209 "parser.y"
	{
    cur_scope--;
    code_gen_at_end_of_function_body();
    yyval.stringVal = NULL;
}
break;
case 34:
#line 216 "parser.y"
	{
    
}
break;
case 35:
#line 219 "parser.y"
	{
    
}
break;
case 36:
#line 223 "parser.y"
	{}
break;
case 37:
#line 224 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 38:
#line 228 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 39:
#line 231 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 40:
#line 234 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 41:
#line 237 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 42:
#line 240 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 43:
#line 243 "parser.y"
	{
    
}
break;
case 44:
#line 246 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 45:
#line 249 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 46:
#line 252 "parser.y"
	{
    
}
break;
case 47:
#line 255 "parser.y"
	{

}
break;
case 48:
#line 258 "parser.y"
	{

}
break;
case 49:
#line 263 "parser.y"
	{
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
break;
case 50:
#line 279 "parser.y"
	{
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
break;
case 51:
#line 293 "parser.y"
	{}
break;
case 52:
#line 295 "parser.y"
	{
    cur_scope++;
    if_index++;
    if_i++;
    if_record[if_i] = if_index;
    fprintf(f_asm, "/* if%d start---------------------*/\n", if_record[if_i]);
}
break;
case 53:
#line 301 "parser.y"
	{
    fprintf(f_asm, "  // test whether to ignore if \n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  beq t0, zero, else%d\n", if_record[if_i]);
    fprintf(f_asm, "  j if%d\n", if_record[if_i]);
    fprintf(f_asm, "if%d:\n", if_record[if_i]);
}
break;
case 54:
#line 308 "parser.y"
	{
    fprintf(f_asm, "  j if%d_end\n", if_record[if_i]);
    yyval.stringVal = NULL;
}
break;
case 55:
#line 313 "parser.y"
	{
    fprintf(f_asm, "else%d:\n", if_record[if_i]);
}
break;
case 56:
#line 315 "parser.y"
	{
    fprintf(f_asm, "  j if%d_end\n", if_record[if_i]);
    fprintf(f_asm, "if%d_end:\n", if_record[if_i]);
    cur_scope--;
    if_i--;
}
break;
case 57:
#line 321 "parser.y"
	{
    fprintf(f_asm, "else%d:\n", if_record[if_i]);
    fprintf(f_asm, "if%d_end:\n", if_record[if_i]);
    cur_scope--;
    if_i--;
    yyval.stringVal = NULL;
}
break;
case 58:
#line 330 "parser.y"
	{
    cur_scope++;
    loop_index++;
    loop_i++;
    loop_record[loop_i] = loop_index;
    fprintf(f_asm, "/* loop%d(while) start------------*/\n", loop_record[loop_i]);
    fprintf(f_asm, "  j loop%d_cond\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d_cond:\n", loop_record[loop_i]);
}
break;
case 59:
#line 338 "parser.y"
	{
    fprintf(f_asm, "  // test whether to jump out the while loop\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  beq t0, zero, loop%d_end\n", loop_record[loop_i]);
    fprintf(f_asm, "  j loop%d\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d:\n", loop_record[loop_i]);
}
break;
case 60:
#line 345 "parser.y"
	{
    fprintf(f_asm, "  j loop%d_cond\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d_end:\n", loop_record[loop_i]);
    cur_scope--;
    loop_i--;
    yyval.stringVal = NULL;
}
break;
case 61:
#line 352 "parser.y"
	{
    cur_scope++;
    loop_index++;
    loop_i++;
    loop_record[loop_i] = loop_index;
    fprintf(f_asm, "/* loop%d(do-while) start---------*/\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d:\n", loop_record[loop_i]);
}
break;
case 62:
#line 359 "parser.y"
	{
    fprintf(f_asm, "  j loop%d_cond\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d_cond:\n", loop_record[loop_i]);
}
break;
case 63:
#line 362 "parser.y"
	{
    fprintf(f_asm, "  // test whether to jump out the while loop\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  beq t0, zero, loop%d_end\n", loop_record[loop_i]);
    fprintf(f_asm, "  j loop%d\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d_end:\n", loop_record[loop_i]);
    cur_scope--;
    loop_i--;
}
break;
case 64:
#line 374 "parser.y"
	{
    loop_index++;
    loop_i++;
    loop_record[loop_i] = loop_index;
    cur_scope++;
    fprintf(f_asm, "/* loop%d(for) start-------------*/\n", loop_record[loop_i]);

}
break;
case 65:
#line 381 "parser.y"
	{
    fprintf(f_asm, "  j loop%d\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d_cond:\n", loop_record[loop_i]);
}
break;
case 66:
#line 384 "parser.y"
	{
    /* pop to the first to see 1 or 0*/
    fprintf(f_asm, "  // test whether to jump out the for loop\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  beq t0, zero, loop%d_end\n", loop_record[loop_i]);
    fprintf(f_asm, "  j loop%d\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d_last_cond:\n", loop_record[loop_i]);
}
break;
case 67:
#line 392 "parser.y"
	{
    fprintf(f_asm, "  j loop%d_cond\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d:\n", loop_record[loop_i]);
}
break;
case 68:
#line 395 "parser.y"
	{
    fprintf(f_asm, "  j loop%d_last_cond\n", loop_record[loop_i]);
    fprintf(f_asm, "loop%d_end:\n", loop_record[loop_i]);
    cur_scope--;
    loop_i--;
    yyval.stringVal = NULL;
}
break;
case 69:
#line 403 "parser.y"
	{
    
}
break;
case 70:
#line 406 "parser.y"
	{
    
}
break;
case 71:
#line 410 "parser.y"
	{
    
}
break;
case 72:
#line 413 "parser.y"
	{
    
}
break;
case 73:
#line 419 "parser.y"
	{
    fprintf(f_asm, "  // pop first one to return\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi a0, t0, 0\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    code_gen_at_end_of_function_body();
}
break;
case 74:
#line 428 "parser.y"
	{
    fprintf(f_asm, "  // break the cur loop\n");
    fprintf(f_asm, "  j loop%d_end\n", loop_record[loop_i]);
}
break;
case 75:
#line 434 "parser.y"
	{
    fprintf(f_asm, "  // pop first two to assign(t0 is value, t1 is offset)\n");
    /*pop first, but the second isn't necessary*/
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 4(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    /*calculate the absolute address*/
    fprintf(f_asm, "  li t2, -8\n");
    fprintf(f_asm, "  mul t1, t1, t2\n");
    fprintf(f_asm, "  add t1, t1, s0\n");
    fprintf(f_asm, "  sw t0, 0(t1)\n");
    yyval.stringVal = NULL;
}
break;
case 76:
#line 448 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 77:
#line 453 "parser.y"
	{
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
    yyval.stringVal = NULL;
}
break;
case 78:
#line 471 "parser.y"
	{
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
    yyval.stringVal = NULL;
}
break;
case 79:
#line 489 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 80:
#line 494 "parser.y"
	{
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
    yyval.stringVal = NULL;
}
break;
case 81:
#line 512 "parser.y"
	{
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
    yyval.stringVal = NULL;
}
break;
case 82:
#line 530 "parser.y"
	{
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
    yyval.stringVal = NULL;
}
break;
case 83:
#line 548 "parser.y"
	{
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
    yyval.stringVal = NULL;
}
break;
case 84:
#line 566 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 85:
#line 571 "parser.y"
	{
    fprintf(f_asm, "  // pop first two to add\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  add t0, t0, t1\n");
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    yyval.stringVal = NULL;
}
break;
case 86:
#line 582 "parser.y"
	{
    fprintf(f_asm, "  // pop first two to sub\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  sub t0, t1, t0\n");
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    yyval.stringVal = NULL;
}
break;
case 87:
#line 593 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 88:
#line 598 "parser.y"
	{
    fprintf(f_asm, "  // pop first two to mul\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  mul t0, t0, t1\n");
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    yyval.stringVal = NULL;
}
break;
case 89:
#line 609 "parser.y"
	{
    fprintf(f_asm, "  // pop first two to div\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  div t0, t1, t0\n");
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    yyval.stringVal = NULL;
}
break;
case 90:
#line 620 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 91:
#line 626 "parser.y"
	{
    
}
break;
case 92:
#line 629 "parser.y"
	{
    
}
break;
case 93:
#line 632 "parser.y"
	{
   
}
break;
case 94:
#line 635 "parser.y"
	{
    fprintf(f_asm, "  // pop id then push -id into stack\n");
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  sub t0, zero, t0\n");
    fprintf(f_asm, "  sw t0, 0(sp)\n");
    yyval.stringVal = NULL;
}
break;
case 95:
#line 642 "parser.y"
	{
    
}
break;
case 96:
#line 645 "parser.y"
	{
    
}
break;
case 97:
#line 648 "parser.y"
	{
    
}
break;
case 98:
#line 651 "parser.y"
	{
    
}
break;
case 99:
#line 654 "parser.y"
	{
    fprintf(f_asm, "  // pop id then push *id into stack\n");
    /* load the value (that address) and save as address*/
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  sw t0, 4(sp)\n");
    /* save the value at that address*/
    fprintf(f_asm, "  li t1, -8\n");
    fprintf(f_asm, "  mul t0, t0, t1\n");
    fprintf(f_asm, "  add t0, t0, s0\n");
    fprintf(f_asm, "  lw t1, 0(t0)\n");
    fprintf(f_asm, "  sw t1, 0(sp)\n");
    yyval.stringVal = NULL;
    
}
break;
case 100:
#line 668 "parser.y"
	{
    fprintf(f_asm, "  // pop id then push &id into stack\n");
    /* get address and save the address as value*/
    fprintf(f_asm, "  lw t0, 4(sp)\n");
    fprintf(f_asm, "  sw t0, 0(sp)\n");
    yyval.stringVal = NULL;
}
break;
case 101:
#line 675 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 102:
#line 680 "parser.y"
	{
    
}
break;
case 103:
#line 683 "parser.y"
	{
    
}
break;
case 104:
#line 686 "parser.y"
	{}
break;
case 105:
#line 687 "parser.y"
	{
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  ukadd8 t0, t0, t1\n");
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
}
break;
case 106:
#line 696 "parser.y"
	{
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  cmpeq8 t2, t1, t0\n");
    fprintf(f_asm, "  sw t2, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
}
break;
case 107:
#line 705 "parser.y"
	{
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  ucmplt8 t2, t1, t0\n");
    fprintf(f_asm, "  sw t2, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
}
break;
case 108:
#line 714 "parser.y"
	{
    fprintf(f_asm, "  lw t0, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  uksub8 t0, t1, t0\n");
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
}
break;
case 109:
#line 723 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 110:
#line 729 "parser.y"
	{
    int i = look_up_symbol(yystack.l_mark[-1].stringVal);
    fprintf(f_asm, "  // pop the index and push array element value\n");
    fprintf(f_asm, "  li t0, %d\n", table[i].offset);
    /* pop index to calculate*/
    fprintf(f_asm, "  lw t1, 0(sp)\n");
    fprintf(f_asm, "  addi sp, sp, 8\n");
    fprintf(f_asm, "  add t0, t1, t0\n");
    /* save the offset*/
    fprintf(f_asm, "  sw t0, -4(sp)\n");
    /* calculate the absolute address*/
    fprintf(f_asm, "  li t1, -8\n");
    fprintf(f_asm, "  mul t2, t0, t1\n");
    fprintf(f_asm, "  add t3, t2, s0\n");
    /* save the value*/
    fprintf(f_asm, "  lw t0, 0(t3)\n");
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    yyval.stringVal = NULL;
}
break;
case 111:
#line 749 "parser.y"
	{
    int i = look_up_symbol(yystack.l_mark[0].stringVal);
    if (i >= 0) {
        if (strcmp(table[i].type, "int") == 0) {
            fprintf(f_asm, "  // push value %s into stack\n", yystack.l_mark[0].stringVal);
            /* save the offset*/
            fprintf(f_asm, "  li t0, %d\n", table[i].offset);
            fprintf(f_asm, "  sw t0, -4(sp)\n");
            /* if is int, save the value*/
            fprintf(f_asm, "  lw t0, %d(s0)\n", table[i].offset * (-8));
            fprintf(f_asm, "  sw t0, -8(sp)\n");
            fprintf(f_asm, "  addi sp, sp, -8\n");
        } else if (strcmp(table[i].type, "arguement1") == 0){
            /* if is argument1 get from a0*/
            fprintf(f_asm, "  // push value %s into stack\n", yystack.l_mark[0].stringVal);
            fprintf(f_asm, "  addi t0, a0, 0\n");
            fprintf(f_asm, "  sw t0, -8(sp)\n");
            fprintf(f_asm, "  addi sp, sp, -8\n");
        } else if (strcmp(table[i].type, "arguement2") == 0){
            /* if is argument2 get from a1*/
            fprintf(f_asm, "  // push value %s into stack\n", yystack.l_mark[0].stringVal);
            fprintf(f_asm, "  addi t0, a1, 0\n");
            fprintf(f_asm, "  sw t0, -8(sp)\n");
            fprintf(f_asm, "  addi sp, sp, -8\n");
        } else {
            fprintf(f_asm, "  // push value %s into stack\n", yystack.l_mark[0].stringVal);
            /* save the offset*/
            fprintf(f_asm, "  li t0, %d\n", table[i].offset);
            fprintf(f_asm, "  sw t0, -4(sp)\n");
            /* if is array, save the offset*/
            fprintf(f_asm, "  sw t0, -8(sp)\n");
            fprintf(f_asm, "  addi sp, sp, -8\n");
        }
    }
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 112:
#line 785 "parser.y"
	{
    fprintf(f_asm, "  // push %d into stack\n", yystack.l_mark[0].intVal);
    /* save the value*/
    fprintf(f_asm, "  li t0, %d\n", yystack.l_mark[0].intVal);
    fprintf(f_asm, "  sw t0, -8(sp)\n");
    fprintf(f_asm, "  addi sp, sp, -8\n");
    char* tem = int_to_string(yystack.l_mark[0].intVal);
    yyval.stringVal = tem;
}
break;
case 113:
#line 794 "parser.y"
	{}
break;
case 114:
#line 795 "parser.y"
	{}
break;
case 115:
#line 796 "parser.y"
	{}
break;
case 116:
#line 797 "parser.y"
	{}
break;
case 117:
#line 799 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[-1].stringVal;
}
break;
#line 1848 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}

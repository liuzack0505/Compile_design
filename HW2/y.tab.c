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
#line 33 "parser.y"
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
#line 65 "y.tab.c"

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
#define SWITCH 265
#define CASE 266
#define DEFAULT 267
#define WHILE 268
#define DO 269
#define FOR 270
#define RETURN 271
#define BREAK 272
#define CONTINUE 273
#define COMMA 274
#define SEMICOLON 275
#define COLON 276
#define ASSIGN 277
#define R_BRACKET 278
#define L_BRACKET 279
#define R_BRACE 280
#define L_BRACE 281
#define R_PARENTHESE 282
#define L_PARENTHESE 283
#define AND 284
#define OR 285
#define AND_OP 286
#define XOR_OP 287
#define OR_OP 288
#define EQUAL 289
#define NOT_EQUAL 290
#define LESS 291
#define GREATER 292
#define LESS_EQUAL 293
#define GREATER_EQUAL 294
#define L_SHIFT 295
#define R_SHIFT 296
#define PLUS 297
#define MINUS 298
#define MUL 299
#define DIV 300
#define PERCENT 301
#define INCREMENT 302
#define DECREMENT 303
#define NOT 304
#define NOT_OP 305
#define UPLUS 306
#define UMINUS 307
#define POINTER 308
#define ADDRESS_Of 309
#define POST_INC 310
#define POST_DEC 311
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    2,    3,    6,    6,
    4,    4,    5,    5,    9,   10,   10,   11,   11,   12,
   14,   14,   13,   13,   13,   13,   15,   15,   15,   15,
   17,   17,   18,   18,   16,   16,   16,   16,   19,   19,
   20,   20,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   22,   22,   23,   23,   24,   24,   25,
   25,   25,   25,   26,   26,   27,   28,   28,   29,   29,
   30,   30,   31,   32,    8,    8,    7,    7,   33,   33,
   34,   34,   35,   35,   36,   36,   37,   37,   38,   38,
   38,   39,   39,   39,   39,   39,   40,   40,   40,   41,
   41,   41,   42,   42,   42,   42,   43,   43,   43,   43,
   43,   43,   43,   43,   43,   43,   43,   44,   44,   44,
   44,   44,   45,   45,   45,   45,   45,   45,   45,   46,
   46,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    1,    1,    1,    1,    3,    1,    3,
    3,    1,    1,    2,    3,    1,    3,    5,    1,    2,
    4,    3,    3,    5,    3,    1,    6,    5,    7,    6,
    3,    1,    2,    3,    6,    5,    7,    6,    3,    2,
    2,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    2,    5,    7,    7,    6,    2,    1,    4,
    3,    3,    2,    5,    7,    6,    2,    1,    2,    1,
    3,    2,    2,    2,    3,    1,    3,    1,    3,    1,
    3,    1,    3,    1,    3,    1,    3,    1,    3,    3,
    1,    3,    3,    3,    3,    1,    3,    3,    1,    3,
    3,    1,    3,    3,    3,    1,    2,    2,    2,    2,
    2,    2,    4,    5,    2,    2,    1,    2,    2,    3,
    4,    1,    2,    1,    1,    1,    1,    1,    3,    4,
    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    3,    4,    5,    6,    7,    0,    0,
    9,    0,    0,    0,   16,    0,    2,    0,    0,    0,
    0,    0,    0,    8,    0,   15,    0,  125,  126,  127,
  128,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  106,    0,  122,    0,    0,    0,   32,    0,
    0,   11,   13,    0,   10,    0,   17,    0,    0,    0,
    0,    0,  116,  109,  110,  115,  107,  108,  111,  112,
   22,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  118,  119,   33,    0,   28,    0,   36,    0,    0,
    0,    0,    0,   14,    0,   26,    0,    0,    0,    0,
    0,  129,   77,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  103,  104,
  105,  120,   76,    0,   34,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   40,   51,    0,   52,   50,    0,
   42,   43,   44,   45,   46,   47,   48,   49,   31,   27,
   35,   21,   30,   38,    0,    0,    0,   18,  131,    0,
  113,    0,    0,  121,    0,    0,    0,    0,    0,    0,
   72,    0,   73,   74,   53,   39,   41,   29,   37,   23,
    0,   25,  130,  114,   75,    0,    0,    0,    0,   68,
    0,    0,   71,    0,    0,    0,    0,    0,   67,    0,
   24,    0,    0,   64,    0,   70,    0,    0,    0,    0,
    0,   57,    0,   59,    0,   69,   66,   55,    0,    0,
   56,   58,   65,    0,    0,    0,
};
static const YYINT yydgoto[] = {                          2,
    3,    4,  156,   11,   12,   13,  157,  144,  158,   14,
   15,   16,  117,   20,    7,    8,   58,   59,  159,  160,
  161,  162,  163,  233,  234,  164,  165,  212,  228,  166,
  167,  168,   43,   44,   45,   46,   47,   48,   49,   50,
   51,   52,   53,   54,   55,   70,
};
static const YYINT yysindex[] = {                      -235,
 -246,    0, -235,    0,    0,    0,    0,    0, -183, -259,
    0, -249,  -71,  -35,    0, -211,    0,  -61, -243, -191,
 -215,  -61, -245,    0, -164,    0, -165,    0,    0,    0,
    0, -161, -155,  -61,  -61,  -61,  -61,  -61,  -61,  -61,
  -61, -112, -258, -132, -124, -106, -113,  -41,  -20,  -32,
  -22,   53,    0, -218,    0, -240, -250, -253,    0,  -61,
 -241,    0,    0,  -87,    0,  -94,    0,   76,  -61,  -86,
 -269,  -21,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,
  -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,  -61,
  106,    0,    0,    0,  -67,    0,   -3,    0,  -34, -182,
  -48, -146, -207,    0,   76,    0, -144,    1,  -61,  -61,
    5,    0,    0, -132, -124, -106, -113,  -41,  -20,  -20,
  -32,  -32,  -32,  -32,  -22,  -22,   53,   53,    0,    0,
    0,    0,    0, -192,    0, -239,    6,    8,   27, -225,
   41,  137,   18,   50,    0,    0,   62,    0,    0,   46,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -120, -135,  167,    0,    0,   63,
    0,  -61,  -61,    0,  -94,  -61,  -61,  -61,   60,  198,
    0,   80,    0,    0,    0,    0,    0,    0,    0,    0,
   76,    0,    0,    0,    0,   74,   78,   79,   75,    0,
   92,  198,    0, -118,   88,   89, -225,  -61,    0,  228,
    0,  107, -204,    0,   90,    0,   94, -225,   88,  -61,
  101,    0, -172,    0,  108,    0,    0,    0,  109, -225,
    0,    0,    0, -225, -225, -225,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  382,    0,    0,    0,    0,    0,  -51,    0,
    0,    7,    0,    0,    0,   23,    0,    0,    0,  -42,
   65,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  260,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   10,  169,  704,  674,  644,  614, -163,  492,
  423,  348,    0,  320,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  290,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  728,  716,  689,  659,  629,  -98,  597,
  513,  534,  555,  576,  446,  469,  373,  398,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -51,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -52,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -134,
    0,    0,    0, -129, -126, -109,
};
static const YYINT yygindex[] = {                         0,
    0,  381,   49,  363,    0,    0,  -18,    0,   86,    0,
  362,    0, -114,    0,    0,    0,  329,  282,  -55,  -77,
 -136,    0,    0,    0,  160,    0,    0,  186,    0,    0,
    0,    0,    0,  317,  318,  316,  321,  319,  224,  230,
  236,  250,  -29,    0,    0,    0,
};
#define YYTABLESIZE 1013
static const YYINT yytable[] = {                         42,
  176,  108,   21,   62,   73,   74,   75,   76,   77,   78,
   79,   80,  120,  189,   72,    9,   63,   56,   82,   56,
  109,  104,  185,  197,  106,    1,   83,   22,  110,  121,
  107,   28,   29,   30,   31,  146,   32,  147,   57,  148,
  112,  111,  149,  150,  151,  152,  153,  154,    5,  116,
  118,    5,   10,   64,  171,  107,  174,   33,  105,   64,
   34,  230,  231,  123,  101,   27,  109,   61,  139,  140,
  141,   35,   36,   37,  175,  232,   38,   39,   40,   41,
  224,  183,  143,  102,  103,    6,  214,   60,    6,  184,
  181,  237,  170,  230,  231,   18,  116,   66,  107,   19,
  180,   28,   29,   30,   31,   71,   32,  241,  197,  197,
   91,   91,   91,   91,   91,   68,   91,   69,   91,  199,
   91,   91,   91,   91,   91,   91,   91,   33,  173,  177,
   34,   63,   63,  192,  107,  178,   61,   61,  177,   62,
   62,   35,   36,   37,  200,   63,   38,   39,   40,   41,
   61,   84,  204,   62,  198,  177,   60,   60,  202,  222,
  107,  221,  245,   85,  205,   81,  246,  206,  207,  208,
   60,  211,   87,  238,  114,   89,   89,   89,   89,   89,
   86,   89,  116,   89,   18,   89,   89,   89,   89,   89,
   89,   89,  119,  211,  145,   28,   29,   30,   31,  225,
   32,  227,   23,   24,   54,   54,   54,   54,   54,   54,
   54,  239,   54,   54,   54,   54,   54,   54,   54,   54,
   54,   33,   13,   13,   34,   13,   56,   54,   54,  172,
   54,   20,   20,   54,   20,   35,   36,   37,   25,   26,
   38,   39,   40,   41,   54,   54,   54,   88,   89,   54,
   54,   54,   54,   28,   29,   30,   31,  146,   32,  147,
  122,  148,   94,   95,  149,  150,  151,  152,  153,  154,
   90,   91,   92,   93,   96,   97,  155,  107,  179,   33,
   12,   12,   34,   78,   78,   78,  182,   78,  186,   78,
  187,   78,  193,   35,   36,   37,   19,   19,   38,   39,
   40,   41,   28,   29,   30,   31,  146,   32,  147,  188,
  148,  129,  130,  149,  150,  151,  152,  153,  154,  131,
  132,  133,  134,  190,  194,  196,  107,  209,   33,  135,
  136,   34,   28,   29,   30,   31,  195,   32,   14,   14,
  203,   14,   35,   36,   37,  137,  138,   38,   39,   40,
   41,   98,   99,  100,  213,  215,  115,  218,   33,  216,
  217,   34,   28,   29,   30,   31,  219,   32,  107,  223,
  229,  235,   35,   36,   37,  236,  240,   38,   39,   40,
   41,    1,  243,   17,  244,   65,   67,  142,   33,  113,
  169,   34,  242,   28,   29,   30,   31,  220,   32,  124,
  126,  125,   35,   36,   37,  128,  127,   38,   39,   40,
   41,  191,    0,    0,    0,    0,    0,    0,    0,   33,
    0,    0,   34,   28,   29,   30,   31,    0,   32,    0,
    0,    0,    0,   35,   36,   37,    0,    0,   38,   39,
   40,   41,   80,   80,   80,   80,   80,  201,   80,   33,
   80,    0,   34,   80,   28,   29,   30,   31,    0,   32,
    0,    0,    0,   35,   36,   37,    0,    0,   38,   39,
   40,   41,  210,    0,    0,    0,    0,    0,    0,    0,
   33,    0,    0,   34,   28,   29,   30,   31,    0,   32,
    0,    0,    0,    0,   35,   36,   37,    0,    0,   38,
   39,   40,   41,    0,    0,    0,    0,    0,    0,  226,
   33,    0,    0,   34,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   35,   36,   37,    0,    0,   38,
   39,   40,   41,  124,  124,  124,  124,  124,    0,  124,
    0,  124,  124,  124,  124,  124,  124,  124,  124,  124,
  124,  124,  124,  124,  124,  124,  124,  124,  124,  124,
  124,  124,  124,  123,  123,  123,  123,  123,    0,  123,
    0,  123,  123,  123,  123,  123,  123,  123,  123,  123,
  123,  123,  123,  123,  123,  123,  123,  123,  123,  123,
  123,  123,  123,  117,  117,  117,  117,  117,    0,  117,
    0,  117,    0,  117,  117,  117,  117,  117,  117,  117,
  117,  117,  117,  117,  117,  117,  117,  117,  117,  117,
  117,  102,  102,  102,  102,  102,    0,  102,    0,  102,
    0,  102,  102,  102,  102,  102,  102,  102,  102,  102,
  102,  102,  102,  102,  102,  102,  100,  100,  100,  100,
  100,    0,  100,    0,  100,    0,  100,  100,  100,  100,
  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,
  100,  101,  101,  101,  101,  101,    0,  101,    0,  101,
    0,  101,  101,  101,  101,  101,  101,  101,  101,  101,
  101,  101,  101,  101,  101,  101,   99,   99,   99,   99,
   99,    0,   99,    0,   99,    0,   99,   99,   99,   99,
   99,   99,   99,   99,   99,   99,   99,   99,   99,   97,
   97,   97,   97,   97,    0,   97,    0,   97,    0,   97,
   97,   97,   97,   97,   97,   97,   97,   97,   97,   97,
   97,   97,   98,   98,   98,   98,   98,    0,   98,    0,
   98,    0,   98,   98,   98,   98,   98,   98,   98,   98,
   98,   98,   98,   98,   98,   96,   96,   96,   96,   96,
    0,   96,    0,   96,    0,   96,   96,   96,   96,   96,
   96,   96,   96,   96,   96,   96,   92,   92,   92,   92,
   92,    0,   92,    0,   92,    0,   92,   92,   92,   92,
   92,   92,   92,   92,   92,   92,   92,   93,   93,   93,
   93,   93,    0,   93,    0,   93,    0,   93,   93,   93,
   93,   93,   93,   93,   93,   93,   93,   93,   94,   94,
   94,   94,   94,    0,   94,    0,   94,    0,   94,   94,
   94,   94,   94,   94,   94,   94,   94,   94,   94,   95,
   95,   95,   95,   95,    0,   95,    0,   95,    0,   95,
   95,   95,   95,   95,   95,   95,   95,   95,   95,   95,
   90,   90,   90,   90,   90,    0,   90,    0,   90,    0,
   90,   90,   90,   90,   90,   90,   90,   88,   88,   88,
   88,   88,    0,   88,    0,   88,    0,   88,   88,   88,
   88,   88,   87,   87,   87,   87,   87,    0,   87,    0,
   87,    0,   87,   87,   87,   87,   87,   86,   86,   86,
   86,   86,    0,   86,    0,   86,    0,   86,   86,    0,
   86,   86,   85,   85,   85,   85,   85,    0,   85,    0,
   85,    0,   85,   85,    0,   85,   85,   84,   84,   84,
   84,   84,    0,   84,    0,   84,    0,   84,   84,    0,
    0,   84,   83,   83,   83,   83,   83,    0,   83,    0,
   83,    0,   83,   83,    0,    0,   83,   82,   82,   82,
   82,   82,    0,   82,    0,   82,    0,   82,   82,   81,
   81,   81,   81,   81,    0,   81,    0,   81,    0,   81,
   81,   79,   79,   79,   79,   79,    0,   79,    0,   79,
    0,    0,   79,
};
static const YYINT yycheck[] = {                         18,
  115,   57,  262,   22,   34,   35,   36,   37,   38,   39,
   40,   41,  282,  150,   33,  262,  262,  261,  277,  261,
  274,  262,  262,  160,  275,  261,  285,  277,  282,  299,
  281,  257,  258,  259,  260,  261,  262,  263,  282,  265,
  282,   60,  268,  269,  270,  271,  272,  273,    0,   68,
   69,    3,  299,  299,  110,  281,  112,  283,  299,  299,
  286,  266,  267,   82,  283,  277,  274,  283,   98,   99,
  100,  297,  298,  299,  282,  280,  302,  303,  304,  305,
  217,  274,  101,  302,  303,    0,  201,  279,    3,  282,
  120,  228,  275,  266,  267,  279,  115,  262,  281,  283,
  119,  257,  258,  259,  260,  261,  262,  280,  245,  246,
  274,  275,  276,  277,  278,  281,  280,  279,  282,  175,
  284,  285,  286,  287,  288,  289,  290,  283,  275,  274,
  286,  266,  267,  152,  281,  280,  266,  267,  274,  266,
  267,  297,  298,  299,  280,  280,  302,  303,  304,  305,
  280,  284,  182,  280,  275,  274,  266,  267,  177,  215,
  281,  280,  240,  288,  183,  278,  244,  186,  187,  188,
  280,  190,  286,  229,  262,  274,  275,  276,  277,  278,
  287,  280,  201,  282,  279,  284,  285,  286,  287,  288,
  289,  290,  279,  212,  262,  257,  258,  259,  260,  218,
  262,  220,  274,  275,  257,  258,  259,  260,  261,  262,
  263,  230,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  283,  274,  275,  286,  277,  261,  280,  281,  278,
  283,  274,  275,  286,  277,  297,  298,  299,  274,  275,
  302,  303,  304,  305,  297,  298,  299,  289,  290,  302,
  303,  304,  305,  257,  258,  259,  260,  261,  262,  263,
  282,  265,  295,  296,  268,  269,  270,  271,  272,  273,
  291,  292,  293,  294,  297,  298,  280,  281,  278,  283,
  274,  275,  286,  274,  275,  276,  282,  278,  283,  280,
  283,  282,  275,  297,  298,  299,  274,  275,  302,  303,
  304,  305,  257,  258,  259,  260,  261,  262,  263,  283,
  265,   88,   89,  268,  269,  270,  271,  272,  273,   90,
   91,   92,   93,  283,  275,  280,  281,  268,  283,   94,
   95,  286,  257,  258,  259,  260,  275,  262,  274,  275,
  278,  277,  297,  298,  299,   96,   97,  302,  303,  304,
  305,  299,  300,  301,  275,  282,  281,  283,  283,  282,
  282,  286,  257,  258,  259,  260,  275,  262,  281,  281,
  264,  282,  297,  298,  299,  282,  276,  302,  303,  304,
  305,    0,  275,    3,  276,   23,   25,  282,  283,   61,
  109,  286,  233,  257,  258,  259,  260,  212,  262,   83,
   85,   84,  297,  298,  299,   87,   86,  302,  303,  304,
  305,  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  283,
   -1,   -1,  286,  257,  258,  259,  260,   -1,  262,   -1,
   -1,   -1,   -1,  297,  298,  299,   -1,   -1,  302,  303,
  304,  305,  274,  275,  276,  277,  278,  281,  280,  283,
  282,   -1,  286,  285,  257,  258,  259,  260,   -1,  262,
   -1,   -1,   -1,  297,  298,  299,   -1,   -1,  302,  303,
  304,  305,  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  283,   -1,   -1,  286,  257,  258,  259,  260,   -1,  262,
   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,  302,
  303,  304,  305,   -1,   -1,   -1,   -1,   -1,   -1,  282,
  283,   -1,   -1,  286,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,  302,
  303,  304,  305,  274,  275,  276,  277,  278,   -1,  280,
   -1,  282,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  292,  293,  294,  295,  296,  297,  298,  299,  300,
  301,  302,  303,  274,  275,  276,  277,  278,   -1,  280,
   -1,  282,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  292,  293,  294,  295,  296,  297,  298,  299,  300,
  301,  302,  303,  274,  275,  276,  277,  278,   -1,  280,
   -1,  282,   -1,  284,  285,  286,  287,  288,  289,  290,
  291,  292,  293,  294,  295,  296,  297,  298,  299,  300,
  301,  274,  275,  276,  277,  278,   -1,  280,   -1,  282,
   -1,  284,  285,  286,  287,  288,  289,  290,  291,  292,
  293,  294,  295,  296,  297,  298,  274,  275,  276,  277,
  278,   -1,  280,   -1,  282,   -1,  284,  285,  286,  287,
  288,  289,  290,  291,  292,  293,  294,  295,  296,  297,
  298,  274,  275,  276,  277,  278,   -1,  280,   -1,  282,
   -1,  284,  285,  286,  287,  288,  289,  290,  291,  292,
  293,  294,  295,  296,  297,  298,  274,  275,  276,  277,
  278,   -1,  280,   -1,  282,   -1,  284,  285,  286,  287,
  288,  289,  290,  291,  292,  293,  294,  295,  296,  274,
  275,  276,  277,  278,   -1,  280,   -1,  282,   -1,  284,
  285,  286,  287,  288,  289,  290,  291,  292,  293,  294,
  295,  296,  274,  275,  276,  277,  278,   -1,  280,   -1,
  282,   -1,  284,  285,  286,  287,  288,  289,  290,  291,
  292,  293,  294,  295,  296,  274,  275,  276,  277,  278,
   -1,  280,   -1,  282,   -1,  284,  285,  286,  287,  288,
  289,  290,  291,  292,  293,  294,  274,  275,  276,  277,
  278,   -1,  280,   -1,  282,   -1,  284,  285,  286,  287,
  288,  289,  290,  291,  292,  293,  294,  274,  275,  276,
  277,  278,   -1,  280,   -1,  282,   -1,  284,  285,  286,
  287,  288,  289,  290,  291,  292,  293,  294,  274,  275,
  276,  277,  278,   -1,  280,   -1,  282,   -1,  284,  285,
  286,  287,  288,  289,  290,  291,  292,  293,  294,  274,
  275,  276,  277,  278,   -1,  280,   -1,  282,   -1,  284,
  285,  286,  287,  288,  289,  290,  291,  292,  293,  294,
  274,  275,  276,  277,  278,   -1,  280,   -1,  282,   -1,
  284,  285,  286,  287,  288,  289,  290,  274,  275,  276,
  277,  278,   -1,  280,   -1,  282,   -1,  284,  285,  286,
  287,  288,  274,  275,  276,  277,  278,   -1,  280,   -1,
  282,   -1,  284,  285,  286,  287,  288,  274,  275,  276,
  277,  278,   -1,  280,   -1,  282,   -1,  284,  285,   -1,
  287,  288,  274,  275,  276,  277,  278,   -1,  280,   -1,
  282,   -1,  284,  285,   -1,  287,  288,  274,  275,  276,
  277,  278,   -1,  280,   -1,  282,   -1,  284,  285,   -1,
   -1,  288,  274,  275,  276,  277,  278,   -1,  280,   -1,
  282,   -1,  284,  285,   -1,   -1,  288,  274,  275,  276,
  277,  278,   -1,  280,   -1,  282,   -1,  284,  285,  274,
  275,  276,  277,  278,   -1,  280,   -1,  282,   -1,  284,
  285,  274,  275,  276,  277,  278,   -1,  280,   -1,  282,
   -1,   -1,  285,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 311
#define YYUNDFTOKEN 360
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
"TYPE","ID","IF","ELSE","SWITCH","CASE","DEFAULT","WHILE","DO","FOR","RETURN",
"BREAK","CONTINUE","COMMA","SEMICOLON","COLON","ASSIGN","R_BRACKET","L_BRACKET",
"R_BRACE","L_BRACE","R_PARENTHESE","L_PARENTHESE","AND","OR","AND_OP","XOR_OP",
"OR_OP","EQUAL","NOT_EQUAL","LESS","GREATER","LESS_EQUAL","GREATER_EQUAL",
"L_SHIFT","R_SHIFT","PLUS","MINUS","MUL","DIV","PERCENT","INCREMENT",
"DECREMENT","NOT","NOT_OP","UPLUS","UMINUS","POINTER","ADDRESS_Of","POST_INC",
"POST_DEC",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"arr_dim : arr_dim L_BRACKET assign_expr R_BRACKET",
"arr_dim : L_BRACKET assign_expr R_BRACKET",
"arr_content : L_BRACE arr_content R_BRACE",
"arr_content : arr_content COMMA L_BRACE arr_content R_BRACE",
"arr_content : arr_content COMMA assign_expr",
"arr_content : assign_expr",
"func_decl : TYPE ID L_PARENTHESE parameters R_PARENTHESE SEMICOLON",
"func_decl : TYPE ID L_PARENTHESE R_PARENTHESE SEMICOLON",
"func_decl : TYPE MUL ID L_PARENTHESE parameters R_PARENTHESE SEMICOLON",
"func_decl : TYPE MUL ID L_PARENTHESE R_PARENTHESE SEMICOLON",
"parameters : parameters COMMA parameter",
"parameters : parameter",
"parameter : TYPE ID",
"parameter : TYPE MUL ID",
"func_def : TYPE ID L_PARENTHESE parameters R_PARENTHESE compound_stmt",
"func_def : TYPE ID L_PARENTHESE R_PARENTHESE compound_stmt",
"func_def : TYPE MUL ID L_PARENTHESE parameters R_PARENTHESE compound_stmt",
"func_def : TYPE MUL ID L_PARENTHESE R_PARENTHESE compound_stmt",
"compound_stmt : L_BRACE stmts R_BRACE",
"compound_stmt : L_BRACE R_BRACE",
"stmts : stmts stmt",
"stmts : stmt",
"stmt : if_else_stmt",
"stmt : switch_stmt",
"stmt : while_stmt",
"stmt : for_stmt",
"stmt : return_stmt",
"stmt : break_stmt",
"stmt : continue_stmt",
"stmt : compound_stmt",
"stmt : scalar_decl",
"stmt : array_decl",
"stmt : assign_expr SEMICOLON",
"if_else_stmt : IF L_PARENTHESE assign_expr R_PARENTHESE compound_stmt",
"if_else_stmt : IF L_PARENTHESE assign_expr R_PARENTHESE compound_stmt ELSE compound_stmt",
"switch_stmt : SWITCH L_PARENTHESE assign_expr R_PARENTHESE L_BRACE switch_clauses R_BRACE",
"switch_stmt : SWITCH L_PARENTHESE assign_expr R_PARENTHESE L_BRACE R_BRACE",
"switch_clauses : switch_clauses switch_clause",
"switch_clauses : switch_clause",
"switch_clause : CASE assign_expr COLON stmts",
"switch_clause : CASE assign_expr COLON",
"switch_clause : DEFAULT COLON stmts",
"switch_clause : DEFAULT COLON",
"while_stmt : WHILE L_PARENTHESE assign_expr R_PARENTHESE stmt",
"while_stmt : DO stmt WHILE L_PARENTHESE assign_expr R_PARENTHESE SEMICOLON",
"for_stmt : FOR L_PARENTHESE for_cond for_cond for_last_cond stmt",
"for_cond : assign_expr SEMICOLON",
"for_cond : SEMICOLON",
"for_last_cond : assign_expr R_PARENTHESE",
"for_last_cond : R_PARENTHESE",
"return_stmt : RETURN assign_expr SEMICOLON",
"return_stmt : RETURN SEMICOLON",
"break_stmt : BREAK SEMICOLON",
"continue_stmt : CONTINUE SEMICOLON",
"exprs : exprs COMMA assign_expr",
"exprs : assign_expr",
"assign_expr : or_expr ASSIGN assign_expr",
"assign_expr : or_expr",
"or_expr : or_expr OR and_expr",
"or_expr : and_expr",
"and_expr : and_expr AND or_op_expr",
"and_expr : or_op_expr",
"or_op_expr : or_op_expr OR_OP xor_op_expr",
"or_op_expr : xor_op_expr",
"xor_op_expr : xor_op_expr XOR_OP and_op_expr",
"xor_op_expr : and_op_expr",
"and_op_expr : and_op_expr AND_OP equal_expr",
"and_op_expr : equal_expr",
"equal_expr : equal_expr EQUAL comp_expr",
"equal_expr : equal_expr NOT_EQUAL comp_expr",
"equal_expr : comp_expr",
"comp_expr : comp_expr LESS shift_op_expr",
"comp_expr : comp_expr GREATER shift_op_expr",
"comp_expr : comp_expr LESS_EQUAL shift_op_expr",
"comp_expr : comp_expr GREATER_EQUAL shift_op_expr",
"comp_expr : shift_op_expr",
"shift_op_expr : shift_op_expr L_SHIFT add_sub_expr",
"shift_op_expr : shift_op_expr R_SHIFT add_sub_expr",
"shift_op_expr : add_sub_expr",
"add_sub_expr : add_sub_expr PLUS mul_div_rem_expr",
"add_sub_expr : add_sub_expr MINUS mul_div_rem_expr",
"add_sub_expr : mul_div_rem_expr",
"mul_div_rem_expr : mul_div_rem_expr MUL pre_expr",
"mul_div_rem_expr : mul_div_rem_expr DIV pre_expr",
"mul_div_rem_expr : mul_div_rem_expr PERCENT pre_expr",
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
"post_expr : post_expr L_PARENTHESE R_PARENTHESE",
"post_expr : post_expr L_PARENTHESE exprs R_PARENTHESE",
"post_expr : end_expr",
"end_expr : ID arr_expr",
"end_expr : ID",
"end_expr : NUM",
"end_expr : FLOAT",
"end_expr : CHAR",
"end_expr : STRING",
"end_expr : L_PARENTHESE assign_expr R_PARENTHESE",
"arr_expr : arr_expr L_BRACKET assign_expr R_BRACKET",
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
#line 1044 "parser.y"

void yyerror(char *msg) {
    fprintf(stderr, "Error at line %d: %s\n", lineNo, msg);
}

int main(void) {
    yydebug = 1;
    yyparse();
    return 0;
}




#line 702 "y.tab.c"

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
#line 60 "parser.y"
	{
    printf("%s", yystack.l_mark[0].stringVal);
}
break;
case 2:
#line 64 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + strlen(yystack.l_mark[0].stringVal) + 1));
    strcpy(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 3:
#line 70 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 4:
#line 74 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 5:
#line 77 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 6:
#line 80 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 7:
#line 83 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 8:
#line 88 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[-1].stringVal) + SCALAR_TAG + 2));
    strcpy(tem, "<scalar_decl>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, ";");
    strcat(tem, "</scalar_decl>");
    yyval.stringVal = tem;
}
break;
case 9:
#line 98 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 10:
#line 101 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + 2));
    strcpy(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ",");
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 11:
#line 109 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + 2));
    strcpy(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "=");
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 12:
#line 116 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 13:
#line 120 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 14:
#line 123 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[0].stringVal) + 2));
    strcpy(tem, "*");
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 15:
#line 131 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[-1].stringVal) + ARRAY_TAG + 2));
    strcpy(tem, "<array_decl>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, ";");
    strcat(tem, "</array_decl>");
    yyval.stringVal = tem;
}
break;
case 16:
#line 141 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 17:
#line 144 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + 2));
    strcpy(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ",");
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 18:
#line 152 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-4].stringVal) + strlen(yystack.l_mark[-1].stringVal) + 4));
    strcpy(tem, yystack.l_mark[-4].stringVal);
    strcat(tem, "=");
    strcat(tem, "{");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, "}");
    yyval.stringVal = tem;
}
break;
case 19:
#line 161 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 20:
#line 165 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + strlen(yystack.l_mark[0].stringVal) + 1));
    strcpy(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 21:
#line 172 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-3].stringVal) + strlen(yystack.l_mark[-1].stringVal) + 3));
    strcpy(tem, yystack.l_mark[-3].stringVal);
    strcat(tem, "[");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, "]");
    yyval.stringVal = tem;
}
break;
case 22:
#line 180 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + 3));
    strcpy(tem, "[");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, "]");
    yyval.stringVal = tem;
}
break;
case 23:
#line 188 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + 3));
    strcpy(tem, "{");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, "}");
    yyval.stringVal = tem;
}
break;
case 24:
#line 195 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-4].stringVal)+ strlen(yystack.l_mark[-1].stringVal) + 4));
    strcpy(tem, yystack.l_mark[-4].stringVal);
    strcat(tem, ",");
    strcat(tem, "{");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, "}");
    yyval.stringVal = tem;
}
break;
case 25:
#line 204 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal)+ strlen(yystack.l_mark[0].stringVal) + 4));
    strcpy(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ",");
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 26:
#line 211 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 27:
#line 216 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-5].stringVal) + strlen(yystack.l_mark[-4].stringVal) + strlen(yystack.l_mark[-2].stringVal) + FUNC_DECL_TAG + 4));
    strcpy(tem, "<func_decl>");
    strcat(tem, yystack.l_mark[-5].stringVal);
    strcat(tem, yystack.l_mark[-4].stringVal);
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ")");
    strcat(tem, ";");
    strcat(tem, "</func_decl>");
    yyval.stringVal = tem;
}
break;
case 28:
#line 228 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-4].stringVal) + strlen(yystack.l_mark[-3].stringVal) + FUNC_DECL_TAG + 4));
    strcpy(tem, "<func_decl>");
    strcat(tem, yystack.l_mark[-4].stringVal);
    strcat(tem, yystack.l_mark[-3].stringVal);
    strcat(tem, "(");
    strcat(tem, ")");
    strcat(tem, ";");
    strcat(tem, "</func_decl>");
    yyval.stringVal = tem;
}
break;
case 29:
#line 239 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-6].stringVal) + strlen(yystack.l_mark[-4].stringVal) + strlen(yystack.l_mark[-2].stringVal) + FUNC_DECL_TAG + 5));
    strcpy(tem, "<func_decl>");
    strcat(tem, yystack.l_mark[-6].stringVal);
    strcat(tem, "*");
    strcat(tem, yystack.l_mark[-4].stringVal);
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ")");
    strcat(tem, ";");
    strcat(tem, "</func_decl>");
    yyval.stringVal = tem;
}
break;
case 30:
#line 252 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-5].stringVal) + strlen(yystack.l_mark[-3].stringVal) + FUNC_DECL_TAG + 5));
    strcpy(tem, "<func_decl>");
    strcat(tem, yystack.l_mark[-5].stringVal);
    strcat(tem, "*");
    strcat(tem, yystack.l_mark[-3].stringVal);
    strcat(tem, "(");
    strcat(tem, ")");
    strcat(tem, ";");
    strcat(tem, "</func_decl>");
    yyval.stringVal = tem;
}
break;
case 31:
#line 265 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + 2));
    strcpy(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ",");
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 32:
#line 272 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 33:
#line 276 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + strlen(yystack.l_mark[0].stringVal) + 1));
    strcpy(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 34:
#line 282 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + 2));
    strcpy(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "*");
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 35:
#line 291 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-5].stringVal) + strlen(yystack.l_mark[-4].stringVal) + strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + FUNC_DEF_TAG + 3));
    strcpy(tem, "<func_def>");
    strcat(tem, yystack.l_mark[-5].stringVal);
    strcat(tem, yystack.l_mark[-4].stringVal);
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ")");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</func_def>");
    yyval.stringVal = tem;
}
break;
case 36:
#line 303 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-4].stringVal) + strlen(yystack.l_mark[-3].stringVal) + strlen(yystack.l_mark[0].stringVal) + FUNC_DEF_TAG + 3));
    strcpy(tem, "<func_def>");
    strcat(tem, yystack.l_mark[-4].stringVal);
    strcat(tem, yystack.l_mark[-3].stringVal);
    strcat(tem, "(");
    strcat(tem, ")");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</func_def>");
    yyval.stringVal = tem;
}
break;
case 37:
#line 314 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-6].stringVal) + strlen(yystack.l_mark[-4].stringVal) + strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + FUNC_DEF_TAG + 4));
    strcpy(tem, "<func_def>");
    strcat(tem, yystack.l_mark[-6].stringVal);
    strcat(tem, "*");
    strcat(tem, yystack.l_mark[-4].stringVal);
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ")");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</func_def>");
    yyval.stringVal = tem;
}
break;
case 38:
#line 327 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-5].stringVal) + strlen(yystack.l_mark[-3].stringVal) + strlen(yystack.l_mark[0].stringVal) + FUNC_DEF_TAG + 4));
    strcpy(tem, "<func_def>");
    strcat(tem, yystack.l_mark[-5].stringVal);
    strcat(tem, "*");
    strcat(tem, yystack.l_mark[-3].stringVal);
    strcat(tem, "(");
    strcat(tem, ")");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</func_def>");
    yyval.stringVal = tem;
}
break;
case 39:
#line 341 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + 3));
    strcpy(tem, "{");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, "}");
    yyval.stringVal = tem;
}
break;
case 40:
#line 348 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * 3);
    strcpy(tem, "{");
    strcat(tem, "}");
    yyval.stringVal = tem;
}
break;
case 41:
#line 355 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + strlen(yystack.l_mark[0].stringVal) + 1));
    strcpy(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 42:
#line 361 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 43:
#line 365 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 44:
#line 368 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 45:
#line 371 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 46:
#line 374 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 47:
#line 377 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 48:
#line 380 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 49:
#line 383 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 50:
#line 386 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[0].stringVal) + STMT_TAG + 1));
    strcpy(tem, "<stmt>");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</stmt>");
    yyval.stringVal = tem;
}
break;
case 51:
#line 393 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 52:
#line 396 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 53:
#line 399 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + STMT_TAG + 2));
    strcpy(tem, "<stmt>");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, ";");
    strcat(tem, "</stmt>");
    yyval.stringVal = tem;
}
break;
case 54:
#line 409 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + STMT_TAG + 5));
    strcpy(tem, "<stmt>");
    strcat(tem, "if");
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ")");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</stmt>");
    yyval.stringVal = tem;
}
break;
case 55:
#line 420 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-4].stringVal) + strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + STMT_TAG + 9));
    strcpy(tem, "<stmt>");
    strcat(tem, "if");
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-4].stringVal);
    strcat(tem, ")");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "else");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</stmt>");
    yyval.stringVal = tem;
}
break;
case 56:
#line 436 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-4].stringVal) + strlen(yystack.l_mark[-1].stringVal) + STMT_TAG + 11));
    strcpy(tem, "<stmt>");
    strcat(tem, "switch");
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-4].stringVal);
    strcat(tem, ")");
    strcat(tem, "{");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, "}");
    strcat(tem, "</stmt>");
    yyval.stringVal = tem;
}
break;
case 57:
#line 449 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-3].stringVal) + STMT_TAG + 11));
    strcpy(tem, "<stmt>");
    strcat(tem, "switch");
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-3].stringVal);
    strcat(tem, ")");
    strcat(tem, "{");
    strcat(tem, "}");
    strcat(tem, "</stmt>");
    yyval.stringVal = tem;
}
break;
case 58:
#line 462 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + strlen(yystack.l_mark[0].stringVal) + 1));
    strcpy(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 59:
#line 468 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 60:
#line 472 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + 6));
    strcpy(tem, "case");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ":");
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 61:
#line 480 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + 6));
    strcpy(tem, "case");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, ":");
    yyval.stringVal = tem;
}
break;
case 62:
#line 487 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[0].stringVal) + 9));
    strcpy(tem, "default");
    strcat(tem, ":");
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 63:
#line 494 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * 9);
    strcpy(tem, "default");
    strcat(tem, ":");
    yyval.stringVal = tem;
}
break;
case 64:
#line 502 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + STMT_TAG + 8));
    strcpy(tem, "<stmt>");
    strcat(tem, "while");
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ")");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</stmt>");
    yyval.stringVal = tem;
}
break;
case 65:
#line 513 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-5].stringVal) + strlen(yystack.l_mark[-2].stringVal) + STMT_TAG + 11));
    strcpy(tem, "<stmt>");
    strcat(tem, "do");
    strcat(tem, yystack.l_mark[-5].stringVal);
    strcat(tem, "while");
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ")");
    strcat(tem, ";");
    strcat(tem, "</stmt>");
    yyval.stringVal = tem;
}
break;
case 66:
#line 528 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-3].stringVal) + strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[-1].stringVal) + strlen(yystack.l_mark[0].stringVal) + STMT_TAG + 5));
    strcpy(tem, "<stmt>");
    strcat(tem, "for");
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-3].stringVal);
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</stmt>");
    yyval.stringVal = tem;
}
break;
case 67:
#line 541 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + 2));
    strcpy(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, ";");
    yyval.stringVal = tem;
}
break;
case 68:
#line 547 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char)*2);
    strcpy(tem, ";");
    yyval.stringVal = tem;
}
break;
case 69:
#line 553 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + 2));
    strcpy(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, ")");
    yyval.stringVal = tem;
}
break;
case 70:
#line 559 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char)*2);
    strcpy(tem, ")");
    yyval.stringVal = tem;
}
break;
case 71:
#line 567 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + STMT_TAG + 8));
    strcpy(tem, "<stmt>");
    strcat(tem, "return");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, ";");
    strcat(tem, "</stmt>");
    yyval.stringVal = tem;
}
break;
case 72:
#line 576 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (STMT_TAG + 8));
    strcpy(tem, "<stmt>");
    strcat(tem, "return;");
    strcat(tem, "</stmt>");
    yyval.stringVal = tem;
}
break;
case 73:
#line 584 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (STMT_TAG + 7));
    strcpy(tem, "<stmt>");
    strcat(tem, "break;");
    strcat(tem, "</stmt>");
    yyval.stringVal = tem;
}
break;
case 74:
#line 592 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (STMT_TAG + 10));
    strcpy(tem, "<stmt>");
    strcat(tem, "continue;");
    strcat(tem, "</stmt>");
    yyval.stringVal = tem;
}
break;
case 75:
#line 602 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + 2));
    strcpy(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ",");
    strcat(tem, yystack.l_mark[0].stringVal);
    yyval.stringVal = tem;
}
break;
case 76:
#line 609 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 77:
#line 614 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "=");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 78:
#line 623 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 79:
#line 628 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "||");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 80:
#line 637 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 81:
#line 642 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "&&");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 82:
#line 651 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 83:
#line 656 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "|");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 84:
#line 665 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 85:
#line 670 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "^");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 86:
#line 679 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 87:
#line 684 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "&");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 88:
#line 693 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 89:
#line 698 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "==");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 90:
#line 707 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "!=");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 91:
#line 716 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 92:
#line 721 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "<");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 93:
#line 730 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ">");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 94:
#line 739 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "<=");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 95:
#line 748 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ">=");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 96:
#line 757 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 97:
#line 762 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "<<");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 98:
#line 771 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ">>");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 99:
#line 780 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 100:
#line 785 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "+");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 101:
#line 794 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "-");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 102:
#line 803 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 103:
#line 808 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "*");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 104:
#line 817 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "/");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 105:
#line 826 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "%");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 106:
#line 835 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 107:
#line 841 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, "++");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 108:
#line 849 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, "--");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 109:
#line 857 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, "+");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 110:
#line 865 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, "-");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 111:
#line 873 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, "!");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 112:
#line 881 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, "~");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 113:
#line 889 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, ")");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 114:
#line 899 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-3].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 4));
    strcpy(tem, "<expr>");
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-3].stringVal);
    strcat(tem, "*");
    strcat(tem, ")");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 115:
#line 910 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, "*");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 116:
#line 918 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 2));
    strcpy(tem, "<expr>");
    strcat(tem, "&");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 117:
#line 926 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 118:
#line 931 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, "++");
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 119:
#line 939 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, "--");
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 120:
#line 947 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-2].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-2].stringVal);
    strcat(tem, "(");
    strcat(tem, ")");
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 121:
#line 956 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-3].stringVal) + strlen(yystack.l_mark[-1].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-3].stringVal);
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, ")");
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 122:
#line 966 "parser.y"
	{
    yyval.stringVal = yystack.l_mark[0].stringVal;
}
break;
case 123:
#line 972 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 1));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 124:
#line 980 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 1));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 125:
#line 987 "parser.y"
	{
    char *str = int_to_string(yystack.l_mark[0].intVal);
    char *tem = (char*)malloc(sizeof(char) * (strlen(str) + EXPR_TAG + 1));
    strcpy(tem, "<expr>");
    strcat(tem, str);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 126:
#line 995 "parser.y"
	{
    char *str = double_to_string(yystack.l_mark[0].doubleVal);
    char *tem = (char*)malloc(sizeof(char) * (strlen(str) + EXPR_TAG + 1));
    strcpy(tem, "<expr>");
    strcat(tem, str);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 127:
#line 1003 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 1));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 128:
#line 1010 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[0].stringVal) + EXPR_TAG + 1));
    strcpy(tem, "<expr>");
    strcat(tem, yystack.l_mark[0].stringVal);
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 129:
#line 1017 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + EXPR_TAG + 3));
    strcpy(tem, "<expr>");
    strcat(tem, "(");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, ")");
    strcat(tem, "</expr>");
    yyval.stringVal = tem;
}
break;
case 130:
#line 1027 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-3].stringVal) + strlen(yystack.l_mark[-1].stringVal) + 3));
    strcpy(tem, yystack.l_mark[-3].stringVal);
    strcat(tem, "[");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, "]");
    yyval.stringVal = tem;
}
break;
case 131:
#line 1035 "parser.y"
	{
    char *tem = (char*)malloc(sizeof(char) * (strlen(yystack.l_mark[-1].stringVal) + 3));
    strcpy(tem, "[");
    strcat(tem, yystack.l_mark[-1].stringVal);
    strcat(tem, "]");
    yyval.stringVal = tem;
}
break;
#line 2203 "y.tab.c"
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

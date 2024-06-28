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
extern YYSTYPE yylval;

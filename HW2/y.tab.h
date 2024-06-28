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

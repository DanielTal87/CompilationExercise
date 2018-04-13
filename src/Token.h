#ifndef TOKEN_H
#define TOKEN_H
#include <stdio.h>

extern FILE *yyin, *yyout;

typedef enum eTOKENS
{
	BINARY_ARITHMETIC_OPERATION,
	UNARY_OPERATION_ADD_ONE,
	COMPARISON_OPERATION,
	ASSIGNMENT,
	POINTER_INDICATOR,
	UNARY_OPERATION_ADDRESS,
	IDENTIFIER,
	INTEGER_NUMBER,
	REAL_NUMBER,
	BLOCK_KEYWORD,
	BEGIN_KEYWORD,
	END_KEYWORD,
	TYPE_KEYWORD,
	IS_KEYWORD,
	INTEGER_KEYWORD,
	REAL_KEYWORD,
	ARRAY_KEYWORD,
	OF_ARRAY_KEYWORD,
	WHEN_KEYWORD,
	WHEN_DO_KEYWORD,
	DEFAULT_KEYWORD,
	END_WHEN_KEYWORD,
	FOR_KEYWORD,
	END_FOR_KEYWORD,
	MALLOC_KEYWORD,
	SIZE_OF_KEYWORD,
	FREE_KEYWORD,
	COLON,
	SEMICOLON,
	LEFT_PARENTHESIS,
	RIGHT_PARENTHESIS,
	LEFT_BRACKET,
	RIGHT_BRACKET,
	END_OF_FILE
} eTOKENS;

typedef struct Token
{
	eTOKENS kind;
	char *lexeme;
	int lineNumber;
} Token;

typedef struct Node
{
	Token *tokensArray;
	struct Node *prev;
	struct Node *next;
} Node;

void create_and_store_token(eTOKENS kind, char* lexeme, int numOfLine);
Token *next_token();
Token *back_token();
void match(Token token);
void free_token_storage();

#endif

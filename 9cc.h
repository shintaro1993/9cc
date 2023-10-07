#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    ND_ADD,
    ND_SUB,
    ND_MUL,
    ND_DIV,
    ND_IDV,
    ND_NUM,
    ND_NE,
    ND_EQ,
    ND_GT,
    ND_GE,
    ND_LT,
    ND_LE,
    ND_ASSIGN,
    ND_LVAR,
} NodeKind;

typedef struct Node Node;
typedef struct Token Token;

extern Token *token;
extern char *user_input;

struct Node {
    NodeKind kind;
    Node *lhs;
    Node *rhs;
    int val;
    int offset;
};

typedef enum {
    TK_RESERVED,
    TK_IDENT,
    TK_NUM,
    TK_EOF,
} TokenKind;

struct Token {
    TokenKind kind;
    Token *next;
    int val;
    char *str;
    int len;
};

void program();

Node *expr();
Node *equality();
Node *relational();
Node *add();
Node *mul();
Node *unary();
Node *primary();
bool consume(char *op);
void expect(char *op);
int expect_number();
bool at_eof();
Token *consume_ident();

void tokenize();
void gen(Node *node);

void error(char *fmt, ...);

extern Node *code[];
Node *stmt();
Node *assign();
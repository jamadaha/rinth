#pragma once

#include <stdbool.h>

typedef enum {
    DEF_DEFINE,
    DEF_NAME,
    DEF_REQUIREMENTS,
    DEF_PREDICATES,
    DEF_ACTION,
    DEF_PARAMETERS,
    DEF_PRECONDITION,
    DEF_EFFECT,
    DEF_DOMAIN,
    DEF_OBJECTS,
    DEF_INIT,
    DEF_GOAL,
    REQ_STRIPS,
    EXP_AND,
    EXP_NOT,
    EXP_OR,
    LPAREN,
    RPAREN,
    VARIABLE,
    ID,
    MAX_TOKEN_KIND
} TokenKind;

extern const char *TOKEN_NAMES[MAX_TOKEN_KIND];

typedef struct {
    TokenKind kind;
    int pos, len;
} Token;

typedef struct {
    const char *str;
    int pos;
} Lexer;

void TokenAssign(Token *token, TokenKind kind, int pos, int len);

bool MatchDef(TokenKind *kind, const char *str, int len);
void LexID(Lexer *lexer);
bool LexerNext(Token *token, Lexer *lexer);

void EOI(TokenKind expected);
void Expect(TokenKind actual, TokenKind expected);
void ExpectEither(TokenKind actual, TokenKind e1, TokenKind e2);
void ExpectNext(Token *t, Lexer *lexer, TokenKind kind);
void Expected(const char *str, TokenKind found);
void WriteToken(char **id, Token *t, const char *str);

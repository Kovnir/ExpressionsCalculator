#pragma once
#include "TokenType.h"

struct Token
{
    enum TokenType type;
    char lexeme;
};
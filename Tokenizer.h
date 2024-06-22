#pragma once
#include "Token.h"

typedef unsigned int uint;

class Tokenizer
{
public:
    Tokenizer(char *input);
    Token lookAhead();
    void stepBack();

private:
    uint inputIndex;
    char *inputStr;
};

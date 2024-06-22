#include "Tokenizer.h"
#include <iostream>

Tokenizer::Tokenizer(char *input)
{
    inputStr = input;
    inputIndex = 0;
}

void Tokenizer::stepBack()
{
    inputIndex--;
    if (inputIndex < 0)
        throw "Invalid index";
}

Token Tokenizer::lookAhead()
{
    Token token =
        {
            .type = EOI};

    switch (inputStr[inputIndex])
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        token.type = NUM;
        break;
    case '+':
        token.type = PLUS;
        break;
    case '-':
        token.type = MINUS;
        break;
    case '*':
        token.type = STAR;
        break;
    case '(':
        token.type = LP;
        break;
    case ')':
        token.type = RP;
        break;
    default:
        if (strlen(inputStr) > inputIndex)
            token.type = UNKNOWN;
        break;
    }

    if (token.type != EOI)
    {
        token.lexeme = inputStr[inputIndex];
        inputIndex++;
    }

    return token;
}
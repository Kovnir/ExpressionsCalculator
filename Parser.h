#include <stdio.h>
#include <stdlib.h>
#include "Tokenizer.h"

class Parser
{
public:
    Parser(char *input);
    int calculate();

private:
    Tokenizer tokenizer;

    int stmt(Token token);
    int expr(Token token);
    int term(Token token);
    int fact(Token token);
};
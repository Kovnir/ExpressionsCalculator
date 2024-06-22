#include "Parser.h"
#include "TokenType.h"
#include "Token.h"
#include "Tokenizer.h"
#include <string>
#include <stdexcept>

// smth -> expr
// expr -> term { + expr }
// term -> fact { * term }
// fact -> num | ( expr )

Parser::Parser(char *input) : tokenizer(input)
{
}

int Parser::calculate()
{
	Token token;
	int result = 0;

	token = tokenizer.lookAhead();
	result = stmt(token);

	return result;
}

int Parser::stmt(Token token)
{
	int result = 0;

	switch (token.type)
	{
	case LP:
	case NUM:
		result = expr(token);
		break;
	default:
		throw std::runtime_error(std::string("Syntax error: ") + token.lexeme);
		break;
	}

	return result;
}

int Parser::expr(Token token)
{
	int result = 0;

	switch (token.type)
	{
	case NUM:
	case LP:
		result = term(token);

		token = tokenizer.lookAhead();

		switch (token.type)
		{
		case PLUS:
			token = tokenizer.lookAhead();
			result += expr(token);
			break;
		case MINUS:
			token = tokenizer.lookAhead();
			result -= expr(token);
			break;
		case RP:
			// if token is closing parenthesis, return it back to the string
			tokenizer.stepBack();
			break;
		case EOI:
			break;
		default:
			throw std::runtime_error(std::string("Syntax error: ") + token.lexeme);
			break;
		}

		break;
	default:
		throw std::runtime_error(std::string("Syntax error: ") + token.lexeme);
		break;
	}

	return result;
}

int Parser::term(Token token)
{
	int result = 0;

	switch (token.type)
	{
	case LP:
	case NUM:
		result = fact(token);

		token = tokenizer.lookAhead();

		switch (token.type)
		{
		case STAR:
			token = tokenizer.lookAhead();
			result *= term(token);
			break;
		case PLUS:
		case MINUS:
		case RP:
			tokenizer.stepBack();
			break;
		case EOI:
			break;
		default:
			throw std::runtime_error(std::string("Syntax error: ") + token.lexeme);
			break;
		}
		break;
	default:
		throw std::runtime_error(std::string("Syntax error: ") + token.lexeme);
		break;
	}

	return result;
}

int Parser::fact(Token token)
{
	int result = 0;

	switch (token.type)
	{
	case NUM:
		result = atoi(&token.lexeme);
		break;
	case LP:
		token = tokenizer.lookAhead();
		result = expr(token);
		token = tokenizer.lookAhead();
		if (token.type != RP)
		{
			throw std::runtime_error(std::string("Syntax error: ") + token.lexeme);
		}
		break;
	default:
		break;
	}

	return result;
}

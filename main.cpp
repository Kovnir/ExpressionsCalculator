#include "Parser.h"
#include <string>

void Check(char *input, int expected)
{
	Parser parser(input);
	int result = parser.calculate();
	if (result != expected)
	{
		printf(("Test " + std::string(input) + " failed\n").c_str());
	}
	else
	{
		printf(("Test " + std::string(input) + " passed\n").c_str());
	}
}

void Test()
{
	Check((char *)"9", 9);
	Check((char *)"1+2", 3);
	Check((char *)"(1+2)", 3);
	Check((char *)"1+2*3", 7);
	Check((char *)"(1+2)*3", 9);
	Check((char *)"1+2*3+4", 11);
	Check((char *)"1+2*(3+4)", 15);
	Check((char *)"1+2*(3+4)-9", 6);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <expression>\n", argv[0]);
		Test();
		return 1;
	}

	Parser parser(argv[1]);

	int result = parser.calculate();

	printf("Result: %d\n", result);
	return 0;
}

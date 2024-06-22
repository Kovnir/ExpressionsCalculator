#include "Parser.h"

int main(int argc, char **argv)
{
	//	Parser parser(argv[1]);
	char *input = (char *)"1+2*(3+4)-9";
	Parser parser(input);

	int result = parser.calculate();

	printf("Result: %d\n", result);
	return 0;
}

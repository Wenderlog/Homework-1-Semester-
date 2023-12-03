#include <stdio.h>
#include <string.h>
#include "solutionComments.h"


int main()
{
	char fileName[] = "input.txt";
	printf("Comments from file:\n%s", comments(fileName));
	return 0;
}

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

	if(argc != 2)
	{
		printf("Usage: %s <input_file_PATH>\n", argv[0]);
		return 0;
	}

	// Open input file
	FILE* input = fopen(argv[1], "r");
	if(!input)
	{
		printf("Could not open file\n");
		return 1;
	}

	char ch = getc(input);
	int first = -1;
	int last = -1;
	int number = -1;
	int sum = 0;

	while(ch != EOF)
	{
		if(isdigit(ch))
		{
			if(first == -1)
				first = ch - '0';
			last = ch - '0';
		}

		// If reached end of line
		if(ch == '\n')
		{
			number = first * 10 + last;
			printf("Number in line: %d\n", number);
			first = -1;
			last = -1;
			sum = sum + number;
		}

		//printf("%c", ch);
		ch = getc(input);
	}

	fclose(input);

	printf("Total SUM: %d\n", sum);

	return 0;
}

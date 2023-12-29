#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#include "common.h"

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

	char* words[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	const int MAXLEN = 128;
	char* buf = (char*)malloc(MAXLEN * sizeof(char));

	read_line(input, buf, MAXLEN);
	int linenumber = 1;
	int sum;
	while(*buf != '\0')
	{
		printf("%d. line: %s\n", linenumber, buf);

		// Process line
		int pos = 1000000;
		bool first_isstring = false;
		bool last_isstring = false;
		int first_number = -1;
		int last_number = -1;
		for(int i = 0; i < 10; i++)
		{
			int temp = pos_first_digit(buf, digits[i]);
			if(temp < pos && temp >= 0)
			{
				pos = temp;
				first_isstring = false;
				first_number = i;
			}			
		}
		for(int i = 0; i < 10; i++)
		{
			int temp = pos_first_substring(buf, words[i]);
			if(temp < pos && temp >= 0)
			{
				pos = temp;
				first_isstring = true;
				first_number = i;
			}
		}
		printf("Smallest number index: %d\n", pos);
		printf("Is it a string: %d\n\n", first_isstring);


		pos = -1;
		for(int i = 0; i < 10; i++)
		{
			int temp = pos_last_digit(buf, digits[i]);
			if(temp > pos && temp >= 0)
			{
				pos = temp;
				last_isstring = false;
				last_number = i;
			}			
		}
		for(int i = 0; i < 10; i++)
		{
			int temp = pos_last_substring(buf, words[i]);
			if(temp > pos && temp >= 0)
			{
				pos = temp;
				last_isstring = true;
				last_number = i;
			}
		}
		printf("Largest number index: %d\n", pos);
		printf("Is it a string: %d\n\n", last_isstring);

		// Add 2digit number
		sum += first_number*10 + last_number;

		linenumber++;
		read_line(input, buf, MAXLEN);
	}




	fclose(input);

	printf("Total SUM: %d\n", sum);

	return 0;
}

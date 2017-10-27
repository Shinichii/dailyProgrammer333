#include <errno.h>
#include "parser.h"

int main(int argc, char* argv[])
{
	int number_of_lines = 0;
	packet* packet_array = NULL;
	FILE* input_file;
	if(argc != 2)
	{
		fprintf(stderr, "Usage : [program] [path-to-input-file]");
		return -1;
	}
	//Opening the file
	input_file = fopen(argv[1], "r");
	if(!input_file)
	{
		fprintf(stdout, "Error while opening the file : %s\n", strerror(errno));
	}
	number_of_lines = parse_input_file(input_file, packet_array);
	fprintf(stdout, "There are %d lines in the file", number_of_lines);
	return 0;
}

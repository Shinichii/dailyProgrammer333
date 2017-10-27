#include <stdio.h>
#include <errno.h>
#include "parser.h"

int main(int argc, char* argv[])
{
	FILE* input_file;
	if(argc != 2)
	{
		fprintf(stderr, "Usage : [program] [path-to-input-file]");
		return -1;
	}
	//Opening the file
	input_file = fopen(argv[1]);
	if(!input_file)
	{
		fprintf(stdout, "Error while opening the file : %s\n", strerror(errno));
	}
	return 0;
}

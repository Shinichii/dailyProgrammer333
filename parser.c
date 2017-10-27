#include "parser.h"

int parse_input_file(FILE* input_file,packet * array_parsed)
{
	array_parsed = NULL;
	char *buffer;
	int buffer_used = 0;
	int number_of_lines = 0;
	int i = 0;
	if(!input_file)
	{
		fprintf(stderr, "Could not open input_file !");
		return NULL;
	}
	number_of_lines = getNumberOfLines(input_file);
	if(number_of_lines < 1)
	{
		fprintf(stderr, "No line to parse");
		return NULL;
	}
	else
	{
		array_parsed = (packet*)malloc(sizeof(packet) * number_of_lines);
		if(!array_parsed)
		{
			printf("erreur lors de l'allocation");
			exit(-1);
		}
	}
	for(i = 0; i < number_of_lines; i++)
	{
		getline(&buffer, &buffer_used, input_file);
		array_parsed[i] = parseLine(buffer);
	}
	show_array(array_parsed, number_of_lines);
	return number_of_lines;
}
void show_packet(packet p)
{
	fprintf(stdout, "%d \t %d \t %d \t %s", p.messageID, p.packetID, p.numberOfPackets, p.message);
}
void show_array(packet* packet_array, int array_size)
{
	int i = 0;
	fprintf(stdout, "mID\tpkID\tnbPk\tmessage\n");
	for(i = 0; i < array_size; i++)
	{
		show_packet(packet_array[i]);
	}
}
packet parseLine(char* buffer)
{
	packet p;
	char* current = buffer;
	char* runner= current;
	char tmp[BUFFER_SIZE];
	while(*runner++ != ' ');
	strncpy(tmp, current, (runner-current));
	tmp[runner-current] = '\0';
	p.messageID = atoi(tmp);
	while(*runner++ == ' ');
	current = runner;
	current--;
	//parse packetID
	while(*runner++ != ' ');
	strncpy(tmp, current, (runner-current));
	tmp[runner-current] = '\0';
	p.packetID= atoi(tmp);
	while(*runner++ == ' ');
	current = runner;
	current--;
	//parse numberOfPackets
	while(*runner++ != ' ');
	strncpy(tmp, current, (runner-current));
	tmp[runner-current] = '\0';
	p.numberOfPackets= atoi(tmp);
	while(*runner++ == ' ');
	current = runner;
	current--;
	//parse message
	while(*runner++ != '\0');
	strncpy(tmp, current, (runner-current));
	tmp[runner-current] = '\0';
	p.message = (char*)malloc(sizeof(char) * (runner-current+1));
	strncpy(p.message, current, (runner-current));
	p.message[runner-current] = '\0';
	return p;
}
int getNumberOfLines(FILE* file)
{
	char c = '\0';
	fpos_t pos;
	int number_of_lines = 0;
	if(!file)
	{
		fprintf(stdout, "Could not open input_file !");
		return NULL;
	}
	fgetpos(file, &pos);
	while(!feof(file))
	{
		c = fgetc(file);
		if(c == '\n')
		{
			number_of_lines++;
		}
	}
	fsetpos(file, &pos);
	return number_of_lines;
}

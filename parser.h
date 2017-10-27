#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 100
typedef struct packet
{
	int messageID;
	int packetID;
	int numberOfPackets;
	char* message;
}packet;
void sort_by_message_id(packet * array_parsed, int number_of_lines);
int compare_by_message_id(const void *a, const void *b);
void show_packet(packet p);
void show_array(packet* packet_array, int array_size);
packet parseLine(char* buffer);
int getNumberOfLines(FILE* file);
int parse_input_file(FILE *input_file, packet* array_parsed);

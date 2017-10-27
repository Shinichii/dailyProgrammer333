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
void show_packet(packet p);
void show_array(packet* packet_array, int array_size);
packet parseLine(char* buffer);
int getNumberOfLines(FILE* file);
int parse_input_file(FILE *input_file, packet* array_parsed);

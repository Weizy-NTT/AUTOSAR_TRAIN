#ifndef VALIDATOR_H
#define VALIDATOR_H
#define MAX_LINE_LENGTH 512
#include <stdbool.h>

// Validate a single record line
bool validateRecord(const char *line, unsigned int *segmentAddress);

// Parse the fields of a record
void parseRecord(const char *line, unsigned char *byteCount, unsigned int *addressField, unsigned char *recordType, char *dataField, unsigned char *checksumValue);

// Calculate checksum of a record line
unsigned char calculateChecksum(const char *line);

#endif // VALIDATOR_H

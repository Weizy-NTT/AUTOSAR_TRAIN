#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "valid.h"

unsigned char calculateChecksum(const char *line) {
    unsigned char totalSum = 0;

    for (size_t i = 1; i < strlen(line) - 2; i += 2) {
        unsigned int byteValue;
        sscanf(line + i, "%2x", &byteValue);
        totalSum += (unsigned char)byteValue;
    }

    unsigned char checksum = ((~totalSum + 1) & 0xFF);
    return checksum;
}

void parseRecord(const char *line, unsigned char *byteCount, unsigned int *addressField, unsigned char *recordType, char *dataField, unsigned char *checksumValue) {
    sscanf(line + 1, "%2hhx%4x%2hhx", byteCount, addressField, recordType);

    if (*byteCount > 0) {
        strncpy(dataField, line + 9, (*byteCount) * 2);
        dataField[(*byteCount) * 2] = '\0';
    } else {
        dataField[0] = '\0'; // No data in this record
    }

    sscanf(line + 9 + (*byteCount) * 2, "%2hhx", checksumValue);
}

bool validateRecord(const char *line, unsigned int *segmentAddress) {
    if (line[0] != ':') {
        printf("Invalid record format: Missing start character ':'\n");
        return false;
    }

    unsigned char byteCount, recordType, checksumValue;
    unsigned int addressField;
    char dataField[MAX_LINE_LENGTH];

    parseRecord(line, &byteCount, &addressField, &recordType, dataField, &checksumValue);

    unsigned char calculatedChecksum = calculateChecksum(line);
    if (calculatedChecksum != checksumValue) {
        printf("Checksum error! Expected: 0x%02X, Got: 0x%02X\n", checksumValue, calculatedChecksum);
        return false;
    }

    if (recordType == 0x02) { // Extended Segment Address Record
        sscanf(dataField, "%4x", segmentAddress);
    } else if (recordType == 0x01) { // End of File Record
        printf("EOF record found. Processing complete.\n");
        return true;
    }

    return true;
}
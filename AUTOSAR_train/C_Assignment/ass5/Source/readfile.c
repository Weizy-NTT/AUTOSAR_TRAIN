#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"
#include "valid.h"

bool processHexFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", fileName);
        return false;
    }

    char hexLine[MAX_LINE_LENGTH];
    unsigned int segmentAddress = 0;
    bool eofRecordFound = false;

    while (fgets(hexLine, sizeof(hexLine), file)) {
        hexLine[strcspn(hexLine, "\r\n")] = 0; // Remove newline characters

        if (!validateRecord(hexLine, &segmentAddress)) {
            fclose(file);
            return false; // Stop processing on invalid record
        }

        // Process and print record details if valid
        unsigned char byteCount, recordType, checksum;
        unsigned int address;
        char dataField[MAX_LINE_LENGTH];
        parseRecord(hexLine, &byteCount, &address, &recordType, dataField, &checksum);

        unsigned int absoluteAddress = (segmentAddress << 4) + address;
        printf("ABS Address: 0x%04X, Data: %s\n", absoluteAddress, dataField);

        if (recordType == 0x01) { // End of File Record
            eofRecordFound = true;
            break;
        }
    }

    fclose(file);

    if (!eofRecordFound) {
        printf("Error: EOF Record not found.\n");
        return false;
    }

    return true;
}

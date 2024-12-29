#include <stdio.h>
#include "readfile.h"

int main() {
    const char *filename = "binary.hex";
    
    // Process the HEX file
    if (!processHexFile(filename)) {
        printf("Failed to process the file. Either the file contains invalid records or the EOF record is missing.\n");
        return 1;
    }

    printf("The HEX file was successfully processed without any errors.\n");
    return 0;
}

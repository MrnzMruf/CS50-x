#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define the block size
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Ensure correct usage
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // Open the memory card file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Define a buffer to store the 512-byte blocks
    uint8_t buffer[BLOCK_SIZE];

    // Initialize variables
    int file_count = 0;            // To count the JPEG files
    FILE *output = NULL;           // File pointer for the output JPEG file
    char filename[8];              // To store the filenames "###.jpg"

    // Loop over the memory card, reading 512-byte blocks
    while (fread(buffer, sizeof(uint8_t), BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        // Check if this block is the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If a new JPEG is found, close the previous one (if any)
            if (output != NULL)
            {
                fclose(output);
            }

            // Create a new filename for the JPEG
            sprintf(filename, "%03i.jpg", file_count);
            file_count++;

            // Open a new file to write the JPEG
            output = fopen(filename, "w");
            if (output == NULL)
            {
                printf("Could not create output file.\n");
                fclose(input);
                return 1;
            }
        }

        // If a JPEG file is currently open, write the current block to the file
        if (output != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), BLOCK_SIZE, output);
        }
    }

    // Close any remaining files
    if (output != NULL)
    {
        fclose(output);
    }

    // Close the input file
    fclose(input);

    return 0;
}

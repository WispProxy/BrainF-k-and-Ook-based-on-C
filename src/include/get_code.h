#ifndef GET_CODE_H
#define GET_CODE_H

/*---Get program code from input file or stdin---*/
long getProgramCode(FILE *file, char* data)
{
    int i = 0;
	long BYTES;
    char memory[BUFFER_SIZE];

	BYTES = fread(memory, 1, BUFFER_SIZE, file);
    if (BYTES == ERROR) return ERROR;

    for (i = 0; i < BYTES; i++) data[i] = memory[i];

    return BYTES;
}

/*---END CODE---*/
#endif

#include "include/settings_global.h"
#include "include/get_code.h"
#include "include/interpreter_brainf.h"
#include "include/translator_ook_to_brainf.h"

/*---Initialize Main block---*/
int main(int argc, char **argv)
{
    int getFileFlag = 0;
	long codeSize = CODE_SIZE;

    if (argc < 2)
	{
        file = stdin;
		if (getFileFlag) fclose(file);
    }
	else
	{
        if ((file = fopen( argv[1], "r" ))==NULL)
		{
            fprintf(stderr, "This can't open: \"%s\"\n", argv[1]);
            return ERROR;
        }
        getFileFlag = FAILED;
    }

    codeSize = getProgramCode(file, data);
    if (codeSize == ERROR)
	{
		fprintf(stderr, "Error in code file.\n");
		return ERROR;
    }

    if (strstr(data, "Ook") != NULL)
	{
		translatorOokToBFCode(data);
	}

    interpreterBFCode(codeSize, data);

    return OK;
}

/*---END CODE---*/

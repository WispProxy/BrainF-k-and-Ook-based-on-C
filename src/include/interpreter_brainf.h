#ifndef INTERPRETER_BRAINF_H
#define INTERPRETER_BRAINF_H

/*---Initialize the interpreter BrainF**k---*/
int interpreterBFCode(long codeSize, char* data)
{
    int i = 0,																						//-// i - counter
		position = 0,																				//-// position - is the memory position
		level = 0;   																				//-// level - counter for memory[]
    char memory[BUFFER_SIZE];

    memset(memory, 0, BUFFER_SIZE);
    for (i = 0; ((i > -1) && (i < codeSize)); i++)
	{
        switch (data[i])
		{
            case '>':   position++; if (position >= BUFFER_SIZE) return ERROR; break; 				//-// ">" - increment the data position
			case '<':   position--; if (position < 0) return ERROR; break;            				//-// "<" - decrement the data position
            case '+':   memory[position]++; break;													//-// "+" - increment the byte at the data position		
            case '-':   memory[position]--; break;													//-// "-" - decrement the byte at the data position			
            case '.':   putchar(memory[position]); break;											//-// "." - output the byte at the data position				
            case ',':   memory[position] = getchar(); break;										//-// "," - accept one byte of input, storing its value in the byte at the data position
            case '[':   if (memory[position] == 0)													//-// "[" - jump it forward to the command after the matching if byte position = 0
						{
							for(i++; ((level > 0) || (data[i] != ']')); i++)
							{
							    if (data[i] == '[') level++;
                                if (data[i] == ']') level--;
							}
                        }
                        break;
            case ']':   if (memory[position] != 0)													//-// "]" - jump it back to the command after the matching if byte position != 0
						{
							for(i--; ((level > 0) || (data[i] != '[')); i--)
							{
								if (data[i] == '[') level--;
                                if (data[i] == ']') level++;
							}
                            i--;  																	//-// Avoiding loops
                        }
                        break;
            default:	break;																		//-// Filtered other symbols
        }
    }
    return OK; 
}

/*---END CODE---*/
#endif

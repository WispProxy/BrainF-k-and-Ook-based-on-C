#ifndef TRANSLATOR_OOK_TO_BF_H
#define TRANSLATOR_OOK_TO_BF_H

/*---Initialize the translator Ook! to BrainF**k---*/
int translatorOokToBFCode(char* data)
{
	int O = 0,																						//-// O - value for symbol 'O'
		o = 0,																						//-// o - value for symbol 'o'
		k = 0;																						//-// k - value for symbol 'k'
    int i,																							//-// i - counter for data array
		left_i = 0,																					//-// left_i - counter for left symbol in memory array (this 'i' in memory array)
		right_i = 0;																				//-// right_i - counter for right symbol in memory array (this 'i + 1' in memory array)
    char memory[BUFFER_SIZE];

    memset(memory, 0, BUFFER_SIZE);
    for (i = 0; i < BUFFER_SIZE; i++)																//-// This need for filter word - Ook
    {
		if (data[i] == 'O')
		{
			O = 1;
			o = 0;
			k = 0;
			continue;
		}
        else if (O && (data[i] == 'o'))
		{
			o = 1;
			continue;
		}
        else if (o && (data[i] == 'k'))
		{
			k = 1;
			continue;
		}
        else if (k)
		{ 
            memory[left_i] = data[i];
			left_i++;
            O = 0;
			o = 0;
			k = 0;
        }
    }

	i = 0;																							//-// This need for reset counter - 'data array'
	left_i = 0;																						//-// This need for reset counter - 'memory array'
	memset(data, 0, BUFFER_SIZE);
    for (left_i = 0; left_i < BUFFER_SIZE; left_i += 2, i++)										//-// This need for compare Ook symbols ('memory array') with BrainF**k symbols ('data array')
	{
		right_i = left_i + 1;
		if ((memory[left_i] == '.') && (memory[right_i] == '?'))									//-// 'Ook. Ook?' = '>'
		{
			data[i] = '>';
		}
        else if ((memory[left_i] == '?') && (memory[right_i] == '.'))								//-// 'Ook? Ook.' = '<'
		{
			data[i] = '<';
		}
        else if ((memory[left_i] == '.') && (memory[right_i] == '.'))								//-// 'Ook. Ook.' = '+'
		{
			data[i] = '+';
		}
        else if ((memory[left_i] == '!') && (memory[right_i] == '!'))								//-// 'Ook! Ook!' = '-'
		{
			data[i] = '-';
		}
        else if ((memory[left_i] == '!') && (memory[right_i] == '.'))								//-// 'Ook! Ook.' = '.'
		{
			data[i] = '.';
		}
        else if ((memory[left_i] == '.') && (memory[right_i] == '!'))								//-// 'Ook. Ook!' = ','
		{
			data[i] = ',';
		}
        else if ((memory[left_i] == '!') && (memory[right_i] == '?'))								//-// 'Ook! Ook?' = '['
		{
			data[i] = '[';
		}
        else if ((memory[left_i] == '?') && (memory[right_i] == '!'))								//-// 'Ook? Ook!' = ']'
		{
			data[i] = ']';
		}
    }

    return OK;
}

/*---END CODE---*/
#endif

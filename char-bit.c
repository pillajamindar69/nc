#include <stdio.h>
#include <string.h>

#define START_CHAR 'S'
#define END_CHAR 'E'
#define ESC_CHAR 'X'

void stuff_characters(const char *data, char *stuffed)
{
    int i, j = 0;
    stuffed[j++]=START_CHAR;
    for(i=0;i<strlen(data);i++)
    {
    	if(data[i]==START_CHAR||data[i]==END_CHAR)
    	{
    		stuffed[j++]=ESC_CHAR;
    	}
    	stuffed[j++]=data[i];
    }
    stuffed[j++]=END_CHAR;
    stuffed[j]='\0';
}
int main()
{
 	char stuffed[100];
 	const char *data="HelloSEWorldE";
 	
 	stuff_characters(data,stuffed);
 	printf("Stuffed data is %s",stuffed);
 	return 0;
}


//bit stuffing

#include <stdio.h>
#include <string.h>

void stuff_bits(const char *data, char *stuffed)
{
    int i, j = 0;
    int count = 0; 
    
    for (i = 0; i < strlen(data); i++) 
    {
        stuffed[j++] = data[i]; 
        if (data[i] == '1') 
        {
            count++; 
            if (count == 5) 
            {
                stuffed[j++] = '0'; 
                count = 0; 
            }
        }
        else
        {
        	count=0;
        }
     }
     stuffed[j]='\0';
}

int main() {
    const char *data = "1101111110111111"; 
    char stuffed[100]; 

    stuff_bits(data, stuffed); 

    printf("Stuffed Data: %s\n", stuffed); 

    return 0;
}
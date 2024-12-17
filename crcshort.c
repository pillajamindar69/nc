#include <stdio.h>
#include <string.h>
void computeCRC(char data[], char divisor[], char crc[])
{
    int dataLen = strlen(data);
    int divisorLen = strlen(divisor);
    char temp[50];
    strcpy(temp, data);
    for (int i = 0; i < dataLen; i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < divisorLen; j++)
            {
                temp[i + j] = temp[i + j] == divisor[j] ? '0' : '1';
            }
        }
    }
    strncpy(crc, temp + dataLen, divisorLen - 1);
    crc[divisorLen - 1] = '\0';
}
int main()
{
    char data[50], divisor[20], crc[20];
    printf("Enter the data: ");
    scanf("%s", data);
    printf("Enter the divisor: ");
    scanf("%s", divisor);
    char paddedData[100];
    strcpy(paddedData, data);
    for (int i = 0; i < strlen(divisor) - 1; i++)
    {
        strcat(paddedData, "0");
    }
    computeCRC(paddedData, divisor, crc);
    printf("CRC Code: %s\n", crc);
    return 0;
}
#include <stdio.h>
#include <string.h>

void encrypt(char text[], int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') { 
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') { 
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
        }
    }
}


void decrypt(char text[], int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') { 
            text[i] = (text[i] - 'A' - key + 26) % 26 + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') { 
            text[i] = (text[i] - 'a' - key + 26) % 26 + 'a';
        }
    }
}

 
int main() {
    char text[100];
    int key;

  
    printf("Enter the text to encrypt: ");
    gets(text);

    
    printf("Enter the key (number of shifts): ");
    scanf("%d", &key);

  
    encrypt(text, key);
    printf("Encrypted text: %s\n", text);

  
    decrypt(text, key);
    printf("Decrypted text: %s\n", text);

    return 0;
}
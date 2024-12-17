#include <stdio.h>

struct Frame {
    int sequence;
    char data[100]; 
};


void sortFrames(struct Frame frames[], int n) {
    int i, j;
    struct Frame temp;

  
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (frames[j].sequence > frames[j + 1].sequence) {
            
                temp = frames[j];
                frames[j] = frames[j + 1];
                frames[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;

  
    printf("Enter the number of frames: ");
    scanf("%d", &n);

    struct Frame frames[n];

   
    for (i = 0; i < n; i++) {
        printf("Enter sequence number for frame %d: ", i + 1);
        scanf("%d", &frames[i].sequence);

        printf("Enter data for frame %d: ", i + 1);
        scanf("%s", frames[i].data);
    }

  
    sortFrames(frames, n);

  
    printf("\nFrames in sorted order:\n");
    for (i = 0; i < n; i++) {
        printf("Sequence: %d, Data: %s\n", frames[i].sequence, frames[i].data);
    }

    return 0;

}
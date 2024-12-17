#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 5
void sender(int frames[], int n) {
 int i = 0, ack, windowSize = MAX_FRAMES;
 while (i < n) {
 printf("\nSender sends frames: ");
 for (int j = 0; j < windowSize && i + j < n; j++) {
 printf("%d ", frames[i + j]);
 }
 printf("\nEnter the ACK for the first frame: ");
 scanf("%d", &ack);
 if (ack > i && ack <= i + windowSize) {
 i = ack;
 } else {
 printf("\nInvalid ACK received. Resending frames...\n");
 }
 }
 printf("\nAll frames sent successfully!\n");
}
int main() {
 int n;
 printf("Enter the number of frames to send: ");
 scanf("%d", &n);
 int frames[n];
 for (int i = 0; i < n; i++) {
 frames[i] = i + 1;
 }
 sender(frames, n);
 return 0;
}

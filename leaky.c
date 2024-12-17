#include <stdio.h>
#include <unistd.h> // For sleep()
void leakyBucket(int bucketSize, int outputRate, int packets[], int n)
{
    int remaining = 0, i;
    for (i = 0; i < n; i++)
    {
        printf("\nIncoming packet size: %d\n", packets[i]);
        if (packets[i] + remaining > bucketSize)
        {
            printf("Bucket overflow! Packet dropped.\n");
        }
        else
        {
            remaining += packets[i];
            printf("Bucket buffer: %d\n", remaining);
        }
        if (remaining > 0)
        {
            int transmitted = remaining < outputRate ? remaining : outputRate;
            printf("Transmitted: %d\n", transmitted);
            remaining -= transmitted;
        }
        sleep(1); 
    }
  
    while (remaining > 0)
    {
        printf("\nBucket buffer: %d\n", remaining);
        int transmitted = remaining < outputRate ? remaining : outputRate;
        printf("Transmitted: %d\n", transmitted);
        remaining -= transmitted;
        sleep(1);
    }
    printf("\nBucket is empty.\n");
}
int main()
{
    int bucketSize, outputRate, n;
    printf("Enter bucket size: ");
    scanf("%d", &bucketSize);
    printf("Enter output rate: ");
    scanf("%d", &outputRate);
    printf("Enter number of packets: ");
    scanf("%d", &n);
    int packets[n];
    printf("Enter packet sizes:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &packets[i]);
    }
    leakyBucket(bucketSize, outputRate, packets, n);
    return 0;
}
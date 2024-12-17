#include <stdio.h>
void sortFrames(int frames[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (frames[j] > frames[j + 1])
            {
                int temp = frames[j];
                frames[j] = frames[j + 1];
                frames[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of frames: ");
    scanf("%d", &n);
    int frames[n];
    printf("Enter the frame numbers:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &frames[i]);
    }
    sortFrames(frames, n);
    printf("Sorted frames: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", frames[i]);
    }
    printf("\n");
    return 0;
}
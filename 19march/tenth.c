#include <stdio.h>

int main()
{
    int p1=0,p2=0,p3=0,p4=0,p5=0;
    int numbers[] = {100,200,300,400,500,600,700,800,900,1000};
    for(int i = 0; i < 10; i++)
    {
        if (numbers[i] < 200)
        {
            p1++;
        }
        else if (numbers[i] >= 200 && numbers[i] < 400)
        {
            p2++;
        }
        else if (numbers[i] >= 400 && numbers[i] < 600)
        {
            p3++;
        }
        else if (numbers[i] >= 600 && numbers[i] < 800)
        {
            p4++;
        }
        else if (numbers[i] >= 800)
        {
            p5++;
        }
    }

    printf("From 0 to 199: %.2f%%\n", ((double)p1 / 10) * 100);
    printf("From 200 to 399: %.2f%%\n", ((double)p2 / 10) * 100);
    printf("From 400 to 599: %.2f%%\n", ((double)p3 / 10) * 100);
    printf("From 600 to 799: %.2f%%\n", ((double)p4 / 10) * 100);
    printf("From 800 to 1000: %.2f%%\n", ((double)p5 / 10) * 100);

    return 0;
}
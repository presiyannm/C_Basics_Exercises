#include <stdio.h>

int main()
{
    int x,y,x1,y1,x2,y2;
    printf("Enter the coordinates of the first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of the second point (x2 y2): ");
    if(scanf("%d", &x2) < x1 || scanf("%d", &y2) < y1)
    {
        printf("Invalid input for the second point. Please enter coordinates greater than the first point.\n");
        return 1;
    }
    printf("Enter the coordinates of the point to check (x y): ");
    scanf("%d %d", &x, &y);
    
    if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
    {
        printf("The point (%d, %d) is inside the rectangle defined by (%d, %d) and (%d, %d).\n", x, y, x1, y1, x2, y2);
    }
    else
    {
        printf("The point (%d, %d) is outside the rectangle defined by (%d, %d) and (%d, %d).\n", x, y, x1, y1, x2, y2);
    }
    return 0;
}
#include <stdio.h>

int calculateAreaOfSquare(int a)
{
    return a*a;
}

int calculateAreaOfRectangle(int l, int b)
{
    return l*b;
}

int calculateAreaOfCircle(int r)
{
    return 3.14*r*r;
}

int calculateAreaOfTriangle(int b, int h)
{
    return 0.5*b*h;
}

int main()
{
    int a;
    printf("Choose from 1 to 4 to calculate area of square, rectangle, circle and triangle respectively: ");
    scanf("%d", &a);
    if(a == 1)
    {
        int side;
        printf("Enter the side of the square: ");
        scanf("%d", &side);
        printf("Area of the square is: %d", calculateAreaOfSquare(side));
    }
    else if(a == 2)
    {
        int length, breadth;
        printf("Enter the length and breadth of the rectangle: ");
        scanf("%d %d", &length, &breadth);
        printf("Area of the rectangle is: %d", calculateAreaOfRectangle(length, breadth));
    }
    else if(a == 3)
    {
        int base, height;
        printf("Enter the base and height of the triangle: ");
        scanf("%d %d", &base, &height);
        printf("Area of the triangle is: %d", calculateAreaOfTriangle(base, height));
    }
    else if(a == 4)
    {
        int radius;
        printf("Enter the radius of the circle: ");
        scanf("%d", &radius);
        printf("Area of the circle is: %d", calculateAreaOfCircle(radius));
    }
    else
    {
        printf("Invalid choice!");
    }

    return 0;
}


#include <stdio.h>
#include <math.h>

void calculateStuffOfSquare(int a)
{
    printf("The figure is square\n");
    printf("Area of the square is: %d\n", a*a);
    printf("Perimeter of the square is: %d\n", 4*a);
}

void calculateStuffOfRectangle(int l, int b)
{
    printf("The figure is rectangle\n");
    printf("Area of the rectangle is: %d\n", l*b);
    printf("Perimeter of the rectangle is: %d\n", 2*(l+b));
}

void calculateStuffOfCircle(int r)
{
    printf("The figure is circle\n");
    printf("Area of the circle is: %d\n", 3.14*r*r);
    printf("Circumference of the circle is: %d\n", 2*3.14*r);
}

void calculateStuffOfTriangle(int b, int h)
{
    printf("The figure is triangle\n");
    printf("Area of the triangle is: %.2f\n", 0.5*b*h);
    int thirdSide = sqrt(pow(b, 2) + pow(h, 2));
    printf("Perimeter of the triangle is: %d\n", b + h + thirdSide);
}

void calculateStuffOfTrapezium(int a, int b, int h)
{
    printf("The figure is trapezium\n");
    printf("Area of the trapezium is: %d\n", 0.5*(a+b)*h);
    int side = sqrt(pow((b-a), 2) + pow(h, 2));
    printf("Perimeter of the trapezium is: %d\n", a + b + h + side);
}

int main()
{
    int a;
    printf("Choose from 1 to 5 to calculate area and perimeter of square, rectangle, circle, triangle and trapezium respectively: ");
    scanf("%d", &a);
    if(a == 1)
    {
        int side;
        printf("Enter the side of the square: ");
        scanf("%d", &side);
        calculateStuffOfSquare(side);
    }
    else if(a == 2)
    {
        int length, breadth;
        printf("Enter the length and breadth of the rectangle: ");
        scanf("%d %d", &length, &breadth);
        calculateStuffOfRectangle(length, breadth);
    }
    else if(a == 3)
    {
        int radius;
        printf("Enter the radius of the circle: ");
        scanf("%d", &radius);
        calculateStuffOfCircle(radius);
    }
    else if(a == 4)
    {
        int base, height;
        printf("Enter the base and height of the triangle: ");
        scanf("%d %d", &base, &height);
        calculateStuffOfTriangle(base, height);
    }
    else if(a == 5)
    {
        int a, b, h;
        printf("Enter the lengths of the parallel sides and height of the trapezium: ");
        scanf("%d %d %d", &a, &b, &h);
        calculateStuffOfTrapezium(a, b, h);
    }
    else
    {
        printf("Invalid choice!");
    }
    return 0;
}
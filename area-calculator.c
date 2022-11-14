#include <stdio.h>
// Program to calculate the area of circle, square or sphere upon option entry and gives the output based on the measurements entered by user.
int main()
{
    int loop=1;
    while (loop) //Table for entering the option.
    {
        float result;
        int num;
        char choice;
        printf("=============================\n");
        printf("|~~~~~Area Calculator~~~~~~~|\n");
        printf("=============================\n");
        printf("a).Calculate area of circle\n");
        printf("b).Calculate area of square\n");
        printf("c).Calculate area of sphere\n");
        printf("d).Exit Program\n");
        printf("=============================\n");
        printf("\nEnter your choice:");
        scanf(" %c", &choice);
        fflush(stdout);  
        switch (choice)
        {
        case 'a':     //For circle
        {
            printf("\nEnter radius:");
            scanf("%d", &num);
            result = 3.14 * num * num;
            printf("Area of Circle=%f\n",result);
            break;
        }
        case 'b':     //For square
        {
            printf("\nEnter side of square:");
            scanf("%d", &num);
            result = num * num;
            printf("Area of Square=%f\n",result);
            break;
        }
        case 'c':      //For sphere
        {
            printf("\nEnter radius:");
            scanf("%d", &num);
            result = 4 * (3.14 * num * num);
            printf("Area of Sphere=%f\n",result);
            break;
        }
        case 'd':      //Else
            loop=0;
            break;
        default:
            printf("Invalid Option\n");
        }
    }

    return 0;
}

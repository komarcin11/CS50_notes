#include <stdio.h>
int main(void)
{
    int i = 2;
    switch(i)// it will compare the varaible in () with the valeuses in the cases
    {
        case 1:
            printf("i = one\n");
            break;
        case 2:
            printf("i = two\n");
            break;
        default:
            printf("i is not two or one");
    }
    return 0;
}
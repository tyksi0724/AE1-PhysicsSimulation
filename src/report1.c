#include <stdio.h>
#include <math.h>

int main(void)
{
    double z = sqrt(168.9);
    double x = 13.0 -z; double y = 0.1/(13.0 +z);
    double err = fabs(1.0 -x/y);
    printf( "         13 = %15.7e \n", 13.0);
    printf( "sqrt(168.9) = %15.7e \n", z);
    printf( "          x = %15.7e \n", x);
    printf( "      y,err = %15.7e %12.5e\n", y, err);
}
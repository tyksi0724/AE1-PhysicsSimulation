#include <stdio.h>
#include <math.h>

#define TAYLOR_TERMS 20
// TAYLOR_TERMSはTaylor展開の項数を指定するマクロ

#define pi 3.14159265358979323846

double taylor_sin(double x) 
{
    // xを[-pi, pi]に収めてからTaylor展開
    x = fmod(x + pi, 2 * pi);
    if (x < 0) x += 2 * pi;
    x -= pi;
    double term = x;
    double sum = x;
    int n = 1;
    const double EPS = 1e-15; // マシンイプシロン程度の閾値
    while (fabs(term) > EPS) {
        term *= -x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }
    return sum;
}

int main(void)
{
    printf("x, taylor_sin(x), sin(x), rel_error\n");
    printf("--------------------------------------------------\n");
    for (int i = 2; i <= 50; i += 2) 
    {
        double x = (double)i;
        double taylor = taylor_sin(x);
        double libsin = sin(x);
        double relerr = fabs((taylor - libsin) / libsin);
        printf("%2d %15.7e %15.7e %12.5e\n", i, taylor, libsin, relerr);
    }
}
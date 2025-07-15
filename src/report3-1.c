#include <stdio.h>
#include <math.h>

// 積分範囲
#define I1_A 0.0
#define I1_B 2.0
#define I2_A 0.0
#define I2_B 1.0


double f1(double x) {
    return pow(x, 5);
}

double f2(double x) {
    return x * sqrt(1 + x * x);
}

// 台形則
double trapezoidal(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

// Simpson則
double simpson(double (*f)(double), double a, double b, int n) {
    if (n % 2 != 0) n++; // nを偶数に
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 4 * f(a + i * h);
    }
    return sum * h / 3.0;
}

int main() {
    int Ns[] = {8,16,32,64,128,256,512};
    int num_Ns = sizeof(Ns)/sizeof(Ns[0]);

    double exact_I1 = pow(2.0,6)/6.0;      
    double exact_I2 = sqrt(2.0) - 1.0;     

    printf("I1 = ∫0^2 x^5 dx\n");
    printf("N\t台形\t\t誤差\t\tSimpson\t\t誤差\n");
    for (int i=0; i<num_Ns; i++) {
        int N = Ns[i];
        double trap = trapezoidal(f1, I1_A, I1_B, N);
        double simp = simpson(f1, I1_A, I1_B, N);
        printf("%d\t%.8f\t%.2e\t%.8f\t%.2e\n",
            N,
            trap, fabs(trap - exact_I1)/exact_I1,
            simp, fabs(simp - exact_I1)/exact_I1);
    }

    printf("\nI2 = ∫0^1 x/sqrt(1+x^2) dx\n");
    printf("N\t台形\t\t誤差\t\tSimpson\t\t誤差\n");
    for (int i=0; i<num_Ns; i++) {
        int N = Ns[i];
        double trap = trapezoidal(f2, I2_A, I2_B, N);
        double simp = simpson(f2, I2_A, I2_B, N);
        printf("%d\t%.8f\t%.2e\t%.8f\t%.2e\n",
            N,
            trap, fabs(trap - exact_I2)/exact_I2,
            simp, fabs(simp - exact_I2)/exact_I2);
    }
    return 0;
}

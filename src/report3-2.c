#include <stdio.h>
#include <math.h>

// 積分区間
#define I3_A (-M_PI/2)
#define I3_B (M_PI/2)
#define I4_A 1.0
#define I4_B 1000.0  // 無限大の代わりに大きな値を使う

// 被積分関数
double f3(double x) {
    return pow(x,3) * sin(x);
}

double f4(double x) {
    return log(x) / (x*x);
}

// 中点則
double midpoint(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for(int i=0; i<n; i++) {
        double xi = a + (i + 0.5) * h;
        sum += f(xi);
    }
    return sum * h;
}

int main() {
    int N = 512;  // 分割数

    double i3 = midpoint(f3, I3_A, I3_B, N);
    double i4 = midpoint(f4, I4_A, I4_B, N);

    printf("課題2: 拡張中点則 N=%d\n", N);
    printf("I3 = ∫_{-π/2}^{π/2} x^3*sin(x) dx = %.10f\n", i3);
    printf("I4 = ∫_{1}^{∞} ln(x)/x^2 dx (∞を1000で近似) = %.10f\n", i4);

    return 0;
}

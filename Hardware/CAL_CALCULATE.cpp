#include "CAL_math.h"
#include <vector>
#include"stm32f10x.h"
#include <cmath>

extern char x;
using std::vector;

std::vector<char>Expression;

double f(double x) {
    return x*x*x*x;  
}

void Getexpression()
{
    
    while(Expression.back()!='=')
{
        
}

}

double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += 2 * f(x);
    }

    return sum * h / 2; 
}

double intergral()
 {
    double up =100;         
    double down =0;    
    int n = 100;             

    double result = trapezoidal_rule(up, down, n);
    

    return 0;
}



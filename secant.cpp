#include <bits/stdc++.h>
using namespace std;

/* Rohan */

int n;
double a[20];

double f(double x)
{
    double sum = 0;

    for(int i = 0; i <= n; i++)
        sum = sum * x + a[i];

    return sum;
}

int main()
{
    cout << "Enter degree: ";
    cin >> n;

    cout << "Enter coefficients:\n";

    for(int i = 0; i <= n; i++)
        cin >> a[i];

    // Print polynomial
    cout << "\nPolynomial: ";

    for(int i = 0; i <= n; i++)
    {
        int power = n - i;

        if(i > 0 && a[i] >= 0)
            cout << "+";

        cout << a[i];

        if(power > 1)
            cout << "x^" << power;
        else if(power == 1)
            cout << "x";
    }

    // Find hi
    double hi = 0;

    for(int i = 1; i <= n; i++)
    {
        double temp = abs(a[i] / a[0]);

        if(temp > hi)
            hi = temp;
    }

    hi = 1 + hi;

    double low = -hi;

    cout << "\nRange = [" << low << ", " << hi << "]\n";

    double period = 0.45;
    double error = 0.001;

    cout << "\n===== SECANT METHOD =====\n";

    double x = low;
    int rootNo = 0;

    while(x < hi)
    {
        double y = min(x + period, hi);

        // Check whether root is inside this bracket
        if(f(x) * f(y) < 0)
        {
            double x0 = x;
            double x1 = y;
            double x2 = x1;

            int iteration = 0;

            while(iteration < 1000)
            {
                // Avoid division by zero
                if(abs(f(x1) - f(x0)) < 1e-12)
                    break;

                x2 = x1 - f(x1) * (x1 - x0)
                         / (f(x1) - f(x0));

                iteration++;

                if(abs(x2 - x1) < error)
                    break;

                x0 = x1;
                x1 = x2;
            }

            rootNo++;

            cout << "\nRoot " << rootNo << " = "
                 << fixed << setprecision(6) << x2;

            cout << "\nBracket = [" << x << ", " << y << "]";

            cout << "\nIterations = "
                 << iteration << endl;
        }

        x = y;
    }

    return 0;
}

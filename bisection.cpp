#include <bits/stdc++.h>
using namespace std;

double a, b, c, d, e;

double f(double x)
{
    return a*x*x*x*x + b*x*x*x + c*x*x + d*x + e;
}

double bisection(double l, double r)
{
    double m;

    for(int i = 0; i < 100; i++)
    {
        m = (l + r) / 2;

        if(f(l) * f(m) < 0)
            r = m;
        else
            l = m;
    }

    return m;
}

int main()
{
    cout << "Enter a, b, c, d, e: ";
    cin >> a >> b >> c >> d >> e;

    // Root range
    double R =1+ max({
        abs(b/a),
        abs(c/a),
        abs(d/a),
        abs(e/a)
    });

    cout << "Root range: " << -R << " to " << R << endl;

    double x = -R;
    double step = 0.01;

    int root = 0;

    cout << "\nRoots using Bisection Method:\n";

    while(x < R && root < 4)
    {
        double x1 = x;
        double x2 = x + step;

        if(f(x1) * f(x2) < 0)
        {
            root++;

            double ans = bisection(x1, x2);

            cout << "Root " << root << " = "
                 << fixed << setprecision(6)
                 << ans << endl;
        }

        x += step;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
/*Rohan*/
//degree 4

double a,b,c,d,e;

double f(double x)
{
    return a*x*x*x*x + b*x*x*x + c*x*x + d*x + e;
}

double falsePosition(double l,double r)
{
    double m;

    for(int i=0; i<100; i++)
    {
        m = (l*f(r)-r*f(l))/(f(r)-f(l));

        if(f(l)*f(m) < 0)
            r = m;
        else
            l = m;
    }

    return m;
}

int main()
{
    cout<<"Input 5 constant only: ";
    cin >> a >> b >> c >> d >> e;

    double r = 1 + max({
        abs(b/a),
        abs(c/a),
        abs(d/a),
        abs(e/a)
    });

    int root = 0;

    double x = -r, t = 0.01;

    while(x < r && root < 4)
    {
        double x1 = x;
        double x2 = x + t;

        if(f(x1)*f(x2) < 0)
        {
            root++;

            double ans = falsePosition(x1,x2);

            cout << "Root " << root << " = "
                 << fixed << setprecision(4)
                 << ans << endl;
        }

        x += t;
    }

    return 0;
}

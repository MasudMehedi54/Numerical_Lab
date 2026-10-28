#include<bits/stdc++.h>
using namespace std;

/*Rohan*/

double E = 1e-9;

void printMatrix(vector<vector<double>>& a, int n) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            cout << setw(10) << fixed << setprecision(3)
                 << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int main() {

    int n;
    char ch;

    do {

        cout << "Enter number of equations: ";
        cin >> n;

        vector<vector<double>> a(n, vector<double>(n + 1));
        vector<vector<double>> org(n, vector<double>(n + 1));

        cout << "Enter AUG matrix:" << endl;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= n; j++) {
                cin >> a[i][j];
            }
        }

        org = a;

        cout << "\nInitial Augmented Matrix:\n";
        printMatrix(a, n);


        bool impossible = false;

        for(int i = 0; i < n; i++) {

            int p = i;

            for(int j = i + 1; j < n; j++) {
                if(fabs(a[j][i]) > fabs(a[p][i])) {
                    p = j;
                }
            }

            if(fabs(a[p][i]) < E) {
                continue;
            }

            if(p != i) {
                swap(a[i], a[p]);

                cout << "After row swap R" << i + 1
                     << " <-> R" << p + 1 << ":\n";

                printMatrix(a, n);
            }

            double x = a[i][i];

            for(int j = 0; j <= n; j++) {
                a[i][j] /= x;
            }

            cout << "After making pivot 1 (Row " << i + 1 << "):\n";
            printMatrix(a, n);



            for(int k = 0; k < n; k++) {

                if(k == i)
                    continue;

                double f = a[k][i];

                if(fabs(f) < E)
                    continue;

                for(int j = 0; j <= n; j++) {
                    a[k][j] -= f * a[i][j];
                }
            }

            cout << "After eliminating column " << i + 1 << ":\n";
            printMatrix(a, n);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= n; j++) {
                if(fabs(a[i][j]) < E)
                    a[i][j] = 0;
            }
        }


        int rnkA = 0;
        int rnkAUG = 0;

        for(int i = 0; i < n; i++) {

            bool nzA = false;
            bool nzAUG = false;


            for(int j = 0; j < n; j++) {
                if(fabs(a[i][j]) > E) {
                    nzA = true;
                    break;
                }
            }


            for(int j = 0; j <= n; j++) {
                if(fabs(a[i][j]) > E) {
                    nzAUG = true;
                    break;
                }
            }

            if(nzA)
                rnkA++;

            if(nzAUG)
                rnkAUG++;
        }

        if(rnkA < rnkAUG) {

            cout << "No solution." << endl;
        }

        else if(rnkA < n) {

            cout << "Infinite solutions." << endl;
        }

        else {

            cout << "Unique Solution." << endl;

            vector<double> x(n);

            for(int i = 0; i < n; i++) {
                x[i] = a[i][n];
            }

            cout << "\nSolutions:\n";

            for(int i = 0; i < n; i++) {
                cout << "x" << i + 1 << " = "
                     << fixed << setprecision(3)
                     << x[i] << endl;
            }

            cout << "\nVerification:\n";

            int k = 0;

            for(int i = 0; i < n; i++) {

                double sum = 0;

                for(int j = 0; j < n; j++) {
                    sum += org[i][j] * x[j];
                }

                cout << "Equation " << i + 1 << ": ";

                if(fabs(sum - org[i][n]) < E) {
                    cout << "Satisfied" << endl;
                    k++;
                }
                else {
                    cout << "Not satisfied" << endl;
                }
            }

            if(k == n)
                cout << "\nSolution verified successfully." << endl;
        }


        cout << "\nSolve another system? (y/n): ";
        cin >> ch;

    } while(ch == 'y' || ch == 'Y');

    return 0;
}

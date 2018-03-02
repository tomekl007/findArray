#include <iostream>

using namespace std;

int kadane2D(int n, int a[][101]) {
    int *columnSum = new int[n];
    int s = INT_MIN, S = INT_MIN, t;
    for (int row = 0; row < n; row++) {
        for (int i = 0; i < n; i++) columnSum[i] = 0;
        for (int x = row; x < n; x++) {
            s = INT_MIN;
            t = 0;
            for (int i = 0; i < n; i++) {
                columnSum[i] += a[x][i];
                t += columnSum[i];
                if (t > s)
                    s = t;
                if (t < 0)
                    t = 0;
            }
            if (s > S)
                S = s;
        }
    }
    delete[] columnSum;
    return S;
}

int main() {

    int numberOfArrays;
    int numberOfRows[101];
    int numberOfColumns[101];

    cin >> numberOfArrays;
    int a[numberOfArrays][101][101];

    for (int i = 0; i < numberOfArrays; i++) {
        cin >> numberOfRows[i];
        cin >> numberOfColumns[i];

        for (int rows = 0; rows < numberOfRows[i]; rows++) {
            for (int column = 0; column < numberOfColumns[i]; column++) {
                int columnValue;
                cin >> columnValue;
                a[i][rows][column] = columnValue;
            }

        }
    }


    for (int c = 0; c < numberOfArrays; c++) {
        int dim = 3;
        cout << kadane2D(dim, a[c]) << endl;
    }

    return 0;
}
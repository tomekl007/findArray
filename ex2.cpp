#include <iostream>

void test1();

void test2();

void test3();

void test4();


using namespace std;

int kadane2D(int rowCount, int columnCount, int a[][101]) {
    int *columnSum = new int[columnCount];
    int s = INT_MIN, S = INT_MIN, t;
    for (int row = 0; row < rowCount; row++) {
        for (int i = 0; i < columnCount; i++) columnSum[i] = 0;
        for (int x = row; x < rowCount; x++) {
            s = INT_MIN;
            t = 0;
            for (int i = 0; i < columnCount; i++) {
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
        int rowCount = numberOfRows[c];
        int columnCount = numberOfColumns[c];
        cout << kadane2D(rowCount, columnCount, a[c]) << endl;
    }



    return 0;
}


////todo only for test
//int main() {
//    test1();
//    test2();
//    test3();
//    test4();
//    return 0;
//}
//
//
//void test1() {
//    int tab[4][101] = { //todo load from standard input
//            {0,  -2, -7, 0},
//            {9,  2,  -6, 2},
//            {-4, 1,  -4, 1},
//            {-1, 8,  0,  -2}
//    };
//    int nubmerOfColumns = 4;
//    int nubmerOfRows = 4;
//
//    cout << kadane2D(nubmerOfRows, nubmerOfColumns, tab) << endl;
//
//}
//
//void test2() {
//    int tab[][101] = { //todo load from standard input
//            {1, 1, 1},
//            {1, 1, 1},
//            {1, 1, 1}
//    };
//    int nubmerOfColumns = 3;
//    int nubmerOfRows = 3;
//
//    cout << kadane2D(nubmerOfRows, nubmerOfColumns, tab) << endl;
//
//}
//
//void test3() {
//    int tab[][101] = { //todo load from standard input
//            {-1, -1, -1},
//            {-1, 1,  -1},
//            {-1, -1, -1}
//    };
//    int nubmerOfColumns = 3;
//    int nubmerOfRows = 3;
//
//    cout << kadane2D(nubmerOfRows, nubmerOfColumns, tab) << endl;
//
//}
//
//
//void test4() {
//    int tab[][101] = { //todo load from standard input
//            {-1, 2,  -3, 5,  -4, -8,  3, -3},
//            {2,  -4, -6, -8, 2,  -5,  4, 1},
//            {3,  -2, 9,  -9, -1, 10, -5, 2},
//            {1,  -3, 5,  -7, 8,  -2,  2, -6}
//    };
//    int nubmerOfColumns = 8;
//    int nubmerOfRows = 4;
//
//    cout << kadane2D(nubmerOfRows, nubmerOfColumns, tab) << endl;
//
//}


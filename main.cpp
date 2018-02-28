#include <iostream>

int test2();
int test3();

int main() {
    long result = test2();
    std::cout << result << std::endl;
    std::cout << test3() << std::endl;
    return 0;
}

int test2() {
    int tab[4][4] = { //todo load from standard input
            {0,  -2, -7, 0},
            {9,  2,  -6, 2},
            {-4, 1,  -4, 1},
            {-1, 8,  0,  -2}
    };

    int n = 4;
    int m = 4;

    int max1 = 0;
    int max2 = 0;
    int suma = 0;

    int tmp[] = {0, 0, 0, 0}; //wiersz

    for (int i = 0; i < n; i++) //wiersze
    {
        for (int w = 0; w < m; w++) tmp[w] = 0; //czyszczenie tmp
        for (int j = i; j < n; j++) //wiersze
        {
            //pierwotna wersja algorytmu Kadane dla jednowymiarowej talbicy
            max1 = 0;

            for (int k = 0; k < m; k++) //kolumny
            {
                tmp[k] += tab[j][k];
                max1 += tmp[k];

                if (max1 > max2) max2 = max1;
            }

            if (suma < max2)
                suma = max2;
        }
    }

    return suma;
}


int test3() {
    int tab[3][3] = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1},
    };

    int n = 3;
    int m = 3;

    int max1 = 0;
    int max2 = 0;
    int suma = 0;

    int tmp[] = {0, 0, 0}; //wiersz

    for (int i = 0; i < n; i++) //wiersze
    {
        for (int w = 0; w < m; w++) tmp[w] = 0; //czyszczenie tmp
        for (int j = i; j < n; j++) //wiersze
        {
            //pierwotna wersja algorytmu Kadane dla jednowymiarowej talbicy
            max1 = 0;

            for (int k = 0; k < m; k++) //kolumny
            {
                tmp[k] += tab[j][k];
                max1 += tmp[k];

                if (max1 > max2) max2 = max1;
            }

            if (suma < max2)
                suma = max2;
        }
    }

    return suma;
}




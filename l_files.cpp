#include <sstream>
#include <vector>
#include "l_files.h"


int f_wyszukiwanie_interpolacyjne(long long k, int N, long long *Z);

void
obliczLiczbeElementow(long long dataSet[], int numberOfElements, const long long dataSetToFind[], int numbersToFind);

int f_znajd_liczbe_wystapien(long long szukanaLiczbna, int N, long long dataSet[]);

using namespace std;

void split(string line, long long arr[], int numberOfElements) {
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < numberOfElements) {
        ssin >> arr[i];
        ++i;
    }
    for (i = 0; i < numberOfElements; i++) {
        cout << arr[i] << endl;
    }
}


void f_otwarcie_pliku_do_odczytu(ifstream &odczyt_pliku) {
    string nazwa = "/Users/tomasz.lelek/CLionProjects/tablica/in1.txt"; //todo hardcoded
    cout << "Podaj pelna sciezke do pliku: " << endl;

    // /Users/tomasz.lelek/CLionProjects/tablica/in1.txt
//    cin >> nazwa;


    int numberOfInputDataSets = 0;

    string line;
    ifstream myfile(nazwa);
    if (myfile.is_open()) {
        getline(myfile, line);
        numberOfInputDataSets = std::stoi(line);

        cout << "number of data sets " << numberOfInputDataSets << endl;

        for (int dataSetNumber = 0; dataSetNumber < numberOfInputDataSets; dataSetNumber++) {
            getline(myfile, line);
            int numberOfElements = std::stoi(line);
            cout << "number of elements " << numberOfElements << endl;
            long long dataSet[numberOfElements];

            getline(myfile, line);
            cout << "dataSet before parse " << line << endl;
            split(line, dataSet, numberOfElements);
            for (int i = 0; i < numberOfElements; i++) {
                cout << "--> " << dataSet[i] << endl;
            }


            getline(myfile, line);
            int numberOfElementsToSearch = std::stoi(line);
            long long dataToFind[numberOfElementsToSearch];
            getline(myfile, line);
            cout << "dataSet to find before parse " << line << endl;
            split(line, dataToFind, numberOfElementsToSearch);

            obliczLiczbeElementow(dataSet, numberOfElements, dataToFind, numberOfElementsToSearch);

        }

        myfile.close();


    } else cout << "Unable to open file ";
}


int f_wyszukiwanie_interpolacyjne(long long k, int N, long long *Z) {
    // poszukujemy interpolacyjnie elementu k
    int ip, ik, isr, L, p;

    L = ip = 0;
    ik = N - 1;
    while ((Z[ip] <= k) && (k <= Z[ik])) {
        L++;
        isr = ip + (k - Z[ip]) * (ik - ip) / (Z[ik] - Z[ip]);
        if (Z[isr] == k) {
            p = isr;
            return p;
        } else if (k < Z[isr])
            ik = isr - 1;
        else
            ip = isr + 1;
    }

    return -1;
}


void
obliczLiczbeElementow(long long dataSet[], int numberOfElements, const long long dataSetToFind[], int numbersToFind) {

    for (int i = 0; i < numbersToFind; i++) {
//        wyszukiwanieBinarne(dataSet, numberOfElements, dataSetToFind[i]);

        long long szukanaLiczba = dataSetToFind[i];

        int liczbaElementow = f_znajd_liczbe_wystapien(szukanaLiczba, numberOfElements, dataSet);
        cout << "liczba Elementow: " << liczbaElementow << endl;

        int index = f_wyszukiwanie_interpolacyjne(szukanaLiczba, numberOfElements, dataSet);
        cout << "index: " << index << endl;

    }
}

int f_znajd_liczbe_wystapien(long long szukanaLiczbna, int N, long long dataSet[]) {
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (dataSet[i] == szukanaLiczbna) {
            counter++;
        }
    }
    return counter;
}


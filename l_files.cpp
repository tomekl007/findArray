#include <sstream>
#include <vector>
#include <set>
#include "l_files.h"


int f_wyszukiwanie_interpolacyjne(long long k, int N, long long *Z);

long long **
obliczLiczbeElementow(long long int dataSet[], int numberOfElements, long long int dataSetToFind[],
                      int numbersToFind);

int f_znajd_liczbe_wystapien(long long szukanaLiczbna, int N, long long dataSet[]);


set<long long> f_usun_duplikaty(long long dataSet[], int n);

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


            //todo tmp directory
            ofstream outputFile(string("/tmp/out")
                                        .append(std::to_string(dataSetNumber + 1))
                                        .append(".txt")
            );

            long long **result = obliczLiczbeElementow(dataSet,
                                                       numberOfElements,
                                                       dataToFind,
                                                       numberOfElementsToSearch
            );


            for (int i = 0; i < numberOfElementsToSearch; i++) {
                cout << result[i][0] << " " << result[i][1] << " " << endl;

                outputFile << "(" << result[i][0] << " " << result[i][1] << ") ";
            }
            outputFile << endl;

            auto usunieteDuplikaty = f_usun_duplikaty(dataSet, numberOfElements);

            int counter = 0;
            for (auto f : usunieteDuplikaty) {
                if (counter >= 200) {
                    break;
                }

                if (counter % 50 == 0) {
                    outputFile << endl;
                }

                cout << "dup removed: " << endl;
                cout << f;
                outputFile << f << " ";
                counter++;
            }
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


long long **
obliczLiczbeElementow(long long int dataSet[], int numberOfElements, long long int dataSetToFind[],
                      int numbersToFind) {
    auto **result = new long long *[numbersToFind];

    for (int i = 0; i < numbersToFind; i++) {
//        wyszukiwanieBinarne(dataSet, numberOfElements, dataSetToFind[i]);

        long long szukanaLiczba = dataSetToFind[i];

        int liczbaElementow = f_znajd_liczbe_wystapien(szukanaLiczba, numberOfElements, dataSet);
        cout << "liczba Elementow: " << liczbaElementow << endl;

        int index = f_wyszukiwanie_interpolacyjne(szukanaLiczba, numberOfElements, dataSet);
        cout << "index: " << index << endl;

        result[i] = new long long[2];
        result[i][0] = liczbaElementow;
        result[i][1] = index;
    }
    return result;
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

set<long long> f_usun_duplikaty(long long dataSet[], int n) {
//    long long result[n];
//
//    for (int i = 0; i < n; i++) {
//        result[dataSet[i] % n] = dataSet[i];
//    }
//    return result;

    std::set<long long> result;

    for (int i = 0; i < n; i++) {
        result.insert(dataSet[i]);
    }
    return result;
}


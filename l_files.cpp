#include <sstream>
#include <vector>
#include "l_files.h"

using namespace std;

void split(string line, int arr[], int numberOfElements) {
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
            int dataSet[numberOfElements];

            getline(myfile, line);
            split(line, dataSet, numberOfElements);
            cout << "dataSet before parse " << line << endl;

            getline(myfile, line);
            int numberOfElementsToSearch = std::stoi(line);
            int dataToFind[numberOfElementsToSearch];
            getline(myfile, line);
            cout << "dataSet to find before parse " << line << endl;
            split(line, dataToFind, numberOfElementsToSearch);
        }

        myfile.close();
    } else cout << "Unable to open file ";

}

long long *f_otworz_tab(unsigned short int rozmiar) {
    long long *tab;
    tab = new long long[rozmiar];

    return tab;
}


int f_wyszukiwanie_interpolacyjne(long long wartosc_szukana, int Ip, int Ik, long long *tab) {
    int Is; //indeks szukanej
    Is = (Ip + ((wartosc_szukana - tab[Ip] * (Ik - Ip)) / (tab[Ik] - tab[Ip])));
    if (tab[Is] == wartosc_szukana)
        return Is;

    while (tab[Is] != wartosc_szukana) {
        if (tab[Is] != wartosc_szukana) {
            Ik = Is;
            Is = (Ip + ((wartosc_szukana - tab[Ip] * (Ik - Ip)) / (tab[Ik] - tab[Ip])));
        } else {
            if (tab[Is] < wartosc_szukana) {
                Ip = Is;
                Is = (Ip + ((wartosc_szukana - tab[Ip] * (Ik - Ip)) / (tab[Ik] - tab[Ip])));
            }
        }
    }
    return Is;
}


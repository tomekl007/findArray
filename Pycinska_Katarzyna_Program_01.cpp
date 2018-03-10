#include <iostream>
#include <string>
#include <fstream>
#include "l_files.h"

using namespace std;

int main() {
    ifstream odczyt_pliku;
    ofstream zapis_pliku;

    f_otwarcie_pliku_do_odczytu(odczyt_pliku);


    unsigned short int z; //zmienna oznaczajaca ilosc zestawow
    unsigned short int a; //zmienna oznaczajaca ilosc danych w zestawie
    unsigned short int b; //zmienna oznaczajaca ilosc zapytan o szukana wartosc

    odczyt_pliku >> z; //ile zestawow wyswietlic

//    //instrukcja dla jednego zestawu
//    for (int i = 0; i < z; i++) {
//        odczyt_pliku >> a;
//        long long *tab = f_otworz_tab(a); //tablica przechowujaca dane z jednego zestawu
//
//        for (int i = 0; i < a; i++) {
//            odczyt_pliku >> tab[i];
//        }
//
//        odczyt_pliku >> b;
//
//        long long *tab_search = f_otworz_tab(b);
//
//        for (int i = 0; i < b; i++) {
//            odczyt_pliku >> tab_search[i];           //tablica przechowujaca szukane wartosci
//        }
//
//        unsigned short int Ip = 0;    //Ip-indeks poczatkowy
//        int Ik = a - 1; //indeks koncowy
//
//        int Is; //indeks szukanej
//
//        for (int i = 0; i < b; i++) {
//            long long search = tab_search[i];
//            int l = 0; //l-ilosc wystapienia szukanej wartosci
//            for (int j = 0; j < a; j++) {
//                if (tab[j] == search)
//                    l++;
//            }
//
//            if (l != 0 && l != a) {
//                int Is = f_wyszukiwanie_interpolacyjne(search, Ip, Ik, tab);
//            } else {
//                if (l == 0)
//                    Is = -1;
//                if (l == a)
//                    Is = 0;
//            }
//            zapis_pliku << "(" << l << " " << Is << ") ";
//        }
//        zapis_pliku << endl;
//
//        //usunac duplikaty i wpisac 200 poczatkowy elementow tablicy po usunieciu duplikatow
//    }
//    zapis_pliku << endl;
//
//    odczyt_pliku.close();
//    zapis_pliku.close();
//    getchar();
    return 0;
}
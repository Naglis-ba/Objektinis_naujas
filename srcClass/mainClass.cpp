/**
 * @file mainClass.cpp
 * @author Naglis
 * @brief Pagrindinė programa studentų pažymių valdymo sistemai class versijai
 * @version 0.1
 * @date 2025-12-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "studentasClass.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>     
#include <algorithm>   
#include <sstream> 
#include <fstream>
#include <list>
#include "funkcijosClass.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::left;
using std::swap;
using std::stoi;
/**
 * @brief Suvedimo funkcija, kuri leidžia įvesti studentų duomenis rankiniu būdu arba nuskaityti iš failo
 * 
 * @param Studentu_sarasas 
 */
void Suvedimas(vector<Studentas>& Studentu_sarasas){
        srand(static_cast<unsigned>(time(0)));
    auto start = std::chrono::high_resolution_clock::now();

    while (true) {
        cout << "\nPasirinkite veiksma:\n";
        cout << "1 - Ivesti studento duomenis rankiniu budu / Generuoti pažymius\n";
        cout << "2 - Nuskaityti studentus is failo\n";
        cout << "0 - Baigti/Rodyti lentelę\n";
        cout << "Jusu pasirinkimas: ";
        int pasirinkimas;
        cin >> pasirinkimas;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (pasirinkimas) {
            case 0:
                return;
            case 1: {
                Studentas stud;
                Studentu_sarasas.push_back(stud);
                break;
            }
            case 2: {
                cout << "Failo pavadinimas: ";
                string failo_vardas;
                cin >> failo_vardas;
                std::vector<Studentas> loaded = Studentas::ReadFromFile(failo_vardas);
                for (auto& stud : loaded) {
                    Studentu_sarasas.push_back(std::move(stud));
                }
                break;
            }
        }

    }

}
/**
 * @brief Kviečia funkciją, kuri rikiuoja studentus pagal vartotojo pasirinkimą
 * 
 * @param Studentu_sarasas 
 */
void Rikiavimas(vector<Studentas>& Studentu_sarasas){

    cout << "Kaip rikiuoti sudentus?\n";
    cout << "0 - Pagal vardą \n";
    cout << "1 - Pagal pažymius \n";

    int a;
    cin >> a;
    if (a != 0 && a != 1) {
        cout << "Neteisingas pasirinkimas. Programa baigiama.\n";
        return;
    }
    Rikiavimas_output(a, Studentu_sarasas);

}
/**
 * @brief Skirstymo funkcija, kuri pagal vartotojo pasirinkimą išskiria išlaikiusius ir neišlaikiusius studentus
 * 
 * @param Studentu_sarasas 
 * @param zem_lyg 
 * @param aukst_lyg 
 */
void Skirstymas(vector<Studentas>& Studentu_sarasas, vector<Studentas>& zem_lyg,vector<Studentas>& aukst_lyg){

    cout << "Ar išskirti išlaikiusius ir neišlaikiusius?\n" ;
    cout << "1 - Taip\n";
    cout << "0 - Ne\n" ;
    int iskyrimas;
    cin >> iskyrimas;
    if (iskyrimas != 0 && iskyrimas != 1) {
        std::cout << "Klaida! Įveskite 0 arba 1.\n";
        return;
    }
    if (iskyrimas == 0){
        return;
    }

    if(iskyrimas == 1) {
        skirstymas_pagal_paz(Studentu_sarasas, zem_lyg, aukst_lyg);
    }

}
/**
 * @brief Išvedimo funkcija, kuri pagal vartotojo pasirinkimą išveda duomenis į failą arba konsolę
 * 
 * @param Studentu_sarasas 
 * @param zem_lyg 
 * @param aukst_lyg 
 */
void Isvedimas(const vector<Studentas> Studentu_sarasas,const vector<Studentas> zem_lyg,const vector<Studentas> aukst_lyg){

    cout << "Ar duomenis išvesti į failą?\n" ;
    cout << "1 - Taip\n";
    cout << "0 - Ne\n" ;
    int i_faila;
    cin >> i_faila;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (i_faila == 1) {
        if (zem_lyg.empty()) {
            Outas_i_faila(Studentu_sarasas);
        } else if (!zem_lyg.empty()) { 
            Outas_i_du_failus(zem_lyg, aukst_lyg);
        }
    } else {  // nerasyti į failą, rodyti konsolėje
        if (zem_lyg.empty()) {
            cout << "\nVisi studentai:\n";
            Outas_i_console(Studentu_sarasas);
        } else if (!zem_lyg.empty()) {
            cout << "\nNeišlaikę studentai:\n";
            Outas_i_console(zem_lyg);
            cout << "\nIšlaikę studentai:\n";
            Outas_i_console(aukst_lyg);
        } 
    }


}



int main() {
    srand(static_cast<unsigned>(time(0)));
    auto start = std::chrono::high_resolution_clock::now();
    vector<Studentas> Studentu_sarasas;
    vector<Studentas> zem_lyg;
    vector<Studentas> aukst_lyg;
    // Zmogus a;

    Suvedimas(Studentu_sarasas);

    Rikiavimas(Studentu_sarasas);
    
    Skirstymas(Studentu_sarasas, zem_lyg, aukst_lyg);
    
    Isvedimas(Studentu_sarasas, zem_lyg, aukst_lyg);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Programa uztruko: " << diff.count() << " s\n";

    return 0;
}
      
       

    
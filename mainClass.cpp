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
#include "funkcijos.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::left;
using std::swap;
using std::stoi;


int main() {
    
    vector<Studentas> Studentu_sarasas;

    Interface();

    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    srand(static_cast<unsigned>(time(0)));
    auto start = std::chrono::high_resolution_clock::now();
    int data;
    cout << "Pasirinkite duomenų struktūrą: \n";
    cout << "0 - vector \n";
    cout << "1 - list \n";
    cin >> data;
        vector<Studentas> studentai_vec;
        vector<Studentas> zem_lyg_vec;
        vector<Studentas> aukst_lyg_vec;
        std::list<Studentas> studentai_list;
        std::list<Studentas> zem_lyg_list;
        std::list<Studentas> aukst_lyg_list;
    while (true) {
        cout << "\nPasirinkite veiksma:\n";
        cout << "1 - Ivesti studento duomenis rankiniu budu\n";
        cout << "2 - Generuoti studento duomenis atsitiktinai\n";
        cout << "3 - Nuskaityti studentus is failo\n";
        cout << "0 - Baigti/Rodyti lentelę\n";
        cout << "Jusu pasirinkimas: ";
        int pasirinkimas;
        cin >> pasirinkimas;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (pasirinkimas == 0) break;

        if (pasirinkimas == 3) {
            cout << "Failo pavadinimas: ";
            string failo_vardas;
            cin >> failo_vardas;
            if (data == 1){
                nuskaitytiIsFailo(studentai_list, failo_vardas);
            } 
            else {
                nuskaitytiIsFailo(studentai_vec, failo_vardas);
            }
            continue;
        }

        Studentas stud;
        cout << "Iveskite studento varda: ";
        std::getline(cin, stud.vardas);
        cout << "Iveskite studento pavarde: ";
        std::getline(cin, stud.pavarde);

        if (pasirinkimas == 1) {
            IvestiPazymius(stud);
            cout << "Koks egzamino ivertinimas? ";
            cin >> stud.egz;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (pasirinkimas == 2) {
            generuotiAtsitiktinai(stud);
            cout << "Sugeneruoti pazymiai: ";
            for (int p : stud.paz) cout << p << " ";
            cout << "\nSugeneruotas egzamino balas: " << stud.egz << "\n";
        } else {
            cout << "Tokio pasirinkimo nera.\n";
            continue;
        }
        
    SkaiciuotiGalutinius(stud);
    if (data == 1){
        studentai_list.push_back(stud);
        const void* addr = static_cast<const void*>(&studentai_list.back());
        cout << "Objekto adresas konteineryje: " << addr << "\n";
        } 
    else {
        studentai_vec.push_back(stud);
        const void* addr = static_cast<const void*>(&studentai_vec.back());
        cout << "Objekto adresas konteineryje: " << addr << "\n";
    }
       
    }
        cout << "Kaip rikiuoti sudentus?\n";
        cout << "0 - Pagal vardą \n";
        cout << "1 - Pagal pažymius \n";

        int a;
        cin >> a;
        if (a != 0 && a != 1) {
            cout << "Neteisingas pasirinkimas. Programa baigiama.\n";
            return 1;
        }
        if (data == 1){
            Rikiavimas_output(a, data, studentai_list);
        }
        else {
            Rikiavimas_output(a, data, studentai_vec);
        }
       

        cout << "Ar išskirti išlaikiusius ir neišlaikiusius?\n" ;
        cout << "1 - Taip\n";
        cout << "0 - Ne\n" ;
        int iskyrimas;
        cin >> iskyrimas;
        int strat = 0;
        if (iskyrimas == 1){
            cout << "strategija?\n";
            cout << "0 - Pirma\n";
            cout << "1 - Antra\n";
            cin >> strat;
        }
        
        if(strat == 0) {
            if(iskyrimas == 1) {
                if (data == 1) {
                    skirstymas_pagal_paz(studentai_list, zem_lyg_list, aukst_lyg_list);
                } else {
                    skirstymas_pagal_paz(studentai_vec, zem_lyg_vec, aukst_lyg_vec);
                }
            }
        } else if(strat == 1) {
            if(iskyrimas == 1) {
                if (data == 1) {
                    skirstymas_pagal_paz_2_strat(studentai_list, zem_lyg_list);
                } else {
                    skirstymas_pagal_paz_2_strat(studentai_vec, zem_lyg_vec);
                }
            }
        }
        cout << "Ar įrašyti į failą?\n" ;
        cout << "1 - Taip\n";
        cout << "0 - Ne\n" ;
        int i_faila;
        cin >> i_faila;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (data == 1) {
            handle_output(i_faila, iskyrimas, strat, studentai_list, zem_lyg_list, aukst_lyg_list);
        } 
        else {
            handle_output(i_faila, iskyrimas, strat, studentai_vec, zem_lyg_vec, aukst_lyg_vec);
        }

   return 0;
}
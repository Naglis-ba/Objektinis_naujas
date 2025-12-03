#pragma once
#include "studentasClass.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <type_traits>
#include <list>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <chrono>


using namespace std;

void Sort(std::vector<int>& arr);
double skaiciuotiVidurki(const std::vector<int>& paz);
double skaiciuotiMediana(std::vector<int> paz);
void SkaiciuotiGalutinius(Studentas& stud);
void generuotiAtsitiktinai(Studentas& stud);
void IvestiPazymius(Studentas& stud);


template <typename Container>
void RikiuotiStudentus_paz(Container& studentai) {
    auto start = std::chrono::high_resolution_clock::now();
    if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
        studentai.sort([](const Studentas& a, const Studentas& b) {
            return a.GalVid() > b.GalVid();
        });
    } else {
        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.GalVid() > b.GalVid();
        });
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Rikiavimas uztruko: " << diff.count() << " s\n";
}
template <typename Container>
void RikiuotiStudentus_vardas(Container& studentai) {
    auto start = std::chrono::high_resolution_clock::now();
    auto comparator = [](const Studentas& a, const Studentas& b) {
        size_t len_a = a.Vardas().length();
        size_t len_b = b.Vardas().length();

        if (len_a != len_b) {
            return len_a < len_b;
        }

        return a.Vardas() < b.Vardas();
    };

    if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
        studentai.sort(comparator);
    } else {
        std::sort(studentai.begin(), studentai.end(), comparator);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Rikiavimas uztruko: " << diff.count() << " s\n";
}
template <typename Container>
void nuskaitytiIsFailo(Container& studentai, const string& failoVardas) {
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream in(failoVardas);
    if (!in) {
        cout << "Nepavyko atidaryti failo: " << failoVardas << endl;
        return;
    }
    string eilute;
    std::getline(in, eilute);
   
    while (std::getline(in, eilute)) {
        std::istringstream iss(eilute);
        std::string vardas, pavarde;
        vector<int> paz;
        int x;
        iss >> vardas >> pavarde;
        while (iss >> x) paz.push_back(x);
        if (paz.empty()) continue;
        int egz = paz.back();
        paz.pop_back();
        Studentas stud(vardas, pavarde);
        stud.SetEgz(egz);
        for (int g : paz) stud.AddGrade(g);
        
        SkaiciuotiGalutinius(stud);
        studentai.push_back(std::move(stud));
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Nuskaitymas uztruko: " << diff.count() << " s\n";
};
template <typename Container>
void Outas_i_faila(const Container& studentai){
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream out("rez.txt");

    out << setw(20) << left << "Vardas"
         << setw(20) << left << "Pavarde"
         << setw(25) << left << "Galutinis (Vid.)"
         << setw(25) << left << "Galutinis (Med.)";
    out << "\n";
    out << string(90, '-') << "\n";
    for (const auto& stud : studentai) {
        out << setw(20) << left << stud.Vardas()
             << setw(20) << left << stud.Pavarde()
             << setw(25) << left << std::fixed << std::setprecision(2) << stud.GalVid()
             << setw(25) << left << std::fixed << std::setprecision(2) << stud.GalMed() << "\n";
        out << string(90, '-') << "\n";
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Isvedimas uztruko: " << diff.count() << " s\n";
};
template <typename Container>
void Outas_i_console(const Container& studentai){
    auto start = std::chrono::high_resolution_clock::now();
    cout << setw(20) << left << "Vardas"
         << setw(20) << left << "Pavarde"
         << setw(25) << left << "Galutinis (Vid.)"
         << setw(25) << left << "Galutinis (Med.)" << "\n";
    cout << string(90, '-') << "\n";

    for (const auto& stud : studentai) {
        cout << setw(20) << left << stud.Vardas()
             << setw(20) << left << stud.Pavarde()
             << setw(25) << left << std::fixed << std::setprecision(2) << stud.GalVid()
             << setw(25) << left << std::fixed << std::setprecision(2) << stud.GalMed() << "\n";
        cout << string(90, '-') << "\n";
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Isvedimas uztruko: " << diff.count() << " s\n";
};

template <typename Container>
void Outas_i_du_failus(const Container& zem_lyg, const Container& aukst_lyg,
                        const std::string& varg_file = "vargsiukai.txt",
                        const std::string& kiet_file = "kietiakai.txt"){
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream out_varg(varg_file);
    std::ofstream out_kiet(kiet_file);

    auto write_header = [](std::ofstream& out){
        out << setw(20) << left << "Vardas"
            << setw(20) << left << "Pavarde"
            << setw(25) << left << "Galutinis (Vid.)"
            << setw(25) << left << "Galutinis (Med.)" << "\n";
        out << string(90, '-') << "\n";
    };

    write_header(out_kiet);
    write_header(out_varg);

    for (const auto& stud : aukst_lyg) {
        out_kiet << setw(20) << left << stud.Vardas()
                 << setw(20) << left << stud.Pavarde()
                 << setw(25) << left << std::fixed << std::setprecision(2) << stud.GalVid()
                 << setw(25) << left << std::fixed << std::setprecision(2) << stud.GalMed() << "\n";
        out_kiet << string(90, '-') << "\n";
    }

    for (const auto& stud : zem_lyg) {
        out_varg << setw(20) << left << stud.Vardas()
                 << setw(20) << left << stud.Pavarde()
                 << setw(25) << left << std::fixed << std::setprecision(2) << stud.GalVid()
                 << setw(25) << left << std::fixed << std::setprecision(2) << stud.GalMed() << "\n";
        out_varg << string(90, '-') << "\n";
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Isvedimas uztruko: " << diff.count() << " s\n";
}

template <typename Container>
void Outas_i_du_failus_strat_2(const Container& zem_lyg, const Container& studentai,
                        const std::string& varg_file = "vargsiukai.txt",
                        const std::string& kiet_file = "kietiakai.txt"){
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream out_varg(varg_file);
    std::ofstream out_kiet(kiet_file);

    auto write_header = [](std::ofstream& out){
        out << setw(20) << left << "Vardas"
            << setw(20) << left << "Pavarde"
            << setw(25) << left << "Galutinis (Vid.)"
            << setw(25) << left << "Galutinis (Med.)" << "\n";
        out << string(90, '-') << "\n";
    };

    write_header(out_kiet);
    write_header(out_varg);

    for (const auto& stud : studentai) {
        out_kiet << setw(20) << left << stud.Vardas()
                 << setw(20) << left << stud.Pavarde()
                 << setw(25) << left << std::fixed << std::setprecision(2) << stud.GalVid()
                 << setw(25) << left << std::fixed << std::setprecision(2) << stud.GalMed() << "\n";
        out_kiet << string(90, '-') << "\n";
    }

    for (const auto& stud : zem_lyg) {
        out_varg << setw(20) << left << stud.Vardas()
                 << setw(20) << left << stud.Pavarde()
                 << setw(25) << left << std::fixed << std::setprecision(2) << stud.GalVid()
                 << setw(25) << left << std::fixed << std::setprecision(2) << stud.GalMed() << "\n";
        out_varg << string(90, '-') << "\n";
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Isvedimas uztruko: " << diff.count() << " s\n";
}


template <typename Container>
void skirstymas_pagal_paz(Container studentai, Container &zem_lyg, Container &aukst_lyg){
    auto start = std::chrono::high_resolution_clock::now();
    for (auto& stud : studentai) {
        if (stud.GalVid() >= 5.0) {
           aukst_lyg.push_back(std::move(stud));
        } else {
           zem_lyg.push_back(std::move(stud));
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Studentai surušiuoti per: " << diff.count() << " s\n";
}

template <typename Container>
void skirstymas_pagal_paz_2_strat(Container &studentai, Container &zem_lyg){
    auto start = std::chrono::high_resolution_clock::now();
    for (auto it = studentai.begin(); it != studentai.end(); ) {
        if (it->GalVid() <= 5.0) {
            zem_lyg.push_back(std::move(*it));
            it = studentai.erase(it);
        } else {
            ++it;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Studentai surušiuoti per: " << diff.count() << " s\n";
}

template <typename Container>
void Rikiavimas_output(int sort_type, Container& studentai){

        if (sort_type == 0){

                RikiuotiStudentus_vardas(studentai);

        }
        else if(sort_type == 1){

            RikiuotiStudentus_paz(studentai);

          
        }
}

template <typename Container>
void handle_output(int i_faila, int iskyrimas, int strat,
                   const Container& main_container,
                   const Container& zem_container,
                   const Container& aukst_container) {
    if (i_faila == 1) {  // rasyti į failą
        if (iskyrimas == 0) { // Neatskirta
            Outas_i_faila(main_container); // Outinam visus studentus
        } else if (strat == 0) {
            Outas_i_du_failus(zem_container, aukst_container); // pirma strategija
        } else if (strat == 1) {
            Outas_i_du_failus(zem_container, main_container);  // antra strategija
        }
    } else {  // nerasyti į failą, rodyti konsolėje
        if (iskyrimas == 0) { // Neatskirta
            Outas_i_console(main_container);
        } else if (strat == 0) { //pirma strategija
            cout << "\nNeišlaikę studentai:\n";
            Outas_i_console(zem_container);
            cout << "\nIšlaikę studentai:\n";
            Outas_i_console(aukst_container);
        } else if (strat == 1) { //antra strategija
            cout << "\nNeišlaikę studentai (Strategy 1):\n";
            Outas_i_console(zem_container);
            Outas_i_console(main_container); 
        }
    }
}
#include "studentasClass.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::string;
using std::vector;


Studentas::~Studentas() {
    paz_.clear();
}

Studentas::Studentas(){
    int sum=0, n, m;
    cout << "Iveskite studento varda: "; cin >> vardas_;
    cout << "Iveskite studento pavarde: "; cin >> pavarde_;
    cout << "Kiek namu darbu pazymiu? "; cin >> n;
    std::cout << "Ar generuoti pazymius atsitiktinai? (1 - Taip, 0 - Ne): ";
    int gen;
    std::cin >> gen;
    
    string paz_str;
    int laik_paz;
    int tusciu_eiluciu = 0;
    
    switch (gen) {
        case 1:
            for (int i = 0; i < n; i++) {
                paz_.push_back(rand() % 10 + 1);
            }
            egz_ = rand() % 10 + 1;
            galVid_ = egz_ * 0.6 + (std::accumulate(paz_.begin(), paz_.end(), 0.0) / paz_.size()) * 0.4;
            galMed_ = skaiciuotiMediana() * 0.4 + egz_ * 0.6;
            break;
        case 0:
            cout << "Iveskite namu darbu pazymius (du ENTER is eiles baigia ivedima):\n";
            paz_.clear();
            while (true) {
                std::getline(cin, paz_str);
                if (paz_str.empty()) {
                    tusciu_eiluciu++;
                    if (tusciu_eiluciu == 2) break;
                    continue;
                }
                tusciu_eiluciu = 0;
                try {
                    laik_paz = stoi(paz_str);
                    paz_.push_back(laik_paz);
                } catch (...) { cout << "Iveskite skaiciu arba ENTER.\n"; }
            }
            std::cout << "Egzamino ivertinimas: ";
            std::cin >> egz_;
            // Calculate final grades
            SkaiciuotiGalutinius();
            break;
        default:
            std::cout << "Neteisinga ivestis." << std::endl;
            break;
    }
}

Studentas::Studentas(std::istream& in){
    in >> vardas_ >> pavarde_;
    std::vector<int> laik_paz;
    int x;
    while (in >> x) laik_paz.push_back(x);
    if (laik_paz.empty()) return;
    egz_ = laik_paz.back();
    laik_paz.pop_back();
    paz_ = move(laik_paz);
    SkaiciuotiGalutinius();
}

std::vector<Studentas> Studentas::ReadFromFile(const std::string& failo_vardas){
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Studentas> studentai;
    std::ifstream in(failo_vardas);
    if (!in) {
        cout << "Nepavyko atidaryti failo: " << failo_vardas << "\n";
        return studentai;
    }
    string eilute;
    std::getline(in, eilute);
   
    while (std::getline(in, eilute)) {
        std::istringstream iss(eilute);
        Studentas stud(iss);
        studentai.push_back(std::move(stud));
    }
    in.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Nuskaitymas uztruko: " << diff.count() << " s\n";
    return studentai;
}
Studentas::Studentas(const Studentas& other):
      vardas_(other.vardas_), 
      pavarde_(other.pavarde_), 
      paz_(other.paz_),  // Vector copied here
      egz_(other.egz_), 
      galVid_(other.galVid_), 
      galMed_(other.galMed_) {
    std::cout << "Copy constructor called for: " << vardas_ << " " << pavarde_ << "\n";
}

Studentas& Studentas::operator=(const Studentas& other) {
    if (this == &other) {
        return *this;
    }
    
    vardas_ = other.vardas_;
    pavarde_ = other.pavarde_;
    paz_ = other.paz_;  
    egz_ = other.egz_;
    galVid_ = other.galVid_;
    galMed_ = other.galMed_;
    
    std::cout << "Copy assignment operator called for: " << vardas_ << " " << pavarde_ << "\n";
    
    return *this;
}

void Studentas::SkaiciuotiGalutinius() {
    double vid = skaiciuotiVidurki();
    galVid_ = 0.4 * vid + 0.6 * egz_;
    double med = skaiciuotiMediana();
    galMed_ = 0.4 * med + 0.6 * egz_;
}

double Studentas::skaiciuotiVidurki() {
    if (paz_.empty()) return 0.0;
    int suma = 0;
    for (int x : paz_) suma += x;
    double avg = static_cast<double>(suma) / paz_.size();
    return avg;
}

double Studentas::skaiciuotiMediana() {
    if (paz_.empty()) return 0.0;
    stable_sort(paz_.begin(), paz_.end());
    size_t n = paz_.size();
    if (n % 2 == 0)
        return (paz_[n/2 - 1] + paz_[n/2]) / 2.0;
    else
        return paz_[n/2];
}
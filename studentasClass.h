#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> paz_;
    int egz_;
    double galVid_;
    double galMed_;
    
    // Private helper methods
    double skaiciuotiVidurki();
    double skaiciuotiMediana();

public:
    // Constructors
    Studentas();  // Default constructor
    Studentas(const std::string& vardas, const std::string& pavarde);
    Studentas(std::istream& in);
    ~Studentas(); // Destructor

    // Getters
    inline std::string Vardas() const { return vardas_; }
    inline std::string Pavarde() const { return pavarde_; }
    inline std::vector<int> Paz() const { return paz_; }
    inline int Egz() const { return egz_; }
    inline double GalVid() const { return galVid_; }
    inline double GalMed() const { return galMed_; }

    // Setters
    void SetVardas(const std::string& vardas) { vardas_ = vardas; }
    void SetPavarde(const std::string& pavarde) { pavarde_ = pavarde; }
    void SetEgz(int egz) { egz_ = egz; }
    void SetGalVid(double vid) { galVid_ = vid; }
    void SetGalMed(double med) { galMed_ = med; }
    

    // Methods for grades
    void AddGrade(int grade) { paz_.push_back(grade); }
    void ClearGrades() { paz_.clear(); }

    // Utility methods
    void SkaiciuotiGalutinius();  // Calculate final grade and median
    void IvestiPazymius();  // Input grades manually
    void GeneruotiAtsitiktinai();  // Generate random grades
    void PrintInfo() const;  // Print student info

    // Static factory method for reading from file
    static std::vector<Studentas> ReadFromFile(const std::string& filename);

    // Comparison operators (for sorting)
    bool operator>(const Studentas& other) const { return galVid_ > other.galVid_; }
    bool operator<(const Studentas& other) const { return galVid_ < other.galVid_; }
    bool operator==(const Studentas& other) const { 
        return vardas_ == other.vardas_ && pavarde_ == other.pavarde_; 
    }
};
/**
 * @file zmogus.h
 * @author Naglis
 * @brief Abstrakti Zmogus klasė, iš kurios paveldima Studentas klasė
 * @version 0.1
 * @date 2025-12-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include <string>
#include <iostream>

class Zmogus {
protected: 
    std::string vardas_;
    std::string pavarde_;

public:
    
    Zmogus(const std::string& vardas = "", const std::string& pavarde = "")
        : vardas_(vardas), pavarde_(pavarde) {}
    
    virtual ~Zmogus() = default;
    

    virtual void PrintInfo() const = 0;
    
    // Getters
    virtual std::string GetVardas() const { return vardas_; }
    virtual std::string GetPavarde() const { return pavarde_; }
    
    // Setters
    virtual void SetVardas(const std::string& vardas) { vardas_ = vardas; }
    virtual void SetPavarde(const std::string& pavarde) { pavarde_ = pavarde; }
};
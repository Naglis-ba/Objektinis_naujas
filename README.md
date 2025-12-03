# Objektinis


## Paleidimo Instrukcija

WSL:Ubuntu
    (Būnant programos direktorijoje)
    cmake CMakeLists.txt
    cmake --install .
    cmake --build .
    ./Objektinis_v1.0


    Sekti instrukcijas
    Standartinis failo vardas: studentai.txt



## Programa
    Programa skirta skaičiuoti mokinių pažymių vidurkius ir gauti rezultatus pasirinktu formatu.
    Programoje yra galimybė įvesti mokinį ir jo rezultatus, sugeneruoti mokinio balus, taip pat skaityti mokinių sąrašą iš failo.




## v0.3

Tikslas:
    0.3 versija skirta palyginti C++ kalbos duomenų struktūrų list ir vector spartą apdorojant didelius kiekius duomenų.

Sistemos specifikacijos:
    Procesorius: AMD Ryzen 7 7435HS, 3100 Mhz, 8 branduoliai, 16 loginių procesorių
    RAM: 16GB
    Diskas: SSD

Testavimas:

    Pateikti laikai vidutiniai per kelis testavimus

    Studentų skaičius: 1000

        Vector<Studentai>:
        Failų nuskaitymas: 0.00429844s
        Rikiavimas pagal pažymius: 0.00115516s
        Rikiavimas pagal vardą: 0.000773873s
        Studentų rūšiavimas: 0.000539068s
        Duomenų įrašymas į failus: 0.00276976s
        Pilnas veikimo laikas: 0.00953630s

        List<Studentai>:
        Failų nuskaitymas: 0.00441098s
        Rikiavimas pagal pažymius: 0.000396083s
        Rikiavimas pagal vardą: 0.000334981s
        Studentų rūšiavimas: 0.000519063s
        Duomenų įrašymas į failus: 0.00283785s
        Pilnas veikimo laikas: 0.00849896s

    Su 1000 studentų List turi spartesnį rikiavimą, kitose kategorijose skirtumai nežymūs.

    Studentų skaičius: 10000

        Vector<Studentai>:
        Failų nuskaitymas: 0.0801375s
        Rikiavimas pagal pažymius: 0.0162182s
        Rikiavimas pagal vardą: 0.00984555s
        Studentų rūšiavimas: 0.00624465s
        Duomenų įrašymas į failus: 0.0224558s
        Pilnas veikimo laikas: 0.1349017s

        List<Studentai>:
        Failų nuskaitymas: 0.074241s
        Rikiavimas pagal pažymius: 0.00616155s
        Rikiavimas pagal vardą: 0.00399334s
        Studentų rūšiavimas: 0.00442617s
        Duomenų įrašymas į failus: 0.0252468s
        Pilnas veikimo laikas: 0.1140689s

    List duomenų struktūra pasižymi greitesniu rikiavimu pagal pažymius ir vardą

    Studentų skaičius: 100000

        Vector<Studentai>:
        Failų nuskaitymas: 1.09426s
        Rikiavimas pagal pažymius: 0.197106s
        Rikiavimas pagal vardą: 0.105873s
        Studentų rūšiavimas: 0.0586521s
        Duomenų įrašymas į failus: 0.203254s
        Pilnas veikimo laikas: 1.6591451s

        List<Studentai>:
        Failų nuskaitymas:  0.973157s
        Rikiavimas pagal pažymius: 0.113715s
        Rikiavimas pagal vardą: 0.0549911s
        Studentų rūšiavimas: 0.0483787s
        Duomenų įrašymas į failus: 0.18008s
        Pilnas veikimo laikas: 1.3703218s

    Rikiavimas list greitesnis, kiti parametrai panašūs

    Studentų skaičius: 1000000 (milijonas)

        Vector<Studentai>:
        Failų nuskaitymas: 5.00494s
        Rikiavimas pagal pažymius: 2.82426s
        Rikiavimas pagal vardą: 1.27244s
        Studentų rūšiavimas: 0.749614s
        Duomenų įrašymas į failus: 2.12965s
        Pilnas veikimo laikas: 11.980904s

        List<Studentai>:
        Failų nuskaitymas: 4.85795s
        Rikiavimas pagal pažymius: 1.4554s
        Rikiavimas pagal vardą: 0.571668s
        Studentų rūšiavimas: 0.646082s
        Duomenų įrašymas į failus: 2.12742s
        Pilnas veikimo laikas: 9.65852s

    Rikiavimas list greitesnis, kiti parametrai panašūs, list nežymiai greitesnis

    Studentų skaičius: 10000000 (10 milijonų)

        Vector<Studentai>:
        Failų nuskaitymas: 50.1437s
        Rikiavimas pagal pažymius: 33.7627s
        Rikiavimas pagal vardą: 14.7195s
        Studentų rūšiavimas: 10.79s
        Duomenų įrašymas į failus: 21.3615s
        Pilnas veikimo laikas: 130.7774s

        List<Studentai>:
        Failų nuskaitymas: 46.8239s
        Rikiavimas pagal pažymius: 19.3993s
        Rikiavimas pagal vardą: 6.56693s
        Studentų rūšiavimas: 6.76617s
        Duomenų įrašymas į failus: 18.0148s
        Pilnas veikimo laikas: 97.5711s


Rezultatai:
Iš testavimo galima matyti, kad list struktūra atlieka operacijas kaip rikiavimas ir rūšiavimas sparčiau negu vector struktūra. Kiti parametrai, kaip failų nuskaitymas ir išvedimas į failus, nežymiai spartesni su list struktūra, skirtumas išryškėja didėjant duomenų kiekiui



## v1.0 :

Visi testai daryti su 100000 įrašų.

1 Strategija:
Iš v0.3 tyrimo matome, kad List konteineris veikia sparčiau negu Vector konteineris

Rušiavimas su List: 0.0434585 s 0.0409563 s 
Rušiavimas su Vector: 0.0520665 s

2 Strategija:

Rikiuojant pagal paz:
Rušiavimas su List: 0.0255668 s 0.0238579 s
Rušiavimas su Vector: 98.6134 s 

1 ir 2 strategijose Vector konteineris veikia daug lėčiau negu List, kadangi Vector ištrynimo O(n),
o List O(1). Antra strategija naudojant List greičiausia


3 Strategija:
    Implementuota atskiros funkcijos vector is list konteinerių tipams.
        Vector:
            konteinerio atveju, kviečiama funkcija skirstymas_pagal_paz_vector, kuri veikia stable_partition() algoritmo pagalba, kuris suskirsto visus studentus turinčius <5 vidurkį į pradžią vektoriaus ir paima ribą iki kurios vietos perkelti į kitus vektorius.
        Rūšiavimo laikas: 0.108211 s


        List:
            konteinerio atveju, kviečiama funkcija skirstymas_pagal_paz_list, kuri ištrina studentus su <5 vidurkiu iš studentai list ir perkelia juos į kitą  list zem_lyg
        Rūšiavimo laikas: 0.025946 s

## v1.1 :

Struct versija:
    100000 Studentų :
        Failų nuskaitymas: 0.860554 s
        Rikiavimas pagal pažymius:  0.22768 s
        Studentų rūšiavimas: 0.0929735s
        Duomenų įrašymas į failus: 0.175444 s

    1000000 Studentų :
        Failų nuskaitymas:          0.86055 s || -O1  1.45609 s  || -O2 1.40518 s  || -O3 1.40568 s
        Rikiavimas pagal pažymius:  0.22768 s || -O1  0.31687 s  || -O2 0.308264 s || -O3 0.266457 s
        Studentų rūšiavimas:        0.09297 s || -O1  0.49551 s  || -O2 0.503482 s || -O3 0.508501 s
        Duomenų įrašymas į failus:  0.17544 s || -O1  1.47687 s  || -O2 1.57545 s  || -O3 1.47876 s

Class versija:
    100000 Studentų :
        Failų nuskaitymas: 3.98689 s
        Rikiavimas pagal pažymius: 2.64623 s
        Studentų rūšiavimas:  1.16904 s
        Duomenų įrašymas į failus: 2.01999 s

    1000000 Studentų :
        Failų nuskaitymas:          3.94216 s || -O1  1.6346 s   || -O2 1.54307 s  || -O3 1.42303 s
        Rikiavimas pagal pažymius:  3.83705 s || -O1  0.772583 s || -O2 0.726094 s || -O3 0.699226 s
        Studentų rūšiavimas:        0.95569 s || -O1  0.555033 s || -O2 0.588292 s || -O3 0.526771 s
        Duomenų įrašymas į failus:  2.02929 s || -O1  1.54024 s  || -O2 1.53029 s  || -O3 1.49763 s

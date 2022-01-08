/**
 * Project Untitled
 */

#include <iostream>
#include "Menedzer.h"
#ifndef _PRACOWNIK_H
#define _PRACOWNIK_H

class Pracownik {
private: 
    std::string Imie;
    std::string Nazwisko;
    std::string Numer_telefonu;
    std::string E_mail;
    std::string Data_zatrudnienia;
    std::string haslo;
public:
    Pracownik();

    Pracownik(std::string Imie,std::string Nazwisko, std::string Numer_telefonu,std::string E_mail,std::string Data_zatrudnienia,std::string haslo){
        this->Imie = Imie;
        this->Nazwisko = Nazwisko;
        this->Numer_telefonu = Numer_telefonu;
        this->E_mail = E_mail;
        this->Data_zatrudnienia = Data_zatrudnienia;
        this->haslo = haslo;
    }
    int zaloguj(std::string email,std::string haslo){
        if(email == this->E_mail && haslo == this->haslo){
            return 0;
        }
        else return -1;
    }
    void Realizowanie_zamowienia() {
        
    }

    void Zloz_zamowienie_do_hurtowni() {

    }
};
#endif //_PRACOWNIK_H
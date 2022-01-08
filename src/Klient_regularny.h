/**
 * Project Untitled
 */


#ifndef _KLIENT_REGULARNY_H
#define _KLIENT_REGULARNY_H

#include "Klient.h"


class Klient_regularny: public Klient {
private:
    std::string E_mail;
    std::string Haslo;
    std::string Data_Rejestracji;
public: 
    Klient_regularny(std::string email,std::string haslo,std::string datar){
        std::cout<<"hello "<<email<<" "<<haslo<<" "<<datar<<"\n";
        E_mail = email;
        Haslo = haslo;
        Data_Rejestracji = datar;
    }
    int Zaloguj(std::string email,std::string haslo) {
        if(email == E_mail && haslo == Haslo){
            std::cout<<"Zalogowano\n";
            return 0;
        }
        return -1;
    }

    /*void Zarejestruj(std::string email,std::string haslo,std::string datar) {
        std::cout<<"hello "<<email<<" "<<haslo<<" "<<datar<<"\n";
        E_mail = email;
        Haslo = haslo;
        Data_Rejestracji = datar;
        std::cout<<"hello "<<email<<" "<<haslo<<" "<<datar<<"\n";
    }*/

    void Usun(std::string email,std::string haslo) {

    }

    void Modyfikuj() {

    }

    void Wyslij_mail() {

    }
/*
Klient_regularny(std::string email,std::string haslo,std::string datar);

int Zaloguj(std::string email,std::string haslo);
    
void Zarejestruj(std::string email,std::string haslo,std::string datar);
    
void Usun(std::string email,std::string haslo);
    
void Modyfikuj();
    
void Wyslij_mail();
*/
};

#endif //_KLIENT_REGULARNY_H
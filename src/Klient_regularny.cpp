/**
 * Project Untitled
 */


#include "Klient_regularny.h"

/**
 * Klient_regularny implementation
 */

/**
Klient_regularny::Klient_regularny(std::string email,std::string haslo,std::string datar){
    E_mail = email;
    Haslo = haslo;
    Data_Rejestracji = datar;
}
int Klient_regularny::Zaloguj(std::string email,std::string haslo) {
    if(email == E_mail && haslo == Haslo){
        std::cout<<"Zalogowano\n";
        return 0;
    }
    return -1;
}

void Klient_regularny::Zarejestruj(std::string email,std::string haslo,std::string datar) {
    E_mail = email;
    Haslo = haslo;
    Data_Rejestracji = datar;
}

void Klient_regularny::Usun(std::string email,std::string haslo) {

}

void Klient_regularny::Modyfikuj() {

}

void Klient_regularny::Wyslij_mail() {

}*/
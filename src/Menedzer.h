/**
 * Project Untitled
 */
#ifndef _MENEDZER_H
#define _MENEDZER_H

#include "Pracownik.h"

class Menedzer: public Pracownik {
private:
public: 
    Menedzer(){
    }
    void Odbierz_zamowienie_z_hurtowni() {
        std::cout<<"Odebrano";
    }
};
#endif //_MENEDŻER_H
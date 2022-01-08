/**
 * Project Untitled
 */

#include <iostream>
#include <vector>
#include "Zamowienia.h"
#ifndef _KLIENT_H
#define _KLIENT_H

class Klient {
private:
	std::string Imie;
	std::string Nazwisko;
	std::string Numer_telefonu;
	std::string zamowienie;
	std::vector<Zamowienia*> zamowienia;
public: 

	Klient(std::string im, std::string nazw, std::string nr){
		Klient::Imie = im;
		Klient::Nazwisko = nazw;
		Klient::Numer_telefonu = nr;
	}
	
	Klient(){}
	
	void Dodaj_zamowienie(std::string typ, std::string ilosc) {
		zamowienia.push_back(new Zamowienia(typ,ilosc));
	}
	void Dodaj_zamowienie(std::string typ, std::string ilosc, bool reg) {
		zamowienia.push_back(new Zamowienia(typ,ilosc,reg));
	}
	
	void Anuluj_zamowienie() {
		std::cout<<"Twoje zamowienia\n";
		for(int i = 0; i < (int)this->zamowienia.size();i++){
			std::cout<<"Zamowienie nr ["<<i<<"] - "<<this->zamowienia[i]->wypiszZam()<<"\n";
		}
		std::cout<<"Podaj nr. zamowienia\n";
		int nr;
		std::cin>>nr;
		if(nr < (int)zamowienia.size()){
			std::cout<<"Zamowienie "<<this->zamowienia[nr]->wypiszZam()<<" zostalo usuniete\n";
			
			this->zamowienia.erase(this->zamowienia.begin()+nr);
			std::cout<<"Zamowienia usuniete\n";
		}
	}
	void wyswietl_zamowienie() {
		std::cout<<"Twoje zamowienia\n";
		for(int i = 0; i < (int)this->zamowienia.size();i++){
			std::cout<<"Zamowienie nr ["<<i<<"] - "<<this->zamowienia[i]->wypiszZam()<<"  -  "<<this->zamowienia[i]->wypiszZam(true)<<"zl"<<" \n";
		}
	}
	bool weryfikuj(std::string im, std::string nazw, std::string nr){
		if(Klient::Imie == im && Klient::Nazwisko == nazw && Klient::Numer_telefonu == nr)
			return true;
		else return false;
	}
};

#endif //_KLIENT_H
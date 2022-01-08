/**
 * Project Untitled
 */

#include <iostream>
#include <string>
#include "Pracownik.h"
#ifndef _ZAMOWIENIA_H
#define _ZAMOWIENIA_H

class Zamowienia {
private:
	std::string Data_zlozenia_zamowienia;
	std::string Typ_zamomwienia;
	double Kwota;
	std::string Metoda_platnosci;
	std::string Rodzaj;
	int Ilosc;
	std::string Data_odbioru;
	std::string czas_wykonania;
	bool dowoz;
public: 
	Zamowienia(std::string typ, std::string ile){
		int tmp = std::stoi(ile);
		this->Typ_zamomwienia = typ;
		this->Ilosc = tmp;
		std::cout<<"Wybierz metode platnosci [1] - Gotowka  [2] - Karta\n";
		int odr;
		std::cin>>odr;
		if(odr == 2){
			this->Rodzaj += "Platnosc karta";
		}
		else
			this->Rodzaj += "Platnosc gotowka";
		
		std::cout<<"Info: "<<this->Rodzaj<<"\n";

		this->Kwota = 10;
	}
	Zamowienia(std::string typ, std::string ile, bool reg){
		int tmp = std::stoi(ile);
		this->Typ_zamomwienia = typ;
		this->Ilosc = tmp;

		std::cout<<"Wybierz metode platnosci [1] - Gotowka  [2] - Karta\n";
		int odr;
		std::cin>>odr;
		if(odr == 2){
			this->Rodzaj += "Platnosc karta";
		}
		else
			this->Rodzaj += "Platnosc gotowka";

		std::cout<<"czy płatność ma zostać odroczona? [1]-tak  [2]-nie\n";
		std::cin>>odr;
		if(odr == 1){
			this->Rodzaj += " Odroczona";
		}
		std::cout<<"Info: "<<this->Rodzaj<<"\n";

		this->Kwota = 10;
	}
/*
	void wyslij_dowozem(){
		if(this->dowoz){

		}
	}
		*/
	std::string wypiszZam(){
		return this->Typ_zamomwienia;
	}
	double wypiszZam(bool i){
		return this->Kwota;
	}

	void wyslij_potwierdzenie(){}
};

#endif //_ZAMOWIENIA_H
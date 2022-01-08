#include <iostream>
#include <vector>
#include "Klient_regularny.h"

int main(){
	int usernum = -1;
	int user = -1;
	std::vector<Klient*> klienci;
	std::vector<Klient_regularny*> kliencireg;
	std::vector<Pracownik*> pracownicy;
	//std::vector<Menedzer*> menedzerowie;
	int pracownik;

	pracownicy.push_back(new Pracownik("Jan","Kowalski","123543212","janjan@kowal.com","02.04.2020","haslo"));
	pracownicy.push_back(new Pracownik("Piotr","Piotrowski","235133763","pootrek@kowal.com","03.04.2020","haslo"));
	pracownicy.push_back(new Pracownik("Kinga","Dziobak","231643877","dziy@kowal.com","01,04,2020","haslo"));

	//menedzerowie.push_back(new Menedzer());

	std::cout<<"czy jesteś pracownikiem? [1]-Tak [2]-nie\n";
	std::cin>>pracownik;

	int userInputflag = 1;
	while(userInputflag != 0){
		while(pracownik == 2 && usernum == -1){
			std::cout<<"[1] - Zaloguj sie\n";
			std::cout<<"[2] - Zarejestruj sie\n";
			std::cout<<"[3] - Jestem pracownikiem\n";
			std::cout<<"[4] - Zloz zamowienie\n";
			std::cout<<"[5] - Anuluj zamowienie\n";
			std::cout<<"[0] - wyjdz\n";
			std::cin>>userInputflag;
			std::cout<<"wybrales "<<userInputflag<<std::endl;
			std::string login;
			std::string haslo;
			std::string nr;
			if(userInputflag == 0)
				break;
			if(userInputflag == 3){
				pracownik = 1;
			}
			if(userInputflag == 1){
				std::cout<<"Login\n";
				std::cin>>login;
				std::cout<<"Haslo\n";
				std::cin>>haslo;
				for(int kl = 0; kl < (int)kliencireg.size(); kl++){
					if(kliencireg[kl]->Zaloguj(login,haslo) == 0){
						std::cout<<"Zostałeś zalogowany\n";
						usernum = kl;
					}
				}
			}
			else if(userInputflag == 2){
				std::cout<<"Wpisz email\n";
				std::cin>>login;
				std::cout<<"Wpisz haslo\n";
				std::cin>>haslo;
				bool ex=false;
				for(int kl = 0; kl < (int)kliencireg.size(); kl++){
					if(kliencireg[kl]->Zaloguj(login,haslo) == 0){
						std::cout<<"taki użytkownik istnieje\n";
						ex = true;
					}
				}
				if(!ex){
					kliencireg.push_back(new Klient_regularny(login,haslo,"08.01.2022"));
					std::cout<<"Dodalo\n";
				}
			}
			else if(userInputflag == 4){
				std::cout<<"Wpisz swoje imie\n";
				std::cin>>login;
				std::cout<<"Wpisz swoje nazwisko\n";
				std::cin>>haslo;
				std::cout<<"Wpisz swoj numer telefonu\n";
				std::cin>>nr;
				for(int kl = 0; kl < (int)klienci.size(); kl++){
					if(klienci[kl]->weryfikuj(login,haslo,nr)){
						user = kl;
					}
				}
				if(user == -1){
					klienci.push_back(new Klient(login,haslo,nr));
					user = klienci.size()-1;
				}
				std::cout<<"Co chcesz zamowic?\n";
				std::cin>>nr;
				std::cout<<"podaj ilosc\n";
				std::cin>>login;

				klienci[user]->Dodaj_zamowienie(nr,login);
				user = -1;
			}
			else if(userInputflag == 5){
				std::cout<<"Wpisz swoje imie\n";
				std::cin>>login;
				std::cout<<"Wpisz swoje nazwisko\n";
				std::cin>>haslo;
				std::cout<<"Wpisz swoj numer telefonu\n";
				std::cin>>nr;

				for(int kl = 0; kl < (int)klienci.size(); kl++){
					if(klienci[kl]->weryfikuj(login,haslo,nr)){
						user = kl;
					}
				}
				if(user > -1)
					klienci[user]->Anuluj_zamowienie();
				user = -1;
			}
		}

		while(pracownik == 1 && usernum == -1){
			std::cout<<"[1] - Zaloguj sie\n";
			std::cout<<"[2] - Jestem klientem\n";
			std::cout<<"[0] - wyjdz\n";
			std::cin>>userInputflag;
			std::cout<<"wybrales "<<userInputflag<<std::endl;
			std::string login;
			std::string haslo;
			if(userInputflag == 0)
				break;
			if(userInputflag == 2){
				pracownik = 2;
			}
			if(userInputflag == 1){
				std::cout<<"Login\n";
				std::cin>>login;
				std::cout<<"Haslo\n";
				std::cin>>haslo;
				for(int kl = 0; kl < (int)pracownicy.size(); kl++){
					if(pracownicy[kl]->zaloguj(login,haslo) == 0){
						std::cout<<"Zostałeś zalogowany\n";
						usernum = kl;
					}
				}
			}
		}
		while(pracownik == 2 && usernum != -1){
			std::cout<<"[1] - Wyloguj sie\n";
			std::cout<<"[2] - Zloz zamowienie\n";
			std::cout<<"[3] - Anuluj zamowienie\n";
			std::cout<<"[4] - Wyswietl zamowienie\n";
			std::cout<<"[8] - Usuń konto\n";
			std::cout<<"[0] - wyjdz\n";
			std::cin>>userInputflag;
			std::cout<<"wybrales "<<userInputflag<<std::endl;
			if(userInputflag == 0)
				break;
			if(userInputflag == 1){
				usernum = -1;
			}
			if(userInputflag == 2){
				std::cout<<"Co chcesz zamowic?\n";
				std::string zam;
				std::cin>>zam;
				std::cout<<"podaj ilosc\n";
				std::string ilosc;
				std::cin>>ilosc;
				kliencireg[usernum]->Dodaj_zamowienie(zam,ilosc,true);
			}
			else if(userInputflag == 3){
				kliencireg[usernum]->Anuluj_zamowienie();
			}
			else if(userInputflag == 4){
				kliencireg[usernum]->wyswietl_zamowienie();
			}
			else if(userInputflag == 8){
				bool napewno = false;
				std::cout<<"Na pewno chcesz usunąć swoje konto? [1] - TAK, usuń,   [2] - Nie!!!\n";
				int a;
				std::cin>>a;
				if(a==1)
					napewno = true;
				if(napewno){
					kliencireg.erase(kliencireg.begin()+usernum);
					std::cout<<"Twoje konto zostało usunięte\n";
					usernum = -1;
				}
			}
		}
		while(pracownik == 1 && usernum != -1){
			std::cout<<"[1] - Wyloguj sie\n";
			std::cout<<"[2] - Sprawdz zamowienia\n";
			std::cout<<"[0] - wyjdz\n";
			std::cin>>userInputflag;
			std::cout<<"wybrales "<<userInputflag<<std::endl;
			if(userInputflag == 0)
				break;
			if(userInputflag == 1){
				usernum = -1;
			}
			if(userInputflag == 2){
				std::cout<<"Sprawdzam zamowienia\n";
			}
		}
	}

	exit(0); 
}
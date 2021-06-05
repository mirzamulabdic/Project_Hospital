#include "Odjel.h"
#include <iostream>
using std::cout;
using std::cin;
int Odjel::maxKreveta = 0;

Odjel::Odjel()
{
	Odjel::maxKreveta = 0;
	strcpy_s(this->naziv, "Novi odjel");
}

void Odjel::setNaziv()
{
	cout << "Unesite naziv odjela: ";
	cin.getline(this->naziv, 50);
}

void Odjel::setMaxKrevet()
{
	cout << "Unesite broj kreveta na odjelu: ";
	cin >> Odjel::maxKreveta;
	cin.ignore();
}

void Odjel::setKreveti()
{
	std::shared_ptr<Krevet> temp = std::make_shared<Krevet>();
	for (int i = 0; i < Odjel::maxKreveta; i++) {
		temp->postaviKrevet(i, slobodan);
		this->kreveti.push_back(*temp);
	}
}

char* Odjel::getNaziv()
{
	return this->naziv;
}

int Odjel::getMaxKrevet()
{
	return Odjel::maxKreveta;
}

std::vector<Krevet> Odjel::getKreveti()
{
	return this->kreveti;
}

void Odjel::postaviOdjel()
{
	this->setNaziv();
	this->setMaxKrevet();
	this->setKreveti();
}

void Odjel::smjestiPacijenta()
{
	bool smjesten = false;
	try {
		for (int i = 0; i < this->kreveti.size(); i++) {
			if (this->kreveti[i].getStatus() == slobodan && !smjesten) {
				this->kreveti[i].setStatus(zauzet);
				cout << "Pacijent je uspjesno smjesten.\n";
				smjesten = true;
			}
		}
		if (!smjesten) {
			throw "Svi kreveti zauzeti!\n";
		}
	}
	catch (const char* Greska) {
		cout << "[GRESKA] " << Greska << "\n"; 
	}
	catch (...) {
		cout << "[GRESKA] Nepoznata greska!\n";
	}
}

void Odjel::rezervisiKrevet()
{
	bool smjesten = false;
	try {
		for (int i = 0; i < this->kreveti.size(); i++) {
			if (this->kreveti[i].getStatus() == slobodan && !smjesten) {
				this->kreveti[i].setStatus(rezervisan);
				cout << "Krevet je uspjesno rezervisan.\n";
				smjesten = true;
			}
		}
		if (!smjesten) {
			throw "Svi kreveti zauzeti!\n";
		}
	}
	catch (const char* Greska) {
		cout << "[GRESKA] " << Greska << "\n";
	}
	catch (...) {
		cout << "[GRESKA] Nepoznata greska!\n";
	}
}

void Odjel::oslobodiKrevet(int n)
{
	try {
		if (n > Odjel::getMaxKrevet() || n < 1) {
			throw n;
		}
		else if (this->kreveti[n-1].getStatus() == slobodan) {
			throw "Taj krevet je vec slobodan!\n";
		}
		else if(this->kreveti[n-1].getStatus() == rezervisan){
			throw "Taj krevet je rezervisan";
		}
		else {
			this->kreveti[n-1].setStatus(slobodan);
			cout << "Krevet broj " << n << " je sada slobodan!\n";
		}
	}
	catch (int n) {
		cout << "[GRESKA] Ne postoji krevet sa brojem " << n << "!\n";
	}
	catch (const char* Greska) {
		cout << "[GRESKA] " << Greska << "\n";
	}
	catch (...) {
		cout << "[GRESKA] Nepoznata greska!\n";
	}
}

void Odjel::ispisKreveta()
{
	cout << "Odjel: " << this->getNaziv() << "\n";
	cout << "Broj\t\tStatus\n";
	cout << "kreveta\t\tkreveta\n";
	cout << "----------------------------------\n";
	for (int i = 0; i < this->kreveti.size(); i++) {
		cout << i + 1 << "\t\t";
		if (this->kreveti[i].getStatus() == slobodan) {
			cout << "Slobodan\n";
		}
		else if (this->kreveti[i].getStatus() == zauzet) {
			cout << "Zauzet\n";
		}
		else {
			cout << "Rezervisan\n";
		}
	}
}

Odjel::~Odjel()
{
}

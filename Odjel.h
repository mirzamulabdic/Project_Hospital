#pragma once
#include <vector>
#include "Krevet.h"
class Odjel
{
private:
	char naziv[50];
	static int maxKreveta;
	std::vector<Krevet> kreveti;
public:
	Odjel();
	void setNaziv();
	static void setMaxKrevet();
	void setKreveti();
	char* getNaziv();
	static int getMaxKrevet();
	std::vector<Krevet> getKreveti();
	void postaviOdjel();
	void smjestiPacijenta();
	void rezervisiKrevet();
	void oslobodiKrevet(int n);
	void ispisKreveta();
	~Odjel();
};


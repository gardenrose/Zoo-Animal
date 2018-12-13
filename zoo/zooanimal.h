#ifndef ZOOANIMAL_H
#define ZOOANIMAL_H
#include <iostream>
#include <string>
using namespace std;
class Masa
{
public:
	int godina;
	int tezina;
};
class ZooAnimal
{
public:
	
	// ZooAnimal(ZooAnimal& animal);
	ZooAnimal();
	ZooAnimal(int obrok);
	ZooAnimal(string vrsta, string ime, int godRodjenja, int brojKaveza, int brojDnevnihObroka, int ocekivaniZivotniVijek);
	void promjenaBrObroka(string unos);
	void dodajMasu(int kilogrami, int godina);
	void udebljala();
	void ispisi_zivotinju();
	static void povecajCounter();
	static void smanjiCounter();
	static void ispisCountera();
	friend int getCounter();
	friend bool operator==(const ZooAnimal& a, const ZooAnimal& b);
	ZooAnimal operator++();
	ZooAnimal operator--();
	friend ostream& operator<<(ostream& os, const ZooAnimal& a);
	ZooAnimal& operator=(const ZooAnimal& a);
	ZooAnimal operator--(int);
	ZooAnimal operator++(int);
	 // ~ZooAnimal();
	ZooAnimal(const ZooAnimal& an);
	  

private:
	static int counter;
	string vrsta;
	string ime;
	int godRodjenja;
	int brojKaveza;
	int brojDnevnihObroka;
	int ocekivaniZivotniVijek;
	Masa* masa;
};

#endif // ZOOANIMAL_H

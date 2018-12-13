#include <iostream>
#include <vector>
#include "zooanimal.h"
void promjena(vector<ZooAnimal>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i].udebljala();
	}
}
int getCounter()
{
	return ZooAnimal::counter;
	
}

int main()
{
	vector<ZooAnimal> animals;
	ZooAnimal prase("prase", "perica", 1991, 8, 3, 30);
	prase.dodajMasu(100, 1995);
	prase.dodajMasu(100, 1996);
	prase.dodajMasu(101, 1998);
	prase.dodajMasu(100, 2016);
	prase.dodajMasu(110, 2017);
	prase.dodajMasu(115, 2017);
	animals.push_back(prase);
	ZooAnimal::povecajCounter();
	ZooAnimal pas("pas", "amte", 1991, 5, 2, 20);
	pas.dodajMasu(40, 1999);
	pas.dodajMasu(45, 2016);
	pas.dodajMasu(60, 2017);
	animals.push_back(pas);
	ZooAnimal::povecajCounter();
	/*for (int i = 0; i < animals.size(); i++)
	{
		animals[i].ispisi_zivotinju();
	}
	promjena(animals);
	for (int i = 0; i < animals.size(); i++)
	{ 
		animals[i].ispisi_zivotinju();
	}*/
	ZooAnimal pas2;
	pas2 = pas;
	pas.ispisi_zivotinju();
	pas++;
	cout << pas;
	ZooAnimal::ispisCountera();
	return 0;

}


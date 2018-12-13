#include "zooanimal.h"
using namespace std;


/*void ZooAnimal::unosZivotinje()
{
string v,i;
int god,bk,bo,ozv;
cout<<"Ime: ";
cin>>i;
cout<<" Vrsta: ";
cin>>v;
cout<<" Godina rodjenja: ";
cin>>god;
cout<<" Broj kaveza: ";
cin>>bk;
cout<<" Broj dnevnih obroka: ";
cin>>bo;
cout<<" Ocekivani zivotni vijek: ";
cin>>ozv;

}*/
//int ZooAnimal::x = 0;
int ZooAnimal::counter = 0;
ZooAnimal::ZooAnimal()
{

}
ZooAnimal::ZooAnimal(int obrok)
{
	brojDnevnihObroka = obrok;
}
ZooAnimal::ZooAnimal(string v, string i, int god, int bk, int bo, int ozv)
{
	vrsta = v;
	ime = i;
	godRodjenja = god;
	brojKaveza = bk;
	brojDnevnihObroka = bo;
	ocekivaniZivotniVijek = ozv;
	masa = new Masa[ozv + ozv];
	for (int i = 0; i<ozv * 2; i++)
	{
		ZooAnimal::masa[i].godina = 0;
		ZooAnimal::masa[i].tezina = 0;

	}
	
}

ZooAnimal::ZooAnimal(const ZooAnimal& an)
{
	vrsta = an.vrsta;
	ime = an.ime;
	brojDnevnihObroka = an.brojDnevnihObroka;
	brojKaveza = an.brojKaveza;
	godRodjenja = an.godRodjenja;
	ocekivaniZivotniVijek = an.ocekivaniZivotniVijek;
	masa = new Masa[2 * ocekivaniZivotniVijek];
	for (int i = 0; i < 2 * ocekivaniZivotniVijek; i++)
	{
		masa[i].godina = an.masa[i].godina;
		masa[i].tezina = an.masa[i].tezina;
	}
}
void ZooAnimal::povecajCounter()
{
	counter++;
}
void ZooAnimal::smanjiCounter()
{
	counter--;
}
void ZooAnimal::ispisCountera()
{
	cout << "Counter:" << counter;
}
bool operator==(const ZooAnimal& a, const ZooAnimal& b)
{
	if (a.ime == b.ime && a.vrsta == b.vrsta)
	{
		return true;
	}
	else {
		return false;
	}
}
ZooAnimal ZooAnimal::operator++()
{
	return ++brojDnevnihObroka;
}
ZooAnimal ZooAnimal::operator--()
{
	return --brojDnevnihObroka;
}
ZooAnimal ZooAnimal::operator--(int)
{
	return brojDnevnihObroka--;
}
ZooAnimal ZooAnimal::operator++(int)
{
	return brojDnevnihObroka++;
}
ostream& operator<<(ostream& os, const ZooAnimal& a)
{
	os << a.vrsta << " " << a.ime << " " << a.godRodjenja << " " << a.brojKaveza << " " << a.brojDnevnihObroka << " " << a.ocekivaniZivotniVijek;
	return os;
}
ZooAnimal& ZooAnimal::operator=(const ZooAnimal& an)
{
	vrsta = an.vrsta;
	ime = an.ime;
	brojDnevnihObroka = an.brojDnevnihObroka;
	brojKaveza = an.brojKaveza;
	godRodjenja = an.godRodjenja;
	ocekivaniZivotniVijek = an.ocekivaniZivotniVijek;
	masa = new Masa[2 * ocekivaniZivotniVijek];
	for (int i = 0; i < 2 * ocekivaniZivotniVijek; i++)
	{
		masa[i].godina = an.masa[i].godina;
		masa[i].tezina = an.masa[i].tezina;
	}
	return *this;
}
//ZooAnimal::~ZooAnimal()
//{
//	delete[] masa;
//	masa = 0;
//}


void ZooAnimal::promjenaBrObroka(string unos)
{
	if (unos == "povecaj")
	{
		ZooAnimal::brojDnevnihObroka += 1;
	}
	else if (unos == "smanji")
	{
		ZooAnimal::brojDnevnihObroka -= 1;
		//x++;
		
	}
}
void ZooAnimal::dodajMasu(int kilogrami, int godina)
{
	int i, index = 0, trenutna = 2017;
	for (i = 0; i<2 * ocekivaniZivotniVijek; i++)
	{
		if (godina == ZooAnimal::masa[i].godina && godina != trenutna)
		{
			cout << "Greska" << endl;
			return;
		}

			if (ZooAnimal::masa[i].godina == trenutna && trenutna==godina )
			{
				ZooAnimal::masa[i].godina = godina;
				ZooAnimal::masa[i].tezina = kilogrami;
				return;
			}
			if (ZooAnimal::masa[i].godina != 0)
			{
				index++;
			}
		}
	
	ZooAnimal::masa[index].godina = godina;
	ZooAnimal::masa[index].tezina = kilogrami;

}

void ZooAnimal::udebljala()
{
	int trenutna = 2017, i, masa1 = 0, masa2 = 0;
	for (i = 0; i < ocekivaniZivotniVijek; i++)
	{
		if (ZooAnimal::masa[i].godina == trenutna)
		{
			masa1 = ZooAnimal::masa[i].tezina;
		}
		if (ZooAnimal::masa[i].godina == trenutna - 1)
		{
			masa2 = ZooAnimal::masa[i].tezina;
		}

	}
	
		if (masa1 == masa2)
		{
			cout << "Isto" << endl;
			return;
		}
		if (masa1 > masa2)
		{
			if (masa1 > masa2 + (masa2 * 10) / 100) 
			{
				cout << "udebljala vise od 10%" << endl;
				ZooAnimal::promjenaBrObroka("smanji");
				return;
			}
			else if (masa1 == masa2 + (masa2 * 10) / 100)
			{
				cout << "udebljala za 10%" << endl;
				return;
			}
			else {
				cout << "udebljala za manje od 10%" << endl;
				return;
			}
		}
		if (masa1 < masa2)
		{
			if (masa1 < masa2 - (masa2 * 10) / 100)
			{
				cout << "smrsala za vise od 10%" << endl;
				ZooAnimal::promjenaBrObroka("povecaj");
				return;
			}
			else if (masa1 == masa2 - (masa2 * 10) / 100)
			{
				cout << "smrsala za 10%" << endl;
				return;
			}
			else {
				cout << "smrsala za manje od 10%" << endl;
				return;
			}
		}
}
void ZooAnimal::ispisi_zivotinju()
{
	int j = 0;
	cout << vrsta << " " << ime << " " << brojKaveza << " " << godRodjenja << " " << ocekivaniZivotniVijek << " " << brojDnevnihObroka << endl;    
	while (ZooAnimal::masa[j].godina != 0)
	{
		cout << ZooAnimal::masa[j].godina << " " << ZooAnimal::masa[j].tezina << endl;
		j++;
	}
	//cout << "X:" << x << endl;
}



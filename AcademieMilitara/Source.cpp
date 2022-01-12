// Aelenei Ciprian - AC_ademie Militara

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include <conio.h>

using namespace std;

class ExceptieMesaj : public exception
{
	string mesaj;
public:
	ExceptieMesaj()
	{
		this->mesaj = "Necunoscuta";
	}
	ExceptieMesaj(string mesaj)
	{
		this->mesaj = mesaj;
	}
	string getMesaj()
	{
		return this->mesaj;
	}
	~ExceptieMesaj()
	{

	}
};

#pragma region enum uri
enum GradOfiter { SUBLOCOTENENT = 1, LOCOTENENT = 2, CAPITAN = 3, MAIOR = 4, LOCOTENENTCOLONEL = 5, COLONEL = 6, GENERAL = 7 };
enum GradSubofiter { SERGENT = 1, SERGENTMAJOR = 2, PLUTONIER = 3, PLUTONIERMAJOR = 4, PLUTONIERADJUTANT = 5, PLUTONIERPRINCIPAL = 6 };
enum GradMaistru { CLASA5 = 5, CLASA4 = 4, CLASA3 = 3, CLASA2 = 2, CLASA1 = 1, PRINCIPAL = 0 };
enum Forta { TERESTRE = 1, NAVALE = 2, AERIENE = 3 };

enum Functie { COMANDA = 1, EXECUTIE = 2 };
enum Dificultate { usoara = 1, medie = 2, grea = 3 };

# pragma endregion

# pragma region nivel 1
class Membru;
class Civil;
class Militar;
class Ofiter;
class Subofiter;
class MaistruMilitar;
class Misiune;


class Membru {
private:
	const int id;
	char* nume;
	char* prenume;
	char* locatie;
	int varsta;
	bool sex; //0 = feminin, 1 = masculin
	int nrZile = 31;
	int oreLucrate[31];

public:
	static int contorMembri;

	Membru() : id(contorMembri++) {
		nume = new char[strlen("necunoscut") + 1];
		strcpy(nume, "necunoscut");
		prenume = new char[strlen("necunoscut") + 1];
		strcpy(prenume, "necunoscut");
		locatie = new char[strlen("necunoscuta") + 1];
		strcpy(locatie, "necunoscuta");
		varsta = 18;
		sex = true;
		nrZile = 31;
		for (int i = 0; i < nrZile; i++) {
			oreLucrate[i] = 0;
		}
	}

	Membru(const char* nume, const char* prenume, const char* adresa, int varsta, bool sex, int nrZile, int oreLucrate[]) :id(contorMembri++) {
		if (strlen(nume) > 3) {
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else {
			this->nume = new char[strlen("") + 1];
			strcpy(this->nume, "");
		}

		if (strlen(prenume) > 3) {
			this->prenume = new char[strlen(prenume) + 1];
			strcpy(this->prenume, prenume);
		}
		else {
			this->prenume = new char[strlen("") + 1];
			strcpy(this->prenume, "");
		}
		if (strlen(adresa) > 5) {
			this->locatie = new char[strlen(adresa) + 1];
			strcpy(this->locatie, adresa);
		}
		else {
			this->locatie = new char[strlen("") + 1];
			strcpy(this->locatie, "");
		}
		if (varsta > 18)
			this->varsta = varsta;
		else
			this->varsta = 18;
		this->sex = sex;
		if (nrZile > 0)
			this->nrZile = nrZile;
		else
			this->nrZile = 1;
		for (int i = 0; i < nrZile; i++) {
			this->oreLucrate[i] = oreLucrate[i];
		}
	}

	Membru(const Membru& m) :id(contorMembri++) {
		if (strlen(m.nume) > 3) {
			this->nume = new char[strlen(m.nume) + 1];
			strcpy(this->nume, m.nume);
		}
		else {
			this->nume = new char[strlen("") + 1];
			strcpy(this->nume, "");
		}

		if (strlen(m.prenume) > 3) {
			this->prenume = new char[strlen(m.prenume) + 1];
			strcpy(this->prenume, m.prenume);
		}
		else {
			this->prenume = new char[strlen("") + 1];
			strcpy(this->prenume, "");
		}
		if (strlen(m.locatie) > 5) {
			this->locatie = new char[strlen(m.locatie) + 1];
			strcpy(this->locatie, m.locatie);
		}
		else {
			this->locatie = new char[strlen("") + 1];
			strcpy(this->locatie, "");
		}
		if (m.varsta > 18)
			this->varsta = m.varsta;
		else
			this->varsta = 18;
		this->sex = m.sex;
		if (m.nrZile > 0)
			this->nrZile = m.nrZile;
		else
			this->nrZile = 1;
		for (int i = 0; i < m.nrZile; i++) {
			this->oreLucrate[i] = m.oreLucrate[i];
		}

	}

	Membru& operator=(const Membru& m) {
		if (this != &m) {
			if (this->prenume != NULL)
				delete[] this->prenume;
			if (this->nume != NULL)
				delete[] this->nume;
			if (this->locatie != NULL)
				delete[] this->locatie;
		}

		this->nume = new char[strlen(m.nume) + 1];
		strcpy(this->nume, m.nume);
		this->prenume = new char[strlen(m.prenume) + 1];
		strcpy(this->prenume, m.prenume);
		this->locatie = new char[strlen(m.locatie) + 1];
		strcpy(this->locatie, m.locatie);
		this->varsta = m.varsta;
		this->sex = m.sex;
		this->nrZile = m.nrZile;
		for (int i = 0; i < m.nrZile; i++) {
			this->oreLucrate[i] = m.oreLucrate[i];
		}
		return *this;

	}



	~Membru() {
		if (this->prenume)
			delete[] this->prenume;
		if (this->nume)
			delete[] this->nume;
		if (this->locatie)
			delete[] this->locatie;

	}

	//functii accesor
	int getId() {
		return this->id;
	}

	char* getNume() {
		return this->nume;
	}
	void setNume(const char* nume) {
		if (strlen(nume) > 2) {
			if (this->nume != NULL) {
				delete[] this->nume;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else {
			throw ExceptieMesaj("Numele este gresit!\n");
		}
	}
	char* getPrenume() {
		return this->prenume;
	}
	void setPrenume(const char* prenume) {
		if (strlen(prenume) > 2) {
			if (this->prenume != NULL) {
				delete[] this->prenume;
			}
			this->prenume = new char[strlen(prenume) + 1];
			strcpy(this->prenume, prenume);
		}
		else {
			throw ExceptieMesaj("Prenumele este gresit!\n");
		}
	}
	char* getLocatie() {
		return this->locatie;
	}
	void setLocatie(const char* locatie) {
		if (strlen(locatie) > 2) {
			if (this->locatie != NULL) {
				delete[] this->locatie;
			}
			this->locatie = new char[strlen(locatie) + 1];
			strcpy(this->locatie, locatie);
		}
		else throw ExceptieMesaj("Locatia este gresita!\n");

	}
	int getVarsta() {
		return this->varsta;
	}
	void setVarsta(int varsta) {
		if (varsta > 18)
			this->varsta = varsta;
		else
			this->varsta = 18;
	}
	bool getSex() {
		return this->sex;
	}
	void setSex(bool sex) {
		if (sex == true && sex == false) {
			this->sex = sex;
		}
		else
			this->sex = true;
	}

	int getNrZile() {
		return this->nrZile;
	}
	void setNrZile(int nrZile) {
		if (nrZile > 0) {
			this->nrZile = nrZile;
		}
		else {
			this->nrZile = 1;
		}
	}

	int getPrezenta(int zi) {
		if (zi < this->nrZile + 1)
			return this->oreLucrate[zi - 1];

	}
	void setPrezenta(int ziua, int nrOreLucrate) {

		if (ziua <= this->nrZile && nrOreLucrate <= 24)
			this->oreLucrate[ziua - 1] = nrOreLucrate;
		else
			throw ExceptieMesaj("Nu se pot asigna orele lucrate!\n");

	}

	//operatori 
	friend ostream& operator<<(ostream& out, const Membru& m);
	//friend istream& operator>>(istream& in, Membru& m);
	friend istream& operator>>(istream& in, Membru& m) {
		if (m.nume != NULL)
			delete[] m.nume;
		if (m.prenume != NULL)
			delete[] m.prenume;
		if (m.locatie != NULL)
			delete[] m.locatie;

		cout << "Nume: ";
		char nume[50];
		in.getline(nume, 50);
		m.nume = new char[strlen(nume) + 1];
		strcpy(m.nume, nume);

		cout << "Preume: ";
		char prenume[50];
		in.getline(prenume, 50);
		m.prenume = new char[strlen(prenume) + 1];
		strcpy(m.prenume, prenume);

		cout << "Locatie: ";
		char locatie[50];
		in.getline(locatie, 50);
		m.locatie = new char[strlen(locatie) + 1];
		strcpy(m.locatie, locatie);

		cout << "Varsta: "; in >> m.varsta;
		cout << "Sex: "; in >> m.sex;
		cout << "Numar zile: "; in >> m.nrZile;
		//delete[] m.oreLucrate;
		for (int i = 0; i < m.nrZile; i++) {
			cout << "Ore lucrate[" << i << "] = ";
			in >> m.oreLucrate[i];
		}
		return in;
	}

	int& operator[] (int index)
	{
		//de adaugat validari + throw exception
		if (index < 32)
			return this->oreLucrate[index];
		else
			throw ExceptieMesaj("Index gresit!\n");
	}

	Membru operator+(int valoare)
	{
		//Membru copie = *this;
		//copie.varsta = copie.varsta + valoare;
		this->oreLucrate[this->nrZile - 1] = valoare;
		this->nrZile++;
		return *this;
	}

	Membru operator++() {
		this->varsta++;
		return *this;
	}

	Membru operator++(int) {
		Membru copie = *this;
		this->varsta++;
		return copie;
	}

	operator string()
	{
		return this->nume;
	}

	Membru operator!() {
		Membru rez = *this;
		rez.oreLucrate[rez.nrZile - 1] = 0;
		return rez;
	}

	bool operator<(Membru m) {
		int rezultatThis = 0;
		int rezultatM = 0;
		for (int i = 0; i < this->nrZile; i++)
			rezultatThis += oreLucrate[i];
		for (int i = 0; i < m.nrZile; i++)
			rezultatM += oreLucrate[i];

		return rezultatThis < rezultatM;

	}

	bool operator==(Membru m) {
		return this->varsta == m.varsta;
	}

	friend ifstream& operator>>(ifstream& in, Membru& m) {
		if (m.nume != NULL)
			delete[] m.nume;
		if (m.prenume != NULL)
			delete[] m.prenume;
		if (m.locatie != NULL)
			delete[] m.locatie;

		char nume[50];
		in.getline(nume, 50);
		m.nume = new char[strlen(nume) + 1];
		strcpy(m.nume, nume);

		char prenume[50];
		in.getline(prenume, 50);
		m.prenume = new char[strlen(prenume) + 1];
		strcpy(m.prenume, prenume);

		char locatie[50];
		in.getline(locatie, 50);
		m.locatie = new char[strlen(locatie) + 1];
		strcpy(m.locatie, locatie);

		in >> m.varsta;
		in >> m.sex;
		in >> m.nrZile;

		for (int i = 0; i < m.nrZile; i++) {
			in >> m.oreLucrate[i];
		}
		return in;
	}

	friend ofstream& operator<<(ofstream& out, const Membru& m) {
		out << m.id << endl;
		out << m.nume << endl;
		out << m.prenume << endl;
		out << m.locatie << endl;
		out << m.varsta << endl;
		out << m.sex << endl;
		out << m.nrZile << endl;

		for (int i = 0; i <= m.nrZile; i++) {
			if (i + 1 < m.nrZile + 1)
				out << m.oreLucrate[i] << endl;
		}

		return out;
	}



};

int Membru::contorMembri = 0;

ostream& operator<<(ostream& out, const Membru& m) {
	out << "Membru: " << endl;
	out << "id = " << m.id << ", ";
	out << "numele = " << m.nume << ", ";
	out << "prenumele = " << m.prenume << ", ";
	out << "locatia = " << m.locatie << ", ";
	out << "varsta = " << m.varsta << ", ";
	out << "sexul = " << m.sex << ", ";
	out << "numarul de zile disponibile = " << m.nrZile << ", ";
	out << "si are orele lucrate: " << endl;
	for (int i = 0; i <= m.nrZile; i++) {
		if (i + 1 < m.nrZile + 1)
			out << " + ziua[" << i + 1 << "] == " << m.oreLucrate[i] << endl;
	}
	out << "---------------------------------------" << endl;
	out << " " << endl;
	return out;
}

class Civil : public Membru {
private:
	int id;
	char* atributie;
	int luniVechime;
	int interventie[];
public:
	Civil():Membru() {

		atributie = new char[strlen("Necunoscuta") + 1];
		strcpy(atributie, "Necunoscuta");
		luniVechime = 1;
		interventie[0] = 0;
	}
	Civil(Membru m, const char* atributie, int luniVechime, int interventie[]):Membru(m) {
		if (strlen(atributie) > 0) {
			this->atributie = new char[strlen(atributie) + 1];
			strcpy(this->atributie, atributie);
		}
		else {
			this->atributie = new char[strlen("") + 1];
			strcpy(this->atributie, "");
		}
		if (luniVechime > 0) {
			this->luniVechime = luniVechime;
		}
		else {
			this->luniVechime = 1;
		}
		for (int i = 0; i < this->luniVechime; i++) {
			this->interventie[i] = interventie[i];
		}
	}

	Civil(const Civil& c):Membru(c) {
		if (strlen(c.atributie) > 3) {
			this->atributie = new char[strlen(c.atributie) + 1];
			strcpy(this->atributie, c.atributie);
		}
		else {
			this->atributie = new char[strlen("") + 1];
			strcpy(this->atributie, "");
		}
		if (luniVechime > 0) {
			this->luniVechime = c.luniVechime;
		}
		else {
			this->luniVechime = 1;
		}
		for (int i = 0; i < this->luniVechime; i++) {
			this->interventie[i] = c.interventie[i];
		}
	}

	~Civil() {
		if (this->atributie)
			delete[] this->atributie;

	}


	Civil& operator=(const Civil& c) {
		Membru::operator=(c);	
		if (this != &c) {
			if (this->atributie)
				delete[] this->atributie;
			this->atributie = new char[strlen(c.atributie) + 1];
			strcpy(this->atributie, c.atributie);
			this->luniVechime = c.luniVechime;
			for (int i = 0; i < this->luniVechime; i++) {
				this->interventie[i] = c.interventie[i];
			}
		}
		return *this;
	}
	//getteri si setteri
	char* getAtributie() {
		return this->atributie;
	}
	void setAtributie(const char* atributie) {
		if (atributie != NULL) {
			this->atributie = new char[strlen(atributie) + 1];
			strcpy(this->atributie, atributie);
		}
		else {
			strcpy(this->atributie, "Necunoscuta");
		}

	}
	int getLuniVechime() {
		return this->luniVechime;
	}
	void setLuniVechime(int nr) {
		this->luniVechime = nr;
		/*for (int i = 0; i < this->luniVechime; i++) {
			this->interventie[i] = 0;
		}*/

	}
	int getInterventie(int luna) {
		if (luna < this->luniVechime + 1)
			return this->interventie[luniVechime - 1];

	}
	void setPrezenta(int luna, int valoare) {

		if (luna <= this->luniVechime)
			this->interventie[luna - 1] = valoare;
		else
			throw ExceptieMesaj("Nu se pot asigna interventiile!\n");

	}

	int& operator[] (int index)
	{
		//de adaugat validari + throw exception
		if (index < this->luniVechime)
			return this->interventie[index];
		else
			throw ExceptieMesaj("Luni vechime gresite!\n");
	}

	Civil operator+(int valoare)
	{
		//Civil copie = *this;
		//copie.luniVechime = copie.luniVechime + valoare;
		this->interventie[this->luniVechime - 1] = valoare;
		this->luniVechime++;
		return *this;
	}

	Civil operator++() {
		this->luniVechime++;
		return *this;
	}

	Civil operator++(int) {
		Civil copie = *this;
		this->luniVechime++;
		return copie;
	}

	operator string()
	{
		return this->atributie;
	}

	Civil operator!() {
		Civil rez = *this;
		rez.interventie[rez.luniVechime - 1] = 0;
		return rez;
	}

	bool operator<(Civil c) {
		if (this->luniVechime > c.luniVechime)
			return true;
		else
			return false;

	}

	bool operator==(Civil c) {
		return this->luniVechime == c.luniVechime;
	}


	friend ostream& operator<<(ostream& out, const Civil& c);
	friend istream& operator>>(istream& in, Civil& c);

	friend ofstream& operator<<(ofstream& out, const Civil& c) {
		out << (Membru)c;
		out << c.atributie;
		out << c.luniVechime;

		for (int i = 0; i < c.luniVechime; i++) {
			out << c.interventie[i] << endl;
		}

		return out;
	}

	friend ifstream& operator>>(ifstream& in, Civil& c) {
		if (c.atributie)
			delete[] c.atributie;
		in >> (Membru&)c;
		char nume[50];
		in.getline(nume, 50);
		c.atributie = new char[strlen(nume) + 1];
		strcpy(c.atributie, nume);

		in >> c.luniVechime;


		for (int i = 0; i < c.luniVechime; i++)
			in >> c.interventie[i];

		return in;
	}

};
ostream& operator<<(ostream& out, const Civil& c) {
	out << "-----------------------------------------------" << endl;
	out << "Civil: " << endl;
	out << (Membru)c;
	out << "Atributie = " << c.atributie;
	out << ", Numar luni vechime = " << c.luniVechime;
	out << ", Interventiile sunt: " << endl;
	for (int i = 0; i < c.luniVechime; i++) {
		out << "+ interventia[" << i << "] = " << c.interventie[i] << endl;
	}
	out << "-----------------------------------------------" << endl;
	return out;
}

istream& operator>>(istream& in, Civil& c) {
	if (c.atributie)
		delete[] c.atributie;
	in >> (Membru&)c;
	cout << "Atributie: ";
	char nume[50];
	in.getline(nume, 50);
	c.atributie = new char[strlen(nume) + 1];
	strcpy(c.atributie, nume);

	cout << "Numar luni vechime: ";
	in >> c.luniVechime;

	cout << "Introduceti interventiile: ";
	for (int i = 0; i < c.luniVechime; i++) {
		cout << "Interventia[" << i << "] = ";
		in >> c.interventie[i];
	}

	return in;
}

class Militar : public Membru {
private:
	const int idMilitar;
protected:
	bool rh; //0 - pozitiv , 1 = negativ
	char* grupaSanguina;
	int nrOre;
	int nrEvaluari;
	int* note;
	Forta forta;

public:
	static int numarInrolari;
	Militar() :idMilitar(numarInrolari++ * 100),Membru() {
		rh = false;
		grupaSanguina = new char[4];
		strcpy(grupaSanguina, "00");
		nrOre = 0;
		nrEvaluari = 0;
		note = NULL;
		forta = Forta::TERESTRE;
	}
	Militar(Membru m, bool rh, const char* grupaSanguina, int nrOre, int nrEvaluari, int* note, Forta forta) :idMilitar(numarInrolari++ * 100), Membru(m) {
		this->rh = rh;
		this->grupaSanguina = new char[strlen(grupaSanguina) + 1];
		strcpy(this->grupaSanguina, grupaSanguina);
		this->nrOre = nrOre;
		this->forta = forta;
		this->nrEvaluari = nrEvaluari;
		this->note = new int[this->nrEvaluari];
		for (int i = 0; i < this->nrEvaluari; i++) {
			this->note[i] = note[i];
		}
	}
	Militar(Membru me, const Militar& m) :idMilitar(m.numarInrolari++ * 100), Membru(me) {
		this->rh = m.rh;
		this->grupaSanguina = new char[strlen(m.grupaSanguina) + 1];
		strcpy(this->grupaSanguina, m.grupaSanguina);
		this->nrOre = m.nrOre;
		this->forta = m.forta;
		this->nrEvaluari = m.nrEvaluari;
		this->note = new int[this->nrEvaluari];
		for (int i = 0; i < this->nrEvaluari; i++) {
			this->note[i] = m.note[i];
		}
	}
	Militar& operator =(const Militar& m){
		if (this != &m) {
			Membru::operator=(m);
			if (this->grupaSanguina != NULL)
				delete[] this->grupaSanguina;
			this->rh = m.rh;
			this->grupaSanguina = new char[strlen(m.grupaSanguina) + 1];
			strcpy(this->grupaSanguina, m.grupaSanguina);
			this->nrOre = m.nrOre;
			this->forta = m.forta;
			this->nrEvaluari = m.nrEvaluari;
			this->note = new int[this->nrEvaluari];
			for (int i = 0; i < this->nrEvaluari; i++) {
				this->note[i] = m.note[i];
			}
			return *this;
		}
	}
	/*~Militar() {
		if (this->grupaSanguina)
			delete[] this->grupaSanguina;
		if (this->note)
			delete[] this->note;
	}*/

	friend ostream& operator<<(ostream& out, const Militar& m) {
		out << "----------------------------------------------------------------------------" << endl;
		out << (Membru)m;
		out << "Id militar = " << m.idMilitar;
		out << ", Rh: ";
		if (m.rh)
			out << "negativ";
		else
			out << "pozitiv";
		out << ", grupa sanguina: " << m.grupaSanguina;
		out << ", numar ore program: " << m.nrOre;
		out << ", face parte din Fortele ";
		switch (m.forta) {
		case 1: out << "Terestre Romane";
			break;
		case 2: out << "Navale Romane";
			break;
		case 3: out << "Aeriene Romane";
			break;
		}
		out << ", are " << m.nrEvaluari << " evaluari si a obtinut urmatoarele note: ";
		for (int i = 0; i < m.nrEvaluari; i++) {
			out << m.note[i] << " ";
		}
		return out;
	}

	friend istream& operator>>(istream& in, Militar& m) {
		cout << endl;
		if (m.grupaSanguina)
			delete[] m.grupaSanguina;

		//char* rh = new char[2];
		//cout << "introduceti rh-ul(+,-) "; 
		//in.getline(rh, 1);
		//cout << endl;
		//if (strcmp(rh, "-") == 0)
		//    m.rh = 1;
		//else if (strcmp(rh, "+") == 0)
		//    m.rh = 0;
		//else
		//    cout << "rh gresit. Introduceti rh-ul(+,-) "; in >> rh; cout << endl;
		//delete[] rh;
		in >> (Membru&)m;
		cout << "introduceti rh-ul(+ = 0, - = 1): "; in >> m.rh;
		cout << "grupa sanguina: "; in >> m.grupaSanguina;
		cout << "numar ore program: "; in >> m.nrOre;
		cout << "forta(1=terestre, 2=navale, 3=aeriene): ";
		int fortaInt;
		in >> fortaInt; cout << endl;
		switch (fortaInt) {
		case 1: m.forta = Forta::TERESTRE;
			break;
		case 2: m.forta = Forta::NAVALE;
			break;
		case 3: m.forta = Forta::AERIENE;
			break;
		}
		cout << "numar evaluari: "; in >> m.nrEvaluari;
		cout << "introduceti notele ->" << endl;

		m.note = new int[m.nrEvaluari];
		for (int i = 0; i < m.nrEvaluari; i++) {
			cout << "nota " << i << " = ";
			in >> m.note[i];
		}
		return in;
	}

	friend ofstream& operator<<(ofstream& out, const Militar& m) {
		out << (Membru)m;
		out << m.idMilitar;

		if (m.rh)
			out << "negativ";
		else
			out << "pozitiv";

		out << m.grupaSanguina << endl;
		out << m.nrOre << endl;

		switch (m.forta) {
		case 1: out << "Terestre Romane" << endl;
			break;
		case 2: out << "Navale Romane" << endl;
			break;
		case 3: out << "Aeriene Romane" << endl;
			break;
		}
		out << m.nrEvaluari << endl;
		for (int i = 0; i < m.nrEvaluari; i++) {
			out << m.note[i] << endl;
		}
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Militar& m) {

		if (m.grupaSanguina)
			delete[] m.grupaSanguina;
		in >> (Membru&)m;
		in >> m.rh;
		in >> m.grupaSanguina;
		in >> m.nrOre;

		int fortaInt;
		in >> fortaInt; cout << endl;
		switch (fortaInt) {
		case 1: m.forta = Forta::TERESTRE;
			break;
		case 2: m.forta = Forta::NAVALE;
			break;
		case 3: m.forta = Forta::AERIENE;
			break;
		}
		in >> m.nrEvaluari;


		m.note = new int[m.nrEvaluari];
		for (int i = 0; i < m.nrEvaluari; i++) {
			in >> m.note[i];
		}
		return in;
	}
};

int Militar::numarInrolari = 0;

# pragma endregion

# pragma region nivel 2 militar

class Ofiter : public Militar {
private:
	GradOfiter grad;
	Functie functie;
	int nrMilitariSubordine;
	string* numeMilitariSubordine;
public:
	Ofiter():Militar() {
		grad = GradOfiter::SUBLOCOTENENT;
		functie = Functie::EXECUTIE;
		nrMilitariSubordine = 0;
		numeMilitariSubordine = NULL;
	}
	Ofiter(Militar m, GradOfiter grad, Functie functie, int nrMilitariSubordine, string* nume):Militar(m) {
		this->grad = grad;
		this->functie = functie;
		if (nrMilitariSubordine > 0)
			this->nrMilitariSubordine = nrMilitariSubordine;
		else
			this->nrMilitariSubordine = 0;
		numeMilitariSubordine = new string[nrMilitariSubordine];
		for (int i = 0; i < this->nrMilitariSubordine; i++) {
			this->numeMilitariSubordine[i] = nume[i];
		}

	}
	Ofiter(const Ofiter& o):Militar(o) {
		this->grad = o.grad;
		this->functie = o.functie;
		if (o.nrMilitariSubordine > 0)
			this->nrMilitariSubordine = o.nrMilitariSubordine;
		else
			this->nrMilitariSubordine = 0;
		if (this->nrMilitariSubordine > 0) {
			for (int i = 0; i < this->nrMilitariSubordine; i++) {
				this->numeMilitariSubordine[i] = o.numeMilitariSubordine[i];
			}
		}
		else {
			this->numeMilitariSubordine = NULL;
		}
	}
	~Ofiter() {
		if (this->numeMilitariSubordine != NULL)
			delete[] this->numeMilitariSubordine;
	}
	Ofiter& operator=(const Ofiter& o) {
		if (this != &o) {
			Militar::operator=(o);
			this->grad = o.grad;
			this->functie = o.functie;
			if (o.nrMilitariSubordine > 0)
				this->nrMilitariSubordine = o.nrMilitariSubordine;
			else
				this->nrMilitariSubordine = 0;
			if (this->nrMilitariSubordine > 0) {
				for (int i = 0; i < this->nrMilitariSubordine; i++) {
					this->numeMilitariSubordine[i] = o.numeMilitariSubordine[i];
				}
			}
			else {
				this->numeMilitariSubordine = NULL;
			}
		}
		return *this;
	}

	//getteri si setteri
	GradOfiter getGrad() {
		return this->grad;
	}
	void setGrad(GradOfiter grad) {
		this->grad = grad;
	}
	Functie getFunctie() {
		return this->functie;
	}
	void setFunctie(Functie functie) {
		this->functie = functie;
	}
	int getNrMilitariSubordine() {
		return this->nrMilitariSubordine;
	}
	void setNrMilitariSubordine(int nr) {
		if (nr > 0) {
			this->nrMilitariSubordine = nr;
		}
		else {
			this->nrMilitariSubordine = 0;
		}
	}
	string* getNumeMilitariSubordine() {
		return this->numeMilitariSubordine;
	}
	void setNumeMilitariSubordine(string* numeMilitariSubordine) {
		for (int i = 0; i < this->nrMilitariSubordine; i++) {
			this->numeMilitariSubordine[i] = numeMilitariSubordine[i];
		}
	}
	friend ostream& operator<<(ostream& out, const Ofiter& o) {
		out << (Militar)o;
		out << "\nofiterul are gradul de ";
		switch (o.grad) {
		case 1: out << "SUBLOCOTENENT";
			break;
		case 2: out << "LOCOTENENT"; ;
			break;
		case 3: out << "CAPITAN"; ;
			break;
		case 4: out << "MAIOR"; ;
			break;
		case 5: out << "LOCOTENENTCOLONEL"; ;
			break;
		case 6: out << "COLONEL"; ;
			break;
		case 7: out << "GENERAL"; ;
			break;
			out << "si functia de ";
			switch (o.functie) {
			case 1: out << "COMANDA";
				break;
			case 2: out << "EXECUTIE";
				break;
			}
			out << ", are numarul de militari in subordine: " << o.nrMilitariSubordine;
			out << "Lista cu militarii din subordine: " << endl;
			for (int i = 0; i < o.nrMilitariSubordine; i++) {
				out << o.numeMilitariSubordine[i];
			}
			return out;
		}
	}

	friend istream& operator>>(istream& in, Ofiter& o) {
		if (o.numeMilitariSubordine)
			delete[] o.numeMilitariSubordine;
		in >> (Militar&)o;
		cout << "\ngrad ofiter: ";
		int gradInt;
		in >> gradInt;
		switch (gradInt) {
		case 1: o.grad = GradOfiter::SUBLOCOTENENT;
			break;
		case 2: o.grad = GradOfiter::LOCOTENENT;
			break;
		case 3: o.grad = GradOfiter::CAPITAN;
			break;
		case 4: o.grad = GradOfiter::MAIOR;
			break;
		case 5: o.grad = GradOfiter::LOCOTENENTCOLONEL;
			break;
		case 6: o.grad = GradOfiter::COLONEL;
			break;
		case 7: o.grad = GradOfiter::GENERAL;
			break;
		}
		cout << "\nfunctie ofiter: ";
		int functieInt;
		in >> functieInt;
		switch (functieInt) {
		case 1: o.functie = Functie::COMANDA;
			break;
		case 2: o.functie = Functie::EXECUTIE;
			break;
		}
		cout << "\nnr militari subordine: ";
		in >> o.nrMilitariSubordine;
		cout << "/nIntroduceti militarii din subordine";
		for (int i = 0; i < o.nrMilitariSubordine; i++) {
			cout << "\nmilitarul " << "i" << " = ";
			in >> o.numeMilitariSubordine[i];
		}

		return in;
	}

	friend ofstream& operator<<(ofstream& out, const Ofiter& o) {
		out << (Militar)o;
		out << "\nofiterul are gradul de ";
		switch (o.grad) {
		case 1: out << "SUBLOCOTENENT";
			break;
		case 2: out << "LOCOTENENT"; ;
			break;
		case 3: out << "CAPITAN"; ;
			break;
		case 4: out << "MAIOR"; ;
			break;
		case 5: out << "LOCOTENENTCOLONEL"; ;
			break;
		case 6: out << "COLONEL"; ;
			break;
		case 7: out << "GENERAL"; ;
			break;
			out << "si functia de ";
			switch (o.functie) {
			case 1: out << "COMANDA";
				break;
			case 2: out << "EXECUTIE";
				break;
			}
			out << ", are numarul de militari in subordine: " << o.nrMilitariSubordine;
			out << "Lista cu militarii din subordine: " << endl;
			for (int i = 0; i < o.nrMilitariSubordine; i++) {
				out << o.numeMilitariSubordine[i];
			}
			return out;
		}
	}

	friend ifstream& operator>>(ifstream& in, Ofiter& o) {
		if (o.numeMilitariSubordine)
			delete[] o.numeMilitariSubordine;
		in >> (Militar&)o;
		cout << "\ngrad ofiter: ";
		int gradInt;
		in >> gradInt;
		switch (gradInt) {
		case 1: o.grad = GradOfiter::SUBLOCOTENENT;
			break;
		case 2: o.grad = GradOfiter::LOCOTENENT;
			break;
		case 3: o.grad = GradOfiter::CAPITAN;
			break;
		case 4: o.grad = GradOfiter::MAIOR;
			break;
		case 5: o.grad = GradOfiter::LOCOTENENTCOLONEL;
			break;
		case 6: o.grad = GradOfiter::COLONEL;
			break;
		case 7: o.grad = GradOfiter::GENERAL;
			break;
		}
		cout << "\nfunctie ofiter: ";
		int functieInt;
		in >> functieInt;
		switch (functieInt) {
		case 1: o.functie = Functie::COMANDA;
			break;
		case 2: o.functie = Functie::EXECUTIE;
			break;
		}
		cout << "\nnr militari subordine: ";
		in >> o.nrMilitariSubordine;
		cout << "/nIntroduceti militarii din subordine";
		for (int i = 0; i < o.nrMilitariSubordine; i++) {
			cout << "\nmilitarul " << "i" << " = ";
			in >> o.numeMilitariSubordine[i];
		}

		return in;
	}


	//operatori
	string& operator[] (int index) {
		if (index < this->nrMilitariSubordine)
			return this->numeMilitariSubordine[index];
		else
			throw ExceptieMesaj("Index gresit!\n");
	}

	Ofiter operator+(string valoare)
	{
		//Membru copie = *this;
		//copie.varsta = copie.varsta + valoare;
		this->numeMilitariSubordine[this->nrMilitariSubordine - 1] = valoare;
		this->nrMilitariSubordine++;
		return *this;
	}
	Ofiter operator++() {
		this->nrMilitariSubordine++;
		return *this;
	}
	Ofiter operator++(int) {
		Ofiter copie = *this;
		this->nrMilitariSubordine++;
		return copie;
	}
	operator float()
	{
		return this->nrMilitariSubordine;
	}
	Ofiter operator!() {
		Ofiter rez = *this;
		rez.numeMilitariSubordine[rez.nrMilitariSubordine - 1] = "NAN";
		return rez;
	}

	bool operator==(Ofiter m) {
		return this->nrMilitariSubordine == m.nrMilitariSubordine;
	}

	Ofiter operator()() {
		int gradInt = this->grad;
		if (gradInt >= 0 && gradInt <= 6) {
			gradInt++;
			switch (gradInt) {
			case 1: this->grad = GradOfiter::SUBLOCOTENENT;
				break;
			case 2: this->grad = GradOfiter::LOCOTENENT;
				break;
			case 3: this->grad = GradOfiter::CAPITAN;
				break;
			case 4: this->grad = GradOfiter::MAIOR;
				break;
			case 5: this->grad = GradOfiter::LOCOTENENTCOLONEL;
				break;
			case 6: this->grad = GradOfiter::COLONEL;
				break;
			case 7: this->grad = GradOfiter::GENERAL;
				break;
			}
		}
		else
			this->grad = GradOfiter::SUBLOCOTENENT;
		return *this;
	}
};





class Subofiter : public Militar{
private:
	GradSubofiter grad;
	Functie functie;
	char* sefCompanie;
public:
	Subofiter():Militar() {
		grad = GradSubofiter::SERGENT;
		functie = Functie::EXECUTIE;
		sefCompanie = new char[strlen("neasignat") + 1];
		strcpy(sefCompanie, "neasignat");
	}
	Subofiter(Militar s, GradSubofiter grad, Functie functie, const char* sefCompanie):Militar(s) {
		this->grad = grad;
		this->functie = functie;
		if (strlen(sefCompanie) > 3) {
			this->sefCompanie = new char[strlen(sefCompanie) + 1];
			strcpy(this->sefCompanie, sefCompanie);
		}
		else
			this->sefCompanie = NULL;
	}
	Subofiter(const Subofiter& s):Militar(s) {
		this->grad = s.grad;
		this->functie = s.functie;
		if (strlen(s.sefCompanie) > 3) {
			this->sefCompanie = new char[strlen(s.sefCompanie) + 1];
			strcpy(this->sefCompanie, s.sefCompanie);
		}
		else
			this->sefCompanie = NULL;
	}
	Subofiter& operator=(const Subofiter& s) {
		if (this != &s) {
			Militar::operator=(s);
			if (this->sefCompanie != NULL)
				delete[] this->sefCompanie;
			this->grad = s.grad;
			this->functie = s.functie;
			if (strlen(s.sefCompanie) > 3) {
				this->sefCompanie = new char[strlen(s.sefCompanie) + 1];
				strcpy(this->sefCompanie, s.sefCompanie);
			}
			else
				this->sefCompanie = NULL;
		}
		return *this;
	}

	~Subofiter() {
		if (this->sefCompanie != NULL)
			delete[] this->sefCompanie;
	}

	//getteri si setteri
	GradSubofiter getGradSubofiter() {
		return this->grad;
	}
	void setGradSubofiter(GradSubofiter grad) {
		this->grad = grad;
	}
	Functie getFunctieSubofiter() {
		return this->functie;
	}
	void setFunctieSubofiter(Functie functie) {
		this->functie = functie;
	}
	char* getSefCompanie() {
		return this->sefCompanie;
	}
	void setSefCompanie(char* sef) {
		if (strlen(sef) > 3) {
			if (this->sefCompanie != NULL)
				delete[] this->sefCompanie;
			this->sefCompanie = new char[strlen(sef) + 1];
			strcpy(this->sefCompanie, sef);
		}
		else throw ExceptieMesaj("Numele sefului de companie este gresit!");
	}


	friend ostream& operator<<(ostream& out, const Subofiter& s) {
		out << (Militar)s;
		out << "\nsubofiterul are gradul de ";
		switch (s.grad) {
		case 1: out << "SERGENT";
			break;
		case 2: out << "SERGENTMAJOR";
			break;
		case 3: out << "PLUTONIER";
			break;
		case 4: out << "PLUTONIERMAJOR";
			break;
		case 5: out << "PLUTONIERADJUTANT";
			break;
		case 6: out << "PLUTONIERPRINCIPAL";
			break;
		}
		out << " si functia de ";
		switch (s.functie) {
		case 1: out << "COMANDA";
			break;
		case 2: out << "EXECUTIE";
			break;
		}
		out << " si este comandat de " << s.sefCompanie;
		return out;
	}

	friend istream& operator>>(istream& in, Subofiter& s) {
		if (s.sefCompanie)
			delete[] s.sefCompanie;
		in >> (Militar&)s;
		cout << "\ngrad subofiter: ";
		int gradInt;
		in >> gradInt;
		switch (gradInt) {
		case 1: s.grad = GradSubofiter::SERGENT;
			break;
		case 2: s.grad = GradSubofiter::SERGENTMAJOR;
			break;
		case 3: s.grad = GradSubofiter::PLUTONIER;
			break;
		case 4: s.grad = GradSubofiter::PLUTONIERMAJOR;
			break;
		case 5: s.grad = GradSubofiter::PLUTONIERADJUTANT;
			break;
		case 6: s.grad = GradSubofiter::PLUTONIERPRINCIPAL;
			break;
		}
		cout << "\nfunctie subofiter: ";
		int functieInt;
		in >> functieInt;
		switch (functieInt) {
		case 1: s.functie = Functie::COMANDA;
			break;
		case 2: s.functie = Functie::EXECUTIE;
			break;
		}
		cout << "\nnume sef companie: ";
		char nume[50];
		in.getline(nume, 50);
		s.sefCompanie = new char[strlen(nume) + 1];
		strcpy(s.sefCompanie, nume);

		return in;
	}

	friend ofstream& operator<<(ofstream& out, const Subofiter& s) {
		out << (Militar)s;
		out << "\nsubofiterul are gradul de ";
		switch (s.grad) {
		case 1: out << "SERGENT";
			break;
		case 2: out << "SERGENTMAJOR";
			break;
		case 3: out << "PLUTONIER";
			break;
		case 4: out << "PLUTONIERMAJOR";
			break;
		case 5: out << "PLUTONIERADJUTANT";
			break;
		case 6: out << "PLUTONIERPRINCIPAL";
			break;
		}
		out << " si functia de ";
		switch (s.functie) {
		case 1: out << "COMANDA";
			break;
		case 2: out << "EXECUTIE";
			break;
		}
		out << " si este comandat de " << s.sefCompanie;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Subofiter& s) {
		if (s.sefCompanie)
			delete[] s.sefCompanie;
		in >> (Militar&)s;
		cout << "\ngrad subofiter: ";
		int gradInt;
		in >> gradInt;
		switch (gradInt) {
		case 1: s.grad = GradSubofiter::SERGENT;
			break;
		case 2: s.grad = GradSubofiter::SERGENTMAJOR;
			break;
		case 3: s.grad = GradSubofiter::PLUTONIER;
			break;
		case 4: s.grad = GradSubofiter::PLUTONIERMAJOR;
			break;
		case 5: s.grad = GradSubofiter::PLUTONIERADJUTANT;
			break;
		case 6: s.grad = GradSubofiter::PLUTONIERPRINCIPAL;
			break;
		}
		cout << "\nfunctie subofiter: ";
		int functieInt;
		in >> functieInt;
		switch (functieInt) {
		case 1: s.functie = Functie::COMANDA;
			break;
		case 2: s.functie = Functie::EXECUTIE;
			break;
		}
		cout << "\nnume sef companie: ";
		char nume[50];
		in.getline(nume, 50);
		s.sefCompanie = new char[strlen(nume) + 1];
		strcpy(s.sefCompanie, nume);

		return in;
	}

	Subofiter operator()() {
		int gradInt = this->grad;
		if (gradInt >= 0 && gradInt <= 6) {
			gradInt++;
			switch (gradInt) {
			case 1: this->grad = GradSubofiter::SERGENT;
				break;
			case 2: this->grad = GradSubofiter::SERGENTMAJOR;
				break;
			case 3: this->grad = GradSubofiter::PLUTONIER;
				break;
			case 4: this->grad = GradSubofiter::PLUTONIERMAJOR;
				break;
			case 5: this->grad = GradSubofiter::PLUTONIERADJUTANT;
				break;
			case 6: this->grad = GradSubofiter::PLUTONIERPRINCIPAL;
				break;
			}
		}
		else
			this->grad = GradSubofiter::PLUTONIERPRINCIPAL;
		return *this;
	}
	operator string()
	{
		return this->sefCompanie;
	}
};

class MaistruMilitar : public Militar{
private:
	GradMaistru grad;
	Functie functie;
	bool esteInginer;
	int nrElevi;
	string* numeElevi;
public:
	MaistruMilitar():Militar() {
		grad = GradMaistru::CLASA5;
		functie = Functie::EXECUTIE;
		esteInginer = true;
		nrElevi = 0;
		string* numeElevi = NULL;
	}
	MaistruMilitar(Militar m, GradMaistru grad, Functie functie, bool esteInginer, int nrElevi, const string* numeElevi):Militar(m) {
		this->grad = grad;
		this->functie = functie;
		this->esteInginer = esteInginer;
		this->nrElevi = nrElevi;
		this->numeElevi = new string[nrElevi];
		for (int i = 0; i < nrElevi; i++) {
			this->numeElevi[i] = numeElevi[i];
		}
	}
	MaistruMilitar(const MaistruMilitar& m) :Militar(m) {
		this->grad = m.grad;
		this->functie = m.functie;
		this->esteInginer = m.esteInginer;
		this->nrElevi = m.nrElevi;
		this->numeElevi = new string[m.nrElevi];
		for (int i = 0; i < m.nrElevi; i++) {
			this->numeElevi[i] = m.numeElevi[i];
		}
	}
	MaistruMilitar& operator=(const MaistruMilitar& m) {
		Militar::operator=(m);
		this->grad = m.grad;
		this->functie = m.functie;
		this->esteInginer = m.esteInginer;
		this->nrElevi = m.nrElevi;
		this->numeElevi = new string[m.nrElevi];
		for (int i = 0; i < m.nrElevi; i++) {
			this->numeElevi[i] = m.numeElevi[i];
		}
		return *this;
	}
	~MaistruMilitar() {
		if (this->numeElevi != NULL)
			delete[] this->numeElevi;
	}

	friend ostream& operator<<(ostream& out, const MaistruMilitar& m) {
		out << (Militar)m;
		out << "grad: " << m.grad;
		out << ", functie: " << m.functie;
		if (m.esteInginer)
			out << ", este inginer";
		else
			out << ", nu este inginer";
		out << "are " << m.nrElevi << " elevi"<<endl;
		out << "Lista elevilor:" << endl;
		for (int i = 0; i < m.nrElevi; i++) {
			cout << i + 1 << ". " << m.numeElevi[i] << endl;
		}
		return out;
	}

	friend istream& operator>>(istream& in, MaistruMilitar& m) {
		in >> (Militar&)m;
		int grad;
		int functie;
		cout << "Grad maistru: "; in >> grad;
		cout << "Functie: "; in >> functie;
		switch (grad) {
		case 0:
			m.grad = GradMaistru::PRINCIPAL;
			break;
		case 1:
			m.grad = GradMaistru::CLASA1;
			break;
		case 2:
			m.grad = GradMaistru::CLASA2;
			break;
		case 3:
			m.grad = GradMaistru::CLASA3;
			break;
		case 4:
			m.grad = GradMaistru::CLASA4;
			break;
		case 5:
			m.grad = GradMaistru::CLASA5;
			break;
		}

		switch (functie) {
		case 1: 
			m.functie = Functie::EXECUTIE;
			break;
		case 2:
			m.functie = Functie::COMANDA;
			break;
		}

		cout << "este inginer(1 - da, 0 - nu): "; in >> m.esteInginer;
		cout << "numar elevi: "; in >> m.nrElevi;
		cout << "Introduceti elevii inscrisi: " << endl;
		for (int i = 0; i < m.nrElevi; i++) {
			cout << "\nelev[" << i << "] = "; in >> m.numeElevi[i];
		}
		return in;
	}

	friend ofstream& operator<<(ofstream& out, const MaistruMilitar& m) {
		out << (Militar)m;
		out << "grad: " << m.grad;
		out << ", functie: " << m.functie;
		if (m.esteInginer)
			out << ", este inginer";
		else
			out << ", nu este inginer";
		out << "are " << m.nrElevi << " elevi" << endl;
		out << "Lista elevilor:" << endl;
		for (int i = 0; i < m.nrElevi; i++) {
			cout << i + 1 << ". " << m.numeElevi[i] << endl;
		}
		return out;
	}

	friend ifstream& operator>>(ifstream& in, MaistruMilitar& m) {
		in >> (Militar&)m;
		int grad;
		int functie;
		cout << "Grad maistru: "; in >> grad;
		cout << "Functie: "; in >> functie;
		switch (grad) {
		case 0:
			m.grad = GradMaistru::PRINCIPAL;
			break;
		case 1:
			m.grad = GradMaistru::CLASA1;
			break;
		case 2:
			m.grad = GradMaistru::CLASA2;
			break;
		case 3:
			m.grad = GradMaistru::CLASA3;
			break;
		case 4:
			m.grad = GradMaistru::CLASA4;
			break;
		case 5:
			m.grad = GradMaistru::CLASA5;
			break;
		}

		switch (functie) {
		case 1:
			m.functie = Functie::EXECUTIE;
			break;
		case 2:
			m.functie = Functie::COMANDA;
			break;
		}

		cout << "este inginer(1 - da, 0 - nu): "; in >> m.esteInginer;
		cout << "numar elevi: "; in >> m.nrElevi;
		cout << "Introduceti elevii inscrisi: " << endl;
		for (int i = 0; i < m.nrElevi; i++) {
			cout << "\nelev[" << i << "] = "; in >> m.numeElevi[i];
		}
		return in;
	}

};

class Misiune {
private:
	char* nume;
	char* locatie;
	char* dataMisiune;
	Dificultate dificultate;
	Ofiter comandant;
	char* armament;
public:
	Misiune() {
		nume = NULL;
		locatie = NULL;
		dataMisiune = NULL;
		dificultate = Dificultate::usoara;
		comandant = Ofiter();
		armament = NULL;
	}
	Misiune(char* nume, char* locatie, char* dataMisiune, Dificultate dificultate, Ofiter comandant, char* armament) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->locatie = new char[strlen(locatie) + 1];
		strcpy(this->locatie, locatie);
		this->dataMisiune = new char[strlen(dataMisiune) + 1];
		strcpy(this->dataMisiune, dataMisiune);
		this->dificultate = dificultate;
		this->comandant = comandant;
		this->armament = new char[strlen(armament) + 1];
		strcpy(this->armament, armament);
	}

	Misiune(const Misiune& m) {
		this->nume = new char[strlen(m.nume) + 1];
		strcpy(this->nume, m.nume);
		this->locatie = new char[strlen(m.locatie) + 1];
		strcpy(this->locatie, m.locatie);
		this->dataMisiune = new char[strlen(m.dataMisiune) + 1];
		strcpy(this->dataMisiune, m.dataMisiune);
		this->dificultate = m.dificultate;
		this->comandant = m.comandant;
		this->armament = new char[strlen(m.armament) + 1];
		strcpy(this->armament, m.armament);
	}

	~Misiune() {
		if (this->nume != nullptr)
			delete[] this->nume;
		if (this->locatie != nullptr)
			delete[] this->locatie;
		if (this->dataMisiune != nullptr)
			delete[] this->dataMisiune;
		if (this->armament != nullptr)
			delete[] this->armament;
	}

	Misiune operator=(const Misiune& m) {
		if (this != &m) {
			if (this->nume != nullptr)
				delete[] this->nume;
			if (this->locatie != nullptr)
				delete[] this->locatie;
			if (this->dataMisiune != nullptr)
				delete[] this->dataMisiune;
			if (this->armament != nullptr)
				delete[] this->armament;

			this->nume = new char[strlen(m.nume) + 1];
			strcpy(this->nume, m.nume);
			this->locatie = new char[strlen(m.locatie) + 1];
			strcpy(this->locatie, m.locatie);
			this->dataMisiune = new char[strlen(m.dataMisiune) + 1];
			strcpy(this->dataMisiune, m.dataMisiune);
			this->dificultate = m.dificultate;
			this->comandant = m.comandant;
			this->armament = new char[strlen(m.armament) + 1];
			strcpy(this->armament, m.armament);
		}
		return *this;

	}

	friend istream& operator>>(istream& in, Misiune& m) {
		cout << "nume misiune: ";
		char aux[50];
		in >> ws;
		in.getline(aux, 49);
		m.nume = new char[strlen(aux) + 1];
		strcpy(m.nume, aux);

		cout << endl << "locatie: ";
		in >> aux;
		m.locatie = new char[strlen(aux) + 1];
		strcpy(m.locatie, aux);

		cout << endl << "data: ";
		in >> aux;
		m.dataMisiune = new char[strlen(aux) + 1];
		strcpy(m.dataMisiune, aux);

		/*this->dificultate = m.dificultate;
		this->comandant = m.comandant;
		this->armament = new char[strlen(m.armament) + 1];
		strcpy(this->armament, m.armament);*/

		int numar;
		cout << endl << "dificultate: "; in >> numar;
		switch (numar) {
		case 1:
			m.dificultate = Dificultate::usoara;
			break;
		case 2: 
			m.dificultate = Dificultate::medie;
			break;
		case 3: 
			m.dificultate = Dificultate::grea;
			break;
		}
		cout << endl << "comandantul misiunii: "; in >> m.comandant;

		cout << endl << "armament: ";
		in >> aux;
		m.armament = new char[strlen(aux) + 1];
		strcpy(m.armament, aux);


	    return in;
	}

	friend ifstream& operator>>(ifstream& in, Misiune& m) {
		cout << "nume misiune: ";
		char aux[50];
		in >> ws;
		in.getline(aux, 49);
		m.nume = new char[strlen(aux) + 1];
		strcpy(m.nume, aux);

		cout << endl << "locatie: ";
		in >> aux;
		m.locatie = new char[strlen(aux) + 1];
		strcpy(m.locatie, aux);

		cout << endl << "data: ";
		in >> aux;
		m.dataMisiune = new char[strlen(aux) + 1];
		strcpy(m.dataMisiune, aux);

		/*this->dificultate = m.dificultate;
		this->comandant = m.comandant;
		this->armament = new char[strlen(m.armament) + 1];
		strcpy(this->armament, m.armament);*/

		int numar;
		cout << endl << "dificultate: "; in >> numar;
		switch (numar) {
		case 1:
			m.dificultate = Dificultate::usoara;
			break;
		case 2:
			m.dificultate = Dificultate::medie;
			break;
		case 3:
			m.dificultate = Dificultate::grea;
			break;
		}
		cout << endl << "comandantul misiunii: "; in >> m.comandant;

		cout << endl << "armament: ";
		in >> aux;
		m.armament = new char[strlen(aux) + 1];
		strcpy(m.armament, aux);


		return in;
	}

	friend ostream& operator<<(ostream& out, const Misiune& m) {
		out << "nume misiune: " << m.nume << ", locatie: " << m.locatie << ", data misiune: " << m.dataMisiune;
		out << ", a avut o dificultate ";
		switch (m.dificultate) {
		case 1:
			out<< "usoara";
			break;
		case 2:
			out << "medie";
			break;
		case 3:
			out << "grea";
			break;
		}
		out << "\nmisiunea a fost comandata de " << m.comandant;
		out << "\narmament: " << m.armament;

		return out;
	}

	friend ofstream& operator<<(ofstream& out, const Misiune& m) {
		out << "nume misiune: " << m.nume << ", locatie: " << m.locatie << ", data misiune: " << m.dataMisiune;
		out << ", a avut o dificultate ";
		switch (m.dificultate) {
		case 1:
			out << "usoara";
			break;
		case 2:
			out << "medie";
			break;
		case 3:
			out << "grea";
			break;
		}
		out << "\nmisiunea a fost comandata de " << m.comandant;
		out << "\narmament: " << m.armament;

		return out;
	}
};
# pragma endregion

void header();
void meniuPrincipal();
void meniuFisier();
void meniuIntern();
int meniuMilitar();
void meniuCivil();
void meniuInterogareDatabase();
void meniuInregistrareDatabase();


#pragma region meniuri

void meniuFisier(int alegere) {


	cout << "Optiuni: " << endl;

	cout << "1. Salvare in text" << endl;
	cout << "2. Salvare in binar" << endl;
	cout << "3. Salvare in CSV" << endl;





}

void meniuIntern() {
	cout << "	Selecteaza o categorie:" << endl;
	cout << "	1. Militar " << endl;
	cout << "	2. Civil " << endl;
	cout << "---------------------------" << endl;
	cout << "	9. <-- INAPOI " << endl;
	int alegere;
	cout << "Introduceti optiunea: ";
	cin >> alegere;
}

int meniuMilitar() {

	cout << "Selectati gradul: " << endl;

	cout << "I. OFITER" << endl;

	cout << "      1.SUBLOCOTENENT " << endl;
	cout << "      2.LOCOTENENT " << endl;
	cout << "      3.CAPITAN " << endl;
	cout << "      4.MAIOR " << endl;
	cout << "      5.LOCOTENENT COLONEL " << endl;
	cout << "      6.COLONEL " << endl;
	cout << "      6.GENERAL " << endl;

	cout << "II. SUBOFITER" << endl;

	cout << "      7.SERGENT" << endl;
	cout << "      8.SERGENT MAJOR " << endl;
	cout << "      9.PLUTONIER " << endl;
	cout << "      10.PLUTONIER MAJOR " << endl;
	cout << "      11.PLUTONIER ADJUTANT" << endl;
	cout << "      12.PLUTONIER PRINCIPAL" << endl;

	cout << "III. MAISTRU" << endl;

	cout << "      13.CLASA 5" << endl;
	cout << "      14.CLASA 4" << endl;
	cout << "      15.CLASA 3" << endl;
	cout << "      16.CLASA 2" << endl;
	cout << "      17.CLASA 1" << endl;
	cout << "      18.PRINCIPAL" << endl;
	cout << "---------------------------" << endl;
	cout << "	0. inapoi " << endl;

	int alegere;

	cout << "Introduceti optiunea: ";
	cin >> alegere;

	cout << alegere << endl;


	if (alegere >= 0 || alegere > 19) {
		if (alegere = 0) {
			system("CLS");
			meniuPrincipal();
		}
		meniuFisier(alegere);
		cout << "Alegerea este invalida!!" << endl << endl;
		meniuMilitar();
	}
	else cout << "Alegerea este invalida!!" << endl << endl;


	return alegere;

}

void meniuCivil() {
	//meniuFisier();

}

void header() {
	string user = "Ciprian";
	cout << "Buna ziua, " << user << " !" << endl;
}

void meniuPrincipal() {
	system("CLS");
	header ();
	int alegere;

	do {
		cout << "\nSelectati o optiune: " << endl;
		cout << "     1. Interogare database" << endl;
		cout << "     2. Inregistrare in database" << endl;
		cout << endl;
		cout << "     0.Exit" << endl;
		cout << "Introduceti optiunea: ";
		cin >> alegere;

		switch (alegere) {
		case 0: 
			exit(0);
			break;
		case 1: cout << "\n...INTEROGARE DATABASE..."<<endl;
			meniuInterogareDatabase();
			break;
		case 2: cout << "\n...INREGISTRARE IN DATABASE..."<<endl;
			meniuInregistrareDatabase();
			break;
		default:
			system("CLS");
			cout << "!! ALEGERE INVALIDA !!" << endl << endl;
			//meniuPrincipal();
		}

	} while(alegere >= 0);

}

#pragma endregion 

void meniuInterogareDatabase() {
	system("CLS");
	header();
	
	int opt;
	do {
		cout << endl;
		cout << "|-----------------------------------|" << endl;
		cout << "|       INTEROGARE DATABASE         |" << endl;
		cout << "|-----------------------------------|" << endl;
		cout << "| 1. Afisati toate inregistarile    |" << endl;
		cout << "| 2. Afisati inregistrar MILITARI   |" << endl;
		cout << "| 3. Afisati inregistrari CVIILI    |" << endl;
		cout << "|-----------------------------------|" << endl;
		cout << "  9. <-- INAPOI" << endl;
		cout << "  0. Exit" << endl;
		cout << endl;
		cout << "Selectati o optiune: " << endl;
		cin >> opt;
		switch (opt) {
		case 0:
			system("CLS");
			exit(0);
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 9:
			system("CLS");
			meniuPrincipal();
		default:
			cout << "Optiune indisponibila!!"<<endl;
		}
	} while(opt >= 0);
}

void meniuInregistrareDatabase() {
	system("CLS");
	header();
	
	int opt;
	do {
		cout << endl;
		cout << "|-----------------------------------|" << endl;
		cout << "|        INREGISTRARE DATE          |" << endl;
		cout << "|-----------------------------------|" << endl;
		cout << "| 1. Adaugati inregistrari MILITARI |" << endl;
		cout << "| 2. Adaugati inregistrari CVIILI   |" << endl;
		cout << "|-----------------------------------|" << endl;
		cout << "  9. <-- INAPOI" << endl;
		cout << "  0. Exit" << endl;
		cout << endl;
		cout << "Selectati o optiune: " << endl;
		cin >> opt;
		switch (opt) {
		case 0:
			system("CLS");
			exit(0);
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 9:
			system("CLS");
			meniuPrincipal();
		default:
			cout << "Optiune indisponibila!!" << endl;
		}
	} while (opt >= 0);
}



void main() {

#pragma region Testare-Membru
	//    Membru m1;
	//    cout << m1;
	//    try
	//    {
	//        m1.setLocatie("In");
	//    }
	//    catch (ExceptieMesaj ex)
	//    {
	//        cout << ex.getMesaj() << endl;
	//    }
	//    int lucrat[13];
	//    for (int i = 0; i < 13; i++) {
	//        lucrat[i] = 0;
	//    }
	//    m1.setPrezenta(2, 12);
	//    m1.setNume("Aelenei");
	//    m1.setPrenume("Ciprian");
	//    cout << m1.getNume() << " " << m1.getPrenume() << endl;
	//    Membru m2("Vasile", "Ion", "Bucuresti", 23, 1, 13, lucrat);
	//    m2.setPrezenta(m2.getNrZile() - 5, 12);
	//    m2.setLocatie("Brasov");
	//    cout << m2;
	//    Membru m3(m1);
	//    m3.setVarsta(21);
	//    m3.setPrezenta(1, 14);
	//    cout << m3;
	//    //cout << m3.getPrezenta(2)<<endl;
	//    /*Membru m4;
	//    cin >> m4;
	//    cout << m4;*/
	//    cout << m3[1] << endl;
	//    cout << m3.getPrezenta(1) << endl;
	//    cout << m1 << endl;
	//    cout << m2.getNrZile() << endl;
	//    m2 + 5;
	//    cout << m2.getNrZile() << endl;
	//    cout << m2 << endl;
	//    ++m2;
	//    cout << m2 << endl;
	//    cout << m2++;
	//    cout << m2 << endl;
	//
	//    string nume = m1;
	//    cout << "Nume: " << nume << endl;
	//
	//    m2.setPrezenta(m2.getNrZile(), 12);
	//    cout << m2;
	//    Membru m5 = !m2;
	//    cout << "Prezenta pentru m5 in ultima zi este: " << m5.getPrezenta(m5.getNrZile()) << endl;
	//
	//    bool compOre = m5 < m2;
	//    cout << "m5 are mai putine ore lucrate decat m2: " << compOre << endl;
	//    bool compVarsta = m2 == m5;
	//    cout << "m2 are aceeasi varsta cu m5: " << compVarsta << endl;
	//#pragma endregion;
	//
	//#pragma region Testare-Civil
	//    Civil c1;
	//    cout << c1;
	//    Civil c2(c1);
	//    cout << c2;
	//    Civil c3;
	//    //cin >> c3;
	//
	//    int interventie[] = { 23, 54, 12 };
	//    //Civil c4("Membr", 3, interventie);
	//    cout << c2.getAtributie();
	//    c2.setLuniVechime(13);
	//    cout << c2.getLuniVechime();
	//    c2.setPrezenta(1, 23);
	//    cout << c2;
	//
	//
	//    Subofiter s;
	//    cout << s;
	//    Subofiter s2 = s();
	//    cout << s2;
	//
	//    Militar militar;
	//    Militar militar2;
	//    Militar militar3;
	//    Militar militar4;
	//    cin >> militar4;
	//    cout << militar4;

	meniuPrincipal();




#pragma endregion;
}

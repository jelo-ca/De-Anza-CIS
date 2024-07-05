#include <iostream>
#include <string>
using namespace std;

class Cargo
{
private:
	string uld;
	string abbr;
	string uldid;
	int air;
	double wt;
	string dest;

public:
	//Default constructor
	Cargo();

	//Full constructor
	Cargo(const string uld, const string abbr, const string uldid, const int air, const double wt, const string dest);

	//Destructor
	~Cargo();

	//Mutators
	void setuld();
	void setabbr();
	void setuldid();
	void setair();
	void setwt();
	void setdest();

	//Accessors
	string getuld() const;
	string getabbr() const;
	string getuldid() const;
	int getair() const;
	double getwt() const;
	string getdest() const;

	void AssignCargo(Cargo&);
	void DeclareCargo(Cargo&);
};

Cargo::Cargo() {}

Cargo::Cargo(const string uld, const string abbr, const string uldid, const int air, const double wt, const string destination)
{
	this->uld = uld;
	this->abbr = abbr;
	this->uldid = uldid;
	this->air = air;
	this->wt = wt;
	this->dest = dest;
}

Cargo::~Cargo() {
	cout << "\nDestructor Called" << "\n------------------------------------------------" << endl;
}

//MUTATORS
void Cargo::setuld() {
	cout << "Please input Unit Type: ";
	cin >> this->uld;
}

void Cargo::setabbr() {
	cout << "Unit Abbreviation: ";
	cin >> this->abbr;
}

void Cargo::setuldid() {
	cout << "Unit ID: ";
	cin >> this->uldid;
}

void Cargo::setair() {
	cout << "Aircraft: ";
	cin >> this->air;
}

void Cargo::setwt() {
	cout << "Weight: ";
	cin >> this->wt;
}

void Cargo::setdest() {
	cout << "Destination: ";
	cin >> this->dest;
}

//ACCESSORS
string Cargo::getuld() const {
	return uld;
}

string Cargo::getabbr() const {
	return abbr;
}

string Cargo::getuldid() const {
	return uldid;
}

int Cargo::getair() const {
	return air;
}

double Cargo::getwt() const {
	return wt;
}

string Cargo::getdest() const {
	return dest;
}

void Cargo::AssignCargo(Cargo& cargo) {
	cargo.setuld();
	cargo.setabbr();
	cargo.setuldid();
	cargo.setair();
	cargo.setwt();
	cargo.setdest();
}

void Cargo::DeclareCargo(Cargo& cargo) {
	cout << "------------------------------------------------" <<
		"\nUnit Type: " << cargo.getuld() <<
		"\nAbbreviation: " << cargo.getabbr() <<
		"\nUnit ID: " << cargo.getuldid() <<
		"\nAircraft: " << cargo.getair() <<
		"\nWeight: " << cargo.getwt() <<
		"\nDestination: " << cargo.getdest() << endl;
}

int main() {

	Cargo* sampleCargo = new Cargo(); //Create Cargo obj w default constructor
	sampleCargo->DeclareCargo(*sampleCargo); //Output Default Constructor
	delete sampleCargo;

	Cargo* load = new Cargo(); //Create Cargo obj w default constructor
	load->AssignCargo(*load); //Use mutators to input data
	load->DeclareCargo(*load); //Output new contents of obj
	delete load;

	return 0;
}
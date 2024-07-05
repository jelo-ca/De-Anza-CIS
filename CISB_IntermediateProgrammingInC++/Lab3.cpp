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

	//Kilo to pound function
	friend double kilotopound(double kilograms);
};

//kg to lb function
double kilotopound(double kilograms) {
	return kilograms * 2.2;
}


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
	cout << "Destructor Called" << endl;
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
	string unit;

	cout << "Weight: ";
	cin >> this->wt;
	cout << "(kg/lb)?: ";
	cin >> unit;
	if (unit == "kg") {
		this->wt = this->wt * 2.2;
	}
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

void AssignCargo(Cargo& cargo) {
	cargo.setuld();
	cargo.setabbr();
	cargo.setuldid();
	cargo.setair();
	cargo.setwt();
	cargo.setdest();
}

void DeclareCargo(Cargo& cargo) {
	cout << "------------------------------------------------" <<
		"\nUnit Type: " << cargo.getuld() <<
		"\nAbbreviation: " << cargo.getabbr() <<
		"\nUnit ID: " << cargo.getuldid() <<
		"\nAircraft: " << cargo.getair() <<
		"\nWeight: " << cargo.getwt() << " lbs" <<
		"\nDestination: " << cargo.getdest() <<
		"\n------------------------------------------------" << endl;
}

int main() {

	Cargo* sampleCargo = new Cargo(); //Create Cargo obj w default constructor
	DeclareCargo(*sampleCargo); //Output Default Constructor


	Cargo* load = new Cargo(); //Create Cargo obj w default constructor
	AssignCargo(*load); //Use mutators to input data

	Cargo* copyLoad = load; //Creates COPY


	DeclareCargo(*load); //Output new contents of obj
	DeclareCargo(*copyLoad); //Outputs COPY

	delete sampleCargo;
	delete load;
	delete copyLoad;

	return 0;
}
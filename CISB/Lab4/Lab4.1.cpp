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

	//Copy constructor
	Cargo(const Cargo& other);

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

	//overload friend
	friend bool operator==(const Cargo& unit, const Cargo& other);
};

//kg to lb function
double kilotopound(double kilograms) {
	return kilograms * 2.2;
}

//overload operator
bool operator==(const Cargo& lhs, const Cargo& rhs) {
	return (lhs.abbr == rhs.abbr) && (lhs.uldid == rhs.uldid);
}


Cargo::Cargo() {
	uld = "XXX";
	abbr = "00000";
	uldid = "xxxxxIB";
	air = 700;
	wt = 0.0;
	dest = "NONE";
}

Cargo::Cargo(const string uld, const string abbr, const string uldid, const int air, const double wt, const string destination)
{
	this->uld = uld;
	this->abbr = abbr;
	this->uldid = uldid;
	this->air = air;
	this->wt = wt;
	this->dest = dest;
}

Cargo::Cargo(const Cargo& other) {
	this->uld = other.uld;
	this->abbr = other.abbr;
	this->uldid = other.uldid;
	this->air = other.air;
	this->wt = other.wt;
	this->dest = other.dest;
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


	Cargo unit1 = Cargo("Pallet", "PAG", "PAG32597IB", 737, 3321, "SEA"); //Create Cargo obj and loading the data
	//AssignCargo(*unit1); //Use mutators to input data

	Cargo unit2 = Cargo(unit1); //Creates COPY

	Cargo unit3 = Cargo(); //Create Cargo obj w default constructor


	DeclareCargo(unit3); //output default constructor

	DeclareCargo(unit1); //output new contents of obj
	DeclareCargo(unit2); //outputs copy


	if (unit1 == unit2)
		cout << "\nunit1 is the same as unit2 \n";
	else
		cout << " \nunit1 is not the same as unit2 \n";
	if (unit2 == unit3)
		cout << " \nunit2 is the same as unit3 \n";
	else
		cout << " \nunit2 is not the same as unit3\n";

	return 0;
}
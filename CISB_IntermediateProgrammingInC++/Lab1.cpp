#include <iostream>
using namespace std;

struct Cargo
{
	string uld;
	string abbr;
	string uldid;
	int air;
	double wt;
	string dest;
};

void AssignCargo(Cargo& cargo) {
	cout << "Please input Unit Type: ";
	cin >> cargo.uld;

	cout << "Unit Abbreviation: ";
	cin >> cargo.abbr;

	cout << "Unit ID: ";
	cin >> cargo.uldid;

	cout << "Aircraft: ";
	cin >> cargo.air;

	cout << "Weight: ";
	cin >> cargo.wt;

	cout << "Destination: ";
	cin >> cargo.dest;
}

void DeclareCargo(Cargo cargo) {
	cout << "\nUnit Type: " << cargo.uld <<
		"\nAbbreviation: " << cargo.abbr <<
		"\nUnit ID: " << cargo.uldid <<
		"\nAircraft: " << cargo.air <<
		"\nWeight: " << cargo.wt <<
		"\nDestination: " << cargo.dest;
}

int main() {

	Cargo* sampleCargo = new Cargo;

	AssignCargo(*sampleCargo);

	DeclareCargo(*sampleCargo);

	delete sampleCargo;

	return 0;
}
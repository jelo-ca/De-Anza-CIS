#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
double kilotopound(double kilograms)
{
    return kilograms * 2.2;
}

//overload operator
bool operator==(const Cargo& lhs, const Cargo& rhs)
{
    return ((lhs.abbr == rhs.abbr) && (lhs.uldid == rhs.uldid));
}

Cargo::Cargo() {}

Cargo::Cargo(const string uld, const string abbr, const string uldid, const int air, const double wt, const string dest)
{
    this->uld = uld;
    this->abbr = abbr;
    this->uldid = uldid;
    this->air = air;
    this->wt = wt;
    this->dest = dest;
}

//Copy constructor
Cargo::Cargo(const Cargo& other)
{
    this->uld = other.uld;
    this->abbr = other.abbr;
    this->uldid = other.uldid;
    this->air = other.air;
    this->wt = other.wt;
    this->dest = other.dest;
}

Cargo::~Cargo()
{
    cout << "Destructor Called" << endl;
}

//MUTATORS
void Cargo::setuld()
{
    cout << "Please input Unit Type: ";
    cin >> this->uld;
}

void Cargo::setabbr()
{
    cout << "Unit Abbreviation: ";
    cin >> this->abbr;
}

void Cargo::setuldid()
{
    cout << "Unit ID: ";
    cin >> this->uldid;
}

void Cargo::setair()
{
    cout << "Aircraft: ";
    cin >> this->air;
}

void Cargo::setwt()
{
    string unit;

    cout << "Weight: ";
    cin >> this->wt;
}

void Cargo::setdest()
{
    cout << "Destination: ";
    cin >> this->dest;
}

//ACCESSORS
string Cargo::getuld() const
{
    return uld;
}

string Cargo::getabbr() const
{
    return abbr;
}

string Cargo::getuldid() const
{
    return uldid;
}

int Cargo::getair() const
{
    return air;
}

double Cargo::getwt() const
{
    return wt;
}

string Cargo::getdest() const
{
    return dest;
}

// function to print cargo data
void DeclareCargo(const Cargo& cargo)
{
    cout << "------------------------------------------------" <<
        "\nUnit Type: " << cargo.getuld() <<
        "\nAbbreviation: " << cargo.getabbr() <<
        "\nUnit ID: " << cargo.getuldid() <<
        "\nAircraft: " << cargo.getair() <<
        "\nWeight: " << cargo.getwt() << " lbs" <<
        "\nDestination: " << cargo.getdest() <<
        "\n------------------------------------------------" << endl;
}

// function to read cargo data from a file
void AssignCargo()
{
    ifstream inputFile;
    string fileName, cargoString;

    cout << "Enter input file name: \n";
    cin >> fileName; //= "/uploads/cardata4.txt";

    inputFile.open(fileName);

    if (!inputFile.is_open())
    {
        cerr << "Unable to open file" << endl;
        exit(1);
    }

    while (getline(inputFile, cargoString))
    {
        istringstream cargoISS(cargoString);
        string type1, type2, abbr, uldid, dest;
        int plane;
        double weight;

        cargoISS >> type1;
        //Since combo flat is the only 2 word type, its the only one you have to check for
        if ((type1.compare("Combo")) == 0)
        {
            cargoISS >> type2 >> abbr >> uldid >> plane >> weight >> dest;
            type1 = type1 + " " + type2;
            if (!((type2.compare("Flat")) == 0))
            {
                cout << type2 << " bad unit name\n";
                continue;
            }
        }
        else
        {
            cargoISS >> abbr >> uldid >> plane >> weight >> dest;
        }

        Cargo temp(type1, abbr, uldid, plane, weight, dest);
        DeclareCargo(temp);
    }

    inputFile.close();
}



int main()
{
    AssignCargo();
    return 0;
}
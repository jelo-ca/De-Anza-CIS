#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdexcept>
using namespace std;

const int MAXLOAD737 = 46000;
const int MAXLOAD767 = 116000;

class Cargo
{
protected:
    string uld;
    string abbr;
    string uldid;
    int air;
    double wt;
    string dest;

public:
    // Default constructor
    Cargo();

    // Full constructor
    Cargo(const string uld, const string abbr, const string uldid, const int air, const double wt, const string dest);

    // Copy constructor
    Cargo(const Cargo &other);

    // Destructor
    ~Cargo();

    // Mutators
    void setuld();
    void setabbr();
    void setuldid();
    void setair();
    void setwt();
    void setdest();

    // Accessors
    string getuld() const;
    string getabbr() const;
    string getuldid() const;
    int getair() const;
    double getwt() const;
    string getdest() const;

    // Kilo to pound function
    friend double kilotopound(double kilograms);

    // overload friend
    friend bool operator==(const Cargo &unit, const Cargo &other);

    // virtual function
    virtual void maxweight(double &, double) = 0;
};

// -------------------------------------BOEING 737 -----------------------------
class Boeing737 : public Cargo
{
    using Cargo::Cargo;

private:
    int totwt737;

public:
    void maxweight(double &, double) override;
};

class Boeing767 : public Cargo
{
    using Cargo::Cargo;

private:
    int totwt767;

public:
    void maxweight(double &, double) override;
};

void load737(vector<Boeing737> &vectorptr737,
             const string type,
             const string abbr,
             const string uld,
             const int craft,
             const double wt,
             const string dest,
             double &totwt737)
{
    Boeing737 unitobj737(type, abbr, uld, craft, wt, dest);
    unitobj737.maxweight(totwt737, wt);
    vectorptr737.push_back(unitobj737);
}

void load767(vector<Boeing767> &vectorptr767,
             const string type,
             const string abbr,
             const string uld,
             const int craft,
             const double wt,
             const string dest,
             double &totwt767)
{
    Boeing767 unitobj767(type, abbr, uld, craft, wt, dest);
    unitobj767.maxweight(totwt767, wt);
    vectorptr767.push_back(unitobj767);
}

// MAXWEIGHT OVERRIDES
void Boeing737::maxweight(double &totwt737, double wt)
{
    if (totwt737 > MAXLOAD737)
    {
        totwt737 -= wt; /// remove if overweight
        throw runtime_error("too heavy for 737, removed\n\n");
    }
}

void Boeing767::maxweight(double &totwt767, double wt)
{
    if (totwt767 > MAXLOAD767)
    {
        totwt767 -= wt; /// remove if overweight
        throw runtime_error("too heavy for 767, removed\n\n");
    }
}

// kg to lb function
double kilotopound(double kilograms)
{
    return kilograms * 2.2;
}

// overload operator
bool operator==(const Cargo &lhs, const Cargo &rhs)
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

// Copy constructor
Cargo::Cargo(const Cargo &other)
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
    // cout << "Destructor Called" << endl;
}

// MUTATORS
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

// ACCESSORS
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
void DeclareCargo(const Cargo &cargo)
{
    cout << "------------------------------------------------"
         << "\nUnit Type: " << cargo.getuld() << "\nAbbreviation: " << cargo.getabbr() << "\nUnit ID: " << cargo.getuldid() << "\nAircraft: " << cargo.getair() << "\nWeight: " << cargo.getwt() << " lbs"
         << "\nDestination: " << cargo.getdest() << "\n------------------------------------------------" << endl;
}

//------------DATA VALIDATION FUNCTIONS------------------------
void checkType(string type1)
{
    if (type1 != "Container" && type1 != "Pallet")
        throw runtime_error(type1 + " Bad type, not Container, Pallet or Combo Flat\n");
}

void checkPlane(int air)
{
    if (air != 737 && air != 767)
        throw runtime_error((to_string(air)) + " " + " Bad plane type\n");
}

void checkAbbr(string type1, string abbr, int plane)
{
    if (plane == 737 && type1 == "Container" || type1 == "Pallet")
    {
        if (type1 == "Container" &&
            abbr != "AYF" &&
            abbr != "AYK" &&
            abbr != "AAA" &&
            abbr != "AYY")
            throw runtime_error(type1 + " " + abbr + " Bad type for 737\n");
    }
    if (plane == 767 && type1 == "Container" || type1 == "Pallette")
    {
        if ((type1 == "Container" || type1 == "Pallette") && abbr != "AKE" &&
            abbr != "APE" &&
            abbr != "AKC" &&
            abbr != "AQP" &&
            abbr != "AQF" &&
            abbr != "P1P" &&
            abbr != "AAP" &&
            abbr != "P6P")
            throw runtime_error(abbr + " bad type for 767\n\n");
    }
}

// Uses DeclareCargo to print according to plane
void vectorprint(vector<Boeing737> vectorptr737, vector<Boeing767> vectorptr767)
{
    for (int i = 0; i < vectorptr737.size(); i++)
    {
        cout << "\n737 unit # " << i + 1 << endl;
        DeclareCargo(vectorptr737[i]);
    }

    for (int i = 0; i < vectorptr767.size(); i++)
    {
        cout << "\n767 unit # " << i + 1 << endl;
        DeclareCargo(vectorptr767[i]);
    }
}

// function to read cargo data from a file
void AssignCargo()
{
    ifstream inputFile;
    string fileName, cargoString;

    double totwt737 = 0;
    double totwt767 = 0;
    vector<Boeing737> vectorptr737;
    vector<Boeing767> vectorptr767;
    string type1, type2, abbr, uldid, dest;
    int plane;
    double weight;

    do
    {
        try
        {
            cout << "Enter input file name: \n";
            getline(cin, fileName);

            inputFile.open(fileName);
            if (!inputFile)
                throw runtime_error(fileName + " file name not valid\n\n");
            cout << fileName << " is open\n\n";
        }
        catch (runtime_error &e)
        {
            cout << fileName << " " << e.what();
        }

    } while (!inputFile);

    while (getline(inputFile, cargoString))
    {
        try
        {
            istringstream cargoISS(cargoString);
            // Since combo flat is the only 2 word type, its the only one you have to check for
            cargoISS >> type1;
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
        }
        catch (runtime_error &e)
        {
            cout << e.what();
        }

        // Validate Data
        try
        {
            checkType(type1);  /// check for Container, Pallet
            checkPlane(plane); /// 737 or 767
            if (plane == 737)
            {
                checkAbbr(type1, abbr, plane);
                totwt737 += weight;
                load737(vectorptr737, type1, abbr, uldid, plane, weight, dest, totwt737);
            }
            if (plane == 767)
            {
                checkAbbr(type1, abbr, plane);
                totwt767 += weight;
                load767(vectorptr767, type1, abbr, uldid, plane, weight, dest, totwt767);
            }
        }
        catch (runtime_error &e)
        {
            cout << e.what();
        }
    }

    inputFile.close();

    vectorprint(vectorptr737, vectorptr767);
    cout << "737 total weight: " << totwt737 << endl;
    cout << "767 total weight: " << totwt767 << endl;
}

int main()
{
    AssignCargo();
    return 0;
}
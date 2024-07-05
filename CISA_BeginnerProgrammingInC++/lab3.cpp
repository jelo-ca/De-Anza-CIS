#include <iostream>;
#include <iomanip>;
#include <cstdlib>;
#include <ctime>;
using namespace std;

int main()
{
	// part 1
	int userAge;

	cout << "How old are you?" << endl;
	cin >> userAge;

	if (userAge < 10) {
		cout << "You are too young to watch a movie in this theater.";
	}
	else if (userAge >= 10 && userAge <= 17) {
		cout << "You have to be accompanied by an adult to enter.";
	}
	else {
		cout << "Feel free to enter.";
	}

	cout << endl;

	// part 2
	int userInt;
	int remainderSix;
	int remainderEight;

	cout << "Enter an integer.";
	cin >> userInt;

	remainderSix = userInt % 6;
	remainderEight = userInt % 8;

	if (remainderEight == 0 && remainderSix == 0) {
		cout << userInt << " is divisible by 6 and 8.";
	}
	else if (remainderEight == 0) {
		cout << userInt << " is divisible by 8."
	}
	else if (remainderSix == 0) {
		cout << userInt << " is divisible by 6."
	}
	else {
		cout << userInt << " is not divisible by 6 or 8."
	}

	cout << endl;
}
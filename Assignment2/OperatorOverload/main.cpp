#include <iostream>
using namespace std;

class Rational {
private:
	int numerator;
	int denominator;
	int wholeNumber = 0;
public:
	// Setter
	void setNumber(int tNumerator, int tDenominator, int tWholenumer = 0){
		numerator = tNumerator;
		denominator = tDenominator;
		wholeNumber = tWholenumer;
	}
	// Getters
	int getNumerator(){ return numerator; }
	int getDenominator() { return denominator; }
	int getWholeNumber() { return wholeNumber; }

	// operator overloads
	friend ostream& operator <<(ostream& os, Rational& rational);
	friend istream& operator >>(istream& is, Rational& rational);
	friend bool operator ==(Rational& firstRational, Rational& secondRational);
	friend bool operator <(const Rational& firstRational, const Rational& secondRational);
	friend bool operator >(const Rational& firstRational, const Rational& secondRational);
	friend bool operator <=(const Rational& firstRational, const Rational& secondRational);
	friend bool operator >=(const Rational& firstRational, const Rational& secondRational);
	friend const Rational operator +(Rational& firstRational, Rational& secondRational);
	friend const Rational operator -(Rational& firstRational, Rational& secondRational);
	friend const Rational operator *(Rational& firstRational, Rational& secondRational);
	friend const Rational operator /(Rational& firstRational, Rational& secondRational);
};

// Declare functions here
bool isInt(char i);
Rational normalize(int num, int den);
int gcd(int x, int y);
Rational makeWholeNumber(int num, int den);
Rational makeNonWholeNumber(int num, int den, int wholeNumber);

ostream& operator <<(ostream& os, Rational& rational) {		// Overload out stream
	// Assume that current saved numerator and denominator are integers and just print them in the correct format
	rational = makeWholeNumber(rational.numerator, rational.denominator);
	// If wholeNumber equals 0 then there's no need to print it with the fractions
	if(rational.wholeNumber == 0){
		if(rational.numerator == 0 && rational.denominator == 0){
			// Prints a 0 when numerator and denominator are 0
			os << 0;
		} else {
			//Prints just fractions
			os << rational.numerator << '/' << rational.denominator;
		}
	} else {
		// If num and den are the same the don't print them
		if (rational.numerator == rational.denominator){
			// Prints just whole number when numerator and denominator are equal
			os << rational.wholeNumber;
		} else {
			// This print the WholeNumber and fraction
			os << rational.wholeNumber << " " << rational.numerator << '/' << rational.denominator;
		}
	}
	rational = makeNonWholeNumber(rational.numerator, rational.denominator, rational.wholeNumber);
	return os;
}

istream& operator >>(istream& is, Rational& rational) {		//Overload the in stream
	string numerator;	// used to hold the numerator when taking characters of the input stream
	char buffer;		// holds the character that's current;y being operated on
	string denominator;	// holds the value of the denominator
	while(true){
		// Only breaks when fraction sign is seen
		is >> buffer;
		if(buffer == '/') {
			if(numerator == ""){	// If fraction sign is found but nothing is stored in numerator then return error
				cout << "Error, you need to enter a number before the fraction sign. Exiting...";
				exit(1);
			}
			break;
		} else if(buffer == '-'){
			// Add buffer to numerator
			numerator += buffer;
		} else if(isInt(buffer)){
			// Add buffer to numerator
			numerator += buffer;
		} else {
			cout << "That was not a valid input, Please fix the numerator\n";
			exit(1);
		}
	}

	// This loads the rest of the input stream into the denominator
	is >> denominator;

	// loop through the characters in the denominator to verify every char
	for(int i=0; i<denominator.length(); i++){
		if(!isInt(denominator[i])){			// if not an int then enter this block
			if(denominator[i] == '-'){
				// do nothing if negative because that's ok
			} else {
				cout << "That was not a valid input, Please fix the denominator\n";
				exit(1);
			}
		}
	}

	rational.setNumber(stoi(numerator), stoi(denominator));
	rational = normalize(rational.numerator, rational.denominator);
	return is;
}

bool operator ==(Rational& firstRational, Rational& secondRational){
	//   (a/b == c/d) when (a*d == c*b)
	int temp1;
	int temp2;
	temp1 = firstRational.getNumerator() * secondRational.getDenominator();
	temp2 = firstRational.getDenominator() * secondRational.getNumerator();

	return temp1 == temp2;
}
bool operator <(const Rational& firstRational, const Rational& secondRational){
	//		(a/b < c/d) when (a*d < c*b)
	int temp1;
	int temp2;
	temp1 = firstRational.numerator * secondRational.denominator;
	temp2 = firstRational.denominator * secondRational.numerator;

	return temp1 < temp2;
}
bool operator >(const Rational& firstRational, const Rational& secondRational){
	//		(a/b > c/d) when (a*d > c*b)
	int temp1;
	int temp2;
	temp1 = firstRational.numerator * secondRational.denominator;
	temp2 = firstRational.denominator * secondRational.numerator;

	return temp1 > temp2;
}
bool operator <=(const Rational& firstRational, const Rational& secondRational){
	//		(a/b <= c/d) when (a*d <= c*b)

	int temp1;
	int temp2;
	temp1 = firstRational.numerator * secondRational.denominator;
	temp2 = firstRational.denominator * secondRational.numerator;

	return temp1 <= temp2;
}
bool operator >=(const Rational& firstRational, const Rational& secondRational){
	//		(a/b >= c/d) when (a*d >= c*b)
	int temp1;
	int temp2;
	temp1 = firstRational.numerator * secondRational.denominator;
	temp2 = firstRational.denominator * secondRational.numerator;

	return temp1 >= temp2;
}
const Rational operator +(Rational& firstRational, Rational& secondRational){
	Rational rational;
	// First find common denominator
	int commonDen = firstRational.getDenominator() * secondRational.getDenominator();
	// Find new numerators
	int firstNumerator = firstRational.getNumerator() * secondRational.getDenominator();
	int secondNumerator = secondRational.getNumerator() * firstRational.getDenominator();
	// we can add numerators now and use common denominator
	rational.setNumber(firstNumerator + secondNumerator, commonDen);

	rational = normalize(rational.getNumerator(), rational.getDenominator());
	return rational;
}
const Rational operator -(Rational& firstRational, Rational& secondRational){
	Rational rational;
	if(firstRational.getNumerator() == secondRational.getNumerator() &&
	   firstRational.getDenominator() == secondRational.getDenominator()){
		// If both fractions are the same then the result is zero
		rational.setNumber(0,0,0);
		return rational;
	}

	// First find common denominator
	int commonDen = firstRational.getDenominator() * secondRational.getDenominator();
	// Find new numerators
	int firstNumerator = firstRational.getNumerator() * secondRational.getDenominator();
	int secondNumerator = secondRational.getNumerator() * firstRational.getDenominator();
	// we can add numerators now and use common denominator
	rational.setNumber(firstNumerator - secondNumerator, commonDen);
	rational = normalize(rational.getNumerator(), rational.getDenominator());

	return rational;
}
const Rational operator *(Rational& firstRational, Rational& secondRational){
	// Just multiply the numerators together and denominators together
	Rational rational;
	int num = firstRational.getNumerator() * secondRational.getNumerator();
	int den = firstRational.getDenominator() * secondRational.getDenominator();
	rational = normalize(num, den);
	rational.setNumber(rational.getNumerator(), rational.getDenominator());
	return rational;
}
const Rational operator /(Rational& firstRational, Rational& secondRational){
	// Begin calculations
	Rational rational;
	//To divide we flip the second fraction then multiply

	int num = firstRational.getNumerator() * secondRational.getDenominator();
	int den = firstRational.getDenominator() * secondRational.getNumerator();
	rational.setNumber(num, den);
	rational = normalize(num, den);

	return rational;
}

Rational normalize(int num, int den){		//This function reduces the fractions
	Rational rational;

	// if bot num and den are zero then we want to return zero to avoid divide by zero errors
	if(num == 0 || den == 0){
		rational.setNumber(0, 0);
		return rational;
	}

	bool isNeg = false;
	if(num < 0){
		//numerator is negative
		isNeg = true;
		num = -1 * num; 		//Make positive for calculations
	}
	if(den < 0){
		// denominator is negative
		// Use the opposite of Negative flag because it could already be true and if both
		// num and den are negative then our rational is positive
		isNeg = !isNeg;
		den = -1 * den;		// Make positive for calculations
	}

	if(den != 0) {
		//Avoid divide by zero errors
		int gcdValue = gcd(num, den);
		// If GCD it more than 1 then we can reduce
		if (gcdValue > 1) {
			num = num / gcdValue;
			den = den / gcdValue;
		}
	}

	if(isNeg){ num = num * -1; }		// Makes num negative
	rational.setNumber(num, den);
	return rational;

}

Rational makeWholeNumber(int num, int den){	// find the fraction with wholeNumber
	Rational rational;
	int wholeNumber = 0;

	//if numerator and denominator are zero then return all zeros
	if(num == 0 && den == 0){
		rational.setNumber(0,0,0);
		return rational;
	}
	// if num and den are equal then no need to continue, set wholeNumber to 1 and return
	if(abs(num) == abs(den)){
		if(num < 0){
			rational.setNumber(0,0,-1);
		} else {
			rational.setNumber(0, 0, 1);
		}
		return rational;
	}

	// If numerator is more than denominator then we have a whole number
	if(num > den){
		//find the whole number
		float notWholeNumber = (float)num / den;
		wholeNumber = num / den;

		if(wholeNumber == notWholeNumber){  // if the float of the divisor is equal to the int then there nothing left todo
			rational.setNumber(0,0,wholeNumber);
			return rational;
		}
		num = num - (wholeNumber * den);
		rational.setNumber(num, den, wholeNumber);
		return rational;
	}

	//Only reaches here if Fraction is already in whole form
	rational.setNumber(num, den, 0);
	return rational;
}

Rational makeNonWholeNumber(int num, int den, int wholeNumber){	// find the fraction with wholeNumber being zero for calculations
	Rational rational;
	// if both are zero then take a whole unit and put it into the fraction so we aren't multiplying by zero
	if(num == 0 && den == 0){
		wholeNumber -= 1;
		num = 1;
		den = 1;
	}

	// find the new numerator
	num = (den * wholeNumber) + num;
	rational.setNumber(num, den, 0);

	return rational;
}

bool isInt(char i){		// Function to check if character is a integer (return true) if not then (returns false)
	//checks the ASCII value from 0-9
	if((i <= 57) && (i >= 48)) {
		return true;
	} else {
		return false;
	}
}

int gcd( int x, int y )		// Function to find the GCD used in the normalize function
{
	if( x < y )
		return gcd( y, x );

	int f = x % y;
	if( f == 0 )
		return y;
	else
		return gcd( y, f );
}

// Main function for the program
int main( ) {
	Rational firstRational;
	Rational secondRational;

	// Prompt user for first rational number, then print actual saved number
	cout << "Please enter a rational in the format [number]/[number]: ";
	cin >> firstRational;
	cout << "Saving rational number as:\n";
	cout << firstRational << "\n";

	// Prompt user for second rational number, then print the actual saved number
	cout << "Please enter a second rational to compare it to in the format [number]/[numer]: ";
	cin >> secondRational;
	cout << "Saving rational number as:\n";
	cout << secondRational << "\n";

	cout << "\n\nBeginning Calculations:\n\n";

	// Setup temp bool for operations
	bool temp;
	temp = firstRational == secondRational;
	cout << firstRational << " == " << secondRational << " :  " << boolalpha << temp << "\n";

	temp = firstRational < secondRational;
	cout << firstRational << " <  " << secondRational << " :  " << boolalpha << temp << "\n";

	temp = firstRational <= secondRational;
	cout << firstRational << " <= " << secondRational << " :  " << boolalpha << temp << "\n";

	temp = firstRational > secondRational;
	cout << firstRational << " >  " << secondRational << " :  " << boolalpha << temp << "\n";

	temp = firstRational >= secondRational;
	cout << firstRational << " >= " << secondRational << " :  " << boolalpha << temp << "\n";

	// Start operations
	cout << "\n";

	// Init a tmepRational number for calculations
	Rational tempRational;
	tempRational = firstRational + secondRational;
	cout << firstRational << " + " << secondRational << " :  " << tempRational << "\n";

	tempRational = firstRational - secondRational;
	cout << firstRational << " - " << secondRational << " :  " << tempRational << "\n";

	tempRational = firstRational * secondRational;
	cout << firstRational << " * " << secondRational << " :  " << tempRational << "\n";

	tempRational = firstRational / secondRational;
	cout << firstRational << " / " << secondRational << " :  " << tempRational << "\n";


	return 0;
}


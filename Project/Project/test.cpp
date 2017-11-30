#include "test.h"
#include <iostream>
#include "QwintoScoresheet.h"

using namespace std;


int main()


{

	QwintoScoreSheet test;
	cout << "Player Name :" << "Ahmed Gabtni" << '\t' << '\t' << "Points: " << "128" << endl;
	cout << '\t' + '\t' + '\t' << "-------------------------------------" << endl;

	cout << "Red " << '\t' + '\t'+ '\t' << test.redRow;
	cout << '\t' + '\t'  << "-------------------------------------" << endl;
	cout << "Yellow " << '\t'+ '\t' << test.yellowRow;

	cout << '\t' << "-------------------------------------" << endl;

	cout << "Blue " << '\t' << test.blueRow;

	cout << '\t' << "-------------------------------------" << endl;

	cout << "Failed Throw:";

	return 0;
}
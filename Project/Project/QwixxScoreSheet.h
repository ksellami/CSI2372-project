#pragma once
#include "scoresheet.h"
#include "QwixxRow.h"
#include "Colour.h"
#include <list>

class QwixxScoreSheet : public ScoreSheet
{
	QwixxRow<std::vector<int>, Colour::RED> redRow; 
	QwixxRow<std::vector<int>, Colour::YELLOW> yellowRow;
	QwixxRow<std::list<int>,Colour::GREEN> greenRow;
	QwixxRow<std::list<int>, Colour::BLUE> blueRow;

public:

	QwixxScoreSheet(string name); 
	int calcTotal();
	bool operator ! ();
	friend ostream& operator<<(ostream& os, const QwixxScoreSheet& dt);

protected:
	bool validate(Colour&, int&);


};


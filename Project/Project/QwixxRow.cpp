#include "QwixxRow.h"

template<class T, Colour col>
QwixxRow<T,col>& operator+=(QwixxRow<T,col>& rw,const RollOfDice & rod)
{
	Row += rod; 
	return this; 
}

template<class T, Colour col>
bool QwixxRow<T, col>::validateEntry(int &)
{
	return false;
}

template<class T, Colour col>
int & QwixxRow<T, col>::operator[](int param)
{
	return Row[param];
}

template<class T, Colour col>
ostream & operator<<(ostream & os, QwixxRow<T, col>& pRow)

	{
		if (col == Colour::RED)
		{
			os << "  " << "| " << pRow.Row[0] << "| " << pRow.Row[1] << "| " << pRow.Row[2] << "| " << pRow.Row[3] << "| " << pRow.Row[4]
				<< "| " << pRow.Row[5] << "| " << pRow.Row[6] << "| " << pRow.Row[7] << "| " << pRow.Row[8] << "| " << pRow.Row[9] << "| " << pRow.Row[10] << "| ";

		}
		else if (col == Colour::YELLOW)
		{
			os << "  " << "| " << pRow.Row[0] << "| " << pRow.Row[1] << "| " << pRow.Row[2] << "| " << pRow.Row[3] << "| " << pRow.Row[4]
				<< "| " << pRow.Row[5] << "| " << pRow.Row[6] << "| " << pRow.Row[7] << "| " << pRow.Row[8] << "| " << pRow.Row[9] << "| " << pRow.Row[10] << "| ";

		}
		else if (col == Colour::GREEN)
		{
			os << "  " << "| " << pRow.Row[10] << "| " << pRow.Row[9] << "| " << pRow.Row[8] << "| " << pRow.Row[7] << "| " << pRow.Row[6]
				<< "| " << pRow.Row[5] << "| " << pRow.Row[4] << "| " << pRow.Row[3] << "| " << pRow.Row[2] << "| " << pRow.Row[1] << "| " << pRow.Row[0] << "| ";

		}
		else if (col == Colour::BLUE)
		{
			os << "  " << "| " << pRow.Row[10] << "| " << pRow.Row[9] << "| " << pRow.Row[8] << "| " << pRow.Row[7] << "| " << pRow.Row[6]
				<< "| " << pRow.Row[5] << "| " << pRow.Row[4] << "| " << pRow.Row[3] << "| " << pRow.Row[2] << "| " << pRow.Row[1] << "| " << pRow.Row[0] << "| ";
		}

		return os;
}

template<class T, Colour col>
QwixxRow<T, col>::QwixxRow()
{
	for (int i = 0, i < Row.max_size(), i++)
		Row[i] = i + 2;
}
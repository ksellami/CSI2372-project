#include "RandomDice.h"

uint32 RandomDice::DrawNumber(uint32 min, uint32 max)
{
	return std::uniform_int_distribution<uint32>{min, max}(eng);
}

#include <iostream>
#include <random>

using uint32 = unsigned int;
class RandomDice {
public:
	RandomDice() = default;
	RandomDice(std::mt19937::result_type seed) : eng(seed) {}
	uint32 DrawNumber(uint32 min, uint32 max);

private:
	std::mt19937 eng{ std::random_device{}() };
};


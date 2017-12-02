#include "Player.h"

void Player::setActive(bool param)
{
	isActive = param; 
}

bool Player::isOrNotActive()
{
	return isActive;
}

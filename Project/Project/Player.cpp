#include "Player.h"

void Player::setActive(bool param)
{
	statut = param; 
}

bool Player::isActive()
{
	return statut;
}

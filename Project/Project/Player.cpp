#include "Player.h"

void Player::setActive(bool param) // modify the statut of the player
{
	statut = param; 
}

bool Player::isActive() // return the statut of the player
{
	return statut;
}

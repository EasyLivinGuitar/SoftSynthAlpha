#include "player.hpp"

Player::Player(std::string filename):
filename_(filename)
{
	engine_=irrklang::createIrrKlangDevice();
}

void Player::play() const
{
	engine_->play2D("audio/osc_test.wav", true);
}
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <irrKlang.h>
#include <string>

class Player
{
	public:
		Player(std::string filename);
		~Player();

		void play() const;
	private:
		irrklang::ISoundEngine* engine_;
		std::string filename_;
};

#endif
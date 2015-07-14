#ifndef DELAY_HPP
#define DELAY_HPP

#include "settings.hpp"

#include "sfx.hpp"
#include <iostream>

class Delay : public SFX
{
	public:
		Delay(float pre_delay, float decay_time);

		void proceed();
	private:
		float delay_time_;
		float decay_;

};

#endif
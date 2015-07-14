#ifndef OSCILLATOR_HPP
#define OSCILLATOR_HPP

#include "settings.hpp"

#include "sfx.hpp"

#include <math.h>
#include <vector>
#include <iostream>

#define PI 3.14
#define PITCH_CORRECT 568.181818
#define FOURIER_PARAM 200

class Oscillator
{
	public:
		Oscillator();
		Oscillator(std::vector<float> const& wave);
		Oscillator(Oscillator* const& osc);

		void setSinWave(float amplitude, float frequency, float phase_offset);
		void setSawWave(float amplitude, float frequency);
		void setSquareWave(float amplitude, float frequency);
		void setTriangleWave(float amplitude, float frequency);

		float* getWaveArray() const;
		std::vector<float> getWaveVector() const;

		void insertSFX(SFX* const& sfx);

	private:
		std::vector<float> wave_;

		void setWave(std::vector<float> const& wave);
};

Oscillator operator+(Oscillator const& lhs, Oscillator const& rhs);
#endif
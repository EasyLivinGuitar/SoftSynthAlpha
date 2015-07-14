#include "sfx.hpp"

std::vector<float> SFX::getWaveVector() const
{
	return wave_;
}

void SFX::setWave(std::vector<float> const& wave)
{
	wave_=wave;
}

float* SFX::getWaveArray() const
{
	float wave[wave_.size()];

	for(int i=0; i<wave_.size()-1; i++)
	{
		wave[i]=wave_[i];
	}

	return wave;
}
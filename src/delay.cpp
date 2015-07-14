#include "delay.hpp"

Delay::Delay(float delay_time, float decay):
delay_time_(delay_time),
decay_(decay)
{}

void Delay::proceed()
{
	std::cout<<"Setting delay...";
	const int pre_samples=delay_time_ * SAMPLE_RATE;

	if(pre_samples < wave_.size())
	{
		for (int i=0; i < wave_.size() - pre_samples; i++)
		{
				wave_[i+pre_samples]+= wave_[i] * decay_;
		} 
	}
	std::cout<<"Done.\n";
}
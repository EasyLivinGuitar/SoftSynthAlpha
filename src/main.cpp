#include <iostream>

#include "settings.hpp"

#include "wave_writer.hpp"
#include "oscillator.hpp"
#include "player.hpp"
#include "delay.hpp"

int main()
{
	std::cout<<"\n================\n=SOFTSYNTHALPHA=\n================\n \n";

	// Oscillator* osc0=new Oscillator();
	// osc0->setSinWave(0.1, 110, 0);

	// Oscillator* osc1=new Oscillator();
	// osc1->setSinWave(0.2, 440.0, 0);
	
	// Oscillator* osc2=new Oscillator();
	// osc2->setSinWave(0.1, 523.251, 0);

	// Oscillator* osc3=new Oscillator();
	// osc3->setSinWave(0.05, 659.255, 0);

	Oscillator* osc4=new Oscillator();
	osc4->setTriangleWave(0.2, 440.0f);

	// osc4->insertSFX(new Delay(0.3f, 0.8f));

	WaveWriter* wave_writer = new WaveWriter(osc4->getWaveArray());
	wave_writer->write();

}
#ifndef WAVE_WRITER_HPP
#define WAVE_WRITER_HPP

#include "settings.hpp"

#include <stdio.h>
#include <iostream>

class WaveWriter
{
	public:
		WaveWriter(float* wave);
		~WaveWriter();

		void write();
	private:
		uint8_t header_[58];
		
		float *wave_;

		void createHeader();
		void write4CC(unsigned int value, unsigned int index);
		void write4Bytes(unsigned int value, unsigned int index);
		void write2Bytes(unsigned int value, unsigned int index);

};

#endif
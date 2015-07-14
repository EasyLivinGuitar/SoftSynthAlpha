#include "wave_writer.hpp"

WaveWriter::WaveWriter(float* wave):
wave_(wave)
{}

void WaveWriter::write()
{
	createHeader();

	FILE *wav_file;
	wav_file = fopen("audio/osc_test.wav", "wb");

	if(wav_file)
	{
		std::cout<<"Writing header...";
		fwrite(header_, 1, sizeof(header_), wav_file);
		std::cout<<"Done\nWriting wave...";
		fwrite(wave_, sizeof(*wave_), SAMPLE_RATE*PLAY_LENGTH, wav_file);
		std::cout<<"Done\n";
		fclose(wav_file);
	}
} 

void WaveWriter::createHeader()
{
	std::cout<<"Creating Header...";
	const unsigned int num_channels = 1;
	const unsigned int bytes_per_sample = 4;
	const unsigned int chunk_length = SAMPLE_RATE * PLAY_LENGTH * bytes_per_sample;

	write4CC('RIFF', 0); //File description header
	write4Bytes(4 + 26 + 12 + 8 + chunk_length, 4); //size of file
	write4CC('WAVE', 8); //WAV description header
	write4CC('fmt ', 12); //Format description header
	write4Bytes(18, 16); //Size of Wave section chunck
	write2Bytes(0x0003 ,20); //WAVE type format
	write2Bytes(num_channels, 22); //number of channels
	write4Bytes(SAMPLE_RATE, 24); //saples per second
	write4Bytes(SAMPLE_RATE * bytes_per_sample * num_channels, 28); // bytes oer second
	write2Bytes(num_channels * bytes_per_sample, 32); //block alignment
	write2Bytes(bytes_per_sample * 8, 34); //bits per sample
	write2Bytes(0, 36); 
	write4CC('fact', 38);
	write4Bytes(4, 42);
	write4Bytes(num_channels * PLAY_LENGTH * SAMPLE_RATE, 46);
	write4CC('data', 50); //data description header
	write4Bytes(PLAY_LENGTH * SAMPLE_RATE * num_channels * bytes_per_sample, 54); //size of data
	std::cout<<"Done\n";
}

void WaveWriter::write4CC(uint32_t value, unsigned int index)
{
	header_[index] = value >> 24;
	index++;
	header_[index] = value >> 16;
	index++;
	header_[index] = value >> 8;
	index++;
	header_[index] = value;
}

void WaveWriter::write4Bytes(uint32_t value, unsigned int index)
{
	header_[index] = value;
	index++;
	header_[index] = value >> 8;
	index++;
	header_[index] = value >> 16;
	index++;
	header_[index] = value >> 24;
}

void WaveWriter::write2Bytes(uint32_t value, unsigned int index)
{
	header_[index] = value;
	index++;
	header_[index] = value >> 8;
}
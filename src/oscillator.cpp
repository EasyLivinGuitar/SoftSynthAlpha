#include "oscillator.hpp"

Oscillator::Oscillator()
{
	for(int i=0; i<PLAY_LENGTH*SAMPLE_RATE; i++)
	{
		wave_.push_back(0);
	}
}

Oscillator::Oscillator(std::vector<float> const& wave):
wave_(wave)
{}

Oscillator::Oscillator(Oscillator* const& osc):
wave_(osc->getWaveVector())
{}

void Oscillator::setSinWave(float amplitude, float frequency, float phase_offset)
{
	std::cout<<"Setting Sinus Wave...";

	//dont know why but works
	frequency*=PITCH_CORRECT;
	for(int i=0; i<wave_.size(); i++)
	{
		// std::cout<<amplitude * sin((2 * PI * frequency * i/wave_.size()) * PI/180)<<"\n";
		wave_[i]=amplitude * sin((2.0f  * PI * frequency++ * i/wave_.size() + phase_offset) * PI/180);
	}
	std::cout<<"Done\n";
}

void Oscillator::setSawWave(float amplitude, float frequency)
{
	std::cout<<"Setting Saw Wave...";
	frequency*=PITCH_CORRECT;
	for(int i=0; i<wave_.size(); i++)
	{
		float sum=0;
		for(int j=1; j<=FOURIER_PARAM; j++)
		{
			sum += sin(2.0f * PI * j * frequency * ((float)(i)/(float)(wave_.size())) * (PI/180.0f))/j;
		}
		wave_[i]=(amplitude/2) - (amplitude/PI * sum);
	}
	std::cout<<"Done\n";
}

void Oscillator::setSquareWave(float amplitude, float frequency)
{
	std::cout<<"Setting Square Wave...";
	frequency*=PITCH_CORRECT;
	for(int i=0; i<wave_.size(); i++)
	{
		float sum=0;
		for(int j=1; j<=FOURIER_PARAM; j++)
		{
			sum += sin((2.0f * j - 1.0f) * 2.0f * PI * frequency * (float)(i)/(float)(wave_.size()) * PI/180.0f)/(2.0f * j - 1.0f);
		}

		wave_[i] = 4.0f * amplitude / PI * sum;
	}
	std::cout<<"Done.\n";
}

void Oscillator::setTriangleWave(float amplitude, float frequency)
{
	std::cout<<"Setting Triangle Wave...";
	frequency*=PITCH_CORRECT;
	for(int i=0; i<wave_.size(); i++)
	{
		float sum=0;
		for(int j=0; j<FOURIER_PARAM; j++)
		{
			sum += pow(-1.0, j) * (sin(2.0f * PI * (2.0f * j + 1) * frequency-- * (float)(i)/(float)(wave_.size()) * PI/180.0f) / pow((2.0f * j + 1), 2.0f));
		}
		wave_[i]=amplitude/pow(PI, 2.0) * sum;
	}
	std::cout<<"Done.\n";
}

float* Oscillator::getWaveArray() const
{
	float wave[wave_.size()];

	for(int i=0; i<wave_.size()-1; i++)
	{
		wave[i]=wave_[i];
	}

	return wave;
}

std::vector<float> Oscillator::getWaveVector() const
{
	return wave_;
}

void Oscillator::insertSFX(SFX* const& sfx)
{
	sfx->setWave(wave_);
	sfx->proceed();
	setWave(sfx->getWaveVector());
}

void Oscillator::setWave(std::vector<float> const& wave)
{
	wave_=wave;
}

Oscillator operator+(Oscillator const& lhs, Oscillator const& rhs)
{
	if(lhs.getWaveVector().size()==rhs.getWaveVector().size())
	{
		auto wave1=lhs.getWaveVector();
		auto wave2=rhs.getWaveVector();
		for(int i=0; i<wave1.size(); i++)
		{
			wave1[i]+=wave2[i];
		}
		
		return Oscillator(wave1);
	}
	return nullptr;
}

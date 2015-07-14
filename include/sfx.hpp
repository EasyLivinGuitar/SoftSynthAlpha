#ifndef SFX_HPP
#define SFX_HPP

#include <vector>

class SFX
{
	public:
		virtual void proceed()=0;

		void setWave(std::vector<float> const& wave);

		std::vector<float> getWaveVector() const;
		float* getWaveArray() const;
	protected:
		std::vector<float> wave_;
};

#endif
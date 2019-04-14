#pragma once
#include <array>

namespace bom
{
	class ToneArray
	{
	protected:
		const std::array<double, 7> tones = { 0.0, 2.0, 4.0, 5.0, 7.0, 9.0, 11.0 };

	public:
	};

	class BasicTone
	{
	protected:
		const std::array<double, 12> tones = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0 };

	public:
	};
}
#include "timer.hpp"

// sets the id gen to 1 without this the entire class breaks.
int Timer::idGen = 1;

/*
\param Name of timer (std::string)
\brief starts the timer at the point the function was called.
*/
void Timer::start(std::string opName)
{
	timerName = opName;
	m_start = clock::now();
}

Timer& Timer::reset() { m_start = clock::now(); return *this; }

double Timer::elapsed() const
{
	return std::chrono::duration_cast<seconds>(clock::now() - m_start).count();
}

Timer& Timer::result()
{
	if (timerName.empty())
		timerName = "Timer #" + std::to_string(timerID);

	std::cout << timerName << ' ' << elapsed() << std::endl;

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Timer& timer)
{
	std::string timerName = timer.timerName;

	if (timer.timerName.empty())
		timerName = "Timer #" + std::to_string(timer.timerID);

	return out << timerName << ' ' << timer.elapsed();
}
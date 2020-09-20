#pragma once

#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <iostream>

class Timer
{

private:

	using clock = std::chrono::high_resolution_clock;
	using seconds = std::chrono::duration<double, std::ratio<1>>;

	std::string timerName;
	static int idGen;
	int timerID;

	std::chrono::time_point<clock> m_start;

public:

	// function paramter sets the timer name to empthy as a default so the result function can set a nameless timer to operation time
	Timer(std::string timerName = "") : m_start(clock::now())
	{
		this->timerName = timerName;
		timerID = idGen++;
	}

	/*
	*\param Optional Name of timer (std::string)
	*\brief starts the timer at the point the function was called.
	*/
	void start(std::string opName = "");

	/*
	\brief Resets the timer
	*/
	Timer& reset();

	/*
	\brief time passed since timer was started
	*/
	double elapsed() const;

	/*
	\brief Prints the timer results to the console with the timer name
	*/
	Timer& result();

	friend std::ostream& operator<<(std::ostream& out, const Timer& timer);

};


#endif


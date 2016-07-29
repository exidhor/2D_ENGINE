/*!
 * \brief TODO
 * \file Timer.cpp
 * \author Exidhor
 * \version 0.1
 * \date 2016-07-29
 */
#include "Modules/Utilities/Timer.hpp"

Timer::Timer(double newStartTime)
{
	m_startTime = newStartTime;
	m_timeLeft = m_startTime;
}

bool Timer::removeTime(double timeToRemove)
{
	m_timeLeft -= timeToRemove;
	if (m_timeLeft <= 0)
	{
		return true;
	}
	return false;
}

void Timer::restart(double newStartTime)
{
	m_timeLeft = newStartTime;
}

void Timer::setStartTime(double newStartTime)
{
	m_startTime = newStartTime;
	m_timeLeft = m_startTime;
}

double Timer::getStartTime() const
{
	return m_startTime;
}

void Timer::restart()
{
	m_timeLeft = m_startTime;
}

void Timer::softRestart()
{
	m_timeLeft += m_startTime;

	if (m_timeLeft <= 0)
	{
		m_timeLeft = m_startTime;
	}
}

double Timer::getTimeLeft() {
	return m_timeLeft;
}
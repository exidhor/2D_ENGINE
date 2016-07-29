/*!
 * \brief TODO
 * \file Timer.hpp
 * \author Exidhor
 * \version 0.1
 * \date 2016-07-29
 */

#ifndef DEF_TIMER_HPP
#define DEF_TIMER_HPP

#include <iostream>
#include "Modules/ModConfig.hpp"

/*! \class Timer
 * \brief Used to time time spent
 *        It decrements and reset with the time passed
 *        during the construction.
 */
class UTILITIES_API Timer
{
public:

	/*!
	 * \brief TODO
	 * \param TODO
	 * \return TODO
	 */
	Timer(double startTime);

	/*!
	 * \brief TODO
	 * \param TODO
	 * \return TODO
	 */
	bool removeTime(double timeToRemove);

	/*!
	 * \brief TODO
	 * \param TODO
	 */
	void restart(double newStartTime);

	/*!
	 * \brief TODO
	 */
	void restart();

	/*!
	 * \brief TODO
	 */
	void softRestart();

	/*!
	 * \brief TODO
	 * \param TODO
	 */
	void setStartTime(double newStartTime);

	/*!
	 * \brief TODO
	 * \return TODO
	 */
	double	getStartTime() const;

	/*!
	 * \brief TODO
	 * \return TODO
	 */
	double	getTimeLeft();

private:
	double m_startTime;
	double m_timeLeft;
};

#endif // DEF_TIMER_HPP
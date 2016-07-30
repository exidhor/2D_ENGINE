/*!
 * \brief Unit test of class timer
 * \file TimerUnitTest.cpp
 * \author Aredhele
 * \version 0.1
 * \date 15/11/2015
 * \class TimerUnitTest
 */

// Header
#include "GTest/gtest.h"
#include "Modules/Utilities/Timer.hpp"

class TimerFixture : public ::testing::Test {

protected:
    virtual void TearDown() {}
    virtual void SetUp()
    {
        if(m_timer != nullptr)
            delete m_timer;

        m_testTime = 5.0;
        m_timer = new Timer(m_testTime);
    }

public:
    TimerFixture() : Test() {
        m_testTime = 5.0;
    }

    virtual ~TimerFixture() {
        if(m_timer != nullptr)
            delete m_timer;

        m_timer = nullptr;
    }

    double m_testTime;
    Timer * m_timer = nullptr;
};

/*!
 * \brief Check if the getTimeLeft method works
 */
TEST_F(TimerFixture, GetTimeLeftUnitTest)
{
    EXPECT_DOUBLE_EQ(m_timer->getTimeLeft(), m_testTime);

    m_timer->removeTime(1.0);
    EXPECT_DOUBLE_EQ(m_timer->getTimeLeft(), m_testTime - 1.0);
}

/*!
 * \brief Check if the getStartTime method works
 */
TEST_F(TimerFixture, GetStartTimeUnitTest)
{
    EXPECT_DOUBLE_EQ(m_timer->getStartTime(), m_testTime);

    delete m_timer;
    m_timer = new Timer(2.666);
    EXPECT_DOUBLE_EQ(m_timer->getStartTime(), 2.666);
}

/*!
 * \brief Test the constructor of the timer
 *        Check if the start and left time
 *        are well initialized
 */
TEST_F(TimerFixture, ConstructorUnitTest)
{
    EXPECT_DOUBLE_EQ(m_timer->getStartTime(), m_testTime);
    EXPECT_DOUBLE_EQ(m_timer->getTimeLeft(), m_testTime);
}

/*!
 * \brief Check the method removeTimeUnitTest
 *        in many case
 */
TEST_F(TimerFixture, RemoveTimeUnitTest)
{
    double timeToRemove = 2;
    EXPECT_DOUBLE_EQ(m_timer->getTimeLeft(), m_testTime);

    m_timer->removeTime(timeToRemove);
    EXPECT_DOUBLE_EQ(m_timer->getTimeLeft(), m_testTime - timeToRemove);

    m_timer->removeTime(0);
    EXPECT_DOUBLE_EQ(m_timer->getTimeLeft(), m_testTime - timeToRemove);
    ASSERT_FALSE(m_timer->removeTime(0));

    ASSERT_TRUE(m_timer->removeTime(m_testTime - (m_testTime - m_timer->getTimeLeft())));
    ASSERT_TRUE(m_timer->removeTime(1));
}

/*!
 * \brief Restart the timer and check if the current left time
 *        is equal to the start time
 */
TEST_F(TimerFixture, RestartUnitTest)
{
    double timeToRemove = 2;
    EXPECT_DOUBLE_EQ(m_timer->getTimeLeft(), m_testTime);

    m_timer->removeTime(timeToRemove);
    m_timer->restart();
    EXPECT_DOUBLE_EQ(m_timer->getTimeLeft(), m_testTime);
}

/*!
 * \brief Restart the timer with a value
 *        and check if the current left time
 *        matches with the given value
 */
TEST_F(TimerFixture, RestartOverloadUnitTest)
{
    double newStartValue = 3.0;
    m_timer->restart(newStartValue);
    EXPECT_DOUBLE_EQ(m_timer->getTimeLeft(), newStartValue);
}

/*!
 * \brief Set the timer with a new start time
 *        and check if the new start time and
 *        the new left time match with the given
 *        value
 */
TEST_F(TimerFixture, SetStartTimeUnitTest)
{
    double timeToSet = 9.0;
    m_timer->setStartTime(timeToSet);

    EXPECT_DOUBLE_EQ(m_timer->getTimeLeft(), timeToSet);
    EXPECT_DOUBLE_EQ(m_timer->getStartTime(), timeToSet);
}

/*!
 * \brief Check if the softrestart reset the timer correctly
 */
TEST_F(TimerFixture, SoftRestartUnitTest)
{
    double timeToRemove = 0.5;
    unsigned int removeCount = 5;

    m_timer->removeTime(timeToRemove * removeCount);
    EXPECT_DOUBLE_EQ(m_timer->getTimeLeft(), m_testTime - (timeToRemove * removeCount));

    double buffer = m_timer->getTimeLeft();

    m_timer->softRestart();
    EXPECT_DOUBLE_EQ(m_timer->getTimeLeft(), m_testTime + buffer);

    m_timer->removeTime(15);
    m_timer->softRestart();
    EXPECT_DOUBLE_EQ(m_timer->getTimeLeft(), m_testTime) << m_timer->getTimeLeft();
}
/*!
 * \brief Unit test of class Tile Set
 * \file QuadVerticesUnitTest.cpp
 * \author Aredhele, Exidhor
 * \version 0.1
 * \date 15/11/2015
 * \class QuadVerticesUnitTest
 */

// Header
#include "GTest/gtest.h"
#include "Engines/GraphicEngine/QuadVertices.hpp"

class QuadVerticesFixture : public ::testing::Test {

protected:
    virtual void TearDown() {}
    virtual void SetUp()
    {
        if(m_quadVertices != nullptr)
            delete m_quadVertices;

        m_quadVertices = new GraphicMonsters::QuadVertices(*m_bounds);
    }

public:
    QuadVerticesFixture() : Test() {

        m_bounds = new sf::FloatRect(0, 0, 1, 1);
        m_quadVertices = new GraphicMonsters::QuadVertices(*m_bounds);
    }

    /**
     * \brief TODO
     */
    virtual ~QuadVerticesFixture() {
        delete m_quadVertices;
        m_quadVertices = 0;
    }

    GraphicMonsters::QuadVertices * m_quadVertices;
    sf::FloatRect* m_bounds;
};

/**
 * \brief TODO
 */
TEST_F(QuadVerticesFixture, GlobalBoundsUnitTest)
{
    EXPECT_EQ(1, 1);
}

/**
 * \brief TODO
 */
TEST_F(QuadVerticesFixture, ConstructorUnitTest)
{
    EXPECT_EQ(1, 1);
}
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
    virtual void SetUp() {}

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
TEST_F(QuadVerticesFixture, ApplyTransformationUnitTest)
{
    sf::Transform tr;
    tr.rotate(360);

    delete m_quadVertices;
    m_quadVertices = new GraphicMonsters::QuadVertices(*m_bounds);

    const sf::Vertex* beforeVertexArray = m_quadVertices->getConstVerticesArray();

    m_quadVertices->applyTranformation(tr);

    const sf::Vertex* afterVertexArray = m_quadVertices->getConstVerticesArray();


    for(int i = 0; i < 4; i++)
    {
        EXPECT_EQ(beforeVertexArray[i].position, afterVertexArray[i].position);
    }
}

/**
 * \brief TODO
 */
TEST_F(QuadVerticesFixture, SetPositionUnitTest)
    {
    EXPECT_EQ(1, 1);
}

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
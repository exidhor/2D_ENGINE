/*!
 * \brief Unit test of class Tile Set
 * \file TileSetUnitTest.cpp
 * \author Aredhele, Exidhor
 * \version 0.1
 * \date 15/11/2015
 * \class TileSetUnitTest
 */

// Header
#include "GTest/gtest.h"
#include "Engines/GraphicEngine/Tileset.hpp"

class TileSetFixture : public ::testing::Test {

protected:
    virtual void TearDown() {}
    virtual void SetUp() {}

public:
    TileSetFixture() : Test() {
        m_tileSet = new GraphicMonsters::Tileset();
    }

    /**
     * \brief TODO
     */
    virtual ~TileSetFixture() {
        delete m_tileSet;
        m_tileSet = 0;
    }

    GraphicMonsters::Tileset * m_tileSet;
};

/**
 * \brief TODO
 */
TEST_F(TileSetFixture, ConstructorUnitTest)
{
EXPECT_EQ(1, 1);
}
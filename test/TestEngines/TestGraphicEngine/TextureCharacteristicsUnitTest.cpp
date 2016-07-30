/*!
 * \brief Unit test of class Tile Set
 * \file TextureCharacteristicsUnitTest.cpp
 * \author Aredhele
 * \version 0.1
 * \date 15/11/2015
 * \class TileSetUnitTest
 */

// Header
#include "GTest/gtest.h"
#include "Engines/GraphicEngine/TextureCharacteristics.hpp"

class TextureCharacteristicsFixture : public ::testing::Test {

protected:
    virtual void TearDown() {}
    virtual void SetUp()
    {
        if(m_textureCharacteristics != nullptr)
            delete m_textureCharacteristics;

        if(m_tileSet != nullptr)
            delete m_tileSet;

        m_tileSet = new GraphicMonsters::Tileset();

    }

public:
    TextureCharacteristicsFixture() : Test() {
        // None
    }

    /**
     * \brief TODO
     */
    virtual ~TileSetFixture() {
        if(m_textureCharacteristics != nullptr)
            delete m_textureCharacteristics;

        if(m_tileSet != nullptr)
            delete m_tileSet;

        if(m_texture != nullptr)
            delete m_texture;


        m_tileSet = nullptr;
        m_textureCharacteristics = nullptr;
    }

    sf::Texture * m_texture = nullptr;
    GraphicMonsters::Tileset * m_tileSet = nullptr;
    GraphicMonsters::TextureCharacteristics * m_textureCharacteristics = nullptr;
};

/**
 * \brief TODO
 */
TEST_F(TextureCharacteristicsFixture, ConstructorUnitTest)
{
    EXPECT_EQ(1, 1);
}
#include "Engines/GameEngine/GameEngine.hpp"

int main()
{
    //GameEngine ge;
    //ge.construct();

    //return 0;

    GraphicMonsters::Engine graphicEngine;

    graphicEngine.init();

    int numberOfElements = 1000;

    graphicEngine.addTileset("Test", "../res/tileTest.png", numberOfElements, 2);

    std::string nomCleAnimation("vieuxJaune");
    Vector2f tailleTuile(32, 48);
    std::vector <Vector2f> texturePoints;

    for (unsigned int indiceColonne = 0; indiceColonne < 3; indiceColonne++)
    {
        texturePoints.push_back(Vector2f(indiceColonne*tailleTuile.x, 0));
    }

    // ajout dans le moteur des caracteristiques
    graphicEngine.addTileCharacteristics(
            nomCleAnimation,
            "Test",
            tailleTuile,
            texturePoints,
            0.25);

    graphicEngine.addAnimation(nomCleAnimation, 0, 1);

    graphicEngine.openWindow("Tuto 2D_ENGINE");

    GraphicMonsters::Sprite* ourAnimation;
    ourAnimation = graphicEngine.getFreeSprite(nomCleAnimation);
    ourAnimation->start();
    ourAnimation->setRepeated(true);

    graphicEngine.run(60);

    return 0;
}


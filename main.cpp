#include <cstdio>
#include <SFML/Graphics.hpp>

static const int SCREEN_WIDTH = 1920;
using namespace sf;

int main() {
    float spaceshipSpeed = 256.0f;

    Event event;

    VideoMode vm(SCREEN_WIDTH, 1080);

    RenderWindow window(vm, "Astrosmash");

    Texture spaceshipTexture;
    spaceshipTexture.loadFromFile("graphics/spaceship.png");

    Sprite spaceship(spaceshipTexture);
    spaceship.setPosition(960, 960);

    Clock clock;

    bool acceptInput = true;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }

        Time dt = clock.restart();

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            if (spaceship.getPosition().x > 0) {
                spaceship.setPosition(spaceship.getPosition().x - (spaceshipSpeed * dt.asSeconds()),
                                      spaceship.getPosition().y);
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            if (spaceship.getPosition().x < SCREEN_WIDTH - 64) {
                spaceship.setPosition(spaceship.getPosition().x + (spaceshipSpeed * dt.asSeconds()),
                                      spaceship.getPosition().y);
            }
        }

        window.clear();

        window.draw(spaceship);

        window.display();
    }
}
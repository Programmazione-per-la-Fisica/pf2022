#include "complex.hpp"
#include <SFML/Graphics.hpp>
#include <cassert>
#include <iostream>
#include <string>
#include <thread>

using complex = Complex<double>;

int mandelbrot(complex const& c)
{
  auto i = 0;
  auto z = c;
  for (; i != 256 && norm2(z) < 2.; ++i) {
    z = z * z + c;
  }
  return i;
}

auto to_color(int k)
{
  return k < 256 ? sf::Color{static_cast<sf::Uint8>(10 * k), 0, 0}
                 : sf::Color::Black;
}

int main()
{
  auto const display_width  = 600u;
  auto const display_height = 600u;

  complex const top_left{-2.2, 1.5};
  complex const lower_right{0.8, -1.5};
  auto const diff = lower_right - top_left;

  auto const delta_x = diff.real() / display_width;
  auto const delta_y = diff.imag() / display_height;

  sf::RenderWindow window(sf::VideoMode(display_width, display_height),
                          "Mandelbrot Set");
  window.setFramerateLimit(60);

  sf::Image image;
  image.create(window.getSize().x, window.getSize().y);

  for (auto row = 0u; row != display_height; ++row) {
    for (auto column = 0u; column != display_width; ++column) {
      auto k = mandelbrot(top_left + complex{delta_x * column, delta_y * row});
      image.setPixel(column, row, to_color(k));
    }
  }

  sf::Texture texture;
  texture.loadFromImage(image);
  sf::Sprite sprite;
  sprite.setTexture(texture);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();

    window.draw(sprite);

    window.display();

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(15ms);
  }
}

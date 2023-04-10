#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

std::vector<std::unique_ptr<sf::Shape>> create_shapes();

int main()
{
  // create the window
  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
  // window.setVerticalSyncEnabled(true);
  constexpr int frame_rate{60};
  window.setFramerateLimit(frame_rate);

  auto shapes = create_shapes();

  // run the program as long as the window is open
  while (window.isOpen()) {

    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // evolve the scene
    for (auto& shape : shapes) {
      shape->move(sf::Vector2f{window.getSize().x / (5.f * frame_rate),
                               window.getSize().y / (5.f * frame_rate)});
    }

    // clear the window with black color
    window.clear(sf::Color::Black);

    // draw the shapes
    for (auto const& shape : shapes) {
      window.draw(*shape);
    }

    // display the window
    window.display();
  }
}

std::vector<std::unique_ptr<sf::Shape>> create_shapes()
{
  std::vector<std::unique_ptr<sf::Shape>> shapes;

  auto circle = std::make_unique<sf::CircleShape>(50.f);
  circle->setFillColor(sf::Color(100, 250, 50));
  shapes.push_back(std::move(circle));

  auto rectangle = std::make_unique<sf::RectangleShape>(sf::Vector2f{120.f, 50.f});
  rectangle->setPosition(sf::Vector2f{300.f, 200.f});
  rectangle->setFillColor(sf::Color::Yellow);
  shapes.push_back(std::move(rectangle));

  return shapes;
}

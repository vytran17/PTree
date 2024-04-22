// Copyright Vy Tran 2024

#ifndef PTREE_HPP
#define PTREE_HPP

#include <SFML/Graphics.hpp>

class PTree {
 public:
    PTree(double L, int N);
    ~PTree();

    void pTree(double L, int N, sf::Vector2f vPoint, sf::Vector2f vOrigin, float rotation);
    void drawPtree(sf::RenderTarget& target, const int N, sf::RectangleShape& parent);
    void drawPtree(sf::RenderTarget& target, const float L, const int N);

 private:
    float width = 0.0;
    float height = 0.0;
    int Xorigin = 0;
    int Yorigin = 0;
    float rotation = 0.0;
    int angle1 = 0;
    int angle2 = 0;
    int initialN;
    sf::Color startColor = sf::Color::Red;
    sf::Color endColor = sf::Color::Blue;
    sf::RenderWindow window;
};

#endif  // PTREE_HPP

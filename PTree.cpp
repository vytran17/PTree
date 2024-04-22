// Copyright Vy Tran 2024

#include "PTree.hpp"
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using sf::Color;
using sf::Event;
using sf::RectangleShape;
using sf::RenderTarget;
using sf::VideoMode;
using std::sqrt;

PTree::PTree(double L, int N) {
    // Sets the window size by multiplying L
    width = 6 * L;
    height = 4 * L;
    initialN = N;

    window.create(VideoMode(width, height), "Pythagoras Tree");
    // Once the window is created, time to generate the tree
    while (window.isOpen()) {
        for (Event event; window.pollEvent(event); ) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear(Color::White);
        drawPtree(window, L, N);
        window.display();
    }
}

PTree::~PTree() {}

void PTree::drawPtree(RenderTarget& target, const int N, RectangleShape& parent) {
    static const float halfSqrt2 = sqrt(2.f) / 2;

    if (N < 1) {
        return;
    }

    float ratio = static_cast<float>(N) / initialN;
    Color color(
        startColor.r * ratio + endColor.r * (1 - ratio),
        startColor.g * ratio + endColor.g * (1 - ratio),
        startColor.b * ratio + endColor.b * (1 - ratio));
    parent.setFillColor(color);

    target.draw(parent);
    const auto& sz = parent.getSize();
    const auto& tf = parent.getTransform();

    // Left side recursion call
    RectangleShape childL = parent;
    childL.setSize(sz * halfSqrt2);
    childL.setOrigin(0, childL.getSize().y);
    childL.setPosition(tf.transformPoint(sf::Vector2f(0, 0)));
    childL.rotate(-45);
    drawPtree(target, N - 1, childL);

    // Right side recursion call
    RectangleShape childR = parent;
    childR.setSize(sz * halfSqrt2);
    childR.setOrigin(childR.getSize());
    childR.setPosition(tf.transformPoint(sf::Vector2f(sz.x, 0)));
    childR.rotate(45);
    drawPtree(target, N - 1, childR);
}

void PTree::drawPtree(RenderTarget& target, const float L, const int N) {
    // Set origin to the center of the rectangle
    RectangleShape rect(sf::Vector2f(L, L));

    rect.setOrigin(rect.getSize() / 2.f);
    rect.setPosition(target.getSize().x / 2.f, target.getSize().y - L / 2.f);
    drawPtree(target, N, rect);
}

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

const int WIDTH = 800;
const int HEIGHT = 600;
const int PIXEL_SIZE = 1;

using Canvas = std::vector<std::vector<sf::Color>>;

// Drawing
void clearCanvas(Canvas& canvas);
void drawPixel(Canvas& canvas, int x, int y, const sf::Color& color);
void drawBrush(Canvas& canvas, int x, int y,
               const sf::Color& color, int radius);

// Shapes
void drawRectangle(Canvas& canvas,
                   int x1, int y1,
                   int x2, int y2,
                   const sf::Color& color);

void drawLine(Canvas& canvas,
              int x1, int y1,
              int x2, int y2,
              const sf::Color& color);

// Undo
void undo(Canvas& canvas);
void saveToUndo(const Canvas& canvas);

// Filters
void applyGrayscale(Canvas& canvas);
void applyNegative(Canvas& canvas);
void applyBlur(Canvas& canvas);

// Render
void renderToWindow(sf::RenderWindow& window,
                    const Canvas& canvas);
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "utility.h"

using namespace std;

#define PI 3.14159265359f

float dist(const sf::Vector2f& a, const sf::Vector2f& b) {
    return pow(pow(a.x-b.x,2.f) + pow(a.y-b.y,2.f),0.5f);
}
float colorDifference(const sf::Color& c1, const sf::Color& c2) {
    return pow(pow(float(c1.r) - float(c2.r), 2.f) + pow(float(c1.g) - float(c2.g), 2.f) + pow(float(c1.b) - float(c2.b), 2.f), 0.5f);
}
sf::Vector2i scaleVector(const sf::Vector2i& pos_ratio, const sf::Vector2u& image_size) {
    return sf::Vector2i(pos_ratio.x * image_size.x, pos_ratio.y * image_size.y);
}
int fixIndex(int i) {
    if(i == 0) return 0;
    else return 4-i;
}

ThickLine::ThickLine() {
	setSize(sf::Vector2f(1,1));
	setOrigin(sf::Vector2f(0.5,0.5));
}
ThickLine::ThickLine(const sf::Vector2f& aa, const sf::Vector2f& bb, float t, const sf::Color& c) : a(aa), b(bb), thickness(t) {
	setFillColor(c);
	setSize(sf::Vector2f(1,1));
	setOrigin(sf::Vector2f(0.5,0.5));
	update(a, b);
}
void ThickLine::setA(const sf::Vector2f& x) {
	a = x;
}
void ThickLine::setB(const sf::Vector2f& x) {
	b = x;
}
void ThickLine::setThickness(const float& x) {
	thickness = x;
}
sf::Vector2f ThickLine::getA() const {
	return a;
}
sf::Vector2f ThickLine::getB() const {
	return b;
}
float ThickLine::getThickness() const {
	return thickness;
}
void ThickLine::update(const sf::Vector2f& aa, const sf::Vector2f& bb) {
	a = aa;
	b = bb;
	setScale(dist(a, b)+0.5, thickness);
	setPosition(b);
	setRotation(atan2(a.y-b.y, a.x-b.x)*180.f/PI);
}

ThickLineSet::ThickLineSet(const sf::Vector2f& aa, const sf::Vector2f& bb, float t1, float t2, const sf::Color& c) : a(aa), b(bb), thickness1(t1), thickness2(t2), color(c) {
    update(a, b);
}
void ThickLineSet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(auto &tl: lines) target.draw(tl, states);
}
void ThickLineSet::update(const sf::Vector2f& aa, const sf::Vector2f& bb) {
    a = aa;
    b = bb;
    lines.clear();
    float line_count = 30;
    sf::Vector2f line_offset = (b - a)/line_count;
    for(float i = 0; i < line_count; i++) {
        lines.push_back(ThickLine(a + i*line_offset, a + (i+1.f)*line_offset, (pow((line_count-i)*thickness1,2.f) + pow(i*thickness2, 2.f))/(4.f*pow(line_count,2.f)), color));
    }
}

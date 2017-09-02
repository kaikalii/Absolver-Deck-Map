#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "utility.h"
#include "move.h"

using namespace std;

Move::Move(sf::Texture& tex, const sf::IntRect& rect, const sf::Vector2f& pos) {
    sprite.setTexture(tex);
    sprite.setTextureRect(rect);
    sprite.setOrigin(sf::Vector2f(rect.width/2, rect.height/2));
    sprite.setPosition(pos);

    // Determine end_stance
    sf::Vector2i tr_pos(rect.left + 162, rect.top + 57);
    sf::Vector2i br_pos(rect.left + 162, rect.top + 70);
    sf::Vector2i bl_pos(rect.left + 149, rect.top + 70);
    sf::Vector2i tl_pos(rect.left + 149, rect.top + 57);
    sf::Vector2f center_pos(rect.left + rect.width/2, rect.top + rect.height/2);

    sf::Color selected(255, 235, 132, 255);
    sf::Color kinda_selected(167, 178, 178, 255);
    sf::Color not_selected(144, 156, 155, 255);

    sf::Color no_move_selected(247, 233, 172, 255);
    sf::Color no_move_selected2(175, 170, 134, 255);

    sf::Image image = tex.copyToImage();
    int m = 20;
    if(colorDifference(no_move_selected, image.getPixel(center_pos.x, center_pos.y)) < m || colorDifference(no_move_selected2, image.getPixel(center_pos.x, center_pos.y)) < m) end_stance = undefined;
    else if(colorDifference(selected, image.getPixel(tr_pos.x, tr_pos.y)) < m || colorDifference(kinda_selected, image.getPixel(tr_pos.x, tr_pos.y)) < m || colorDifference(not_selected, image.getPixel(tr_pos.x, tr_pos.y)) < m) end_stance = top_right;
    else if(colorDifference(selected, image.getPixel(br_pos.x, br_pos.y)) < m || colorDifference(kinda_selected, image.getPixel(br_pos.x, br_pos.y)) < m || colorDifference(not_selected, image.getPixel(br_pos.x, br_pos.y)) < m) end_stance = bottom_right;
    else if(colorDifference(selected, image.getPixel(bl_pos.x, bl_pos.y)) < m || colorDifference(kinda_selected, image.getPixel(bl_pos.x, bl_pos.y)) < m || colorDifference(not_selected, image.getPixel(bl_pos.x, bl_pos.y)) < m) end_stance = bottom_left;
    else if(colorDifference(selected, image.getPixel(tl_pos.x, tl_pos.y)) < m || colorDifference(kinda_selected, image.getPixel(tl_pos.x, tl_pos.y)) < m || colorDifference(not_selected, image.getPixel(tl_pos.x, tl_pos.y)) < m) end_stance = top_left;
    else end_stance = undefined;

    if(end_stance == top_right) cout << "Move ends in top right" << endl;
    else if(end_stance == bottom_right) cout << "Move ends in bottom right" << endl;
    else if(end_stance == bottom_left) cout << "Move ends in bottom left" << endl;
    else if(end_stance == top_left) cout << "Move ends in top left" << endl;
    else if(end_stance == undefined) cout << "Move has no end stance or move's end stance could not be determined" << endl;
}

void Move::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if(end_stance != undefined) target.draw(sprite);
}

void Move::setPosition(const sf::Vector2f& pos) {
    sprite.setPosition(pos);
}
sf::Vector2f Move::getPosition() const {
    return sprite.getPosition();
}

sf::Vector2f Move::getCorner(const sf::Vector2f& center) {
    auto texrec = sprite.getTextureRect();
    vector<sf::Vector2f> corners(4, getPosition());
    corners[0] += sf::Vector2f(texrec.width/2, -texrec.height/2);
    corners[1] += sf::Vector2f(texrec.width/2, texrec.height/2);
    corners[2] += sf::Vector2f(-texrec.width/2, texrec.height/2);
    corners[3] += sf::Vector2f(-texrec.width/2, -texrec.height/2);
    int min_index = 0;
    float min_dist = dist(center, corners[0]);
    for(int i = 1; i < corners.size(); i++) {
        float this_dist = dist(center, corners[i]);
        if(this_dist < min_dist) {
            min_dist = this_dist;
            min_index = i;
        }
    }
    return corners[min_index];
}

sf::Vector2f Move::getSide(const sf::Vector2f& center) {
    auto texrec = sprite.getTextureRect();
    vector<sf::Vector2f> sides(4, getPosition());
    sides[0] += sf::Vector2f(0, -texrec.height/2);
    sides[1] += sf::Vector2f(texrec.width/2, 0);
    sides[2] += sf::Vector2f(0, texrec.height/2);
    sides[3] += sf::Vector2f(-texrec.width/2, 0);
    int min_index = 0;
    float min_dist = dist(center, sides[0]);
    for(int i = 1; i < sides.size(); i++) {
        float this_dist = dist(center, sides[i]);
        if(this_dist < min_dist) {
            min_dist = this_dist;
            min_index = i;
        }
    }
    return sides[min_index];
}

sf::Vector2f Move::getCornerOrSide(const sf::Vector2f& center) {
    auto texrec = sprite.getTextureRect();
    vector<sf::Vector2f> points(8, getPosition());
    points[0] += sf::Vector2f(0, -texrec.height/2);
    points[1] += sf::Vector2f(texrec.width/2, 0);
    points[2] += sf::Vector2f(0, texrec.height/2);
    points[3] += sf::Vector2f(-texrec.width/2, 0);
    points[4] += sf::Vector2f(texrec.width/2, -texrec.height/2);
    points[5] += sf::Vector2f(texrec.width/2, texrec.height/2);
    points[6] += sf::Vector2f(-texrec.width/2, texrec.height/2);
    points[7] += sf::Vector2f(-texrec.width/2, -texrec.height/2);
    int min_index = 0, min_side_index = 0, min_corner_index = 4;
    float min_dist = dist(center, points[0]);
    float min_side_dist = dist(center, points[0]);
    float min_corner_dist = dist(center, points[4]);
    for(int i = 1; i < points.size(); i++) {
        float this_dist = dist(center, points[i]);
        if(this_dist < min_dist) {
            min_dist = this_dist;
            min_index = i;
        }
        if(i < 4 && this_dist < min_side_dist) {
            min_side_dist = this_dist;
            min_side_index = i;
        }
        else if(i >= 4 && this_dist < min_corner_dist) {
            min_corner_dist = this_dist;
            min_corner_index = i;
        }
    }
    if(min_side_dist < 300) return points[min_side_index];
    else return points[min_corner_index];
}

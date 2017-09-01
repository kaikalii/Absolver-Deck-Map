#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "utility.h"
#include "Move.h"

using namespace std;

#define PI 3.14159265359f

int main(int argc, char **argv) {
    if(argc < 2) return 0;
    sf::Texture screenshot;
    screenshot.loadFromFile(argv[1]);
    if(screenshot.getSize() != sf::Vector2u(1920,1080)) return 0;
    vector<Move> moves;
    sf::Vector2i Move_dim(128,128);
    float angle = -PI/2.f + PI/16.f;
    float dist_from_center = 600;
    sf::Vector2f output_size(1400,1400);

    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(238,287), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f;
    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(421,287), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f;
    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(604,287), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f;
    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(1492,287), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f + PI;
    cout << endl;

    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(238,430), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f;
    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(421,430), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f;
    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(604,430), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f;
    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(1492,430), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f + PI;
    cout << endl;

    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(238,573), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f;
    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(421,573), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f;
    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(604,573), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f;
    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(1492,573), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f + PI;
    cout << endl;

    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(238,716), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f;
    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(421,716), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f;
    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(604,716), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));
    angle += PI/8.f;
    moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(1492,716), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center*cos(angle), dist_from_center*sin(angle))));

    vector<ThickLineSet> tls;
    unsigned char opacity = 128;
    sf::Color col1, col2(255,255,0,opacity);
    float t1 = 8, t2 = 2;
    for(int i = 0; i < moves.size(); i++) {

        if(i%4 < 2) col1 = sf::Color(200,200,200,opacity);
        else col1 = sf::Color(0,0,255,opacity);

        if(i%4 < 2) tls.push_back(ThickLineSet(moves[i].getCorner(moves[i+1].getPosition()), moves[i+1].getCorner(moves[i].getPosition()), t1, t2, sf::Color(0,0,255,opacity)));

        if(i%4 == 0) tls.push_back(ThickLineSet(output_size/2.f, moves[i].getCorner(output_size/2.f), t1, t2, sf::Color(0,0,255,opacity)));
        if(i%4 == 3) tls.push_back(ThickLineSet(output_size/2.f, moves[i].getCorner(output_size/2.f), t1, t2, sf::Color(255,255,0,opacity)));

        switch(moves[i].end_stance) {
            case top_right: tls.push_back(ThickLineSet(moves[i].getCorner(moves[0].getPosition()), moves[0].getCorner(moves[i].getPosition()), t1, t2, col1)); break;
            case bottom_right: tls.push_back(ThickLineSet(moves[i].getCorner(moves[12].getPosition()), moves[12].getCorner(moves[i].getPosition()), t1, t2, col1)); break;
            case bottom_left: tls.push_back(ThickLineSet(moves[i].getCorner(moves[8].getPosition()), moves[8].getCorner(moves[i].getPosition()), t1, t2, col1)); break;
            case top_left: tls.push_back(ThickLineSet(moves[i].getCorner(moves[4].getPosition()), moves[4].getCorner(moves[i].getPosition()), t1, t2, col1)); break;
        }
        switch(moves[i].end_stance) {
            case top_right: tls.push_back(ThickLineSet(moves[i].getCorner(moves[3].getPosition()), moves[3].getCorner(moves[i].getPosition()), t1, t2, col2)); break;
            case bottom_right: tls.push_back(ThickLineSet(moves[i].getCorner(moves[15].getPosition()), moves[15].getCorner(moves[i].getPosition()), t1, t2, col2)); break;
            case bottom_left: tls.push_back(ThickLineSet(moves[i].getCorner(moves[11].getPosition()), moves[11].getCorner(moves[i].getPosition()), t1, t2, col2)); break;
            case top_left: tls.push_back(ThickLineSet(moves[i].getCorner(moves[7].getPosition()), moves[7].getCorner(moves[i].getPosition()), t1, t2, col2)); break;
        }
    }

    sf::CircleShape center;
    center.setFillColor(sf::Color(131, 146, 141, 255));
    center.setRadius(output_size.x/40.f);
    center.setOrigin(center.getRadius()*sf::Vector2f(1,1));
    center.setPosition(output_size/2.f);

    sf::RenderTexture output;
    output.create(output_size.x,output_size.y);
    output.clear(sf::Color(111, 126, 121, 255));
    for(auto &m: moves) output.draw(m);
    for(auto &t: tls) output.draw(t);
    output.draw(center);
    output.display();
    output.getTexture().copyToImage().saveToFile("output.png");

    char dud;
    cin >> dud;
    return 0;
}

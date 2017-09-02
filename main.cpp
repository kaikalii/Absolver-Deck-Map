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

    // Create stance markers
    vector<sf::RectangleShape> stances(4, sf::RectangleShape(output_size/20.f));
    for(auto &st: stances) {
        st.setFillColor(sf::Color::Black);
        st.setOutlineColor(sf::Color::White);
        st.setOutlineThickness(output_size.x/300.f);
        st.setOrigin(st.getSize()/2.f);
        st.rotate(45);
    }
    float pratio = 3.f/7.f;
    sf::Vector2f tlp = pratio * output_size;
    sf::Vector2f brp = (1.f - pratio) * output_size;
    stances[0].setPosition(brp.x, tlp.y);
    stances[1].setPosition(brp.x, brp.y);
    stances[2].setPosition(tlp.x, brp.y);
    stances[3].setPosition(tlp.x, tlp.y);

    // Create Lines
    vector<ThickLineSet> tls;
    unsigned char opacity = 115;
    sf::Color col1, col2(255,255,0,opacity);
    float t1 = 8, t2 = 3;
    for(int i = 0; i < moves.size(); i++) {
        if(moves[i].end_stance != undefined) {

            // Add blue lines for regular same-stance combos
            if(i%4 < 2 && moves[i+1].end_stance != undefined) tls.push_back(ThickLineSet(moves[i].getCornerOrSide(moves[i+1].getPosition()), moves[i+1].getCornerOrSide(moves[i].getPosition()), t1, t2, sf::Color(0,0,255,opacity)));

            // Add blue and yellow lines from stances to first regular attacks and alternate attacks
            if(i%4 == 0) tls.push_back(ThickLineSet(stances[i/4].getPosition(), moves[i].getCornerOrSide(stances[i/4].getPosition()), t1, t2, sf::Color(0,0,255,opacity)));
            if(i%4 == 3) tls.push_back(ThickLineSet(stances[i/4].getPosition(), moves[i].getCornerOrSide(stances[i/4].getPosition()), t1, t2, sf::Color(255,255,0,opacity)));

            // Add grey lines for waiting
            if(i%4 < 2 && moves[i+1].end_stance != undefined) {
                switch(moves[i].end_stance) {
                    case top_right: tls.push_back(ThickLineSet(moves[i].getCornerOrSide(stances[0].getPosition()), stances[0].getPosition(), t1, t2, sf::Color(200,200,200,opacity))); break;
                    case bottom_right: tls.push_back(ThickLineSet(moves[i].getCornerOrSide(stances[1].getPosition()), stances[1].getPosition(), t1, t2, sf::Color(200,200,200,opacity))); break;
                    case bottom_left: tls.push_back(ThickLineSet(moves[i].getCornerOrSide(stances[2].getPosition()), stances[2].getPosition(), t1, t2, sf::Color(200,200,200,opacity))); break;
                    case top_left: tls.push_back(ThickLineSet(moves[i].getCornerOrSide(stances[3].getPosition()), stances[3].getPosition(), t1, t2, sf::Color(200,200,200,opacity))); break;
                }
            }
            // Add blue lines for next stances
            else {
                switch(moves[i].end_stance) {
                    case top_right: tls.push_back(ThickLineSet(moves[i].getCornerOrSide(moves[0].getPosition()), moves[0].getCornerOrSide(moves[i].getPosition()), t1, t2, sf::Color(0,0,255,opacity))); break;
                    case bottom_right: tls.push_back(ThickLineSet(moves[i].getCornerOrSide(moves[12].getPosition()), moves[12].getCornerOrSide(moves[i].getPosition()), t1, t2, sf::Color(0,0,255,opacity))); break;
                    case bottom_left: tls.push_back(ThickLineSet(moves[i].getCornerOrSide(moves[8].getPosition()), moves[8].getCornerOrSide(moves[i].getPosition()), t1, t2, sf::Color(0,0,255,opacity))); break;
                    case top_left: tls.push_back(ThickLineSet(moves[i].getCornerOrSide(moves[4].getPosition()), moves[4].getCornerOrSide(moves[i].getPosition()), t1, t2, sf::Color(0,0,255,opacity))); break;
                }
            }

            // Add yellow lines to alternate attacks
            switch(moves[i].end_stance) {
                case top_right: tls.push_back(ThickLineSet(moves[i].getCornerOrSide(moves[3].getPosition()), moves[3].getCornerOrSide(moves[i].getPosition()), t1, t2, col2)); break;
                case bottom_right: tls.push_back(ThickLineSet(moves[i].getCornerOrSide(moves[15].getPosition()), moves[15].getCornerOrSide(moves[i].getPosition()), t1, t2, col2)); break;
                case bottom_left: tls.push_back(ThickLineSet(moves[i].getCornerOrSide(moves[11].getPosition()), moves[11].getCornerOrSide(moves[i].getPosition()), t1, t2, col2)); break;
                case top_left: tls.push_back(ThickLineSet(moves[i].getCornerOrSide(moves[7].getPosition()), moves[7].getCornerOrSide(moves[i].getPosition()), t1, t2, col2)); break;
            }
        }
    }

    sf::RenderTexture output;
    output.create(output_size.x,output_size.y);
    output.clear(sf::Color(111, 126, 121, 255));
    for(auto &m: moves) output.draw(m);
    for(auto &s: stances) output.draw(s);
    for(auto &t: tls) output.draw(t);
    output.display();
    output.getTexture().copyToImage().saveToFile("output.png");

    char dud;
    cin >> dud;
    return 0;
}

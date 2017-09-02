#include <windows.h>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <fstream>
#include "utility.h"
#include "Move.h"

using namespace std;

#define PI 3.14159265359f

int main(int argc, char **argv) {
    if(argc < 2) return 0;

    // Get exe path
    char buffer[1000];
    GetModuleFileName(NULL, buffer, 1000);
    string exe_path = buffer;
    while(*exe_path.rbegin() != '\\') exe_path.pop_back();

    // Open settings
    sf::Vector2f output_size(2133,1200);
    float t1 = 8, t2 = 3;
    unsigned char opacity = 115;

    ifstream settings(exe_path + "settings.ini");
    if(settings.is_open()) {
        string in_string;
        getline(settings, in_string);
        getline(settings, in_string);
        output_size.x = stof(in_string);
        getline(settings, in_string);
        getline(settings, in_string);
        output_size.y = stof(in_string);
        getline(settings, in_string);
        getline(settings, in_string);
        t1 = stof(in_string);
        getline(settings, in_string);
        getline(settings, in_string);
        t2 = stof(in_string);
        getline(settings, in_string);
        getline(settings, in_string);
        opacity = stof(in_string);
        cout << "Loaded settings" << endl << endl;
    }


    for(int args = 1; args < argc; args++) {
        sf::Texture screenshot;
        screenshot.loadFromFile(argv[args]);
        if(screenshot.getSize() == sf::Vector2u(1920,1080)) {
            cout << "Making map from " << argv[args] << endl << endl;;
            vector<Move> moves;
            sf::Vector2i Move_dim(128,128);
            float angle = -PI/2.f + PI/16.f;
            sf::Vector2f dist_from_center = output_size/2.f*5.f/6.f;

            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(238,287), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI*3.f/32.f;
            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(421,287), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI*3.f/32.f;
            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(604,287), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI*3.f/16.f;
            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(1492,287), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI/8.f + PI;
            cout << endl;

            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(238,430), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI/8.f;
            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(421,430), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI/8.f;
            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(604,430), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI/8.f;
            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(1492,430), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI/8.f + PI;
            cout << endl;

            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(238,573), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI*3.f/32.f;
            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(421,573), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI*3.f/32.f;
            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(604,573), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI*3.f/16.f;
            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(1492,573), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI/8.f + PI;
            cout << endl;

            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(238,716), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI/8.f;
            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(421,716), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI/8.f;
            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(604,716), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));
            angle += PI/8.f;
            moves.push_back(Move(screenshot, sf::IntRect(sf::Vector2i(1492,716), Move_dim), output_size/2.f + sf::Vector2f(dist_from_center.x*cos(angle), dist_from_center.y*sin(angle))));

            // Create stance markers
            vector<sf::RectangleShape> stances(4, sf::RectangleShape(min(output_size.x, output_size.y)*sf::Vector2f(1,1)/20.f));
            for(auto &st: stances) {
                st.setFillColor(sf::Color::Black);
                st.setOutlineColor(sf::Color::White);
                st.setOutlineThickness(output_size.x/300.f);
                st.setOrigin(st.getSize()/2.f);
                st.rotate(45);
            }
            float pratio = 0.37f;
            sf::Vector2f tlp = pratio * output_size;
            sf::Vector2f brp = (1.f - pratio) * output_size;
            stances[0].setPosition(brp.x, tlp.y);
            stances[1].setPosition(brp.x, brp.y);
            stances[2].setPosition(tlp.x, brp.y);
            stances[3].setPosition(tlp.x, tlp.y);
            // Create stance direction indicators
            vector<sf::CircleShape> stance_dirs(4);
            for(auto &sd: stance_dirs) {
                sd.setFillColor(sf::Color::White);
                sd.setRadius(min(output_size.x, output_size.y)/80.f);
                sd.setOrigin(sd.getRadius()*sf::Vector2f(1,1));
            }
            stance_dirs[0].setPosition(stances[0].getPosition() + stances[0].getSize().x/2.f*sf::Vector2f(0.707,-0.707));
            stance_dirs[1].setPosition(stances[1].getPosition() + stances[1].getSize().x/2.f*sf::Vector2f(0.707,0.707));
            stance_dirs[2].setPosition(stances[2].getPosition() + stances[2].getSize().x/2.f*sf::Vector2f(-0.707,0.707));
            stance_dirs[3].setPosition(stances[3].getPosition() + stances[3].getSize().x/2.f*sf::Vector2f(-0.707,-0.707));

            // Create Lines
            vector<ThickLineSet> tls;
            sf::Color col1, col2(255,255,0,opacity);
            for(int i = 0; i < moves.size(); i++) {
                if(moves[i].end_stance != undefined) {

                    // Add blue lines for regular same-stance combos
                    if(i%4 < 2 && moves[i+1].end_stance != undefined) tls.push_back(ThickLineSet(moves[i].getSide(moves[i+1].getPosition()), moves[i+1].getCorner(moves[i].getPosition()), t1, t2, sf::Color(0,0,255,opacity)));

                    // Add blue and yellow lines from neutral to first regular attacks and alternate attacks
                    if(i%4 == 0) tls.push_back(ThickLineSet(stances[fixIndex(i/4)].getPosition(), moves[i].getSide(stances[fixIndex(i/4)].getPosition()), t1, t2, sf::Color(0,0,255,opacity)));
                    if(i%4 == 3) tls.push_back(ThickLineSet(stances[fixIndex(i/4)].getPosition(), moves[i].getSide(stances[fixIndex(i/4)].getPosition()), t1, t2, sf::Color(255,255,0,opacity)));

                    // Add grey lines for waiting
                    if(i%4 < 2 && moves[i+1].end_stance != undefined) {
                        switch(moves[i].end_stance) {
                            case top_right: tls.push_back(ThickLineSet(moves[i].getCorner(stances[0].getPosition()), stances[0].getPosition(), t1, t2, sf::Color(200,200,200,opacity))); break;
                            case bottom_right: tls.push_back(ThickLineSet(moves[i].getCorner(stances[3].getPosition()), stances[3].getPosition(), t1, t2, sf::Color(200,200,200,opacity))); break;
                            case bottom_left: tls.push_back(ThickLineSet(moves[i].getCorner(stances[2].getPosition()), stances[2].getPosition(), t1, t2, sf::Color(200,200,200,opacity))); break;
                            case top_left: tls.push_back(ThickLineSet(moves[i].getCorner(stances[1].getPosition()), stances[1].getPosition(), t1, t2, sf::Color(200,200,200,opacity))); break;
                        }
                    }
                    // Add blue lines for next stances
                    else {
                        switch(moves[i].end_stance) {
                            case top_right: tls.push_back(ThickLineSet(moves[i].getSide(moves[0].getPosition()), moves[0].getCornerOrSide(moves[i].getPosition()), t1, t2, sf::Color(0,0,255,opacity))); break;
                            case bottom_right: tls.push_back(ThickLineSet(moves[i].getSide(moves[12].getPosition()), moves[12].getCornerOrSide(moves[i].getPosition()), t1, t2, sf::Color(0,0,255,opacity))); break;
                            case bottom_left: tls.push_back(ThickLineSet(moves[i].getSide(moves[8].getPosition()), moves[8].getCornerOrSide(moves[i].getPosition()), t1, t2, sf::Color(0,0,255,opacity))); break;
                            case top_left: tls.push_back(ThickLineSet(moves[i].getSide(moves[4].getPosition()), moves[4].getCornerOrSide(moves[i].getPosition()), t1, t2, sf::Color(0,0,255,opacity))); break;
                        }
                    }

                    // Add yellow lines to alternate attacks
                    switch(moves[i].end_stance) {
                        case top_right: tls.push_back(ThickLineSet(moves[i].getSide(moves[3].getPosition()), moves[3].getCornerOrSide(moves[i].getPosition()), t1, t2, col2)); break;
                        case bottom_right: tls.push_back(ThickLineSet(moves[i].getSide(moves[15].getPosition()), moves[15].getCornerOrSide(moves[i].getPosition()), t1, t2, col2)); break;
                        case bottom_left: tls.push_back(ThickLineSet(moves[i].getSide(moves[11].getPosition()), moves[11].getCornerOrSide(moves[i].getPosition()), t1, t2, col2)); break;
                        case top_left: tls.push_back(ThickLineSet(moves[i].getSide(moves[7].getPosition()), moves[7].getCornerOrSide(moves[i].getPosition()), t1, t2, col2)); break;
                    }
                }
            }

            // Background Rectangles
            vector<sf::RectangleShape> back_rects(4, sf::RectangleShape(output_size/2.f));
            back_rects[0].setPosition(sf::Vector2f(0,0));
            back_rects[1].setPosition(sf::Vector2f(output_size.x/2.f,0));
            back_rects[2].setPosition(sf::Vector2f(0,output_size.y/2.f));
            back_rects[3].setPosition(output_size/2.f);
            back_rects[0].setFillColor(sf::Color(104,133,121,255));
            back_rects[1].setFillColor(sf::Color(104,104,104,255));
            back_rects[2].setFillColor(sf::Color(133,133,121,255));
            back_rects[3].setFillColor(sf::Color(133,104,104,255));

            sf::RenderTexture output;
            output.create(output_size.x,output_size.y);
            output.clear(sf::Color(104, 133, 133, 255));
            for(auto &b: back_rects) output.draw(b);
            for(auto &m: moves) output.draw(m);
            for(auto &s: stances) output.draw(s);
            for(auto &s: stance_dirs) output.draw(s);
            for(auto &t: tls) output.draw(t);
            output.display();
            string output_name = *split(string(argv[args]), '\\').rbegin();
            output_name = output_name.substr(0,output_name.size()-4);
            output_name += "_map.png";
            output.getTexture().copyToImage().saveToFile(output_name);
            cout << endl << endl << endl;
        }
    }
    cout << "Done" << endl;
    char dud;
    cin >> dud;
    return 0;
}

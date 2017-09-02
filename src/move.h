using namespace std;

enum stance {undefined, top_right, bottom_right, top_left, bottom_left};

class Move : public sf::Drawable {
private:
    void draw(sf::RenderTarget&, sf::RenderStates) const;
public:
    stance end_stance;
    sf::Sprite sprite;
    Move(sf::Texture&, const sf::IntRect&, const sf::Vector2f&);
    void setPosition(const sf::Vector2f&);
    sf::Vector2f getPosition() const;
    sf::Vector2f getCorner(const sf::Vector2f&);
    sf::Vector2f getSide(const sf::Vector2f&);
    sf::Vector2f getCornerOrSide(const sf::Vector2f&);
};

using namespace std;

float dist(const sf::Vector2f&, const sf::Vector2f&);
float colorDifference(const sf::Color&, const sf::Color&);
sf::Vector2i scaleVector(const sf::Vector2i&, const sf::Vector2u&);
int fixIndex(int);
vector<string> split(const string& s, char delim);

class ThickLine : public sf::RectangleShape {
private:
	sf::Vector2f a, b;
	float thickness;
public:
	ThickLine();
	ThickLine(const sf::Vector2f&, const sf::Vector2f&, float, const sf::Color&);
	void setA(const sf::Vector2f&);
	void setB(const sf::Vector2f&);
	void setThickness(const float&);
	sf::Vector2f getA() const;
	sf::Vector2f getB() const;
	float getThickness() const;
	void update(const sf::Vector2f&, const sf::Vector2f&);
};

class ThickLineSet : public sf::Drawable {
private:
    sf::Vector2f a, b;
    vector<ThickLine> lines;
    float thickness1, thickness2;
    sf::Color color;
    void draw(sf::RenderTarget&, sf::RenderStates) const;
public:
    ThickLineSet(const sf::Vector2f&, const sf::Vector2f&, float, float, const sf::Color&);
    void update(const sf::Vector2f&, const sf::Vector2f&);
};

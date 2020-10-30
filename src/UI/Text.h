#include <string>
#include <SFML/Graphics.hpp>

using std::string;
class Text {
    public:
        Text(sf::RenderWindow* window, sf::Font* font, string text, int size, sf::Color color, sf::Uint32 style);
        ~Text();

        void SetPosition(double x, double y);
        void Move(double x, double y);
        double GetX();
        double GetY();

        void Draw();

    private:
        sf::Text* txt = NULL;
        sf::RenderWindow* w = NULL;
};
#include <string>
#include <SFML/Graphics.hpp>
#include <cstdint>

using std::string;
class Text {
    public:
        Text(sf::RenderWindow* window, sf::Font* font,string text, int size, sf::Color color, uint32_t style);
        ~Text();

        void SetPosition(double x, double y);
        void Move(double x, double y);
        double GetX();
        double GetY();

        void DrawText();

    private:
        sf::Text* txt = NULL;
        sf::RenderWindow* w;
};
#include <SFML/Graphics.hpp>

//Will be rewritten!!! No use now!!!
namespace mine_grid
{
    class Cell
    {
    private:
        sf::Vector2f _position;
        sf::Color _color;
        bool _isVisible;

        bool is_opened;
        bool has_mine;
    public:
        Cell();
        ~Cell();

        void on_lmb_release();
    }
}
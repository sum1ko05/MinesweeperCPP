#include <SFML/Graphics.hpp>
#include "core/include/app.hpp"
#ifdef INCUDE_DICE_LIB
#include <dice_lib/dice_lib.hpp>
#endif
//#include <my_library/my_library.hpp>

int main()
{
    //std::cout << my_library::add(42, 27) << std::endl;
    #ifdef INCUDE_DICE_LIB
    dice_lib::print_character_characteristics();
    #endif
    mine_core::App app;
    app.run();
    return 0;
}
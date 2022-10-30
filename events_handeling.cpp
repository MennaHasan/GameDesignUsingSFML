#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main(){

    RenderWindow window(VideoMode(900,700), "First Window");


    while(window.isOpen()){

    Event ev;

    while(window.pollEvent(ev)){
        if(ev.type == Event::Closed){

        window.close();
    }

    if(ev.type == Event::GainedFocus){

        std::cout << "the window gained focus\n";
    }

        if(ev.type == Event::KeyPressed){
                if(ev.key.code == Keyboard::Up){
                    std::cout << "keyboard up button is pressed \n"  ;
                }
        }


        if(ev.type == Event::MouseButtonPressed){

                if(ev.mouseButton.button == Mouse::Right){
                        std::cout <<  "right mouse clicked\n";
                }
        }



        if(ev.type == Event::MouseEntered){
                std::cout << "mouse entered the window\n" ;

        }
    }
    }

return 0;
}

#include <SFML/Graphics.hpp>
//#include <RectangleShape.hpp>
#include <iostream>
//using namespace std;
using namespace sf;

int main()
{
   //making the window show up
   RenderWindow window(VideoMode(900,600), "First Game");

   RectangleShape rshape(Vector2f(100,500));

    // loop to be repeated, to keep window open (as main doesn't return this way)
   while(window.isOpen()){
       // declaring an event
       Event ev;

       while (window.pollEvent(ev)){
            if(ev.type == Event::Closed){

                window.close();
            }
            if(ev.type == Event::KeyPressed){
                if(ev.key.code == Keyboard::Up){
                    std:: cout << ev.key.control << "   " << std::endl;
                }
            }
            if(ev.type == Event::MouseMoved){
                    std:: cout << "MOVED    " << std::endl;
            }
            if(ev.type == Event::MouseButtonPressed){
                    if(ev.mouseButton.button == Mouse::Right){
                    std:: cout << "right mouse click pressed   " << std::endl;
                }
            }
       }
   }
    return EXIT_SUCCESS;
}

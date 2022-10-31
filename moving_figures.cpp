// This file was created by Menatalla Hassan during day 2 of the Hackathon
// this program aims to use rectangles and sprites to show a picture and move/rotate/scale them according to input from the keyboard

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
   //defining dimensions of window 
   int windowx = 1000;
   int windowy = 1000;
  
   //creating the window object, giving it dimensions and title 
   RenderWindow window(VideoMode(windowx,windowy), "First Game");
   
   //setting a frame limit to the window 
   window.setFramerateLimit(60);
  
   //creating 2 texture objects for the pictures used 
   Texture killua_pic, Gon_pic;

   //loading pictures from files to the textures
   Gon_pic.loadFromFile("Gon.JPG");
   killua_pic.loadFromFile("killua.JPG");

    // creating variables to save positions of textures in   
    int killua_xposition  = 100;
    int killua_yposition = 100;
    int Gon_xposition = 120;
    int Gon_yposition = 120;

   // loop to be repeated, to keep window open (as main does not return this way)
   while(window.isOpen()){
       // declaring an ev object from class Event
       Event ev;

     //creating a sprite for first texture 
   Sprite killua_box;
     //defining texture, position, and color for the sprite 
   killua_box.setTexture(killua_pic);
   killua_box.setPosition(killua_xposition,killua_yposition);
   killua_box.setOrigin(100,100);
   killua_box.setColor(Color(255,255,255));


    //creating a rectangle shape for first texture 
    RectangleShape Gon_shape(Vector2f(500,500));
    //defining texture, position, and color for the sprite
    Gon_shape.setTexture(&Gon_pic);
    Gon_shape.setPosition(Gon_xposition,Gon_yposition);
    Gon_shape.setOrigin(50,50);
    Gon_shape.setFillColor(Color(255,255,255));


        //controlling position of the first character (sprite) using ASWD keys
        // if statements to make sure picture cross borders to the opposite one and doesn't disappear from window
        if (Keyboard::isKeyPressed(Keyboard::S)){
            std:: cout << "S pressed" << std::endl;
            killua_yposition += 3;
            if (killua_yposition> windowy){
                killua_yposition = 0;
            }
            killua_box.setPosition(killua_xposition,killua_yposition);

        }
        if (Keyboard::isKeyPressed(Keyboard::D)){
            std:: cout << "D pressed" << std::endl;
            killua_xposition += 3;

            if (killua_xposition> windowx){
                killua_xposition = 0;
            }
            killua_box.setPosition(killua_xposition,killua_yposition);

        }
        if (Keyboard::isKeyPressed(Keyboard::A)){
            std:: cout << "A pressed" << std::endl;
            killua_xposition -= 3;
            if (killua_xposition < 0){
                killua_xposition = windowx;
            }

            killua_box.setPosition(killua_xposition,killua_yposition);

        }
        if (Keyboard::isKeyPressed(Keyboard::W)){
            std:: cout << "W pressed" << std::endl;

            killua_yposition -= 3;
            if (killua_yposition <  0){
                killua_yposition = windowy;
            }
            killua_box.setPosition(killua_xposition,killua_yposition);

        }
        if (Keyboard::isKeyPressed(Keyboard::R)){
            std:: cout << "R pressed" << std::endl;
            killua_box.rotate(50.0f);
        }



        //controlling position of the second character (rectangle shape) using ASWD keys
        // if statements to make sure picture cross borders to the opposite one and doesn't disappear from window
        if (Keyboard::isKeyPressed(Keyboard::Down)){
            std:: cout << "Down  pressed" << std::endl;
            //Gon_shape.move(Vector2f(3f,3f));
            Gon_yposition += 3;
            Gon_shape.setPosition(Gon_xposition,Gon_yposition);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)){
            std:: cout << "Right  pressed" << std::endl;
            Gon_xposition += 3;
            Gon_shape.setPosition(Gon_xposition,Gon_yposition);

        }
        if (Keyboard::isKeyPressed(Keyboard::Left)){
            std:: cout << "Left pressed" << std::endl;
            Gon_xposition -= 3;
            Gon_shape.setPosition(Gon_xposition,Gon_yposition);

        }
        if (Keyboard::isKeyPressed(Keyboard::Up)){
            std:: cout << "UP pressed" << std::endl;
            Gon_yposition -= 3;
            Gon_shape.setPosition(Gon_xposition,Gon_yposition);
        }
        if (Keyboard::isKeyPressed(Keyboard::O)){
            std:: cout << "o pressed" << std::endl;
            Gon_shape.rotate(50.0f);
        }
     
        //change the picture uploaded for rectangle when J key is pressed
        if (Keyboard::isKeyPressed(Keyboard::J)){
            std:: cout << "J pressed" << std::endl;
            Gon_pic.loadFromFile("Gon_jump.JPG");
            Gon_yposition -= 3;
        }

       // clearing previous frame
       window.clear();
       //drawing the sprite and rectangle on the window
       window.draw(killua_box);
       window.draw(Gon_shape);
        
       //displaying window contents 
       window.display();
   }
    return EXIT_SUCCESS;
}

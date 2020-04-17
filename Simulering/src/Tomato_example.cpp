#include "Tomato.h"
#include "Cucumber.h"
#include "Melon.h"
#include "graphics.h"
#include <iostream>
#include "water_reservoir.h"
#include <math.h>

#define PI 3.14159265
void dataWindow(sf::Vector2u pos, WaterReservoir &reservoir, sf::RenderWindow &window);

double degtorad(double deg){
    double rad =  (deg * PI) / 180.0 ;
    return rad;
}
int main(int argc, char const *argv[])
{

 // create the window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Tomato Simulator");
    window.setFramerateLimit(144);
    ImGui::SFML::Init(window);

    //Defines a vector consisting of pointers of type "PlantBase"
    std::vector<std::shared_ptr<PlantBase>> greenhouse;

    //Defines a Waterreservoir, for later use in the grow() function.
    WaterReservoir Reservoir;

    int days = 0;

    //Pushes pointer into greenhouse - respresenting tomatos and cucumbers
    float windowHeight = window.getSize().y;
    greenhouse.push_back(std::make_shared<Tomato>(335.0F, windowHeight-190));
    greenhouse.push_back(std::make_shared<Tomato>(200.0F, windowHeight));
    greenhouse.push_back(std::make_shared<Cucumber>(300.0F, windowHeight));
    greenhouse.push_back(std::make_shared<Melon>(550.0F, windowHeight-150));
    greenhouse.push_back(std::make_shared<Melon>(620.0F, windowHeight-190));
    greenhouse.push_back(std::make_shared<Melon>(800.0F, windowHeight));
    sf::Clock deltaClock;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ImGui::SFML::Update(window, deltaClock.restart());
        ImGui::SetNextItemWidth(100.0);

        // clear the window with black color
        window.clear(sf::Color::Black);

        



        //Create dialog box
        ImGui::Begin("Greenhouse");
        //Button
        if (ImGui::SliderInt("Days to grow", &days, 0., 10.)){}

        if (ImGui::Button("GROW THANKS", {200.0, 20.0}))
        {
            for (size_t i = 0; i < greenhouse.size(); i++)
                greenhouse[i]->grow(days, Reservoir);
                std::cout << "Nutrition level er: " << Reservoir.getNutrition() << std::endl;
        }

        if(ImGui::Button("Fill up Water", {200.0, 20.0})){
            Reservoir.FillUp('w', 100);
        }
        
        if(ImGui::Button("Fill up Nutrition", {200.0, 20.0})){
            Reservoir.FillUp('n', 100);
        }
        
        ImGui::End();
        /**********************************************************************
        *                              Graphics
        * *********************************************************************/
       sf::Vector2u pos {1000,50};
        dataWindow(pos,Reservoir,window);

        for (size_t i = 0; i < greenhouse.size(); i++)
        {
            greenhouse[i]->draw(window);
        }


        int posx = 500;
        int posy = 650;
        float length = 300.0F;
        float width = 150.0F;
        float height = 100.0F;

        sf::RectangleShape greenhouseDraw1;
        greenhouseDraw1.setSize({5.0F,length});
        greenhouseDraw1.setRotation(240);
        greenhouseDraw1.setPosition(posx,posy);
        window.draw(greenhouseDraw1);

        sf::RectangleShape greenhouseDraw2;
        greenhouseDraw2.setSize({5.0F,height});
        greenhouseDraw2.setRotation(180);
        greenhouseDraw2.setPosition(posx,posy);
        window.draw(greenhouseDraw2);

        sf::RectangleShape greenhouseDraw3;
        greenhouseDraw3.setSize({5.0F,width*1.5F});
        greenhouseDraw3.setRotation(120);
        greenhouseDraw3.setPosition(posx,posy);
        window.draw(greenhouseDraw3);

        sf::RectangleShape greenhouseDraw4;
        greenhouseDraw4.setSize({5.0F,length});
        greenhouseDraw4.setRotation(240);
        greenhouseDraw4.setPosition(posx,posy-100);
        window.draw(greenhouseDraw4);

        sf::RectangleShape greenhouseDraw5;
        greenhouseDraw5.setSize({5.0F,width});
        greenhouseDraw5.setRotation(120);
        greenhouseDraw5.setPosition(posx,posy-100);
        window.draw(greenhouseDraw5);

        sf::RectangleShape greenhouseDraw6;
        greenhouseDraw6.setSize({5.0F,height});
        greenhouseDraw6.setRotation(180);
        greenhouseDraw6.setPosition(posx+cos(degtorad(30))*length,posy-sin(degtorad(30))*length);
        window.draw(greenhouseDraw6);

        sf::RectangleShape greenhouseDraw7;
        greenhouseDraw7.setSize({5.0F,150.0F});
        greenhouseDraw7.setRotation(120);
        greenhouseDraw7.setPosition(posx+cos(degtorad(30))*length,posy-sin(degtorad(30))*length-100);
        window.draw(greenhouseDraw7);

        sf::RectangleShape greenhouseDraw8;
        greenhouseDraw8.setSize({5.0F,length});
        greenhouseDraw8.setRotation(180);
        greenhouseDraw8.setPosition(posx-cos(degtorad(30))*width,posy-sin(degtorad(30))*width);
        window.draw(greenhouseDraw8);


        sf::RectangleShape greenhouseDraw9;
        greenhouseDraw9.setSize({5.0F,length});
        greenhouseDraw9.setRotation(240);
        greenhouseDraw9.setPosition(posx-cos(degtorad(30))*width,posy-sin(degtorad(30))*width-100);
        window.draw(greenhouseDraw9);

        sf::RectangleShape greenhouseDraw10;
        greenhouseDraw10.setSize({5.0F,length});
        greenhouseDraw10.setRotation(180);
        greenhouseDraw10.setPosition(posx-cos(degtorad(30))*width*1.5,posy-sin(degtorad(30))*width*1.5);
        window.draw(greenhouseDraw10);

        sf::RectangleShape greenhouseDraw11;
        greenhouseDraw11.setSize({5.0F,length});
        greenhouseDraw11.setRotation(240);
        greenhouseDraw11.setPosition(posx-cos(degtorad(30))*width,(posy-sin(degtorad(30))*width)-length);
        window.draw(greenhouseDraw11);

        sf::RectangleShape greenhouseDraw12;
        greenhouseDraw12.setSize({5.0F,length});
        greenhouseDraw12.setRotation(240);
        greenhouseDraw12.setPosition(posx-cos(degtorad(30))*width*1.5,(posy-sin(degtorad(30))*width*1.5)-length);
        window.draw(greenhouseDraw12);

        sf::RectangleShape greenhouseDraw13;
        greenhouseDraw13.setSize({5.0F,width*0.5F});
        greenhouseDraw13.setRotation(120);
        greenhouseDraw13.setPosition(posx-cos(degtorad(30))*width,(posy-sin(degtorad(30))*width)-length);
        window.draw(greenhouseDraw13);

        sf::RectangleShape greenhouseDraw14;
        greenhouseDraw14.setSize({5.0F,width*0.5F});
        greenhouseDraw14.setRotation(120);
        greenhouseDraw14.setPosition((posx-cos(degtorad(30))*width)+cos(degtorad(30))*length,((posy-sin(degtorad(30))*width)-length)-sin(degtorad(30))*length);
        window.draw(greenhouseDraw14);

        sf::RectangleShape greenhouseDraw15;
        greenhouseDraw15.setSize({5.0F,length-height});
        greenhouseDraw15.setRotation(0);
        greenhouseDraw15.setPosition((posx-cos(degtorad(30))*width)+cos(degtorad(30))*length,((posy-sin(degtorad(30))*width)-length)-sin(degtorad(30))*length);
        window.draw(greenhouseDraw15);





        ImGui::SFML::Render(window);
        // end the current frame
        window.display();
    }
}



void dataWindow(sf::Vector2u pos, WaterReservoir &reservoir, sf::RenderWindow &window){
        sf::Vector2f posFloat {(float)pos.x,(float)pos.y};
        sf::RectangleShape rect;
        rect.setSize({200.0F,300.0F});
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineColor(sf::Color::White);
        rect.setOutlineThickness(5.0F);
        rect.setPosition(posFloat);
        window.draw(rect);

        sf::Font font;
        font.loadFromFile("arial_narrow_7.ttf");
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);

        text.setString("Levels");
        text.setPosition(pos.x+70,pos.y+10);
        window.draw(text);
        const std::vector<char> letters = {'W','K','P','N'};
        
        for (int i = 0; i < letters.size(); i++)
        {
            int offset = 45;
            int spacing = 40;
            text.setString(letters[i]);
            text.setPosition(pos.x+offset+(spacing*i)-text.getLocalBounds().width,pos.y+70);
            window.draw(text);
            sf::RectangleShape outerShape;
            outerShape.setSize({21.0F,153.0F});
            outerShape.setPosition(pos.x+offset+(spacing*i)-text.getLocalBounds().width/2-outerShape.getGlobalBounds().width/2,pos.y+110);
            window.draw(outerShape);
            sf::RectangleShape innerShape;
            innerShape.setFillColor(sf::Color::Blue);
            innerShape.setSize({15.0F,147.0F*((float)reservoir.getNutrition(letters[i]))/100.0F});
            innerShape.setPosition(pos.x+offset+(spacing*i)-text.getLocalBounds().width/2-innerShape.getGlobalBounds().width/2,pos.y+113+147-innerShape.getGlobalBounds().height);
            window.draw(innerShape);



        }
        


}
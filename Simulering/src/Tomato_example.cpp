#include "Tomato.h"
#include "Cucumber.h"
#include "Melon.h"
#include "graphics.h"
#include <iostream>
#include "water_reservoir.h"
#include <math.h>

#define PI 3.14159265

double degtorad(double deg){
    double rad =  (deg * PI) / 180.0 ;
    return rad;
}
int main(int argc, char const *argv[])
{
float offsetXkim = 300;
float offsetYkim = -40;
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
    float windowLength = window.getSize().x;
    greenhouse.push_back(std::make_shared<Tomato>(470.0F-offsetXkim, windowHeight-160-offsetYkim));
    greenhouse.push_back(std::make_shared<Tomato>(570.0F-offsetXkim, windowHeight-200-offsetYkim));
    greenhouse.push_back(std::make_shared<Cucumber>(670.0F-offsetXkim, windowHeight-250-offsetYkim));
    greenhouse.push_back(std::make_shared<Melon>(705.0F-offsetXkim, windowHeight-190-offsetYkim));
    greenhouse.push_back(std::make_shared<Melon>(625.0F-offsetXkim, windowHeight-150-offsetYkim));
    greenhouse.push_back(std::make_shared<Melon>(550.0F-offsetXkim, windowHeight-100-offsetYkim));
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

        //Setup background
        sf::RectangleShape background;
        sf::Texture bg;
        bg.loadFromFile("Kim.png");
        background.setSize({windowLength, windowHeight});
        background.setTexture(&bg);

        //setup greenhouse
        float sizegh {600};
        float posx = (windowLength-sizegh)/2;
        float posy {100};
        sf::RectangleShape GreenhouseBack;
        sf::Texture gh;
        gh.loadFromFile("drivhusBagerst.png");
        GreenhouseBack.setSize({sizegh, sizegh});
        GreenhouseBack.setPosition({posx-offsetXkim, posy-offsetYkim});
        GreenhouseBack.setTexture(&gh);

        //setup greenhouse Front
        sf::RectangleShape GreenhouseFront;
        sf::Texture ghf;
        ghf.loadFromFile("drivhusForrest.png");
        GreenhouseFront.setSize({sizegh, sizegh});
        GreenhouseFront.setPosition({posx-offsetXkim, posy-offsetYkim});
        GreenhouseFront.setTexture(&ghf);

        // clear the window with black color
        window.clear(sf::Color::Transparent);
        window.draw(background);
        window.draw(GreenhouseBack);


        //Create dialog box
        ImGui::Begin("Greenhouse");
        //Button
        ImVec2 size = {200, 100};
        const float values[4] = {(float)Reservoir.getNutrition('N'), (float)Reservoir.getNutrition('P'), (float)Reservoir.getNutrition('K'), (float)Reservoir.getNutrition('W')};
        ImGui::PlotHistogram("##values", values, IM_ARRAYSIZE(values), 0, NULL, 0.0f, 100.0f, size);
        ImGui::Text("N: %f", Reservoir.getNutrition('N'));
        ImGui::Text("P: %f", Reservoir.getNutrition('P'));
        ImGui::Text("K: %f", Reservoir.getNutrition('K'));
        ImGui::Text("W: %f", Reservoir.getNutrition('W'));
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
        if(ImGui::Button("GrOw DoWn", {200.0, 20.0})){
            for (size_t i = 0; i < greenhouse.size(); i++)
                greenhouse[i]->grow(-days, Reservoir);
                std::cout << "Nutrition level er: " << Reservoir.getNutrition() << std::endl;
        }
        ImGui::End();
        /**********************************************************************
        *                              Graphics
        * *********************************************************************/

        for (size_t i = 0; i < greenhouse.size(); i++)
        {
            greenhouse[i]->draw(window);
        }


        // int posx = 500;
        // int posy = 650;
        // float length = 300.0F;
        // float width = 150.0F;
        // float height = 100.0F;

        // sf::RectangleShape greenhouseDraw1;
        // greenhouseDraw1.setSize({5.0F,length});
        // greenhouseDraw1.setRotation(240);
        // greenhouseDraw1.setPosition(posx,posy);
        // window.draw(greenhouseDraw1);

        // sf::RectangleShape greenhouseDraw2;
        // greenhouseDraw2.setSize({5.0F,height});
        // greenhouseDraw2.setRotation(180);
        // greenhouseDraw2.setPosition(posx,posy);
        // window.draw(greenhouseDraw2);

        // sf::RectangleShape greenhouseDraw3;
        // greenhouseDraw3.setSize({5.0F,width*1.5F});
        // greenhouseDraw3.setRotation(120);
        // greenhouseDraw3.setPosition(posx,posy);
        // window.draw(greenhouseDraw3);

        // sf::RectangleShape greenhouseDraw4;
        // greenhouseDraw4.setSize({5.0F,length});
        // greenhouseDraw4.setRotation(240);
        // greenhouseDraw4.setPosition(posx,posy-100);
        // window.draw(greenhouseDraw4);

        // sf::RectangleShape greenhouseDraw5;
        // greenhouseDraw5.setSize({5.0F,width});
        // greenhouseDraw5.setRotation(120);
        // greenhouseDraw5.setPosition(posx,posy-100);
        // window.draw(greenhouseDraw5);

        // sf::RectangleShape greenhouseDraw6;
        // greenhouseDraw6.setSize({5.0F,height});
        // greenhouseDraw6.setRotation(180);
        // greenhouseDraw6.setPosition(posx+cos(degtorad(30))*length,posy-sin(degtorad(30))*length);
        // window.draw(greenhouseDraw6);

        // sf::RectangleShape greenhouseDraw7;
        // greenhouseDraw7.setSize({5.0F,150.0F});
        // greenhouseDraw7.setRotation(120);
        // greenhouseDraw7.setPosition(posx+cos(degtorad(30))*length,posy-sin(degtorad(30))*length-100);
        // window.draw(greenhouseDraw7);

        // sf::RectangleShape greenhouseDraw8;
        // greenhouseDraw8.setSize({5.0F,300.0F});
        // greenhouseDraw8.setRotation(180);
        // greenhouseDraw8.setPosition(posx-cos(degtorad(30))*width,posy-sin(degtorad(30))*width);
        // window.draw(greenhouseDraw8);


        // sf::RectangleShape greenhouseDraw9;
        // greenhouseDraw9.setSize({5.0F,length});
        // greenhouseDraw9.setRotation(240);
        // greenhouseDraw9.setPosition(posx-cos(degtorad(30))*width,posy-sin(degtorad(30))*width-100);
        // window.draw(greenhouseDraw9);

        // sf::RectangleShape greenhouseDraw10;
        // greenhouseDraw10.setSize({5.0F,300.0F});
        // greenhouseDraw10.setRotation(180);
        // greenhouseDraw10.setPosition(posx-cos(degtorad(30))*width*1.5,posy-sin(degtorad(30))*width*1.5);
        // window.draw(greenhouseDraw10);

        // sf::RectangleShape greenhouseDraw11;
        // greenhouseDraw11.setSize({5.0F,length});
        // greenhouseDraw11.setRotation(240);
        // greenhouseDraw11.setPosition(posx-cos(degtorad(30))*width,(posy-sin(degtorad(30))*width)-length);
        // window.draw(greenhouseDraw11);

        // sf::RectangleShape greenhouseDraw12;
        // greenhouseDraw12.setSize({5.0F,length});
        // greenhouseDraw12.setRotation(240);
        // greenhouseDraw12.setPosition(posx-cos(degtorad(30))*width*1.5,(posy-sin(degtorad(30))*width*1.5)-length);
        // window.draw(greenhouseDraw12);

        // sf::RectangleShape greenhouseDraw13;
        // greenhouseDraw13.setSize({5.0F,width*0.5F});
        // greenhouseDraw13.setRotation(120);
        // greenhouseDraw13.setPosition(posx-cos(degtorad(30))*width,(posy-sin(degtorad(30))*width)-length);
        // window.draw(greenhouseDraw13);

        // sf::RectangleShape greenhouseDraw14;
        // greenhouseDraw14.setSize({5.0F,width*0.5F});
        // greenhouseDraw14.setRotation(120);
        // greenhouseDraw14.setPosition((posx-cos(degtorad(30))*width)+cos(degtorad(30))*length,((posy-sin(degtorad(30))*width)-length)-sin(degtorad(30))*length);
        // window.draw(greenhouseDraw14);

        // sf::RectangleShape greenhouseDraw15;
        // greenhouseDraw15.setSize({5.0F,height*2});
        // greenhouseDraw15.setRotation(0);
        // greenhouseDraw15.setPosition((posx-cos(degtorad(30))*width)+cos(degtorad(30))*length,((posy-sin(degtorad(30))*width)-length)-sin(degtorad(30))*length);
        // window.draw(greenhouseDraw15);



        window.draw(GreenhouseFront);

        ImGui::SFML::Render(window);
        // end the current frame
        window.display();
    }
}



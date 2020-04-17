#include "graphics.h"

Graphics::Graphics() : window(sf::VideoMode(1280, 720), "Tomato Simulator")
{

    greenhouse.push_back(std::make_shared<Tomato>(100.0F, 720.0F));
    greenhouse.push_back(std::make_shared<Tomato>(200.0F, 720.0F));
    greenhouse.push_back(std::make_shared<Cucumber>(300.0F, 720.0F));

    standardGraphics();
}

Graphics::~Graphics()
{
}
//This function contains only the standard setup of SFML and IMGUI, with the exception of one line calling the custom graphics for the project.
void Graphics::standardGraphics()
{
    // create the window
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

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

        //customGraphics();

        ImGui::SFML::Render(window);
        // end the current frame
        window.display();
    }
}

void Graphics::customGraphics()
{
    //Create dialog box
    ImGui::Begin("Hello, world");
    //Button
    if (ImGui::Button("GROW THANKS", {100.0, 20.0}))
    {
        for (size_t i = 0; i < greenhouse.size(); i++)
            greenhouse[i]->grow(2, Reservoir);
    }
    ImGui::End();

    for (size_t i = 0; i < greenhouse.size(); i++)
    {
        greenhouse[i]->draw(window);
    }
}

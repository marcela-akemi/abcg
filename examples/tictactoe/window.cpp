#include "window.hpp"
#include <chrono>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>


using namespace std;

void Window::onCreate() {
  // Load font with bigger size for the X's and O's
  auto const filename{abcg::Application::getAssetsPath() +
                      "Inconsolata-Medium.ttf"};
  m_font = ImGui::GetIO().Fonts->AddFontFromFileTTF(filename.c_str(), 72.0f);
  if (m_font == nullptr) {
    throw abcg::RuntimeError{"Cannot load font file"};
  }
  
}
void Window::onPaintUI() {
  // Get size of application's window
  auto const appWindowWidth{gsl::narrow<float>(getWindowSettings().width)};
  auto const appWindowHeight{gsl::narrow<float>(getWindowSettings().height)};
  
  {
    ImGui::SetNextWindowSize(ImVec2(appWindowWidth, appWindowHeight));
    ImGui::SetNextWindowPos(ImVec2(0, 0));

    auto const flags{ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoCollapse};
    ImGui::Begin("Encriptador", nullptr, flags);

    // Static text
    auto const &windowSettings{getWindowSettings()};
    ImGui::Text("Current window size: %dx%d (in windowed mode)",
                windowSettings.width, windowSettings.height);

    // Slider from 0.0f to 1.0f
    static float f{};
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);

    // ColorEdit to change the clear color
  
    ImGui::ColorEdit3("clear color", m_clearColor.data());

    int i;
    

    ImGui::InputText("input text", str, IM_ARRAYSIZE(str));
    if(ImGui::Button("Criptografar", ImVec2(-2, 25)))
    {
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
      {
        temp[i] = str[i];
      }
      for(i = 0; (i < 100 && temp[i] != '\0'); i++){
        temp[i] = temp[i] + 2; //the key for encryption is 3 that is added to ASCII value 
      }
    }
     ImGui::Text("Texto criptografado: %s", temp);
    ImGui::Spacing();
    if(ImGui::Button("Limpar", ImVec2(-2, 25)))
    {
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
      {
        str[i] = {0};
        temp[i] = {0};
      }
    }

    ImGui::End();
  }
}

#include<stdio.h>
#include<math.h>
 
//to find gcd
int gcd(int a, int h)
{
    int temp;
    while(1)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
}
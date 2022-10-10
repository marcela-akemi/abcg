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
  m_font = ImGui::GetIO().Fonts->AddFontFromFileTTF(filename.c_str(), 24.0f);
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
     
     {
     bool testeSelected{};
    
     if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("Menu")) {
          ImGui::MenuItem("Desencriptador", nullptr, &testeSelected);
          ImGui::MenuItem("Sair", nullptr);
          ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
      }
     }
    // Static text
    ImGui::PushFont(m_font);
    ImGui::Text(" " );
    ImGui::Text("Insira texto a ser encriptado: " );

    int i;

    ImGui::InputText(" ", str, IM_ARRAYSIZE(str));
    ImGui::Text(" ");
    ImGui::Text("Texto criptografado: %s", temp);

    if(ImGui::BeginTable("Botoes", 2)){
      ImGui::TableNextColumn();
      if(ImGui::Button("Criptografar", ImVec2(-2, 35)))
      {
        for(i = 0; (i < 100 && str[i] != '\0'); i++)
        {
          temp[i] = str[i];
        }
        for(i = 0; (i < 100 && temp[i] != '\0'); i++){
          temp[i] = temp[i] + 2; //the key for encryption is 3 that is added to ASCII value 
        }
      }
      ImGui::TableNextColumn();
      if(ImGui::Button("Limpar", ImVec2(-2, 35)))
       {
        for(i = 0; (i < 100 && str[i] != '\0'); i++)
        {
          str[i] = {0};
          temp[i] = {0};
        }
      }
      ImGui::EndTable(); 
    }
    ImGui::PopFont();

    ImGui::End();
  }

}




 

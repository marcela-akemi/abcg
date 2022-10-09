#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "abcgOpenGL.hpp"

class Window : public abcg::OpenGLWindow {
protected:
  void onCreate() override;
  void onPaintUI() override;

private:
  static int const m_N{3}; // Board size is m_N x m_N

  enum class GameState { Play, Draw, WinX, WinO };
  GameState m_gameState;
  bool timer_set = false;
  bool m_XsTurn{true};
  char str[100] = {0};
  char temp[100] = {0};
  std::array<char, m_N * m_N> m_board{}; // '\0', 'X' or 'O'
  std::array<char, m_N * m_N> m_values{}; // '\0', 'X' or 'O'
  std::array<char, m_N * m_N> m_backup{}; // '\0', 'X' or 'O'
  std::array<char, m_N * m_N> m_resposta{}; // '\0', 'X' or 'O'

  std::array<float, 4> m_clearColor{0.906f, 0.910f, 0.918f, 1.0f};
 

  ImFont *m_font{};

  void checkEndCondition();
  void restartGame();



};

#endif

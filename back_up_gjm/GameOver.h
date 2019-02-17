#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <Arduboy2.h>

class GameOver {
  private:
  Arduboy2 arduboy;
  
  public:
    GameOver();
    ~GameOver();
    void Draw(const unsigned char*);
};



GameOver::GameOver(){
  
}

GameOver::~GameOver(){
  delete this;
}

void GameOver::Draw(const unsigned char* sprite){
  Sprites::drawSelfMasked(89,40,sprite,0);
}

#endif

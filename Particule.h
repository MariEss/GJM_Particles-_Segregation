#ifndef PARTICULE_H
#define PARTICULE_H
#include <Arduboy2.h>

//Sommaire apparently
class Particule {
  private:
  int status; //Electron or proton ?
  Arduboy2 arduboy;
  
  
  public:
  Particule(); //Créateur
  ~Particule(); //Destructeur
  void Draw(const unsigned char*); //Fonction qui permet d'afficher la particule
  int y;
  int Getstatus();
  int Changestatus();
  int Verif();
  void coordonnee();
};



//Définition de l'apparition de la particule
Particule::Particule()
{
  status = random(0,2); // 0=- ; 1=+
}

//Définition du destructeur de la particule
Particule::~Particule()
{
  delete this; //Détruit la particule
}

//Définition de la fonction qui permet d'afficher la particule
void Particule::Draw(const unsigned char* sprite)
{
  Sprites::drawSelfMasked(64-4,y,sprite,status); //le status change le sprite (double sprite !)
}


int Particule::Getstatus()
{
  return status;
}


int Particule::Changestatus()
{
  status = random(0,2);
}


int Particule::Verif()
{
  if(arduboy.pressed(LEFT_BUTTON) and y==32-5 and status==0){
    y=-100;
    Changestatus();
    return 0;
  } else if (arduboy.pressed(RIGHT_BUTTON) and y==32-5 and status==1){
    y=-100;
    Changestatus();
    return 0;
  } else if (y!=32-5){
    //Nothing happens
    return 0;
  } else if (y==32-5 and status==1 and arduboy.pressed(LEFT_BUTTON) or y==32-5 and status==0 and arduboy.pressed(RIGHT_BUTTON)){
    return -1;
  } else{
    return 0;
  }
}


void Particule::coordonnee()
{
  if (y<32-5)
  {
    y++;
  }
}


#endif

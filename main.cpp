#include <iostream>
#include "./headers/sculptor.h"

int main() {
  Sculptor letra_e(10,10,10);
  letra_e.setColor(0,0,1.0,1.0);
  letra_e.putBox(0,9,0,2,0,2);
  letra_e.putBox(0,5,2,4,0,2);
  letra_e.putBox(0,9,4,6,0,2);
  letra_e.putBox(0,5,6,8,0,2);
  letra_e.putBox(0,9,8,10,0,2);
  // letra_e.cutBox(1,8,1,9,1,9);
  letra_e.writeOFF("off_files/e.off");
}
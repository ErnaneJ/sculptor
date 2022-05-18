#include <iostream>
#include "./headers/sculptor.h"

int main() {
  Sculptor Placa(100,75,100);
  Sculptor trono(10,10,10);
  trono.setColor(0,0,1.0,1.0);
  trono.putBox(0,9,0,9,0,9);
  trono.cutBox(1,8,1,9,1,9);
  trono.writeOFF("off_files/trono.off");
}
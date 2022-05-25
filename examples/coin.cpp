#include <iostream>
#include "./headers/sculptor.h"

int main() {
  Sculptor coin(50,50,50);

  coin.setColor(233.0/255.0, 124.0/255.0, 3.0/255.0,1.0);
  
    coin.putEllipsoid(8, 8, 3, 8, 8, 3);

  coin.setColor(255.0/255.0, 222.0/255.0, 23.0/255.0,1.0);

    coin.putEllipsoid(8, 8, 3, 7, 7, 6);

    coin.cutBox(0, 17, 0, 17, 0, 2);
    coin.cutBox(0, 17, 0, 17, 5, 17);

    coin.cutBox(0, 17, 0, 1, 0, 17);
    coin.cutBox(0, 1, 0, 17, 0, 17);
    coin.cutBox(16, 17, 0, 17, 0, 17);
    coin.cutBox(0, 17, 16, 17, 0, 17);
  
  coin.setColor(233.0/255.0, 124.0/255.0, 3.0/255.0,1.0);

    coin.putBox(8, 9, 4, 13, 1, 6);
    coin.putBox(6, 11, 11, 12, 1, 6);
    coin.putBox(6, 11, 8, 9, 1, 6);
    coin.putBox(6, 11, 5, 6, 1, 6);

    coin.putBox(5, 6, 9, 11, 1, 6);
    coin.putBox(11, 12, 6, 8, 1, 6);

    coin.putBox(11, 12, 10, 11, 1, 6);
    coin.putBox(5, 6, 6, 7, 1, 6);

  coin.setColor(255.0/255.0, 255.0/255.0, 255.0/255.0,1.0);

    coin.putBox(12, 13, 4, 5, 2, 5);
    coin.putBox(2, 3, 10, 12, 2, 5);
    coin.putBox(3, 4, 13, 14, 2, 5);
    coin.putBox(5, 7, 14, 15, 2, 5);
    coin.putBox(4, 5, 11, 12, 2, 5);

  coin.writeOFF("off_files/coin.off");
}
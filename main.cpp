#include <iostream>
#include "./headers/sculptor.h"

void buildFideFaces(Sculptor *bmo, int xi, int xe){
    bmo -> cutBox(11, 12, 7, 9, 3, 7);
    // Pontos
    bmo -> cutVoxel(xi, 24, 3);
    bmo -> cutVoxel(xi, 24, 7);

    bmo -> cutVoxel(xi, 22, 1);
    bmo -> cutVoxel(xi, 22, 5);
    bmo -> cutVoxel(xi, 22, 9);

    bmo -> cutVoxel(xi, 20, 3);
    bmo -> cutVoxel(xi, 20, 7);

    // B
    bmo -> cutBox(xi, xe, 18, 19, 3, 8);
    bmo -> cutVoxel(xi, 17, 3);
    bmo -> cutVoxel(xi, 17, 5);
    bmo -> cutVoxel(xi, 17, 7);
    bmo -> cutVoxel(xi, 16, 4);
    bmo -> cutVoxel(xi, 16, 6);
    
    // M
    bmo -> cutBox(xi, xe, 14, 15, 3, 8);
    bmo -> cutBox(xi, xe, 13, 14, 3, 5);
    bmo -> cutVoxel(xi, 12, 5);
    bmo -> cutBox(xi, xe, 11, 12, 3, 5);
    bmo -> cutBox(xi, xe, 10, 11, 3, 8);

    // O
    bmo -> cutBox(xi, xe, 8, 9, 4, 7);
    bmo -> cutBox(xi, xe, 7, 8, 3, 8);
    bmo -> cutBox(xi, xe, 6, 7, 3, 8);
    bmo -> cutBox(xi, xe, 5, 6, 4, 7);
}

void buildBottomFace(Sculptor *bmo){
    bmo -> putBox(8, 10, 0, 4, 4, 7);
    bmo -> cutBox(8, 10, 1, 4, 6, 7);

    bmo -> putBox(16, 18, 0, 4, 4, 7);
    bmo -> cutBox(16, 18, 1, 4, 6, 7);

    bmo -> cutBox(4, 5, 4, 5, 0, 2);
    bmo -> cutBox(4, 5, 4, 5, 10, 12);
    bmo -> cutBox(21, 22, 4, 5, 0, 2);
    bmo -> cutBox(21, 22, 4, 5, 10, 12);
}

void buildBackFace(Sculptor *bmo){
    bmo -> cutBox(8, 18, 6, 7, 0, 1);
    bmo -> cutBox(8, 18, 7, 8, 0, 1);

    bmo -> cutBox(6, 20, 10, 11, 0, 1);
    bmo -> cutBox(6, 7, 10, 16, 0, 1);
    bmo -> cutBox(19, 20, 10, 16, 0, 1);
   
    bmo -> cutVoxel(11,15,0);
    bmo -> cutVoxel(14,15,0);
    bmo -> cutVoxel(12,14,0);
    bmo -> cutVoxel(13,14,0);
   
    bmo -> cutBox(6, 20, 16, 17, 0, 1);

    bmo -> cutBox(6, 7, 19, 25, 0, 1);
    bmo -> cutBox(9, 10, 19, 25, 0, 1);
    bmo -> cutBox(12, 13, 19, 25, 0, 1);
    bmo -> cutBox(15, 16, 19, 25, 0, 1);
    bmo -> cutBox(18, 19, 19, 25, 0, 1);
}

void buildUpperFace(Sculptor *bmo){
  bmo -> cutVoxel(5, 25, 0);
  bmo -> cutVoxel(5, 25, 11);
  bmo -> cutVoxel(20, 25, 0);
  bmo -> cutVoxel(20, 25, 11);
  bmo -> putBox(6, 20, 26, 27, 1, 11);
}

void buildFrontFace(Sculptor *bmo){
  bmo -> setColor(161.0/255.0, 219.0/255.0, 190.0/255.0,1.0); // => Green?

  bmo -> cutBox(6, 20, 16, 24, 11, 12);
  bmo -> putBox(6, 20, 16, 24, 10, 11);

  bmo -> setColor(44.0/255.0, 44.0/255.0, 44.0/255.0,1.0); // => Black Zinc
  bmo -> putBox(11, 12, 20, 22, 10, 11);
  bmo -> putBox(14, 15, 20, 22, 10, 11);
  bmo -> putVoxel(14, 17, 10);

  bmo -> setColor(219.0/255.0, 0.0/255.0, 0.0/255.0,1.0); // => Red
  bmo -> putBox(9, 11, 19, 20, 10, 11);
  bmo -> putBox(15, 17, 19, 20, 10, 11);

  bmo -> cutBox(6, 14, 13, 14, 11, 12);

  bmo -> setColor(0.0/255.0, 44.0/255.0, 219.0/255.0,1.0); // => Blue
  bmo -> putVoxel(18, 13, 11);
}

int main() {
  Sculptor bmo(50,50,50);

  // Main structure
  bmo.setColor(0.0/255.0, 142.0/255.0, 142.0/255.0,1.0); // => Blue Cyan
    bmo.putBox(4, 22, 4, 26, 0, 12);
  bmo.setColor(44.0/255.0, 44.0/255.0, 44.0/255.0,1.0); // => Black Zinc
    bmo.putBox(5, 21, 5, 25, 1, 11);

  bmo.setColor(0.0/255.0, 142.0/255.0, 142.0/255.0,1.0); // => Blue Cyan

  buildBottomFace(&bmo); 
  buildFideFaces(&bmo, 4, 5); // => Direita
  buildFideFaces(&bmo, 21, 22); // => Esquerda
  buildUpperFace(&bmo);
  buildBackFace(&bmo);
  buildFrontFace(&bmo);



  // bmo.setColor(255.0/255.0, 0.0/255.0, 0.0/255.0,1.0);
  
  // bmo.putVoxel(5,25,0);
  // bmo.putVoxel(20,25,0);
  // bmo.putVoxel(5,4,0);
  // bmo.putVoxel(20,4,0);

  bmo.writeOFF("off_files/bmo.off");
}


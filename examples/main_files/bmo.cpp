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
    bmo -> setColor(47.0/255.0, 221.0/255.0, 221.0/255.0,1.0); // => Blue Cyan +
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
  bmo -> setColor(0.0/255.0, 142.0/255.0, 142.0/255.0,1.0); // => Blue Cyan
  bmo -> cutVoxel(4, 25, 0);
  bmo -> cutVoxel(4, 25, 11);
  bmo -> cutVoxel(21, 25, 0);
  bmo -> cutVoxel(21, 25, 11);
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

  bmo -> setColor(219.0/255.0, 219.0/255.0, 0.0/255.0,1.0); // => Yellow
  bmo -> putBox(8, 9, 9, 12, 12, 13);
  bmo -> putBox(7, 10, 10, 11, 12, 13);

  bmo -> setColor(0.0/255.0, 146.0/255.0, 219.0/255.0,1.0); // => Blue Cyan
  bmo -> putBox(13, 16, 10, 11, 12, 13);
  bmo -> putVoxel(14, 11, 12);
  
  bmo -> setColor(219.0/255.0, 0.0/255.0, 0.0/255.0,1.0); // => Red
  bmo -> putBox(16, 18, 7, 9, 12, 13);

  bmo -> setColor(88.0/255.0, 205.0/255.0, 0.0/255.0,1.0); // => Green
  bmo -> putVoxel(19, 10, 12);

  bmo -> cutBox(9, 11, 5, 6, 11, 12);
}

void buildsYarn(Sculptor *bmo){
  bmo -> setColor(44.0/255.0, 44.0/255.0, 44.0/255.0,1.0); // => Black Zinc
  bmo -> putBox(6, 8, 5, 6, 12, 14);
  bmo -> putBox(6, 7, 0, 5, 13, 14);
  bmo -> putBox(2, 7, 0, 1, 13, 14);
  bmo -> putBox(1, 3, 0, 1, 14, 15);
  bmo -> putBox(0, 2, 0, 1, 15, 16);
  bmo -> putBox(0, 1, 0, 1, 16, 18);
  bmo -> putBox(1, 3, 0, 1, 17, 18);
  bmo -> putBox(2, 9, 0, 1, 18, 19);
  bmo -> putBox(8, 10, 0, 1, 17, 18);
  bmo -> putBox(9, 11, 0, 1, 16, 17);
  bmo -> putBox(10, 13, 0, 1, 15, 16);
  bmo -> putBox(12, 14, 0, 1, 16, 17);
  bmo -> putBox(13, 18, 0, 1, 17, 18);
  bmo -> putBox(17, 19, 0, 1, 16, 17);
  bmo -> putBox(18, 20, 0, 1, 15, 16);
  bmo -> putBox(19, 23, 0, 1, 14, 15);
  bmo -> putBox(22, 24, 0, 1, 13, 14);
  bmo -> putBox(23, 24, 0, 1, 11, 14);
  bmo -> putBox(21, 23, 0, 1, 11, 12);
  bmo -> putBox(21, 22, 0, 1, 9, 11);
  bmo -> putBox(21, 23, 0, 1, 9, 10);
  bmo -> putBox(22, 23, 1, 2, 8, 10);
  bmo -> putBox(22, 23, 2, 3, 6, 9);
  bmo -> putBox(22, 23, 3, 4, 1, 4);
  bmo -> putBox(22, 23, 2, 3, 0, 4);
  bmo -> putBox(22, 23, 1, 2, 0, 4);
  bmo -> putBox(22, 23, 0, 1, 1, 3);

  bmo -> setColor(126.0/255.0, 126.0/255.0, 126.0/255.0,1.0); // => Gray
  bmo -> putVoxel(23, 2, 2);

  bmo -> setColor(219.0/255.0, 0.0/255.0, 0.0/255.0,1.0); // => Red
  bmo -> putVoxel(23, 1, 1);
}

void buildLeftArm(Sculptor *bmo){
  bmo -> setColor(47.0/255.0, 221.0/255.0, 221.0/255.0,1.0); // => Blue Cyan +
  bmo -> putVoxel(22, 7, 5);
  bmo -> putBox(22, 23, 2, 7, 4, 7);
  bmo -> putBox(22, 23, 6, 7, 4, 7);
}

void buildRightArm(Sculptor *bmo){
  bmo -> setColor(47.0/255.0, 221.0/255.0, 221.0/255.0,1.0); // => Blue Cyan +
  bmo -> putBox(3, 4, 6, 7, 4, 7);
  bmo -> putBox(3, 4, 7, 8, 4, 8);
  bmo -> putBox(3, 4, 8, 9, 6, 10);
  bmo -> putBox(3, 4, 9, 10, 7, 11);
  bmo -> putBox(3, 4, 10, 11, 8, 12);
  bmo -> putBox(3, 4, 11, 12, 9, 13);
  bmo -> putBox(3, 4, 12, 13, 10, 13);
  bmo -> putBox(3, 4, 13, 14, 11, 13);
  bmo -> putBox(3, 4, 14, 15, 12, 13);
  bmo -> putBox(3, 5, 12, 15, 12, 13);
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
  buildsYarn(&bmo);
  buildRightArm(&bmo);
  buildLeftArm(&bmo);

  bmo.writeOFF("off_files/bmo.off");
}
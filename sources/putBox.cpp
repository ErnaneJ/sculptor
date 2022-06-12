#include "../headers/putBox.h"

PutBox::PutBox(int xi_, int xf_, int yi_, int yf_, int zi_, int zf_, float r_, float g_, float b_, float a_){
  this -> xi = xi_, this -> xf = xf_;
  this -> yi = yi_, this -> yf = yf_;
  this -> zi = zi_, this -> zf = zf_;

  this -> r  = r_;  this -> g  = g_ ; this -> b = b_; this -> a = a;
}

void PutBox::draw(Sculptor &sculptor){
  sculptor.setColor(r, g, b, a);
  for(int i = xi; i < xf; i++){
    for(int j = yi; j < yf; j++){
      for(int k = zi; k < zf; k++){
        sculptor.putVoxel(i, j, k);
      }
    }
  }
}
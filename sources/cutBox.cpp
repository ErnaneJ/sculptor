#include "../headers/cutBox.h"

CutBox::CutBox(int xi_, int xf_, int yi_, int yf_, int zi_, int zf_){
  this -> xi = xi_, this -> xf = xf_;
  this -> yi = yi_, this -> yf = yf_;
  this -> zi = zi_, this -> zf = zf_;
}

void CutBox::draw(Sculptor &sculptor){
  for(int i = xi; i < xf; i++){
    for(int j = yi; j < yf; j++){
      for(int k = zi; k < zf; k++){
        sculptor.cutVoxel(i, j, k);
      }
    }
  }
}
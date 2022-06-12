#include "../headers/putSphere.h"

#include <iostream>

PutSphere::PutSphere(int x_center_, int y_center_, int z_center_, int radius_, float r_, float g_, float b_, float a_){
  this -> x_center = x_center_;
  this -> y_center = y_center_;
  this -> z_center = z_center_;
  this -> radius   = radius_;

  this -> r  = r_;  this -> g  = g_ ; this -> b = b_; this -> a = a;
}

void PutSphere::draw(Sculptor &sculptor){
  sculptor.setColor(r, g, b, a);
  for(int x = x_center - radius; x < x_center + radius; x++){
    for(int y = y_center - radius; y < y_center + radius; y++){
      for(int z = z_center - radius; z < z_center + radius; z++){
        float distance = ((x-x_center)/2.0) * ((x-x_center)/2.0 ) / ((radius/2.0)*(radius/2.0)) +
                         ((y-y_center)/2.0) * ((y-y_center)/2.0) / ((radius/2.0)*(radius/2.0)) +
                         ((z-z_center)/2.0) * ((z-z_center)/2.0 ) / ((radius/2.0)*(radius/2.0));
        if( distance < 1.0){
          sculptor.putVoxel(x, y, z);
        }
      }
    }
  }
}
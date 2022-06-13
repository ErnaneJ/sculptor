#include "../headers/cutEllipsoid.h"

CutEllipsoid::CutEllipsoid(int x_center_, int y_center_, int z_center_, int x_radius_, int y_radius_, int z_radius_){
  this -> x_center = x_center_;
  this -> y_center = y_center_;
  this -> z_center = z_center_;
  this -> x_radius = x_radius_; 
  this -> y_radius = y_radius_;
  this -> z_radius = z_radius_;
}

void CutEllipsoid::draw(Sculptor &sculptor){
  sculptor.setColor(r, g, b, a);
  for(int x = x_center - x_radius; x < x_center + x_radius; x++){
    for(int y = y_center - y_radius; y < y_center + y_radius; y++){
      for(int z = z_center - z_radius; z < z_center + z_radius; z++){
        float distance = ((x-x_center)/2.0) * ((x-x_center)/2.0 ) / ((x_radius/2.0)*(x_radius/2.0)) +
                         ((y-y_center)/2.0) * ((y-y_center)/2.0) / ((y_radius/2.0)*(y_radius/2.0)) +
                         ((z-z_center)/2.0) * ((z-z_center)/2.0 ) / ((z_radius/2.0)*(z_radius/2.0));

        if((distance <= 1)){
          sculptor.cutVoxel(x, y, z);
        }
      }
    }
  }
}
#include <iostream>
#include <cstdlib>
#include <fstream>

#include "../headers/voxel.h"
#include "../headers/sculptor.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz){
  r = g = b = a = 1; // Default colors configuration
  nx = _nx;
  ny = _ny;
  nz = _nz;

  allocate_array();
}

Sculptor::~Sculptor(){
  for (int i = 0; i < nx; i++){
    for (int j = 0; j < ny; j++){
      delete[] v[i][j];
    }
    delete[] v[i];
  }
  delete[] v;
}

// ----------| Public Methos;
void Sculptor::setColor(float r_, float g_, float b_, float alpha_){
  r = r_;
  g = g_;
  b = b_;
  a = alpha_;
}

void Sculptor::putVoxel(int x, int y, int z){
  v[x][y][z].r = r;
  v[x][y][z].g = g;
  v[x][y][z].b = b;
  v[x][y][z].a = a;
  v[x][y][z].isOn = true;
}

void Sculptor::cutVoxel(int x, int y, int z){
  v[x][y][z].isOn = false;
}

void Sculptor::validates_box_parameters(int xi, int xf, int yi, int yf, int zi, int zf){
  if(!(
    (xi >= 0 && xi <= nx) &&
    (yi >= 0 && yi <= ny) &&
    (zi >= 0 && zi <= nz) &&

    (xf >= 0 && xf > xi && xf <= nx) &&
    (yf >= 0 && yf > yi && yf <= ny) &&
    (zf >= 0 && zf > zi && zf <= nz)
  )){
    std::cout << "[Error - Box] As dimensões da caixa passadas é inconsistente com relação à matriz de Voxels utilizada." << std::endl;
    exit(1);
  }
}

void Sculptor::putBox(int xi, int xf, int yi, int yf, int zi, int zf){
  validates_box_parameters(xi, xf, yi, yf, zi, zf);
  
  for(int i = xi; i < xf; i++){
    for(int j = yi; j < yf; j++){
      for(int k = zi; k < zf; k++){
        this -> putVoxel(i, j, k);
      }
    }
  }
}
void Sculptor::cutBox(int xi, int xf, int yi, int yf, int zi, int zf){
  validates_box_parameters(xi, xf, yi, yf, zi, zf);
  
  for(int i = xi; i < xf; i++){
    for(int j = yi; j < yf; j++){
      for(int k = zi; k < zf; k++){
        this -> cutVoxel(i, j, k);
      }
    }
  }
}

void Sculptor::validates_sphere_parameters(int xcenter, int ycenter, int zcenter, int radius){
  if(!(
    (xcenter >= 0 && xcenter <= nx) &&
    (ycenter >= 0 && ycenter <= ny) &&
    (zcenter >= 0 && zcenter <= nz) &&

    ((xcenter + radius) >= 0 && (xcenter + radius) <= nx) &&
    ((ycenter + radius) >= 0 && (ycenter + radius) <= ny) &&
    ((zcenter + radius) >= 0 && (zcenter + radius) <= nz)
  )){
    std::cout << "[Error - Sphere] As coordenadas e/ou raio da esfera passadas é inconsistente com relação à matriz de Voxels utilizada." << std::endl;
    exit(1);
  }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
  validates_sphere_parameters(xcenter, ycenter, zcenter, radius);
  Voxel *current_voxel;
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      for(int k = 0; k < nz; k++){
        current_voxel = &v[i][j][k];
        if(check_coordinates_for_a_sphere((i-xcenter), (j-ycenter), (k-zcenter), (radius/2.0))){
          current_voxel -> r = r;
          current_voxel -> b = b;
          current_voxel -> g = g;
          current_voxel -> a = a;
          current_voxel -> isOn = true;
        }
      }
    }
  }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
  validates_sphere_parameters(xcenter, ycenter, zcenter, radius);
  Voxel *current_voxel;
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      for(int k = 0; k < nz; k++){
        current_voxel = &v[i][j][k];
        if(check_coordinates_for_a_sphere((i-xcenter), (j-ycenter), (k-zcenter), (radius/2.0))){
          current_voxel -> isOn = false;
        }
      }
    }
  }
}

bool Sculptor::check_coordinates_for_a_ellipsoid(
  int variation_of_x, int variation_of_y, int variation_of_z, 
  float radius_x, float radius_y, float radius_z){
  
  float distance = (variation_of_x/2.0) * (variation_of_x/2.0) / (radius_x*radius_x) +
                  (variation_of_y/2.0) * (variation_of_y/2.0) / (radius_y*radius_y) +
                  (variation_of_z/2.0) * (variation_of_z/2.0) / (radius_z*radius_z);
  return (distance <= 1);
}

void Sculptor::validates_ellipsoid_parameters(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  if(!(
    (xcenter >= 0 && xcenter <= nx) &&
    (ycenter >= 0 && ycenter <= ny) &&
    (zcenter >= 0 && zcenter <= nz) &&

    ((xcenter + rx) >= 0 && (xcenter + rx) <= nx) &&
    ((ycenter + ry) >= 0 && (ycenter + ry) <= ny) &&
    ((zcenter + rz) >= 0 && (zcenter + rz) <= nz)
  )){
    std::cout << "[Error - Ellipsoid] As coordenadas e/ou raios do ellipsoid passadas é inconsistente com relação à matriz de Voxels utilizada." << std::endl;
    exit(1);
  }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  validates_ellipsoid_parameters(xcenter, ycenter, zcenter, rx, ry, rz);
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      for(int k = 0; k < nz; k++){
        bool coordinates_respect_equation = check_coordinates_for_a_ellipsoid((i-xcenter), (j-ycenter), (k-zcenter), (rx/2.0), (ry/2.0), (rz/2.0));
        if(coordinates_respect_equation){
          v[i][j][k].isOn=true;
          v[i][j][k].r=r;
          v[i][j][k].b=b;
          v[i][j][k].g=g;
          v[i][j][k].a=a;
        }
      }
    }
  }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  validates_ellipsoid_parameters(xcenter, ycenter, zcenter, rx, ry, rz);
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      for(int k = 0; k < nz; k++){
        bool coordinates_respect_equation = check_coordinates_for_a_ellipsoid((i-xcenter), (j-ycenter), (k-zcenter), (rx/2.0), (ry/2.0), (rz/2.0));
        if(coordinates_respect_equation){
          v[i][j][k].isOn=false;
        }
      }
    }
  }
}

void Sculptor::writeOFF(const char* filename){
  output_file.open(filename);
  
  if(output_file.is_open()){
    fill_file_with_voxel_data();
  }else{
    std::cout << "[Error - WriteOFF] Ocorreu um erro na leitura/gravação do arquivo ("<< filename << ")."<< std::endl;
    exit(1);
  }
  
  output_file.close();
}

// ----------| Private Methods;

void Sculptor::allocate_array(){
  v = new Voxel **[ny];
  for (int i = 0; i < ny; i++) {
    v[i] = new Voxel *[nx];
    for (int j = 0; j < nx; j++){
     v[i][j] = new Voxel [nz];
    }
  }
}

int Sculptor::number_of_voxels_to_show(){
  int counter = 0;
  Voxel *current_voxel;
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      for(int k = 0; k < nz; k++){
        current_voxel = &v[i][j][k];
        if(current_voxel -> isOn) counter++;
      }
    }
  }
  return counter;
}

void Sculptor::insert_voxel_vertices(){
  Voxel *current_voxel;
  for(int i = 0; i < nz; i++){
  for(int j = 0; j < ny; j++){
    for(int k = 0; k < nx; k++){
      current_voxel = &v[i][j][k];
      if(current_voxel -> isOn){
        output_file << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl
             << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl
             << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl
             << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl
             << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl
             << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl
             << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl
             << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
        }
      }
    }
  }
}
void Sculptor::insert_voxel_faces(){
  Voxel *current_voxel;
  int current_face = 0;
  for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for(int k=0; k<nz; k++){
        current_voxel = &v[i][j][k];
        if(current_voxel -> isOn){
          output_file << 4 << " " << 0 + current_face << " " << 3 + current_face << " " << 2 + current_face << " " << 1 + current_face << " "
               << current_voxel -> r << " " << current_voxel -> g << " " << current_voxel -> b << " " << current_voxel -> a << std::endl
               << 4 << " " << 4 + current_face << " " << 5 + current_face << " " << 6 + current_face << " " << 7 + current_face<< " "
               << current_voxel -> r << " " << current_voxel -> g << " " << current_voxel -> b << " " << current_voxel -> a << std::endl
               << 4 << " " << 0 + current_face << " " << 1 + current_face << " " << 5 + current_face << " " << 4 + current_face << " "
               << current_voxel -> r << " " << current_voxel -> g << " " << current_voxel -> b << " " << current_voxel -> a << std::endl
               << 4 << " " << 0 + current_face << " " << 4 + current_face << " " << 7 + current_face << " " << 3 + current_face << " "
               << current_voxel -> r << " " << current_voxel -> g << " " << current_voxel -> b << " " << current_voxel -> a << std::endl
               << 4 << " " << 3 + current_face << " " << 7 + current_face << " " << 6 + current_face << " " << 2 + current_face << " "
               << current_voxel -> r << " " << current_voxel -> g << " " << current_voxel -> b << " " << current_voxel -> a << std::endl
               << 4 << " " << 1 + current_face << " " << 2 + current_face << " " << 6 + current_face << " " << 5 + current_face<< " "
               << current_voxel -> r << " " << current_voxel -> g << " " << current_voxel -> b << " " << current_voxel -> a << std::endl;
          current_face += 8;
        }
      }
    }
  }
}

void Sculptor::fill_file_with_voxel_data(){
  int number_of_vertices = 8*number_of_voxels_to_show();
  int number_of_edges = 6*number_of_voxels_to_show();
  
  output_file << "OFF" << std::endl;
  output_file << number_of_vertices << " " 
       << number_of_edges << " " 
       << 0 << " " << std::endl;

  insert_voxel_vertices();
  insert_voxel_faces();
}

bool Sculptor::check_coordinates_for_a_sphere(int variation_of_x, int variation_of_y, int variation_of_z, int radius ){
  float distance = (variation_of_x/2.0) * (variation_of_x/2.0 ) / (radius*radius) +
                   (variation_of_y/2.0) * (variation_of_y/2.0) / (radius*radius) +
                   (variation_of_z/2.0) * (variation_of_z/2.0 ) / (radius*radius);
  return distance <= 1.0;
}
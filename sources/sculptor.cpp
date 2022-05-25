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

  v = new Voxel **[ny];
  for (int i = 0; i < ny; i++) {
    v[i] = new Voxel *[nx];
    for (int j = 0; j < nx; j++){
     v[i][j] = new Voxel [nz];
    }
  }
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
  if(!((x >= 0 && x <= nx) && (y >= 0 && y <= ny) && (z >= 0 && z <= nz))){ return; }

  Voxel *current_voxel = &v[x][y][z];
  current_voxel -> r = r;
  current_voxel -> g = g;
  current_voxel -> b = b;
  current_voxel -> a = a;
  current_voxel -> isOn = true;
}

void Sculptor::cutVoxel(int x, int y, int z){
  if(!((x >= 0 && x <= nx) && (y >= 0 && y <= ny) && (z >= 0 && z <= nz))){ return; }
  v[x][y][z].isOn = false;
}

void Sculptor::putBox(int xi, int xf, int yi, int yf, int zi, int zf){
  for(int i = xi; i < xf; i++){
    for(int j = yi; j < yf; j++){
      for(int k = zi; k < zf; k++){
        this -> putVoxel(i, j, k);
      }
    }
  }
}
void Sculptor::cutBox(int xi, int xf, int yi, int yf, int zi, int zf){
  for(int i = xi; i < xf; i++){
    for(int j = yi; j < yf; j++){
      for(int k = zi; k < zf; k++){
        this -> cutVoxel(i, j, k);
      }
    }
  }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      for(int k = 0; k < nz; k++){
        float distance = ((i-xcenter)/2.0) * ((i-xcenter)/2.0 ) / ((radius/2.0)*(radius/2.0)) +
                         ((j-ycenter)/2.0) * ((j-ycenter)/2.0) / ((radius/2.0)*(radius/2.0)) +
                         ((k-zcenter)/2.0) * ((k-zcenter)/2.0 ) / ((radius/2.0)*(radius/2.0));
        if( distance <= 1.0){
          this -> putVoxel(i, j, k);
        }
      }
    }
  }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      for(int k = 0; k < nz; k++){
        float distance = ((i-xcenter)/2.0) * ((i-xcenter)/2.0 ) / ((radius/2.0)*(radius/2.0)) +
                         ((j-ycenter)/2.0) * ((j-ycenter)/2.0) / ((radius/2.0)*(radius/2.0)) +
                         ((k-zcenter)/2.0) * ((k-zcenter)/2.0 ) / ((radius/2.0)*(radius/2.0));
        if( distance <= 1.0){
          this -> cutVoxel(i, j, k);
        }
      }
    }
  }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      for(int k = 0; k < nz; k++){
        float distance = ((i-xcenter)/2.0) * ((i-xcenter)/2.0) / ((rx/2.0)*(rx/2.0)) +
                         ((j-ycenter)/2.0) * ((j-ycenter)/2.0) / ((ry/2.0)*(ry/2.0)) +
                         ((k-zcenter)/2.0) * ((k-zcenter)/2.0) / ((rz/2.0)*(rz/2.0));

        if((distance <= 1)){
          this -> putVoxel(i, j, k);
        }
      }
    }
  }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      for(int k = 0; k < nz; k++){        
        float distance = ((i-xcenter)/2.0) * ((i-xcenter)/2.0) / ((rx/2.0)*(rx/2.0)) +
                         ((j-ycenter)/2.0) * ((j-ycenter)/2.0) / ((ry/2.0)*(ry/2.0)) +
                         ((k-zcenter)/2.0) * ((k-zcenter)/2.0) / ((rz/2.0)*(rz/2.0));
      
        if((distance <= 1)){
          this -> cutVoxel(i, j, k);
        }
      }
    }
  }
}

void Sculptor::writeOFF(const char* filename){
  Voxel *current_voxel;
  std::ofstream output_file;
  output_file.open(filename);
  
  if(!output_file.is_open()){
    std::cout << "[Error] Ocorreu um erro na leitura/gravação do arquivo ("<< filename << ")."<< std::endl;
    exit(1);
  }

  int counter = 0;
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      for(int k = 0; k < nz; k++){
        current_voxel = &v[i][j][k];
        if(current_voxel -> isOn) counter++;
      }
    }
  }

  int number_of_vertices = 8*counter;
  int number_of_edges = 6*counter;
  
  output_file << "OFF" << std::endl;
  output_file << number_of_vertices << " " 
       << number_of_edges << " " 
       << 0 << " " << std::endl;

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
  
  output_file.close();
}
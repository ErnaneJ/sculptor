#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include "../headers/putVoxel.h"
#include "../headers/putSphere.h"
#include "../headers/putEllipsoid.h" 
#include "../headers/putBox.h"

#include "../headers/cutVoxel.h"
#include "../headers/cutSphere.h"
#include "../headers/cutEllipsoid.h" 
#include "../headers/cutBox.h"

#include "../headers/interpreter.h"

Interpreter::Interpreter(){
  dimX=dimY=dimZ=0;
  r=g=b=a=1.0;
}

int Interpreter::getDimX(){
  return dimX;
}

int Interpreter::getDimY(){
  return dimY;
}

int Interpreter::getDimZ(){
  return dimZ;
}

std::vector<FiguraGeometrica *> Interpreter::parse(std::string file_path){
  std::vector<FiguraGeometrica *> figures;
  std::ifstream data_input;
  std::stringstream ss;
  std::string line, token;

  data_input.open(file_path.c_str());
  if(!data_input.is_open()){
    std::cout << "[Error] Ocorreu um erro na leitura do arquivo ("<< file_path << ")."<< std::endl;
    exit(1);
  }

  while (data_input.good()){
    std::getline(data_input, line);

    ss.clear();
    ss.str(line);
    ss >> token;
    if(ss.good()){
      std::cout << "Line: " << line << std::endl;

      if(token.compare("dim") == 0){
        ss >> dimX >> dimY >> dimZ;
      }else if(token.compare("putvoxel") == 0){
        int x, y, z;
        ss >> x >> y >> z >> r >> g >> b >> a;
        std::cout << "new PutVoxel("<< x<<", "<< y <<", "<< z<<", "<<r<<", "<<g<<", "<<b<<", "<<a<<");"<< std::endl;
        figures.push_back(new PutVoxel(x, y, z, r, g, b, a));
      }else if(token.compare("putbox") == 0){
        int xi, xf, yi, yf, zi, zf;
        ss >> xi >> xf >> yi >> yf >> zi >> zf >> r >> g >> b >> a;
        std::cout << "new PutBox("<< xi<<", "<< xf<<", " << yi<<", "<< yf<<", "<< zi<<", "<< zf<<", "<<r<<", "<<g<<", "<<b<<", "<<a<<");"<< std::endl;
        figures.push_back(new PutBox(xi, xf, yi, yf, zi, zf, r, g, b, a));
      }else if(token.compare("putsphere") == 0){
        int x_center, y_center, z_center, radius;
        ss >> x_center >> y_center >> z_center >> radius >> r >> g >> b >> a;
        std::cout << "new PutSphere("<< x_center<<", "<< y_center<<", " << z_center<<", "<< radius<<r<<", "<<g<<", "<<b<<", "<<a<<");"<< std::endl;
        figures.push_back(new PutSphere(x_center, y_center, z_center, radius, r, g, b, a));
      }else if(token.compare("putellipsoid") == 0){
        int x_center, y_center, z_center, x_radius, y_radius, z_radius;
        ss >> x_center >> y_center >> z_center >> x_radius >> y_radius  >> z_radius >> r >> g >> b >> a;
        std::cout << "new PutEllipsoid("<< x_center<<", "<< y_center<<", " << z_center<<", "<< x_radius<<", "<< z_radius<<", "<<r<<", "<<g<<", "<<b<<", "<<a<<");"<< std::endl;
        figures.push_back(new PutEllipsoid(x_center, y_center, z_center, x_radius, y_radius, z_radius, r, g, b, a));
      }else if(token.compare("cutvoxel") == 0){
        int x, y, z;
        ss >> x >> y >> z >> r >> g >> b >> a;
        std::cout << "new CutVoxel("<< x<<", "<< y <<", "<< z<<", "<<");"<<std::endl;
        figures.push_back(new CutVoxel(x, y, z));
      }else if(token.compare("cutbox") == 0){
        int xi, xf, yi, yf, zi, zf;
        ss >> xi >> xf >> yi >> yf >> zi >> zf;
        std::cout << "new CutBox("<< xi<<", "<< xf<<", " << yi<<", "<< yf<<", "<< zi<<", "<< zf<<", "<<");"<<std::endl;
        figures.push_back(new CutBox(xi, xf, yi, yf, zi, zf));
      }else if(token.compare("cutsphere") == 0){
        int x_center, y_center, z_center, radius;
        ss >> x_center >> y_center >> z_center >> radius >> r >> g >> b >> a;
        std::cout << "new CutSphere("<< x_center<<", "<< y_center<<", " << z_center<<", "<< radius<<");"<<std::endl;
        figures.push_back(new CutSphere(x_center, y_center, z_center, radius));
      }else if(token.compare("cutellipsoid") == 0){
        int x_center, y_center, z_center, x_radius, y_radius, z_radius;
        ss >> x_center >> y_center >> z_center >> x_radius >> y_radius  >> z_radius >> r >> g >> b >> a;
        std::cout << "new CutEllipsoid("<< x_center<<", "<< y_center<<", " << z_center<<", "<< x_radius<<", "<< z_radius<<", "<<");"<<std::endl;
        figures.push_back(new CutEllipsoid(x_center, y_center, z_center, x_radius, z_radius, z_radius));
      }
    }  
  }

  return figures;
}
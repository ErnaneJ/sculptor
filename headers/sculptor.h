#include <iostream>
#include <fstream>

#include "voxel.h"

#ifndef SCULPTOR
#define SCULPTOR

  class Sculptor {
    protected:
      std::ofstream fout;
      Voxel ***v; // 3D matrix
      int nx,ny,nz; // Dimensions
      float r,g,b,a; // Current drawing color
    public:
      Sculptor(int _nx, int _ny, int _nz);
      ~Sculptor();
      void setColor(float r, float g, float b, float alpha);
      void putVoxel(int x, int y, int z);
      void cutVoxel(int x, int y, int z);
      void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
      void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
      void putSphere(int xcenter, int ycenter, int zcenter, int radius);
      void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
      void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
      void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
      void writeOFF(const char* filename);
    private:
      void allocate_array();
      void fill_file_with_voxel_data();
      int number_of_voxels_to_show();
      void insert_voxel_faces();
      void insert_voxel_vertices();
      bool check_coordinates_for_a_sphere(int variation_of_x, int variation_of_y, int variation_of_z, int radius);
      bool check_coordinates_for_a_ellipsoid(int variation_of_x, int variation_of_y, int variation_of_z, float radius_x, float radius_y, float radius_z);
      void validates_box_parameters(int xi, int xf, int yi, int yf, int zi, int zf);
      void validates_sphere_parameters(int xcenter, int ycenter, int zcenter, int radius);
      void validates_ellipsoid_parameters(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  };

#endif // SCULPTOR
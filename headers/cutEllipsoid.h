#ifndef CUT_ELLIPSOID_H
  #define CUT_ELLIPSOID_H

  #include "figuraGeometrica.h"

  //! Classe concreta CutEllipsoid - Utiliza-se para apagar um conjunto de voxels pertencentes a um volume elíptico
  /*! 
   *  \brief Irá informar para o sistema que todos os voxels, presentes em uma determinada região elíptica 
   *         e pertencente ao espaço da matriz tridimensional de voxels alocada por uma instância da classe Sculptor, deverá ser **apagado**.
   *
   *  @param x_center Representa uma coordenada no eixo **x** pertencente à matriz de voxels que denota o centro da elipse a ser deletada;
   *  @param y_center Representa uma coordenada no eixo **y** pertencente à matriz de voxels que denota o centro da elipse a ser deletada;
   *  @param z_center Representa uma coordenada no eixo **z** pertencente à matriz de voxels que denota o centro da elipse a ser deletada;
   *  @param x_radius Representa o raio da elipse a ser deletada no eixo **x**;
   *  @param y_radius Representa o raio da elipse a ser deletada no eixo **y**;
   *  @param z_radius Representa o raio da elipse a ser deletada no eixo **z**;
   * 
   * Herda diretamente da classe abstrata FiguraGeometrica.
   **/
  class CutEllipsoid:public FiguraGeometrica{
    int x_center; /**< Coordenada central da elipse no eixo **x**.*/
    int y_center; /**< Coordenada central da elipse no eixo **y**.*/
    int z_center; /**< Coordenada central da elipse no eixo **z**.*/
    int x_radius; /**< Raio da elipse no eixo **x**.*/
    int y_radius; /**< Raio da elipse no eixo **y**.*/
    int z_radius; /**< Raio da elipse no eixo **z**.*/
  public:
    //! Construtor da classe CutEllipsoid.
    /*!
     * Este construtor receberá como parâmetros as coordenadas dimensionais da elipse de voxels a ser deletada. Com isso, 
     * construirá uma instância da classe CutEllipsoid.
     *
     *  @param x_center_ Coordenada central da elipse no eixo **x**;
     *  @param y_center_ Coordenada central da elipse no eixo **y**;
     *  @param z_center_ Coordenada central da elipse no eixo **z**;
     *  @param x_radius_ Raio da elipse no eixo **x**;
     *  @param y_radius_ Raio da elipse no eixo **y**;
     *  @param z_radius_ Raio da elipse no eixo **z**;
     **/
    CutEllipsoid(int x_center_, int y_center_, int z_center_, int x_radius_, int y_radius_, int z_radius_);
    //! Destrutor da classe CutEllipsoid.
    /*!
     * Atua como destrutor padrão;
     **/
    ~CutEllipsoid(){};
    //! Função membro draw.
    /*!
     * Método que deletará, a partir de uma instância da classe Sculptor passada como parâmetro, uma elipse presente em sua matriz de voxels.
     *
     *  @param sculptor instância da classe Sculptor;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // CUT_ELLIPSOID_H
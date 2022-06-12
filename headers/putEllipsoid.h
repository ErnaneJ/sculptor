#ifndef PUT_ELLIPSOID_H
  #define PUT_ELLIPSOID_H

  #include "figuraGeometrica.h"

  //! Classe concreta PutEllipsoid - Utiliza-se para mostrar um conjunto de voxels pertencentes a um volume elíptico
  /*! 
   * \brief Irá informar para o sistema que todos os voxels, presentes em uma determinada região elíptica 
   *        e pertencente ao espaço da matriz tridimensional de voxels alocada por uma instância da classe Sculptor, deverá ser **mostrado**.
   *
   * @param x_center Representa uma coordenada no eixo **x** pertencente à matriz de voxels que denota o centro da elipse a ser criada;
   * @param y_center Representa uma coordenada no eixo **y** pertencente à matriz de voxels que denota o centro da elipse a ser criada;
   * @param z_center Representa uma coordenada no eixo **z** pertencente à matriz de voxels que denota o centro da elipse a ser criada;
   * @param x_radius Representa o raio da elipse a ser criada no eixo **x**;
   * @param y_radius Representa o raio da elipse a ser criada no eixo **y**;
   * @param z_radius Representa o raio da elipse a ser criada no eixo **z**;
   * 
   * Herda diretamente da classe abstrata FiguraGeometrica.
   **/
  class PutEllipsoid:public FiguraGeometrica{
    int x_center; /**< Coordenada central da elipse no eixo **x**.*/
    int y_center; /**< Coordenada central da elipse no eixo **y**.*/
    int z_center; /**< Coordenada central da elipse no eixo **z**.*/
    int x_radius; /**< Raio da elipse no eixo **x**.*/
    int y_radius; /**< Raio da elipse no eixo **y**.*/
    int z_radius; /**< Raio da elipse no eixo **z**.*/
  public:
    //! Construtor da classe PutEllipsoid.
    /*!
     * Este construtor receberá como parâmetros as coordenadas dimensionais da elipse de voxels a ser criada como também, sua cor e transparência. Com isso, 
     * construirá uma instância da classe PutEllipsoid.
     *
     *  @param x_center_ Coordenada central da elipse no eixo **x**;
     *  @param y_center_ Coordenada central da elipse no eixo **y**;
     *  @param z_center_ Coordenada central da elipse no eixo **z**;
     *  @param x_radius_ Raio da elipse no eixo **x**;
     *  @param y_radius_ Raio da elipse no eixo **y**;
     *  @param z_radius_ Raio da elipse no eixo **z**;
     *  @param r_ Representa a componente vermelha da cor que a elipse será pintada;
     *  @param g_ Representa a componente verde da cor que a elipse será pintada;
     *  @param b_ Representa a componente azul da cor que a elipse será pintada;
     *  @param a_ Representa a componente de transparência da cor que a elipse será pintada;
     **/
    PutEllipsoid(int x_center_, int y_center_, int z_center_, int x_radius_, int y_radius_, int z_radius_, float r_, float g_, float b_, float a_);
    //! Destrutor da classe PutEllipsoid.
    /*!
     * Atua como destrutor padrão;
     **/
    ~PutEllipsoid(){};
    //! Função membro draw.
    /*!
     * Método que criará, a partir de uma instância da classe Sculptor passada como parâmetro, uma elipse presente em sua matriz de voxels.
     *
     *  @param sculptor instância da classe Sculptor;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // PUT_ELLIPSOID_H
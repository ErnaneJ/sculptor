#ifndef PUT_SPHERE_H
  #define PUT_SPHERE_H

  #include "figuraGeometrica.h"

  //! Classe concreta PutSphere - Utiliza-se para mostrar um conjunto de voxels pertencentes a um volume esférico
  /*! 
   * \brief Irá informar para o sistema que todos os voxels, presentes em uma determinada região esférica 
   *        e pertencente ao espaço da matriz tridimensional de voxels alocada por uma instância da classe Sculptor, deverá ser **mostrado**.
   *
   * @param x_center Representa uma coordenada no eixo **x** pertencente à matriz de voxels que denota o centro da esfera a ser criada;
   * @param y_center Representa uma coordenada no eixo **y** pertencente à matriz de voxels que denota o centro da esfera a ser criada;
   * @param z_center Representa uma coordenada no eixo **z** pertencente à matriz de voxels que denota o centro da esfera a ser criada;
   * @param radius Representa o raio da esfera a ser criada, nas três dimensões, **x**, **y** e  **z**;
   * 
   * Herda diretamente da classe abstrata FiguraGeometrica.
   **/
  class PutSphere:public FiguraGeometrica{
    int x_center; /**< Coordenada central da esfera no eixo **x**.*/
    int y_center; /**< Coordenada central da esfera no eixo **y**.*/
    int z_center; /**< Coordenada central da esfera no eixo **z**.*/
    int radius; /**< Raio da esfera nas três dimensões.*/
  public:

    //! Construtor da classe PutSphere.
    /*!
     * Este construtor receberá como parâmetros as coordenadas dimensionais da esfera de voxels a ser criada como também, sua cor e transparência. Com isso, 
     * construirá uma instância da classe PutSphere.
     *
     *  @param x_center_ Coordenada central da esfera no eixo **x**;
     *  @param y_center_ Coordenada central da esfera no eixo **y**;
     *  @param z_center_ Coordenada central da esfera no eixo **z**;
     *  @param radius_ Raio da esfera nas três dimensões;
     *  @param r_ Representa a componente vermelha da cor que a esfera será pintada;
     *  @param g_ Representa a componente verde da cor que a esfera será pintada;
     *  @param b_ Representa a componente azul da cor que a esfera será pintada;
     *  @param a_ Representa a componente de transparência da cor que a esfera será pintada;
     **/
    PutSphere(int x_center_, int y_center_, int z_center_, int radius_, float r_, float g_, float b_, float a_);
    
    //! Destrutor da classe PutBox.
    /*!
     * Atua como destrutor padrão;
     **/
    ~PutSphere(){};

    //! Função membro draw.
    /*!
     * Método que criará, a partir de uma instância da classe Sculptor passada como parâmetro, uma esfera presente em sua matriz de voxels.
     *
     *  @param sculptor instância da classe Sculptor;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // PUT_SPHERE_H
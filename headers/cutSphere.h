#ifndef CUT_SPHERE_H
  #define CUT_SPHERE_H

  #include "figuraGeometrica.h"

  //! Classe concreta CutSphere - Utiliza-se para apagar um conjunto de voxels pertencentes a um volume esférico
  /*! 
   *  \brief Irá informar para o sistema que todos os voxels, presentes em uma determinada região esférica 
   *         e pertencente ao espaço da matriz tridimensional de voxels alocada por uma instância da classe Sculptor, deverá ser **apagado**.
   *
   *  @param x_center Representa uma coordenada no eixo **x** pertencente à matriz de voxels que denota o centro da esfera a ser deletada;
   *  @param y_center Representa uma coordenada no eixo **y** pertencente à matriz de voxels que denota o centro da esfera a ser deletada;
   *  @param z_center Representa uma coordenada no eixo **z** pertencente à matriz de voxels que denota o centro da esfera a ser deletada;
   *  @param radius Representa o raio da esfera a ser deletada nas três dimensões: **x**, **y** e  **z**.
   * 
   * Herda diretamente da classe abstrata FiguraGeometrica.
   **/
  class CutSphere:public FiguraGeometrica{
    int x_center; /**< Coordenada central da esfera no eixo **x**.*/
    int y_center; /**< Coordenada central da esfera no eixo **y**.*/
    int z_center; /**< Coordenada central da esfera no eixo **z**.*/
    int radius; /**< Raio da esfera nas três dimensões.*/
  public:

    //! Construtor da classe CutSphere.
    /*!
     * Este construtor receberá como parâmetros as coordenadas dimensionais da esfera de voxels a ser deletada, dessa forma, 
     * construirá uma instância da classe CutSphere.
     *
     *  @param x_center_ Coordenada central da esfera no eixo **x**;
     *  @param y_center_ Coordenada central da esfera no eixo **y**;
     *  @param z_center_ Coordenada central da esfera no eixo **z**;
     **/
    CutSphere(int x_center_, int y_center_, int z_center_, int radius_);

    //! Destrutor da classe PutBox.
    /*!
     * Atua como destrutor padrão;
     **/
    ~CutSphere(){};

    //! Função membro draw.
    /*!
     * Método que deletará, a partir de uma instância da classe Sculptor passada como parâmetro, uma esfera presente em sua matriz de voxels.
     *
     *  @param sculptor instância da classe Sculptor;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // CUT_SPHERE_H
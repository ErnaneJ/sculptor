#ifndef PUT_BOX_H
  #define PUT_BOX_H

  #include "figuraGeometrica.h"
  
  //! Classe concreta PutBox - Utiliza-se para mostrar um bloco de voxels
  /*! 
   * \brief Irá informar para o sistema que todos os voxels, presentes em uma determinada região cúbica 
   *        e pertencente ao espaço da matriz tridimensional de voxels alocada por uma instância da classe Sculptor, deverá ser **mostrado**.
   *
   * @param xi Representa uma coordenada no eixo **x** pertencente à matriz de voxels que denota o inicio do intervalo de voxels;
   * @param xf Representa uma coordenada no eixo **x** pertencente à matriz de voxels que denota o término do intervalo de voxels;
   * @param yi Representa uma coordenada no eixo **y** pertencente à matriz de voxels que denota o inicio do intervalo de voxels;
   * @param yf Representa uma coordenada no eixo **y** pertencente à matriz de voxels que denota o término do intervalo de voxels;
   * @param zi Representa uma coordenada no eixo **z** pertencente à matriz de voxels que denota o inicio do intervalo de voxels;
   * @param zf Representa uma coordenada no eixo **z** pertencente à matriz de voxels que denota o término do intervalo de voxels;
   *
   * Herda diretamente da classe abstrata FiguraGeometrica.
   **/
  class PutBox:public FiguraGeometrica{
    int xi; /**< Coordenada inicial da caixa no eixo **x**.*/
    int xf; /**< Coordenada final da caixa no eixo **x**.*/
    int yi; /**< Coordenada inicial da caixa no eixo **y**.*/
    int yf; /**< Coordenada final da caixa no eixo **y**.*/
    int zi; /**< Coordenada inicial da caixa no eixo **z**.*/
    int zf; /**< Coordenada final da caixa no eixo **z**.*/
  public:

    //! Construtor da classe PutBox.
    /*!
     * Este construtor receberá como parâmetros as coordenadas dimensionais da caixa de voxels a ser criada como também, sua cor e transparência. Com isso, 
     * construirá uma instância da classe PutBox.
     *
     *  @param xi_ Representa uma coordenada no eixo **x** pertencente à matriz de voxels que denota o inicio do intervalo de voxels;
     *  @param xf_ Representa uma coordenada no eixo **x** pertencente à matriz de voxels que denota o término do intervalo de voxels;
     *  @param yi_ Representa uma coordenada no eixo **y** pertencente à matriz de voxels que denota o inicio do intervalo de voxels;
     *  @param yf_ Representa uma coordenada no eixo **y** pertencente à matriz de voxels que denota o término do intervalo de voxels;
     *  @param zi_ Representa uma coordenada no eixo **z** pertencente à matriz de voxels que denota o inicio do intervalo de voxels;
     *  @param zf_ Representa uma coordenada no eixo **z** pertencente à matriz de voxels que denota o término do intervalo de voxels;
     *  @param r_ Representa a componente vermelha da cor que a caixa será pintada;
     *  @param g_ Representa a componente verde da cor que a caixa será pintada;
     *  @param b_ Representa a componente azul da cor que a caixa será pintada;
     *  @param a_ Representa a componente de transparência da cor que a caixa será pintada;
     **/
    PutBox(int xi_, int xf_, int yi_, int yf_, int zi_, int zf_, float r_, float g_, float b_, float a_);

    //! Destrutor da classe PutBox.
    /*!
     * Atua como destrutor padrão;
     **/
    ~PutBox(){};

    //! Função membro draw.
    /*!
     * Método que criará, a partir de uma instância da classe Sculptor passada como parâmetro, uma caixa presente em sua matriz de voxels.
     *
     *  @param sculptor instância da classe Sculptor;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // PUT_BOX_H
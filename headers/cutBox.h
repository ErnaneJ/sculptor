#ifndef CUTBOX_H
  #define CUTBOX_H

  #include "figuraGeometrica.h"

  //! Classe concreta CutBox - Utiliza-se para apagar um bloco de voxels
  /*! 
   *  \brief Irá informar para o sistema que todos os voxels, presentes em uma determinada região cúbica 
   *         e pertencente ao espaço da matriz tridimensional de voxels alocada por uma instância da classe Sculptor, deverá ser **apagado**.
   *
   *  @param xi Representa uma coordenada no eixo **x** pertencente à matriz de voxels que denota o inicio do intervalo de voxels;
   *  @param xf Representa uma coordenada no eixo **x** pertencente à matriz de voxels que denota o término do intervalo de voxels;
   *  @param yi Representa uma coordenada no eixo **y** pertencente à matriz de voxels que denota o inicio do intervalo de voxels;
   *  @param yf Representa uma coordenada no eixo **y** pertencente à matriz de voxels que denota o término do intervalo de voxels;
   *  @param zi Representa uma coordenada no eixo **z** pertencente à matriz de voxels que denota o inicio do intervalo de voxels;
   *  @param zf Representa uma coordenada no eixo **z** pertencente à matriz de voxels que denota o término do intervalo de voxels;
   * 
   *  Herda diretamente da classe abstrata FiguraGeometrica.
   **/
  class CutBox:public FiguraGeometrica{
    int xi; /**< Coordenada inicial da caixa no eixo **x**.*/
    int xf; /**< Coordenada final da caixa no eixo **x**.*/
    int yi; /**< Coordenada inicial da caixa no eixo **y**.*/
    int yf; /**< Coordenada final da caixa no eixo **y**.*/
    int zi; /**< Coordenada inicial da caixa no eixo **z**.*/
    int zf; /**< Coordenada final da caixa no eixo **z**.*/
  public:
  
    //! Construtor da classe CutBox.
    /*!
     * Este construtor receberá como parâmetros as coordenadas dimensionais da caixa de voxels a ser deletada e, com isso, 
     * construirá uma instância da classe CutBox.
     *
     *  @param xi_ Representa uma coordenada no eixo **x** pertencente à matriz de voxels que denota o inicio do intervalo de voxels;
     *  @param xf_ Representa uma coordenada no eixo **x** pertencente à matriz de voxels que denota o término do intervalo de voxels;
     *  @param yi_ Representa uma coordenada no eixo **y** pertencente à matriz de voxels que denota o inicio do intervalo de voxels;
     *  @param yf_ Representa uma coordenada no eixo **y** pertencente à matriz de voxels que denota o término do intervalo de voxels;
     *  @param zi_ Representa uma coordenada no eixo **z** pertencente à matriz de voxels que denota o inicio do intervalo de voxels;
     *  @param zf_ Representa uma coordenada no eixo **z** pertencente à matriz de voxels que denota o término do intervalo de voxels;
     **/
    CutBox(int xi_, int xf_, int yi_, int yf_, int zi_, int zf_);

    //! Destrutor da classe CutBox.
    /*!
     * Atua como destrutor padrão;
     **/
    ~CutBox(){};

    //! Função membro draw.
    /*!
     * Método que deletará, a partir de uma instância da classe Sculptor passada como parâmetro, uma caixa presente em sua matriz de voxels.
     *
     *  @param sculptor instância da classe Sculptor;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // CUTBOX_H
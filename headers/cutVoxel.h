#ifndef CUT_VOXEL_H
  #define CUT_VOXEL_H

  #include "figuraGeometrica.h"

  //! Classe concreta CutVoxel - Utiliza-se para apagar um único voxel
  /*! 
   * \brief Irá informar para o sistema que o voxel, presente em uma determinada coordenada e pertencente 
   *        ao espaço da matriz tridimensional de voxels alocada por uma instância da classe Sculptor, 
   *        deverá ser **apagado**.
   *
   * @param x Representa a coordenada no eixo **x** do voxel;
   * @param y Representa a coordenada no eixo **y** do voxel;
   * @param z Representa a coordenada no eixo **z** do voxel;
   *
   * Herda diretamente da classe abstrata FiguraGeometrica.
   **/
  class CutVoxel:public FiguraGeometrica{
    int x; /**< Coordenada do voxel eixo **x**.*/
    int y; /**< Coordenada do voxel eixo **y**.*/
    int z; /**< Coordenada do voxel eixo **z**.*/
  public:
    //! Construtor da classe CutVoxel.
    /*!
     * Este construtor receberá como parâmetros as coordenadas do caixa de voxel a ser criado e com isso, 
     * construirá uma instância da classe CutVoxel.
     *
     *  @param x_ Representa a coordenada no eixo **x** do voxel;
     *  @param y_ Representa a coordenada no eixo **y** do voxel;
     *  @param z_ Representa a coordenada no eixo **z** do voxel;   
     **/
    CutVoxel(int x_, int y_, int z_);
    //! Destrutor da classe CutVoxel.
    /*!
     * Atua como destrutor padrão;
     **/
    ~CutVoxel(){};
    //! Função membro draw.
    /*!
     * Método que deletará, a partir de uma instância da classe Sculptor passada como parâmetro, um voxel em sua matriz de voxels.
     *
     *  @param sculptor instância da classe Sculptor;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // CUT_VOXEL_H
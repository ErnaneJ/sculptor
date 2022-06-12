#ifndef PUT_VOXEL_H
  #define PUT_VOXEL_H

  #include "figuraGeometrica.h"

  //! Classe concreta PutVoxel - Utiliza-se para mostrar um único voxel
  /*! 
   * \brief Irá informar para o sistema que o voxel, presente em uma determinada coordenada e pertencente 
   *        ao espaço da matriz tridimensional de voxels alocada por uma instância da classe Sculptor, 
   *        deverá ser **mostrado**.
   *
   * @param x Representa a coordenada no eixo **x** do voxel;
   * @param y Representa a coordenada no eixo **y** do voxel;
   * @param z Representa a coordenada no eixo **z** do voxel;
   *
   * Herda diretamente da classe abstrata FiguraGeometrica.
   **/
  class PutVoxel:public FiguraGeometrica{
    int x; /**< Coordenada do voxel eixo **x**.*/
    int y; /**< Coordenada do voxel eixo **y**.*/
    int z; /**< Coordenada do voxel eixo **z**.*/
  public:
    //! Construtor da classe PutVoxel.
    /*!
     * Este construtor receberá como parâmetros as coordenadas do caixa de voxel a ser criado como também, sua cor e transparência. Com isso, 
     * construirá uma instância da classe PutVoxel.
     *
     *  @param x_ Representa a coordenada no eixo **x** do voxel;
     *  @param y_ Representa a coordenada no eixo **y** do voxel;
     *  @param z_ Representa a coordenada no eixo **z** do voxel;   
     *  @param r_ Representa a componente vermelha da cor que o voxel será pintado;
     *  @param g_ Representa a componente verde da cor que o voxel será pintado;
     *  @param b_ Representa a componente azul da cor que o voxel será pintado;
     *  @param a_ Representa a componente de transparência da cor que o voxel será pintado;
     **/
    PutVoxel(int x_, int y_, int z_, float r_, float g_, float b_, float a_);
    //! Destrutor da classe PutVoxel.
    /*!
     * Atua como destrutor padrão;
     **/
    ~PutVoxel(){};
    //! Função membro draw.
    /*!
     * Método que criará, a partir de uma instância da classe Sculptor passada como parâmetro, um voxel em sua matriz de voxels.
     *
     *  @param sculptor instância da classe Sculptor;
     **/
    void draw(Sculptor &sculptor);
  };

#endif // PUT_VOXEL_H
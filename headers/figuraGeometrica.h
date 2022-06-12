#ifndef FIGURA_GEOMETRICA_H
  #define FIGURA_GEOMETRICA_H
  #include "sculptor.h"
  
  //! Classe abstrata FiguraGeometrica - Base para geração de geometrias
  /*! 
   * \brief Classe base para a aplicação geométrica de todos os elementos possíveis de construir ou apagar
   *        da matriz de voxel de uma instancia da classe Sculptor.
   *
   *  @param r Representa a componente vermelha da cor que o/os voxel(s) será/serão pintado(s);
   *  @param g Representa a componente verde da cor que o/os voxel(s) será/serão pintado(s);
   *  @param b Representa a componente azul da cor que o/os voxel(s) será/serão pintado(s);
   *  @param a Representa a componente de transparência da cor que o/os voxel(s) será/serão pintado(s);
   **/
  class FiguraGeometrica{
    protected:
      float r; /**< Componente vermelha formato de cor RGBA em um intervalo ponto flutuante de 0 à 1.*/
      float g; /**< Componente verde formato de cor RGBA em um intervalo ponto flutuante de 0 à 1.*/
      float b; /**< Componente azul formato de cor RGBA em um intervalo ponto flutuante de 0 à 1.*/
      float a; /**< Componente de transparência no formato de cor RGBA em um intervalo ponto flutuante de 0 à 1.*/
    public:
      //! Construtor da classe FiguraGeometrica.
      virtual ~FiguraGeometrica(){};

    //! Função virtual pura Draw.
    /*!
     * Método base para implementação da lógica de aplicação de cada geometria que herda desta classe
     * em cima de um escultor digital instância da classe Sculptor.
     * 
     * @param sculptor instância da classe Sculptor; 
     **/
      virtual void draw(Sculptor &sculptor)=0; // NOOP
  };

#endif // FIGURA_GEOMETRICA_H
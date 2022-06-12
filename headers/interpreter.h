#ifndef INTERPRETER_H
  #define INTERPRETER_H

  #include <vector>
  #include <string>
  #include "./figuraGeometrica.h"

  //! Classe Interpreter - Interpretador de arquivos de texto simples com descrição para geração de esculturas
  /*! 
   * \brief Classe auxiliar para leitura e interpretação de arquivos que descrevem uma escultura
   * em um determinado modelo esperado. A mesma captura o conteúdo de um arquivo de texto simples
   * e gera uma sequência de formas geométricas, filhas da classe FiguraGeometrica. Sequência essa que
   * poderá ser utilizada para a construção de um modelo digital tridimensional instanciado pela 
   * classe Sculptor. 
   *
   * @param dimX Dimensão máxima da escultura na direção do eixo **x**;
   * @param dimY Dimensão máxima da escultura na direção do eixo **y**;
   * @param dimZ Dimensão máxima da escultura na direção do eixo **z**;
   * @param r Componente vermelha formato de cor RGBA em um intervalo ponto flutuante de 0 à 1;
   * @param g Componente verde formato de cor RGBA em um intervalo ponto flutuante de 0 à 1;
   * @param b Componente azul formato de cor RGBA em um intervalo ponto flutuante de 0 à 1;
   * @param a Componente de transparência no formato de cor RGBA em um intervalo ponto flutuante de 0 à 1;
   *
   **/
  class Interpreter{
    private:
      int dimX; /**< Dimensão máxima da escultura na direção do eixo **x**.*/
      int dimY; /**< Dimensão máxima da escultura na direção do eixo **y**.*/
      int dimZ; /**< Dimensão máxima da escultura na direção do eixo **z**.*/
      float r; /**< Componente vermelha formato de cor RGBA em um intervalo ponto flutuante de 0 à 1.*/
      float g; /**< Componente verde formato de cor RGBA em um intervalo ponto flutuante de 0 à 1.*/
      float b; /**< Componente azul formato de cor RGBA em um intervalo ponto flutuante de 0 à 1.*/
      float a; /**< Componente de transparência no formato de cor RGBA em um intervalo ponto flutuante de 0 à 1.*/
    public:
    public:
      //! Construtor da classe Interpreter.
      /*!
      * Atua como construtor padrão;
      **/
      Interpreter();
      //! Função membro getDimX.
      /*!
      * Captura e retorna a informação presente na variável dimX privada.
      * 
      * @return Inteiro presente na variável dimX.
      **/
      int getDimX();
      //! Função membro getDimY.
      /*!
      * Captura e retorna a informação presente na variável dimY privada.
      * 
      * @return Inteiro presente na variável dimY.
      **/
      int getDimY();
      //! Função membro getDimZ.
      /*!
      * Captura e retorna a informação presente na variável dimZ privada.
      * 
      * @return Inteiro presente na variável dimZ.
      **/
      int getDimZ();

      //! Função membro parse.
      /*!
      * Recebe o caminho de um arquivo de texto simples e, em seguida, captura suas informações e interpreta
      * gerando um vetor de FiguraGeometrica que será retornado.
      * 
      * @param file_path String informativa do caminho do arquivo a ser analisado.
      * 
      * @return Ponteiro para uma sequência de instancias de classes filhas de FiguraGeometrica - std::vector<FiguraGeometrica *>.
      **/
      std::vector<FiguraGeometrica *> parse(std::string file_path);
  };

#endif // INTERPRETER_H
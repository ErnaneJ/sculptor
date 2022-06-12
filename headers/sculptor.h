#include <iostream>
#include <fstream>

#include "voxel.h"

#ifndef SCULPTOR
#define SCULPTOR

  /*! \brief Classe Sculptor para manipulação de elementos, denotados voxels, em matrizes
  *          digitais tridimensionais.
  */
  class Sculptor {
    protected:
      Voxel ***v; /**< Matriz digital de voxels tridimensionais*/
      
      int nx; /**< Dimensionador digital da matriz de voxels no eixo X.*/
      int ny; /**< Dimensionador digital da matriz de voxels no eixo Y.*/
      int nz; /**< Dimensionador digital da matriz de voxels no eixo Z.*/
      
      float r; /**< Componente de cor R (Red) no formato RGBA para implementação dos voxels*/
      float g; /**< Componente de cor G (Green) no formato RGBA para implementação dos voxels*/
      float b; /**< Componente de cor B (Blue) no formato RGBA para implementação dos voxels*/
      float a; /**< Componente de cor A (Alpha) no formato RGBA para implementação dos voxels*/
    public:

      //! Construtor da classe.
      /*!
        Este construtor receberá os parâmetros dimensionais da matriz de voxels e 
        construirá uma instância da classe Sculptor.

        @param _x Dimensionador digital inteiro da matriz de voxels no eixo X;
        @param _y Dimensionador digital inteiro da matriz de voxels no eixo Y;
        @param _z Dimensionador digital inteiro da matriz de voxels no eixo Z.


        O mesmo irá alocar dinamicamente, com as dimensões passadas, a matriz de voxels **v** e 
        configurar os elementos de cor (**r**, **g**, **b** e **a**) para seus valores padrão: 0.0.
      */
      Sculptor(int _nx, int _ny, int _nz);

      //! Destrutor da classe.
      /*!
        Ao ser executado, irá liberar o espaço de memória alocado dinamicamente para a matriz tridimensional
        com as dimensões informadas durante a execução do programa.
      */
      ~Sculptor();

      //! Função membro setColor. 
      /*!
        Irá configurar os atributos privados **r**, **g**, **b** e **a** para os valores recebidos 
        como parâmetro da função.

        @param r     Representa a componente R (Red) de cor no modelo RGBA em um intervalo de 0.0 à 1.0;
        @param g     Representa a componente G (Green) de cor no modelo RGBA em um intervalo de 0.0 à 1.0;
        @param b     Representa a componente B (Blue) de cor no modelo RGBA em um intervalo de 0.0 à 1.0;
        @param alpha Representa a componente A (Alpha - Transparência) de cor no modelo RGBA em um intervalo de 0.0 à 1.0.

        @return ***void***;
      */
      void setColor(float r, float g, float b, float alpha);

      //! Função membro putVoxel.
      /*!
        Esse método irá informar para o sistema que um voxel deverá ser **mostrado** na matriz de voxels
        nas coordenadas **x**, **y** e **z** que foram passadas como parâmetro.

        @param x Representa uma coordenada no eixo **x** do plano da matriz 3D de voxels;
        @param y Representa uma coordenada no eixo **y** do plano da matriz 3D de voxels;
        @param z Representa uma coordenada no eixo **z** do plano da matriz 3D de voxels;

        @return ***void***;
      */

      void putVoxel(int x, int y, int z);

      //! Função membro cutVoxel.
      /*!
        Esse método irá informar para o sistema que um voxel deverá ser **apagado** na matriz de voxels
        nas coordenadas **x**, **y** e **z** que foram passadas como parâmetro.

        @param x Representa uma coordenada no eixo **x** do plano da matriz 3D de voxels;
        @param y Representa uma coordenada no eixo **y** do plano da matriz 3D de voxels;
        @param z Representa uma coordenada no eixo **z** do plano da matriz 3D de voxels;

        @return ***void***;
      */
      void cutVoxel(int x, int y, int z);

      //! Função membro writeOFF.
      /*!
        Esse método irá utilizar todos os dados presentes na classe sculptor para montar um arquivo de texto simples na 
        estrutura de um OFF (Object File Format) nomeado e no diretório passado como parâmetro.

        @param filename nome/caminho do arquivo de texto simples a ser criado/editado com o conteúdo gerado pela classe;

        @return ***void***;
      */
      void writeOFF(const char* filename);
  };

#endif // SCULPTOR
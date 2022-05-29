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
        construirá uma instancia da classe Sculptor.

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

      //! Função membro putBox.
      /*!
        Esse método irá informar para o sistema que todos os voxels, presentes em uma determinada região cúbica 
        e pertencente ao espaço da matriz tridimensional de voxels, deverá ser **mostrado**.

        @param x0 Representa uma coordenada no eixo **x** que denota o inicio do intervalo de voxels;
        @param x1 Representa uma coordenada no eixo **x** que denota o término do intervalo de voxels;
        @param y0 Representa uma coordenada no eixo **y** que denota o inicio do intervalo de voxels;
        @param y1 Representa uma coordenada no eixo **y** que denota o término do intervalo de voxels;
        @param z0 Representa uma coordenada no eixo **z** que denota o inicio do intervalo de voxels;
        @param z1 Representa uma coordenada no eixo **z** que denota o término do intervalo de voxels;

        @return ***void***;
      */
      void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

      //! Função membro cutBox.
      /*!
        Esse método irá informar para o sistema que todos os voxels, presentes em uma determinada região cúbica 
        e pertencente ao espaço da matriz tridimensional de voxels, deverá ser **apagado**.

        @param x0 Representa uma coordenada no eixo **x** que denota o inicio do intervalo de voxels;
        @param x1 Representa uma coordenada no eixo **x** que denota o término do intervalo de voxels;
        @param y0 Representa uma coordenada no eixo **y** que denota o inicio do intervalo de voxels;
        @param y1 Representa uma coordenada no eixo **y** que denota o término do intervalo de voxels;
        @param z0 Representa uma coordenada no eixo **z** que denota o inicio do intervalo de voxels;
        @param z1 Representa uma coordenada no eixo **z** que denota o término do intervalo de voxels;

        @return ***void***;
      */
      void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

      //! Função membro putSphere.
      /*!
        Esse método irá informar para o sistema que todos os voxels, presentes em uma determinada região esférica 
        e pertencente ao espaço da matriz tridimensional de voxels, deverá ser **mostrado**.

        @param xcenter Representa uma coordenada no eixo **x** que denota o centro, naquele eixo, da esfera a ser mostrada;
        @param ycenter Representa uma coordenada no eixo **y** que denota o centro, naquele eixo, da esfera a ser mostrada;
        @param zcenter Representa uma coordenada no eixo **z** que denota o centro, naquele eixo, da esfera a ser mostrada;
        @param radius  Representa o tamanho do **raio** da esfera, nas direções de **x**, **y** e **z**, que será mostrada;

        @return ***void***;
      */
      void putSphere(int xcenter, int ycenter, int zcenter, int radius);

      //! Função membro cutSphere.
      /*!
        Esse método irá informar para o sistema que todos os voxels, presentes em uma determinada região esférica 
        e pertencente ao espaço da matriz tridimensional de voxels, deverá ser **apagado**.

        @param xcenter Representa uma coordenada no eixo **x** que denota o centro, naquele eixo, da esfera a ser apagada;
        @param ycenter Representa uma coordenada no eixo **y** que denota o centro, naquele eixo, da esfera a ser apagada;
        @param zcenter Representa uma coordenada no eixo **z** que denota o centro, naquele eixo, da esfera a ser apagada;
        @param radius  Representa o tamanho do **raio** da esfera, nas direções de **x**, **y** e **z**, que será apagada;

        @return ***void***;
      */
      void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

      //! Função membro putEllipsoid.
      /*!
        Esse método irá informar para o sistema que todos os voxels, presentes em uma determinada região formada por uma elipsoide 
        e pertencente ao espaço da matriz tridimensional de voxels, deverá ser **mostrado**.

        @param xcenter Representa uma coordenada no eixo **x** que denota o centro, naquele eixo, do elipsoide a ser mostrado;
        @param ycenter Representa uma coordenada no eixo **y** que denota o centro, naquele eixo, do elipsoide a ser mostrado;
        @param zcenter Representa uma coordenada no eixo **z** que denota o centro, naquele eixo, do elipsoide a ser mostrado;
        @param rx  Representa o tamanho do **raio** do elipsoide na direção do eixo **x**;
        @param ry  Representa o tamanho do **raio** do elipsoide na direção do eixo **y**;
        @param rz  Representa o tamanho do **raio** do elipsoide na direção do eixo **z**;

        @return ***void***;
      */
      void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

      //! Função membro cutEllipsoid.
      /*!
        Esse método irá informar para o sistema que todos os voxels, presentes em uma determinada região formada por uma elipsoide 
        e pertencente ao espaço da matriz tridimensional de voxels, deverá ser **apagado**.

        @param xcenter Representa uma coordenada no eixo **x** que denota o centro, naquele eixo, do elipsoide a ser apagado;
        @param ycenter Representa uma coordenada no eixo **y** que denota o centro, naquele eixo, do elipsoide a ser apagado;
        @param zcenter Representa uma coordenada no eixo **z** que denota o centro, naquele eixo, do elipsoide a ser apagado;
        @param rx  Representa o tamanho do **raio** do elipsoide na direção do eixo **x**;
        @param ry  Representa o tamanho do **raio** do elipsoide na direção do eixo **y**;
        @param rz  Representa o tamanho do **raio** do elipsoide na direção do eixo **z**;

        @return ***void***;
      */
      void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

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
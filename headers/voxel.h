#ifndef VOXEL
#define VOXEL

/*! \brief Struct Voxel (volume element) utilizada para armazenar propriedades dos elementos que constituirá a escultura criada
 *         pela classe sculptor. É definido como um ***struct*** e comporta as propriedades e informações nexessárias para
           construção e utilização dos voxels: sua cor e transparência e se ele deverá ser incluído ou não no modelo digital 
 *         que representa a escultura gerada na classe Sculptor.
 */
struct Voxel {
  float r; /**< Componente de cor R (Red) no formato RGBA em um intervalo de ponto flutuante de 0.0 à 1.0;*/
  float g; /**< Componente de cor G (Green) no formato RGBA em um intervalo de ponto flutuante de 0.0 à 1.0;*/
  float b; /**< Componente de cor B (Blue) no formato RGBA em um intervalo de ponto flutuante de 0.0 à 1.0;*/
  float a; /**< Componente de cor A (Alpha - Transparência) no formato RGBA em um intervalo de ponto flutuante de 0.0 à 1.0;*/
  bool isOn; /**< Informação booleana que informará, a quem acessar o elemento, se ele deverá ser incluído ou não no modelo digital da escultura.*/
};

#endif // VOXEL
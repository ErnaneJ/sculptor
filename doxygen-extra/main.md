# Sculptor

| BMO - Example Model | Coin - Example Model | 
| :---: | :---: |
| <img style="filter: none !important;" title="BMO - example model" align="right" alt="BMO - example model" src="https://raw.githubusercontent.com/ErnaneJ/sculptor/master/assets/bmo.gif" width="100%"> | <img style="filter: none !important;" title="Coin - example model" align="center" alt="Coin - example model" src="https://raw.githubusercontent.com/ErnaneJ/sculptor/master/assets/coin.gif" width="100%"> |

## About

Tool in C++ to make sculptures in blocks represented by digital matrices. It allows the user to be able to create a plain text file that contains a sequence of steps to be followed to define properties of a three-dimensional matrix. The properties contain specifications for coordinates in the three-dimensional plane and color, with added transparency, for the elements. The built model can be visualized with the help of visualization software such as [GeomView](http://www.geomview.org/).

##  Docs
Access the documentation for using the Sculptor class [here](https://ernanej.github.io/sculptor/).

## Conceptualization files

- The system has a strong feature to read figures recorded in a file and
  draw them according to the present instructions. The file can
  contain the following instructions.
- The file will contain several of these lines, each one containing an instruction orienting the type of drawing to be carried out in the sequence. At the end, the program will read this file and create an output file in `OFF` format containing the design conceptualized in the provided file.

| Code | What it does|
|:-------|:------|
| `dim largura altura profundidade`| Defines the dimensions of the sculpture. <br/><br/> Ex.: `dim 60 40 55`|
| `putvoxel x y z r g b a` | Draw a voxel at position (`x`,`y`,`z`) with color `r`,`g`,`b` and `a`. <br/><br/> Ex.: `putvoxel 5 5 10 1.0 0.8 0.4 0.3`|
| `cutvoxel x y z` | Deletes a voxel at position (`x`,`y`,`z`) with color `r`,`g`,`b` and `a`. <br/><br/> Ex.: `cutvoxel 5 5 10` |
| `putbox xi xf yi yf zi zf r g b a` | Draws a parallelepiped delimited by `x` belonging to (`xi`, `xf`), `y` belonging to (`yi`, `yf`) and `z` belonging to (`zi`, `z1`) with the color `r`, `g`, `b` and `a`. <br/><br/> Ex.: `putbox 10 15 12 33 1 8 0.4 0.5 0.8 1`|
| `cutbox xi xf yi yf zi zf` | Deletes a parallelepiped delimited by `x` belonging to (`xi`, `xf`), `y` belonging to (`yi`, `yf`) and `z` belonging to (`zi`, `z1`). <br/><br/> Ex.: `cutbox 10 15 12 33 1 8`|
| `putsphere x_center y_center z_center radius r g b a` | Draws a sphere with center at point (`x_center`, `y_center`, `z_center`), specified `radius` and color `r`, `g`, `b` and `a`.<br/><br/> Ex.: `putsphere 10 10 5 3 1.0 1.0 0.5 0.3`|
| `cutsphere x_center y_center z_center radius` | Deletes a sphere with center at the specified point (`x_center`, `y_center`, `z_center`), `radius`. <br/><br/> Ex.: `cutsphere 10 10 5 3`
| `putellipsoid x_center y_center z_center x_radius y_radius z_radius r g b a` | Draws an ellipsoid with center at point (`x_center`, `y_center`, `z_center`), specified radii (`x_radius`, `y_radius`, `z_radius`) and color `r`,`g`,`b ` and `a`.<br/><br/> Ex.: `putellipsoid 10 10 5 3 4 5 1.0 0.5 0.9 0.4`
| `cutellipsoid x_center y_center z_center x_radius y_radius z_radius` | Deletes an ellipsoid with center at point (`x_center`, `y_center`, `z_center`) and specified radius (`x_radius`, `y_radius`, `z_radius`).<br/><br/> Ex.: `cutellipsoid 10 10 5 3 4 5`|

## Running

```bash
  $ chmod +x ./run.sh && ./run.sh

  # to directly open the file in geomeview

  $ chmod +x ./run.sh && ./run.sh --geomview bmo # necessary to have geomview previously installed
```

---

<div align="center">
  Developed with ❤ by <a href="https://links.ernane.dev/">Ernane Ferreira</a>. 👋🏻<br/> Encouraged and idealized in semester 2022.1 by the teacher <a href="https://agostinhobritojr.github.io/">Agostinho Brito Junior</a>. <br> Federal University of Rio Grande do Norte - Department of Computer Engineering and Automation.
</div>
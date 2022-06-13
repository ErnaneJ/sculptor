#include <vector>

#include "./headers/interpreter.h"

int main() {
  Sculptor *sculpture;
  Interpreter interpreter;
  std::vector<FiguraGeometrica*> figs;

  figs = interpreter.parse("./examples/conceptualization_files/coin.txt");
  sculpture = new Sculptor(interpreter.getDimX(), interpreter.getDimY(), interpreter.getDimZ());
  for(int i=0; i<figs.size(); i++){
    figs[i] -> draw(*sculpture);
  }
  sculpture -> writeOFF("off_files/sculpture.off");

  for(size_t i = 0; i < figs.size(); i++){
    delete figs[i];
  }
  delete sculpture;
  
  return 0;
}
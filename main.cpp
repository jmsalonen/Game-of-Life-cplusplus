#include <vector>
#include <iostream>
#include "life.h"

using namespace cpp_life; 
using namespace std; 

int main() {
  
    /*
     *  _0123
     *  0_x_x
     *  1x_xx
     *  2_x_x
     *  3____
     */
    
    vector<Life::Cell> init; 
    
    init.push_back(Life::Cell::Cell(0, 1)); 
    init.push_back(Life::Cell::Cell(0, 3)); 
    init.push_back(Life::Cell::Cell(1, 0)); 
    init.push_back(Life::Cell::Cell(1, 2)); 
    init.push_back(Life::Cell::Cell(1, 3)); 
    init.push_back(Life::Cell::Cell(2, 1)); 
    init.push_back(Life::Cell::Cell(2, 3)); 
    
    Life game = Life(init); 
    
    cout << game << endl; 
    
    for (int i = 0; i < 10; ++i) {
      game.simulate(1); 
      cout << game << endl; 
    }
    
  
  return 0; 
}

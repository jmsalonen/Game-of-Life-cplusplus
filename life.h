#ifndef CPP_LIFE_H
#define CPP_LIFE_H

#include <vector>
#include <iostream>

namespace cpp_life {
  
  class Life {
    
  public: 
    
    struct Cell {
      int i, j;
      Cell(int x, int y);
    };
  
  private: 
    
    int gen; 
    std::vector<Cell> cells; 
    
  public:
    
    Life(const std::vector<Cell> &init);
    
    int generation() const;
    void simulate(int steps);
    std::vector<Cell> liveCells() const;
    
    int countNeighbors(int i, int j, const std::vector<Cell>& c) const;
    bool isAlive(int i, int j, const std::vector<Cell>& c) const;
    
    void addCell(const int& i, const int& j);
    
  };
  
  std::ostream& operator<<(std::ostream& os, const Life& l);
  
}

#endif

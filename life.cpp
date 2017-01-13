#include <vector>
#include <iostream>

#include "life.h"

using namespace std; 

namespace cpp_life {
  
  Life::Life(const vector<Cell>& init) {
    if (init.size() > 0) {
      gen = 0; 
      for (unsigned int i = 0; i < init.size(); ++i) {
        cells.push_back(init.at(i));
      }
    }
  }
  
  Life::Cell::Cell(int x, int y) {
    i = x;  
    j = y;  
  }
  
  int Life::generation() const {
    return gen; 
  }
  
  int Life::countNeighbors(int i, int j, const vector<Cell>& c) const {
    int nbcount = 0; 
    
    if (c.size() > 0) {
      for (int x = 0; x < c.size(); ++x) {
        // TOP
        if (c.at(x).i == i-1 && c.at(x).j == j-1) {
          ++nbcount;
        }
        if (c.at(x).i == i-1 && c.at(x).j == j) {
          ++nbcount;
        }
        if (c.at(x).i == i-1 && c.at(x).j == j+1) {
          ++nbcount;
        }
        
        // MID
        if (c.at(x).i == i && c.at(x).j == j-1) {
          ++nbcount;
        }
        if (c.at(x).i == i && c.at(x).j == j+1) {
          ++nbcount;
        }
        
        // BOTTOM
        if (c.at(x).i == i+1 && c.at(x).j == j-1) {
          ++nbcount;
        }
        if (c.at(x).i == i+1 && c.at(x).j == j) {
          ++nbcount;
        }
        if (c.at(x).i == i+1 && c.at(x).j == j+1) {
          ++nbcount;
        }
      }
    }
    
    return nbcount; 
  }
  
  bool Life::isAlive(int i, int j, const vector<Life::Cell>& c) const {
    
    if (c.size() > 0) {
      for (int x = 0; x < c.size(); ++x) {
        if (c.at(x).i == i && c.at(x).j == j) {
          return true; 
        }
      }
    }
    return false; 
  }
  
  void Life::addCell(const int &i, const int &j) {
    if (!isAlive(i, j, cells)) {
      cells.push_back(Cell(i, j));
    }
  }
  
  vector<Life::Cell> Life::liveCells() const {
    vector<Cell> status = cells; 
    return status; 
  }
  
  void Life::simulate(int steps) {
    
    while (steps > 0) {
      vector<Cell> newCells; 
      int begin_i = 0, begin_j = 0, end_i = 0, end_j = 0; 
      
      // find the beginning and the end of the "area" with living cells
      for (int x = 0; x < cells.size(); ++x) {
        if (cells.at(x).i < begin_i) {
          begin_i = cells.at(x).i;
        }
        if (cells.at(x).j < begin_j) {
          begin_j = cells.at(x).j;
        }
        if (cells.at(x).i > end_i) {
          end_i = cells.at(x).i; 
        }
        if (cells.at(x).j > end_j) {
          end_j = cells.at(x).j; 
        }
      }
      
      // Let's increase the "map" size just in case. 
      begin_i -= 2; 
      begin_j -= 2; 
      end_i += 2; 
      end_j += 2; 
      
      for (int i = begin_i; i < end_i; ++i) {
        for (int j = begin_j; j < end_j; ++j) {
          
          bool alive = isAlive(i, j, cells); 
          int neighbors = countNeighbors(i, j, cells); 
          
          if (alive) {
            if (neighbors == 2 || neighbors == 3) 
              newCells.push_back(Cell(i, j));
          }
          else {
            if (neighbors == 3) {
              newCells.push_back(Cell(i, j)); 
            }
          }
          
        }
      }
      
      cells = newCells; 
      --steps;
      ++gen; 
    }
    
  }
  
  std::ostream& operator<<(std::ostream& os, const Life::Life& l) {
    os << "Generation: " << l.generation() << '\n'; 
    
    for (int i = -10; i <= 10; ++i) {
      for (int j = -20; j <= 20; ++j) {
        if (l.isAlive(i, j, l.liveCells())) {
          os << '#'; 
        }
        else if (i % 3 == 0 && j % 3 == 0) {
          os << '.'; 
        }
        else {
          os << ' '; 
        }
      }
      os << '\n';
    }
    
    return os; 
  }
  
}

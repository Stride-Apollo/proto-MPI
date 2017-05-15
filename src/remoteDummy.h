#pragma once
#include <vector>
#include "dataDummy.h"
// TODO Inherits of AsyncSimulator
class remoteDummy{
  public:
    remoteDummy(uint id):m_id(id){};
    ~remoteDummy() = default;
    void sendData(dataDummy data, const int destination, const int tag){
      MPI_Send(&data, 1, MPI_INT, destination, tag, MPI_COMM_WORLD);
    }
    uint getId() const {return m_id;}
  private:
    uint m_id;
};

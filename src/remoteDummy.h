#pragma once
#include <vector>
#include "dataDummy.h"
// TODO Inherits of AsyncSimulator
class remoteDummy{
  public:
    remoteDummy(uint id):m_id(id){};
    ~remoteDummy() = default;
    template<class T>
    void sendData(T data, const int times, const int destination, int tag){
      MPI_Send(&data, times, MPI_INT, destination, tag, MPI_COMM_WORLD);
    }
    uint getId() const {return m_id;}
  private:
    uint m_id;
};

#pragma once
#include <mpi.h>
#include "dataDummy.h"
class receiverDummy{
  public:
    receiverDummy(uint id): m_id(id){};
    ~receiverDummy() = default;
    void receiveData(dataDummy data, const int source, int tag){
      MPI_Recv(&data, 1, MPI_INT, source, tag, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    }
    uint getId() const {return m_id;}
  private:
    uint m_id;
};

#pragma once

#include <mpi.h>
#include <string>
#include <iostream>

#include "dataDummy.h"

class remoteSimulatorReceiver{
  public:
    remoteSimulatorReceiver(uint id): m_id(id), m_data("MESSAGE RECEIVED"){};
    ~remoteSimulatorReceiver() = default;
    template<class T>
    void receiveData(T data, const int maxOccurrences,const int source, int tag){
      MPI_Recv(&data, maxOccurrences, MPI_INT, source, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      std::cout << "ID("<< m_id << ") Received message " << data << " from source " << source << " with tag " << tag << ".\n";
    }

    void respond(const int maxOccurrences, const int dest, int tag){
      MPI_Send(&m_data, maxOccurrences, MPI_INT, dest, tag, MPI_COMM_WORLD);
      std::cout << "ID("<< m_id << ") Response message " << m_data << " to destination " << dest << " with tag " << tag << ".\n";
    }
    uint getId() const {return m_id;}
    std::string getData() const {return m_data;}
  private:
    uint m_id;
    std::string m_data;
};

#pragma once

#include <vector>
#include <iostream>
#include "dataDummy.h"

// TODO Inherits of AsyncSimulator

class remoteSimulatorSender{
  public:
    remoteSimulatorSender(uint id):m_id(id){};
    ~remoteSimulatorSender() = default;

    // This should implement the sendTravellers of the AsyncSimulator
    // Define a tag for this kind of messages (for example 1)
    // TODO which number of times?
    template<class T>
    void sendData(T data, const int times, const int destination, int tag){
      MPI_Send(&data, times, MPI_INT, destination, tag, MPI_COMM_WORLD);
      std::cout << "ID("<< m_id << ") Sent message " << data << " to destination " << destination << " with tag " << tag << ".\n";
    }

    // Obsolete, not longer necessary, but keep it for examplatory reasons
    template<class T>
    void receiveData(T data, const int times,const int source, int tag){
      MPI_Recv(&data, times, MPI_INT, source, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      std::cout << "ID("<< m_id << ") Received message " << data << " from source " << source << " with tag " << tag << ".\n";
    }
    uint getId() const {return m_id;}
  private:
    uint m_id;
};

#pragma once

#include <mpi.h>
#include <string>
#include <iostream>
#include <vector>

#include "dataDummy.h"
class TravellerType;

class remoteSimulatorReceiver{
  public:
    remoteSimulatorReceiver(uint id): m_id(id){};
    ~remoteSimulatorReceiver() = default;

    // This should receive the travellers sent by sendTravellers (the remoteSimulatorSender)
    // And have tag 1 (defined in remoteSimulatorSender)
    template <class T>
    bool hostTravellers(T travellers, uint days, std::string destination_district, std::string destination_facility){
      MPI_Recv(&travellers, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      std::cout << "Message @ receiver side: \n";
      std::cout << "Received travellers TODO for " << days << " for " << destination_district << " and facility " << destination_facility << std::endl;
      return true;
    };

    uint getId() const {return m_id;}
  private:
    uint m_id;
};

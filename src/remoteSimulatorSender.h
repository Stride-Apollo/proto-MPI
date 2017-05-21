#pragma once

#include <vector>
#include <iostream>
#include "dataDummy.h"
#include "AsyncSimulator.h"

class remoteSimulatorSender: public AsyncSimulator{
  public:
    remoteSimulatorSender() = default;
    ~remoteSimulatorSender() = default;

    // TODO
    virtual future<bool> timeStep(){};

    // Implemented method of the AsyncSimulator interface
    virtual vector<unsigned int> sendTravellersAway(uint amount, uint days, uint destination_sim_id, std::string destination_district, std::string destination_facility){
      auto data = travelData(amount, days, destination_district, destination_facility);
      // TODO times more than 1??
      // TODO define a tag specific for this message (now it is 1)
      MPI_Send(&data, 1, MPI_INT, destination_sim_id, 1, MPI_COMM_WORLD);
      std::cout << "Message @ sender side: \n";
      data.print();
      std::cout << std::endl;
      return {};
    };

    // TODO implement
    virtual vector<unsigned int> sendTravellersHome(){
      return {};
    };
};

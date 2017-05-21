#include <iostream>
#include <string>
#include <mpi.h>
#include <vector>
#include "remoteSimulatorReceiver.h"
#include "remoteSimulatorSender.h"
#include "dataDummy.h"

// Go to http://mpitutorial.com/tutorials/ for more information

int main(){
  std::cout << "MPI prototype per process\n";

  // Set up remote and receiver
  std::vector<int> v = {1,2,3,4};
  remoteSimulatorSender remote;
  remote.setId(0);
  remoteSimulatorReceiver receiver{1};

  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  // Find out rank, size
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Tag is used to specify the message ID
  // When a process requests a message with a certain tag number,
  // messages with different tags will be buffered by the network until the process is ready for them.
  int tag = 1;
  int times = 1;
  uint days = 3;
  uint people = 5;
  std::string district = "District 13";
  std::string facility = "Facility 1";
  dataDummy data = dataDummy("Hello world!", 5);

  if (world_rank == remote.getId()) {
    // Send travellers to the receiver
    remote.sendTravellersAway(people, days,receiver.getId(), district, facility);
  } else if (world_rank == receiver.getId()) {
    // TODO replace v with real travellers
    receiver.hostTravellers(v, days, district, facility);
  }

  // Finalize the MPI environment.
  MPI_Finalize();
}

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
  remoteSimulatorSender remote{0};
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
  dataDummy data = dataDummy("Hello world!", 5);

  if (world_rank == remote.getId()) {
    // Remote will send vector v, 1 time, to the receiver with a specific tag
    remote.sendData(&v, times, receiver.getId(), tag);
  } else if (world_rank == receiver.getId()) {
    // Receiver will receive a vector v, 1 time, from remote with a specific tag
    receiver.receiveData(&v, times, remote.getId(), tag);
  }

  // New message tag
  tag = 2;
  if (world_rank == receiver.getId()){
    receiver.respond(times, remote.getId(), 2);
  }else if(world_rank == remote.getId()){
    remote.receiveData(receiver.getData(), times, receiver.getId(), tag);
  }

  // Finalize the MPI environment.
  MPI_Finalize();
}

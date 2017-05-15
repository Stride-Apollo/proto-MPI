#include <iostream>
#include <string>
#include <mpi.h>
#include <vector>
#include "remoteDummy.h"
#include "receiverDummy.h"
#include "dataDummy.h"

int main(){
  std::cout << "MPI prototype per process\n";
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);

  std::vector<int> v = {1,2,3,4};
  receiverDummy receiver{0};
  remoteDummy remote{1};
  // Find out rank, size
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Dummy code
  int tag = 10;
  dataDummy data = dataDummy("Hello world!", 5);
  int occurrences = 0;
  if (world_rank == 0) {
      remote.sendData(&v, 1, remote.getId(), tag);
      // remote.sendData(data, 1, remote.getId(), tag);
      // tag++;
      // times = rand();
      // remote.sendData(array, 1, remote.getId(),tag);
  } else if (world_rank == 1) {
      MPI_Status status;
      receiver.receiveData(&v, 1, receiver.getId(), tag, status);
      // receiver.receiveData(data, 1, receiver.getId(), tag, status);
      std::cout << "Process 1 received message " << data.getMessage() << " from process 0\n";
      // After receiving the message, check the status to determine
      // how many numbers were actually received
      MPI_Get_count(&status, MPI_INT, &occurrences);
      std::cout << "Proc 1 received " << occurrences << " messages from " << status.MPI_SOURCE << " with tag "<< status.MPI_TAG << "\n";
  }

  // Finalize the MPI environment.
  MPI_Finalize();
}

#include <iostream>
#include <string>
#include <mpi.h>
#include "remoteDummy.h"
#include "receiverDummy.h"
#include "dataDummy.h"

int main(){
  std::cout << "MPI prototype per process\n";
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);

  receiverDummy sender{0};
  remoteDummy remote{1};
  // Find out rank, size
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Dummy code
  int tag = 1;
  dataDummy data = dataDummy("Hello world!", 5);
  if (world_rank == 0) {
      MPI_Send(&data, 1, MPI_INT, remote.getId(), tag, MPI_COMM_WORLD);
  } else if (world_rank == 1) {
      // MPI_Recv(&data, 1, MPI_INT, sender.getId(), tag, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      sender.receiveData(data, sender.getId(), tag);
      std::cout << "Process 1 received message(" << data.getMessage() << ") from process 0\n";
      data.printContent();
  }

  // Finalize the MPI environment.
  MPI_Finalize();
}

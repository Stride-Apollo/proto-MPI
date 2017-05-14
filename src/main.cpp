#include <iostream>
#include </usr/local/include/mpi.h>

class remote{};
class receiver{};
int main(){
  std::cout << "MPI prototype\n";
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  // Based dummy on http://mpitutorial.com/tutorials/mpi-send-and-receive/
  // Find out rank, size
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  int number;
  if (world_rank == 0) {
      number = -1;
      MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
  } else if (world_rank == 1) {
      MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE);
      std::cout << "Process 1 received number " << number << " from process 0\n";
  }
  MPI_Finalize();
}

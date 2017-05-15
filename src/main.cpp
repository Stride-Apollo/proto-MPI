#include <iostream>
#include <string>
#include <mpi.h>

class remote{};
class receiver{};

class DummyData{
  public:
    DummyData(std::string i_msg, int i_vct): msg(i_msg), content(i_vct){}
    std::string getMessage(){return msg;}
    void printContent(){
      std::cout << "Contents ";
      std::cout << content << std::endl;
    }
  private:
    std::string msg;
    int content;
};

int main(){
  std::cout << "MPI prototype\n";
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);

  // Find out rank, size
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Dummy code
  DummyData data = DummyData("Hello world!", 5);
  if (world_rank == 0) {
      MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
  } else if (world_rank == 1) {
      MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      std::cout << "Process 1 received message(" << data.getMessage() << ") from process 0\n";
      data.printContent();
  }

  // Finalize the MPI environment.
  MPI_Finalize();
}

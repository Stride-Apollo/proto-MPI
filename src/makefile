EXECS=mpi_dummy
MPICC?=mpicc

all: ${EXECS}

mpi_dummy: main.cpp
	${MPICC} -o mpi_dummy main.cpp

clean:
	rm -f ${EXECS}

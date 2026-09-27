#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("Etapa 1: Rank %d de %d antes de MPI_Barrier\n", rank, size);
    fflush(stdout);

    // Simula que algunos procesos tardan más en llegar a la barrera
    sleep(rank % 3);

    MPI_Barrier(MPI_COMM_WORLD);

    printf("Etapa 2: Rank %d de %d después de MPI_Barrier\n", rank, size);
    fflush(stdout);

    MPI_Finalize();
    return 0;
}

#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // El rank 0 se identifica como comunicador
    if (rank == 0) {
        printf("Rank 0 comunicador\n");
        fflush(stdout);
    }

    MPI_Barrier(MPI_COMM_WORLD);

    // Mostrar los ranks en orden 1, 2, ..., size-1
    for (int i = 1; i < size; i++) {
        if (rank == i) {
            printf("Rank %d con size %d\n", rank, size);
            fflush(stdout);
        }
        MPI_Barrier(MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}

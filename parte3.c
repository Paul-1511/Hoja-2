#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    long long valor = 0;   // cambiado a long long

    if (rank == 0) {
        valor = 9999999999LL;   // valor grande con sufijo LL
        printf("Rank 0 (coordinador) asigna valor = %lld\n", valor);
        fflush(stdout);
    }

    // Difunde un long long desde el rank 0
    MPI_Bcast(&valor, 1, MPI_LONG_LONG, 0, MPI_COMM_WORLD);

    printf("Rank %d recibió valor = %lld\n", rank, valor);
    fflush(stdout);

    MPI_Finalize();
    return 0;
}

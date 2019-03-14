#include <mpi.h>
#include <stdio.h>
#define ROOT 0
#define MSG_TAG 100

int main(int argc, char **argv)
{
	int tid,size;
	MPI_Status status;

	MPI_Init(&argc, &argv); //Musi być w każdym programie na początku

	printf("Checking!\n");
	MPI_Comm_size( MPI_COMM_WORLD, &size );
	MPI_Comm_rank( MPI_COMM_WORLD, &tid );
	printf("My id is %d from %d\n",tid, size);

	int i;

	if ( tid == ROOT)
	{
		i=0;

		MPI_Ssend( &i, 1, MPI_INT, 1, MSG_TAG, MPI_COMM_WORLD );
		printf(" Wyslalem %d do %d\n", i, 1);

		MPI_Recv(&i, 1, MPI_INT, size-1, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		printf(" Otrzymalem %d od %d\n", i, status.MPI_SOURCE);
	}
	else
	{
		MPI_Recv(&i, 1, MPI_INT, tid-1, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		printf(" Otrzymalem %d od %d\n", i, status.MPI_SOURCE);

		i++;

		if(tid+1>size-1)
		{
			MPI_Ssend( &i, 1, MPI_INT, 0, MSG_TAG, MPI_COMM_WORLD );
			printf(" Wyslalem %d do %d\n", i, 0 );
		}
		else
		{
			MPI_Ssend( &i, 1, MPI_INT, tid+1, MSG_TAG, MPI_COMM_WORLD );
			printf(" Wyslalem %d do %d\n", i, tid+1 );
		}
		
	}

	MPI_Finalize(); // Musi być w każdym programie na końcu
}

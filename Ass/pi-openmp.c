#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>

double getTime() {
    const double kMicro = 1.0e-6;
    struct timeval TV;
    const int RC = gettimeofday(&TV, NULL);
    if (RC == -1) {
        printf("ERROR: Bad call to gettimeofday\n");
        return -1;
    }
    return ((double)TV.tv_sec) + kMicro * ((double)TV.tv_usec);
}

double parallelCompute(long iterations, int numberOfThreads) {
    double local_sum = 0.0;
    omp_set_num_threads(numberOfThreads);

    #pragma omp parallel for reduction(+:local_sum)
    for (long k = 0; k < iterations; k++) {
        double factor = (k % 2 == 0) ? 1.0 : -1.0;
        local_sum += factor / (2 * k + 1);
    }

    return 4.0 * local_sum;
}

double sequentialCompute(long iterations) {
    double factor = 1.0;
    double sum = 0.0;

    for (long k = 0; k < iterations; k++) {
        sum += factor / (2 * k + 1);
        factor *= -1;
    }

    return 4.0 * sum;
}

double getDifference(double calculatedPi) {
    return calculatedPi - 3.14159265358979323846;
}

int main(int argc, char* argv[]) {
    double sequentialStart, sequentialEnd, sequentialTime;
    double parallelStart, parallelEnd, parallelTime;
    double sequentialPi, parallelPi;
    double sequentialDifference, parallelDifference;
    long iterations;
    int numberOfThreads;

    if (argc > 1) {
        iterations = strtol(argv[1], NULL, 10);
        numberOfThreads = strtol(argv[2], NULL, 10);
    } else {
        printf("Usage: %s ITERS NumThreads\n", argv[0]);
        return 0;
    }

    // Time sequential calculation
    sequentialStart = getTime();
    sequentialPi = sequentialCompute(iterations);
    sequentialEnd = getTime();
    sequentialTime = sequentialEnd - sequentialStart;

    // Time parallel calculation
    parallelStart = getTime();
    parallelPi = parallelCompute(iterations, numberOfThreads);
    parallelEnd = getTime();
    parallelTime = parallelEnd - parallelStart;

    // Calculate differences from actual Pi
    sequentialDifference = getDifference(sequentialPi);
    parallelDifference = getDifference(parallelPi);

    // Print results
    printf("Sequential Calculation: %f\n", sequentialPi);
    printf("This is %f away from the correct value of PI.\n\n", sequentialDifference);
    printf("Parallel Calculation: %f\n", parallelPi);
    printf("This is %f away from the correct value of PI.\n\n", parallelDifference);
    printf("Number of iterations: %ld, Number of Threads: %d\n\n", iterations, numberOfThreads);

    // Validate parallel computation
    double difference = parallelDifference - sequentialDifference;
    if (difference < 0.01 && difference > -0.01)
        printf("Parallel calculation is VALID!\n");
    else
        printf("Parallel calculation is INVALID!\n");

    // Calculate and print speedup
    double speedup = sequentialTime / parallelTime;
    printf("Sequential Time: %f, Parallel Time: %f, Speedup: %f\n", sequentialTime, parallelTime, speedup);

    return 0;
}
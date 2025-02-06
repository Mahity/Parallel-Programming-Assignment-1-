#include <stdio.h>
#include <math.h>

void part_a_calculate_speedup_efficiency() {
    FILE *fp = fopen("part_a_output.csv", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    // Write headers to CSV
    fprintf(fp, "n,p,Speedup,Efficiency\n");
    
    int n_values[] = {10, 20, 40, 80, 160, 320};
    int p_values[] = {1, 2, 4, 8, 16, 32, 64, 128};
    
    for (int i = 0; i < 6; i++) {
        int n = n_values[i];
        double T_serial = n * n;
        
        for (int j = 0; j < 8; j++) {
            int p = p_values[j];
            double T_parallel = (n * n) / (double)p + log2(p);  // Parallel time for part a
            double speedup = T_serial / T_parallel;
            double efficiency = speedup / p;
            
            // Write the results for each n and p to CSV
            fprintf(fp, "%d,%d,%.4f,%.4f\n", n, p, speedup, efficiency);
        }
    }
    
    fclose(fp);
    printf("Results written to part_a_output.csv\n");
}

void part_b_slow_overhead_growth() {
    FILE *fp = fopen("slow_overhead_output.csv", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    // Write headers to CSV
    fprintf(fp, "n,p,Speedup,Efficiency\n");
    
    int n_values[] = {10, 20, 40, 80, 160, 320};
    int p_values[] = {1, 2, 4, 8, 16, 32, 64, 128};
    
    for (int i = 0; i < 6; i++) {
        int n = n_values[i];
        double T_serial = n * n;
        
        for (int j = 0; j < 8; j++) {
            int p = p_values[j];
            double T_parallel = (n * n) / (double)p + log2(n);  // Slow overhead growth: log2(n)
            double speedup = T_serial / T_parallel;
            double efficiency = speedup / p;
            
            // Write the results for each n and p to CSV
            fprintf(fp, "%d,%d,%.4f,%.4f\n", n, p, speedup, efficiency);
        }
    }
    
    fclose(fp);
    printf("Results written to slow_overhead_output.csv\n");
}

void part_b_fast_overhead_growth() {
    FILE *fp = fopen("fast_overhead_output.csv", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    // Write headers to CSV
    fprintf(fp, "n,p,Speedup,Efficiency\n");
    
    int n_values[] = {10, 20, 40, 80, 160, 320};
    int p_values[] = {1, 2, 4, 8, 16, 32, 64, 128};
    
    for (int i = 0; i < 6; i++) {
        int n = n_values[i];
        double T_serial = n * n;
        
        for (int j = 0; j < 8; j++) {
            int p = p_values[j];
            double T_parallel = (n * n) / (double)p + n;  // Fast overhead growth: n
            double speedup = T_serial / T_parallel;
            double efficiency = speedup / p;
            
            // Write the results for each n and p to CSV
            fprintf(fp, "%d,%d,%.4f,%.4f\n", n, p, speedup, efficiency);
        }
    }
    
    fclose(fp);
    printf("Results written to fast_overhead_output.csv\n");
}

int main() {
    // Part (a) - Calculate speedup and efficiency with given formula
    part_a_calculate_speedup_efficiency();
    
    // Part (b) - Slow and Fast Overhead Growth experiments
    part_b_slow_overhead_growth();
    part_b_fast_overhead_growth();
    
    return 0;
}

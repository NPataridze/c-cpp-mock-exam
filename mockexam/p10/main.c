#include <stdio.h>

void print_matrix(int **A, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main(){
    FILE* file = fopen("matrix.dat", "r"); 
    if(file == NULL){
        return 1;
    }

    int rows, cols;
    if(fscanf(file, "%d", &rows) != 1 || fscanf(file, "%d", &cols) != 1){
        printf("failed to read rows and cols\n");
        fclose(file);
        return 1;
    }

    int **matrix = (int*)malloc(rows * sizeof(int*));
    if(matrix == NULL){
        fclose(file);
        return 1;
    }

    for(int i = 0; i < rows; i++){
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if(matrix == NULL){
            fclose(file);
            return 1;
        }
        for(int j = 0; j < cols; j++){
            matrix[i][j] = 0;
        }
    }

    int row, col, value;
    while(fscanf(file, "%d %d %d\n", &row, &col, &value) == 3){
        if(row >= 1 && row <= rows && col >= 1 && col <= cols){
            matrix[row - 1][cols - 1] = value;
        }else {
            printf("invalid input\n");
        }
    }
    fclose(file);

    print_matrix(matrix, rows, cols);
    for(int i = 0; i < rows; i++){
        free(matrix[i]);
    }
    free(matrix);

    return 0;

}
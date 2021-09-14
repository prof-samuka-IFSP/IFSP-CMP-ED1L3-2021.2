#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// função que aloca dinamicamente um vetor
// com n elementos double
double *create_double_vector(int n) {
    //// alternativa 1
    // double *vet = NULL;
    // vet = calloc(n, sizeof(double));
    // return vet;

    //// alternativa 2
    return calloc(n, sizeof(double));
}


void create_double_vector_by_ref(int n,
                                 double **vet_ref) {
    *vet_ref = calloc(n, sizeof(double));
}


double *copy_double_vector(double *v, int n) {
    // declarar uma variavel v_copy e alocar
    // uma regiao na heap com n elementos double
    double *v_copy = create_double_vector(n);
    // double *v_copy = calloc(n, sizeof(double));

    // copiar cada um dos elementos do vetor v
    // em v_copy
    for (int i = 0; i < n; i++) {
        v_copy[i] = v[i];
    }

    // retornar v_copy
    return v_copy;
}

void print_double_vector(double *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%lf, ", v[i]);
    }
    printf("\n");
}


// checa se o vetor v1 é igual ao vetor v2,
// ou seja, se ambos possuem os mesmos elementos
bool are_double_vectors_equal(double *v1, double *v2, int n) {
    // por padrão, assuma que os vetores são iguais
    bool is_equal = true;

    // para cada elemento dos vetores, cheque
    // se há ao menos um único elemento que é diferente.
    // Se houver, os vetores são diferentes.
    // Assim, ao achar o primeiro valor diferente,
    // pare o loop e assuma que os vetores são
    // diferentes.
    // Se ao percorrer todos os elementos não
    // encontrarmos nenhum elemento diferente,
    // nossa premissa inicial que eles são verdadeiros,
    // continua sendo válida.
    for (int i = 0; i < n; i++) {
        // se os elementos no índice [i] são diferentes
        if (v1[i] != v2[i]) {
            // assuma que os vetores são diferentes
            is_equal = false;
            // saia/pare o loop
            break;
        }
    }

    return is_equal;
}


int main() {
    int n = 4;

    double *v = NULL;
    v = create_double_vector(n);
    v[0] = 0;
    v[1] = 10;
    v[2] = 20;
    v[3] = 30;
    
    printf("v\n");
    print_double_vector(v, n);
    printf("\n");

    // double *v2 = NULL;
    // create_double_vector_by_ref(4, &v2);

    double *v_copy = copy_double_vector(v, n);
    printf("v_copy\n");
    print_double_vector(v_copy, n);
    printf("\n");

    printf("v == v_copy\n");
    if (v == v_copy) {
        printf("Verdade\n\n");
    }
    else {
        printf("Falso\n\n");
    }

    printf("are_double_vectors_equal(v, v_copy)\n");
    if (are_double_vectors_equal(v, v_copy, n)) {
        printf("Verdade\n\n");
    }
    else {
        printf("Falso\n\n");
    }

    return 0;
}

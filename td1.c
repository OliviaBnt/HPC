#include <omp.h>
#include <stdlib.h>
#include <stdio.h> 
#include <time.h>

// gcc/g++ --fopenmp -o td1 td1.c
// export OMP_NUM_THREADS=2 ; ./td1

void func(double* tab, int size){ 
  #pragma omp parallel
  for ( int i = 0 ; i < size ; ++i ) {
    tab[i] = (double) rand();
  }
}

double* add(double* tab1, double* tab2, int size){
  double* tab;
  tab = malloc(size * sizeof(double));
  #pragma omp parallel for
  for ( int i = 0 ; i < size ; ++i ) {
    tab[i] = tab1[i] + tab2[i];
  }
  return tab;
}


double sum(double* tab, int size){
  double total = 0;
  #pragma omp parallel for reduction (+:total)
  for ( int i = 0 ; i < size ; ++i ) {
    total += tab[i];
  }
}

/* Passage à l'échelle fort :
  coeurs : 1, 2, 4
  Teste vecteur de taille fixe avec tous les coeurs
  
  Passage à l'échelle faible 
     Teste vecteur de taille variée proportionnel au nb de coeurs :
     1 c = 1 000 000
     2c = 2 000 000
     3c = 4 000 000
*/
  

int main (int argc , char ** argv ) {
  /* 
   * Function qui va déterminer le temps de calcul
   * before lié avec after et diff
   * CLOCKS_PER_SEC = précision jusqu'à laquelle on peut aller (nombre de tours (genre 1 000000)*/
  int threads = atoi(argv[2]);
  omp_set_num_threads(threads);
  
  
  double before = (clock() * 1000)/CLOCKS_PER_SEC;
  srand(time(NULL));
  
  
  /* peut être remplacé par argv.
  Ecrire './td1 1024' dans le terminal pour executer avec la bonne valeur de taille */
  
  int size = atoi(argv[1]);
  double* tab1;
  double* tab2;
  
  tab1 = malloc(size * sizeof(double));
  func(tab1, size);
  tab2 = malloc(size * sizeof(double));
  func(tab2, size);
  
  
  double total = sum(tab1, size);
  printf("Total = %f \n", total);
  
  double* tab = add(tab1 , tab2, size);
  
  
  
  double after = (clock() * 1000)/CLOCKS_PER_SEC;
  double diff = after - before;
  printf("temps : %f\n", diff);
  
  
  /********* TESTS !!! ************/
  /*Test fonction add  
  *
  for ( int i = 0 ; i < size ; ++i ) {
    printf("%f + %f = %f \n", tab1[i], tab2[i], tab[i]);
  }
  */
  
  /******* TEST tab ***********
  *
  for ( int i = 0 ; i < size ; ++i ) {
    printf("%f\n", tab[i]);
  }*/
  
  
  free(tab1);
  free(tab2);
}

#include <omp.h>
#include <stdlib.h>
#include <stdio.h> 
#include <time.h>

// gcc/g++ --fopenmp -o td1 td1.c
// export OMP_NUM_THREADS=2 ; ./td1

// Fonction qui crée un vecteur
void func(double* tab, int size){ 
  for ( int i = 0 ; i < size ; ++i ) {
    tab[i] = (double) rand();
  }
}

// Fonction qui crée une matrice
void funcMat(double** mat, int size){
  for ( int i = 0 ; i < size ; ++i ) {
    for (int j = 0 ; j < size ; ++j){
      mat[i][j] = (double) rand();
    }
  }
}

// Fonction qui additionne 2 vecteurs entre eux
double* add(double* tab1, double* tab2, int size){
  double* tab;
  tab = malloc(size * sizeof(double));
  #pragma omp parallel for
  for ( int i = 0 ; i < size ; ++i ) {
    tab[i] = tab1[i] + tab2[i];
  }
  return tab;
}

// Fonction qui additionne 2 matrice entre elles
void addMat(double** mat1, double** mat2, int size){
  //double mat[size][size];
  #pragma omp parallel for
  for ( int i = 0 ; i < size ; ++i ) {
    for (int j = 0 ; j < size ; ++j){
      mat1[i][j] + mat2[i][j];
      //printf("%f + %f = %f \n", mat1[i][j], mat2[i][j], mat[i][j]);
    }
  }
}

//Fonction qui somme les éléments d'un vecteur
double sum(double* tab, int size){
  double total = 0;
  #pragma omp parallel for reduction (+:total)
  for ( int i = 0 ; i < size ; ++i ) {
    total += tab[i];
  }
}

//Fonction qui somme tous les éléments d'une matrice entre eux
double sumMat(double** mat, int size){
  double total = 0;
  #pragma omp parallel for reduction (+:total)
  for ( int i = 0 ; i < size ; ++i ) {
    for (int j = 0 ; j < size ; ++j){
      total += mat[i][j];
    }
  }
  //printf(" total = %f \n", total);
}

//
/*************************** MAIN CODE ****************************/
int main (int argc , char ** argv ) {
  
  /*
   * Nombre de threads correspondant au deuxième argument de argv */
  int threads = atoi(argv[2]);
  omp_set_num_threads(threads);
  

  /*
  Ecrire './td1 1024' dans le terminal pour executer avec la bonne valeur de taille */
  
  int size = atoi(argv[1]);
  double* tab1;
  double* tab2;
  double** mat1;
  double** mat2;
  
  /*Declarations des variables*/
  
  tab1 = malloc(size * sizeof(double));
  func(tab1, size);
  tab2 = malloc(size * sizeof(double));
  func(tab2, size);
  
  mat1 =(double **)malloc(size*sizeof(double));
  for ( int i = 0 ; i < size ; ++i ){
    mat1[i] = (double *) malloc(size*sizeof(double));
  } 
  funcMat(mat1, size);
  
  mat2 =(double **)malloc(size*sizeof(double));
  for ( int i = 0 ; i < size ; ++i ){
    mat2[i] = (double *) malloc(size*sizeof(double));
  }
  funcMat(mat2, size);
  
  /* 
   * clock() = Fonction qui va déterminer le temps de calcul
   * before lié avec after et diff
   * CLOCKS_PER_SEC = précision jusqu'à laquelle on peut aller*/

/*
  double before = (clock() * 1000)/CLOCKS_PER_SEC;
  srand(time(NULL));
  
  double total = sum(tab1, size);
  */
  
  //addMat(mat1, mat2, size);
  
  sumMat(mat1, size);
  
  /*double* tab = add(tab1 , tab2, size);*/
  
  
  /*
  double after = (clock() * 1000)/CLOCKS_PER_SEC;
  double diff = after - before;
  printf("temps : %f\n", diff);
  
  
  /********* TESTS !!! ************/
  /*Test fonction add  */
  /*
  for ( int i = 0 ; i < size ; ++i ) {
    printf("%f + %f = %f \n", tab1[i], tab2[i], tab[i]);
  }
  */
  
  /*Test function sum*/
  /*printf("Total = %f \n", total);*/
  
  /******* TEST affichage ************/
  /* Test affichage vecteur
  for ( int i = 0 ; i < size ; ++i ) {
    printf("%f\n", tab[i]);
  }*/
  
  /* Test affichage matrice
  for ( int i = 0 ; i < size; ++i ) {
    for (int j = 0 ; j < size ; ++j){
      printf("%f\n", mat1[i][j]);
    }
  }*/
  
  free(tab1);
  free(tab2);
  free(mat1);
  free(mat2);
}

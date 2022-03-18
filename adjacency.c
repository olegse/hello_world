#include "adjacency.h"


int main() {
  
  adjmat mat;

  int u, v;

  printf("You have a matrix %dx%d.\nYou need to fill it with only two digits 0 or 1.\n", N, N);

  /*input to matrix arr from type adjmat*/
  inputToMatrix(mat);
  
  /*call the function to output the matrix*/
  printMatrix(mat);

  /*loop for input indexes & checking exit from the program via input '-1' '-1'*/
  while(u != -1 || v != -1){
    
    /*input index - u*/
    u = writeIndex('u');

    /*input index - v*/
    v = writeIndex('v');
   
    printf("\n=========================================");
    if(u == -1 && v == -1){
      printf("\nThe End!\nHave a nice day. Bye.\n");   
    }
    else{
      /*go to the function 'path' to check a junction and output result*/
      printf("\nHas %s junction with indexes %d and %d \n", path(mat, u, v) ? "a" : "not", u, v);
    }
    printf("=========================================\n");
  }
  
  return 0;
}

/*fill the matrix input line by line*/
void inputToMatrix(adjmat mat){
  int i, j;
  for(i = 0; i < N; i++){
    printf("Please fill inline %d using numbers only 0 or 1. \n", (i + 1));
    for(j = 0; j < N; j++){
      scanf("%d", &mat[i][j]); 
    }
  }
}

/*output matrix with indexes*/
void printMatrix(adjmat mat){
  int i, j;

  printf("\nYour matrix is:\n\n");

  for(i = 0; i < N; i++){
    if(i == 0){
      printf("     ");
      /*print indexes horizontal*/
      for(j = 0; j < N; j++){
        printf("%d  ", j);
      }
      printf("\n\n");
    }

    for(j = 0; j < N; j++){
      /*print indexes vertical*/
      if(j == 0){
        /*checking the index i (horizontal) 
          for one or two digits for a beautiful print*/
        if(i <= 9)
         printf(" %d   ", i); 
        else if(i >= 10)
          printf("%d   ", i);
      }

      /*checking the index j (vertical) 
        for one or two digits for a beautiful print*/
      if(j <= 9)
        printf("%d  ", mat[i][j]);
      else if(j >= 10)
        printf(" %d  ", mat[i][j]);
    }
    printf("\n");
  }  
}

/*input indexes u and v*/
int writeIndex(char typeIndex){
  int num;
  /*checking input from -1 to N-1*/
  do{
    printf("\nPlease enter index [%c] from 0 to %d to check a junction.\n", typeIndex, N - 1);
    printf("For exit from the program please enter '-1'\n");
    scanf("%d", &num);
  }while(!(num >= -1 && num < N));

  return num;
}

/*checking junction via indexes u and v to matrix recursively*/
int path(adjmat mat, int u, int v){
  int i;
  
  if(u == v)
    return TRUE; 
  else if(mat[u][v] == 1)
    return TRUE;
  else{ 
    /*checking connection*/
    for(i = 0; i < N; i++){
      if(mat[u][i] == 1 && path(mat, i, v) == TRUE)
        return TRUE;
    }
    return FALSE;
  }
}


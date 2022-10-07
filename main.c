#include <stdio.h>
#include <time.h>

#include "HatONames.h"

int main(int argc, char *argv[]) {
  srand(time(NULL));

  if(argc < 2)
  {
    printf("No se seleccionó archivo de esudiantes");
    return 0;
  }

  FILE *student_file = fopen(argv[1], "r");

  if(student_file == NULL)
  {
    printf("El archivo es inválido");
    return 0xF;
  }

  Hat* hat = hat_new();
  hat_load_from_file(hat, student_file);

  printf("Select 'p' to pull name, any other choice exits the program\n");

  int choice = fgetc(stdin);

  while(!hat_is_empy(hat))
  {
    if(choice == 'p') {
      // obtenemos un nombre del hat, y lo imprimimos
      char *name = hat_get_name(hat);
      printf("%s\n", name);
      free(name);
    } else if (choice == 'e' ) {
      printf("Gracias por usar hat o Names!");
      break;
    } else {
      printf("ese comando no es correcto \n");
    }

    fflush(stdin);
    choice = fgetc(stdin);
  }

  hat_destroy(hat);

  return 0;
}

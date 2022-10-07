//
// Created by Josean Camarena on 06/10/22.
//

#include "HatONames.h"

typedef struct node
{
  char* nombre;
  struct node *next;
}
Node;

struct hat
{
  // seria interesante que hat tuviera una lista alumnos
  // pero nuestro nodo no guardaria ints
  char **students; // esto es un "arreglo de strings"
  int total_student_count;
  int current_student_count;
};

Hat* hat_new()
{
  Hat *new = malloc(sizeof(Hat));

  new->students = NULL;
  new->total_student_count = 0;
  new->current_student_count = 0;

  return new;
}

int count_students_in_file(FILE* source)
{
  int count = 0;
  char buffer[255];
  // esto esta raro
  // porque estamos duplicando trabajo
  // existen tecnicas para "agrandar" un arreglo en mem dinamica (heap)

  while (fgets(buffer, 255, source) != NULL)
    count++;

  rewind(source);
  return count;
}

Hat* hat_load_from_file(Hat* h, FILE* source)
{
  // primero necesito saber CUANTOS estudiantes prentendemos agregar
  // actualizar el contador
  h->total_student_count = count_students_in_file(source);
  h->current_student_count = h->total_student_count;
  // reservar memoria para representarlos
  h->students = malloc(sizeof(char*) * h->total_student_count);
  // guardar los nombres de los estudiantes en hat
  char buffer[255];
  int i = 0;
  while (fgets(buffer, 255, source) != NULL)
  {
    // reservar memoria para ESTE NOMBRE en el hat
    h->students[i] = malloc(sizeof(char) * 255);
    strcpy(h->students[i], buffer);
    i++; // pasamos al siguiente elemento del arreglo
  }
  return h;
}

int hat_is_empy(Hat *h)
{
  return h->current_student_count == 0; // regresará true cuando ya no tengamos estudiantes
}

char* hat_get_name(Hat *h)
{
  // obtener un nombre al azar
  int random = rand() %  h->total_student_count;
  char *picked_student = malloc(sizeof(char) * 255);

  while(h->students[random] == NULL)
    random = (random + 1) % h->total_student_count;

  // ya encontramos un alumno valido o nuevo

  strcpy(picked_student, h->students[random]);
  free(h->students[random]); // liberamos el espacio del nombre
  h->students[random] = NULL;

  // disminuir el current_student_count
  h->current_student_count--;
  return picked_student;
}

void hat_destroy(Hat* hat)
{
  free(hat->students);
  free(hat);
}
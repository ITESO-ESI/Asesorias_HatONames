//
// Created by Josean Camarena on 06/10/22.
//

#ifndef ASESORIAS_HATONAMES_H
#define ASESORIAS_HATONAMES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct hat Hat;

Hat* hat_new();
void hat_destroy(Hat* hat);
Hat* hat_load_from_file(Hat* h, FILE* source);
int hat_is_empy(Hat *h);
char* hat_get_name(Hat *h);

#endif //ASESORIAS_HATONAMES_H

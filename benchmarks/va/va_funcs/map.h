#ifndef USER_H
#define USER_H

#include "../../../lib/processing/map/MapArgs.h"
#include "Param.h"
#include <stdio.h>
#include <stdlib.h>

void start_func(map_arguments_t *args) {}

void map_func(void *input, void *res) {
  *(T *)res = ((T *)input)[0] + ((T *)input)[1];
}

#endif
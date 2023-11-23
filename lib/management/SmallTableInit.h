#ifndef SMALLTABLEINIT_H
#define SMALLTABLEINIT_H
#include <dpu.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
    the UPMEM hardware needs to call some setup code before running
    the code is called once management_init is called
*/

void small_table_init(struct dpu_set_t set);

#endif
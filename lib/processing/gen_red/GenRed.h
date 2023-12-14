#ifndef GENRED_H
#define GENRED_H

#include <dlfcn.h>
#include <dpu.h>
#include <omp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "../../communication/CommOps.h"
#include "../ProcessingHelperHost.h"
#include "GenRedArgs.h"

/*
    table_gen_red implements the array reduction as in the paper
    It parses the function_handle and setups the host for calling the pim kernel
   (GenRed.c) Then it runs the array reduction pim kernel (gen_red_dpu.c and
   GenRedProcessing.h)
*/

void *table_gen_red(const char *src_name, const char *dest_name,
                    uint32_t output_type, uint32_t output_len,
                    handle_t *binary_handle,
                    simplepim_management_t *table_management, uint32_t info);
#endif

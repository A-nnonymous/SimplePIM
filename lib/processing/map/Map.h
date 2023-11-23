#ifndef MAP_H
#define MAP_H
#include "../../management/Management.h"
#include "../ProcessingHelperHost.h"
#include "MapArgs.h"
#include <dpu.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

/*
    table_map implements the array map operator as in the paper
    It parses the function_handle and setups the host for calling the pim kernel
   (Map.c) Then it runs the array reduction pim kernel (map_dpu.c and
   MapProcessing.h)
*/

void table_map(const char *src_name, const char *dest_name,
               uint32_t output_type, handle_t *binary_handle,
               simplepim_management_t *table_management, uint32_t info);
#endif

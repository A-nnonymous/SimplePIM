#ifndef ZIP_H
#define ZIP_H
#include <dpu.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "../../management/Management.h"
#include "../ProcessingHelperHost.h"
#include "ZipArgs.h"

/*
    table_zip implements the array zip operator as in the paper
    It setups the host for calling the pim kernel (Zip.c)
    Then it runs the array reduction pim kernel (zip_dpu.c and ZipProcessing.h)
*/

void table_zip(const char *src1_name, const char *src2_name,
               const char *dest_name, handle_t *binary_handle,
               simplepim_management_t *table_management);
#endif

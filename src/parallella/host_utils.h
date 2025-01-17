/*******************************************************************************
 *   Copyright (c) 2019 Dortmund University of Applied Sciences and Arts and others.
 *   
 *   This program and the accompanying materials are made
 *   available under the terms of the Eclipse Public License 2.0
 *   which is available at https://www.eclipse.org/legal/epl-2.0/
 *   
 *   SPDX-License-Identifier: EPL-2.0
 *   
 *   Contributors:
 *       Dortmund University of Applied Sciences and Arts - initial API and implementation
 *******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
//#include <e-hal.h> //hardware abstraction library
#include <time.h>   /* Needed for struct timespec */
//rtfp imports
#include "c2c.h"
#include "debugFlags.h"
#include "shared_comms.h"
#include "model_enumerations.h"

#define READ_PRECISION_US 1000

#define MEM_TYPE_SHM 	0
#define MEM_TYPE_DSHM 	1

typedef struct{
	unsigned row;
	unsigned col;
	unsigned num_visible_labels;
}LabelVisual;

/**
 * read a value of a label in a distributed shared memory section
 *
 * Arguments:
 * row			:	absolute row number of the core
 * col			:	absolute column number of the core
 * label_indx	:	index of the target shared label
 *
 */
void array_init(unsigned array[],unsigned array_size);

void user_config_print_legend(LabelVisual core_config,unsigned array[]);

void user_config_print_values(LabelVisual core_config,unsigned array[],unsigned int values_array[],unsigned int prv_val_array[]);

LabelVisual get_user_input(unsigned indices[]);

void user_config_print_legend_auto(unsigned array_length,unsigned array[]);

void user_config_print_values_auto(unsigned visible_label_count,unsigned array[],unsigned int values_array[],unsigned int prv_val_array[]);

unsigned get_user_input_DRAM(unsigned indices[]);

void print_legend_enum (unsigned label_count,unsigned label_positions[], unsigned memory_type);

int nsleep(long miliseconds);



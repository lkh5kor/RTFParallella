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


#include "model_enumerations.h"


char SHM_sec1_enum [SHM_section1_label_count][label_str_len] =
{
  "sh_label_a",
  "sh_label_b",
  "sh_label_c",
  "sh_label_d",
  "sh_label_e",
  "sh_label_f",
  "sh_label_g",
  "sh_label_h",
  "sh_label_i",
  "sh_label_j"
};

char DSHM_sec1_enum [DSHM_section1_label_count][label_str_len] =
{
  "DSH_labelA",
  "DSH_labelB",
  "DSH_labelC",
  "DSH_labelD",
  "DSH_labelE",
  "DSH_labelF",
  "DSH_labelG",
  "DSH_labelH",
  "DSH_labelI",
  "DSH_labelJ"
};

char task_enum [task_count +1][label_str_len] =
{
  "[idle]",
  "Task5ms0",
  "Task10ms0",
  "Task20ms0",
  "Task10ms1",
  "Task20ms1"
};

unsigned DSHM_visible_labels [DSHM_visible_label_count] = {0,1};
unsigned SHM_visible_labels [SHM_visible_label_count] = {0,1};



void get_SHM_label_name (int index,char str[]){
	for (int i=0;i<label_str_len;i++){
		str[i] = SHM_sec1_enum[index][i];
	}
}

void get_DSHM_label_name(int index,char str[]){
	for (int i=0;i<label_str_len;i++){
		str[i] = DSHM_sec1_enum[index][i];
	}
}

void get_task_name(int index,char *str){
	for (int i=0;i<label_str_len;i++){
		str[i] = task_enum[index][i];
	}
}

void get_visible_label_index(unsigned array[],unsigned mem_type){
	if (mem_type==0){
		for (int i=0; i<SHM_visible_label_count;i++){
			array[i] = SHM_visible_labels[i];
		}
	}
	for (int i=0; i<DSHM_visible_label_count;i++){
		array[i] = DSHM_visible_labels[i];
	}
}


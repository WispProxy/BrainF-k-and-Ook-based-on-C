#ifndef SETTINGS_GLOBAL_H
#define SETTINGS_GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---------------------------------Defines------------------------------------*/
/*BUFFER_SIZE = DGRAMRCVBUF = 256 Kb*/
#define BUFFER_SIZE			262144
/*CODE_SIZE = standard starting value for BrainF**k*/
#define CODE_SIZE			30000

#define OK          		0
#define FAILED				1
#define ERROR       		-1
/*-----------------------------Global variables-------------------------------*/
FILE *file; 
char data[BUFFER_SIZE];
/*----------------------------------------------------------------------------*/

/*---END CODE---*/
#endif

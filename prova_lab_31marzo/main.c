/**
 * \file main.c
 * File contenente le funzioni di main
 * \author Luciano faretra
 * \date 2015
 * \ver 1.0
 */


#include <stdlib.h>
#include <stdio.h>
#include "inputOutput.h"
#include "elaborazione.h"

int main(void)
{
	int j = 1;
	int targhet = 4;

	stampa_targhet(trova_targhet(lettura_file_testo(), j, targhet));

	return (0);
}


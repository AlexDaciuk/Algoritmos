/*
 * Prueba.c
 * 
 * Copyright 2015 alexdebian <alexdebian@alexdebian>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

/* Este es un programa de prueba, para que vayan probando ustedes */

#include <stdio.h>

int main(int argc, char **argv)
{
	int a ;
	char s[5];
	
	printf("Ingrese un numero menor a 10.000: ");
	fgets(s, 5, stdin);
	a = atoi(s);
	
	printf("Mientras la variable s es un vector de caracteres (string) \n");
	printf("la variable a es un entero \n");
	printf("Igual el numero que ingresaste es el %i. \n",a);
	
	return 0;
}


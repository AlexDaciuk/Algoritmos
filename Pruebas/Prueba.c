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
	/* Aca definimos las variables, usamos un entero para el numero en si
	 * y un vector de caracteres de 4 posiciones para guardar temporalmente
	 * el input, notese que puse un 5 entre corchetes, hay que tener en 
	 * cuenta que C usa un caracter de fin de linea al final de las cadenas
	 * asi que siempre hay que poner una posicion mas de lo que necesitamos */
	int a ;
	char s[5];
	
	/* Pedimos al usuario que ingrese un numero */
	printf("Ingrese un numero menor a 10.000: ");
	
	/* Usamos fgets porque es una funcion segura de ingreso de datos
	 * el primer parametro es la variable cadena donde se va a guardar
	 * lo que se ingresa por teclado, segundo es la cantidad de caracteres
	 * que tiene que admitir, incluyendo el caracter de fin de lineas, el
	 * ultimo parametro es para indicar de donde tiene que leer, en este
	 * caso es standard input */
	fgets(s, 5, stdin);
	
	/* Arriba guardamos el numero en una string, con atoi lo convertimos a
	 * int y lo guardamos en a */	
	a = atoi(s);
	
	/* Aca un ejemplo de como imprimir cosas por pantalla en C, usamos \n
	 * para indicar un salto de linea, se usa % y el tipo de dato que 
	 * queremos imprimir, %i para un integer por ejemplo, que se pone 
	 * en el lugar donde queremos que este el entero, despues se indica 
	 * fuera de la cadena de texto la variable a imprimir */
	printf("\nMientras la variable s es un vector de caracteres (string) \n");
	printf("la variable a es un entero \n \n");
	printf("Igual el numero que ingresaste es el %i. \n",a);
	
	return 0;
}


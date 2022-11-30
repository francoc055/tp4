/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

typedef struct{
	int id;
	char nombre[20];
	char sexo;
	float altura;
}ePersona;


int mostrarPersona(ePersona* m);
int mostrarPersonas(LinkedList* lista);
ePersona* newPersonaParam(int idStr,char* nombre,char sexo, float altura);
ePersona* p_new();

int main(void){
	startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort



		ePersona* auxPersona;
		ePersona* auxPersona2;

		// instancion un linkedlist
	    LinkedList* lista = ll_newLinkedList();
	    if(lista == NULL)
	    {
	    	printf("no se pudo crear el linkedlist");
	    	exit(1);
	    }

	    //muesto el tam del linkedlist
	    printf("%d\n", lista->size);

	    //creo una persona
	    auxPersona = newPersonaParam(1234, "franco", 'm', 1.70);

	    //agrego persona a la lista
	    ll_add(lista, auxPersona);
	    printf("%d\n", lista->size);

	    //creo una persona
		auxPersona = newPersonaParam(1235, "martin", 'm', 1.70);

		//agrego persona a la lista
		ll_add(lista, auxPersona);
		printf("%d\n", lista->size);

		auxPersona = (ePersona*) ll_get(lista, 0); // pasa la direcc de memoria
		mostrarPersonas(lista);

		auxPersona2 = (ePersona*) ll_get(lista, 1);
		printf("%d\n", ll_indexOf(lista, auxPersona2));

		auxPersona = newPersonaParam(1235, "mati", 'm', 1.70);
		ll_push(lista, 1, auxPersona); //agrega en el indice que pongamos
		mostrarPersonas(lista);


		auxPersona = newPersonaParam(1235, "laura", 'f', 1.70);
		ll_set(lista, 2, auxPersona); //remplaza en el indice que pongamos
		mostrarPersonas(lista);

		ll_remove(lista, 1);
		mostrarPersonas(lista); //elimina en el indice que pongamos

		auxPersona = (ePersona*) ll_pop(lista, 1);
		mostrarPersona(auxPersona);
		mostrarPersonas(lista);


		//ll_deleteLinkedList(lista);

    return 0;
}


int mostrarPersona(ePersona* m)
{
    int ret = 0;

    if(m != NULL)
    {

            printf("%-5d %26s %c %15.1f\n", m->id, m->nombre, m->sexo, m->altura);
            ret = 1;

    }
    return ret;
}

int mostrarPersonas(LinkedList* lista)
{
    int ret = 0;
	int leng;
	ePersona* aux;
		    if(lista != NULL && ll_len(lista) > 0)
		    {
		        leng = ll_len(lista);
		        //printf("id\t titulo\t genero\t rating\n"
		        		//"-------------------------------------\n");
		        for(int i = 0; i < leng; i++)
		        {
		            aux = (ePersona*) ll_get(lista, i);
		        	mostrarPersona(aux);
		        }
		        printf("\n\n");
		        ret = 1;
		    }
    return ret;
}

ePersona* p_new()
{
    ePersona* m = (ePersona*) malloc(sizeof(ePersona));
    if(m != NULL)
    {
        m->id = 0;
        *(m->nombre) = '\0';
        m->sexo = ' ';
        m->altura = 0;
    }
    return m;
}


ePersona* newPersonaParam(int idStr,char* nombre,char sexo, float altura)
{
    ePersona* m = p_new();
    if(m != NULL)
    {
        {
            free(m);
            m = NULL;
        }
    }

	return m;
}


























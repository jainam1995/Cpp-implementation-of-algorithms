#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct heap{
int capacity;
int size;
int *array;


};
struct heap* createheap(int capacity)
{struct heap* h=(struct heap*)malloc(sizeof(heap));
	h->array=(int*)malloc(sizeof(int)*capacity);

	return h;

}

int main()
{





	return 0;
}
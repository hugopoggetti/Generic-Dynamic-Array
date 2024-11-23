#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create new array
array *dynarray_create(size_t element_size)
{
    array *new = malloc(sizeof(array));
    new->data = NULL;
    new->capacity = 1;
    new->lenght = 0;
    new->element_size = element_size;
    return new;
}

// realloc array with multiple of 2 GROW_FACTOR
void dynarray_resize(array *a)
{
    // if it's the first element we allocate for 2 element
    if (a->lenght == 0)
        a->data = realloc(a->data, a->element_size * 2);

    if (a->lenght >= a->capacity) {
        a->capacity *= GROW_FACTOR;
        // new size if the current size is to small
        a->data = realloc(a->data, a->element_size * a->capacity);
    }
}

// push new element at the end of the array
void dynarray_push_back(array *a, void *element)
{
    // resize if we need
    dynarray_resize(a);
    // void *target = adress to add the new element
    void *target = ((char*)a->data + (a->lenght * a->element_size));
    // put element to the adress data + lenght
    memcpy(target, element, a->element_size);
    a->lenght++;
}

// get void * at the index we want
void *dynarray_get_element(array *a, size_t index)
{
    if (index >= a->lenght)
        return NULL;
    // return adress to data + index
    return (char *)a->data + index * a->element_size;
}

// push element at the top of the array
void dynarray_push_top(array *a, void *element)
{
    dynarray_resize(a);
    if (a->lenght > 0) {
        for (size_t i = a->lenght; i > 0; i--) {
            void *tmp = (char *)a->data + ((i - 1) * a->element_size);
            void *target = (char *)a->data + (i * a->element_size);
            memcpy(target, tmp, a->element_size);
        }
    }
    memcpy((char *)a->data, element, a->element_size);
}

// return true if the array is empty
bool dynarray_is_empty(array *a)
{
    if (a->lenght == 0)
        return true;
    return false;
}
// return thr size of the array
size_t dynarray_get_size(array *a)
{
    return a->lenght;
}

// retrun the last element and delete it
void *dynarray_pop(array *a)
{
    if (a->lenght == 0)
        abort();
    a->lenght--;
    // return the last element push so array[lenght - 1]
    return (char *)a->data + (a->lenght) * a->element_size;
}

// free array
void dynarray_destroy(array *a)
{
    free(a->data);
    free(a);
}


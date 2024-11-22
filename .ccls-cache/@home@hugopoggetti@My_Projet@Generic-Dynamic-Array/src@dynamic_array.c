#include "dynamic_array.h"

array *dynarray_create(size_t element_size)
{
    array *new = malloc(sizeof(array));
    new->data = NULL;
    new->capacity = 1;
    new->lenght = 0;
    new->element_size = element_size;
    return new;
}

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

void *dynarray_get_element(array *a, size_t index)
{
    if (index >= a->lenght)
        return NULL;
    // return adress to data + index
    return (char *)a->data + index * a->element_size;
}

void *dynarray_pop(array *a)
{
    if (a->lenght == 0)
        abort();
    // return the last element push so array[lenght - 1]
    return (char *)a->data + (a->lenght - 1) * a->element_size;
}

void dynarray_destroy(array *a)
{
    free(a->data);
    free(a);
}


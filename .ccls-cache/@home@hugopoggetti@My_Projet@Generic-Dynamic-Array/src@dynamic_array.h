#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#pragma once

typedef struct {
    void *data;
    size_t lenght;
    size_t capacity;
    size_t element_size;
} array ;

static const size_t GROW_FACTOR = 2;

array        *dynarray_create(size_t element_size);
void                     dynarray_resize(array *a);
void   dynarray_push_back(array *a, void *element);
void *dynarray_get_element(array *a, size_t index);
void                       *dynarray_pop(array *a);
void                    dynarray_destroy(array *a);


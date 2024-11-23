#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
size_t                 dynarray_get_size(array *a);
void    dynarray_push_top(array *a, void *element);
bool                   dynarray_is_empty(array *a);
int dynarray_swap(array *a, size_t index_i, size_t index_j);

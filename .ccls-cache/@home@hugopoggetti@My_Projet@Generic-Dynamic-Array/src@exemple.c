#include "dynamic_array.h"

int main(void)
{
    array *a = dynarray_create(sizeof(int));

    int e = 10;
    int b = 20;
    int c = 30;
    dynarray_push_back(a, &e);
    dynarray_push_back(a, &b);
    dynarray_push_back(a, &c);
    printf("first interger element = [%d]\nlast integer element = [%d]\n", *(int *)dynarray_get_element(a, 0), *(int *)dynarray_pop(a));
    dynarray_destroy(a);

    array *A = dynarray_create(sizeof(double));

    double E = 10.50149;
    double B = 20.25541;
    double C = 30.97544;
    dynarray_push_back(A, &E);
    dynarray_push_back(A, &B);
    dynarray_push_back(A, &C);
    printf("first float element = [%f]\nlast float element = [%f]\n", *(double *)dynarray_get_element(A, 0), *(double *)dynarray_pop(A));
    dynarray_destroy(A);
}

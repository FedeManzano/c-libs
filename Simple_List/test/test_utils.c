
#include "test_utils.h"

int comp_integer(const void *e1, const void *e2)
{
    int * ele1 = (int *)e1;
    int * ele2 = (int *)e2;

    return *ele1 - *ele2;
}

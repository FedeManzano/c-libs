#include <stdio.h>
#include <stdlib.h>
#include "static_stack.h"



int main()
{
    t_static_stack s;
    init_static_stack(&s);


    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int info;
    for(int i = 0; i < 10; i++)
        if(!is_full_static_stack(&s))
            push_static_stack(&s,&arr[i]);


    while(!is_empty_static_stack(&s))
    {
        pop_static_stack(&s, &info);
        printf("%d ", info);
    }

    return 0;
}

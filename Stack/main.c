#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    t_stack s;
    init_stack(&s);

    for(int i = 0; i < 10; i ++)
        if(!is_full_stack(&s))
            push_stack(&s,&arr[i],sizeof(int));

    int in;
    while(!is_empty_stack(&s)){
        pop_stack(&s,&in,sizeof(int));
        printf("%d ", in);
    }

    push_stack(&s,&in,sizeof(int));
    push_stack(&s,&in,sizeof(int));
    push_stack(&s,&in,sizeof(int));
    push_stack(&s,&in,sizeof(int));

    clear_stack(&s);


    printf("\nEsta vacia ?: %d", is_empty_stack(&s));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    t_queue q;

    init_queue(&q);


    for(int i = 0; i < 10; i ++)
        push_queue(&q,&arr[i],sizeof(int));

    int d;
    top_queue(&q,&d,sizeof(int));
    printf("Primer: %d\n", d);
    clear_queue(&q);
    while(!is_empty_queue(&q)){
        pop_queue(&q,&d,sizeof(int));
        printf("%d ", d);
    }

    return 0;
}

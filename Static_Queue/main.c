#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"


int main()
{
    t_static_queue q;
    init_static_queue(&q);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i++)
    {
        push_static_queue(&q,&arr[i],sizeof(int));
    }

    int info = 0;


//    pop_static_queue(&q,&info,sizeof(int));
  //  pop_static_queue(&q,&info,sizeof(int));
    //pop_static_queue(&q,&info,sizeof(int));


    info = 0;
    push_static_queue(&q,&info,sizeof(int));
    info ++;
    push_static_queue(&q,&info,sizeof(int));
    info ++;
    push_static_queue(&q,&info,sizeof(int));

    //pop_static_queue(&q,&info,sizeof(int));
    //pop_static_queue(&q,&info,sizeof(int));

    while(!is_empty_static_queue(&q))
    {
        pop_static_queue(&q,&info,sizeof(int));
        printf("%d ",info);
    }

    clear_static_queue(&q);

    return 0;
}

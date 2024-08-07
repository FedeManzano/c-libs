#include <stdio.h>
#include <stdlib.h>
#include "./it.h"

void it_arr(const void * expected, const void * result, const int ce, const int tam, t_comp comp, char * nameTest){
    if(!expected || !result || ce <= 0 || tam <= 0 || !nameTest)
    {
        message(nameTest," FAIL (Arguments Error)");
        return;
    }
    for(int i = 0; i < ce; i ++){

        if(comp(expected + i * tam, result + i * tam) != 0){
            message(nameTest, " FAIL [expected != result]");
            return;
        }
    }
    message(nameTest, " PASS");
}


void it(const void *expected, const void *result, const int tam, t_comp comp, char * nameTest){
    if(comp(expected,result) != 0){
        message(nameTest," FAIL [expected != result]");
        return;
    }
    message(nameTest," PASS");
}


void message(const char *mes, const char * res){
    printf("%s -> %s\n",mes, res);
}

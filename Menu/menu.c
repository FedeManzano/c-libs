#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./menu.h"

void init_menu(t_menu * menu,char options[TAM][TAM],char decorator){

    menu->cant = strlen(options[0]) + 1;
    menu->decorator = decorator;
    for(int i = 0; i < menu->cant ; i ++){
        strcpy(menu->options[i],options[i]);
    }
}


void show_menu(t_menu * menu){

    system("cls");
    printf("\n\t\t\tMenu de opciones\n\n");
    for(int i = 0; i< menu->cant - 1; i ++ ){
        printf("\t\t[ %c ] %c %s\n", menu->options[0][i], menu->decorator ,menu->options[i + 1]);
    }
}

int val_option(t_menu * menu, const char op){
    for(int i = 0; i < menu->cant; i ++){
        if( toupper(menu->options[0][i]) == toupper(op))
            return 1;
    }
    return 0;
}

char enter_option(int corr){
    char op;
    if(corr)
        printf("\n\n\tSeleccione una opcion: ");
    else
        printf("\n\n\tError seleccione nuevamente: ");
    fflush(stdin);
    scanf("%c",&op);
    return op;
}

char get_option(t_menu * menu){

    char op;
    int correcto = 1;
    do {
        show_menu(menu);
        op = enter_option(correcto);
        correcto = val_option(menu,op);
    }while(!correcto);
    return toupper(op);
}


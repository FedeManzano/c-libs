#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"

int main()
{
    char op[TAM_MENU][TAM_MENU] = {
        "123456789S",
        "Home",
        "Altas Empleados",
        "Bajas Empleados",
        "Actualizar Saldos",
        "Generar Reportes",
        "Emitir Voletines",
        "Pagar Licencias",
        "Pagar Impuestos",
        "Marketing Presupuesto",
        "Salir"
    };

    t_menu menu;
    init_menu(&menu,op,"Gestor de Cobros y Pagos");
    char o = '0';

    do{

        o = get_option(&menu);


        switch(o){
        case '1':
            system("cls");
            printf("Esta es la pagina principal\n");
            system("pause");
            break;
        }
    }while(o != 'S');


    return 0;
}

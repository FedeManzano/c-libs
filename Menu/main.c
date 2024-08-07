#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <menu.h>
#include <selection.h>
#include <date.h>

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
        case '2': system("cls");
                printf("\n\n\t\t\t%s\n",date_to_string(add_days( date_now(),-2),yyyy_MM_dd));
                system("pause");
        }
    }while(o != 'S');


    return 0;
}

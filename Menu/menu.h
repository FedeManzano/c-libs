
/**
    TDA Menú.

    Permite generar un menu en la consola de manera rápida
    y con ciertos controles funcionales.

    Ejemplo

    int main()
    {
        char opciones [TAM_MENU][TAM_MENU] = {
            "ABCDES", // Primera fila hace el papel de ind del menú
            "Primera Opción",
            "Segunda Opción",
            "Tercera Opción",
            "Cuarta Opción",
            "Quinta Opción",
            "Salir"

        };

        t_menu menu; // Menú
        init_menu(&menu,opciones,"Título del menú");

        char op;
        do {
            op = get_option(); // Opción seleccionada

            switch(op){
                /// Decidir que hacer
            }

        }while(op == 'S');
        return 0;
    }

    Resultado:
            Título del menú

        [ A ] > Primera Opcion
        [ B ] > Segunda Opción
        [ C ] > Tercera Opción
        [ D ] > Cuarta Opción
        [ E ] > Quinta Opción
        [ S ] > Salir

    Seleccione una Opción: _

    @author Federico Manzano (https://github.com/FedeManzano)
*/


#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

// Tamaño máximo del menú
#define TAM_MENU 100

/**
    TDA Menu personalizado para aplicaciones en lenguaje c.
    @author Federico Manzano
*/
typedef struct {
    // opciones del menú seteadas por el usuarion con el
    // método init_munu
    char options[TAM_MENU][TAM_MENU];

    // Cantidad del menú
    int cant;

    // Separador de opciones y descripciones
    char decorator;

    // Título del menú
    char * title;
} t_menu;

/**
    Inicializar el menú y le permite conf al usuario
    el título y las opciones del menú
*/
void init_menu(t_menu * menu, char options[TAM_MENU][TAM_MENU], const char *title);

/**
    Imprime el menú en la pantalla
*/
void show_menu(t_menu * menu);

/**
    Devuelve y valida la opción seleccionada por el usuario
    @return un char con la opción seleccionada
*/
char get_option(t_menu * menu);

#endif // MENU_H_INCLUDED

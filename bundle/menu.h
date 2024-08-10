
/**
    TDA Men�.

    Permite generar un menu en la consola de manera r�pida
    y con ciertos controles funcionales.

    Ejemplo

    int main()
    {
        char opciones [TAM_MENU][TAM_MENU] = {
            "ABCDES", // Primera fila hace el papel de ind del men�
            "Primera Opci�n",
            "Segunda Opci�n",
            "Tercera Opci�n",
            "Cuarta Opci�n",
            "Quinta Opci�n",
            "Salir"

        };

        t_menu menu; // Men�
        init_menu(&menu,opciones,"T�tulo del men�");

        char op;
        do {
            op = get_option(); // Opci�n seleccionada

            switch(op){
                /// Decidir que hacer
            }

        }while(op == 'S');
        return 0;
    }

    Resultado:
            T�tulo del men�

        [ A ] > Primera Opcion
        [ B ] > Segunda Opci�n
        [ C ] > Tercera Opci�n
        [ D ] > Cuarta Opci�n
        [ E ] > Quinta Opci�n
        [ S ] > Salir

    Seleccione una Opci�n: _

    @author Federico Manzano (https://github.com/FedeManzano)
*/


#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

// Tama�o m�ximo del men�
#define TAM_MENU 100

/**
    TDA Menu personalizado para aplicaciones en lenguaje c.
    @author Federico Manzano
*/
typedef struct {
    // opciones del men� seteadas por el usuarion con el
    // m�todo init_munu
    char options[TAM_MENU][TAM_MENU];

    // Cantidad del men�
    int cant;

    // Separador de opciones y descripciones
    char decorator;

    // T�tulo del men�
    char * title;
} t_menu;

/**
    Inicializar el men� y le permite conf al usuario
    el t�tulo y las opciones del men�
*/
void init_menu(t_menu * menu, char options[TAM_MENU][TAM_MENU], const char *title);

/**
    Imprime el men� en la pantalla
*/
void show_menu(t_menu * menu);

/**
    Devuelve y valida la opci�n seleccionada por el usuario
    @return un char con la opci�n seleccionada
*/
char get_option(t_menu * menu);

#endif // MENU_H_INCLUDED

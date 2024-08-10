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

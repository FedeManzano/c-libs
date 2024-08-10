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


#define TAM 50


typedef struct {
    char options[TAM][TAM];
    int cant;
    char decorator;
} t_menu;


/** \brief
 *  Inicializar el menú con los parámetros suministrados.
 * \param menu t_menu* Puntero a la estructura t_menu
 * \param options[TAM][TAM] char Opciones del menú
 * \param decorator char Caracter que separa la inicial de la opción con su nombre
 * \return void
 *
 */
void init_menu(t_menu * menu, char options[TAM][TAM],char decorator);



/** \brief
 *  Permite reimprimir el menú.
 * \param menu t_menu* Puntero aal menú
 * \return void
 *
 */
void show_menu(t_menu * menu);



/** \brief
 *  Permite pedirle una opción al usuario.
 * \param menu t_menu* Puntero al menú
 * \return char Opción seleccionada por el usuario.
 *
 */
char get_option(t_menu * menu);

#endif // MENU_H_INCLUDED

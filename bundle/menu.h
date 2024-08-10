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


#define TAM 50


typedef struct {
    char options[TAM][TAM];
    int cant;
    char decorator;
} t_menu;


/** \brief
 *  Inicializar el men� con los par�metros suministrados.
 * \param menu t_menu* Puntero a la estructura t_menu
 * \param options[TAM][TAM] char Opciones del men�
 * \param decorator char Caracter que separa la inicial de la opci�n con su nombre
 * \return void
 *
 */
void init_menu(t_menu * menu, char options[TAM][TAM],char decorator);



/** \brief
 *  Permite reimprimir el men�.
 * \param menu t_menu* Puntero aal men�
 * \return void
 *
 */
void show_menu(t_menu * menu);



/** \brief
 *  Permite pedirle una opci�n al usuario.
 * \param menu t_menu* Puntero al men�
 * \return char Opci�n seleccionada por el usuario.
 *
 */
char get_option(t_menu * menu);

#endif // MENU_H_INCLUDED

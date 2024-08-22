# Bibliotecas en lenguaje C

Algunos TDA para aprender programación e C.

- Algoritmos de ordenamiento
- Lista doblemnte enlazada
- Lista Simple
- Pila
- Cola
- Arbol binario
- TDA menú
- Fechas
- Test unitarios
- M String

## Cabeceras

### Algoritmos de ordenammiento

#### Quick Sort
```c
/**
* Función genérica de ordenamiento con el algoritmo quick sort.
*
* Funcion:
* void qs(void * arr, const int ce, const int tam, t_comp comp);
*
* @author Federico Manzano
*/
```

#### Selection Sort
```c
/**
    Algoritmo Selection Sort

    Algoritmo de ordenamiento de selección
    CC: n^2

    Ejemplo
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};

    selection_sort(arr,10,sizeof(int),comp_int);

    mostrar_arreglo(arr);

    Resultado:

    [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]

    @author Federico Manzano (https://github.com/FedeManzano)

*/

```

### Pila Dinámica

```c
/**
*   TDA Pila
*
*   Pila genérica para almacenar cualquier tipo de dato.
*   El puntero a la información, en la estructura, es de tipo
*   (void *).
*
*   ADV: Queda suje a la responsabilidad del usuario que no se ingresen varios
*   tipos de datos al mismo tiempo en la pila. Si esto sucede el funcionamiento
*   dará errores.
*
*   @author Federico Mazano (https://github.com/FedeManzano)
*/
```

### Cola Dinámica
```c
/**
    TDA Cola
    Cola dinámica genérica para cualquier tipo de dato
    @author Federico Manzano (https://github.com/FedeManzano)
*/
```


### Lista doblemente enlazada

```c

/**
*   TDA Lista doblemente enlazada genérica.
*
*   Se puede utilizar para gestionar cualquier tipo de dato
*   utilizando void * para abstraer la lógica de la lista y que
*   pueda ser reutilizada.
*
*   void init_list(t_list * l);
*   int is_empty_list(const t_list *l);
*   int is_full_list(const t_list * l);
*   int len_list(t_list *l);
*   int add_first_list(t_list *l, const void *info, const int tam);
*   int add_list(t_list *l, const void *info, const int tam);
*   int add_list_o(t_list *l, const void *info,const int tam, t_comp comp);
*   int try_add_list_o(t_list *l,const void *info,const int tam, t_comp comp);
*   int get_key_list(t_list *l, void *info,const int tam, t_comp comp);
*   int get_key_last_list(t_list *l, void *info,const int tam, t_comp comp);
*   void * get_info_list(t_list *l,void *info,const int tam,const int index);
*   int delete_list(t_list *l, void *info,const int tam, t_comp comp);
*   int delete_all_list(t_list *l, void *info,const int tam, t_comp comp);
*   void sort_list(t_list *l,const int tam, t_comp comp);
*   void sort_link_list(t_list *l, t_comp comp);
*   int insert_list(t_list *l,const void * info,const int tam, const int index);
*   void clear_list(t_list *l);
*   int to_array_list(t_list *l, void *arr, int tam);
*
*   Advertencia:
*
*   Esto es un TDA genérico, esto implica que la resposabilidad
*   de los tipos de datos ingresados a la lista es del usuario
*   que la utiliza.
*   Si ingresan a la misma lista varios tipos de datos y después
*   se producen errores, me desentiendo de la resposabilidad.
*
*
*   @author Federico Manzano (https://github.com/FedeManzano)
*/
```
### Lista Simplemente Enlazada
```c
/**
    TDA Lista Simplemente Enlazada

    Funciones:

    void init_simple_list(t_simple_list *l);
    int is_empty_simple_list(t_simple_list *l);
    int is_full_simple_list(t_simple_list *l);
    int add_simple_list(t_simple_list *l, const void *info, const size_t size);
    int len_simple_list(t_simple_list *l);
    int get_simple_list(t_simple_list *l, void *info, size_t size, const int index);
    int add_simple_list_in_order(t_simple_list *l, const void *info, const size_t size, t_comp comp);
    int add_first_simple_list(t_simple_list *l, const void *info, const size_t size);
    int add_simple_list_in_order_sd(t_simple_list *l, const void *info, const size_t size, t_comp comp);
    int try_add_simple_list_in_order_sd(t_simple_list *l, const void *info, const size_t size, t_comp comp);
    int try_add_simple_list_in_order_update(t_simple_list *l, const void *info, const size_t size, t_comp comp, t_update update);
    int insert_simple_list(t_simple_list *l,const void *info, size_t size,const int index);
    int insert_range_simple_list(t_simple_list *l,const void *arr, size_t size,const int ce, int index);
    void sort_simple_list(t_simple_list *l, size_t size, t_comp comp);
    int delete_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);
    int delete_all_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);
    int find_simple_list(t_simple_list *l, void *info, size_t size, t_comp comp);
    int index_of_simple_list(t_simple_list *l, const void *info, t_comp comp);
    void clear_simple_list(t_simple_list *l);

    ADV:

    Los tipos de datos agregados a este TDA son genéricos,
    por lo tanto, en cada lista creada es responsabilidad del
    programador almacer el mismo tipo de dato.

    @author Federico Manzano (https://github.com/FedeManzano)
*/

```


### Árbol Binario

```c
/**
    TDA Arbol Binario

    void init_tree_set (t_tree_set *t);
    int is_empty_tree_set(const t_tree_set *t);
    int is_full_tree_set(const int t_tree_set *)
    int add_tree_set(t_tree_set *t, const void *info, size_t size, t_comp comp);
    int count_tree_set(const t_tree_set *t);
    int height_tree_set(t_tree_set *t);
    int level_tree_set(t_tree_set *t);
    int count_leaf_tree_set(t_tree_set *t);
    int level_info_tree_set(t_tree_set *t,void *info, t_comp comp);
    int delete_tree_set(t_tree_set *t, const void *info,size_t size, t_comp comp);
    void delete_left_tree_set(t_tree_set *t);
    int find_tree_set(t_tree_set *t, void *info, size_t size, t_comp comp);
    void file_binary_to_tree_set(t_tree_set *t, FILE **fi, const size_t size_tree,const size_t size_arch, t_comp comp, t_read read);
    void clear_tree_set(t_tree_set *t);
    void in_order_tree_set(t_tree_set *a, t_show show);
    void pre_order_tree_set(t_tree_set *t, t_show show);
    void post_order_tree_set(t_tree_set *t, t_show show);
    void show_graph_tree_set(t_tree_set *t, t_gra dib, t_comp comp);
    void show_level_tree_set(t_tree_set *t, int level, t_show show);
    void show_leaf_tree_set(t_tree_set *t, t_show show);

    ADV: La informaci n ingresada al arbol es referenciada por un void *
    por lo tanto, para que el TDA funcione, hay que tener cuidado con la uniformidad del
    tipo de dato ingresado.
    Se pueden guardar datos de distintos tipos, pero no se van a poder acceder.

    @author Federico Manzano (https://github.com/FedeManzano)

*/

```

### Fechas

```c
/**
    TDA Date para trabajar con fechas.


    Funciones:

    int comp_date(const void *, const void *)
    int comp_time(const void *d1, const void *d2);
    int val_date(const int, const int, const int);
    int val_time(const int,const int, const int, const int, const int, const int);
    int days_of_month(const int, const int);
    int leap(const int);
    long days_transcurred (t_date *);
    long difference_days(t_date *, t_date *);
    double difference_time(t_date *, t_date *)
    t_date * add_day(t_date *)
    t_date * add_days(t_date *, int)
    t_date * subtract_day(t_date *d)
    t_date * subtract_days(t_date *, int)
    char * date_to_string (t_date *, const int)
    char * day_of_week(t_date *)
    t_date * date_now()
    t_date * add_hour(t_date *)
    t_date * subtract_hour(t_date *)
    t_date * add_hours(t_date *, const int)
    t_date * add_minute(t_date *)
    t_date * subtract_minute(t_date *)
    t_date * add_minutes(t_date *,  const int)
    t_date * add_second(t_date *)
    t_date * subtract_second(t_date *)
    t_date * add_seconds(t_date *, const int)

    ACLARACI N:
    Todas las funciones de a adir o sustraer (Dias, Horas, Minutos, Segundos)
    modifican el valor del par metro de entrada a la funci n.

    Por Ejemplo:
    t_date f1 = {3,1,2024};

    add_day(&f1); // Aqu  se modifica f1.

    printf(date_to_string(&f1,dd_MM_yyyy)); -> 4/1/1987

    @author Federico Manzano (https://github.com/FedeManzano)
*/
```

### TDA Menú

```c
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
```

### Test Unitarios

Librería simple para realizar test unitarios en C.

```c
/**
    Test Unitarios y de integración.

    Biblioteca con las funcionalidades básicas para realizar test unitarios
    y de integración.
    La composición es de tres funciones que permiten comparar arreglos, elementos
    individuales e imprimir un mensaje con el estado del test.


    Funciones:

    void it_arr(const void *, const void *, const int, const int, t_comp comp, char *);
    void it(const void *, const void *, const int, t_comp, char *);
    void message(const char *,const char *);


    Aclaración:

    Las funciones toman un valor esperado para la resolución del test, luego,
    lo compara con el resultado de una determinada operación que se desea probar. Si son iguales,
    entonces el test fue exitoso, caso contrario hubo una falla.

    Ejemplo:

    void test_OrdenarArregloDe5EnterosConQuickSort_RespuestaPass(){
        int expected [5] = {1,2,3,4,5};
        int result [5] = {5,4,3,2,1};

        qs(result, 5); // ordena el arreglo

        it_arr(expected,result, 5,sizeof(int), comp_integer,"1 - test_OrdenarArregloDe5EnterosConQuickSort_RespuestaPass");

    }
    Si la función qs funciona corretamente los arreglos expected y result son iguales despues de la llamada a la función.

    @author Federico Manzano
*/
```

### M String

```c
/**
    Simulación de la librería string.h

    Funciones:

    int m_strcmp(const char *s1,const char *s2);
    int m_strcmpi(const char *s1,const char *s2);
    int m_strncmp(const char *s1,const char *s2, size_t n);
    int m_strncmpi(const char *s1, const char *s2, size_t n)
    char * m_strcpy(char *s1, const char *s2);
    char * m_strncpy(char *s1, const char *s2, size_t n);
    char * m_strcat(char * s1, const char *s2);
    char * m_strncat(char *s1, const char *s2, size_t n);
    int m_strlen(const char * s);
    char * m_strchr(const char *s, const char c);
    char * m_strrchr(const char *s, const char c);
    char * m_strstr(const char *s1, const char *s2);
    size_t m_strspn(const char *s1, const char *s2);
    size_t m_strcspn(const char *s1, const char *s2);
    void * m_memcpy(void *e1, const void *e2,const size_t size);
    char * m_format_title(const char *s);

    @author Federico Manzano (https://github/FedeManzano)
*/
```

## Autor
[FedericoManzano](https://github.com/FedeManzano)


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

    ACLARACI�N:
    Todas las funciones de a�adir o sustraer (Dias, Horas, Minutos, Segundos)
    modifican el valor del par�metro de entrada a la funci�n.

    Por Ejemplo:
    t_date f1 = {3,1,2024};

    add_day(&f1); // Aqu� se modifica f1.

    printf(date_to_string(&f1,dd_MM_yyyy)); -> 4/1/1987

    @author Federico Manzano (https://github.com/FedeManzano)
*/

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#define dd_MM_yyyy      0
#define yyyy_MM_dd      1
#define DESCRIPTIVE     2
#define DESCRIPTIVE_2   3
#define DESCRIPTIVE_3   4
#define DESCRIPTIVE_4   5


/** ERROR cuando se produce una fecha erronea o retorne un *date NULL*/
#define DATE_ERROR     -10

/** La operaci�n termin� correctamente */
#define OK              1

/**
    Estructuta utilizada con los campos:
    d   -> dia
    m   -> mes
    y   -> a�o
    hh  -> hora
    mm  -> minuto
    ss  -> segundo
*/
typedef struct {
    int d, // Dia
        m, // Mes
        y, // A�o
        hh, // Hora
        mm, // Minuto
        ss; // Segundo
}t_date;

/**
    Compara dos fechas y devuelve un entro seg�n que fecha es mayor o si son iguales.
    @return 0 son iguales, -1 la primer fecha es menor, 1 la primera es mayor y -10 hay ERROR
*/
int comp_date(const void *f1, const void *f2);



/**
    Compara la estructura date completa, esto incluye hh mm ss respectivamente.
    @return 1 si la primera fecha es mayor, -1 si la segunda es mayor, 0 si son iguales y -10 si hay error.
*/
int comp_time(const void *d1, const void *d2);



/**
    Valida la fecha expresada en dias meses y a�os ingresados por par�metro.
    @return OK = 1 si la fecha es valida, ERROR = -10 si es erronea.
*/
int val_date(const int day, const int month, const int year);


/**
    Valida la fecha y el tiempo que pertenece a la estructura
    @return si existe un error devuelve -10 caso contrario devuelve 1
*/
int val_time(const int day,const int month, const int year, const int hour, const int minute, const int second);


/**
    Devuelve los dias del mes en cuesti�n.
    recibe el a�o y el mes.
    @return cantidad de dias del mes.
*/
int days_of_month(const int year, const int month);



/**
    Comprueba si un a�o es bisiesto.
    @return 1 si es bisiesto 0 si no lo es.
*/
int leap(const int year);



/**
    D�as transcurridos desde el a�o 1600.
    @return dias transcurridos.
*/
long days_transcurred (t_date *d);



/**
    Devuelve los dias de diferencia entre dos fechas.
    @return long (con la diferencia de fechas en dias).
*/
long difference_days(t_date *d1, t_date *d2);



/**
    Diferencia en segundos entre dos variables date.
    @return double con la dif en segundos.
*/
double difference_time(t_date *d1, t_date *d2);



/**
    A�ade un dia a una fecha.
    Mantiene la coherencia de la informaci�n.
    @return *t_date fecha actualizada.
*/
t_date * add_day(t_date *d);



/**
    A�ade n dias a una fecha.
    Si el valor de los dias es negativo resta n dias a una fecha.
    @return *t_date fecha actualizada.
*/
t_date * add_days(t_date *d, int days);



/**
    Resta un d�a a una fecha
    @return *t_date fecha actualizada
*/
t_date * subtract_day(t_date *d);



/**
    resta n dias a una fecha.
    Si el valor de dias es negativo resta dias,
    si el valor es positivo resta dias.
    @return *t_date Fecha actualizada.
*/
t_date * subtract_days(t_date *d, int days);



/**
    Devuelve una cadena con el formato seleccionado por el usuario.
    0 - dd_MM_yyyy      ej 1/1/2013
    1 - yyyy_MM_dd      ej 2013/1/1
    2 - DESCRIPTIVE     ej 1 de Enero del 2013
    3 - DESCRIPTIVE_2   ej Enero 1 del 2013
    4 - DESCRIPTIVE_3   ej Sabado 3 de Enero del 1987
    5 - DESCRIPTIVE_4   ej Sabado 3 de Enero del 1987 a las 19:45:35
    @return char * (con la fecha en formato cadena).
*/
char * date_to_string (t_date * f, const int format);



/**
    Devuelve el nombre del d�a de la semana al cual hace referencia la fecha.
    @return char * con el nombre del d�a (Lunes, Martes, etc).
*/
char * day_of_week(t_date * f);


/**
    Devuelve la fecha y hora actual.
    @return *t_date con el tiempo actual.
*/
t_date * date_now();


/**
    A�ade una hora a una fecha determinada.
    @return t_date * con la fecha actualizada.
*/
t_date * add_hour(t_date *f);



/**
    Resta una hora a una fecha determinada.
    @return t_date * con la fecha actualizada.
*/
t_date * subtract_hour(t_date *f);



/**
    A�ade varias horas a una fecha dereminada o
    resta varias horas a la fecha dependiendo
    del par�metro h si es positivo o negativo.
    @return t_date * con la fecha actualizada.
*/
t_date * add_hours(t_date * f, const int h);



/**
    A�ade un minuto a una fecha determinada manteniendo la coherencia de la informaci�n
    @return t_date * actualizado.
*/
t_date * add_minute(t_date *f);



/**
    Resta un minuto a una determinada fecha pasada por par�metro
    @return t_date * actualizado.
*/
t_date * subtract_minute(t_date *f);



/**
    A�ade N minutos a una fecha determinada manteniendo la coherencia de la informaci�n
    @return t_date * actualizado.
*/
t_date * add_minutes(t_date *f,  const int mins);



/**
    A�ade un segundo a una fecha determinada manteniendo la coherencia de la informaci�n
    @return t_date * actualizado.
*/
t_date * add_second(t_date *d);



/**
    Sustrae un segundo a una fecha determinada manteniendo la coherencia de la informaci�n
    @return t_date * actualizado.
*/
t_date * subtract_second(t_date *d);



/**
    A�ade o sustrae n segundos de una fecha determinada teniendo en cuenta
    el valor de el par�metro secs + / -. Si es negativo sustrae, si es positivo a�ade segundos.
    @return t_date * actualizado.
*/
t_date * add_seconds(t_date *f,  const int secs);



#endif // DATE_H_INCLUDED

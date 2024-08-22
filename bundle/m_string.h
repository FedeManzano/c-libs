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


#ifndef M_STRING_H_INCLUDED
#define M_STRING_H_INCLUDED



/** \brief
 *  Comprueba si el parámetro X es espacio o tabulación
 * \param X Tipo char
 * \return #define Verdadero si es espacio o TAB, falso si no lo es.
 */
#define ES_BLANCO(X)((X) == ' ' || (X) == '\t')



/** \brief
 * Comprueba si el parámetro X es mayusculas.
 * \param X char
 * \return #define Verdadero si es mayusculas, falso si no lo es.
 */
#define ES_MAY(X)((X) >= 'A' && (X) <= 'Z')


/** \brief
 * Comprueba si el parámetro X es minusculas.
 * \param X char
 * \return #define Verdadero si es minusculas, falso si no lo es.
 */
#define ES_MIN(X)((X) >= 'a' && (X) <= 'z')



/** \brief
 *  Si el parámetro X es minusculas lo devuelve en mayusculas.
 * \param X char
 * \return #define Letra mayusculas.
 */
#define A_MAY(X)(ES_MIN((X)) ? (X) - ' ': (X))



/** \brief
 *  Si el parámetro X es mayusculas lo devuelve en minusculas.
 * \param X char
 * \return #define Letra minusculas.
 */
#define A_MIN(X)(ES_MAY((X)) ? (X) + ' ': (X))



/** \brief
 * Compara caracter a caracter dos cadenas.
 * \param s1 const char* cadena de caracteres
 * \param s2 const char* cadena de caracteres
 * \return int -1 si s2 es mayor, 0 si son iguales y 1 si s1 es mayor.
 */
int m_strcmp(const char *s1,const char *s2);


/** \brief
 *  Comprueba dos cadenas ignorando las mayusculas y minusculas.
 * \param s1 const char* cadena de caracteres
 * \param s2 const char* cadena de caracteres
 * \return int -1 si s2 es mayor, 0 si son iguales y 1 si s1 es mayor.
 */
int m_strcmpi(const char *s1,const char *s2);


/** \brief
 *  Compara N caracteres entre la cadena 1 y la cadena 2.
 * \param s1 const char* cadena de caracteres
 * \param s2 const char* cadena de caracteres
 * \param n size_t cantidad de caracteres a comparar
 * \return int -1 si s2 es mayor, 0 si son iguales y 1 si s1 es mayor.
 */
int m_strncmp(const char *s1,const char *s2, size_t n);


/** \brief
 *  Compara N caracteres entre la cadena 1 y la cadena 2 ignorando las minúsculas y mayúsculas.
 * \param s1 const char* cadena de caracteres
 * \param s2 const char* cadena de caracteres
 * \return int -1 si s2 es mayor, 0 si son iguales y 1 si s1 es mayor.
 */
int m_strncmpi(const char *s1, const char *s2, size_t n);


/** \brief
 * Copia la cadena 2 en la cadena 1 modificando la cadena 1.
 * \param s1 char* cadena de caracteres
 * \param s2 const char* cadena de caracteres
 * \return char* cadena s1 modificada.
 */
char * m_strcpy(char *s1, const char *s2);


/** \brief
 * Copia n caracteres de la cadena s2 en la cadena s1.
 * \param s1 char* cadena de caracteres
 * \param s2 const char* cadena de caracteres
 * \param n size_t cantidad de caracteres a copiar en s1
 * \return char* cadena s1 modificada.
 */
char * m_strncpy(char *s1, const char *s2, size_t n);


/** \brief
 * Concatena la cadena s2 en s1.
 * \param s1 char* cadena de caracteres
 * \param s2 const char* cadena de caracteres.
 * \return char* s1 modificada.
 */
char * m_strcat(char * s1, const char *s2);



/** \brief
 *  Concatena n caracteres de la cadena s2 en s1.
 * \param s1 char* cadena de caracteres
 * \param s2 const char* cadena de caracteres
 * \param n size_t cantidad de caracteres a concatenar
 * \return char* cadena s1 modificada.
 */
char * m_strncat(char *s1, const char *s2, size_t n);


/** \brief
 * Cantidad de caracteres de la cadena s.
 * \param s const char* cadena de caracteres.
 * \return int cantidad de caracteres.
 */
int m_strlen(const char * s);


/** \brief
 * Busca la primera ocurrencia del caracter c en la cadena s.
 * \param s const char* cadena de caracteres.
 * \param c const char c.
 * \return char* cadena s desde el caracter c.
 */
char * m_strchr(const char *s, const char c);


/** \brief
 * Busca la última ocurrencia del caracter c en en la cadena s
 * \param s const char* cadena de caracteres
 * \param c const char caracter a buscar
 * \return char* Puntero a la cadena en la posición de c.
 */
char * m_strrchr(const char *s, const char c);


/** \brief
 * Busca la cadena s2 en s1.
 * \param s1 const char* cadena de caracteres
 * \param s2 const char* cadena de caracteres
 * \return char* Puntero a la posición de comienzo de la cadena s2 en s1.
 */
char * m_strstr(const char *s1, const char *s2);


/** \brief
 * Devuelve la posición del primer caracter que está en s1 y no está en s2.
 * \param s1 const char* cadena de caracteres
 * \param s2 const char* cadena de caracteres
 * \return size_t indice del primer elemento de s1 que no está en s2.
 */
size_t m_strspn(const char *s1, const char *s2);


/** \brief
 * Devuelve la posición del primer elemento de s1 que está en s2.
 * \param s1 const char* cadena de caracteres
 * \param s2 const char* cadena de caracteres
 * \return size_t cantidad de caracteres
 */
size_t m_strcspn(const char *s1, const char *s2);


/** \brief
 * Copia el contenido de la porción de memoria apuntada por *e2
 * en la porción de memoria apuntada por *e1.
 * \param e1 void* Puntero a una porción de memoria.
 * \param e2 const void* Puntero a una porción de memoria.
 * \param size const size_t tamaño en (byte) del espacio de memoria.
 * \return void* Espacio de memoria copiado.
 */
void * m_memcpy(void *e1, const void *e2,const size_t size);


/** \brief
 * Combierte una cadena de caracteres al formato título.
 * Maaaa Maaaa Maaaa.
 * \param s const char* Cadena de caracteres
 * \return char* cadena modificada.
 *
 */
char * m_format_title(const char *s);

#endif // M_STRING_H_INCLUDED

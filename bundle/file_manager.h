/**
    TDA File.
    Funciones muy utilizadas de archivos.

    Funciones

    int open_file_(t_file *file, const char *path, const char *mode);
    t_file open_file(const char *path, const char *mode);
    int show_file_(t_file *file, t_show_record record,const size_t size);
    int show_file(const char *path, t_show_record record,const size_t size);
    long file_bytes_ (t_file *file);
    long file_bytes (const char *path);
    long file_records_ (t_file *file, size_t size);
    long file_records (const char *path, size_t size);
    void file_close(t_file *file);
*/

#ifndef FILE_MANAGER_H_INCLUDED
#define FILE_MANAGER_H_INCLUDED

#define _OPEN_FILE_OK 1
#define _OPEN_FILE_ERROR 0
#define _FILE_ERROR -10

typedef FILE * t_file;

typedef void (*t_show_record)(const void *);


/** \brief
 * Permite la apertura de un archivo con el modo de operación deseado.
 * \param file t_file* Puntero al archivo
 * \param path const char* Ruta de archivo
 * \param mode const char* Modo de apertura
 * \return int 1 si se logró la apertura, 0 sino se pudo abrir
 */
int open_file_(t_file *file, const char *path, const char *mode);


/** \brief
 * Permite la apertura de un archivo a través de su path y modo de apertura.
 * \param path const char* Path del archivo
 * \param mode const char* Modo de apertura del archivo
 * \return t_file FILE *
 */
t_file open_file(const char *path, const char *mode);


/** \brief
 * Permite mostrar el archivo registro por registro.
 * \param file t_file* Puntero al archivo
 * \param record t_show_record Puntero a la función que muestra los registros
 * \param size const size_t Tamaño del tipo de dato almacenado en el archivo
 * \return int 1 Si pudo mostrar 0 sino pudo.
 */
int show_file_(t_file *file, t_show_record record,const size_t size);


/** \brief
 * Permite mostrar el archivo registro por registro.
 * \param path const char* Path del archivo
 * \param record t_show_record  Puntero a la función que muestra los registros
 * \param size const size_t Tamaño del tipo de dato almacenado en el archivo
 * \return int 1 Si pudo mostrar 0 sino pudo.
 */
int show_file(const char *path, t_show_record record,const size_t size);


/** \brief
 * Devuelve los bytes de un archivo
 * \param t_file => FILE *
 * \return long cantidad de bytes de un archivo
 */
long file_bytes_ (t_file *file);


/** \brief
 * Devuelve los bytes de un archivo
 * \param char * path del archivo
 * \return long cantidad de bytes de un archivo
 */
long file_bytes (const char *path);

/** \brief
 * Cantidad de registros de un archivo.
 * \param t_file FILE **
 * \param size_t tamaño del registro del archivo
 * \return Cantidad de registros del archivo
 */
long file_records_ (t_file *file, size_t size);


/** \brief
 * Cantidad de registros de un archivo.
 * \param const char * path del archivo
 * \param size_t tamaño del registro del archivo
 * \return Cantidad de registros del archivo
 */
long file_records (const char *path, size_t size);



/** \brief
 * Cierra el archivo
 * \param file t_file* Puntero al archivo. FILE **
 * \return void
 */
void file_close(t_file *file);

#endif // FILE_MANAGER_H_INCLUDED

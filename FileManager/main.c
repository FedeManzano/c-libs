#include <stdio.h>
#include <stdlib.h>
#include "test/test_file_manager.h"
#include "file_manager.h"

int main()
{
    test_OpenFile_AperturaYCreacionDeArchivos_Resultado_Pass();
    test_OpenFile_AperturaIncorrectaArchivoInexistente_Resultado_Pass();
    test_OpenFile_MostrarArchivoBinario_Resultado_Pass ();
    return 0;
}

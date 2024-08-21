#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "m_string.h"
#include "test/test_m_string.h"

int main()
{
    printf("TEST m_strcmp\n");
    test_Strcmp_CadenasVacias_Resultado_Pass ();
    test_Strcmp_UnaCadenaVacia_Resultado_Pass();
    test_Strcmp_UnaCadenaMasCorta_Resultado_Pass ();
    test_Strcmp_CadenasNumericas_Resultado_Pass();
    test_Strcmp_CadenasNumericasDni_Resultado_Pass();
    test_Strcmp_CadenasNumericasYLetras_Resultado_Pass();

    printf("\nTEST m_strcpy\n");
    test_Strcpy_CadenasVacias_Resultado_Pass();
    test_Strcpy_CadenaMasCorta_Resultado_Pass ();
    test_Strcpy_CadenaPrimeraMasCorta_Resultado_Pass();


    printf("\nTEST m_strcat\n");
    test_Strcat_PrimeraCadenaVacia_Resultado_Pass ();
    test_Strcat_PrimeraCadenaMasCorta_Resultado_Pass ();
    test_Strcat_SegundaCadenaMasCorta_Resultado_Pass();
    test_Strcat_NumerosYLetras_Resultado_Pass ();

    printf("\nTEST m_strlen\n");
    test_Strlen_CantidaSinElementos_Resultado_Pass();
    test_Strlen_CantidadDeCuatroElementos_Resultado_Pass();

    printf("\nTEST m_cmpi\n");
    test_Strcmpi_CadenasVacias_Resultado_Pass();
    test_Strcmpi_UnaCadenaVacia_Resultado_Pass();
    test_Strcmpi_UnaCadenaMasCorta_Resultado_Pass ();
    test_Strcmpi_CadenasNumericas_Resultado_Pass();


    printf("\nTEST m_strchr\n");
    test_Strchr_BuscarCaracter_Resultado_Pass ();
    test_Strchr_BuscarCaracterLetraE_Resultado_Pass ();

    printf("\nTEST m_strrchr\n");
    test_Strrchr_BuscarCaracterLetraE_Resultado_Pass();

    printf("\nTEST m_strncmp\n");
    test_Strncmp_CuartoCaracter_Resultado_Pass ();
    test_Strncmp_NIgualACero_Resultado_Pass ();
    test_Strncmp_NNegativo_Resultado_Pass();


    printf("\nTEST m_strncpy\n");
    test_Strncpy_CadenaUnoMasCorta_Resultado_Pass ();
    test_Strncpy_NNegativo_Resultado_Pass ();
    test_Strncpy_NCero_Resultado_Pass ();

    printf("\nTEST m_strstr\n");
    test_Strstr_PalabraContenida_Resultado_Pass ();
    test_Strstr_SegundaPalabraMasLarga_Resultado_Pass();
    test_Strstr_OcurrenciaAlFinal_Resultado_Pass ();
    test_Strstr_OcurrenciaAlPrincipio_Resultado_Pass();

    printf("\nTEST m_strspn\n");
    test_Strcpn_CuartaLetraDiferente_Resultado_Pass ();
    test_Strcpn_CadenasIguales_Resultado_Pass ();
    test_Strcpn_CadenasMismoTamDiferenteContenido_Resultado_Pass();
    test_Strcpn_TestDocumentacion_Resultado_Pass ();

    printf("\nTEST m_strcspn\n");
    test_Strcspn_TestDocumentacion_Resultado_Pass ();
    test_Strcspn_TestDocumentacionDos_Resultado_Pass();
    test_Strcspn_TestDocumentacionTres_Resultado_Pass ();
    test_Strcspn_TestDocumentacionCuatro_Resultado_Pass();


    printf("\nTEST m_strncat\n");
    test_Strncat_ConcatenarACadenaVacia_Resultado_Pass();
    test_Strncat_NNegativo_Resultado_Pass();
    test_Strncat_CadenaDosVacia_Resultado_Pass ();
    test_Strncat_CadenaDosMasGrandeQueElN_Resultado_Pass ();


    printf("\nTEST m_format_title\n");
    test_FormatTitle_FormatoTituloCadenaIrregular_Resultado_Pass();


    return 0;
}

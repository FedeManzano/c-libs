#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../bundle/it.h"
#include "../m_string.h"

int comp_int(const void *e1, const void *e2)
{
    int *ele1 = (int *)e1;
    int *ele2 = (int *)e2;
    return *ele1 - *ele2;
}


int comp_s(const void *e1, const void *e2)
{
    char * ele1 = (char *)e1;
    char * ele2 = (char *)e2;
    return m_strcmp(ele1,ele2);
}


void test_Strcmp_CadenasVacias_Resultado_Pass ()
{
    char pal1[10] = "";
    char pal2[10] = "";

    int exp = strcmp(pal1,pal2);
    int res = m_strcmp(pal1,pal2);
    it(&exp,&res,sizeof(int), comp_int,"1 - test_Strcmp_CadenasVacias_Resultado_Pass");
}


void test_Strcmp_UnaCadenaVacia_Resultado_Pass ()
{
    char pal1[10] = "";
    char pal2[10] = "Federico";

    int exp = strcmp(pal1,pal2);
    int res = m_strcmp(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"2 - test_Strcmp_UnaCadenaVacia_Resultado_Pass");

}


void test_Strcmp_UnaCadenaMasCorta_Resultado_Pass ()
{
    char pal1[10] = "Fede";
    char pal2[10] = "Federico";

    int exp = strcmp(pal1,pal2);
    int res = m_strcmp(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"3 - test_Strcmp_UnaCadenaMasCorta_Resultado_Pass");

}

void test_Strcmp_CadenasNumericas_Resultado_Pass ()
{
    char pal1[10] = "0001";
    char pal2[10] = "00010000";

    int exp = strcmp(pal1,pal2);
    int res = m_strcmp(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"4 - test_Strcmp_CadenasNumericas_Resultado_Pass");
}

void test_Strcmp_CadenasNumericasDni_Resultado_Pass ()
{
    char pal1[10] = "32595830";
    char pal2[10] = "2555544";

    int exp = strcmp(pal1,pal2);
    int res = m_strcmp(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"5 - test_Strcmp_CadenasNumericasDni_Resultado_Pass");
}

void test_Strcmp_CadenasNumericasYLetras_Resultado_Pass ()
{
    char pal1[10] = "Federico";
    char pal2[10] = "325888";

    int exp = strcmp(pal1,pal2);
    int res = m_strcmp(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"6 - test_Strcmp_CadenasNumericasYLetras_Resultado_Pass");
}


void test_Strcpy_CadenasVacias_Resultado_Pass ()
{
    char pal1[10] = "";
    char pal2[10] = "";

    char * exp = strcpy(pal1,pal2);
    char * res = m_strcpy(pal1,pal2);

    it_arr(exp,res,1,sizeof(exp), comp_s,"7 - test_Strcpy_CadenasVacias_Resultado_Pass");
}


void test_Strcpy_CadenaMasCorta_Resultado_Pass ()
{
    char pal1[10] = "federico";
    char pal2[10] = "fede";

    char * exp = strcpy(pal1,pal2);
    char * res = m_strcpy(pal1,pal2);

    it_arr(exp,res,1,sizeof(exp), comp_s,"8 - test_Strcpy_CadenaMasCorta_Resultado_Pass");
}


void test_Strcpy_CadenaPrimeraMasCorta_Resultado_Pass ()
{
    char pal1[10] = "fede";
    char pal2[10] = "federico";

    char * exp = strcpy(pal1,pal2);
    char * res = m_strcpy(pal1,pal2);

    it_arr(exp,res,1,sizeof(exp), comp_s,"9 - test_Strcpy_CadenaPrimeraMasCorta_Resultado_Pass");
}


void test_Strcat_PrimeraCadenaVacia_Resultado_Pass ()
{
    char pal1[10] = "";
    char pal2[10] = "federico";

    char * exp = "federico";
    char * res = m_strcat(pal1,pal2);

    it_arr(exp,res,1,sizeof(exp), comp_s,"10 - test_Strcat_PrimeraCadenaVacia_Resultado_Pass");
}

void test_Strcat_PrimeraCadenaMasCorta_Resultado_Pass ()
{
    char pal1[10] = {"fe"};
    char pal2[10] = {"derico"};

    char * exp = "federico";
    char * res = m_strcat(pal1,pal2);
    it_arr(exp,res,1,sizeof(exp), comp_s,"11 - test_Strcat_PrimeraCadenaMasCorta_Resultado_Pass");
}


void test_Strcat_SegundaCadenaMasCorta_Resultado_Pass ()
{
    char pal1[20] = {"ferico"};
    char pal2[10] = {"fede"};

    char * exp = "fericofede";
    char * res = m_strcat(pal1,pal2);

    it_arr(exp,res,1,sizeof(exp), comp_s,"12 - test_Strcat_SegundaCadenaMasCorta_Resultado_Pass");
}


void test_Strcat_NumerosYLetras_Resultado_Pass ()
{
    char pal1[20] = {"Federico"};
    char pal2[10] = {"-00114"};

    char * exp = "Federico-00114";
    char * res = m_strcat(pal1,pal2);

    it_arr(exp,res,1,sizeof(exp), comp_s,"13 - test_Strcat_NumerosYLetras_Resultado_Pass");
}

void test_Strlen_CantidaSinElementos_Resultado_Pass ()
{
    char pal1[20] = {""};

    int exp = strlen(pal1);
    int res = m_strlen(pal1);

    it(&exp,&res,sizeof(int), comp_int,"14 - test_Strlen_CantidaSinElementos_Resultado_Pass");
}

void test_Strlen_CantidadDeCuatroElementos_Resultado_Pass ()
{
    char pal1[20] = {"fede"};

    int exp = strlen(pal1);
    int res = m_strlen(pal1);

    it(&exp,&res,sizeof(int), comp_int,"15 - test_Strlen_CantidadDeCuatroElementos_Resultado_Pass");
}

void test_Strcmpi_CadenasVacias_Resultado_Pass ()
{
    char pal1[10] = "FeDeRiCo";
    char pal2[10] = "federico";

    int exp = strcmpi(pal1,pal2);
    int res = m_strcmpi(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"16 - test_Strcmpi_CadenasVacias_Resultado_Pass");
}


void test_Strcmpi_UnaCadenaVacia_Resultado_Pass ()
{
    char pal1[10] = "";
    char pal2[10] = "Federico";

    int exp = strcmpi(pal1,pal2);
    int res = m_strcmpi(pal1,pal2);
    it(&exp,&res,sizeof(int), comp_int,"17 - test_Strcmpi_UnaCadenaVacia_Resultado_Pass");
}


void test_Strcmpi_UnaCadenaMasCorta_Resultado_Pass ()
{
    char pal1[10] = "Fede";
    char pal2[10] = "Federico";

    int exp = strcmpi(pal1,pal2);
    int res = m_strcmpi(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"18 - test_Strcmpi_UnaCadenaMasCorta_Resultado_Pass");

}

void test_Strcmpi_CadenasNumericas_Resultado_Pass ()
{
    char pal1[10] = "0001";
    char pal2[10] = "00010000";

    int exp = strcmpi(pal1,pal2);
    int res = m_strcmpi(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"19 - test_Strcmpi_CadenasNumericas_Resultado_Pass");
}


void test_Strchr_BuscarCaracter_Resultado_Pass ()
{
    char pal1[10] = "0001";

    char * exp = strchr(pal1,'1');
    char * res = m_strchr(pal1,'1');
    it_arr(exp,res,1,sizeof(exp), comp_s,"20 - test_Strchr_BuscarCaracter_Resultado_Pass");
}


void test_Strchr_BuscarCaracterLetraE_Resultado_Pass ()
{
    char pal1[10] = "federico";

    char * exp = strchr(pal1,'e');
    char * res = m_strchr(pal1,'e');
    it_arr(exp,res,1,sizeof(exp), comp_s,"21 - test_Strchr_BuscarCaracterLetraE_Resultado_Pass");
}


void test_Strrchr_BuscarCaracterLetraE_Resultado_Pass ()
{
    char pal1[10] = "federico";

    char * exp = strrchr(pal1,'e');
    char * res = m_strrchr(pal1,'e');

    it_arr(exp,res,1,sizeof(exp), comp_s,"22 - test_Strrchr_BuscarCaracterLetraE_Resultado_Pass");
}


void test_Strncmp_CuartoCaracter_Resultado_Pass ()
{
    char pal1[10] = "fede";
    char pal2[10] = "federico";

    int exp = strncmp(pal1,pal2,4);
    int res = m_strncmp(pal1,pal2,4);

    it(&exp,&res,sizeof(int), comp_int,"23 - test_Strncmp_CuartoCaracter_Resultado_Pass");
}

void test_Strncmp_NIgualACero_Resultado_Pass ()
{
    char pal1[10] = "fede";
    char pal2[10] = "federico";

    int exp = strncmp(pal1,pal2,0);
    int res = m_strncmp(pal1,pal2,0);

    it(&exp,&res,sizeof(int), comp_int,"24 - test_Strncmp_NIgualACero_Resultado_Pass");
}


void test_Strncmp_NNegativo_Resultado_Pass ()
{
    char pal1[10] = "fede";
    char pal2[10] = "federico";

    int exp = strncmp(pal1,pal2,-1);
    int res = m_strncmp(pal1,pal2,-1);

    it(&exp,&res,sizeof(int), comp_int,"25 - test_Strncmp_NNegativo_Resultado_Pass");
}

void test_Strncpy_CadenaUnoMasCorta_Resultado_Pass ()
{
    char pal1[10] = "fede";
    char pal2[10] = "federico";

    char * exp = "federico";
    char * res = m_strncpy(pal1,pal2,15);

    it(exp,res,sizeof(exp), comp_s,"26 - test_Strncpy_CadenaUnoMasCorta_Resultado_Pass");
}


void test_Strncpy_NNegativo_Resultado_Pass ()
{
    char pal1[10] = "fede";
    char pal2[10] = "federico";

    char * exp = "fede";
    char * res = m_strncpy(pal1,pal2,-1);

    it(exp,res,sizeof(exp), comp_s,"27 - test_Strncpy_NNegativo_Resultado_Pass");
}


void test_Strncpy_NCero_Resultado_Pass ()
{
    char pal1[10] = "fede";
    char pal2[10] = "federico";

    char * exp = "";
    char * res = m_strncpy(pal1,pal2,0);

    it(exp,res,sizeof(exp), comp_s,"28 - test_Strncpy_NCero_Resultado_Pass");
}


void test_Strstr_PalabraContenida_Resultado_Pass ()
{
    char pal1[10] = "federico";
    char pal2[10] = "ri";

    char * exp = "rico";
    char * res = m_strstr(pal1,pal2);

    it(exp,res,sizeof(exp), comp_s,"29 - test_Strstr_PalabraContenida_Resultado_Pass");
}


void test_Strstr_SegundaPalabraMasLarga_Resultado_Pass ()
{
    char pal1[10] = "fede";
    char pal2[10] = "federico";

    char * exp = NULL;
    char * res = m_strstr(pal1,pal2);

    it(exp,res,sizeof(exp), comp_s,"30 - test_Strstr_SegundaPalabraMasLarga_Resultado_Pass");
}


void test_Strstr_OcurrenciaAlFinal_Resultado_Pass ()
{
    char pal1[10] = "federico";
    char pal2[10] = "co";

    char * exp = "co";
    char * res = m_strstr(pal1,pal2);

    it(exp,res,sizeof(exp), comp_s,"31 - test_Strstr_OcurrenciaAlFinal_Resultado_Pass");
}


void test_Strstr_OcurrenciaAlPrincipio_Resultado_Pass ()
{
    char pal1[10] = "federico";
    char pal2[10] = "fe";

    char * exp = "federico";
    char * res = m_strstr(pal1,pal2);

    it(exp,res,sizeof(exp), comp_s,"32 - test_Strstr_OcurrenciaAlPrincipio_Resultado_Pass");
}


void test_Strcpn_CuartaLetraDiferente_Resultado_Pass ()
{
    char pal1[10] = "fedr";
    char pal2[10] = "federico";

    int exp = strspn(pal1,pal2);
    int res = m_strspn(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"33 - test_Strcpn_CuartaLetraDiferente_Resultado_Pass");
}


void test_Strcpn_CadenasIguales_Resultado_Pass ()
{
    char pal1[10] = "federico";
    char pal2[10] = "federico";

    int exp = strspn(pal1,pal2);
    int res = m_strspn(pal1,pal2);


    it(&exp,&res,sizeof(int), comp_int,"34 - test_Strcpn_CadenasIguales_Resultado_Pass");
}


void test_Strcpn_CadenasMismoTamDiferenteContenido_Resultado_Pass ()
{
    char pal1[10] = "robertos";
    char pal2[10] = "federico";

    int exp = strspn(pal1,pal2);
    int res = m_strspn(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"35 - test_Strcpn_CadenasMismoTamDiferenteContenido_Resultado_Pass");
}


void test_Strcpn_TestDocumentacion_Resultado_Pass ()
{
    char pal1[10] = "cabbage";
    char pal2[10] = "abc";

    int exp = strspn(pal1,pal2);
    int res = m_strspn(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"36 - test_Strcpn_TestDocumentacion_Resultado_Pass");
}


void test_Strcspn_TestDocumentacion_Resultado_Pass ()
{
    char pal1[10] = "xyzbxz";
    char pal2[10] = "abc";

    int exp = strcspn(pal1,pal2);
    int res = m_strcspn(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"37 - test_Strcspn_TestDocumentacion_Resultado_Pass");
}


void test_Strcspn_TestDocumentacionDos_Resultado_Pass ()
{
    char pal1[10] = "xyzbxz";
    char pal2[10] = "xyz";

    int exp = strcspn(pal1,pal2);
    int res = m_strcspn(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"38 - test_Strcspn_TestDocumentacionDos_Resultado_Pass");
}


void test_Strcspn_TestDocumentacionTres_Resultado_Pass ()
{
    char pal1[10] = "xyzbxz";
    char pal2[10] = "no match";

    int exp = strcspn(pal1,pal2);
    int res = m_strcspn(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"39 - test_Strcspn_TestDocumentacionTres_Resultado_Pass");
}

void test_Strcspn_TestDocumentacionCuatro_Resultado_Pass ()
{
    char pal1[10] = "xyzbxz";
    char pal2[10] = "";

    int exp = strcspn(pal1,pal2);
    int res = m_strcspn(pal1,pal2);

    it(&exp,&res,sizeof(int), comp_int,"40 - test_Strcspn_TestDocumentacionCuatro_Resultado_Pass");
}


void test_Strncat_ConcatenarACadenaVacia_Resultado_Pass ()
{
    char pal1[10] = "";
    char pal2[10] = "xyzbxz";

    char * exp = "xyzbxz";
    char * res = m_strncat(pal1,pal2,15);

    it_arr(exp,res,1,sizeof(exp), comp_s,"41 - test_Strncat_ConcatenarACadenaVacia_Resultado_Pass");
}


void test_Strncat_NNegativo_Resultado_Pass ()
{
    char pal1[10] = "";
    char pal2[10] = "xyzbxz";

    char * exp = "";
    char * res = m_strncat(pal1,pal2,-1);


    it_arr(exp,res,1,sizeof(exp), comp_s,"42 - test_Strncat_NNegativo_Resultado_Pass");
}



void test_Strncat_CadenaDosVacia_Resultado_Pass ()
{
    char pal1[10] = "federico";
    char pal2[10] = "";

    char * exp = "federico";
    char * res = m_strncat(pal1,pal2,10);

    it_arr(exp,res,1,sizeof(exp), comp_s,"43 - test_Strncat_CadenaDosVacia_Resultado_Pass");
}


void test_Strncat_CadenaDosMasGrandeQueElN_Resultado_Pass ()
{
    char pal1[15] = "federico";
    char pal2[10] = " manzano";

    char * exp = "federico ma";
    char * res = m_strncat(pal1,pal2,3);

    it_arr(exp,res,1,sizeof(exp), comp_s,"44 - test_Strncat_CadenaDosMasGrandeQueElN_Resultado_Pass");
}


void test_FormatTitle_FormatoTituloCadenaIrregular_Resultado_Pass ()
{
    char pal1[100] = "     cUENTA   lA   HISTORIA   que    uN    Dia En   Su BOsque EnCANTADO" ;

    char * exp = "Cuenta La Historia Que Un Dia En Su Bosque Encantado";
    char * res = m_format_title(pal1);

    it_arr(exp,res,1,sizeof(exp), comp_s,"45 - test_FormatTitle_FormatoTituloCadenaIrregular_Resultado_Pass");
}


void test_FormatTitle_CadenaSoloEspacios_Resultado_Pass ()
{
    char pal1[100] = "                                    " ;

    char * exp = "";
    char * res = m_format_title(pal1);

    it_arr(exp,res,1,sizeof(exp), comp_s,"46 - test_FormatTitle_CadenaSoloEspacios_Resultado_Pass");
}


void test_FormatTitle_CadenaConNumeros_Resultado_Pass ()
{
    char pal1[100] = "123456789" ;

    char * exp = "123456789";
    char * res = m_format_title(pal1);

    it_arr(exp,res,1,sizeof(exp), comp_s,"47 - test_FormatTitle_CadenaConNumeros_Resultado_Pass");
}


void test_FormatTitle_CadenaTodoMinusculas_Resultado_Pass ()
{
    char pal1[100] = "esto es una cadena en minusculas" ;

    char * exp = "Esto Es Una Cadena En Minusculas";
    char * res = m_format_title(pal1);

    it_arr(exp,res,1,sizeof(exp), comp_s,"48 - test_FormatTitle_CadenaTodoMinusculas_Resultado_Pass");
}


void test_FormatTitle_CadenaTodoMayusculas_Resultado_Pass ()
{
    char pal1[100] = "ESTO ES UNA CADENA EN MAYUSCULAS" ;

    char * exp = "Esto Es Una Cadena En Mayusculas";
    char * res = m_format_title(pal1);

    it_arr(exp,res,1,sizeof(exp), comp_s,"49 - test_FormatTitle_CadenaTodoMayusculas_Resultado_Pass");
}


void test_FormatTitle_CadenaAlfaNumerica_Resultado_Pass ()
{
    char pal1[100] = "1  2  2 con numeros y letras 55 4   " ;

    char * exp = "1 2 2 Con Numeros Y Letras 55 4";
    char * res = m_format_title(pal1);

    it_arr(exp,res,1,sizeof(exp), comp_s,"50 - test_FormatTitle_CadenaAlfaNumerica_Resultado_Pass");
}

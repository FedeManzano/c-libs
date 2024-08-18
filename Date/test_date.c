#include <stdio.h>
#include <stdlib.h>
#include "./date.h"
#include "../bundle/it.h"


int comp_integer(const void * e1,const void *e2 ){
    int * ele1 = (int *)e1;
    int * ele2 = (int *)e2;
    return *ele1 - *ele2;
}

int comp_string(const void * e1,const void *e2 ){
    char * ele1 = (char *)e1;
    char * ele2 = (char *)e2;
    return strcmp(ele1,ele2);
}

void test_ValidarFechaDiaMalo_ResultadoPASS(){
    t_date f1 = {30,2,2024};
    int expected = DATE_ERROR;
    int result = val_date(f1.d,f1.m,f1.y);
    it(&expected,&result,sizeof(int),comp_integer,"1 - test_ValidarFechaDiaMalo_ResultadoPASS");
}

void test_ValidarFechaMes_ResultadoPASS(){
    t_date f1 = {30,13,2024};
    int expected = DATE_ERROR;
    int result = val_date(f1.d,f1.m,f1.y);
    it(&expected,&result,sizeof(int),comp_integer,"2 - test_ValidarFechaMes_ResultadoPASS");
}

void test_ValidarFechaAnoMalo_ResultadoPASS(){
    t_date f1 = {30,12,1599};

    int expected = DATE_ERROR;
    int result = val_date(f1.d,f1.m,f1.y);
    it(&expected,&result,sizeof(int),comp_integer,"3 - test_ValidarFechaAnoMalo_ResultadoPASS");
}

void test_CompFechasIguales_ResultadoPASS(){
    t_date expected =   {30,12,2013};
    t_date result =     {30,12,2013};
    it(&expected,&result,sizeof(t_date),comp_date,"4 - test_CompFechasIguales_ResultadoPASS");
}

void test_CompFechasConValoresNulos_ResultadoPASS(){
    int expected = DATE_ERROR;
    int result = comp_date(NULL,NULL);
    it(&expected,&result,sizeof(int),comp_integer,"5 - test_CompFechasConValoresNulos_ResultadoPASS");
}

void test_CompFechasConUnValorNull_ResultadoPASS(){
    t_date f = {1,1,2013};
    int expected = DATE_ERROR;
    int result = comp_date(&f,NULL);
    it(&expected,&result,sizeof(int),comp_integer,"6 - test_CompFechasConUnValorNull_ResultadoPASS");
}

void test_CompFechasConMismoMesMismoAno_ResultadoPASS(){

    t_date f = {1,1,2013};
    t_date f2 = {10,1,2013};
    int expected = -1;
    int result = comp_date(&f,&f2);

    it(&expected,&result,sizeof(int),comp_integer,"7 - test_CompFechasConMismoMesMismoAno_ResultadoPASS");
}

void test_CompFechasConMismoMesMismoDia_ResultadoPASS(){
    t_date f = {1,1,2013};
    t_date f2 = {1,10,2013};
    int expected = -1;
    int result = comp_date(&f,&f2);
    it(&expected,&result,sizeof(int),comp_integer,"8 - test_CompFechasConMismoMesMismoDia_ResultadoPASS");
}

void test_ObtenerDiasDelMesBisiesto29Febrero_ResultadoPASS(){
    int expected = 29;
    int result = days_of_month(2024,2);
    it(&expected,&result,sizeof(int),comp_integer,"9 - test_ObtenerDiasDelMesBisiesto29Febrero_ResultadoPASS");
}

void test_ObtenerDiasDelMesBisiesto31Enero_ResultadoPASS(){
    int expected = 31;
    int result = days_of_month(2024,1);
    it(&expected,&result,sizeof(int),comp_integer,"10 - test_ObtenerDiasDelMesBisiesto31Enero_ResultadoPASS");
}

void test_ObtenerDiasDelMenorA1600_ResultadoPASS(){
    int expected = DATE_ERROR;
    int result = days_of_month(1599,1);
    it(&expected,&result,sizeof(int),comp_integer,"11 - test_ObtenerDiasDelMenorA1600_ResultadoPASS");
}

void test_ObtenerDiasDelMesMesMenorQue1_ResultadoPASS(){
    int expected = DATE_ERROR;
    int result = days_of_month(2013,0);
    it(&expected,&result,sizeof(int),comp_integer,"12 - test_ObtenerDiasDelMesMesMenorQue1_ResultadoPASS");
}

void test_ObtenerDiasDelMesMesMayorQue12_ResultadoPASS(){
    int expected = DATE_ERROR;
    int result = days_of_month(2013,13);
    it(&expected,&result,sizeof(int),comp_integer,"13 - test_ObtenerDiasDelMesMesMayorQue12_ResultadoPASS");
}

void test_ComprobarSiEsBisiestoUnAno_ResultadoPASS(){
    int expected = DATE_ERROR;
    int result = leap(1599);
    it(&expected,&result,sizeof(int),comp_integer,"14 - test_ComprobarSiEsBisiestoUnAno_ResultadoPASS");
}

void test_ComprobarSiEsBisiestoUnAnoValido_ResultadoPASS(){
    int expected = 0;
    int result = leap(2013);
    it(&expected,&result,sizeof(int),comp_integer,"15 - test_ComprobarSiEsBisiestoUnAnoValido_ResultadoPASS");
}

void test_ComprobarSiEsBisiestoUnAnoBisiesto_ResultadoPASS(){
    int expected = 1;
    int result = leap(2024);
    it(&expected,&result,sizeof(int),comp_integer,"16 - test_ComprobarSiEsBisiestoUnAnoBisiesto_ResultadoPASS");
}

void test_DiferenciaEntreFechasFechasNulas_ResultadoPASS(){
    int expected = DATE_ERROR;
    int result = difference_days(NULL,NULL);
    it(&expected,&result,sizeof(int),comp_integer,"17 - test_DiferenciaEntreFechasFechasNulas_ResultadoPASS");
}

void test_DiferenciaEntreFechasFechasInvalidas_ResultadoPASS(){
    t_date f1 = {29,2,2023}; // Invalida
    t_date f2 = {30,1,2013}; // Valida
    int expected = DATE_ERROR;
    int result = difference_days(&f1,&f2);
    it(&expected,&result,sizeof(int),comp_integer,"18 - test_DiferenciaEntreFechasFechasInvalidas_ResultadoPASS");
}

void test_DiferenciaEntreFechas30DiasDeDiferencia_ResultadoPASS(){
    t_date f1 = {1,1,2023};
    t_date f2 = {1,2,2023};
    int expected = 31;
    int result = difference_days(&f1,&f2);
    it(&expected,&result,sizeof(int),comp_integer,"19 - test_DiferenciaEntreFechas30DiasDeDiferencia_ResultadoPASS");
}

void test_DiferenciaEntreFechas30DiasDeAlReves_ResultadoPASS(){
    t_date f1 = {1,1,2023};
    t_date f2 = {1,2,2023};
    int expected = 31;
    int result = difference_days(&f2,&f1);
    it(&expected,&result,sizeof(int),comp_integer,"20 - test_DiferenciaEntreFechas30DiasDeAlReves_ResultadoPASS");
}

void test_AgregarUnDiaAunaFecha_ResultadoPASS(){
    t_date expected = {1,1,2024};
    t_date result = {31,12,2023};
    result = *add_day(&result);
    it(&expected,&result,sizeof(t_date),comp_date,"21 - test_AgregarUnDiaAunaFecha_ResultadoPASS");
}

void test_RestarUnDiaAUnaFecha_ResultadoPASS(){
    t_date expected = {31,12,2023};
    t_date result = {1,1,2024};
    result = *subtract_day(&result);
    it(&expected,&result,sizeof(t_date),comp_date,"22 - test_RestarUnDiaAUnaFecha_ResultadoPASS");
}

void test_AgregarNDiasAUnaFecha_ResultadoPASS(){
    t_date expected = {29,2,2024};
    t_date result = {31,1,2024};
    result = *add_days(&result, 29);
    it(&expected,&result,sizeof(t_date),comp_date,"23 - test_AgregarNDiasAUnaFecha_ResultadoPASS");
}

void test_RestarNDiasAUnaFecha_ResultadoPASS(){
    t_date expected = {1,1,2022};
    t_date result = {1,1,2024};
    result = *add_days(&result, -365*2);
    it(&expected,&result,sizeof(t_date),comp_date,"24 - test_RestarNDiasAUnaFecha_ResultadoPASS");
}

void test_Restar10DiasAUnaFecha_ResultadoPASS(){
    t_date expected = {22,12,2023};
    t_date result = {1,1,2024};
    result = *add_days(&result, -10);
    it(&expected,&result,sizeof(t_date),comp_date,"25 - test_Restar10DiasAUnaFecha_ResultadoPASS");
}

void test_ToStringFormato1_ResultadoPASS(){

    t_date f = {10,10,2024};
    char expected[20] = {"10/10/2024"};
    char * result = date_to_string(&f,dd_MM_yyyy);
    it(expected,result,sizeof(char),comp_string,"26 - test_ToStringFormato1_ResultadoPASS");
}

void test_ToStringFormato2_ResultadoPASS(){

    t_date f = {1,1,2024};
    char expected[20] = {"2024/01/01"};
    char * result = date_to_string(&f,yyyy_MM_dd);

    it(expected,result,sizeof(char),comp_string,"27 - test_ToStringFormato2_ResultadoPASS");
}

void test_ToStringFormato3_ResultadoPASS(){
    t_date f = {1,1,2024};
    char expected[30] = {"Dia 01 de Enero del 2024."};
    char * result = date_to_string(&f,DESCRIPTIVE);
    it(expected,result,sizeof(char),comp_string,"28 - test_ToStringFormato3_ResultadoPASS");
}

void test_ToStringFormato4_ResultadoPASS(){
    t_date f = {1,1,2024};
    char expected[30] = {"Enero 01 del 2024."};
    char * result = date_to_string(&f,DESCRIPTIVE_2);
    it(expected,result,sizeof(char),comp_string,"29 - test_ToStringFormato4_ResultadoPASS");
}

void test_ToStringFormato5_ResultadoPASS(){
    t_date f = {3,1,1987};
    char expected[30] = {"Sabado 03 de Enero del 1987."};
    char * result = date_to_string(&f,DESCRIPTIVE_3);
    it(expected,result,sizeof(char),comp_string,"30 - test_ToStringFormato5_ResultadoPASS");
}

void test_ToStringFormato5OtraFecha_ResultadoPASS(){
    t_date f = {2,8,2024};
    char expected[30] = {"Viernes 02 de Agosto del 2024."};
    char * result = date_to_string(&f,DESCRIPTIVE_3);
    it(expected,result,sizeof(char),comp_string,"31 - test_ToStringFormato5OtraFecha_ResultadoPASS");
}

void test_CompTimeConFechaYTiempoCorrecto_ResultadoPASS(){
    t_date t1 = {1,8,2024,11,50,30};
    t_date t2 = {1,8,2024,11,50,30};
    int expected = 0;
    int result = comp_time(&t1,&t2);
    it(&expected,&result,sizeof(int),comp_integer,"32 - test_CompTimeConFechaYTiempoCorrecto_ResultadoPASS");
}

void test_CompTimeConFechaIgualadaYHoraDiferente_ResultadoPASS(){
    t_date t1 = {1,8,2024,10,50,30};
    t_date t2 = {1,8,2024,11,50,30};
    int expected = -1;
    int result = comp_time(&t1,&t2);
    it(&expected,&result,sizeof(int),comp_integer,"33 - test_CompTimeConFechaIgualadaYHoraDiferente_ResultadoPASS");
}

void test_CompTimeConFechaIgualadaYHoraDiferenteMayor_ResultadoPASS(){
    t_date t1 = {1,8,2024,12,50,30};
    t_date t2 = {1,8,2024,11,50,30};
    int expected = 1;
    int result = comp_time(&t1,&t2);
    it(&expected,&result,sizeof(int),comp_integer,"34 - test_CompTimeConFechaIgualadaYHoraDiferenteMayor_ResultadoPASS");
}

void test_CompTimeConFechaIgualadaYMinutosDiferenteMayor_ResultadoPASS(){
    t_date t1 = {1,8,2024,11,51,30};
    t_date t2 = {1,8,2024,11,50,30};
    int expected = 1;
    int result = comp_time(&t1,&t2);
    it(&expected,&result,sizeof(int),comp_integer,"35 - test_CompTimeConFechaIgualadaYMinutosDiferenteMayor_ResultadoPASS");
}

void test_CompTimeConFechaIgualadaYMinutosDiferenteMenor_ResultadoPASS(){
    t_date t1 = {1,8,2024,11,49,30};
    t_date t2 = {1,8,2024,11,50,30};
    int expected = -1;
    int result = comp_time(&t1,&t2);
    it(&expected,&result,sizeof(int),comp_integer,"36 - test_CompTimeConFechaIgualadaYMinutosDiferenteMenor_ResultadoPASS");
}

void test_AgregarUnaHoraAUnDateLimite_ResultadoPASS(){
    t_date expected = {1,1,2024,00,00,00};
    t_date result = {31,12,2023,23,00,00};
    result = *add_hour(&result);
    it(&expected,&result,sizeof(t_date),comp_time,"37 - test_AgregarUnaHoraAUnDateLimite_ResultadoPASS");
}

void test_AgregarUnaHoraAUnDateNoLimite_ResultadoPASS(){
    t_date expected = {3,8,2024,01,00,00};
    t_date result = {3,8,2024,0,00,00};
    result = *add_hour(&result);
    it(&expected,&result,sizeof(t_date),comp_time,"38 - test_AgregarUnaHoraAUnDateNoLimite_ResultadoPASS");
}

void test_SustraerUnaHoraALaFechaLimite_ResultadoPASS(){
    t_date expected = {31,12,2023,23,00,00};
    t_date result = {1,1,2024,0,00,00};
    result = *subtract_hour(&result);
    it(&expected,&result,sizeof(t_date),comp_time,"39 - test_SustraerUnaHoraALaFechaLimite_ResultadoPASS");
}

void test_SustraerUnaHoraALaFechaNoLimite_ResultadoPASS(){
    t_date expected = {1,1,2024,00,00,00};
    t_date result = {1,1,2024,1,00,00};
    result = *subtract_hour(&result);
    it(&expected,&result,sizeof(t_date),comp_time,"40 - test_SustraerUnaHoraALaFechaNoLimite_ResultadoPASS");
}

void test_AgregarVariasHorasAUnaFechaLimite_ResultadoPASS(){
    t_date expected = {1,1,2024,5,00,00};
    t_date result = {30,12,2023,0,00,00};
    result = *add_hours(&result,53);
    it(&expected,&result,sizeof(t_date),comp_time,"41 - test_AgregarVariasHorasAUnaFechaLimite_ResultadoPASS");
}

void test_SustraerVariasHorasAUnaFechaLimite_ResultadoPASS(){
    t_date expected = {30,12,2023,0,00,00};
    t_date result = {1,1,2024,5,00,00};
    result = *add_hours(&result,-53);
    it(&expected,&result,sizeof(t_date),comp_time,"42 - test_SustraerVariasHorasAUnaFechaLimite_ResultadoPASS");
}

void test_AgregarInMinutoAUnaFechaLimite_ResultadoPASS(){
    t_date expected = {1,1,2024,0,00,00};
    t_date result = {31,12,2023,23,59,00};
    result = *add_minute(&result);
    it(&expected,&result,sizeof(t_date),comp_time,"43 - test_AgregarInMinutoAUnaFechaLimite_ResultadoPASS");
}

void test_SustraerUnMinutoAUnaFechaLimite_ResultadoPASS(){
    t_date expected = {31,12,2023,23,59,00};
    t_date result = {1,1,2024,0,00,00};
    result = *subtract_minute(&result);
    it(&expected,&result,sizeof(t_date),comp_time,"44 - test_SustraerUnMinutoAUnaFechaLimite_ResultadoPASS");
}

void test_AgregarNMinutoAUnaFechaLimite_ResultadoPASS(){
    t_date expected = {1,1,2024,0,00,00};
    t_date result = {31,12,2023,23,55,00};
    result = *add_minutes(&result,5);
    it(&expected,&result,sizeof(t_date),comp_time,"45 - test_AgregarNMinutoAUnaFechaLimite_ResultadoPASS");
}

void test_AgregarNSegundosAUnaFechaLimite_ResultadoPASS(){
    t_date expected = {1,1,2024,0,00,00};
    t_date result = {31,12,2023,23,58,00};
    result = *add_seconds(&result,120);
    it(&expected,&result,sizeof(t_date),comp_time,"46 - test_AgregarNSegundosAUnaFechaLimite_ResultadoPASS");
}

void test_Agregar3600SegundosAUnaFechaLimite_ResultadoPASS(){
    t_date expected = {1,1,2024,0,00,00};
    t_date result = {31,12,2023,23,00,00};
    result = *add_seconds(&result,3600);
    it(&expected,&result,sizeof(t_date),comp_time,"47 - test_Agregar3600SegundosAUnaFechaLimite_ResultadoPASS");
}

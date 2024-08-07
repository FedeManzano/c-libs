#ifndef TEST_DATE_H_INCLUDED
#define TEST_DATE_H_INCLUDED

#include <pointerFn.h>


void test_ValidarFechaDiaMalo_ResultadoPASS();
void test_ValidarFechaMes_ResultadoPASS();
void test_ValidarFechaAnoMalo_ResultadoPASS();
void test_CompFechasIguales_ResultadoPASS();
void test_CompFechasConValoresNulos_ResultadoPASS();
void test_CompFechasConUnValorNull_ResultadoPASS();
void test_CompFechasConMismoMesMismoAno_ResultadoPASS();
void test_CompFechasConMismoMesMismoDia_ResultadoPASS();
void test_ObtenerDiasDelMesBisiesto29Febrero_ResultadoPASS();
void test_ObtenerDiasDelMesBisiesto31Enero_ResultadoPASS();
void test_ObtenerDiasDelMenorA1600_ResultadoPASS();
void test_ObtenerDiasDelMesMesMenorQue1_ResultadoPASS();
void test_ObtenerDiasDelMesMesMayorQue12_ResultadoPASS();
void test_ComprobarSiEsBisiestoUnAno_ResultadoPASS();
void test_ComprobarSiEsBisiestoUnAnoValido_ResultadoPASS();
void test_ComprobarSiEsBisiestoUnAnoBisiesto_ResultadoPASS();
void test_DiferenciaEntreFechasFechasNulas_ResultadoPASS();
void test_DiferenciaEntreFechasFechasInvalidas_ResultadoPASS();
void test_DiferenciaEntreFechas30DiasDeDiferencia_ResultadoPASS();
void test_DiferenciaEntreFechas30DiasDeAlReves_ResultadoPASS();
void test_AgregarUnDiaAunaFecha_ResultadoPASS();
void test_RestarUnDiaAUnaFecha_ResultadoPASS();
void test_AgregarNDiasAUnaFecha_ResultadoPASS();
void test_RestarNDiasAUnaFecha_ResultadoPASS();
void test_Restar10DiasAUnaFecha_ResultadoPASS();
void test_ToStringFormato1_ResultadoPASS();
void test_ToStringFormato2_ResultadoPASS();
void test_ToStringFormato3_ResultadoPASS();
void test_ToStringFormato4_ResultadoPASS();
void test_ToStringFormato5_ResultadoPASS();
void test_ToStringFormato5OtraFecha_ResultadoPASS();
void test_CompTimeConFechaYTiempoCorrecto_ResultadoPASS();
void test_CompTimeConFechaIgualadaYHoraDiferente_ResultadoPASS();
void test_CompTimeConFechaIgualadaYHoraDiferenteMayor_ResultadoPASS();
void test_CompTimeConFechaIgualadaYMinutosDiferenteMayor_ResultadoPASS();
void test_CompTimeConFechaIgualadaYMinutosDiferenteMenor_ResultadoPASS();
void test_AgregarUnaHoraAUnDateLimite_ResultadoPASS();
void test_AgregarUnaHoraAUnDateNoLimite_ResultadoPASS();
void test_SustraerUnaHoraALaFechaLimite_ResultadoPASS();
void test_SustraerUnaHoraALaFechaNoLimite_ResultadoPASS();
void test_AgregarVariasHorasAUnaFechaLimite_ResultadoPASS();
void test_SustraerVariasHorasAUnaFechaLimite_ResultadoPASS();
void test_AgregarInMinutoAUnaFechaLimite_ResultadoPASS();
void test_SustraerUnMinutoAUnaFechaLimite_ResultadoPASS();
void test_AgregarNMinutoAUnaFechaLimite_ResultadoPASS();
void test_AgregarNSegundosAUnaFechaLimite_ResultadoPASS();
void test_Agregar3600SegundosAUnaFechaLimite_ResultadoPASS();

#endif // TEST_DATE_H_INCLUDED

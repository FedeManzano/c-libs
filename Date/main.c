#include <stdio.h>
#include <stdlib.h>
#include "./date.h"
#include "test_date.h"


int main()
{
    test_ValidarFechaDiaMalo_ResultadoPASS();
    test_ValidarFechaMes_ResultadoPASS();
    test_ValidarFechaAnoMalo_ResultadoPASS();
    test_CompFechasIguales_ResultadoPASS();
    test_CompFechasConValoresNulos_ResultadoPASS();
    test_CompFechasConUnValorNull_ResultadoPASS();
    test_CompFechasConMismoMesMismoAno_ResultadoPASS();
    test_CompFechasConMismoMesMismoDia_ResultadoPASS();
    test_ObtenerDiasDelMesBisiesto29Febrero_ResultadoPASS();
    test_ObtenerDiasDelMesBisiesto31Enero_ResultadoPASS();
    test_ObtenerDiasDelMenorA1600_ResultadoPASS();
    test_ObtenerDiasDelMesMesMenorQue1_ResultadoPASS();
    test_ObtenerDiasDelMesMesMayorQue12_ResultadoPASS();
    test_ComprobarSiEsBisiestoUnAno_ResultadoPASS();
    test_ComprobarSiEsBisiestoUnAnoValido_ResultadoPASS();
    test_ComprobarSiEsBisiestoUnAnoBisiesto_ResultadoPASS();
    test_DiferenciaEntreFechasFechasNulas_ResultadoPASS();
    test_DiferenciaEntreFechasFechasInvalidas_ResultadoPASS();
    test_DiferenciaEntreFechas30DiasDeDiferencia_ResultadoPASS();
    test_DiferenciaEntreFechas30DiasDeAlReves_ResultadoPASS();
    test_AgregarUnDiaAunaFecha_ResultadoPASS();
    test_RestarUnDiaAUnaFecha_ResultadoPASS();
    test_AgregarNDiasAUnaFecha_ResultadoPASS();
    test_RestarNDiasAUnaFecha_ResultadoPASS();
    test_Restar10DiasAUnaFecha_ResultadoPASS();
    test_ToStringFormato1_ResultadoPASS();
    test_ToStringFormato2_ResultadoPASS();
    test_ToStringFormato3_ResultadoPASS();
    test_ToStringFormato4_ResultadoPASS();
    test_ToStringFormato5_ResultadoPASS();
    test_ToStringFormato5OtraFecha_ResultadoPASS();
    test_CompTimeConFechaYTiempoCorrecto_ResultadoPASS();
    test_CompTimeConFechaIgualadaYHoraDiferente_ResultadoPASS();
    test_CompTimeConFechaIgualadaYHoraDiferenteMayor_ResultadoPASS();
    test_CompTimeConFechaIgualadaYMinutosDiferenteMayor_ResultadoPASS();
    test_CompTimeConFechaIgualadaYMinutosDiferenteMenor_ResultadoPASS();
    test_AgregarUnaHoraAUnDateLimite_ResultadoPASS();
    test_AgregarUnaHoraAUnDateNoLimite_ResultadoPASS();
    test_SustraerUnaHoraALaFechaLimite_ResultadoPASS();
    test_SustraerUnaHoraALaFechaNoLimite_ResultadoPASS();
    test_AgregarVariasHorasAUnaFechaLimite_ResultadoPASS();
    test_SustraerVariasHorasAUnaFechaLimite_ResultadoPASS();
    test_AgregarInMinutoAUnaFechaLimite_ResultadoPASS();
    test_SustraerUnMinutoAUnaFechaLimite_ResultadoPASS();
    test_AgregarNMinutoAUnaFechaLimite_ResultadoPASS();
    test_AgregarNSegundosAUnaFechaLimite_ResultadoPASS();
    test_Agregar3600SegundosAUnaFechaLimite_ResultadoPASS();

    return 0;
}

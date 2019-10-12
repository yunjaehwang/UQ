/* Initialization */
#include "OM_Result_model.h"
#include "OM_Result_11mix.h"
#include "OM_Result_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void OM_Result_functionInitialEquations_0(DATA *data, threadData_t *threadData);


/*
 equation index: 1
 type: SIMPLE_ASSIGN
 Temperature_Indoor._port._Q_flow = 0.0
 */
void OM_Result_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  data->localData[0]->realVars[109] /* Temperature_Indoor._port._Q_flow variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 2
 type: SIMPLE_ASSIGN
 two_single_ventilation1._Indoor_temperature._port._Q_flow = 0.0
 */
void OM_Result_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  data->localData[0]->realVars[121] /* two_single_ventilation1._Indoor_temperature._port._Q_flow variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 3
 type: SIMPLE_ASSIGN
 Data_solar_radiation._timeScaled = 0.01666666666666667 * time
 */
void OM_Result_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  data->localData[0]->realVars[76] /* Data_solar_radiation._timeScaled variable */ = (0.01666666666666667) * (data->localData[0]->timeValue);
  TRACE_POP
}

/*
 equation index: 4
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._timeScaled = 0.01666666666666667 * time
 */
void OM_Result_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  data->localData[0]->realVars[73] /* Data_outdoor_temperature._timeScaled variable */ = (0.01666666666666667) * (data->localData[0]->timeValue);
  TRACE_POP
}

/*
 equation index: 5
 type: SIMPLE_ASSIGN
 Data_wind_speed._timeScaled = 0.01666666666666667 * time
 */
void OM_Result_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  data->localData[0]->realVars[79] /* Data_wind_speed._timeScaled variable */ = (0.01666666666666667) * (data->localData[0]->timeValue);
  TRACE_POP
}

/*
 equation index: 6
 type: SIMPLE_ASSIGN
 Data_wind_speed._nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Data_wind_speed.tableID, Data_wind_speed.timeScaled)
 */
void OM_Result_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  data->localData[0]->realVars[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */ = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, data->simulationInfo->extObjs[2], data->localData[0]->realVars[79] /* Data_wind_speed._timeScaled variable */);
  TRACE_POP
}

/*
 equation index: 7
 type: SIMPLE_ASSIGN
 Data_wind_speed._nextTimeEvent = if Data_wind_speed.nextTimeEventScaled < 9.999999999999999e+59 then Data_wind_speed.nextTimeEventScaled * 60.0 else 9.999999999999999e+59
 */
void OM_Result_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  modelica_boolean tmp0;
  tmp0 = Less(data->localData[0]->realVars[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */,9.999999999999999e+59);
  data->localData[0]->realVars[139] /* Data_wind_speed._nextTimeEvent DISCRETE */ = (tmp0?(data->localData[0]->realVars[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */) * (60.0):9.999999999999999e+59);
  TRACE_POP
}

/*
 equation index: 8
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Data_outdoor_temperature.tableID, Data_outdoor_temperature.timeScaled)
 */
void OM_Result_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  data->localData[0]->realVars[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */ = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, data->simulationInfo->extObjs[0], data->localData[0]->realVars[73] /* Data_outdoor_temperature._timeScaled variable */);
  TRACE_POP
}

/*
 equation index: 9
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._nextTimeEvent = if Data_outdoor_temperature.nextTimeEventScaled < 9.999999999999999e+59 then Data_outdoor_temperature.nextTimeEventScaled * 60.0 else 9.999999999999999e+59
 */
void OM_Result_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  modelica_boolean tmp1;
  tmp1 = Less(data->localData[0]->realVars[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */,9.999999999999999e+59);
  data->localData[0]->realVars[135] /* Data_outdoor_temperature._nextTimeEvent DISCRETE */ = (tmp1?(data->localData[0]->realVars[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */) * (60.0):9.999999999999999e+59);
  TRACE_POP
}

/*
 equation index: 10
 type: SIMPLE_ASSIGN
 Data_solar_radiation._nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Data_solar_radiation.tableID, Data_solar_radiation.timeScaled)
 */
void OM_Result_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  data->localData[0]->realVars[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */ = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, data->simulationInfo->extObjs[1], data->localData[0]->realVars[76] /* Data_solar_radiation._timeScaled variable */);
  TRACE_POP
}

/*
 equation index: 11
 type: SIMPLE_ASSIGN
 Data_solar_radiation._nextTimeEvent = if Data_solar_radiation.nextTimeEventScaled < 9.999999999999999e+59 then Data_solar_radiation.nextTimeEventScaled * 60.0 else 9.999999999999999e+59
 */
void OM_Result_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  modelica_boolean tmp2;
  tmp2 = Less(data->localData[0]->realVars[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */,9.999999999999999e+59);
  data->localData[0]->realVars[137] /* Data_solar_radiation._nextTimeEvent DISCRETE */ = (tmp2?(data->localData[0]->realVars[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */) * (60.0):9.999999999999999e+59);
  TRACE_POP
}

/*
 equation index: 12
 type: SIMPLE_ASSIGN
 Capacitor_roof._T = $START.Capacitor_roof.T
 */
void OM_Result_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */ = data->modelData->realVarsData[1].attribute /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */.start;
  TRACE_POP
}

/*
 equation index: 13
 type: SIMPLE_ASSIGN
 Capacitor_wall1._T = $START.Capacitor_wall1.T
 */
void OM_Result_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */ = data->modelData->realVarsData[2].attribute /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */.start;
  TRACE_POP
}

/*
 equation index: 14
 type: SIMPLE_ASSIGN
 Capacitor_wall3._T = $START.Capacitor_wall3.T
 */
void OM_Result_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */ = data->modelData->realVarsData[3].attribute /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */.start;
  TRACE_POP
}

/*
 equation index: 15
 type: SIMPLE_ASSIGN
 Capacitor_wall4._T = $START.Capacitor_wall4.T
 */
void OM_Result_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */ = data->modelData->realVarsData[4].attribute /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */.start;
  TRACE_POP
}

/*
 equation index: 16
 type: SIMPLE_ASSIGN
 Capacitor_indoor_air._T = $START.Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */ = data->modelData->realVarsData[0].attribute /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */.start;
  TRACE_POP
}

/*
 equation index: 17
 type: SIMPLE_ASSIGN
 Radiation_floor._dT = Floor_temperature.k - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  data->localData[0]->realVars[88] /* Radiation_floor._dT variable */ = data->simulationInfo->realParameter[54] - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}

/*
 equation index: 18
 type: SIMPLE_ASSIGN
 Radiation_floor._Q_flow = 5.670367e-08 * Radiation_floor.Gr * (Floor_temperature.k ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  modelica_real tmp3;
  modelica_real tmp4;
  tmp3 = data->simulationInfo->realParameter[54];
  tmp3 *= tmp3;tmp4 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp4 *= tmp4;
  data->localData[0]->realVars[87] /* Radiation_floor._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[60]) * ((tmp3 * tmp3) - ((tmp4 * tmp4))));
  TRACE_POP
}

/*
 equation index: 19
 type: SIMPLE_ASSIGN
 Convection_floor._dT = Floor_temperature.k - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  data->localData[0]->realVars[52] /* Convection_floor._dT variable */ = data->simulationInfo->realParameter[54] - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}

/*
 equation index: 20
 type: SIMPLE_ASSIGN
 Convection_floor._Q_flow = Convection_coef_floor.k * Convection_floor.dT
 */
void OM_Result_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  data->localData[0]->realVars[51] /* Convection_floor._Q_flow variable */ = (data->simulationInfo->realParameter[19]) * (data->localData[0]->realVars[52] /* Convection_floor._dT variable */);
  TRACE_POP
}

void OM_Result_eqFunction_21(DATA*,threadData_t*);
void OM_Result_eqFunction_22(DATA*,threadData_t*);
void OM_Result_eqFunction_23(DATA*,threadData_t*);
void OM_Result_eqFunction_24(DATA*,threadData_t*);
void OM_Result_eqFunction_25(DATA*,threadData_t*);
void OM_Result_eqFunction_26(DATA*,threadData_t*);
/*
 equation index: 32
 indexNonlinear: 0
 type: NONLINEAR
 
 vars: {Conduction_wall4_inner._port_b._T}
 eqns: {21, 22, 23, 24, 25, 26}
 */
void OM_Result_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 32 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[0] = data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 0);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,32};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 32 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */ = data->simulationInfo->nonlinearSystemData[0].nlsx[0];
  TRACE_POP
}

/*
 equation index: 33
 type: SIMPLE_ASSIGN
 Radiation_wall4_inner._dT = Conduction_wall4_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  data->localData[0]->realVars[104] /* Radiation_wall4_inner._dT variable */ = data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}

void OM_Result_eqFunction_34(DATA*,threadData_t*);
void OM_Result_eqFunction_35(DATA*,threadData_t*);
void OM_Result_eqFunction_36(DATA*,threadData_t*);
void OM_Result_eqFunction_37(DATA*,threadData_t*);
void OM_Result_eqFunction_38(DATA*,threadData_t*);
void OM_Result_eqFunction_39(DATA*,threadData_t*);
/*
 equation index: 45
 indexNonlinear: 1
 type: NONLINEAR
 
 vars: {Conduction_wall3_inner._port_b._T}
 eqns: {34, 35, 36, 37, 38, 39}
 */
void OM_Result_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 45 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[1].nlsxOld[0] = data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 1);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,45};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 45 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */ = data->simulationInfo->nonlinearSystemData[1].nlsx[0];
  TRACE_POP
}

/*
 equation index: 46
 type: SIMPLE_ASSIGN
 Radiation_wall3_inner._dT = Conduction_wall3_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
  data->localData[0]->realVars[100] /* Radiation_wall3_inner._dT variable */ = data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}

void OM_Result_eqFunction_47(DATA*,threadData_t*);
void OM_Result_eqFunction_48(DATA*,threadData_t*);
void OM_Result_eqFunction_49(DATA*,threadData_t*);
void OM_Result_eqFunction_50(DATA*,threadData_t*);
void OM_Result_eqFunction_51(DATA*,threadData_t*);
void OM_Result_eqFunction_52(DATA*,threadData_t*);
/*
 equation index: 58
 indexNonlinear: 2
 type: NONLINEAR
 
 vars: {Conduction_wall1_inner._port_b._T}
 eqns: {47, 48, 49, 50, 51, 52}
 */
void OM_Result_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 58 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[2].nlsxOld[0] = data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 2);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,58};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 58 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */ = data->simulationInfo->nonlinearSystemData[2].nlsx[0];
  TRACE_POP
}

/*
 equation index: 59
 type: SIMPLE_ASSIGN
 Radiation_wall1_inner._dT = Conduction_wall1_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
  data->localData[0]->realVars[96] /* Radiation_wall1_inner._dT variable */ = data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}

void OM_Result_eqFunction_60(DATA*,threadData_t*);
void OM_Result_eqFunction_61(DATA*,threadData_t*);
void OM_Result_eqFunction_62(DATA*,threadData_t*);
void OM_Result_eqFunction_63(DATA*,threadData_t*);
void OM_Result_eqFunction_64(DATA*,threadData_t*);
void OM_Result_eqFunction_65(DATA*,threadData_t*);
void OM_Result_eqFunction_66(DATA*,threadData_t*);
/*
 equation index: 73
 indexNonlinear: 3
 type: NONLINEAR
 
 vars: {Conduction_roof_inner._port_b._T}
 eqns: {60, 61, 62, 63, 64, 65, 66}
 */
void OM_Result_eqFunction_73(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,73};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 73 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[3].nlsxOld[0] = data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 3);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,73};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 73 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */ = data->simulationInfo->nonlinearSystemData[3].nlsx[0];
  TRACE_POP
}

/*
 equation index: 74
 type: SIMPLE_ASSIGN
 Radiation_roof_to_floor._dT = Conduction_roof_inner.port_b.T - Floor_temperature.k
 */
void OM_Result_eqFunction_74(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,74};
  data->localData[0]->realVars[94] /* Radiation_roof_to_floor._dT variable */ = data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */ - data->simulationInfo->realParameter[54];
  TRACE_POP
}

/*
 equation index: 75
 type: SIMPLE_ASSIGN
 Temperature_floor._port._Q_flow = Radiation_roof_to_floor.Q_flow - (Convection_floor.Q_flow + Radiation_floor.Q_flow)
 */
void OM_Result_eqFunction_75(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,75};
  data->localData[0]->realVars[111] /* Temperature_floor._port._Q_flow variable */ = data->localData[0]->realVars[93] /* Radiation_roof_to_floor._Q_flow variable */ - (data->localData[0]->realVars[51] /* Convection_floor._Q_flow variable */ + data->localData[0]->realVars[87] /* Radiation_floor._Q_flow variable */);
  TRACE_POP
}

/*
 equation index: 76
 type: SIMPLE_ASSIGN
 Radiation_roof_inner._dT = Conduction_roof_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_76(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,76};
  data->localData[0]->realVars[90] /* Radiation_roof_inner._dT variable */ = data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}

/*
 equation index: 77
 type: SIMPLE_ASSIGN
 $PRE._Data_solar_radiation._nextTimeEventScaled = 0.0
 */
void OM_Result_eqFunction_77(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,77};
  data->simulationInfo->realVarsPre[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */ = 0.0;
  TRACE_POP
}

/*
 equation index: 78
 type: SIMPLE_ASSIGN
 Data_solar_radiation._y[2] = Data_solar_radiation.p_offset[2] + Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_solar_radiation.tableID, 2, Data_solar_radiation.timeScaled, Data_solar_radiation.nextTimeEventScaled, $PRE.Data_solar_radiation.nextTimeEventScaled)
 */
void OM_Result_eqFunction_78(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,78};
  data->localData[0]->realVars[78] /* Data_solar_radiation._y[2] variable */ = data->simulationInfo->realParameter[36] + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[1], ((modelica_integer) 2), data->localData[0]->realVars[76] /* Data_solar_radiation._timeScaled variable */, data->localData[0]->realVars[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}

/*
 equation index: 79
 type: SIMPLE_ASSIGN
 Data_solar_radiation._y[1] = Data_solar_radiation.p_offset[1] + Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_solar_radiation.tableID, 1, Data_solar_radiation.timeScaled, Data_solar_radiation.nextTimeEventScaled, $PRE.Data_solar_radiation.nextTimeEventScaled)
 */
void OM_Result_eqFunction_79(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,79};
  data->localData[0]->realVars[77] /* Data_solar_radiation._y[1] variable */ = data->simulationInfo->realParameter[35] + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[1], ((modelica_integer) 1), data->localData[0]->realVars[76] /* Data_solar_radiation._timeScaled variable */, data->localData[0]->realVars[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}

/*
 equation index: 80
 type: SIMPLE_ASSIGN
 SolarRadiation = Outfall.invUniform(0.41438, Data_solar_radiation.y[1], Data_solar_radiation.y[2])
 */
void OM_Result_eqFunction_80(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,80};
  data->localData[0]->realVars[108] /* SolarRadiation variable */ = omc_Outfall_invUniform(threadData, 0.41438, data->localData[0]->realVars[77] /* Data_solar_radiation._y[1] variable */, data->localData[0]->realVars[78] /* Data_solar_radiation._y[2] variable */);
  TRACE_POP
}

/*
 equation index: 81
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._Q_flow = SolarRadiation * roof_emissivity.k
 */
void OM_Result_eqFunction_81(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,81};
  data->localData[0]->realVars[83] /* Heatflow_solar_radiation._Q_flow variable */ = (data->localData[0]->realVars[108] /* SolarRadiation variable */) * (data->simulationInfo->realParameter[74]);
  TRACE_POP
}

/*
 equation index: 82
 type: SIMPLE_ASSIGN
 $PRE._Data_outdoor_temperature._nextTimeEventScaled = 0.0
 */
void OM_Result_eqFunction_82(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,82};
  data->simulationInfo->realVarsPre[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */ = 0.0;
  TRACE_POP
}

/*
 equation index: 83
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._y[2] = Data_outdoor_temperature.p_offset[2] + Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_outdoor_temperature.tableID, 2, Data_outdoor_temperature.timeScaled, Data_outdoor_temperature.nextTimeEventScaled, $PRE.Data_outdoor_temperature.nextTimeEventScaled)
 */
void OM_Result_eqFunction_83(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,83};
  data->localData[0]->realVars[75] /* Data_outdoor_temperature._y[2] variable */ = data->simulationInfo->realParameter[26] + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 2), data->localData[0]->realVars[73] /* Data_outdoor_temperature._timeScaled variable */, data->localData[0]->realVars[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}

/*
 equation index: 84
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._y[1] = Data_outdoor_temperature.p_offset[1] + Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_outdoor_temperature.tableID, 1, Data_outdoor_temperature.timeScaled, Data_outdoor_temperature.nextTimeEventScaled, $PRE.Data_outdoor_temperature.nextTimeEventScaled)
 */
void OM_Result_eqFunction_84(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,84};
  data->localData[0]->realVars[74] /* Data_outdoor_temperature._y[1] variable */ = data->simulationInfo->realParameter[25] + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 1), data->localData[0]->realVars[73] /* Data_outdoor_temperature._timeScaled variable */, data->localData[0]->realVars[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}

/*
 equation index: 85
 type: SIMPLE_ASSIGN
 OutdoorTemperature = Outfall.invNormal(0.47349, Data_outdoor_temperature.y[1], Data_outdoor_temperature.y[2])
 */
void OM_Result_eqFunction_85(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,85};
  data->localData[0]->realVars[85] /* OutdoorTemperature variable */ = omc_Outfall_invNormal(threadData, 0.47349, data->localData[0]->realVars[74] /* Data_outdoor_temperature._y[1] variable */, data->localData[0]->realVars[75] /* Data_outdoor_temperature._y[2] variable */);
  TRACE_POP
}

/*
 equation index: 86
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct5._u[3] = two_single_ventilation1.add1.k1 * OutdoorTemperature + two_single_ventilation1.add1.k2 * Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_86(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,86};
  data->localData[0]->realVars[129] /* two_single_ventilation1._multiProduct5._u[3] variable */ = (data->simulationInfo->realParameter[87]) * (data->localData[0]->realVars[85] /* OutdoorTemperature variable */) + (data->simulationInfo->realParameter[88]) * (data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */);
  TRACE_POP
}

/*
 equation index: 87
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct1._u[3] = if noEvent(two_single_ventilation1.multiProduct5.u[3] >= 0.0) then two_single_ventilation1.multiProduct5.u[3] else -two_single_ventilation1.multiProduct5.u[3]
 */
void OM_Result_eqFunction_87(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,87};
  modelica_boolean tmp0;
  tmp0 = GreaterEq(data->localData[0]->realVars[129] /* two_single_ventilation1._multiProduct5._u[3] variable */,0.0);
  data->localData[0]->realVars[125] /* two_single_ventilation1._multiProduct1._u[3] variable */ = (tmp0?data->localData[0]->realVars[129] /* two_single_ventilation1._multiProduct5._u[3] variable */:(-data->localData[0]->realVars[129] /* two_single_ventilation1._multiProduct5._u[3] variable */));
  TRACE_POP
}

/*
 equation index: 88
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum2._u[2] = two_single_ventilation1.C2.k * two_single_ventilation1.Height_2.k * two_single_ventilation1.multiProduct1.u[3]
 */
void OM_Result_eqFunction_88(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,88};
  data->localData[0]->realVars[133] /* two_single_ventilation1._multiSum2._u[2] variable */ = (data->simulationInfo->realParameter[78]) * ((data->simulationInfo->realParameter[83]) * (data->localData[0]->realVars[125] /* two_single_ventilation1._multiProduct1._u[3] variable */));
  TRACE_POP
}

/*
 equation index: 89
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum1._u[2] = two_single_ventilation1.C2.k * two_single_ventilation1.Height_1.k * two_single_ventilation1.multiProduct1.u[3]
 */
void OM_Result_eqFunction_89(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,89};
  data->localData[0]->realVars[131] /* two_single_ventilation1._multiSum1._u[2] variable */ = (data->simulationInfo->realParameter[78]) * ((data->simulationInfo->realParameter[82]) * (data->localData[0]->realVars[125] /* two_single_ventilation1._multiProduct1._u[3] variable */));
  TRACE_POP
}

/*
 equation index: 90
 type: SIMPLE_ASSIGN
 Temperature_difference._y = Temperature_difference.k1 * OutdoorTemperature + Temperature_difference.k2 * Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_90(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,90};
  data->localData[0]->realVars[110] /* Temperature_difference._y variable */ = (data->simulationInfo->realParameter[70]) * (data->localData[0]->realVars[85] /* OutdoorTemperature variable */) + (data->simulationInfo->realParameter[71]) * (data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */);
  TRACE_POP
}

/*
 equation index: 91
 type: SIMPLE_ASSIGN
 Heatflow_infiltration._Q_flow = Temperature_difference.y * Infiltration.k
 */
void OM_Result_eqFunction_91(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,91};
  data->localData[0]->realVars[82] /* Heatflow_infiltration._Q_flow variable */ = (data->localData[0]->realVars[110] /* Temperature_difference._y variable */) * (data->simulationInfo->realParameter[59]);
  TRACE_POP
}

/*
 equation index: 92
 type: SIMPLE_ASSIGN
 thermalCollector1._port_a[12]._Q_flow = Heatflow_infiltration.Q_flow * (1.0 + Heatflow_infiltration.alpha * (Capacitor_indoor_air.T - Heatflow_infiltration.T_ref))
 */
void OM_Result_eqFunction_92(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,92};
  data->localData[0]->realVars[119] /* thermalCollector1._port_a[12]._Q_flow variable */ = (data->localData[0]->realVars[82] /* Heatflow_infiltration._Q_flow variable */) * (1.0 + (data->simulationInfo->realParameter[56]) * (data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */ - data->simulationInfo->realParameter[55]));
  TRACE_POP
}

/*
 equation index: 93
 type: SIMPLE_ASSIGN
 multiProduct1._u[2] = sqrt(OutdoorTemperature)
 */
void OM_Result_eqFunction_93(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,93};
  modelica_real tmp1;
  tmp1 = data->localData[0]->realVars[85] /* OutdoorTemperature variable */;
  if(!(tmp1 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(OutdoorTemperature) was %g should be >= 0", tmp1);
  }
  data->localData[0]->realVars[116] /* multiProduct1._u[2] variable */ = sqrt(tmp1);
  TRACE_POP
}

/*
 equation index: 94
 type: SIMPLE_ASSIGN
 SkyTemperatureToK._T = const.k * multiProduct1.u[2] * OutdoorTemperature
 */
void OM_Result_eqFunction_94(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,94};
  data->localData[0]->realVars[107] /* SkyTemperatureToK._T variable */ = (data->simulationInfo->realParameter[72]) * ((data->localData[0]->realVars[116] /* multiProduct1._u[2] variable */) * (data->localData[0]->realVars[85] /* OutdoorTemperature variable */));
  TRACE_POP
}

/*
 equation index: 95
 type: SIMPLE_ASSIGN
 $PRE._Data_wind_speed._nextTimeEventScaled = 0.0
 */
void OM_Result_eqFunction_95(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,95};
  data->simulationInfo->realVarsPre[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */ = 0.0;
  TRACE_POP
}

/*
 equation index: 96
 type: SIMPLE_ASSIGN
 Data_wind_speed._y[2] = Data_wind_speed.p_offset[2] + Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_wind_speed.tableID, 2, Data_wind_speed.timeScaled, Data_wind_speed.nextTimeEventScaled, $PRE.Data_wind_speed.nextTimeEventScaled)
 */
void OM_Result_eqFunction_96(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,96};
  data->localData[0]->realVars[81] /* Data_wind_speed._y[2] variable */ = data->simulationInfo->realParameter[46] + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[2], ((modelica_integer) 2), data->localData[0]->realVars[79] /* Data_wind_speed._timeScaled variable */, data->localData[0]->realVars[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}

/*
 equation index: 97
 type: SIMPLE_ASSIGN
 Data_wind_speed._y[1] = Data_wind_speed.p_offset[1] + Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_wind_speed.tableID, 1, Data_wind_speed.timeScaled, Data_wind_speed.nextTimeEventScaled, $PRE.Data_wind_speed.nextTimeEventScaled)
 */
void OM_Result_eqFunction_97(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,97};
  data->localData[0]->realVars[80] /* Data_wind_speed._y[1] variable */ = data->simulationInfo->realParameter[45] + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[2], ((modelica_integer) 1), data->localData[0]->realVars[79] /* Data_wind_speed._timeScaled variable */, data->localData[0]->realVars[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}

/*
 equation index: 98
 type: SIMPLE_ASSIGN
 WindSpeed = max(0.01, Outfall.invWeibull(0.3386, Data_wind_speed.y[1], Data_wind_speed.y[2]))
 */
void OM_Result_eqFunction_98(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,98};
  data->localData[0]->realVars[112] /* WindSpeed variable */ = fmax(0.01,omc_Outfall_invWeibull(threadData, 0.3386, data->localData[0]->realVars[80] /* Data_wind_speed._y[1] variable */, data->localData[0]->realVars[81] /* Data_wind_speed._y[2] variable */));
  TRACE_POP
}

/*
 equation index: 99
 type: SIMPLE_ASSIGN
 log1._y = log(WindSpeed)
 */
void OM_Result_eqFunction_99(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,99};
  modelica_real tmp2;
  tmp2 = data->localData[0]->realVars[112] /* WindSpeed variable */;
  if(!(tmp2 > 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of log(WindSpeed) was %g should be > 0", tmp2);
  }
  data->localData[0]->realVars[115] /* log1._y variable */ = log(tmp2);
  TRACE_POP
}

/*
 equation index: 100
 type: SIMPLE_ASSIGN
 exp1._u = log1.y * Convection_B.k
 */
void OM_Result_eqFunction_100(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,100};
  data->localData[0]->realVars[113] /* exp1._u variable */ = (data->localData[0]->realVars[115] /* log1._y variable */) * (data->simulationInfo->realParameter[18]);
  TRACE_POP
}

/*
 equation index: 101
 type: SIMPLE_ASSIGN
 exp1._y = exp(exp1.u)
 */
void OM_Result_eqFunction_101(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,101};
  data->localData[0]->realVars[114] /* exp1._y variable */ = exp(data->localData[0]->realVars[113] /* exp1._u variable */);
  TRACE_POP
}

/*
 equation index: 102
 type: SIMPLE_ASSIGN
 product4._y = exp1.y * Convection_A.k
 */
void OM_Result_eqFunction_102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,102};
  data->localData[0]->realVars[117] /* product4._y variable */ = (data->localData[0]->realVars[114] /* exp1._y variable */) * (data->simulationInfo->realParameter[17]);
  TRACE_POP
}

/*
 equation index: 103
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Gc = Area_wall4.k * product4.y
 */
void OM_Result_eqFunction_103(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,103};
  data->localData[0]->realVars[70] /* Convection_wall4_outer._Gc variable */ = (data->simulationInfo->realParameter[3]) * (data->localData[0]->realVars[117] /* product4._y variable */);
  TRACE_POP
}

void OM_Result_eqFunction_104(DATA*,threadData_t*);
void OM_Result_eqFunction_105(DATA*,threadData_t*);
void OM_Result_eqFunction_106(DATA*,threadData_t*);
void OM_Result_eqFunction_107(DATA*,threadData_t*);
void OM_Result_eqFunction_108(DATA*,threadData_t*);
void OM_Result_eqFunction_109(DATA*,threadData_t*);
/*
 equation index: 114
 indexNonlinear: 4
 type: NONLINEAR
 
 vars: {Conduction_wall4_outer._port_a._T}
 eqns: {104, 105, 106, 107, 108, 109}
 */
void OM_Result_eqFunction_114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,114};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 114 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[4].nlsxOld[0] = data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 4);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,114};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 114 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */ = data->simulationInfo->nonlinearSystemData[4].nlsx[0];
  TRACE_POP
}

/*
 equation index: 115
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._dT = OutdoorTemperature - Conduction_wall4_outer.port_a.T
 */
void OM_Result_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
  data->localData[0]->realVars[106] /* Radiation_wall4_outer._dT variable */ = data->localData[0]->realVars[85] /* OutdoorTemperature variable */ - data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */;
  TRACE_POP
}

/*
 equation index: 116
 type: SIMPLE_ASSIGN
 Capacitor_wall4._port._Q_flow = Conduction_wall4_outer.Q_flow - Conduction_wall4_inner.Q_flow
 */
void OM_Result_eqFunction_116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,116};
  data->localData[0]->realVars[26] /* Capacitor_wall4._port._Q_flow variable */ = data->localData[0]->realVars[48] /* Conduction_wall4_outer._Q_flow variable */ - data->localData[0]->realVars[45] /* Conduction_wall4_inner._Q_flow variable */;
  TRACE_POP
}

/*
 equation index: 117
 type: SIMPLE_ASSIGN
 Capacitor_wall4._der_T = DIVISION(Capacitor_wall4.port.Q_flow, Capacitor_wall4.C)
 */
void OM_Result_eqFunction_117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,117};
  data->localData[0]->realVars[25] /* Capacitor_wall4._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[26] /* Capacitor_wall4._port._Q_flow variable */,data->simulationInfo->realParameter[8],"Capacitor_wall4.C",equationIndexes);
  TRACE_POP
}

/*
 equation index: 118
 type: SIMPLE_ASSIGN
 der(Capacitor_wall4._T) = Capacitor_wall4.der_T
 */
void OM_Result_eqFunction_118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,118};
  data->localData[0]->realVars[9] /* der(Capacitor_wall4._T) STATE_DER */ = data->localData[0]->realVars[25] /* Capacitor_wall4._der_T variable */;
  TRACE_POP
}

/*
 equation index: 119
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Gc = Area_wall3.k * product4.y
 */
void OM_Result_eqFunction_119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,119};
  data->localData[0]->realVars[65] /* Convection_wall3_outer._Gc variable */ = (data->simulationInfo->realParameter[2]) * (data->localData[0]->realVars[117] /* product4._y variable */);
  TRACE_POP
}

void OM_Result_eqFunction_120(DATA*,threadData_t*);
void OM_Result_eqFunction_121(DATA*,threadData_t*);
void OM_Result_eqFunction_122(DATA*,threadData_t*);
void OM_Result_eqFunction_123(DATA*,threadData_t*);
void OM_Result_eqFunction_124(DATA*,threadData_t*);
void OM_Result_eqFunction_125(DATA*,threadData_t*);
/*
 equation index: 131
 indexNonlinear: 5
 type: NONLINEAR
 
 vars: {Conduction_wall3_outer._port_a._T}
 eqns: {120, 121, 122, 123, 124, 125}
 */
void OM_Result_eqFunction_131(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,131};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 131 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[5].nlsxOld[0] = data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 5);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,131};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 131 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */ = data->simulationInfo->nonlinearSystemData[5].nlsx[0];
  TRACE_POP
}

/*
 equation index: 132
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._dT = OutdoorTemperature - Conduction_wall3_outer.port_a.T
 */
void OM_Result_eqFunction_132(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,132};
  data->localData[0]->realVars[102] /* Radiation_wall3_outer._dT variable */ = data->localData[0]->realVars[85] /* OutdoorTemperature variable */ - data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */;
  TRACE_POP
}

/*
 equation index: 133
 type: SIMPLE_ASSIGN
 Capacitor_wall3._port._Q_flow = Conduction_wall3_outer.Q_flow - Conduction_wall3_inner.Q_flow
 */
void OM_Result_eqFunction_133(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,133};
  data->localData[0]->realVars[24] /* Capacitor_wall3._port._Q_flow variable */ = data->localData[0]->realVars[42] /* Conduction_wall3_outer._Q_flow variable */ - data->localData[0]->realVars[39] /* Conduction_wall3_inner._Q_flow variable */;
  TRACE_POP
}

/*
 equation index: 134
 type: SIMPLE_ASSIGN
 Capacitor_wall3._der_T = DIVISION(Capacitor_wall3.port.Q_flow, Capacitor_wall3.C)
 */
void OM_Result_eqFunction_134(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,134};
  data->localData[0]->realVars[23] /* Capacitor_wall3._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[24] /* Capacitor_wall3._port._Q_flow variable */,data->simulationInfo->realParameter[7],"Capacitor_wall3.C",equationIndexes);
  TRACE_POP
}

/*
 equation index: 135
 type: SIMPLE_ASSIGN
 der(Capacitor_wall3._T) = Capacitor_wall3.der_T
 */
void OM_Result_eqFunction_135(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,135};
  data->localData[0]->realVars[8] /* der(Capacitor_wall3._T) STATE_DER */ = data->localData[0]->realVars[23] /* Capacitor_wall3._der_T variable */;
  TRACE_POP
}

/*
 equation index: 136
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Gc = Area_wall1.k * product4.y
 */
void OM_Result_eqFunction_136(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,136};
  data->localData[0]->realVars[60] /* Convection_wall1_outer._Gc variable */ = (data->simulationInfo->realParameter[1]) * (data->localData[0]->realVars[117] /* product4._y variable */);
  TRACE_POP
}

void OM_Result_eqFunction_137(DATA*,threadData_t*);
void OM_Result_eqFunction_138(DATA*,threadData_t*);
void OM_Result_eqFunction_139(DATA*,threadData_t*);
void OM_Result_eqFunction_140(DATA*,threadData_t*);
void OM_Result_eqFunction_141(DATA*,threadData_t*);
void OM_Result_eqFunction_142(DATA*,threadData_t*);
/*
 equation index: 147
 indexNonlinear: 6
 type: NONLINEAR
 
 vars: {Conduction_wall1_outer._port_a._T}
 eqns: {137, 138, 139, 140, 141, 142}
 */
void OM_Result_eqFunction_147(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,147};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 147 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[6].nlsxOld[0] = data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 6);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,147};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 147 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */ = data->simulationInfo->nonlinearSystemData[6].nlsx[0];
  TRACE_POP
}

/*
 equation index: 148
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._dT = OutdoorTemperature - Conduction_wall1_outer.port_a.T
 */
void OM_Result_eqFunction_148(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,148};
  data->localData[0]->realVars[98] /* Radiation_wall1_outer._dT variable */ = data->localData[0]->realVars[85] /* OutdoorTemperature variable */ - data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */;
  TRACE_POP
}

/*
 equation index: 149
 type: SIMPLE_ASSIGN
 Capacitor_wall1._port._Q_flow = Conduction_wall1_outer.Q_flow - Conduction_wall1_inner.Q_flow
 */
void OM_Result_eqFunction_149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,149};
  data->localData[0]->realVars[22] /* Capacitor_wall1._port._Q_flow variable */ = data->localData[0]->realVars[36] /* Conduction_wall1_outer._Q_flow variable */ - data->localData[0]->realVars[33] /* Conduction_wall1_inner._Q_flow variable */;
  TRACE_POP
}

/*
 equation index: 150
 type: SIMPLE_ASSIGN
 Capacitor_wall1._der_T = DIVISION(Capacitor_wall1.port.Q_flow, Capacitor_wall1.C)
 */
void OM_Result_eqFunction_150(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,150};
  data->localData[0]->realVars[21] /* Capacitor_wall1._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[22] /* Capacitor_wall1._port._Q_flow variable */,data->simulationInfo->realParameter[6],"Capacitor_wall1.C",equationIndexes);
  TRACE_POP
}

/*
 equation index: 151
 type: SIMPLE_ASSIGN
 der(Capacitor_wall1._T) = Capacitor_wall1.der_T
 */
void OM_Result_eqFunction_151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,151};
  data->localData[0]->realVars[7] /* der(Capacitor_wall1._T) STATE_DER */ = data->localData[0]->realVars[21] /* Capacitor_wall1._der_T variable */;
  TRACE_POP
}

/*
 equation index: 152
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Gc = Area_roof.k * product4.y
 */
void OM_Result_eqFunction_152(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,152};
  data->localData[0]->realVars[55] /* Convection_roof_outer._Gc variable */ = (data->simulationInfo->realParameter[0]) * (data->localData[0]->realVars[117] /* product4._y variable */);
  TRACE_POP
}

void OM_Result_eqFunction_153(DATA*,threadData_t*);
void OM_Result_eqFunction_154(DATA*,threadData_t*);
void OM_Result_eqFunction_155(DATA*,threadData_t*);
void OM_Result_eqFunction_156(DATA*,threadData_t*);
void OM_Result_eqFunction_157(DATA*,threadData_t*);
void OM_Result_eqFunction_158(DATA*,threadData_t*);
void OM_Result_eqFunction_159(DATA*,threadData_t*);
/*
 equation index: 166
 indexNonlinear: 7
 type: NONLINEAR
 
 vars: {Conduction_roof_outer._port_a._T}
 eqns: {153, 154, 155, 156, 157, 158, 159}
 */
void OM_Result_eqFunction_166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,166};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 166 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[7].nlsxOld[0] = data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 7);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,166};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 166 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */ = data->simulationInfo->nonlinearSystemData[7].nlsx[0];
  TRACE_POP
}

/*
 equation index: 167
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._dT = SkyTemperatureToK.T - Conduction_roof_outer.port_a.T
 */
void OM_Result_eqFunction_167(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,167};
  data->localData[0]->realVars[92] /* Radiation_roof_outer._dT variable */ = data->localData[0]->realVars[107] /* SkyTemperatureToK._T variable */ - data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */;
  TRACE_POP
}

/*
 equation index: 168
 type: SIMPLE_ASSIGN
 OutdoorTemperatureToK._port._Q_flow = (-Convection_roof_outer.Q_flow) - Convection_wall1_outer.Q_flow - Convection_wall4_outer.Q_flow - Convection_wall3_outer.Q_flow - Radiation_wall1_outer.Q_flow - Radiation_wall3_outer.Q_flow - Radiation_wall4_outer.Q_flow
 */
void OM_Result_eqFunction_168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,168};
  data->localData[0]->realVars[86] /* OutdoorTemperatureToK._port._Q_flow variable */ = (-data->localData[0]->realVars[56] /* Convection_roof_outer._Q_flow variable */) - data->localData[0]->realVars[61] /* Convection_wall1_outer._Q_flow variable */ - data->localData[0]->realVars[71] /* Convection_wall4_outer._Q_flow variable */ - data->localData[0]->realVars[66] /* Convection_wall3_outer._Q_flow variable */ - data->localData[0]->realVars[97] /* Radiation_wall1_outer._Q_flow variable */ - data->localData[0]->realVars[101] /* Radiation_wall3_outer._Q_flow variable */ - data->localData[0]->realVars[105] /* Radiation_wall4_outer._Q_flow variable */;
  TRACE_POP
}

/*
 equation index: 169
 type: SIMPLE_ASSIGN
 Capacitor_roof._port._Q_flow = Conduction_roof_outer.Q_flow - Conduction_roof_inner.Q_flow
 */
void OM_Result_eqFunction_169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,169};
  data->localData[0]->realVars[20] /* Capacitor_roof._port._Q_flow variable */ = data->localData[0]->realVars[30] /* Conduction_roof_outer._Q_flow variable */ - data->localData[0]->realVars[27] /* Conduction_roof_inner._Q_flow variable */;
  TRACE_POP
}

/*
 equation index: 170
 type: SIMPLE_ASSIGN
 Capacitor_roof._der_T = DIVISION(Capacitor_roof.port.Q_flow, Capacitor_roof.C)
 */
void OM_Result_eqFunction_170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,170};
  data->localData[0]->realVars[19] /* Capacitor_roof._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[20] /* Capacitor_roof._port._Q_flow variable */,data->simulationInfo->realParameter[5],"Capacitor_roof.C",equationIndexes);
  TRACE_POP
}

/*
 equation index: 171
 type: SIMPLE_ASSIGN
 der(Capacitor_roof._T) = Capacitor_roof.der_T
 */
void OM_Result_eqFunction_171(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,171};
  data->localData[0]->realVars[6] /* der(Capacitor_roof._T) STATE_DER */ = data->localData[0]->realVars[19] /* Capacitor_roof._der_T variable */;
  TRACE_POP
}

/*
 equation index: 172
 type: SIMPLE_ASSIGN
 two_single_ventilation1._U_square._y = WindSpeed ^ 2.0
 */
void OM_Result_eqFunction_172(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,172};
  modelica_real tmp0;
  tmp0 = data->localData[0]->realVars[112] /* WindSpeed variable */;
  data->localData[0]->realVars[122] /* two_single_ventilation1._U_square._y variable */ = (tmp0 * tmp0);
  TRACE_POP
}

/*
 equation index: 173
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum1._u[1] = two_single_ventilation1.C1.k * two_single_ventilation1.U_square.y
 */
void OM_Result_eqFunction_173(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,173};
  data->localData[0]->realVars[130] /* two_single_ventilation1._multiSum1._u[1] variable */ = (data->simulationInfo->realParameter[77]) * (data->localData[0]->realVars[122] /* two_single_ventilation1._U_square._y variable */);
  TRACE_POP
}

/*
 equation index: 174
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum2._y = two_single_ventilation1.multiSum2.k[1] * two_single_ventilation1.multiSum1.u[1] + two_single_ventilation1.multiSum2.k[2] * two_single_ventilation1.multiSum2.u[2] + two_single_ventilation1.multiSum2.k[3] * two_single_ventilation1.C3.k
 */
void OM_Result_eqFunction_174(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,174};
  data->localData[0]->realVars[134] /* two_single_ventilation1._multiSum2._y variable */ = (data->simulationInfo->realParameter[93]) * (data->localData[0]->realVars[130] /* two_single_ventilation1._multiSum1._u[1] variable */) + (data->simulationInfo->realParameter[94]) * (data->localData[0]->realVars[133] /* two_single_ventilation1._multiSum2._u[2] variable */) + (data->simulationInfo->realParameter[95]) * (data->simulationInfo->realParameter[79]);
  TRACE_POP
}

/*
 equation index: 175
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct4._u[3] = sqrt(two_single_ventilation1.multiSum2.y)
 */
void OM_Result_eqFunction_175(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,175};
  modelica_real tmp1;
  tmp1 = data->localData[0]->realVars[134] /* two_single_ventilation1._multiSum2._y variable */;
  if(!(tmp1 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(two_single_ventilation1.multiSum2.y) was %g should be >= 0", tmp1);
  }
  data->localData[0]->realVars[127] /* two_single_ventilation1._multiProduct4._u[3] variable */ = sqrt(tmp1);
  TRACE_POP
}

/*
 equation index: 176
 type: SIMPLE_ASSIGN
 two_single_ventilation1._Ventilation_rate._u2 = two_single_ventilation1.const.k * two_single_ventilation1.Area_2.k * two_single_ventilation1.multiProduct4.u[3]
 */
void OM_Result_eqFunction_176(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,176};
  data->localData[0]->realVars[124] /* two_single_ventilation1._Ventilation_rate._u2 variable */ = (data->simulationInfo->realParameter[89]) * ((data->simulationInfo->realParameter[76]) * (data->localData[0]->realVars[127] /* two_single_ventilation1._multiProduct4._u[3] variable */));
  TRACE_POP
}

/*
 equation index: 177
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum1._y = two_single_ventilation1.multiSum1.k[1] * two_single_ventilation1.multiSum1.u[1] + two_single_ventilation1.multiSum1.k[2] * two_single_ventilation1.multiSum1.u[2] + two_single_ventilation1.multiSum1.k[3] * two_single_ventilation1.C3.k
 */
void OM_Result_eqFunction_177(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,177};
  data->localData[0]->realVars[132] /* two_single_ventilation1._multiSum1._y variable */ = (data->simulationInfo->realParameter[90]) * (data->localData[0]->realVars[130] /* two_single_ventilation1._multiSum1._u[1] variable */) + (data->simulationInfo->realParameter[91]) * (data->localData[0]->realVars[131] /* two_single_ventilation1._multiSum1._u[2] variable */) + (data->simulationInfo->realParameter[92]) * (data->simulationInfo->realParameter[79]);
  TRACE_POP
}

/*
 equation index: 178
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct3._u[3] = sqrt(two_single_ventilation1.multiSum1.y)
 */
void OM_Result_eqFunction_178(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,178};
  modelica_real tmp2;
  tmp2 = data->localData[0]->realVars[132] /* two_single_ventilation1._multiSum1._y variable */;
  if(!(tmp2 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(two_single_ventilation1.multiSum1.y) was %g should be >= 0", tmp2);
  }
  data->localData[0]->realVars[126] /* two_single_ventilation1._multiProduct3._u[3] variable */ = sqrt(tmp2);
  TRACE_POP
}

/*
 equation index: 179
 type: SIMPLE_ASSIGN
 two_single_ventilation1._Ventilation_rate._u1 = two_single_ventilation1.const.k * two_single_ventilation1.Area_1.k * two_single_ventilation1.multiProduct3.u[3]
 */
void OM_Result_eqFunction_179(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,179};
  data->localData[0]->realVars[123] /* two_single_ventilation1._Ventilation_rate._u1 variable */ = (data->simulationInfo->realParameter[89]) * ((data->simulationInfo->realParameter[75]) * (data->localData[0]->realVars[126] /* two_single_ventilation1._multiProduct3._u[3] variable */));
  TRACE_POP
}

/*
 equation index: 180
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct5._u[2] = two_single_ventilation1.Ventilation_rate.k1 * two_single_ventilation1.Ventilation_rate.u1 + two_single_ventilation1.Ventilation_rate.k2 * two_single_ventilation1.Ventilation_rate.u2
 */
void OM_Result_eqFunction_180(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,180};
  data->localData[0]->realVars[128] /* two_single_ventilation1._multiProduct5._u[2] variable */ = (data->simulationInfo->realParameter[85]) * (data->localData[0]->realVars[123] /* two_single_ventilation1._Ventilation_rate._u1 variable */) + (data->simulationInfo->realParameter[86]) * (data->localData[0]->realVars[124] /* two_single_ventilation1._Ventilation_rate._u2 variable */);
  TRACE_POP
}

/*
 equation index: 181
 type: SIMPLE_ASSIGN
 two_single_ventilation1._Heat_flow_NV._Q_flow = two_single_ventilation1.Ventilation_param.k * two_single_ventilation1.multiProduct5.u[2] * two_single_ventilation1.multiProduct5.u[3]
 */
void OM_Result_eqFunction_181(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,181};
  data->localData[0]->realVars[120] /* two_single_ventilation1._Heat_flow_NV._Q_flow variable */ = (data->simulationInfo->realParameter[84]) * ((data->localData[0]->realVars[128] /* two_single_ventilation1._multiProduct5._u[2] variable */) * (data->localData[0]->realVars[129] /* two_single_ventilation1._multiProduct5._u[3] variable */));
  TRACE_POP
}

/*
 equation index: 182
 type: SIMPLE_ASSIGN
 thermalCollector1._port_a[11]._Q_flow = two_single_ventilation1.Heat_flow_NV.Q_flow * (1.0 + two_single_ventilation1.Heat_flow_NV.alpha * (Capacitor_indoor_air.T - two_single_ventilation1.Heat_flow_NV.T_ref))
 */
void OM_Result_eqFunction_182(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,182};
  data->localData[0]->realVars[118] /* thermalCollector1._port_a[11]._Q_flow variable */ = (data->localData[0]->realVars[120] /* two_single_ventilation1._Heat_flow_NV._Q_flow variable */) * (1.0 + (data->simulationInfo->realParameter[81]) * (data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */ - data->simulationInfo->realParameter[80]));
  TRACE_POP
}

/*
 equation index: 183
 type: SIMPLE_ASSIGN
 Capacitor_indoor_air._port._Q_flow = thermalCollector1.port_a[12].Q_flow - ((-Convection_roof_inner.Q_flow) - Radiation_roof_inner.Q_flow - Convection_wall1_inner.Q_flow - Radiation_wall1_inner.Q_flow - Convection_wall3_inner.Q_flow - Radiation_wall3_inner.Q_flow - Convection_wall4_inner.Q_flow - Radiation_wall4_inner.Q_flow - Convection_floor.Q_flow - Radiation_floor.Q_flow - thermalCollector1.port_a[11].Q_flow)
 */
void OM_Result_eqFunction_183(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,183};
  data->localData[0]->realVars[18] /* Capacitor_indoor_air._port._Q_flow variable */ = data->localData[0]->realVars[119] /* thermalCollector1._port_a[12]._Q_flow variable */ - ((-data->localData[0]->realVars[53] /* Convection_roof_inner._Q_flow variable */) - data->localData[0]->realVars[89] /* Radiation_roof_inner._Q_flow variable */ - data->localData[0]->realVars[58] /* Convection_wall1_inner._Q_flow variable */ - data->localData[0]->realVars[95] /* Radiation_wall1_inner._Q_flow variable */ - data->localData[0]->realVars[63] /* Convection_wall3_inner._Q_flow variable */ - data->localData[0]->realVars[99] /* Radiation_wall3_inner._Q_flow variable */ - data->localData[0]->realVars[68] /* Convection_wall4_inner._Q_flow variable */ - data->localData[0]->realVars[103] /* Radiation_wall4_inner._Q_flow variable */ - data->localData[0]->realVars[51] /* Convection_floor._Q_flow variable */ - data->localData[0]->realVars[87] /* Radiation_floor._Q_flow variable */ - data->localData[0]->realVars[118] /* thermalCollector1._port_a[11]._Q_flow variable */);
  TRACE_POP
}

/*
 equation index: 184
 type: SIMPLE_ASSIGN
 Capacitor_indoor_air._der_T = DIVISION(Capacitor_indoor_air.port.Q_flow, Capacitor_indoor_air.C)
 */
void OM_Result_eqFunction_184(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,184};
  data->localData[0]->realVars[17] /* Capacitor_indoor_air._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[18] /* Capacitor_indoor_air._port._Q_flow variable */,data->simulationInfo->realParameter[4],"Capacitor_indoor_air.C",equationIndexes);
  TRACE_POP
}

/*
 equation index: 185
 type: SIMPLE_ASSIGN
 der(Capacitor_indoor_air._T) = Capacitor_indoor_air.der_T
 */
void OM_Result_eqFunction_185(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,185};
  data->localData[0]->realVars[5] /* der(Capacitor_indoor_air._T) STATE_DER */ = data->localData[0]->realVars[17] /* Capacitor_indoor_air._der_T variable */;
  TRACE_POP
}

/*
 equation index: 186
 type: SIMPLE_ASSIGN
 $PRE._Data_wind_speed._nextTimeEvent = 0.0
 */
void OM_Result_eqFunction_186(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,186};
  data->simulationInfo->realVarsPre[139] /* Data_wind_speed._nextTimeEvent DISCRETE */ = 0.0;
  TRACE_POP
}

/*
 equation index: 187
 type: SIMPLE_ASSIGN
 $whenCondition1 = time >= $PRE.Data_wind_speed.nextTimeEvent
 */
void OM_Result_eqFunction_187(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,187};
  modelica_boolean tmp3;
  tmp3 = GreaterEq(data->localData[0]->timeValue,data->simulationInfo->realVarsPre[139] /* Data_wind_speed._nextTimeEvent DISCRETE */);
  data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ = tmp3;
  TRACE_POP
}

/*
 equation index: 188
 type: SIMPLE_ASSIGN
 $PRE._Data_outdoor_temperature._nextTimeEvent = 0.0
 */
void OM_Result_eqFunction_188(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,188};
  data->simulationInfo->realVarsPre[135] /* Data_outdoor_temperature._nextTimeEvent DISCRETE */ = 0.0;
  TRACE_POP
}

/*
 equation index: 189
 type: SIMPLE_ASSIGN
 $whenCondition2 = time >= $PRE.Data_outdoor_temperature.nextTimeEvent
 */
void OM_Result_eqFunction_189(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,189};
  modelica_boolean tmp4;
  tmp4 = GreaterEq(data->localData[0]->timeValue,data->simulationInfo->realVarsPre[135] /* Data_outdoor_temperature._nextTimeEvent DISCRETE */);
  data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */ = tmp4;
  TRACE_POP
}

/*
 equation index: 190
 type: SIMPLE_ASSIGN
 $PRE._Data_solar_radiation._nextTimeEvent = 0.0
 */
void OM_Result_eqFunction_190(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,190};
  data->simulationInfo->realVarsPre[137] /* Data_solar_radiation._nextTimeEvent DISCRETE */ = 0.0;
  TRACE_POP
}

/*
 equation index: 191
 type: SIMPLE_ASSIGN
 $whenCondition3 = time >= $PRE.Data_solar_radiation.nextTimeEvent
 */
void OM_Result_eqFunction_191(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,191};
  modelica_boolean tmp5;
  tmp5 = GreaterEq(data->localData[0]->timeValue,data->simulationInfo->realVarsPre[137] /* Data_solar_radiation._nextTimeEvent DISCRETE */);
  data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */ = tmp5;
  TRACE_POP
}

/*
 equation index: 194
 type: ALGORITHM
 
   assert(Data_solar_radiation.tableName <> "NoName", "tableOnFile = true and no table name given");
 */
void OM_Result_eqFunction_194(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,194};
  static const MMC_DEFSTRINGLIT(tmp8,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp9,42,"tableOnFile = true and no table name given");
  static int tmp10 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[3], MMC_REFSTRINGLIT(tmp8))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2207,7,2208,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_solar_radiation.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp9)));
      }
    }
  }
  TRACE_POP
}

/*
 equation index: 193
 type: ALGORITHM
 
   assert(Data_outdoor_temperature.tableName <> "NoName", "tableOnFile = true and no table name given");
 */
void OM_Result_eqFunction_193(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,193};
  static const MMC_DEFSTRINGLIT(tmp13,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp14,42,"tableOnFile = true and no table name given");
  static int tmp15 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[1], MMC_REFSTRINGLIT(tmp13))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2207,7,2208,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_outdoor_temperature.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp14)));
      }
    }
  }
  TRACE_POP
}

/*
 equation index: 192
 type: ALGORITHM
 
   assert(Data_wind_speed.tableName <> "NoName", "tableOnFile = true and no table name given");
 */
void OM_Result_eqFunction_192(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,192};
  static const MMC_DEFSTRINGLIT(tmp18,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp19,42,"tableOnFile = true and no table name given");
  static int tmp20 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[5], MMC_REFSTRINGLIT(tmp18))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2207,7,2208,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_wind_speed.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp19)));
      }
    }
  }
  TRACE_POP
}
void OM_Result_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  OM_Result_eqFunction_1(data, threadData);
  OM_Result_eqFunction_2(data, threadData);
  OM_Result_eqFunction_3(data, threadData);
  OM_Result_eqFunction_4(data, threadData);
  OM_Result_eqFunction_5(data, threadData);
  OM_Result_eqFunction_6(data, threadData);
  OM_Result_eqFunction_7(data, threadData);
  OM_Result_eqFunction_8(data, threadData);
  OM_Result_eqFunction_9(data, threadData);
  OM_Result_eqFunction_10(data, threadData);
  OM_Result_eqFunction_11(data, threadData);
  OM_Result_eqFunction_12(data, threadData);
  OM_Result_eqFunction_13(data, threadData);
  OM_Result_eqFunction_14(data, threadData);
  OM_Result_eqFunction_15(data, threadData);
  OM_Result_eqFunction_16(data, threadData);
  OM_Result_eqFunction_17(data, threadData);
  OM_Result_eqFunction_18(data, threadData);
  OM_Result_eqFunction_19(data, threadData);
  OM_Result_eqFunction_20(data, threadData);
  OM_Result_eqFunction_32(data, threadData);
  OM_Result_eqFunction_33(data, threadData);
  OM_Result_eqFunction_45(data, threadData);
  OM_Result_eqFunction_46(data, threadData);
  OM_Result_eqFunction_58(data, threadData);
  OM_Result_eqFunction_59(data, threadData);
  OM_Result_eqFunction_73(data, threadData);
  OM_Result_eqFunction_74(data, threadData);
  OM_Result_eqFunction_75(data, threadData);
  OM_Result_eqFunction_76(data, threadData);
  OM_Result_eqFunction_77(data, threadData);
  OM_Result_eqFunction_78(data, threadData);
  OM_Result_eqFunction_79(data, threadData);
  OM_Result_eqFunction_80(data, threadData);
  OM_Result_eqFunction_81(data, threadData);
  OM_Result_eqFunction_82(data, threadData);
  OM_Result_eqFunction_83(data, threadData);
  OM_Result_eqFunction_84(data, threadData);
  OM_Result_eqFunction_85(data, threadData);
  OM_Result_eqFunction_86(data, threadData);
  OM_Result_eqFunction_87(data, threadData);
  OM_Result_eqFunction_88(data, threadData);
  OM_Result_eqFunction_89(data, threadData);
  OM_Result_eqFunction_90(data, threadData);
  OM_Result_eqFunction_91(data, threadData);
  OM_Result_eqFunction_92(data, threadData);
  OM_Result_eqFunction_93(data, threadData);
  OM_Result_eqFunction_94(data, threadData);
  OM_Result_eqFunction_95(data, threadData);
  OM_Result_eqFunction_96(data, threadData);
  OM_Result_eqFunction_97(data, threadData);
  OM_Result_eqFunction_98(data, threadData);
  OM_Result_eqFunction_99(data, threadData);
  OM_Result_eqFunction_100(data, threadData);
  OM_Result_eqFunction_101(data, threadData);
  OM_Result_eqFunction_102(data, threadData);
  OM_Result_eqFunction_103(data, threadData);
  OM_Result_eqFunction_114(data, threadData);
  OM_Result_eqFunction_115(data, threadData);
  OM_Result_eqFunction_116(data, threadData);
  OM_Result_eqFunction_117(data, threadData);
  OM_Result_eqFunction_118(data, threadData);
  OM_Result_eqFunction_119(data, threadData);
  OM_Result_eqFunction_131(data, threadData);
  OM_Result_eqFunction_132(data, threadData);
  OM_Result_eqFunction_133(data, threadData);
  OM_Result_eqFunction_134(data, threadData);
  OM_Result_eqFunction_135(data, threadData);
  OM_Result_eqFunction_136(data, threadData);
  OM_Result_eqFunction_147(data, threadData);
  OM_Result_eqFunction_148(data, threadData);
  OM_Result_eqFunction_149(data, threadData);
  OM_Result_eqFunction_150(data, threadData);
  OM_Result_eqFunction_151(data, threadData);
  OM_Result_eqFunction_152(data, threadData);
  OM_Result_eqFunction_166(data, threadData);
  OM_Result_eqFunction_167(data, threadData);
  OM_Result_eqFunction_168(data, threadData);
  OM_Result_eqFunction_169(data, threadData);
  OM_Result_eqFunction_170(data, threadData);
  OM_Result_eqFunction_171(data, threadData);
  OM_Result_eqFunction_172(data, threadData);
  OM_Result_eqFunction_173(data, threadData);
  OM_Result_eqFunction_174(data, threadData);
  OM_Result_eqFunction_175(data, threadData);
  OM_Result_eqFunction_176(data, threadData);
  OM_Result_eqFunction_177(data, threadData);
  OM_Result_eqFunction_178(data, threadData);
  OM_Result_eqFunction_179(data, threadData);
  OM_Result_eqFunction_180(data, threadData);
  OM_Result_eqFunction_181(data, threadData);
  OM_Result_eqFunction_182(data, threadData);
  OM_Result_eqFunction_183(data, threadData);
  OM_Result_eqFunction_184(data, threadData);
  OM_Result_eqFunction_185(data, threadData);
  OM_Result_eqFunction_186(data, threadData);
  OM_Result_eqFunction_187(data, threadData);
  OM_Result_eqFunction_188(data, threadData);
  OM_Result_eqFunction_189(data, threadData);
  OM_Result_eqFunction_190(data, threadData);
  OM_Result_eqFunction_191(data, threadData);
  OM_Result_eqFunction_194(data, threadData);
  OM_Result_eqFunction_193(data, threadData);
  OM_Result_eqFunction_192(data, threadData);
  TRACE_POP
}


int OM_Result_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  OM_Result_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int OM_Result_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int OM_Result_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif


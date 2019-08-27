/* Non Linear Systems */
#include "OM_Result_model.h"
#include "OM_Result_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* inner equations */

/*
 equation index: 22
 type: SIMPLE_ASSIGN
 Radiation_wall4_inner._Q_flow = 5.670367e-08 * Radiation_wall4_inner.Gr * (Conduction_wall4_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[90] /* Radiation_wall4_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[63]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 23
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._dT = Conduction_wall4_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  data->localData[0]->realVars[62] /* Convection_wall4_inner._dT variable */ = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 24
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._Q_flow = Convection_coef_wall4_inner.k * Convection_wall4_inner.dT
 */
void OM_Result_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  data->localData[0]->realVars[61] /* Convection_wall4_inner._Q_flow variable */ = (data->simulationInfo->realParameter[20]) * (data->localData[0]->realVars[62] /* Convection_wall4_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 25
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._Q_flow = Radiation_wall4_inner.Q_flow + Convection_wall4_inner.Q_flow
 */
void OM_Result_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  data->localData[0]->realVars[41] /* Conduction_wall4_inner._Q_flow variable */ = data->localData[0]->realVars[90] /* Radiation_wall4_inner._Q_flow variable */ + data->localData[0]->realVars[61] /* Convection_wall4_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 26
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._dT = DIVISION(Conduction_wall4_inner.Q_flow, Conduction_wall4_inner.G)
 */
void OM_Result_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  data->localData[0]->realVars[42] /* Conduction_wall4_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[41] /* Conduction_wall4_inner._Q_flow variable */,data->simulationInfo->realParameter[11],"Conduction_wall4_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc33(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,33};
  /* iteration variables */
  data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_22(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_23(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_24(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_25(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_26(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */ + (-data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */) - data->localData[0]->realVars[42] /* Conduction_wall4_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS33(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS33(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall4_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS33(sysData);
}

void getIterationVarsNLS33(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 35
 type: SIMPLE_ASSIGN
 Radiation_wall3_inner._Q_flow = 5.670367e-08 * Radiation_wall3_inner.Gr * (Conduction_wall3_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[86] /* Radiation_wall3_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[61]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 36
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._dT = Conduction_wall3_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  data->localData[0]->realVars[58] /* Convection_wall3_inner._dT variable */ = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 37
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._Q_flow = Convection_coef_wall3_inner.k * Convection_wall3_inner.dT
 */
void OM_Result_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  data->localData[0]->realVars[57] /* Convection_wall3_inner._Q_flow variable */ = (data->simulationInfo->realParameter[18]) * (data->localData[0]->realVars[58] /* Convection_wall3_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 38
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._Q_flow = Radiation_wall3_inner.Q_flow + Convection_wall3_inner.Q_flow
 */
void OM_Result_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  data->localData[0]->realVars[35] /* Conduction_wall3_inner._Q_flow variable */ = data->localData[0]->realVars[86] /* Radiation_wall3_inner._Q_flow variable */ + data->localData[0]->realVars[57] /* Convection_wall3_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 39
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._dT = DIVISION(Conduction_wall3_inner.Q_flow, Conduction_wall3_inner.G)
 */
void OM_Result_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  data->localData[0]->realVars[36] /* Conduction_wall3_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[35] /* Conduction_wall3_inner._Q_flow variable */,data->simulationInfo->realParameter[9],"Conduction_wall3_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc46(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,46};
  /* iteration variables */
  data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_35(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_36(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_37(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_38(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_39(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */ + (-data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */) - data->localData[0]->realVars[36] /* Conduction_wall3_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS46(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS46(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS46(sysData);
}

void getIterationVarsNLS46(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 48
 type: SIMPLE_ASSIGN
 Radiation_wall1_inner._Q_flow = 5.670367e-08 * Radiation_wall1_inner.Gr * (Conduction_wall1_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[82] /* Radiation_wall1_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[59]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 49
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._dT = Conduction_wall1_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
  data->localData[0]->realVars[54] /* Convection_wall1_inner._dT variable */ = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 50
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._Q_flow = Convection_coef_wall1_inner.k * Convection_wall1_inner.dT
 */
void OM_Result_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
  data->localData[0]->realVars[53] /* Convection_wall1_inner._Q_flow variable */ = (data->simulationInfo->realParameter[16]) * (data->localData[0]->realVars[54] /* Convection_wall1_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 51
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._Q_flow = Radiation_wall1_inner.Q_flow + Convection_wall1_inner.Q_flow
 */
void OM_Result_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
  data->localData[0]->realVars[29] /* Conduction_wall1_inner._Q_flow variable */ = data->localData[0]->realVars[82] /* Radiation_wall1_inner._Q_flow variable */ + data->localData[0]->realVars[53] /* Convection_wall1_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 52
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._dT = DIVISION(Conduction_wall1_inner.Q_flow, Conduction_wall1_inner.G)
 */
void OM_Result_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
  data->localData[0]->realVars[30] /* Conduction_wall1_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[29] /* Conduction_wall1_inner._Q_flow variable */,data->simulationInfo->realParameter[7],"Conduction_wall1_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc59(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,59};
  /* iteration variables */
  data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_48(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_49(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_50(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_51(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_52(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */ + (-data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */) - data->localData[0]->realVars[30] /* Conduction_wall1_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS59(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS59(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS59(sysData);
}

void getIterationVarsNLS59(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 61
 type: SIMPLE_ASSIGN
 Radiation_roof_inner._Q_flow = 5.670367e-08 * Radiation_roof_inner.Gr * (Conduction_roof_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_61(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,61};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[76] /* Radiation_roof_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[56]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 62
 type: SIMPLE_ASSIGN
 Radiation_roof_to_floor._Q_flow = 5.670367e-08 * Radiation_roof_to_floor.Gr * (Conduction_roof_inner.port_b.T ^ 4.0 - Floor_temperature.k ^ 4.0)
 */
void OM_Result_eqFunction_62(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->simulationInfo->realParameter[49];
  tmp1 *= tmp1;
  data->localData[0]->realVars[80] /* Radiation_roof_to_floor._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[58]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 63
 type: SIMPLE_ASSIGN
 Convection_roof_inner._dT = Conduction_roof_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_63(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,63};
  data->localData[0]->realVars[50] /* Convection_roof_inner._dT variable */ = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 64
 type: SIMPLE_ASSIGN
 Convection_roof_inner._Q_flow = Convection_coef_roof_inner.k * Convection_roof_inner.dT
 */
void OM_Result_eqFunction_64(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,64};
  data->localData[0]->realVars[49] /* Convection_roof_inner._Q_flow variable */ = (data->simulationInfo->realParameter[14]) * (data->localData[0]->realVars[50] /* Convection_roof_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 65
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._Q_flow = Radiation_roof_to_floor.Q_flow - ((-Convection_roof_inner.Q_flow) - Radiation_roof_inner.Q_flow)
 */
void OM_Result_eqFunction_65(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
  data->localData[0]->realVars[23] /* Conduction_roof_inner._Q_flow variable */ = data->localData[0]->realVars[80] /* Radiation_roof_to_floor._Q_flow variable */ - ((-data->localData[0]->realVars[49] /* Convection_roof_inner._Q_flow variable */) - data->localData[0]->realVars[76] /* Radiation_roof_inner._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 66
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._dT = DIVISION(Conduction_roof_inner.Q_flow, Conduction_roof_inner.G)
 */
void OM_Result_eqFunction_66(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,66};
  data->localData[0]->realVars[24] /* Conduction_roof_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[23] /* Conduction_roof_inner._Q_flow variable */,data->simulationInfo->realParameter[5],"Conduction_roof_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc74(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,74};
  /* iteration variables */
  data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_61(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_62(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_63(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_64(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_65(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_66(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */ + (-data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */) - data->localData[0]->realVars[24] /* Conduction_roof_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS74(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS74(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_roof_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS74(sysData);
}

void getIterationVarsNLS74(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 92
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._Q_flow = 5.670367e-08 * Radiation_wall3_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall3_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_92(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,92};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[88] /* Radiation_wall3_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[62]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 93
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall3_outer.port_a.T
 */
void OM_Result_eqFunction_93(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,93};
  data->localData[0]->realVars[60] /* Convection_wall3_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 94
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Q_flow = Convection_coef_wall3_outer.k * Convection_wall3_outer.dT
 */
void OM_Result_eqFunction_94(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,94};
  data->localData[0]->realVars[59] /* Convection_wall3_outer._Q_flow variable */ = (data->simulationInfo->realParameter[19]) * (data->localData[0]->realVars[60] /* Convection_wall3_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 95
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._Q_flow = Radiation_wall3_outer.Q_flow + Convection_wall3_outer.Q_flow
 */
void OM_Result_eqFunction_95(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,95};
  data->localData[0]->realVars[38] /* Conduction_wall3_outer._Q_flow variable */ = data->localData[0]->realVars[88] /* Radiation_wall3_outer._Q_flow variable */ + data->localData[0]->realVars[59] /* Convection_wall3_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 96
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._dT = DIVISION(Conduction_wall3_outer.Q_flow, Conduction_wall3_outer.G)
 */
void OM_Result_eqFunction_96(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,96};
  data->localData[0]->realVars[39] /* Conduction_wall3_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[38] /* Conduction_wall3_outer._Q_flow variable */,data->simulationInfo->realParameter[10],"Conduction_wall3_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc103(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,103};
  /* iteration variables */
  data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_92(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_93(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_94(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_95(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_96(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */ + (-data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */) - data->localData[0]->realVars[39] /* Conduction_wall3_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS103(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS103(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS103(sysData);
}

void getIterationVarsNLS103(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 108
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._Q_flow = 5.670367e-08 * Radiation_wall4_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall4_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_108(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,108};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[92] /* Radiation_wall4_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[64]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 109
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall4_outer.port_a.T
 */
void OM_Result_eqFunction_109(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,109};
  data->localData[0]->realVars[64] /* Convection_wall4_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 110
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Q_flow = Convection_coef_wall4_outer.k * Convection_wall4_outer.dT
 */
void OM_Result_eqFunction_110(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,110};
  data->localData[0]->realVars[63] /* Convection_wall4_outer._Q_flow variable */ = (data->simulationInfo->realParameter[21]) * (data->localData[0]->realVars[64] /* Convection_wall4_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 111
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._Q_flow = Radiation_wall4_outer.Q_flow + Convection_wall4_outer.Q_flow
 */
void OM_Result_eqFunction_111(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,111};
  data->localData[0]->realVars[44] /* Conduction_wall4_outer._Q_flow variable */ = data->localData[0]->realVars[92] /* Radiation_wall4_outer._Q_flow variable */ + data->localData[0]->realVars[63] /* Convection_wall4_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 112
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._dT = DIVISION(Conduction_wall4_outer.Q_flow, Conduction_wall4_outer.G)
 */
void OM_Result_eqFunction_112(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,112};
  data->localData[0]->realVars[45] /* Conduction_wall4_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[44] /* Conduction_wall4_outer._Q_flow variable */,data->simulationInfo->realParameter[12],"Conduction_wall4_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc119(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,119};
  /* iteration variables */
  data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_108(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_109(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_110(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_111(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_112(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */ + (-data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */) - data->localData[0]->realVars[45] /* Conduction_wall4_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS119(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS119(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall4_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS119(sysData);
}

void getIterationVarsNLS119(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 124
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._Q_flow = 5.670367e-08 * Radiation_wall1_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall1_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,124};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[84] /* Radiation_wall1_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[60]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 125
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall1_outer.port_a.T
 */
void OM_Result_eqFunction_125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,125};
  data->localData[0]->realVars[56] /* Convection_wall1_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 126
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Q_flow = Convection_coef_wall1_outer.k * Convection_wall1_outer.dT
 */
void OM_Result_eqFunction_126(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,126};
  data->localData[0]->realVars[55] /* Convection_wall1_outer._Q_flow variable */ = (data->simulationInfo->realParameter[17]) * (data->localData[0]->realVars[56] /* Convection_wall1_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 127
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._Q_flow = Radiation_wall1_outer.Q_flow + Convection_wall1_outer.Q_flow
 */
void OM_Result_eqFunction_127(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,127};
  data->localData[0]->realVars[32] /* Conduction_wall1_outer._Q_flow variable */ = data->localData[0]->realVars[84] /* Radiation_wall1_outer._Q_flow variable */ + data->localData[0]->realVars[55] /* Convection_wall1_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 128
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._dT = DIVISION(Conduction_wall1_outer.Q_flow, Conduction_wall1_outer.G)
 */
void OM_Result_eqFunction_128(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,128};
  data->localData[0]->realVars[33] /* Conduction_wall1_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[32] /* Conduction_wall1_outer._Q_flow variable */,data->simulationInfo->realParameter[8],"Conduction_wall1_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc135(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,135};
  /* iteration variables */
  data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_124(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_125(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_126(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_127(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_128(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */ + (-data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */) - data->localData[0]->realVars[33] /* Conduction_wall1_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS135(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS135(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS135(sysData);
}

void getIterationVarsNLS135(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 140
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._Q_flow = 5.670367e-08 * Radiation_roof_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_roof_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[78] /* Radiation_roof_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[57]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 141
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._port._Q_flow = (-Heatflow_solar_radiation.Q_flow) * (1.0 + Heatflow_solar_radiation.alpha * (Conduction_roof_outer.port_a.T - Heatflow_solar_radiation.T_ref))
 */
void OM_Result_eqFunction_141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,141};
  data->localData[0]->realVars[73] /* Heatflow_solar_radiation._port._Q_flow variable */ = ((-data->localData[0]->realVars[72] /* Heatflow_solar_radiation._Q_flow variable */)) * (1.0 + (data->simulationInfo->realParameter[53]) * (data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ - data->simulationInfo->realParameter[52]));
  TRACE_POP
}
/*
 equation index: 142
 type: SIMPLE_ASSIGN
 Convection_roof_outer._dT = Data_outdoor_temperature.y[1] - Conduction_roof_outer.port_a.T
 */
void OM_Result_eqFunction_142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,142};
  data->localData[0]->realVars[52] /* Convection_roof_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 143
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Q_flow = Convection_coef_roof_outer.k * Convection_roof_outer.dT
 */
void OM_Result_eqFunction_143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,143};
  data->localData[0]->realVars[51] /* Convection_roof_outer._Q_flow variable */ = (data->simulationInfo->realParameter[15]) * (data->localData[0]->realVars[52] /* Convection_roof_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 144
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._Q_flow = Convection_roof_outer.Q_flow - (Heatflow_solar_radiation.port.Q_flow - Radiation_roof_outer.Q_flow)
 */
void OM_Result_eqFunction_144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,144};
  data->localData[0]->realVars[26] /* Conduction_roof_outer._Q_flow variable */ = data->localData[0]->realVars[51] /* Convection_roof_outer._Q_flow variable */ - (data->localData[0]->realVars[73] /* Heatflow_solar_radiation._port._Q_flow variable */ - data->localData[0]->realVars[78] /* Radiation_roof_outer._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 145
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._dT = DIVISION(Conduction_roof_outer.Q_flow, Conduction_roof_outer.G)
 */
void OM_Result_eqFunction_145(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,145};
  data->localData[0]->realVars[27] /* Conduction_roof_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[26] /* Conduction_roof_outer._Q_flow variable */,data->simulationInfo->realParameter[6],"Conduction_roof_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc153(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,153};
  /* iteration variables */
  data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_140(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_141(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_142(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_143(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_144(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_145(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ + (-data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */) - data->localData[0]->realVars[27] /* Conduction_roof_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS153(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS153(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_roof_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS153(sysData);
}

void getIterationVarsNLS153(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
}

/* inner equations */

/*
 equation index: 227
 type: SIMPLE_ASSIGN
 Radiation_wall4_inner._Q_flow = 5.670367e-08 * Radiation_wall4_inner.Gr * (Conduction_wall4_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_227(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,227};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[90] /* Radiation_wall4_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[63]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 228
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._dT = Conduction_wall4_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_228(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,228};
  data->localData[0]->realVars[62] /* Convection_wall4_inner._dT variable */ = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 229
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._Q_flow = Convection_coef_wall4_inner.k * Convection_wall4_inner.dT
 */
void OM_Result_eqFunction_229(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,229};
  data->localData[0]->realVars[61] /* Convection_wall4_inner._Q_flow variable */ = (data->simulationInfo->realParameter[20]) * (data->localData[0]->realVars[62] /* Convection_wall4_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 230
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._Q_flow = Radiation_wall4_inner.Q_flow + Convection_wall4_inner.Q_flow
 */
void OM_Result_eqFunction_230(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,230};
  data->localData[0]->realVars[41] /* Conduction_wall4_inner._Q_flow variable */ = data->localData[0]->realVars[90] /* Radiation_wall4_inner._Q_flow variable */ + data->localData[0]->realVars[61] /* Convection_wall4_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 231
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._dT = DIVISION(Conduction_wall4_inner.Q_flow, Conduction_wall4_inner.G)
 */
void OM_Result_eqFunction_231(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,231};
  data->localData[0]->realVars[42] /* Conduction_wall4_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[41] /* Conduction_wall4_inner._Q_flow variable */,data->simulationInfo->realParameter[11],"Conduction_wall4_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc238(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,238};
  /* iteration variables */
  data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_227(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_228(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_229(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_230(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_231(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */ + (-data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */) - data->localData[0]->realVars[42] /* Conduction_wall4_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS238(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS238(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall4_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS238(sysData);
}

void getIterationVarsNLS238(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 240
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._Q_flow = 5.670367e-08 * Radiation_wall4_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall4_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_240(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,240};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[92] /* Radiation_wall4_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[64]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 241
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall4_outer.port_a.T
 */
void OM_Result_eqFunction_241(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,241};
  data->localData[0]->realVars[64] /* Convection_wall4_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 242
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Q_flow = Convection_coef_wall4_outer.k * Convection_wall4_outer.dT
 */
void OM_Result_eqFunction_242(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,242};
  data->localData[0]->realVars[63] /* Convection_wall4_outer._Q_flow variable */ = (data->simulationInfo->realParameter[21]) * (data->localData[0]->realVars[64] /* Convection_wall4_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 243
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._Q_flow = Radiation_wall4_outer.Q_flow + Convection_wall4_outer.Q_flow
 */
void OM_Result_eqFunction_243(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,243};
  data->localData[0]->realVars[44] /* Conduction_wall4_outer._Q_flow variable */ = data->localData[0]->realVars[92] /* Radiation_wall4_outer._Q_flow variable */ + data->localData[0]->realVars[63] /* Convection_wall4_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 244
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._dT = DIVISION(Conduction_wall4_outer.Q_flow, Conduction_wall4_outer.G)
 */
void OM_Result_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
  data->localData[0]->realVars[45] /* Conduction_wall4_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[44] /* Conduction_wall4_outer._Q_flow variable */,data->simulationInfo->realParameter[12],"Conduction_wall4_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc251(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,251};
  /* iteration variables */
  data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_240(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_241(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_242(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_243(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_244(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */ + (-data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */) - data->localData[0]->realVars[45] /* Conduction_wall4_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS251(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS251(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall4_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS251(sysData);
}

void getIterationVarsNLS251(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 256
 type: SIMPLE_ASSIGN
 Radiation_wall3_inner._Q_flow = 5.670367e-08 * Radiation_wall3_inner.Gr * (Conduction_wall3_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_256(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,256};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[86] /* Radiation_wall3_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[61]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 257
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._dT = Capacitor_wall3.T - Conduction_wall3_inner.port_b.T
 */
void OM_Result_eqFunction_257(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,257};
  data->localData[0]->realVars[36] /* Conduction_wall3_inner._dT variable */ = data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */ - data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
  TRACE_POP
}
/*
 equation index: 258
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._Q_flow = Conduction_wall3_inner.G * Conduction_wall3_inner.dT
 */
void OM_Result_eqFunction_258(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,258};
  data->localData[0]->realVars[35] /* Conduction_wall3_inner._Q_flow variable */ = (data->simulationInfo->realParameter[9]) * (data->localData[0]->realVars[36] /* Conduction_wall3_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 259
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._Q_flow = Conduction_wall3_inner.Q_flow - Radiation_wall3_inner.Q_flow
 */
void OM_Result_eqFunction_259(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,259};
  data->localData[0]->realVars[57] /* Convection_wall3_inner._Q_flow variable */ = data->localData[0]->realVars[35] /* Conduction_wall3_inner._Q_flow variable */ - data->localData[0]->realVars[86] /* Radiation_wall3_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 260
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._dT = DIVISION(Convection_wall3_inner.Q_flow, Convection_coef_wall3_inner.k)
 */
void OM_Result_eqFunction_260(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,260};
  data->localData[0]->realVars[58] /* Convection_wall3_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[57] /* Convection_wall3_inner._Q_flow variable */,data->simulationInfo->realParameter[18],"Convection_coef_wall3_inner.k",equationIndexes);
  TRACE_POP
}

void residualFunc267(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,267};
  /* iteration variables */
  data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_256(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_257(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_258(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_259(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_260(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */ + (-data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */) - data->localData[0]->realVars[58] /* Convection_wall3_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS267(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS267(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS267(sysData);
}

void getIterationVarsNLS267(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 269
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._Q_flow = 5.670367e-08 * Radiation_wall3_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall3_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_269(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,269};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[88] /* Radiation_wall3_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[62]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 270
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall3_outer.port_a.T
 */
void OM_Result_eqFunction_270(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,270};
  data->localData[0]->realVars[60] /* Convection_wall3_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 271
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Q_flow = Convection_coef_wall3_outer.k * Convection_wall3_outer.dT
 */
void OM_Result_eqFunction_271(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,271};
  data->localData[0]->realVars[59] /* Convection_wall3_outer._Q_flow variable */ = (data->simulationInfo->realParameter[19]) * (data->localData[0]->realVars[60] /* Convection_wall3_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 272
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._Q_flow = Radiation_wall3_outer.Q_flow + Convection_wall3_outer.Q_flow
 */
void OM_Result_eqFunction_272(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,272};
  data->localData[0]->realVars[38] /* Conduction_wall3_outer._Q_flow variable */ = data->localData[0]->realVars[88] /* Radiation_wall3_outer._Q_flow variable */ + data->localData[0]->realVars[59] /* Convection_wall3_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 273
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._dT = DIVISION(Conduction_wall3_outer.Q_flow, Conduction_wall3_outer.G)
 */
void OM_Result_eqFunction_273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,273};
  data->localData[0]->realVars[39] /* Conduction_wall3_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[38] /* Conduction_wall3_outer._Q_flow variable */,data->simulationInfo->realParameter[10],"Conduction_wall3_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc280(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,280};
  /* iteration variables */
  data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_269(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_270(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_271(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_272(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_273(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */ + (-data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */) - data->localData[0]->realVars[39] /* Conduction_wall3_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS280(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS280(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS280(sysData);
}

void getIterationVarsNLS280(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 285
 type: SIMPLE_ASSIGN
 Radiation_roof_to_floor._Q_flow = 5.670367e-08 * Radiation_roof_to_floor.Gr * (Conduction_roof_inner.port_b.T ^ 4.0 - Floor_temperature.k ^ 4.0)
 */
void OM_Result_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,285};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->simulationInfo->realParameter[49];
  tmp1 *= tmp1;
  data->localData[0]->realVars[80] /* Radiation_roof_to_floor._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[58]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 286
 type: SIMPLE_ASSIGN
 Radiation_roof_inner._Q_flow = 5.670367e-08 * Radiation_roof_inner.Gr * (Conduction_roof_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,286};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[76] /* Radiation_roof_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[56]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 287
 type: SIMPLE_ASSIGN
 Convection_roof_inner._dT = Conduction_roof_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
  data->localData[0]->realVars[50] /* Convection_roof_inner._dT variable */ = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 288
 type: SIMPLE_ASSIGN
 Convection_roof_inner._Q_flow = Convection_coef_roof_inner.k * Convection_roof_inner.dT
 */
void OM_Result_eqFunction_288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,288};
  data->localData[0]->realVars[49] /* Convection_roof_inner._Q_flow variable */ = (data->simulationInfo->realParameter[14]) * (data->localData[0]->realVars[50] /* Convection_roof_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 289
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._Q_flow = Radiation_roof_to_floor.Q_flow - ((-Convection_roof_inner.Q_flow) - Radiation_roof_inner.Q_flow)
 */
void OM_Result_eqFunction_289(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,289};
  data->localData[0]->realVars[23] /* Conduction_roof_inner._Q_flow variable */ = data->localData[0]->realVars[80] /* Radiation_roof_to_floor._Q_flow variable */ - ((-data->localData[0]->realVars[49] /* Convection_roof_inner._Q_flow variable */) - data->localData[0]->realVars[76] /* Radiation_roof_inner._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 290
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._dT = DIVISION(Conduction_roof_inner.Q_flow, Conduction_roof_inner.G)
 */
void OM_Result_eqFunction_290(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,290};
  data->localData[0]->realVars[24] /* Conduction_roof_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[23] /* Conduction_roof_inner._Q_flow variable */,data->simulationInfo->realParameter[5],"Conduction_roof_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc298(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,298};
  /* iteration variables */
  data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_285(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_286(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_287(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_288(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_289(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_290(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */ + (-data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */) - data->localData[0]->realVars[24] /* Conduction_roof_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS298(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS298(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_roof_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS298(sysData);
}

void getIterationVarsNLS298(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 302
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._Q_flow = 5.670367e-08 * Radiation_roof_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_roof_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,302};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[78] /* Radiation_roof_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[57]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 303
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._port._Q_flow = (-Heatflow_solar_radiation.Q_flow) * (1.0 + Heatflow_solar_radiation.alpha * (Conduction_roof_outer.port_a.T - Heatflow_solar_radiation.T_ref))
 */
void OM_Result_eqFunction_303(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,303};
  data->localData[0]->realVars[73] /* Heatflow_solar_radiation._port._Q_flow variable */ = ((-data->localData[0]->realVars[72] /* Heatflow_solar_radiation._Q_flow variable */)) * (1.0 + (data->simulationInfo->realParameter[53]) * (data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ - data->simulationInfo->realParameter[52]));
  TRACE_POP
}
/*
 equation index: 304
 type: SIMPLE_ASSIGN
 Convection_roof_outer._dT = Data_outdoor_temperature.y[1] - Conduction_roof_outer.port_a.T
 */
void OM_Result_eqFunction_304(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,304};
  data->localData[0]->realVars[52] /* Convection_roof_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 305
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Q_flow = Convection_coef_roof_outer.k * Convection_roof_outer.dT
 */
void OM_Result_eqFunction_305(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,305};
  data->localData[0]->realVars[51] /* Convection_roof_outer._Q_flow variable */ = (data->simulationInfo->realParameter[15]) * (data->localData[0]->realVars[52] /* Convection_roof_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 306
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._Q_flow = Convection_roof_outer.Q_flow - (Heatflow_solar_radiation.port.Q_flow - Radiation_roof_outer.Q_flow)
 */
void OM_Result_eqFunction_306(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,306};
  data->localData[0]->realVars[26] /* Conduction_roof_outer._Q_flow variable */ = data->localData[0]->realVars[51] /* Convection_roof_outer._Q_flow variable */ - (data->localData[0]->realVars[73] /* Heatflow_solar_radiation._port._Q_flow variable */ - data->localData[0]->realVars[78] /* Radiation_roof_outer._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 307
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._dT = DIVISION(Conduction_roof_outer.Q_flow, Conduction_roof_outer.G)
 */
void OM_Result_eqFunction_307(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,307};
  data->localData[0]->realVars[27] /* Conduction_roof_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[26] /* Conduction_roof_outer._Q_flow variable */,data->simulationInfo->realParameter[6],"Conduction_roof_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc315(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,315};
  /* iteration variables */
  data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_302(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_303(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_304(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_305(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_306(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_307(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ + (-data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */) - data->localData[0]->realVars[27] /* Conduction_roof_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS315(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS315(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_roof_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS315(sysData);
}

void getIterationVarsNLS315(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 320
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._Q_flow = 5.670367e-08 * Radiation_wall1_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall1_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_320(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,320};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[84] /* Radiation_wall1_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[60]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 321
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall1_outer.port_a.T
 */
void OM_Result_eqFunction_321(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,321};
  data->localData[0]->realVars[56] /* Convection_wall1_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 322
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Q_flow = Convection_coef_wall1_outer.k * Convection_wall1_outer.dT
 */
void OM_Result_eqFunction_322(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,322};
  data->localData[0]->realVars[55] /* Convection_wall1_outer._Q_flow variable */ = (data->simulationInfo->realParameter[17]) * (data->localData[0]->realVars[56] /* Convection_wall1_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 323
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._Q_flow = Radiation_wall1_outer.Q_flow + Convection_wall1_outer.Q_flow
 */
void OM_Result_eqFunction_323(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,323};
  data->localData[0]->realVars[32] /* Conduction_wall1_outer._Q_flow variable */ = data->localData[0]->realVars[84] /* Radiation_wall1_outer._Q_flow variable */ + data->localData[0]->realVars[55] /* Convection_wall1_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 324
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._dT = DIVISION(Conduction_wall1_outer.Q_flow, Conduction_wall1_outer.G)
 */
void OM_Result_eqFunction_324(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,324};
  data->localData[0]->realVars[33] /* Conduction_wall1_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[32] /* Conduction_wall1_outer._Q_flow variable */,data->simulationInfo->realParameter[8],"Conduction_wall1_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc331(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,331};
  /* iteration variables */
  data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_320(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_321(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_322(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_323(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_324(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */ + (-data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */) - data->localData[0]->realVars[33] /* Conduction_wall1_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS331(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS331(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS331(sysData);
}

void getIterationVarsNLS331(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 334
 type: SIMPLE_ASSIGN
 Radiation_wall1_inner._Q_flow = 5.670367e-08 * Radiation_wall1_inner.Gr * (Conduction_wall1_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_334(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,334};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[82] /* Radiation_wall1_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[59]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 335
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._dT = Conduction_wall1_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_335(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,335};
  data->localData[0]->realVars[54] /* Convection_wall1_inner._dT variable */ = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 336
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._Q_flow = Convection_coef_wall1_inner.k * Convection_wall1_inner.dT
 */
void OM_Result_eqFunction_336(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,336};
  data->localData[0]->realVars[53] /* Convection_wall1_inner._Q_flow variable */ = (data->simulationInfo->realParameter[16]) * (data->localData[0]->realVars[54] /* Convection_wall1_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 337
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._Q_flow = Radiation_wall1_inner.Q_flow + Convection_wall1_inner.Q_flow
 */
void OM_Result_eqFunction_337(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,337};
  data->localData[0]->realVars[29] /* Conduction_wall1_inner._Q_flow variable */ = data->localData[0]->realVars[82] /* Radiation_wall1_inner._Q_flow variable */ + data->localData[0]->realVars[53] /* Convection_wall1_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 338
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._dT = DIVISION(Conduction_wall1_inner.Q_flow, Conduction_wall1_inner.G)
 */
void OM_Result_eqFunction_338(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,338};
  data->localData[0]->realVars[30] /* Conduction_wall1_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[29] /* Conduction_wall1_inner._Q_flow variable */,data->simulationInfo->realParameter[7],"Conduction_wall1_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc345(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,345};
  /* iteration variables */
  data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_334(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_335(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_336(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_337(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_338(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */ + (-data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */) - data->localData[0]->realVars[30] /* Conduction_wall1_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS345(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS345(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS345(sysData);
}

void getIterationVarsNLS345(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */;
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize non-linear systems */
void OM_Result_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA* nonLinearSystemData)
{
  
  nonLinearSystemData[0].equationIndex = 33;
  nonLinearSystemData[0].size = 1;
  nonLinearSystemData[0].homotopySupport = 0;
  nonLinearSystemData[0].mixedSystem = 0;
  nonLinearSystemData[0].residualFunc = residualFunc33;
  nonLinearSystemData[0].strictTearingFunctionCall = NULL;
  nonLinearSystemData[0].analyticalJacobianColumn = OM_Result_functionJacNLSJac0_column;
  nonLinearSystemData[0].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac0;
  nonLinearSystemData[0].jacobianIndex = 0;
  nonLinearSystemData[0].initializeStaticNLSData = initializeStaticDataNLS33;
  nonLinearSystemData[0].getIterationVars = getIterationVarsNLS33;
  nonLinearSystemData[0].checkConstraints = NULL;
  
  
  nonLinearSystemData[1].equationIndex = 46;
  nonLinearSystemData[1].size = 1;
  nonLinearSystemData[1].homotopySupport = 0;
  nonLinearSystemData[1].mixedSystem = 0;
  nonLinearSystemData[1].residualFunc = residualFunc46;
  nonLinearSystemData[1].strictTearingFunctionCall = NULL;
  nonLinearSystemData[1].analyticalJacobianColumn = OM_Result_functionJacNLSJac1_column;
  nonLinearSystemData[1].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac1;
  nonLinearSystemData[1].jacobianIndex = 1;
  nonLinearSystemData[1].initializeStaticNLSData = initializeStaticDataNLS46;
  nonLinearSystemData[1].getIterationVars = getIterationVarsNLS46;
  nonLinearSystemData[1].checkConstraints = NULL;
  
  
  nonLinearSystemData[2].equationIndex = 59;
  nonLinearSystemData[2].size = 1;
  nonLinearSystemData[2].homotopySupport = 0;
  nonLinearSystemData[2].mixedSystem = 0;
  nonLinearSystemData[2].residualFunc = residualFunc59;
  nonLinearSystemData[2].strictTearingFunctionCall = NULL;
  nonLinearSystemData[2].analyticalJacobianColumn = OM_Result_functionJacNLSJac2_column;
  nonLinearSystemData[2].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac2;
  nonLinearSystemData[2].jacobianIndex = 2;
  nonLinearSystemData[2].initializeStaticNLSData = initializeStaticDataNLS59;
  nonLinearSystemData[2].getIterationVars = getIterationVarsNLS59;
  nonLinearSystemData[2].checkConstraints = NULL;
  
  
  nonLinearSystemData[3].equationIndex = 74;
  nonLinearSystemData[3].size = 1;
  nonLinearSystemData[3].homotopySupport = 0;
  nonLinearSystemData[3].mixedSystem = 0;
  nonLinearSystemData[3].residualFunc = residualFunc74;
  nonLinearSystemData[3].strictTearingFunctionCall = NULL;
  nonLinearSystemData[3].analyticalJacobianColumn = OM_Result_functionJacNLSJac3_column;
  nonLinearSystemData[3].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac3;
  nonLinearSystemData[3].jacobianIndex = 3;
  nonLinearSystemData[3].initializeStaticNLSData = initializeStaticDataNLS74;
  nonLinearSystemData[3].getIterationVars = getIterationVarsNLS74;
  nonLinearSystemData[3].checkConstraints = NULL;
  
  
  nonLinearSystemData[4].equationIndex = 103;
  nonLinearSystemData[4].size = 1;
  nonLinearSystemData[4].homotopySupport = 0;
  nonLinearSystemData[4].mixedSystem = 0;
  nonLinearSystemData[4].residualFunc = residualFunc103;
  nonLinearSystemData[4].strictTearingFunctionCall = NULL;
  nonLinearSystemData[4].analyticalJacobianColumn = OM_Result_functionJacNLSJac4_column;
  nonLinearSystemData[4].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac4;
  nonLinearSystemData[4].jacobianIndex = 4;
  nonLinearSystemData[4].initializeStaticNLSData = initializeStaticDataNLS103;
  nonLinearSystemData[4].getIterationVars = getIterationVarsNLS103;
  nonLinearSystemData[4].checkConstraints = NULL;
  
  
  nonLinearSystemData[5].equationIndex = 119;
  nonLinearSystemData[5].size = 1;
  nonLinearSystemData[5].homotopySupport = 0;
  nonLinearSystemData[5].mixedSystem = 0;
  nonLinearSystemData[5].residualFunc = residualFunc119;
  nonLinearSystemData[5].strictTearingFunctionCall = NULL;
  nonLinearSystemData[5].analyticalJacobianColumn = OM_Result_functionJacNLSJac5_column;
  nonLinearSystemData[5].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac5;
  nonLinearSystemData[5].jacobianIndex = 5;
  nonLinearSystemData[5].initializeStaticNLSData = initializeStaticDataNLS119;
  nonLinearSystemData[5].getIterationVars = getIterationVarsNLS119;
  nonLinearSystemData[5].checkConstraints = NULL;
  
  
  nonLinearSystemData[6].equationIndex = 135;
  nonLinearSystemData[6].size = 1;
  nonLinearSystemData[6].homotopySupport = 0;
  nonLinearSystemData[6].mixedSystem = 0;
  nonLinearSystemData[6].residualFunc = residualFunc135;
  nonLinearSystemData[6].strictTearingFunctionCall = NULL;
  nonLinearSystemData[6].analyticalJacobianColumn = OM_Result_functionJacNLSJac6_column;
  nonLinearSystemData[6].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac6;
  nonLinearSystemData[6].jacobianIndex = 6;
  nonLinearSystemData[6].initializeStaticNLSData = initializeStaticDataNLS135;
  nonLinearSystemData[6].getIterationVars = getIterationVarsNLS135;
  nonLinearSystemData[6].checkConstraints = NULL;
  
  
  nonLinearSystemData[7].equationIndex = 153;
  nonLinearSystemData[7].size = 1;
  nonLinearSystemData[7].homotopySupport = 0;
  nonLinearSystemData[7].mixedSystem = 0;
  nonLinearSystemData[7].residualFunc = residualFunc153;
  nonLinearSystemData[7].strictTearingFunctionCall = NULL;
  nonLinearSystemData[7].analyticalJacobianColumn = OM_Result_functionJacNLSJac7_column;
  nonLinearSystemData[7].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac7;
  nonLinearSystemData[7].jacobianIndex = 7;
  nonLinearSystemData[7].initializeStaticNLSData = initializeStaticDataNLS153;
  nonLinearSystemData[7].getIterationVars = getIterationVarsNLS153;
  nonLinearSystemData[7].checkConstraints = NULL;
  
  nonLinearSystemData[8].equationIndex = 238;
  nonLinearSystemData[8].size = 1;
  nonLinearSystemData[8].homotopySupport = 0;
  nonLinearSystemData[8].mixedSystem = 0;
  nonLinearSystemData[8].residualFunc = residualFunc238;
  nonLinearSystemData[8].strictTearingFunctionCall = NULL;
  nonLinearSystemData[8].analyticalJacobianColumn = OM_Result_functionJacNLSJac8_column;
  nonLinearSystemData[8].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac8;
  nonLinearSystemData[8].jacobianIndex = 8;
  nonLinearSystemData[8].initializeStaticNLSData = initializeStaticDataNLS238;
  nonLinearSystemData[8].getIterationVars = getIterationVarsNLS238;
  nonLinearSystemData[8].checkConstraints = NULL;
  
  
  nonLinearSystemData[9].equationIndex = 251;
  nonLinearSystemData[9].size = 1;
  nonLinearSystemData[9].homotopySupport = 0;
  nonLinearSystemData[9].mixedSystem = 0;
  nonLinearSystemData[9].residualFunc = residualFunc251;
  nonLinearSystemData[9].strictTearingFunctionCall = NULL;
  nonLinearSystemData[9].analyticalJacobianColumn = OM_Result_functionJacNLSJac9_column;
  nonLinearSystemData[9].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac9;
  nonLinearSystemData[9].jacobianIndex = 9;
  nonLinearSystemData[9].initializeStaticNLSData = initializeStaticDataNLS251;
  nonLinearSystemData[9].getIterationVars = getIterationVarsNLS251;
  nonLinearSystemData[9].checkConstraints = NULL;
  
  
  nonLinearSystemData[10].equationIndex = 267;
  nonLinearSystemData[10].size = 1;
  nonLinearSystemData[10].homotopySupport = 0;
  nonLinearSystemData[10].mixedSystem = 0;
  nonLinearSystemData[10].residualFunc = residualFunc267;
  nonLinearSystemData[10].strictTearingFunctionCall = NULL;
  nonLinearSystemData[10].analyticalJacobianColumn = OM_Result_functionJacNLSJac10_column;
  nonLinearSystemData[10].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac10;
  nonLinearSystemData[10].jacobianIndex = 10;
  nonLinearSystemData[10].initializeStaticNLSData = initializeStaticDataNLS267;
  nonLinearSystemData[10].getIterationVars = getIterationVarsNLS267;
  nonLinearSystemData[10].checkConstraints = NULL;
  
  
  nonLinearSystemData[11].equationIndex = 280;
  nonLinearSystemData[11].size = 1;
  nonLinearSystemData[11].homotopySupport = 0;
  nonLinearSystemData[11].mixedSystem = 0;
  nonLinearSystemData[11].residualFunc = residualFunc280;
  nonLinearSystemData[11].strictTearingFunctionCall = NULL;
  nonLinearSystemData[11].analyticalJacobianColumn = OM_Result_functionJacNLSJac11_column;
  nonLinearSystemData[11].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac11;
  nonLinearSystemData[11].jacobianIndex = 11;
  nonLinearSystemData[11].initializeStaticNLSData = initializeStaticDataNLS280;
  nonLinearSystemData[11].getIterationVars = getIterationVarsNLS280;
  nonLinearSystemData[11].checkConstraints = NULL;
  
  
  nonLinearSystemData[12].equationIndex = 298;
  nonLinearSystemData[12].size = 1;
  nonLinearSystemData[12].homotopySupport = 0;
  nonLinearSystemData[12].mixedSystem = 0;
  nonLinearSystemData[12].residualFunc = residualFunc298;
  nonLinearSystemData[12].strictTearingFunctionCall = NULL;
  nonLinearSystemData[12].analyticalJacobianColumn = OM_Result_functionJacNLSJac12_column;
  nonLinearSystemData[12].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac12;
  nonLinearSystemData[12].jacobianIndex = 12;
  nonLinearSystemData[12].initializeStaticNLSData = initializeStaticDataNLS298;
  nonLinearSystemData[12].getIterationVars = getIterationVarsNLS298;
  nonLinearSystemData[12].checkConstraints = NULL;
  
  
  nonLinearSystemData[13].equationIndex = 315;
  nonLinearSystemData[13].size = 1;
  nonLinearSystemData[13].homotopySupport = 0;
  nonLinearSystemData[13].mixedSystem = 0;
  nonLinearSystemData[13].residualFunc = residualFunc315;
  nonLinearSystemData[13].strictTearingFunctionCall = NULL;
  nonLinearSystemData[13].analyticalJacobianColumn = OM_Result_functionJacNLSJac13_column;
  nonLinearSystemData[13].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac13;
  nonLinearSystemData[13].jacobianIndex = 13;
  nonLinearSystemData[13].initializeStaticNLSData = initializeStaticDataNLS315;
  nonLinearSystemData[13].getIterationVars = getIterationVarsNLS315;
  nonLinearSystemData[13].checkConstraints = NULL;
  
  
  nonLinearSystemData[14].equationIndex = 331;
  nonLinearSystemData[14].size = 1;
  nonLinearSystemData[14].homotopySupport = 0;
  nonLinearSystemData[14].mixedSystem = 0;
  nonLinearSystemData[14].residualFunc = residualFunc331;
  nonLinearSystemData[14].strictTearingFunctionCall = NULL;
  nonLinearSystemData[14].analyticalJacobianColumn = OM_Result_functionJacNLSJac14_column;
  nonLinearSystemData[14].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac14;
  nonLinearSystemData[14].jacobianIndex = 14;
  nonLinearSystemData[14].initializeStaticNLSData = initializeStaticDataNLS331;
  nonLinearSystemData[14].getIterationVars = getIterationVarsNLS331;
  nonLinearSystemData[14].checkConstraints = NULL;
  
  
  nonLinearSystemData[15].equationIndex = 345;
  nonLinearSystemData[15].size = 1;
  nonLinearSystemData[15].homotopySupport = 0;
  nonLinearSystemData[15].mixedSystem = 0;
  nonLinearSystemData[15].residualFunc = residualFunc345;
  nonLinearSystemData[15].strictTearingFunctionCall = NULL;
  nonLinearSystemData[15].analyticalJacobianColumn = OM_Result_functionJacNLSJac15_column;
  nonLinearSystemData[15].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac15;
  nonLinearSystemData[15].jacobianIndex = 15;
  nonLinearSystemData[15].initializeStaticNLSData = initializeStaticDataNLS345;
  nonLinearSystemData[15].getIterationVars = getIterationVarsNLS345;
  nonLinearSystemData[15].checkConstraints = NULL;
}

#if defined(__cplusplus)
}
#endif

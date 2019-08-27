/* Non Linear Systems */
#include "OM_Result_model.h"
#include "OM_Result_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* inner equations */

/*
 equation index: 21
 type: SIMPLE_ASSIGN
 Radiation_wall4_inner._Q_flow = 5.670367e-08 * Radiation_wall4_inner.Gr * (Conduction_wall4_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[96] /* Radiation_wall4_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[67]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 22
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._dT = Conduction_wall4_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  data->localData[0]->realVars[65] /* Convection_wall4_inner._dT variable */ = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 23
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._Q_flow = Convection_coef_wall4_inner.k * Convection_wall4_inner.dT
 */
void OM_Result_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  data->localData[0]->realVars[64] /* Convection_wall4_inner._Q_flow variable */ = (data->simulationInfo->realParameter[23]) * (data->localData[0]->realVars[65] /* Convection_wall4_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 24
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._Q_flow = Radiation_wall4_inner.Q_flow + Convection_wall4_inner.Q_flow
 */
void OM_Result_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  data->localData[0]->realVars[41] /* Conduction_wall4_inner._Q_flow variable */ = data->localData[0]->realVars[96] /* Radiation_wall4_inner._Q_flow variable */ + data->localData[0]->realVars[64] /* Convection_wall4_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 25
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._dT = DIVISION(Conduction_wall4_inner.Q_flow, Conduction_wall4_inner.G)
 */
void OM_Result_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  data->localData[0]->realVars[42] /* Conduction_wall4_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[41] /* Conduction_wall4_inner._Q_flow variable */,data->simulationInfo->realParameter[15],"Conduction_wall4_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc32(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,32};
  /* iteration variables */
  data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_21(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_22(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_23(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_24(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_25(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */ + (-data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */) - data->localData[0]->realVars[42] /* Conduction_wall4_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS32(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS32(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall4_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS32(sysData);
}

void getIterationVarsNLS32(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 34
 type: SIMPLE_ASSIGN
 Radiation_wall3_inner._Q_flow = 5.670367e-08 * Radiation_wall3_inner.Gr * (Conduction_wall3_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[92] /* Radiation_wall3_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[65]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 35
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._dT = Conduction_wall3_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  data->localData[0]->realVars[60] /* Convection_wall3_inner._dT variable */ = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 36
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._Q_flow = Convection_coef_wall3_inner.k * Convection_wall3_inner.dT
 */
void OM_Result_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  data->localData[0]->realVars[59] /* Convection_wall3_inner._Q_flow variable */ = (data->simulationInfo->realParameter[22]) * (data->localData[0]->realVars[60] /* Convection_wall3_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 37
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._Q_flow = Radiation_wall3_inner.Q_flow + Convection_wall3_inner.Q_flow
 */
void OM_Result_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  data->localData[0]->realVars[35] /* Conduction_wall3_inner._Q_flow variable */ = data->localData[0]->realVars[92] /* Radiation_wall3_inner._Q_flow variable */ + data->localData[0]->realVars[59] /* Convection_wall3_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 38
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._dT = DIVISION(Conduction_wall3_inner.Q_flow, Conduction_wall3_inner.G)
 */
void OM_Result_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  data->localData[0]->realVars[36] /* Conduction_wall3_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[35] /* Conduction_wall3_inner._Q_flow variable */,data->simulationInfo->realParameter[13],"Conduction_wall3_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc45(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,45};
  /* iteration variables */
  data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_34(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_35(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_36(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_37(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_38(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */ + (-data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */) - data->localData[0]->realVars[36] /* Conduction_wall3_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS45(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS45(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS45(sysData);
}

void getIterationVarsNLS45(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 47
 type: SIMPLE_ASSIGN
 Radiation_wall1_inner._Q_flow = 5.670367e-08 * Radiation_wall1_inner.Gr * (Conduction_wall1_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[88] /* Radiation_wall1_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[63]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 48
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._dT = Conduction_wall1_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
  data->localData[0]->realVars[55] /* Convection_wall1_inner._dT variable */ = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 49
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._Q_flow = Convection_coef_wall1_inner.k * Convection_wall1_inner.dT
 */
void OM_Result_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
  data->localData[0]->realVars[54] /* Convection_wall1_inner._Q_flow variable */ = (data->simulationInfo->realParameter[21]) * (data->localData[0]->realVars[55] /* Convection_wall1_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 50
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._Q_flow = Radiation_wall1_inner.Q_flow + Convection_wall1_inner.Q_flow
 */
void OM_Result_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
  data->localData[0]->realVars[29] /* Conduction_wall1_inner._Q_flow variable */ = data->localData[0]->realVars[88] /* Radiation_wall1_inner._Q_flow variable */ + data->localData[0]->realVars[54] /* Convection_wall1_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 51
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._dT = DIVISION(Conduction_wall1_inner.Q_flow, Conduction_wall1_inner.G)
 */
void OM_Result_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
  data->localData[0]->realVars[30] /* Conduction_wall1_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[29] /* Conduction_wall1_inner._Q_flow variable */,data->simulationInfo->realParameter[11],"Conduction_wall1_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc58(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,58};
  /* iteration variables */
  data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_47(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_48(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_49(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_50(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_51(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */ + (-data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */) - data->localData[0]->realVars[30] /* Conduction_wall1_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS58(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS58(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS58(sysData);
}

void getIterationVarsNLS58(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 60
 type: SIMPLE_ASSIGN
 Radiation_roof_inner._Q_flow = 5.670367e-08 * Radiation_roof_inner.Gr * (Conduction_roof_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_60(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,60};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[82] /* Radiation_roof_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[60]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 61
 type: SIMPLE_ASSIGN
 Radiation_roof_to_floor._Q_flow = 5.670367e-08 * Radiation_roof_to_floor.Gr * (Conduction_roof_inner.port_b.T ^ 4.0 - Floor_temperature.k ^ 4.0)
 */
void OM_Result_eqFunction_61(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,61};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->simulationInfo->realParameter[51];
  tmp1 *= tmp1;
  data->localData[0]->realVars[86] /* Radiation_roof_to_floor._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[62]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 62
 type: SIMPLE_ASSIGN
 Convection_roof_inner._dT = Conduction_roof_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_62(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
  data->localData[0]->realVars[50] /* Convection_roof_inner._dT variable */ = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 63
 type: SIMPLE_ASSIGN
 Convection_roof_inner._Q_flow = Convection_coef_roof_inner.k * Convection_roof_inner.dT
 */
void OM_Result_eqFunction_63(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,63};
  data->localData[0]->realVars[49] /* Convection_roof_inner._Q_flow variable */ = (data->simulationInfo->realParameter[20]) * (data->localData[0]->realVars[50] /* Convection_roof_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 64
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._Q_flow = Radiation_roof_to_floor.Q_flow - ((-Convection_roof_inner.Q_flow) - Radiation_roof_inner.Q_flow)
 */
void OM_Result_eqFunction_64(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,64};
  data->localData[0]->realVars[23] /* Conduction_roof_inner._Q_flow variable */ = data->localData[0]->realVars[86] /* Radiation_roof_to_floor._Q_flow variable */ - ((-data->localData[0]->realVars[49] /* Convection_roof_inner._Q_flow variable */) - data->localData[0]->realVars[82] /* Radiation_roof_inner._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 65
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._dT = DIVISION(Conduction_roof_inner.Q_flow, Conduction_roof_inner.G)
 */
void OM_Result_eqFunction_65(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
  data->localData[0]->realVars[24] /* Conduction_roof_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[23] /* Conduction_roof_inner._Q_flow variable */,data->simulationInfo->realParameter[9],"Conduction_roof_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc73(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,73};
  /* iteration variables */
  data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_60(data, threadData);

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
  /* body */
  res[0] = data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */ + (-data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */) - data->localData[0]->realVars[24] /* Conduction_roof_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS73(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS73(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_roof_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS73(sysData);
}

void getIterationVarsNLS73(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 99
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._Q_flow = 5.670367e-08 * Radiation_wall4_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall4_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_99(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,99};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[70] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[98] /* Radiation_wall4_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[68]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 100
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._dT = Conduction_wall4_outer.port_a.T - Capacitor_wall4.T
 */
void OM_Result_eqFunction_100(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,100};
  data->localData[0]->realVars[45] /* Conduction_wall4_outer._dT variable */ = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */ - data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */;
  TRACE_POP
}
/*
 equation index: 101
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._Q_flow = Conduction_wall4_outer.G * Conduction_wall4_outer.dT
 */
void OM_Result_eqFunction_101(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,101};
  data->localData[0]->realVars[44] /* Conduction_wall4_outer._Q_flow variable */ = (data->simulationInfo->realParameter[16]) * (data->localData[0]->realVars[45] /* Conduction_wall4_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 102
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Q_flow = Conduction_wall4_outer.Q_flow - Radiation_wall4_outer.Q_flow
 */
void OM_Result_eqFunction_102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,102};
  data->localData[0]->realVars[67] /* Convection_wall4_outer._Q_flow variable */ = data->localData[0]->realVars[44] /* Conduction_wall4_outer._Q_flow variable */ - data->localData[0]->realVars[98] /* Radiation_wall4_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 103
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall4_outer.port_a.T
 */
void OM_Result_eqFunction_103(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,103};
  data->localData[0]->realVars[68] /* Convection_wall4_outer._dT variable */ = data->localData[0]->realVars[70] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
  TRACE_POP
}

void residualFunc109(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,109};
  /* iteration variables */
  data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_99(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_100(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_101(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_102(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_103(data, threadData);
  /* body */
  res[0] = (data->localData[0]->realVars[66] /* Convection_wall4_outer._Gc variable */) * (data->localData[0]->realVars[68] /* Convection_wall4_outer._dT variable */) - data->localData[0]->realVars[67] /* Convection_wall4_outer._Q_flow variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS109(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS109(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall4_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS109(sysData);
}

void getIterationVarsNLS109(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 115
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._Q_flow = 5.670367e-08 * Radiation_wall3_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall3_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[70] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[94] /* Radiation_wall3_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[66]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 116
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall3_outer.port_a.T
 */
void OM_Result_eqFunction_116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,116};
  data->localData[0]->realVars[63] /* Convection_wall3_outer._dT variable */ = data->localData[0]->realVars[70] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 117
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Q_flow = Convection_wall3_outer.Gc * Convection_wall3_outer.dT
 */
void OM_Result_eqFunction_117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,117};
  data->localData[0]->realVars[62] /* Convection_wall3_outer._Q_flow variable */ = (data->localData[0]->realVars[61] /* Convection_wall3_outer._Gc variable */) * (data->localData[0]->realVars[63] /* Convection_wall3_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 118
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._Q_flow = Radiation_wall3_outer.Q_flow + Convection_wall3_outer.Q_flow
 */
void OM_Result_eqFunction_118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,118};
  data->localData[0]->realVars[38] /* Conduction_wall3_outer._Q_flow variable */ = data->localData[0]->realVars[94] /* Radiation_wall3_outer._Q_flow variable */ + data->localData[0]->realVars[62] /* Convection_wall3_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 119
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._dT = DIVISION(Conduction_wall3_outer.Q_flow, Conduction_wall3_outer.G)
 */
void OM_Result_eqFunction_119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,119};
  data->localData[0]->realVars[39] /* Conduction_wall3_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[38] /* Conduction_wall3_outer._Q_flow variable */,data->simulationInfo->realParameter[14],"Conduction_wall3_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc126(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,126};
  /* iteration variables */
  data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_115(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_116(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_117(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_118(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_119(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */ + (-data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */) - data->localData[0]->realVars[39] /* Conduction_wall3_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS126(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS126(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS126(sysData);
}

void getIterationVarsNLS126(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 132
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._Q_flow = 5.670367e-08 * Radiation_wall1_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall1_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_132(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,132};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[70] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[90] /* Radiation_wall1_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[64]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 133
 type: SIMPLE_ASSIGN
 Heatflow_solar_wall1._port._Q_flow = (-Heatflow_solar_wall1.Q_flow) * (1.0 + Heatflow_solar_wall1.alpha * (Conduction_wall1_outer.port_a.T - Heatflow_solar_wall1.T_ref))
 */
void OM_Result_eqFunction_133(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,133};
  data->localData[0]->realVars[79] /* Heatflow_solar_wall1._port._Q_flow variable */ = ((-data->localData[0]->realVars[78] /* Heatflow_solar_wall1._Q_flow variable */)) * (1.0 + (data->simulationInfo->realParameter[57]) * (data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */ - data->simulationInfo->realParameter[56]));
  TRACE_POP
}
/*
 equation index: 134
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._dT = Conduction_wall1_outer.port_a.T - Capacitor_wall1.T
 */
void OM_Result_eqFunction_134(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,134};
  data->localData[0]->realVars[33] /* Conduction_wall1_outer._dT variable */ = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */ - data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */;
  TRACE_POP
}
/*
 equation index: 135
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._Q_flow = Conduction_wall1_outer.G * Conduction_wall1_outer.dT
 */
void OM_Result_eqFunction_135(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,135};
  data->localData[0]->realVars[32] /* Conduction_wall1_outer._Q_flow variable */ = (data->simulationInfo->realParameter[12]) * (data->localData[0]->realVars[33] /* Conduction_wall1_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 136
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Q_flow = Conduction_wall1_outer.Q_flow + Heatflow_solar_wall1.port.Q_flow - Radiation_wall1_outer.Q_flow
 */
void OM_Result_eqFunction_136(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,136};
  data->localData[0]->realVars[57] /* Convection_wall1_outer._Q_flow variable */ = data->localData[0]->realVars[32] /* Conduction_wall1_outer._Q_flow variable */ + data->localData[0]->realVars[79] /* Heatflow_solar_wall1._port._Q_flow variable */ - data->localData[0]->realVars[90] /* Radiation_wall1_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 137
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall1_outer.port_a.T
 */
void OM_Result_eqFunction_137(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,137};
  data->localData[0]->realVars[58] /* Convection_wall1_outer._dT variable */ = data->localData[0]->realVars[70] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
  TRACE_POP
}

void residualFunc144(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,144};
  /* iteration variables */
  data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_132(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_133(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_134(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_135(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_136(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_137(data, threadData);
  /* body */
  res[0] = (data->localData[0]->realVars[56] /* Convection_wall1_outer._Gc variable */) * (data->localData[0]->realVars[58] /* Convection_wall1_outer._dT variable */) - data->localData[0]->realVars[57] /* Convection_wall1_outer._Q_flow variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS144(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS144(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS144(sysData);
}

void getIterationVarsNLS144(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 150
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._Q_flow = 5.670367e-08 * Radiation_roof_outer.Gr * (Temperature_sky.T ^ 4.0 - Conduction_roof_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_150(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,150};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[104] /* Temperature_sky._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[84] /* Radiation_roof_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[61]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 151
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._port._Q_flow = (-Heatflow_solar_radiation.Q_flow) * (1.0 + Heatflow_solar_radiation.alpha * (Conduction_roof_outer.port_a.T - Heatflow_solar_radiation.T_ref))
 */
void OM_Result_eqFunction_151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,151};
  data->localData[0]->realVars[77] /* Heatflow_solar_radiation._port._Q_flow variable */ = ((-data->localData[0]->realVars[76] /* Heatflow_solar_radiation._Q_flow variable */)) * (1.0 + (data->simulationInfo->realParameter[55]) * (data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ - data->simulationInfo->realParameter[54]));
  TRACE_POP
}
/*
 equation index: 152
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._dT = Conduction_roof_outer.port_a.T - Capacitor_roof.T
 */
void OM_Result_eqFunction_152(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,152};
  data->localData[0]->realVars[27] /* Conduction_roof_outer._dT variable */ = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ - data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */;
  TRACE_POP
}
/*
 equation index: 153
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._Q_flow = Conduction_roof_outer.G * Conduction_roof_outer.dT
 */
void OM_Result_eqFunction_153(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,153};
  data->localData[0]->realVars[26] /* Conduction_roof_outer._Q_flow variable */ = (data->simulationInfo->realParameter[10]) * (data->localData[0]->realVars[27] /* Conduction_roof_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 154
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Q_flow = Conduction_roof_outer.Q_flow + Heatflow_solar_radiation.port.Q_flow - Radiation_roof_outer.Q_flow
 */
void OM_Result_eqFunction_154(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,154};
  data->localData[0]->realVars[52] /* Convection_roof_outer._Q_flow variable */ = data->localData[0]->realVars[26] /* Conduction_roof_outer._Q_flow variable */ + data->localData[0]->realVars[77] /* Heatflow_solar_radiation._port._Q_flow variable */ - data->localData[0]->realVars[84] /* Radiation_roof_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 155
 type: SIMPLE_ASSIGN
 Convection_roof_outer._dT = Data_outdoor_temperature.y[1] - Conduction_roof_outer.port_a.T
 */
void OM_Result_eqFunction_155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,155};
  data->localData[0]->realVars[53] /* Convection_roof_outer._dT variable */ = data->localData[0]->realVars[70] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
  TRACE_POP
}

void residualFunc162(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,162};
  /* iteration variables */
  data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_150(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_151(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_152(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_153(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_154(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_155(data, threadData);
  /* body */
  res[0] = (data->localData[0]->realVars[51] /* Convection_roof_outer._Gc variable */) * (data->localData[0]->realVars[53] /* Convection_roof_outer._dT variable */) - data->localData[0]->realVars[52] /* Convection_roof_outer._Q_flow variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS162(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS162(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_roof_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS162(sysData);
}

void getIterationVarsNLS162(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
}

/* inner equations */

/*
 equation index: 243
 type: SIMPLE_ASSIGN
 Radiation_wall4_inner._Q_flow = 5.670367e-08 * Radiation_wall4_inner.Gr * (Conduction_wall4_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_243(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,243};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[96] /* Radiation_wall4_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[67]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 244
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._dT = Conduction_wall4_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
  data->localData[0]->realVars[65] /* Convection_wall4_inner._dT variable */ = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 245
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._Q_flow = Convection_coef_wall4_inner.k * Convection_wall4_inner.dT
 */
void OM_Result_eqFunction_245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,245};
  data->localData[0]->realVars[64] /* Convection_wall4_inner._Q_flow variable */ = (data->simulationInfo->realParameter[23]) * (data->localData[0]->realVars[65] /* Convection_wall4_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 246
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._Q_flow = Radiation_wall4_inner.Q_flow + Convection_wall4_inner.Q_flow
 */
void OM_Result_eqFunction_246(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,246};
  data->localData[0]->realVars[41] /* Conduction_wall4_inner._Q_flow variable */ = data->localData[0]->realVars[96] /* Radiation_wall4_inner._Q_flow variable */ + data->localData[0]->realVars[64] /* Convection_wall4_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 247
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._dT = DIVISION(Conduction_wall4_inner.Q_flow, Conduction_wall4_inner.G)
 */
void OM_Result_eqFunction_247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,247};
  data->localData[0]->realVars[42] /* Conduction_wall4_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[41] /* Conduction_wall4_inner._Q_flow variable */,data->simulationInfo->realParameter[15],"Conduction_wall4_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc254(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,254};
  /* iteration variables */
  data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_243(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_244(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_245(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_246(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_247(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */ + (-data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */) - data->localData[0]->realVars[42] /* Conduction_wall4_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS254(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS254(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall4_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS254(sysData);
}

void getIterationVarsNLS254(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 256
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._Q_flow = 5.670367e-08 * Radiation_wall4_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall4_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_256(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,256};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[70] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[98] /* Radiation_wall4_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[68]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 257
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._dT = Conduction_wall4_outer.port_a.T - Capacitor_wall4.T
 */
void OM_Result_eqFunction_257(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,257};
  data->localData[0]->realVars[45] /* Conduction_wall4_outer._dT variable */ = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */ - data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */;
  TRACE_POP
}
/*
 equation index: 258
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._Q_flow = Conduction_wall4_outer.G * Conduction_wall4_outer.dT
 */
void OM_Result_eqFunction_258(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,258};
  data->localData[0]->realVars[44] /* Conduction_wall4_outer._Q_flow variable */ = (data->simulationInfo->realParameter[16]) * (data->localData[0]->realVars[45] /* Conduction_wall4_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 259
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Q_flow = Conduction_wall4_outer.Q_flow - Radiation_wall4_outer.Q_flow
 */
void OM_Result_eqFunction_259(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,259};
  data->localData[0]->realVars[67] /* Convection_wall4_outer._Q_flow variable */ = data->localData[0]->realVars[44] /* Conduction_wall4_outer._Q_flow variable */ - data->localData[0]->realVars[98] /* Radiation_wall4_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 260
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall4_outer.port_a.T
 */
void OM_Result_eqFunction_260(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,260};
  data->localData[0]->realVars[68] /* Convection_wall4_outer._dT variable */ = data->localData[0]->realVars[70] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
  TRACE_POP
}

void residualFunc266(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,266};
  /* iteration variables */
  data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */ = xloc[0];
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
  res[0] = (data->localData[0]->realVars[66] /* Convection_wall4_outer._Gc variable */) * (data->localData[0]->realVars[68] /* Convection_wall4_outer._dT variable */) - data->localData[0]->realVars[67] /* Convection_wall4_outer._Q_flow variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS266(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS266(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall4_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS266(sysData);
}

void getIterationVarsNLS266(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 271
 type: SIMPLE_ASSIGN
 Radiation_wall3_inner._Q_flow = 5.670367e-08 * Radiation_wall3_inner.Gr * (Conduction_wall3_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_271(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,271};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[92] /* Radiation_wall3_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[65]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 272
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._dT = Conduction_wall3_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_272(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,272};
  data->localData[0]->realVars[60] /* Convection_wall3_inner._dT variable */ = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 273
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._Q_flow = Convection_coef_wall3_inner.k * Convection_wall3_inner.dT
 */
void OM_Result_eqFunction_273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,273};
  data->localData[0]->realVars[59] /* Convection_wall3_inner._Q_flow variable */ = (data->simulationInfo->realParameter[22]) * (data->localData[0]->realVars[60] /* Convection_wall3_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 274
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._Q_flow = Radiation_wall3_inner.Q_flow + Convection_wall3_inner.Q_flow
 */
void OM_Result_eqFunction_274(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,274};
  data->localData[0]->realVars[35] /* Conduction_wall3_inner._Q_flow variable */ = data->localData[0]->realVars[92] /* Radiation_wall3_inner._Q_flow variable */ + data->localData[0]->realVars[59] /* Convection_wall3_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 275
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._dT = DIVISION(Conduction_wall3_inner.Q_flow, Conduction_wall3_inner.G)
 */
void OM_Result_eqFunction_275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,275};
  data->localData[0]->realVars[36] /* Conduction_wall3_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[35] /* Conduction_wall3_inner._Q_flow variable */,data->simulationInfo->realParameter[13],"Conduction_wall3_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc282(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,282};
  /* iteration variables */
  data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_271(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_272(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_273(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_274(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_275(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */ + (-data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */) - data->localData[0]->realVars[36] /* Conduction_wall3_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS282(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS282(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS282(sysData);
}

void getIterationVarsNLS282(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 284
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._Q_flow = 5.670367e-08 * Radiation_wall3_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall3_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,284};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[70] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[94] /* Radiation_wall3_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[66]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 285
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall3_outer.port_a.T
 */
void OM_Result_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,285};
  data->localData[0]->realVars[63] /* Convection_wall3_outer._dT variable */ = data->localData[0]->realVars[70] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 286
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Q_flow = Convection_wall3_outer.Gc * Convection_wall3_outer.dT
 */
void OM_Result_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,286};
  data->localData[0]->realVars[62] /* Convection_wall3_outer._Q_flow variable */ = (data->localData[0]->realVars[61] /* Convection_wall3_outer._Gc variable */) * (data->localData[0]->realVars[63] /* Convection_wall3_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 287
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._Q_flow = Radiation_wall3_outer.Q_flow + Convection_wall3_outer.Q_flow
 */
void OM_Result_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
  data->localData[0]->realVars[38] /* Conduction_wall3_outer._Q_flow variable */ = data->localData[0]->realVars[94] /* Radiation_wall3_outer._Q_flow variable */ + data->localData[0]->realVars[62] /* Convection_wall3_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 288
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._dT = DIVISION(Conduction_wall3_outer.Q_flow, Conduction_wall3_outer.G)
 */
void OM_Result_eqFunction_288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,288};
  data->localData[0]->realVars[39] /* Conduction_wall3_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[38] /* Conduction_wall3_outer._Q_flow variable */,data->simulationInfo->realParameter[14],"Conduction_wall3_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc295(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,295};
  /* iteration variables */
  data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_284(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_285(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_286(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_287(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_288(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */ + (-data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */) - data->localData[0]->realVars[39] /* Conduction_wall3_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS295(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS295(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS295(sysData);
}

void getIterationVarsNLS295(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 300
 type: SIMPLE_ASSIGN
 Radiation_roof_to_floor._Q_flow = 5.670367e-08 * Radiation_roof_to_floor.Gr * (Conduction_roof_inner.port_b.T ^ 4.0 - Floor_temperature.k ^ 4.0)
 */
void OM_Result_eqFunction_300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,300};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->simulationInfo->realParameter[51];
  tmp1 *= tmp1;
  data->localData[0]->realVars[86] /* Radiation_roof_to_floor._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[62]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 301
 type: SIMPLE_ASSIGN
 Radiation_roof_inner._Q_flow = 5.670367e-08 * Radiation_roof_inner.Gr * (Conduction_roof_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,301};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[82] /* Radiation_roof_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[60]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 302
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._dT = Capacitor_roof.T - Conduction_roof_inner.port_b.T
 */
void OM_Result_eqFunction_302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,302};
  data->localData[0]->realVars[24] /* Conduction_roof_inner._dT variable */ = data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */ - data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  TRACE_POP
}
/*
 equation index: 303
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._Q_flow = Conduction_roof_inner.G * Conduction_roof_inner.dT
 */
void OM_Result_eqFunction_303(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,303};
  data->localData[0]->realVars[23] /* Conduction_roof_inner._Q_flow variable */ = (data->simulationInfo->realParameter[9]) * (data->localData[0]->realVars[24] /* Conduction_roof_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 304
 type: SIMPLE_ASSIGN
 Convection_roof_inner._Q_flow = Conduction_roof_inner.Q_flow - (Radiation_roof_inner.Q_flow + Radiation_roof_to_floor.Q_flow)
 */
void OM_Result_eqFunction_304(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,304};
  data->localData[0]->realVars[49] /* Convection_roof_inner._Q_flow variable */ = data->localData[0]->realVars[23] /* Conduction_roof_inner._Q_flow variable */ - (data->localData[0]->realVars[82] /* Radiation_roof_inner._Q_flow variable */ + data->localData[0]->realVars[86] /* Radiation_roof_to_floor._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 305
 type: SIMPLE_ASSIGN
 Convection_roof_inner._dT = DIVISION(Convection_roof_inner.Q_flow, Convection_coef_roof_inner.k)
 */
void OM_Result_eqFunction_305(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,305};
  data->localData[0]->realVars[50] /* Convection_roof_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[49] /* Convection_roof_inner._Q_flow variable */,data->simulationInfo->realParameter[20],"Convection_coef_roof_inner.k",equationIndexes);
  TRACE_POP
}

void residualFunc313(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,313};
  /* iteration variables */
  data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_300(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_301(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_302(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_303(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_304(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_305(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */ + (-data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */) - data->localData[0]->realVars[50] /* Convection_roof_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS313(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS313(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_roof_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS313(sysData);
}

void getIterationVarsNLS313(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 317
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._Q_flow = 5.670367e-08 * Radiation_roof_outer.Gr * (Temperature_sky.T ^ 4.0 - Conduction_roof_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_317(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,317};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[104] /* Temperature_sky._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[84] /* Radiation_roof_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[61]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 318
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._port._Q_flow = (-Heatflow_solar_radiation.Q_flow) * (1.0 + Heatflow_solar_radiation.alpha * (Conduction_roof_outer.port_a.T - Heatflow_solar_radiation.T_ref))
 */
void OM_Result_eqFunction_318(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,318};
  data->localData[0]->realVars[77] /* Heatflow_solar_radiation._port._Q_flow variable */ = ((-data->localData[0]->realVars[76] /* Heatflow_solar_radiation._Q_flow variable */)) * (1.0 + (data->simulationInfo->realParameter[55]) * (data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ - data->simulationInfo->realParameter[54]));
  TRACE_POP
}
/*
 equation index: 319
 type: SIMPLE_ASSIGN
 Convection_roof_outer._dT = Data_outdoor_temperature.y[1] - Conduction_roof_outer.port_a.T
 */
void OM_Result_eqFunction_319(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,319};
  data->localData[0]->realVars[53] /* Convection_roof_outer._dT variable */ = data->localData[0]->realVars[70] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 320
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Q_flow = Convection_roof_outer.Gc * Convection_roof_outer.dT
 */
void OM_Result_eqFunction_320(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,320};
  data->localData[0]->realVars[52] /* Convection_roof_outer._Q_flow variable */ = (data->localData[0]->realVars[51] /* Convection_roof_outer._Gc variable */) * (data->localData[0]->realVars[53] /* Convection_roof_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 321
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._Q_flow = Convection_roof_outer.Q_flow - (Heatflow_solar_radiation.port.Q_flow - Radiation_roof_outer.Q_flow)
 */
void OM_Result_eqFunction_321(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,321};
  data->localData[0]->realVars[26] /* Conduction_roof_outer._Q_flow variable */ = data->localData[0]->realVars[52] /* Convection_roof_outer._Q_flow variable */ - (data->localData[0]->realVars[77] /* Heatflow_solar_radiation._port._Q_flow variable */ - data->localData[0]->realVars[84] /* Radiation_roof_outer._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 322
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._dT = DIVISION(Conduction_roof_outer.Q_flow, Conduction_roof_outer.G)
 */
void OM_Result_eqFunction_322(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,322};
  data->localData[0]->realVars[27] /* Conduction_roof_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[26] /* Conduction_roof_outer._Q_flow variable */,data->simulationInfo->realParameter[10],"Conduction_roof_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc330(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,330};
  /* iteration variables */
  data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_317(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_318(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_319(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_320(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_321(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_322(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ + (-data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */) - data->localData[0]->realVars[27] /* Conduction_roof_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS330(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS330(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_roof_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS330(sysData);
}

void getIterationVarsNLS330(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 335
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._Q_flow = 5.670367e-08 * Radiation_wall1_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall1_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_335(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,335};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[70] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[90] /* Radiation_wall1_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[64]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 336
 type: SIMPLE_ASSIGN
 Heatflow_solar_wall1._port._Q_flow = (-Heatflow_solar_wall1.Q_flow) * (1.0 + Heatflow_solar_wall1.alpha * (Conduction_wall1_outer.port_a.T - Heatflow_solar_wall1.T_ref))
 */
void OM_Result_eqFunction_336(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,336};
  data->localData[0]->realVars[79] /* Heatflow_solar_wall1._port._Q_flow variable */ = ((-data->localData[0]->realVars[78] /* Heatflow_solar_wall1._Q_flow variable */)) * (1.0 + (data->simulationInfo->realParameter[57]) * (data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */ - data->simulationInfo->realParameter[56]));
  TRACE_POP
}
/*
 equation index: 337
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall1_outer.port_a.T
 */
void OM_Result_eqFunction_337(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,337};
  data->localData[0]->realVars[58] /* Convection_wall1_outer._dT variable */ = data->localData[0]->realVars[70] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 338
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Q_flow = Convection_wall1_outer.Gc * Convection_wall1_outer.dT
 */
void OM_Result_eqFunction_338(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,338};
  data->localData[0]->realVars[57] /* Convection_wall1_outer._Q_flow variable */ = (data->localData[0]->realVars[56] /* Convection_wall1_outer._Gc variable */) * (data->localData[0]->realVars[58] /* Convection_wall1_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 339
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._Q_flow = Convection_wall1_outer.Q_flow - (Heatflow_solar_wall1.port.Q_flow - Radiation_wall1_outer.Q_flow)
 */
void OM_Result_eqFunction_339(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,339};
  data->localData[0]->realVars[32] /* Conduction_wall1_outer._Q_flow variable */ = data->localData[0]->realVars[57] /* Convection_wall1_outer._Q_flow variable */ - (data->localData[0]->realVars[79] /* Heatflow_solar_wall1._port._Q_flow variable */ - data->localData[0]->realVars[90] /* Radiation_wall1_outer._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 340
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._dT = DIVISION(Conduction_wall1_outer.Q_flow, Conduction_wall1_outer.G)
 */
void OM_Result_eqFunction_340(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,340};
  data->localData[0]->realVars[33] /* Conduction_wall1_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[32] /* Conduction_wall1_outer._Q_flow variable */,data->simulationInfo->realParameter[12],"Conduction_wall1_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc348(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,348};
  /* iteration variables */
  data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_335(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_336(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_337(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_338(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_339(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_340(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */ + (-data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */) - data->localData[0]->realVars[33] /* Conduction_wall1_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS348(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS348(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS348(sysData);
}

void getIterationVarsNLS348(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 351
 type: SIMPLE_ASSIGN
 Radiation_wall1_inner._Q_flow = 5.670367e-08 * Radiation_wall1_inner.Gr * (Conduction_wall1_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_351(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,351};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[88] /* Radiation_wall1_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[63]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 352
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._dT = Conduction_wall1_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_352(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,352};
  data->localData[0]->realVars[55] /* Convection_wall1_inner._dT variable */ = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 353
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._Q_flow = Convection_coef_wall1_inner.k * Convection_wall1_inner.dT
 */
void OM_Result_eqFunction_353(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,353};
  data->localData[0]->realVars[54] /* Convection_wall1_inner._Q_flow variable */ = (data->simulationInfo->realParameter[21]) * (data->localData[0]->realVars[55] /* Convection_wall1_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 354
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._Q_flow = Radiation_wall1_inner.Q_flow + Convection_wall1_inner.Q_flow
 */
void OM_Result_eqFunction_354(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,354};
  data->localData[0]->realVars[29] /* Conduction_wall1_inner._Q_flow variable */ = data->localData[0]->realVars[88] /* Radiation_wall1_inner._Q_flow variable */ + data->localData[0]->realVars[54] /* Convection_wall1_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 355
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._dT = DIVISION(Conduction_wall1_inner.Q_flow, Conduction_wall1_inner.G)
 */
void OM_Result_eqFunction_355(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,355};
  data->localData[0]->realVars[30] /* Conduction_wall1_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[29] /* Conduction_wall1_inner._Q_flow variable */,data->simulationInfo->realParameter[11],"Conduction_wall1_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc362(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,362};
  /* iteration variables */
  data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_351(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_352(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_353(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_354(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_355(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */ + (-data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */) - data->localData[0]->realVars[30] /* Conduction_wall1_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS362(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS362(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS362(sysData);
}

void getIterationVarsNLS362(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */;
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize non-linear systems */
void OM_Result_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA* nonLinearSystemData)
{
  
  nonLinearSystemData[0].equationIndex = 32;
  nonLinearSystemData[0].size = 1;
  nonLinearSystemData[0].homotopySupport = 0;
  nonLinearSystemData[0].mixedSystem = 0;
  nonLinearSystemData[0].residualFunc = residualFunc32;
  nonLinearSystemData[0].strictTearingFunctionCall = NULL;
  nonLinearSystemData[0].analyticalJacobianColumn = OM_Result_functionJacNLSJac0_column;
  nonLinearSystemData[0].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac0;
  nonLinearSystemData[0].jacobianIndex = 0;
  nonLinearSystemData[0].initializeStaticNLSData = initializeStaticDataNLS32;
  nonLinearSystemData[0].getIterationVars = getIterationVarsNLS32;
  nonLinearSystemData[0].checkConstraints = NULL;
  
  
  nonLinearSystemData[1].equationIndex = 45;
  nonLinearSystemData[1].size = 1;
  nonLinearSystemData[1].homotopySupport = 0;
  nonLinearSystemData[1].mixedSystem = 0;
  nonLinearSystemData[1].residualFunc = residualFunc45;
  nonLinearSystemData[1].strictTearingFunctionCall = NULL;
  nonLinearSystemData[1].analyticalJacobianColumn = OM_Result_functionJacNLSJac1_column;
  nonLinearSystemData[1].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac1;
  nonLinearSystemData[1].jacobianIndex = 1;
  nonLinearSystemData[1].initializeStaticNLSData = initializeStaticDataNLS45;
  nonLinearSystemData[1].getIterationVars = getIterationVarsNLS45;
  nonLinearSystemData[1].checkConstraints = NULL;
  
  
  nonLinearSystemData[2].equationIndex = 58;
  nonLinearSystemData[2].size = 1;
  nonLinearSystemData[2].homotopySupport = 0;
  nonLinearSystemData[2].mixedSystem = 0;
  nonLinearSystemData[2].residualFunc = residualFunc58;
  nonLinearSystemData[2].strictTearingFunctionCall = NULL;
  nonLinearSystemData[2].analyticalJacobianColumn = OM_Result_functionJacNLSJac2_column;
  nonLinearSystemData[2].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac2;
  nonLinearSystemData[2].jacobianIndex = 2;
  nonLinearSystemData[2].initializeStaticNLSData = initializeStaticDataNLS58;
  nonLinearSystemData[2].getIterationVars = getIterationVarsNLS58;
  nonLinearSystemData[2].checkConstraints = NULL;
  
  
  nonLinearSystemData[3].equationIndex = 73;
  nonLinearSystemData[3].size = 1;
  nonLinearSystemData[3].homotopySupport = 0;
  nonLinearSystemData[3].mixedSystem = 0;
  nonLinearSystemData[3].residualFunc = residualFunc73;
  nonLinearSystemData[3].strictTearingFunctionCall = NULL;
  nonLinearSystemData[3].analyticalJacobianColumn = OM_Result_functionJacNLSJac3_column;
  nonLinearSystemData[3].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac3;
  nonLinearSystemData[3].jacobianIndex = 3;
  nonLinearSystemData[3].initializeStaticNLSData = initializeStaticDataNLS73;
  nonLinearSystemData[3].getIterationVars = getIterationVarsNLS73;
  nonLinearSystemData[3].checkConstraints = NULL;
  
  
  nonLinearSystemData[4].equationIndex = 109;
  nonLinearSystemData[4].size = 1;
  nonLinearSystemData[4].homotopySupport = 0;
  nonLinearSystemData[4].mixedSystem = 0;
  nonLinearSystemData[4].residualFunc = residualFunc109;
  nonLinearSystemData[4].strictTearingFunctionCall = NULL;
  nonLinearSystemData[4].analyticalJacobianColumn = OM_Result_functionJacNLSJac4_column;
  nonLinearSystemData[4].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac4;
  nonLinearSystemData[4].jacobianIndex = 4;
  nonLinearSystemData[4].initializeStaticNLSData = initializeStaticDataNLS109;
  nonLinearSystemData[4].getIterationVars = getIterationVarsNLS109;
  nonLinearSystemData[4].checkConstraints = NULL;
  
  
  nonLinearSystemData[5].equationIndex = 126;
  nonLinearSystemData[5].size = 1;
  nonLinearSystemData[5].homotopySupport = 0;
  nonLinearSystemData[5].mixedSystem = 0;
  nonLinearSystemData[5].residualFunc = residualFunc126;
  nonLinearSystemData[5].strictTearingFunctionCall = NULL;
  nonLinearSystemData[5].analyticalJacobianColumn = OM_Result_functionJacNLSJac5_column;
  nonLinearSystemData[5].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac5;
  nonLinearSystemData[5].jacobianIndex = 5;
  nonLinearSystemData[5].initializeStaticNLSData = initializeStaticDataNLS126;
  nonLinearSystemData[5].getIterationVars = getIterationVarsNLS126;
  nonLinearSystemData[5].checkConstraints = NULL;
  
  
  nonLinearSystemData[6].equationIndex = 144;
  nonLinearSystemData[6].size = 1;
  nonLinearSystemData[6].homotopySupport = 0;
  nonLinearSystemData[6].mixedSystem = 0;
  nonLinearSystemData[6].residualFunc = residualFunc144;
  nonLinearSystemData[6].strictTearingFunctionCall = NULL;
  nonLinearSystemData[6].analyticalJacobianColumn = OM_Result_functionJacNLSJac6_column;
  nonLinearSystemData[6].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac6;
  nonLinearSystemData[6].jacobianIndex = 6;
  nonLinearSystemData[6].initializeStaticNLSData = initializeStaticDataNLS144;
  nonLinearSystemData[6].getIterationVars = getIterationVarsNLS144;
  nonLinearSystemData[6].checkConstraints = NULL;
  
  
  nonLinearSystemData[7].equationIndex = 162;
  nonLinearSystemData[7].size = 1;
  nonLinearSystemData[7].homotopySupport = 0;
  nonLinearSystemData[7].mixedSystem = 0;
  nonLinearSystemData[7].residualFunc = residualFunc162;
  nonLinearSystemData[7].strictTearingFunctionCall = NULL;
  nonLinearSystemData[7].analyticalJacobianColumn = OM_Result_functionJacNLSJac7_column;
  nonLinearSystemData[7].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac7;
  nonLinearSystemData[7].jacobianIndex = 7;
  nonLinearSystemData[7].initializeStaticNLSData = initializeStaticDataNLS162;
  nonLinearSystemData[7].getIterationVars = getIterationVarsNLS162;
  nonLinearSystemData[7].checkConstraints = NULL;
  
  nonLinearSystemData[8].equationIndex = 254;
  nonLinearSystemData[8].size = 1;
  nonLinearSystemData[8].homotopySupport = 0;
  nonLinearSystemData[8].mixedSystem = 0;
  nonLinearSystemData[8].residualFunc = residualFunc254;
  nonLinearSystemData[8].strictTearingFunctionCall = NULL;
  nonLinearSystemData[8].analyticalJacobianColumn = OM_Result_functionJacNLSJac8_column;
  nonLinearSystemData[8].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac8;
  nonLinearSystemData[8].jacobianIndex = 8;
  nonLinearSystemData[8].initializeStaticNLSData = initializeStaticDataNLS254;
  nonLinearSystemData[8].getIterationVars = getIterationVarsNLS254;
  nonLinearSystemData[8].checkConstraints = NULL;
  
  
  nonLinearSystemData[9].equationIndex = 266;
  nonLinearSystemData[9].size = 1;
  nonLinearSystemData[9].homotopySupport = 0;
  nonLinearSystemData[9].mixedSystem = 0;
  nonLinearSystemData[9].residualFunc = residualFunc266;
  nonLinearSystemData[9].strictTearingFunctionCall = NULL;
  nonLinearSystemData[9].analyticalJacobianColumn = OM_Result_functionJacNLSJac9_column;
  nonLinearSystemData[9].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac9;
  nonLinearSystemData[9].jacobianIndex = 9;
  nonLinearSystemData[9].initializeStaticNLSData = initializeStaticDataNLS266;
  nonLinearSystemData[9].getIterationVars = getIterationVarsNLS266;
  nonLinearSystemData[9].checkConstraints = NULL;
  
  
  nonLinearSystemData[10].equationIndex = 282;
  nonLinearSystemData[10].size = 1;
  nonLinearSystemData[10].homotopySupport = 0;
  nonLinearSystemData[10].mixedSystem = 0;
  nonLinearSystemData[10].residualFunc = residualFunc282;
  nonLinearSystemData[10].strictTearingFunctionCall = NULL;
  nonLinearSystemData[10].analyticalJacobianColumn = OM_Result_functionJacNLSJac10_column;
  nonLinearSystemData[10].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac10;
  nonLinearSystemData[10].jacobianIndex = 10;
  nonLinearSystemData[10].initializeStaticNLSData = initializeStaticDataNLS282;
  nonLinearSystemData[10].getIterationVars = getIterationVarsNLS282;
  nonLinearSystemData[10].checkConstraints = NULL;
  
  
  nonLinearSystemData[11].equationIndex = 295;
  nonLinearSystemData[11].size = 1;
  nonLinearSystemData[11].homotopySupport = 0;
  nonLinearSystemData[11].mixedSystem = 0;
  nonLinearSystemData[11].residualFunc = residualFunc295;
  nonLinearSystemData[11].strictTearingFunctionCall = NULL;
  nonLinearSystemData[11].analyticalJacobianColumn = OM_Result_functionJacNLSJac11_column;
  nonLinearSystemData[11].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac11;
  nonLinearSystemData[11].jacobianIndex = 11;
  nonLinearSystemData[11].initializeStaticNLSData = initializeStaticDataNLS295;
  nonLinearSystemData[11].getIterationVars = getIterationVarsNLS295;
  nonLinearSystemData[11].checkConstraints = NULL;
  
  
  nonLinearSystemData[12].equationIndex = 313;
  nonLinearSystemData[12].size = 1;
  nonLinearSystemData[12].homotopySupport = 0;
  nonLinearSystemData[12].mixedSystem = 0;
  nonLinearSystemData[12].residualFunc = residualFunc313;
  nonLinearSystemData[12].strictTearingFunctionCall = NULL;
  nonLinearSystemData[12].analyticalJacobianColumn = OM_Result_functionJacNLSJac12_column;
  nonLinearSystemData[12].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac12;
  nonLinearSystemData[12].jacobianIndex = 12;
  nonLinearSystemData[12].initializeStaticNLSData = initializeStaticDataNLS313;
  nonLinearSystemData[12].getIterationVars = getIterationVarsNLS313;
  nonLinearSystemData[12].checkConstraints = NULL;
  
  
  nonLinearSystemData[13].equationIndex = 330;
  nonLinearSystemData[13].size = 1;
  nonLinearSystemData[13].homotopySupport = 0;
  nonLinearSystemData[13].mixedSystem = 0;
  nonLinearSystemData[13].residualFunc = residualFunc330;
  nonLinearSystemData[13].strictTearingFunctionCall = NULL;
  nonLinearSystemData[13].analyticalJacobianColumn = OM_Result_functionJacNLSJac13_column;
  nonLinearSystemData[13].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac13;
  nonLinearSystemData[13].jacobianIndex = 13;
  nonLinearSystemData[13].initializeStaticNLSData = initializeStaticDataNLS330;
  nonLinearSystemData[13].getIterationVars = getIterationVarsNLS330;
  nonLinearSystemData[13].checkConstraints = NULL;
  
  
  nonLinearSystemData[14].equationIndex = 348;
  nonLinearSystemData[14].size = 1;
  nonLinearSystemData[14].homotopySupport = 0;
  nonLinearSystemData[14].mixedSystem = 0;
  nonLinearSystemData[14].residualFunc = residualFunc348;
  nonLinearSystemData[14].strictTearingFunctionCall = NULL;
  nonLinearSystemData[14].analyticalJacobianColumn = OM_Result_functionJacNLSJac14_column;
  nonLinearSystemData[14].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac14;
  nonLinearSystemData[14].jacobianIndex = 14;
  nonLinearSystemData[14].initializeStaticNLSData = initializeStaticDataNLS348;
  nonLinearSystemData[14].getIterationVars = getIterationVarsNLS348;
  nonLinearSystemData[14].checkConstraints = NULL;
  
  
  nonLinearSystemData[15].equationIndex = 362;
  nonLinearSystemData[15].size = 1;
  nonLinearSystemData[15].homotopySupport = 0;
  nonLinearSystemData[15].mixedSystem = 0;
  nonLinearSystemData[15].residualFunc = residualFunc362;
  nonLinearSystemData[15].strictTearingFunctionCall = NULL;
  nonLinearSystemData[15].analyticalJacobianColumn = OM_Result_functionJacNLSJac15_column;
  nonLinearSystemData[15].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac15;
  nonLinearSystemData[15].jacobianIndex = 15;
  nonLinearSystemData[15].initializeStaticNLSData = initializeStaticDataNLS362;
  nonLinearSystemData[15].getIterationVars = getIterationVarsNLS362;
  nonLinearSystemData[15].checkConstraints = NULL;
}

#if defined(__cplusplus)
}
#endif


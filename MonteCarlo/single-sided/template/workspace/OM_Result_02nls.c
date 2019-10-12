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
  tmp0 = data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[103] /* Radiation_wall4_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[68]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
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
  data->localData[0]->realVars[69] /* Convection_wall4_inner._dT variable */ = data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
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
  data->localData[0]->realVars[68] /* Convection_wall4_inner._Q_flow variable */ = (data->simulationInfo->realParameter[23]) * (data->localData[0]->realVars[69] /* Convection_wall4_inner._dT variable */);
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
  data->localData[0]->realVars[45] /* Conduction_wall4_inner._Q_flow variable */ = data->localData[0]->realVars[103] /* Radiation_wall4_inner._Q_flow variable */ + data->localData[0]->realVars[68] /* Convection_wall4_inner._Q_flow variable */;
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
  data->localData[0]->realVars[46] /* Conduction_wall4_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[45] /* Conduction_wall4_inner._Q_flow variable */,data->simulationInfo->realParameter[15],"Conduction_wall4_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc32(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,32};
  /* iteration variables */
  data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */ = xloc[0];
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
  res[0] = data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */ + (-data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */) - data->localData[0]->realVars[46] /* Conduction_wall4_inner._dT variable */;
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
  sysData->nominal[i] = data->modelData->realVarsData[47].attribute /* Conduction_wall4_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[47].attribute /* Conduction_wall4_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[47].attribute /* Conduction_wall4_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS32(sysData);
}

void getIterationVarsNLS32(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */;
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
  tmp0 = data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[99] /* Radiation_wall3_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[66]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
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
  data->localData[0]->realVars[64] /* Convection_wall3_inner._dT variable */ = data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
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
  data->localData[0]->realVars[63] /* Convection_wall3_inner._Q_flow variable */ = (data->simulationInfo->realParameter[22]) * (data->localData[0]->realVars[64] /* Convection_wall3_inner._dT variable */);
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
  data->localData[0]->realVars[39] /* Conduction_wall3_inner._Q_flow variable */ = data->localData[0]->realVars[99] /* Radiation_wall3_inner._Q_flow variable */ + data->localData[0]->realVars[63] /* Convection_wall3_inner._Q_flow variable */;
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
  data->localData[0]->realVars[40] /* Conduction_wall3_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[39] /* Conduction_wall3_inner._Q_flow variable */,data->simulationInfo->realParameter[13],"Conduction_wall3_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc45(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,45};
  /* iteration variables */
  data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */ = xloc[0];
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
  res[0] = data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */ + (-data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */) - data->localData[0]->realVars[40] /* Conduction_wall3_inner._dT variable */;
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
  sysData->nominal[i] = data->modelData->realVarsData[41].attribute /* Conduction_wall3_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[41].attribute /* Conduction_wall3_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[41].attribute /* Conduction_wall3_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS45(sysData);
}

void getIterationVarsNLS45(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */;
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
  tmp0 = data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[95] /* Radiation_wall1_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[64]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
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
  data->localData[0]->realVars[59] /* Convection_wall1_inner._dT variable */ = data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
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
  data->localData[0]->realVars[58] /* Convection_wall1_inner._Q_flow variable */ = (data->simulationInfo->realParameter[21]) * (data->localData[0]->realVars[59] /* Convection_wall1_inner._dT variable */);
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
  data->localData[0]->realVars[33] /* Conduction_wall1_inner._Q_flow variable */ = data->localData[0]->realVars[95] /* Radiation_wall1_inner._Q_flow variable */ + data->localData[0]->realVars[58] /* Convection_wall1_inner._Q_flow variable */;
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
  data->localData[0]->realVars[34] /* Conduction_wall1_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[33] /* Conduction_wall1_inner._Q_flow variable */,data->simulationInfo->realParameter[11],"Conduction_wall1_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc58(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,58};
  /* iteration variables */
  data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */ = xloc[0];
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
  res[0] = data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */ + (-data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */) - data->localData[0]->realVars[34] /* Conduction_wall1_inner._dT variable */;
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
  sysData->nominal[i] = data->modelData->realVarsData[35].attribute /* Conduction_wall1_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[35].attribute /* Conduction_wall1_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[35].attribute /* Conduction_wall1_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS58(sysData);
}

void getIterationVarsNLS58(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */;
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
  tmp0 = data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[89] /* Radiation_roof_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[61]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
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
  tmp0 = data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->simulationInfo->realParameter[54];
  tmp1 *= tmp1;
  data->localData[0]->realVars[93] /* Radiation_roof_to_floor._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[63]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
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
  data->localData[0]->realVars[54] /* Convection_roof_inner._dT variable */ = data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
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
  data->localData[0]->realVars[53] /* Convection_roof_inner._Q_flow variable */ = (data->simulationInfo->realParameter[20]) * (data->localData[0]->realVars[54] /* Convection_roof_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 64
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._Q_flow = Radiation_roof_inner.Q_flow - ((-Convection_roof_inner.Q_flow) - Radiation_roof_to_floor.Q_flow)
 */
void OM_Result_eqFunction_64(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,64};
  data->localData[0]->realVars[27] /* Conduction_roof_inner._Q_flow variable */ = data->localData[0]->realVars[89] /* Radiation_roof_inner._Q_flow variable */ - ((-data->localData[0]->realVars[53] /* Convection_roof_inner._Q_flow variable */) - data->localData[0]->realVars[93] /* Radiation_roof_to_floor._Q_flow variable */);
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
  data->localData[0]->realVars[28] /* Conduction_roof_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[27] /* Conduction_roof_inner._Q_flow variable */,data->simulationInfo->realParameter[9],"Conduction_roof_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc73(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,73};
  /* iteration variables */
  data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */ = xloc[0];
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
  res[0] = data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */ + (-data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */) - data->localData[0]->realVars[28] /* Conduction_roof_inner._dT variable */;
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
  sysData->nominal[i] = data->modelData->realVarsData[29].attribute /* Conduction_roof_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[29].attribute /* Conduction_roof_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[29].attribute /* Conduction_roof_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS73(sysData);
}

void getIterationVarsNLS73(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 104
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._Q_flow = 5.670367e-08 * Radiation_wall4_outer.Gr * (OutdoorTemperature ^ 4.0 - Conduction_wall4_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_104(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,104};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[85] /* OutdoorTemperature variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[105] /* Radiation_wall4_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[69]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 105
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._dT = Conduction_wall4_outer.port_a.T - Capacitor_wall4.T
 */
void OM_Result_eqFunction_105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,105};
  data->localData[0]->realVars[49] /* Conduction_wall4_outer._dT variable */ = data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */ - data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */;
  TRACE_POP
}
/*
 equation index: 106
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._Q_flow = Conduction_wall4_outer.G * Conduction_wall4_outer.dT
 */
void OM_Result_eqFunction_106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,106};
  data->localData[0]->realVars[48] /* Conduction_wall4_outer._Q_flow variable */ = (data->simulationInfo->realParameter[16]) * (data->localData[0]->realVars[49] /* Conduction_wall4_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 107
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Q_flow = Conduction_wall4_outer.Q_flow - Radiation_wall4_outer.Q_flow
 */
void OM_Result_eqFunction_107(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,107};
  data->localData[0]->realVars[71] /* Convection_wall4_outer._Q_flow variable */ = data->localData[0]->realVars[48] /* Conduction_wall4_outer._Q_flow variable */ - data->localData[0]->realVars[105] /* Radiation_wall4_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 108
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._dT = OutdoorTemperature - Conduction_wall4_outer.port_a.T
 */
void OM_Result_eqFunction_108(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,108};
  data->localData[0]->realVars[72] /* Convection_wall4_outer._dT variable */ = data->localData[0]->realVars[85] /* OutdoorTemperature variable */ - data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */;
  TRACE_POP
}

void residualFunc114(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,114};
  /* iteration variables */
  data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_104(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_105(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_106(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_107(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_108(data, threadData);
  /* body */
  res[0] = (data->localData[0]->realVars[70] /* Convection_wall4_outer._Gc variable */) * (data->localData[0]->realVars[72] /* Convection_wall4_outer._dT variable */) - data->localData[0]->realVars[71] /* Convection_wall4_outer._Q_flow variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS114(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS114(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall4_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[50].attribute /* Conduction_wall4_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[50].attribute /* Conduction_wall4_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[50].attribute /* Conduction_wall4_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS114(sysData);
}

void getIterationVarsNLS114(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 120
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._Q_flow = 5.670367e-08 * Radiation_wall3_outer.Gr * (OutdoorTemperature ^ 4.0 - Conduction_wall3_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,120};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[85] /* OutdoorTemperature variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[101] /* Radiation_wall3_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[67]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 121
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._dT = OutdoorTemperature - Conduction_wall3_outer.port_a.T
 */
void OM_Result_eqFunction_121(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,121};
  data->localData[0]->realVars[67] /* Convection_wall3_outer._dT variable */ = data->localData[0]->realVars[85] /* OutdoorTemperature variable */ - data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 122
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Q_flow = Convection_wall3_outer.Gc * Convection_wall3_outer.dT
 */
void OM_Result_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,122};
  data->localData[0]->realVars[66] /* Convection_wall3_outer._Q_flow variable */ = (data->localData[0]->realVars[65] /* Convection_wall3_outer._Gc variable */) * (data->localData[0]->realVars[67] /* Convection_wall3_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 123
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._Q_flow = Convection_wall3_outer.Q_flow + Radiation_wall3_outer.Q_flow
 */
void OM_Result_eqFunction_123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,123};
  data->localData[0]->realVars[42] /* Conduction_wall3_outer._Q_flow variable */ = data->localData[0]->realVars[66] /* Convection_wall3_outer._Q_flow variable */ + data->localData[0]->realVars[101] /* Radiation_wall3_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 124
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._dT = DIVISION(Conduction_wall3_outer.Q_flow, Conduction_wall3_outer.G)
 */
void OM_Result_eqFunction_124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,124};
  data->localData[0]->realVars[43] /* Conduction_wall3_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[42] /* Conduction_wall3_outer._Q_flow variable */,data->simulationInfo->realParameter[14],"Conduction_wall3_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc131(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,131};
  /* iteration variables */
  data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_120(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_121(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_122(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_123(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_124(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */ + (-data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */) - data->localData[0]->realVars[43] /* Conduction_wall3_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS131(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS131(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[44].attribute /* Conduction_wall3_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[44].attribute /* Conduction_wall3_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[44].attribute /* Conduction_wall3_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS131(sysData);
}

void getIterationVarsNLS131(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 137
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._Q_flow = 5.670367e-08 * Radiation_wall1_outer.Gr * (OutdoorTemperature ^ 4.0 - Conduction_wall1_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_137(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,137};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[85] /* OutdoorTemperature variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[97] /* Radiation_wall1_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[65]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 138
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._dT = Conduction_wall1_outer.port_a.T - Capacitor_wall1.T
 */
void OM_Result_eqFunction_138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,138};
  data->localData[0]->realVars[37] /* Conduction_wall1_outer._dT variable */ = data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */ - data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */;
  TRACE_POP
}
/*
 equation index: 139
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._Q_flow = Conduction_wall1_outer.G * Conduction_wall1_outer.dT
 */
void OM_Result_eqFunction_139(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,139};
  data->localData[0]->realVars[36] /* Conduction_wall1_outer._Q_flow variable */ = (data->simulationInfo->realParameter[12]) * (data->localData[0]->realVars[37] /* Conduction_wall1_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 140
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Q_flow = Conduction_wall1_outer.Q_flow - Radiation_wall1_outer.Q_flow
 */
void OM_Result_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
  data->localData[0]->realVars[61] /* Convection_wall1_outer._Q_flow variable */ = data->localData[0]->realVars[36] /* Conduction_wall1_outer._Q_flow variable */ - data->localData[0]->realVars[97] /* Radiation_wall1_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 141
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._dT = OutdoorTemperature - Conduction_wall1_outer.port_a.T
 */
void OM_Result_eqFunction_141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,141};
  data->localData[0]->realVars[62] /* Convection_wall1_outer._dT variable */ = data->localData[0]->realVars[85] /* OutdoorTemperature variable */ - data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */;
  TRACE_POP
}

void residualFunc147(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,147};
  /* iteration variables */
  data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_137(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_138(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_139(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_140(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_141(data, threadData);
  /* body */
  res[0] = (data->localData[0]->realVars[60] /* Convection_wall1_outer._Gc variable */) * (data->localData[0]->realVars[62] /* Convection_wall1_outer._dT variable */) - data->localData[0]->realVars[61] /* Convection_wall1_outer._Q_flow variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS147(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS147(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[38].attribute /* Conduction_wall1_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[38].attribute /* Conduction_wall1_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[38].attribute /* Conduction_wall1_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS147(sysData);
}

void getIterationVarsNLS147(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 153
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._Q_flow = 5.670367e-08 * Radiation_roof_outer.Gr * (SkyTemperatureToK.T ^ 4.0 - Conduction_roof_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_153(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,153};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[107] /* SkyTemperatureToK._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[91] /* Radiation_roof_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[62]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 154
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._port._Q_flow = (-Heatflow_solar_radiation.Q_flow) * (1.0 + Heatflow_solar_radiation.alpha * (Conduction_roof_outer.port_a.T - Heatflow_solar_radiation.T_ref))
 */
void OM_Result_eqFunction_154(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,154};
  data->localData[0]->realVars[84] /* Heatflow_solar_radiation._port._Q_flow variable */ = ((-data->localData[0]->realVars[83] /* Heatflow_solar_radiation._Q_flow variable */)) * (1.0 + (data->simulationInfo->realParameter[58]) * (data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */ - data->simulationInfo->realParameter[57]));
  TRACE_POP
}
/*
 equation index: 155
 type: SIMPLE_ASSIGN
 Convection_roof_outer._dT = OutdoorTemperature - Conduction_roof_outer.port_a.T
 */
void OM_Result_eqFunction_155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,155};
  data->localData[0]->realVars[57] /* Convection_roof_outer._dT variable */ = data->localData[0]->realVars[85] /* OutdoorTemperature variable */ - data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 156
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Q_flow = Convection_roof_outer.Gc * Convection_roof_outer.dT
 */
void OM_Result_eqFunction_156(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,156};
  data->localData[0]->realVars[56] /* Convection_roof_outer._Q_flow variable */ = (data->localData[0]->realVars[55] /* Convection_roof_outer._Gc variable */) * (data->localData[0]->realVars[57] /* Convection_roof_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 157
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._Q_flow = Convection_roof_outer.Q_flow - (Heatflow_solar_radiation.port.Q_flow - Radiation_roof_outer.Q_flow)
 */
void OM_Result_eqFunction_157(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,157};
  data->localData[0]->realVars[30] /* Conduction_roof_outer._Q_flow variable */ = data->localData[0]->realVars[56] /* Convection_roof_outer._Q_flow variable */ - (data->localData[0]->realVars[84] /* Heatflow_solar_radiation._port._Q_flow variable */ - data->localData[0]->realVars[91] /* Radiation_roof_outer._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 158
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._dT = DIVISION(Conduction_roof_outer.Q_flow, Conduction_roof_outer.G)
 */
void OM_Result_eqFunction_158(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,158};
  data->localData[0]->realVars[31] /* Conduction_roof_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[30] /* Conduction_roof_outer._Q_flow variable */,data->simulationInfo->realParameter[10],"Conduction_roof_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc166(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,166};
  /* iteration variables */
  data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_153(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_154(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_155(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_156(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_157(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_158(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */ + (-data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */) - data->localData[0]->realVars[31] /* Conduction_roof_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS166(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS166(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_roof_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[32].attribute /* Conduction_roof_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[32].attribute /* Conduction_roof_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[32].attribute /* Conduction_roof_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS166(sysData);
}

void getIterationVarsNLS166(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */;
}

/* inner equations */

/*
 equation index: 256
 type: SIMPLE_ASSIGN
 Radiation_wall4_inner._Q_flow = 5.670367e-08 * Radiation_wall4_inner.Gr * (Conduction_wall4_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_256(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,256};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[103] /* Radiation_wall4_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[68]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 257
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._dT = Capacitor_wall4.T - Conduction_wall4_inner.port_b.T
 */
void OM_Result_eqFunction_257(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,257};
  data->localData[0]->realVars[46] /* Conduction_wall4_inner._dT variable */ = data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */ - data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */;
  TRACE_POP
}
/*
 equation index: 258
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._Q_flow = Conduction_wall4_inner.G * Conduction_wall4_inner.dT
 */
void OM_Result_eqFunction_258(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,258};
  data->localData[0]->realVars[45] /* Conduction_wall4_inner._Q_flow variable */ = (data->simulationInfo->realParameter[15]) * (data->localData[0]->realVars[46] /* Conduction_wall4_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 259
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._Q_flow = Conduction_wall4_inner.Q_flow - Radiation_wall4_inner.Q_flow
 */
void OM_Result_eqFunction_259(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,259};
  data->localData[0]->realVars[68] /* Convection_wall4_inner._Q_flow variable */ = data->localData[0]->realVars[45] /* Conduction_wall4_inner._Q_flow variable */ - data->localData[0]->realVars[103] /* Radiation_wall4_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 260
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._dT = DIVISION(Convection_wall4_inner.Q_flow, Convection_coef_wall4_inner.k)
 */
void OM_Result_eqFunction_260(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,260};
  data->localData[0]->realVars[69] /* Convection_wall4_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[68] /* Convection_wall4_inner._Q_flow variable */,data->simulationInfo->realParameter[23],"Convection_coef_wall4_inner.k",equationIndexes);
  TRACE_POP
}

void residualFunc267(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,267};
  /* iteration variables */
  data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */ = xloc[0];
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
  res[0] = data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */ + (-data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */) - data->localData[0]->realVars[69] /* Convection_wall4_inner._dT variable */;
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
  /* static nls data for Conduction_wall4_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[47].attribute /* Conduction_wall4_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[47].attribute /* Conduction_wall4_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[47].attribute /* Conduction_wall4_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS267(sysData);
}

void getIterationVarsNLS267(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 269
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._Q_flow = 5.670367e-08 * Radiation_wall4_outer.Gr * (OutdoorTemperature ^ 4.0 - Conduction_wall4_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_269(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,269};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[85] /* OutdoorTemperature variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[105] /* Radiation_wall4_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[69]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 270
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._dT = OutdoorTemperature - Conduction_wall4_outer.port_a.T
 */
void OM_Result_eqFunction_270(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,270};
  data->localData[0]->realVars[72] /* Convection_wall4_outer._dT variable */ = data->localData[0]->realVars[85] /* OutdoorTemperature variable */ - data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 271
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Q_flow = Convection_wall4_outer.Gc * Convection_wall4_outer.dT
 */
void OM_Result_eqFunction_271(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,271};
  data->localData[0]->realVars[71] /* Convection_wall4_outer._Q_flow variable */ = (data->localData[0]->realVars[70] /* Convection_wall4_outer._Gc variable */) * (data->localData[0]->realVars[72] /* Convection_wall4_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 272
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._Q_flow = Convection_wall4_outer.Q_flow + Radiation_wall4_outer.Q_flow
 */
void OM_Result_eqFunction_272(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,272};
  data->localData[0]->realVars[48] /* Conduction_wall4_outer._Q_flow variable */ = data->localData[0]->realVars[71] /* Convection_wall4_outer._Q_flow variable */ + data->localData[0]->realVars[105] /* Radiation_wall4_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 273
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._dT = DIVISION(Conduction_wall4_outer.Q_flow, Conduction_wall4_outer.G)
 */
void OM_Result_eqFunction_273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,273};
  data->localData[0]->realVars[49] /* Conduction_wall4_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[48] /* Conduction_wall4_outer._Q_flow variable */,data->simulationInfo->realParameter[16],"Conduction_wall4_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc280(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,280};
  /* iteration variables */
  data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */ = xloc[0];
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
  res[0] = data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */ + (-data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */) - data->localData[0]->realVars[49] /* Conduction_wall4_outer._dT variable */;
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
  /* static nls data for Conduction_wall4_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[50].attribute /* Conduction_wall4_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[50].attribute /* Conduction_wall4_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[50].attribute /* Conduction_wall4_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS280(sysData);
}

void getIterationVarsNLS280(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 285
 type: SIMPLE_ASSIGN
 Radiation_wall3_inner._Q_flow = 5.670367e-08 * Radiation_wall3_inner.Gr * (Conduction_wall3_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,285};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[99] /* Radiation_wall3_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[66]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 286
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._dT = Conduction_wall3_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,286};
  data->localData[0]->realVars[64] /* Convection_wall3_inner._dT variable */ = data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 287
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._Q_flow = Convection_coef_wall3_inner.k * Convection_wall3_inner.dT
 */
void OM_Result_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
  data->localData[0]->realVars[63] /* Convection_wall3_inner._Q_flow variable */ = (data->simulationInfo->realParameter[22]) * (data->localData[0]->realVars[64] /* Convection_wall3_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 288
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._Q_flow = Radiation_wall3_inner.Q_flow + Convection_wall3_inner.Q_flow
 */
void OM_Result_eqFunction_288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,288};
  data->localData[0]->realVars[39] /* Conduction_wall3_inner._Q_flow variable */ = data->localData[0]->realVars[99] /* Radiation_wall3_inner._Q_flow variable */ + data->localData[0]->realVars[63] /* Convection_wall3_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 289
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._dT = DIVISION(Conduction_wall3_inner.Q_flow, Conduction_wall3_inner.G)
 */
void OM_Result_eqFunction_289(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,289};
  data->localData[0]->realVars[40] /* Conduction_wall3_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[39] /* Conduction_wall3_inner._Q_flow variable */,data->simulationInfo->realParameter[13],"Conduction_wall3_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc296(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,296};
  /* iteration variables */
  data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */ = xloc[0];
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
  /* body */
  res[0] = data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */ + (-data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */) - data->localData[0]->realVars[40] /* Conduction_wall3_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS296(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS296(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[41].attribute /* Conduction_wall3_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[41].attribute /* Conduction_wall3_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[41].attribute /* Conduction_wall3_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS296(sysData);
}

void getIterationVarsNLS296(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 298
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._Q_flow = 5.670367e-08 * Radiation_wall3_outer.Gr * (OutdoorTemperature ^ 4.0 - Conduction_wall3_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,298};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[85] /* OutdoorTemperature variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[101] /* Radiation_wall3_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[67]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 299
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._dT = OutdoorTemperature - Conduction_wall3_outer.port_a.T
 */
void OM_Result_eqFunction_299(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,299};
  data->localData[0]->realVars[67] /* Convection_wall3_outer._dT variable */ = data->localData[0]->realVars[85] /* OutdoorTemperature variable */ - data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 300
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Q_flow = Convection_wall3_outer.Gc * Convection_wall3_outer.dT
 */
void OM_Result_eqFunction_300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,300};
  data->localData[0]->realVars[66] /* Convection_wall3_outer._Q_flow variable */ = (data->localData[0]->realVars[65] /* Convection_wall3_outer._Gc variable */) * (data->localData[0]->realVars[67] /* Convection_wall3_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 301
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._Q_flow = Convection_wall3_outer.Q_flow + Radiation_wall3_outer.Q_flow
 */
void OM_Result_eqFunction_301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,301};
  data->localData[0]->realVars[42] /* Conduction_wall3_outer._Q_flow variable */ = data->localData[0]->realVars[66] /* Convection_wall3_outer._Q_flow variable */ + data->localData[0]->realVars[101] /* Radiation_wall3_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 302
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._dT = DIVISION(Conduction_wall3_outer.Q_flow, Conduction_wall3_outer.G)
 */
void OM_Result_eqFunction_302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,302};
  data->localData[0]->realVars[43] /* Conduction_wall3_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[42] /* Conduction_wall3_outer._Q_flow variable */,data->simulationInfo->realParameter[14],"Conduction_wall3_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc309(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,309};
  /* iteration variables */
  data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_298(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_299(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_300(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_301(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_302(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */ + (-data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */) - data->localData[0]->realVars[43] /* Conduction_wall3_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS309(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS309(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[44].attribute /* Conduction_wall3_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[44].attribute /* Conduction_wall3_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[44].attribute /* Conduction_wall3_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS309(sysData);
}

void getIterationVarsNLS309(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 314
 type: SIMPLE_ASSIGN
 Radiation_roof_to_floor._Q_flow = 5.670367e-08 * Radiation_roof_to_floor.Gr * (Conduction_roof_inner.port_b.T ^ 4.0 - Floor_temperature.k ^ 4.0)
 */
void OM_Result_eqFunction_314(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,314};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->simulationInfo->realParameter[54];
  tmp1 *= tmp1;
  data->localData[0]->realVars[93] /* Radiation_roof_to_floor._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[63]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 315
 type: SIMPLE_ASSIGN
 Radiation_roof_inner._Q_flow = 5.670367e-08 * Radiation_roof_inner.Gr * (Conduction_roof_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_315(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,315};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[89] /* Radiation_roof_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[61]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 316
 type: SIMPLE_ASSIGN
 Convection_roof_inner._dT = Conduction_roof_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_316(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,316};
  data->localData[0]->realVars[54] /* Convection_roof_inner._dT variable */ = data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 317
 type: SIMPLE_ASSIGN
 Convection_roof_inner._Q_flow = Convection_coef_roof_inner.k * Convection_roof_inner.dT
 */
void OM_Result_eqFunction_317(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,317};
  data->localData[0]->realVars[53] /* Convection_roof_inner._Q_flow variable */ = (data->simulationInfo->realParameter[20]) * (data->localData[0]->realVars[54] /* Convection_roof_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 318
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._Q_flow = Radiation_roof_inner.Q_flow - ((-Convection_roof_inner.Q_flow) - Radiation_roof_to_floor.Q_flow)
 */
void OM_Result_eqFunction_318(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,318};
  data->localData[0]->realVars[27] /* Conduction_roof_inner._Q_flow variable */ = data->localData[0]->realVars[89] /* Radiation_roof_inner._Q_flow variable */ - ((-data->localData[0]->realVars[53] /* Convection_roof_inner._Q_flow variable */) - data->localData[0]->realVars[93] /* Radiation_roof_to_floor._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 319
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._dT = DIVISION(Conduction_roof_inner.Q_flow, Conduction_roof_inner.G)
 */
void OM_Result_eqFunction_319(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,319};
  data->localData[0]->realVars[28] /* Conduction_roof_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[27] /* Conduction_roof_inner._Q_flow variable */,data->simulationInfo->realParameter[9],"Conduction_roof_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc327(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,327};
  /* iteration variables */
  data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_314(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_315(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_316(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_317(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_318(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_319(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */ + (-data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */) - data->localData[0]->realVars[28] /* Conduction_roof_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS327(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS327(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_roof_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[29].attribute /* Conduction_roof_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[29].attribute /* Conduction_roof_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[29].attribute /* Conduction_roof_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS327(sysData);
}

void getIterationVarsNLS327(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 331
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._Q_flow = 5.670367e-08 * Radiation_roof_outer.Gr * (SkyTemperatureToK.T ^ 4.0 - Conduction_roof_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_331(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,331};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[107] /* SkyTemperatureToK._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[91] /* Radiation_roof_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[62]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 332
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._port._Q_flow = (-Heatflow_solar_radiation.Q_flow) * (1.0 + Heatflow_solar_radiation.alpha * (Conduction_roof_outer.port_a.T - Heatflow_solar_radiation.T_ref))
 */
void OM_Result_eqFunction_332(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,332};
  data->localData[0]->realVars[84] /* Heatflow_solar_radiation._port._Q_flow variable */ = ((-data->localData[0]->realVars[83] /* Heatflow_solar_radiation._Q_flow variable */)) * (1.0 + (data->simulationInfo->realParameter[58]) * (data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */ - data->simulationInfo->realParameter[57]));
  TRACE_POP
}
/*
 equation index: 333
 type: SIMPLE_ASSIGN
 Convection_roof_outer._dT = OutdoorTemperature - Conduction_roof_outer.port_a.T
 */
void OM_Result_eqFunction_333(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,333};
  data->localData[0]->realVars[57] /* Convection_roof_outer._dT variable */ = data->localData[0]->realVars[85] /* OutdoorTemperature variable */ - data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 334
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Q_flow = Convection_roof_outer.Gc * Convection_roof_outer.dT
 */
void OM_Result_eqFunction_334(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,334};
  data->localData[0]->realVars[56] /* Convection_roof_outer._Q_flow variable */ = (data->localData[0]->realVars[55] /* Convection_roof_outer._Gc variable */) * (data->localData[0]->realVars[57] /* Convection_roof_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 335
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._Q_flow = Convection_roof_outer.Q_flow - (Heatflow_solar_radiation.port.Q_flow - Radiation_roof_outer.Q_flow)
 */
void OM_Result_eqFunction_335(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,335};
  data->localData[0]->realVars[30] /* Conduction_roof_outer._Q_flow variable */ = data->localData[0]->realVars[56] /* Convection_roof_outer._Q_flow variable */ - (data->localData[0]->realVars[84] /* Heatflow_solar_radiation._port._Q_flow variable */ - data->localData[0]->realVars[91] /* Radiation_roof_outer._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 336
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._dT = DIVISION(Conduction_roof_outer.Q_flow, Conduction_roof_outer.G)
 */
void OM_Result_eqFunction_336(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,336};
  data->localData[0]->realVars[31] /* Conduction_roof_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[30] /* Conduction_roof_outer._Q_flow variable */,data->simulationInfo->realParameter[10],"Conduction_roof_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc344(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,344};
  /* iteration variables */
  data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_331(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_332(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_333(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_334(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_335(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_336(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */ + (-data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */) - data->localData[0]->realVars[31] /* Conduction_roof_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS344(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS344(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_roof_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[32].attribute /* Conduction_roof_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[32].attribute /* Conduction_roof_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[32].attribute /* Conduction_roof_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS344(sysData);
}

void getIterationVarsNLS344(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 349
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._Q_flow = 5.670367e-08 * Radiation_wall1_outer.Gr * (OutdoorTemperature ^ 4.0 - Conduction_wall1_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_349(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,349};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[85] /* OutdoorTemperature variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[97] /* Radiation_wall1_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[65]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 350
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._dT = OutdoorTemperature - Conduction_wall1_outer.port_a.T
 */
void OM_Result_eqFunction_350(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,350};
  data->localData[0]->realVars[62] /* Convection_wall1_outer._dT variable */ = data->localData[0]->realVars[85] /* OutdoorTemperature variable */ - data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 351
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Q_flow = Convection_wall1_outer.Gc * Convection_wall1_outer.dT
 */
void OM_Result_eqFunction_351(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,351};
  data->localData[0]->realVars[61] /* Convection_wall1_outer._Q_flow variable */ = (data->localData[0]->realVars[60] /* Convection_wall1_outer._Gc variable */) * (data->localData[0]->realVars[62] /* Convection_wall1_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 352
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._Q_flow = Convection_wall1_outer.Q_flow + Radiation_wall1_outer.Q_flow
 */
void OM_Result_eqFunction_352(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,352};
  data->localData[0]->realVars[36] /* Conduction_wall1_outer._Q_flow variable */ = data->localData[0]->realVars[61] /* Convection_wall1_outer._Q_flow variable */ + data->localData[0]->realVars[97] /* Radiation_wall1_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 353
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._dT = DIVISION(Conduction_wall1_outer.Q_flow, Conduction_wall1_outer.G)
 */
void OM_Result_eqFunction_353(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,353};
  data->localData[0]->realVars[37] /* Conduction_wall1_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[36] /* Conduction_wall1_outer._Q_flow variable */,data->simulationInfo->realParameter[12],"Conduction_wall1_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc360(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,360};
  /* iteration variables */
  data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_349(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_350(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_351(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_352(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_353(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */ + (-data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */) - data->localData[0]->realVars[37] /* Conduction_wall1_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS360(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS360(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[38].attribute /* Conduction_wall1_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[38].attribute /* Conduction_wall1_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[38].attribute /* Conduction_wall1_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS360(sysData);
}

void getIterationVarsNLS360(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 363
 type: SIMPLE_ASSIGN
 Radiation_wall1_inner._Q_flow = 5.670367e-08 * Radiation_wall1_inner.Gr * (Conduction_wall1_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_363(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,363};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[95] /* Radiation_wall1_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[64]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 364
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._dT = Conduction_wall1_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_364(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,364};
  data->localData[0]->realVars[59] /* Convection_wall1_inner._dT variable */ = data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 365
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._Q_flow = Convection_coef_wall1_inner.k * Convection_wall1_inner.dT
 */
void OM_Result_eqFunction_365(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,365};
  data->localData[0]->realVars[58] /* Convection_wall1_inner._Q_flow variable */ = (data->simulationInfo->realParameter[21]) * (data->localData[0]->realVars[59] /* Convection_wall1_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 366
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._Q_flow = Radiation_wall1_inner.Q_flow + Convection_wall1_inner.Q_flow
 */
void OM_Result_eqFunction_366(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,366};
  data->localData[0]->realVars[33] /* Conduction_wall1_inner._Q_flow variable */ = data->localData[0]->realVars[95] /* Radiation_wall1_inner._Q_flow variable */ + data->localData[0]->realVars[58] /* Convection_wall1_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 367
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._dT = DIVISION(Conduction_wall1_inner.Q_flow, Conduction_wall1_inner.G)
 */
void OM_Result_eqFunction_367(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,367};
  data->localData[0]->realVars[34] /* Conduction_wall1_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[33] /* Conduction_wall1_inner._Q_flow variable */,data->simulationInfo->realParameter[11],"Conduction_wall1_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc374(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,374};
  /* iteration variables */
  data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_363(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_364(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_365(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_366(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_367(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */ + (-data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */) - data->localData[0]->realVars[34] /* Conduction_wall1_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS374(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS374(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[35].attribute /* Conduction_wall1_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[35].attribute /* Conduction_wall1_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[35].attribute /* Conduction_wall1_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS374(sysData);
}

void getIterationVarsNLS374(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */;
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
  
  
  nonLinearSystemData[4].equationIndex = 114;
  nonLinearSystemData[4].size = 1;
  nonLinearSystemData[4].homotopySupport = 0;
  nonLinearSystemData[4].mixedSystem = 0;
  nonLinearSystemData[4].residualFunc = residualFunc114;
  nonLinearSystemData[4].strictTearingFunctionCall = NULL;
  nonLinearSystemData[4].analyticalJacobianColumn = OM_Result_functionJacNLSJac4_column;
  nonLinearSystemData[4].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac4;
  nonLinearSystemData[4].jacobianIndex = 4;
  nonLinearSystemData[4].initializeStaticNLSData = initializeStaticDataNLS114;
  nonLinearSystemData[4].getIterationVars = getIterationVarsNLS114;
  nonLinearSystemData[4].checkConstraints = NULL;
  
  
  nonLinearSystemData[5].equationIndex = 131;
  nonLinearSystemData[5].size = 1;
  nonLinearSystemData[5].homotopySupport = 0;
  nonLinearSystemData[5].mixedSystem = 0;
  nonLinearSystemData[5].residualFunc = residualFunc131;
  nonLinearSystemData[5].strictTearingFunctionCall = NULL;
  nonLinearSystemData[5].analyticalJacobianColumn = OM_Result_functionJacNLSJac5_column;
  nonLinearSystemData[5].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac5;
  nonLinearSystemData[5].jacobianIndex = 5;
  nonLinearSystemData[5].initializeStaticNLSData = initializeStaticDataNLS131;
  nonLinearSystemData[5].getIterationVars = getIterationVarsNLS131;
  nonLinearSystemData[5].checkConstraints = NULL;
  
  
  nonLinearSystemData[6].equationIndex = 147;
  nonLinearSystemData[6].size = 1;
  nonLinearSystemData[6].homotopySupport = 0;
  nonLinearSystemData[6].mixedSystem = 0;
  nonLinearSystemData[6].residualFunc = residualFunc147;
  nonLinearSystemData[6].strictTearingFunctionCall = NULL;
  nonLinearSystemData[6].analyticalJacobianColumn = OM_Result_functionJacNLSJac6_column;
  nonLinearSystemData[6].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac6;
  nonLinearSystemData[6].jacobianIndex = 6;
  nonLinearSystemData[6].initializeStaticNLSData = initializeStaticDataNLS147;
  nonLinearSystemData[6].getIterationVars = getIterationVarsNLS147;
  nonLinearSystemData[6].checkConstraints = NULL;
  
  
  nonLinearSystemData[7].equationIndex = 166;
  nonLinearSystemData[7].size = 1;
  nonLinearSystemData[7].homotopySupport = 0;
  nonLinearSystemData[7].mixedSystem = 0;
  nonLinearSystemData[7].residualFunc = residualFunc166;
  nonLinearSystemData[7].strictTearingFunctionCall = NULL;
  nonLinearSystemData[7].analyticalJacobianColumn = OM_Result_functionJacNLSJac7_column;
  nonLinearSystemData[7].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac7;
  nonLinearSystemData[7].jacobianIndex = 7;
  nonLinearSystemData[7].initializeStaticNLSData = initializeStaticDataNLS166;
  nonLinearSystemData[7].getIterationVars = getIterationVarsNLS166;
  nonLinearSystemData[7].checkConstraints = NULL;
  
  nonLinearSystemData[8].equationIndex = 267;
  nonLinearSystemData[8].size = 1;
  nonLinearSystemData[8].homotopySupport = 0;
  nonLinearSystemData[8].mixedSystem = 0;
  nonLinearSystemData[8].residualFunc = residualFunc267;
  nonLinearSystemData[8].strictTearingFunctionCall = NULL;
  nonLinearSystemData[8].analyticalJacobianColumn = OM_Result_functionJacNLSJac8_column;
  nonLinearSystemData[8].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac8;
  nonLinearSystemData[8].jacobianIndex = 8;
  nonLinearSystemData[8].initializeStaticNLSData = initializeStaticDataNLS267;
  nonLinearSystemData[8].getIterationVars = getIterationVarsNLS267;
  nonLinearSystemData[8].checkConstraints = NULL;
  
  
  nonLinearSystemData[9].equationIndex = 280;
  nonLinearSystemData[9].size = 1;
  nonLinearSystemData[9].homotopySupport = 0;
  nonLinearSystemData[9].mixedSystem = 0;
  nonLinearSystemData[9].residualFunc = residualFunc280;
  nonLinearSystemData[9].strictTearingFunctionCall = NULL;
  nonLinearSystemData[9].analyticalJacobianColumn = OM_Result_functionJacNLSJac9_column;
  nonLinearSystemData[9].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac9;
  nonLinearSystemData[9].jacobianIndex = 9;
  nonLinearSystemData[9].initializeStaticNLSData = initializeStaticDataNLS280;
  nonLinearSystemData[9].getIterationVars = getIterationVarsNLS280;
  nonLinearSystemData[9].checkConstraints = NULL;
  
  
  nonLinearSystemData[10].equationIndex = 296;
  nonLinearSystemData[10].size = 1;
  nonLinearSystemData[10].homotopySupport = 0;
  nonLinearSystemData[10].mixedSystem = 0;
  nonLinearSystemData[10].residualFunc = residualFunc296;
  nonLinearSystemData[10].strictTearingFunctionCall = NULL;
  nonLinearSystemData[10].analyticalJacobianColumn = OM_Result_functionJacNLSJac10_column;
  nonLinearSystemData[10].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac10;
  nonLinearSystemData[10].jacobianIndex = 10;
  nonLinearSystemData[10].initializeStaticNLSData = initializeStaticDataNLS296;
  nonLinearSystemData[10].getIterationVars = getIterationVarsNLS296;
  nonLinearSystemData[10].checkConstraints = NULL;
  
  
  nonLinearSystemData[11].equationIndex = 309;
  nonLinearSystemData[11].size = 1;
  nonLinearSystemData[11].homotopySupport = 0;
  nonLinearSystemData[11].mixedSystem = 0;
  nonLinearSystemData[11].residualFunc = residualFunc309;
  nonLinearSystemData[11].strictTearingFunctionCall = NULL;
  nonLinearSystemData[11].analyticalJacobianColumn = OM_Result_functionJacNLSJac11_column;
  nonLinearSystemData[11].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac11;
  nonLinearSystemData[11].jacobianIndex = 11;
  nonLinearSystemData[11].initializeStaticNLSData = initializeStaticDataNLS309;
  nonLinearSystemData[11].getIterationVars = getIterationVarsNLS309;
  nonLinearSystemData[11].checkConstraints = NULL;
  
  
  nonLinearSystemData[12].equationIndex = 327;
  nonLinearSystemData[12].size = 1;
  nonLinearSystemData[12].homotopySupport = 0;
  nonLinearSystemData[12].mixedSystem = 0;
  nonLinearSystemData[12].residualFunc = residualFunc327;
  nonLinearSystemData[12].strictTearingFunctionCall = NULL;
  nonLinearSystemData[12].analyticalJacobianColumn = OM_Result_functionJacNLSJac12_column;
  nonLinearSystemData[12].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac12;
  nonLinearSystemData[12].jacobianIndex = 12;
  nonLinearSystemData[12].initializeStaticNLSData = initializeStaticDataNLS327;
  nonLinearSystemData[12].getIterationVars = getIterationVarsNLS327;
  nonLinearSystemData[12].checkConstraints = NULL;
  
  
  nonLinearSystemData[13].equationIndex = 344;
  nonLinearSystemData[13].size = 1;
  nonLinearSystemData[13].homotopySupport = 0;
  nonLinearSystemData[13].mixedSystem = 0;
  nonLinearSystemData[13].residualFunc = residualFunc344;
  nonLinearSystemData[13].strictTearingFunctionCall = NULL;
  nonLinearSystemData[13].analyticalJacobianColumn = OM_Result_functionJacNLSJac13_column;
  nonLinearSystemData[13].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac13;
  nonLinearSystemData[13].jacobianIndex = 13;
  nonLinearSystemData[13].initializeStaticNLSData = initializeStaticDataNLS344;
  nonLinearSystemData[13].getIterationVars = getIterationVarsNLS344;
  nonLinearSystemData[13].checkConstraints = NULL;
  
  
  nonLinearSystemData[14].equationIndex = 360;
  nonLinearSystemData[14].size = 1;
  nonLinearSystemData[14].homotopySupport = 0;
  nonLinearSystemData[14].mixedSystem = 0;
  nonLinearSystemData[14].residualFunc = residualFunc360;
  nonLinearSystemData[14].strictTearingFunctionCall = NULL;
  nonLinearSystemData[14].analyticalJacobianColumn = OM_Result_functionJacNLSJac14_column;
  nonLinearSystemData[14].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac14;
  nonLinearSystemData[14].jacobianIndex = 14;
  nonLinearSystemData[14].initializeStaticNLSData = initializeStaticDataNLS360;
  nonLinearSystemData[14].getIterationVars = getIterationVarsNLS360;
  nonLinearSystemData[14].checkConstraints = NULL;
  
  
  nonLinearSystemData[15].equationIndex = 374;
  nonLinearSystemData[15].size = 1;
  nonLinearSystemData[15].homotopySupport = 0;
  nonLinearSystemData[15].mixedSystem = 0;
  nonLinearSystemData[15].residualFunc = residualFunc374;
  nonLinearSystemData[15].strictTearingFunctionCall = NULL;
  nonLinearSystemData[15].analyticalJacobianColumn = OM_Result_functionJacNLSJac15_column;
  nonLinearSystemData[15].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac15;
  nonLinearSystemData[15].jacobianIndex = 15;
  nonLinearSystemData[15].initializeStaticNLSData = initializeStaticDataNLS374;
  nonLinearSystemData[15].getIterationVars = getIterationVarsNLS374;
  nonLinearSystemData[15].checkConstraints = NULL;
}

#if defined(__cplusplus)
}
#endif


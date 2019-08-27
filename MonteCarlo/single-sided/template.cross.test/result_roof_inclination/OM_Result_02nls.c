/* Non Linear Systems */
#include "OM_Result_model.h"
#include "OM_Result_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* inner equations */

/*
 equation index: 23
 type: SIMPLE_ASSIGN
 Radiation_wall4_inner._Q_flow = 5.670367e-08 * Radiation_wall4_inner.Gr * (Conduction_wall4_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[88] /* Radiation_wall4_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[62]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 24
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._dT = Conduction_wall4_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  data->localData[0]->realVars[62] /* Convection_wall4_inner._dT variable */ = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 25
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._Q_flow = Convection_coef_wall4_inner.k * Convection_wall4_inner.dT
 */
void OM_Result_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  data->localData[0]->realVars[61] /* Convection_wall4_inner._Q_flow variable */ = (data->simulationInfo->realParameter[20]) * (data->localData[0]->realVars[62] /* Convection_wall4_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 26
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._Q_flow = Radiation_wall4_inner.Q_flow + Convection_wall4_inner.Q_flow
 */
void OM_Result_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  data->localData[0]->realVars[41] /* Conduction_wall4_inner._Q_flow variable */ = data->localData[0]->realVars[88] /* Radiation_wall4_inner._Q_flow variable */ + data->localData[0]->realVars[61] /* Convection_wall4_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 27
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._dT = DIVISION(Conduction_wall4_inner.Q_flow, Conduction_wall4_inner.G)
 */
void OM_Result_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  data->localData[0]->realVars[42] /* Conduction_wall4_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[41] /* Conduction_wall4_inner._Q_flow variable */,data->simulationInfo->realParameter[11],"Conduction_wall4_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc34(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,34};
  /* iteration variables */
  data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_23(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_24(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_25(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_26(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_27(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */ + (-data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */) - data->localData[0]->realVars[42] /* Conduction_wall4_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS34(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS34(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall4_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS34(sysData);
}

void getIterationVarsNLS34(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 36
 type: SIMPLE_ASSIGN
 Radiation_wall3_inner._Q_flow = 5.670367e-08 * Radiation_wall3_inner.Gr * (Conduction_wall3_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[84] /* Radiation_wall3_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[60]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 37
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._dT = Conduction_wall3_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  data->localData[0]->realVars[58] /* Convection_wall3_inner._dT variable */ = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 38
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._Q_flow = Convection_coef_wall3_inner.k * Convection_wall3_inner.dT
 */
void OM_Result_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  data->localData[0]->realVars[57] /* Convection_wall3_inner._Q_flow variable */ = (data->simulationInfo->realParameter[18]) * (data->localData[0]->realVars[58] /* Convection_wall3_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 39
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._Q_flow = Radiation_wall3_inner.Q_flow + Convection_wall3_inner.Q_flow
 */
void OM_Result_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  data->localData[0]->realVars[35] /* Conduction_wall3_inner._Q_flow variable */ = data->localData[0]->realVars[84] /* Radiation_wall3_inner._Q_flow variable */ + data->localData[0]->realVars[57] /* Convection_wall3_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 40
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._dT = DIVISION(Conduction_wall3_inner.Q_flow, Conduction_wall3_inner.G)
 */
void OM_Result_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  data->localData[0]->realVars[36] /* Conduction_wall3_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[35] /* Conduction_wall3_inner._Q_flow variable */,data->simulationInfo->realParameter[9],"Conduction_wall3_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc47(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,47};
  /* iteration variables */
  data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_36(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_37(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_38(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_39(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_40(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */ + (-data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */) - data->localData[0]->realVars[36] /* Conduction_wall3_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS47(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS47(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS47(sysData);
}

void getIterationVarsNLS47(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 49
 type: SIMPLE_ASSIGN
 Radiation_wall1_inner._Q_flow = 5.670367e-08 * Radiation_wall1_inner.Gr * (Conduction_wall1_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[80] /* Radiation_wall1_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[58]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 50
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._dT = Conduction_wall1_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
  data->localData[0]->realVars[54] /* Convection_wall1_inner._dT variable */ = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 51
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._Q_flow = Convection_coef_wall1_inner.k * Convection_wall1_inner.dT
 */
void OM_Result_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
  data->localData[0]->realVars[53] /* Convection_wall1_inner._Q_flow variable */ = (data->simulationInfo->realParameter[16]) * (data->localData[0]->realVars[54] /* Convection_wall1_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 52
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._Q_flow = Radiation_wall1_inner.Q_flow + Convection_wall1_inner.Q_flow
 */
void OM_Result_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
  data->localData[0]->realVars[29] /* Conduction_wall1_inner._Q_flow variable */ = data->localData[0]->realVars[80] /* Radiation_wall1_inner._Q_flow variable */ + data->localData[0]->realVars[53] /* Convection_wall1_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 53
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._dT = DIVISION(Conduction_wall1_inner.Q_flow, Conduction_wall1_inner.G)
 */
void OM_Result_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
  data->localData[0]->realVars[30] /* Conduction_wall1_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[29] /* Conduction_wall1_inner._Q_flow variable */,data->simulationInfo->realParameter[7],"Conduction_wall1_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc60(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,60};
  /* iteration variables */
  data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_49(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_50(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_51(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_52(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_53(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */ + (-data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */) - data->localData[0]->realVars[30] /* Conduction_wall1_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS60(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS60(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS60(sysData);
}

void getIterationVarsNLS60(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 62
 type: SIMPLE_ASSIGN
 Radiation_roof_inner._Q_flow = 5.670367e-08 * Radiation_roof_inner.Gr * (Conduction_roof_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_62(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[76] /* Radiation_roof_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[56]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
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
 Conduction_roof_inner._Q_flow = Radiation_roof_inner.Q_flow + Convection_roof_inner.Q_flow
 */
void OM_Result_eqFunction_65(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
  data->localData[0]->realVars[23] /* Conduction_roof_inner._Q_flow variable */ = data->localData[0]->realVars[76] /* Radiation_roof_inner._Q_flow variable */ + data->localData[0]->realVars[49] /* Convection_roof_inner._Q_flow variable */;
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
 equation index: 89
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._Q_flow = 5.670367e-08 * Radiation_wall3_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall3_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_89(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,89};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[86] /* Radiation_wall3_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[61]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 90
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall3_outer.port_a.T
 */
void OM_Result_eqFunction_90(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,90};
  data->localData[0]->realVars[60] /* Convection_wall3_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 91
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Q_flow = Convection_coef_wall3_outer.k * Convection_wall3_outer.dT
 */
void OM_Result_eqFunction_91(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,91};
  data->localData[0]->realVars[59] /* Convection_wall3_outer._Q_flow variable */ = (data->simulationInfo->realParameter[19]) * (data->localData[0]->realVars[60] /* Convection_wall3_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 92
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._Q_flow = Radiation_wall3_outer.Q_flow + Convection_wall3_outer.Q_flow
 */
void OM_Result_eqFunction_92(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,92};
  data->localData[0]->realVars[38] /* Conduction_wall3_outer._Q_flow variable */ = data->localData[0]->realVars[86] /* Radiation_wall3_outer._Q_flow variable */ + data->localData[0]->realVars[59] /* Convection_wall3_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 93
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._dT = DIVISION(Conduction_wall3_outer.Q_flow, Conduction_wall3_outer.G)
 */
void OM_Result_eqFunction_93(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,93};
  data->localData[0]->realVars[39] /* Conduction_wall3_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[38] /* Conduction_wall3_outer._Q_flow variable */,data->simulationInfo->realParameter[10],"Conduction_wall3_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc100(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,100};
  /* iteration variables */
  data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_89(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_90(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_91(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_92(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_93(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */ + (-data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */) - data->localData[0]->realVars[39] /* Conduction_wall3_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS100(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS100(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS100(sysData);
}

void getIterationVarsNLS100(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 105
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._Q_flow = 5.670367e-08 * Radiation_wall4_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall4_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,105};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[90] /* Radiation_wall4_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[63]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 106
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall4_outer.port_a.T
 */
void OM_Result_eqFunction_106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,106};
  data->localData[0]->realVars[64] /* Convection_wall4_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 107
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Q_flow = Convection_coef_wall4_outer.k * Convection_wall4_outer.dT
 */
void OM_Result_eqFunction_107(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,107};
  data->localData[0]->realVars[63] /* Convection_wall4_outer._Q_flow variable */ = (data->simulationInfo->realParameter[21]) * (data->localData[0]->realVars[64] /* Convection_wall4_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 108
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._Q_flow = Radiation_wall4_outer.Q_flow + Convection_wall4_outer.Q_flow
 */
void OM_Result_eqFunction_108(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,108};
  data->localData[0]->realVars[44] /* Conduction_wall4_outer._Q_flow variable */ = data->localData[0]->realVars[90] /* Radiation_wall4_outer._Q_flow variable */ + data->localData[0]->realVars[63] /* Convection_wall4_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 109
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._dT = DIVISION(Conduction_wall4_outer.Q_flow, Conduction_wall4_outer.G)
 */
void OM_Result_eqFunction_109(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,109};
  data->localData[0]->realVars[45] /* Conduction_wall4_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[44] /* Conduction_wall4_outer._Q_flow variable */,data->simulationInfo->realParameter[12],"Conduction_wall4_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc116(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,116};
  /* iteration variables */
  data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_105(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_106(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_107(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_108(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_109(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */ + (-data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */) - data->localData[0]->realVars[45] /* Conduction_wall4_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS116(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS116(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall4_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS116(sysData);
}

void getIterationVarsNLS116(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 121
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._Q_flow = 5.670367e-08 * Radiation_wall1_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall1_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_121(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,121};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[82] /* Radiation_wall1_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[59]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 122
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall1_outer.port_a.T
 */
void OM_Result_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,122};
  data->localData[0]->realVars[56] /* Convection_wall1_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 123
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Q_flow = Convection_coef_wall1_outer.k * Convection_wall1_outer.dT
 */
void OM_Result_eqFunction_123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,123};
  data->localData[0]->realVars[55] /* Convection_wall1_outer._Q_flow variable */ = (data->simulationInfo->realParameter[17]) * (data->localData[0]->realVars[56] /* Convection_wall1_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 124
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._Q_flow = Radiation_wall1_outer.Q_flow + Convection_wall1_outer.Q_flow
 */
void OM_Result_eqFunction_124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,124};
  data->localData[0]->realVars[32] /* Conduction_wall1_outer._Q_flow variable */ = data->localData[0]->realVars[82] /* Radiation_wall1_outer._Q_flow variable */ + data->localData[0]->realVars[55] /* Convection_wall1_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 125
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._dT = DIVISION(Conduction_wall1_outer.Q_flow, Conduction_wall1_outer.G)
 */
void OM_Result_eqFunction_125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,125};
  data->localData[0]->realVars[33] /* Conduction_wall1_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[32] /* Conduction_wall1_outer._Q_flow variable */,data->simulationInfo->realParameter[8],"Conduction_wall1_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc132(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,132};
  /* iteration variables */
  data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_121(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_122(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_123(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_124(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_125(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */ + (-data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */) - data->localData[0]->realVars[33] /* Conduction_wall1_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS132(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS132(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS132(sysData);
}

void getIterationVarsNLS132(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 137
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._Q_flow = 5.670367e-08 * Radiation_roof_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_roof_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_137(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,137};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[78] /* Radiation_roof_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[57]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 138
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._port._Q_flow = (-Heatflow_solar_radiation.Q_flow) * (1.0 + Heatflow_solar_radiation.alpha * (Conduction_roof_outer.port_a.T - Heatflow_solar_radiation.T_ref))
 */
void OM_Result_eqFunction_138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,138};
  data->localData[0]->realVars[73] /* Heatflow_solar_radiation._port._Q_flow variable */ = ((-data->localData[0]->realVars[72] /* Heatflow_solar_radiation._Q_flow variable */)) * (1.0 + (data->simulationInfo->realParameter[53]) * (data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ - data->simulationInfo->realParameter[52]));
  TRACE_POP
}
/*
 equation index: 139
 type: SIMPLE_ASSIGN
 Convection_roof_outer._dT = Data_outdoor_temperature.y[1] - Conduction_roof_outer.port_a.T
 */
void OM_Result_eqFunction_139(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,139};
  data->localData[0]->realVars[52] /* Convection_roof_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 140
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Q_flow = Convection_coef_roof_outer.k * Convection_roof_outer.dT
 */
void OM_Result_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
  data->localData[0]->realVars[51] /* Convection_roof_outer._Q_flow variable */ = (data->simulationInfo->realParameter[15]) * (data->localData[0]->realVars[52] /* Convection_roof_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 141
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._Q_flow = Convection_roof_outer.Q_flow - (Heatflow_solar_radiation.port.Q_flow - Radiation_roof_outer.Q_flow)
 */
void OM_Result_eqFunction_141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,141};
  data->localData[0]->realVars[26] /* Conduction_roof_outer._Q_flow variable */ = data->localData[0]->realVars[51] /* Convection_roof_outer._Q_flow variable */ - (data->localData[0]->realVars[73] /* Heatflow_solar_radiation._port._Q_flow variable */ - data->localData[0]->realVars[78] /* Radiation_roof_outer._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 142
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._dT = DIVISION(Conduction_roof_outer.Q_flow, Conduction_roof_outer.G)
 */
void OM_Result_eqFunction_142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,142};
  data->localData[0]->realVars[27] /* Conduction_roof_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[26] /* Conduction_roof_outer._Q_flow variable */,data->simulationInfo->realParameter[6],"Conduction_roof_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc150(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,150};
  /* iteration variables */
  data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ = xloc[0];
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

  /* local constraints */
  OM_Result_eqFunction_142(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ + (-data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */) - data->localData[0]->realVars[27] /* Conduction_roof_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS150(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS150(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_roof_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS150(sysData);
}

void getIterationVarsNLS150(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
}

/* inner equations */

/*
 equation index: 225
 type: SIMPLE_ASSIGN
 Radiation_wall4_inner._Q_flow = 5.670367e-08 * Radiation_wall4_inner.Gr * (Conduction_wall4_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_225(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,225};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[88] /* Radiation_wall4_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[62]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 226
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._dT = Conduction_wall4_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_226(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,226};
  data->localData[0]->realVars[62] /* Convection_wall4_inner._dT variable */ = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 227
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._Q_flow = Convection_coef_wall4_inner.k * Convection_wall4_inner.dT
 */
void OM_Result_eqFunction_227(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,227};
  data->localData[0]->realVars[61] /* Convection_wall4_inner._Q_flow variable */ = (data->simulationInfo->realParameter[20]) * (data->localData[0]->realVars[62] /* Convection_wall4_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 228
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._Q_flow = Radiation_wall4_inner.Q_flow + Convection_wall4_inner.Q_flow
 */
void OM_Result_eqFunction_228(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,228};
  data->localData[0]->realVars[41] /* Conduction_wall4_inner._Q_flow variable */ = data->localData[0]->realVars[88] /* Radiation_wall4_inner._Q_flow variable */ + data->localData[0]->realVars[61] /* Convection_wall4_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 229
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._dT = DIVISION(Conduction_wall4_inner.Q_flow, Conduction_wall4_inner.G)
 */
void OM_Result_eqFunction_229(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,229};
  data->localData[0]->realVars[42] /* Conduction_wall4_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[41] /* Conduction_wall4_inner._Q_flow variable */,data->simulationInfo->realParameter[11],"Conduction_wall4_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc236(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,236};
  /* iteration variables */
  data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_225(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_226(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_227(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_228(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_229(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */ + (-data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */) - data->localData[0]->realVars[42] /* Conduction_wall4_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS236(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS236(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall4_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[43].attribute /* Conduction_wall4_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS236(sysData);
}

void getIterationVarsNLS236(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 238
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._Q_flow = 5.670367e-08 * Radiation_wall4_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall4_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_238(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,238};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[90] /* Radiation_wall4_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[63]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 239
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall4_outer.port_a.T
 */
void OM_Result_eqFunction_239(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,239};
  data->localData[0]->realVars[64] /* Convection_wall4_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 240
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Q_flow = Convection_coef_wall4_outer.k * Convection_wall4_outer.dT
 */
void OM_Result_eqFunction_240(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,240};
  data->localData[0]->realVars[63] /* Convection_wall4_outer._Q_flow variable */ = (data->simulationInfo->realParameter[21]) * (data->localData[0]->realVars[64] /* Convection_wall4_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 241
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._Q_flow = Radiation_wall4_outer.Q_flow + Convection_wall4_outer.Q_flow
 */
void OM_Result_eqFunction_241(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,241};
  data->localData[0]->realVars[44] /* Conduction_wall4_outer._Q_flow variable */ = data->localData[0]->realVars[90] /* Radiation_wall4_outer._Q_flow variable */ + data->localData[0]->realVars[63] /* Convection_wall4_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 242
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._dT = DIVISION(Conduction_wall4_outer.Q_flow, Conduction_wall4_outer.G)
 */
void OM_Result_eqFunction_242(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,242};
  data->localData[0]->realVars[45] /* Conduction_wall4_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[44] /* Conduction_wall4_outer._Q_flow variable */,data->simulationInfo->realParameter[12],"Conduction_wall4_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc249(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,249};
  /* iteration variables */
  data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_238(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_239(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_240(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_241(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_242(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */ + (-data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */) - data->localData[0]->realVars[45] /* Conduction_wall4_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS249(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS249(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall4_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[46].attribute /* Conduction_wall4_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS249(sysData);
}

void getIterationVarsNLS249(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 254
 type: SIMPLE_ASSIGN
 Radiation_wall3_inner._Q_flow = 5.670367e-08 * Radiation_wall3_inner.Gr * (Conduction_wall3_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_254(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,254};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[84] /* Radiation_wall3_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[60]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 255
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._dT = Conduction_wall3_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_255(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,255};
  data->localData[0]->realVars[58] /* Convection_wall3_inner._dT variable */ = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 256
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._Q_flow = Convection_coef_wall3_inner.k * Convection_wall3_inner.dT
 */
void OM_Result_eqFunction_256(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,256};
  data->localData[0]->realVars[57] /* Convection_wall3_inner._Q_flow variable */ = (data->simulationInfo->realParameter[18]) * (data->localData[0]->realVars[58] /* Convection_wall3_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 257
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._Q_flow = Radiation_wall3_inner.Q_flow + Convection_wall3_inner.Q_flow
 */
void OM_Result_eqFunction_257(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,257};
  data->localData[0]->realVars[35] /* Conduction_wall3_inner._Q_flow variable */ = data->localData[0]->realVars[84] /* Radiation_wall3_inner._Q_flow variable */ + data->localData[0]->realVars[57] /* Convection_wall3_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 258
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._dT = DIVISION(Conduction_wall3_inner.Q_flow, Conduction_wall3_inner.G)
 */
void OM_Result_eqFunction_258(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,258};
  data->localData[0]->realVars[36] /* Conduction_wall3_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[35] /* Conduction_wall3_inner._Q_flow variable */,data->simulationInfo->realParameter[9],"Conduction_wall3_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc265(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,265};
  /* iteration variables */
  data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_254(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_255(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_256(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_257(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_258(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */ + (-data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */) - data->localData[0]->realVars[36] /* Conduction_wall3_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS265(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS265(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[37].attribute /* Conduction_wall3_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS265(sysData);
}

void getIterationVarsNLS265(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 267
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._Q_flow = 5.670367e-08 * Radiation_wall3_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall3_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_267(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,267};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[86] /* Radiation_wall3_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[61]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 268
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall3_outer.port_a.T
 */
void OM_Result_eqFunction_268(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,268};
  data->localData[0]->realVars[60] /* Convection_wall3_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 269
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Q_flow = Convection_coef_wall3_outer.k * Convection_wall3_outer.dT
 */
void OM_Result_eqFunction_269(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,269};
  data->localData[0]->realVars[59] /* Convection_wall3_outer._Q_flow variable */ = (data->simulationInfo->realParameter[19]) * (data->localData[0]->realVars[60] /* Convection_wall3_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 270
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._Q_flow = Radiation_wall3_outer.Q_flow + Convection_wall3_outer.Q_flow
 */
void OM_Result_eqFunction_270(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,270};
  data->localData[0]->realVars[38] /* Conduction_wall3_outer._Q_flow variable */ = data->localData[0]->realVars[86] /* Radiation_wall3_outer._Q_flow variable */ + data->localData[0]->realVars[59] /* Convection_wall3_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 271
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._dT = DIVISION(Conduction_wall3_outer.Q_flow, Conduction_wall3_outer.G)
 */
void OM_Result_eqFunction_271(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,271};
  data->localData[0]->realVars[39] /* Conduction_wall3_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[38] /* Conduction_wall3_outer._Q_flow variable */,data->simulationInfo->realParameter[10],"Conduction_wall3_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc278(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,278};
  /* iteration variables */
  data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_267(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_268(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_269(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_270(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_271(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */ + (-data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */) - data->localData[0]->realVars[39] /* Conduction_wall3_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS278(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS278(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall3_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[40].attribute /* Conduction_wall3_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS278(sysData);
}

void getIterationVarsNLS278(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 283
 type: SIMPLE_ASSIGN
 Radiation_roof_inner._Q_flow = 5.670367e-08 * Radiation_roof_inner.Gr * (Conduction_roof_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,283};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[76] /* Radiation_roof_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[56]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 284
 type: SIMPLE_ASSIGN
 Convection_roof_inner._dT = Conduction_roof_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,284};
  data->localData[0]->realVars[50] /* Convection_roof_inner._dT variable */ = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 285
 type: SIMPLE_ASSIGN
 Convection_roof_inner._Q_flow = Convection_coef_roof_inner.k * Convection_roof_inner.dT
 */
void OM_Result_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,285};
  data->localData[0]->realVars[49] /* Convection_roof_inner._Q_flow variable */ = (data->simulationInfo->realParameter[14]) * (data->localData[0]->realVars[50] /* Convection_roof_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 286
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._Q_flow = Radiation_roof_inner.Q_flow + Convection_roof_inner.Q_flow
 */
void OM_Result_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,286};
  data->localData[0]->realVars[23] /* Conduction_roof_inner._Q_flow variable */ = data->localData[0]->realVars[76] /* Radiation_roof_inner._Q_flow variable */ + data->localData[0]->realVars[49] /* Convection_roof_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 287
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._dT = DIVISION(Conduction_roof_inner.Q_flow, Conduction_roof_inner.G)
 */
void OM_Result_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
  data->localData[0]->realVars[24] /* Conduction_roof_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[23] /* Conduction_roof_inner._Q_flow variable */,data->simulationInfo->realParameter[5],"Conduction_roof_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc294(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,294};
  /* iteration variables */
  data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_283(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_284(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_285(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_286(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_287(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */ + (-data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */) - data->localData[0]->realVars[24] /* Conduction_roof_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS294(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS294(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_roof_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[25].attribute /* Conduction_roof_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS294(sysData);
}

void getIterationVarsNLS294(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
}


/* inner equations */

/*
 equation index: 296
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._Q_flow = 5.670367e-08 * Radiation_roof_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_roof_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_296(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,296};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[78] /* Radiation_roof_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[57]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 297
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._port._Q_flow = (-Heatflow_solar_radiation.Q_flow) * (1.0 + Heatflow_solar_radiation.alpha * (Conduction_roof_outer.port_a.T - Heatflow_solar_radiation.T_ref))
 */
void OM_Result_eqFunction_297(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,297};
  data->localData[0]->realVars[73] /* Heatflow_solar_radiation._port._Q_flow variable */ = ((-data->localData[0]->realVars[72] /* Heatflow_solar_radiation._Q_flow variable */)) * (1.0 + (data->simulationInfo->realParameter[53]) * (data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ - data->simulationInfo->realParameter[52]));
  TRACE_POP
}
/*
 equation index: 298
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._dT = Conduction_roof_outer.port_a.T - Capacitor_roof.T
 */
void OM_Result_eqFunction_298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,298};
  data->localData[0]->realVars[27] /* Conduction_roof_outer._dT variable */ = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ - data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */;
  TRACE_POP
}
/*
 equation index: 299
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._Q_flow = Conduction_roof_outer.G * Conduction_roof_outer.dT
 */
void OM_Result_eqFunction_299(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,299};
  data->localData[0]->realVars[26] /* Conduction_roof_outer._Q_flow variable */ = (data->simulationInfo->realParameter[6]) * (data->localData[0]->realVars[27] /* Conduction_roof_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 300
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Q_flow = Conduction_roof_outer.Q_flow + Heatflow_solar_radiation.port.Q_flow - Radiation_roof_outer.Q_flow
 */
void OM_Result_eqFunction_300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,300};
  data->localData[0]->realVars[51] /* Convection_roof_outer._Q_flow variable */ = data->localData[0]->realVars[26] /* Conduction_roof_outer._Q_flow variable */ + data->localData[0]->realVars[73] /* Heatflow_solar_radiation._port._Q_flow variable */ - data->localData[0]->realVars[78] /* Radiation_roof_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 301
 type: SIMPLE_ASSIGN
 Convection_roof_outer._dT = DIVISION(Convection_roof_outer.Q_flow, Convection_coef_roof_outer.k)
 */
void OM_Result_eqFunction_301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,301};
  data->localData[0]->realVars[52] /* Convection_roof_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[51] /* Convection_roof_outer._Q_flow variable */,data->simulationInfo->realParameter[15],"Convection_coef_roof_outer.k",equationIndexes);
  TRACE_POP
}

void residualFunc309(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,309};
  /* iteration variables */
  data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_296(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_297(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_298(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_299(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_300(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_301(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ + (-data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */) - data->localData[0]->realVars[52] /* Convection_roof_outer._dT variable */;
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
  /* static nls data for Conduction_roof_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[28].attribute /* Conduction_roof_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS309(sysData);
}

void getIterationVarsNLS309(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 314
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._Q_flow = 5.670367e-08 * Radiation_wall1_outer.Gr * (Data_outdoor_temperature.y[1] ^ 4.0 - Conduction_wall1_outer.port_a.T ^ 4.0)
 */
void OM_Result_eqFunction_314(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,314};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[82] /* Radiation_wall1_outer._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[59]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 315
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._dT = Data_outdoor_temperature.y[1] - Conduction_wall1_outer.port_a.T
 */
void OM_Result_eqFunction_315(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,315};
  data->localData[0]->realVars[56] /* Convection_wall1_outer._dT variable */ = data->localData[0]->realVars[66] /* Data_outdoor_temperature._y[1] variable */ - data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 316
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Q_flow = Convection_coef_wall1_outer.k * Convection_wall1_outer.dT
 */
void OM_Result_eqFunction_316(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,316};
  data->localData[0]->realVars[55] /* Convection_wall1_outer._Q_flow variable */ = (data->simulationInfo->realParameter[17]) * (data->localData[0]->realVars[56] /* Convection_wall1_outer._dT variable */);
  TRACE_POP
}
/*
 equation index: 317
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._Q_flow = Radiation_wall1_outer.Q_flow + Convection_wall1_outer.Q_flow
 */
void OM_Result_eqFunction_317(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,317};
  data->localData[0]->realVars[32] /* Conduction_wall1_outer._Q_flow variable */ = data->localData[0]->realVars[82] /* Radiation_wall1_outer._Q_flow variable */ + data->localData[0]->realVars[55] /* Convection_wall1_outer._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 318
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._dT = DIVISION(Conduction_wall1_outer.Q_flow, Conduction_wall1_outer.G)
 */
void OM_Result_eqFunction_318(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,318};
  data->localData[0]->realVars[33] /* Conduction_wall1_outer._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[32] /* Conduction_wall1_outer._Q_flow variable */,data->simulationInfo->realParameter[8],"Conduction_wall1_outer.G",equationIndexes);
  TRACE_POP
}

void residualFunc325(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,325};
  /* iteration variables */
  data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */ = xloc[0];
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
  /* body */
  res[0] = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */ + (-data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */) - data->localData[0]->realVars[33] /* Conduction_wall1_outer._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS325(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS325(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_outer.port_a.T */
  sysData->nominal[i] = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[34].attribute /* Conduction_wall1_outer._port_a._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS325(sysData);
}

void getIterationVarsNLS325(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
}


/* inner equations */

/*
 equation index: 328
 type: SIMPLE_ASSIGN
 Radiation_wall1_inner._Q_flow = 5.670367e-08 * Radiation_wall1_inner.Gr * (Conduction_wall1_inner.port_b.T ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_328(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,328};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[80] /* Radiation_wall1_inner._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[58]) * ((tmp0 * tmp0) - ((tmp1 * tmp1))));
  TRACE_POP
}
/*
 equation index: 329
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._dT = Conduction_wall1_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_329(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,329};
  data->localData[0]->realVars[54] /* Convection_wall1_inner._dT variable */ = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 330
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._Q_flow = Convection_coef_wall1_inner.k * Convection_wall1_inner.dT
 */
void OM_Result_eqFunction_330(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,330};
  data->localData[0]->realVars[53] /* Convection_wall1_inner._Q_flow variable */ = (data->simulationInfo->realParameter[16]) * (data->localData[0]->realVars[54] /* Convection_wall1_inner._dT variable */);
  TRACE_POP
}
/*
 equation index: 331
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._Q_flow = Radiation_wall1_inner.Q_flow + Convection_wall1_inner.Q_flow
 */
void OM_Result_eqFunction_331(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,331};
  data->localData[0]->realVars[29] /* Conduction_wall1_inner._Q_flow variable */ = data->localData[0]->realVars[80] /* Radiation_wall1_inner._Q_flow variable */ + data->localData[0]->realVars[53] /* Convection_wall1_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 332
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._dT = DIVISION(Conduction_wall1_inner.Q_flow, Conduction_wall1_inner.G)
 */
void OM_Result_eqFunction_332(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,332};
  data->localData[0]->realVars[30] /* Conduction_wall1_inner._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[29] /* Conduction_wall1_inner._Q_flow variable */,data->simulationInfo->realParameter[7],"Conduction_wall1_inner.G",equationIndexes);
  TRACE_POP
}

void residualFunc339(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,339};
  /* iteration variables */
  data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  OM_Result_eqFunction_328(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_329(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_330(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_331(data, threadData);

  /* local constraints */
  OM_Result_eqFunction_332(data, threadData);
  /* body */
  res[0] = data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */ + (-data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */) - data->localData[0]->realVars[30] /* Conduction_wall1_inner._dT variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS339(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS339(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Conduction_wall1_inner.port_b.T */
  sysData->nominal[i] = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[31].attribute /* Conduction_wall1_inner._port_b._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS339(sysData);
}

void getIterationVarsNLS339(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */;
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize non-linear systems */
void OM_Result_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA* nonLinearSystemData)
{
  
  nonLinearSystemData[0].equationIndex = 34;
  nonLinearSystemData[0].size = 1;
  nonLinearSystemData[0].homotopySupport = 0;
  nonLinearSystemData[0].mixedSystem = 0;
  nonLinearSystemData[0].residualFunc = residualFunc34;
  nonLinearSystemData[0].strictTearingFunctionCall = NULL;
  nonLinearSystemData[0].analyticalJacobianColumn = OM_Result_functionJacNLSJac0_column;
  nonLinearSystemData[0].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac0;
  nonLinearSystemData[0].jacobianIndex = 0;
  nonLinearSystemData[0].initializeStaticNLSData = initializeStaticDataNLS34;
  nonLinearSystemData[0].getIterationVars = getIterationVarsNLS34;
  nonLinearSystemData[0].checkConstraints = NULL;
  
  
  nonLinearSystemData[1].equationIndex = 47;
  nonLinearSystemData[1].size = 1;
  nonLinearSystemData[1].homotopySupport = 0;
  nonLinearSystemData[1].mixedSystem = 0;
  nonLinearSystemData[1].residualFunc = residualFunc47;
  nonLinearSystemData[1].strictTearingFunctionCall = NULL;
  nonLinearSystemData[1].analyticalJacobianColumn = OM_Result_functionJacNLSJac1_column;
  nonLinearSystemData[1].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac1;
  nonLinearSystemData[1].jacobianIndex = 1;
  nonLinearSystemData[1].initializeStaticNLSData = initializeStaticDataNLS47;
  nonLinearSystemData[1].getIterationVars = getIterationVarsNLS47;
  nonLinearSystemData[1].checkConstraints = NULL;
  
  
  nonLinearSystemData[2].equationIndex = 60;
  nonLinearSystemData[2].size = 1;
  nonLinearSystemData[2].homotopySupport = 0;
  nonLinearSystemData[2].mixedSystem = 0;
  nonLinearSystemData[2].residualFunc = residualFunc60;
  nonLinearSystemData[2].strictTearingFunctionCall = NULL;
  nonLinearSystemData[2].analyticalJacobianColumn = OM_Result_functionJacNLSJac2_column;
  nonLinearSystemData[2].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac2;
  nonLinearSystemData[2].jacobianIndex = 2;
  nonLinearSystemData[2].initializeStaticNLSData = initializeStaticDataNLS60;
  nonLinearSystemData[2].getIterationVars = getIterationVarsNLS60;
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
  
  
  nonLinearSystemData[4].equationIndex = 100;
  nonLinearSystemData[4].size = 1;
  nonLinearSystemData[4].homotopySupport = 0;
  nonLinearSystemData[4].mixedSystem = 0;
  nonLinearSystemData[4].residualFunc = residualFunc100;
  nonLinearSystemData[4].strictTearingFunctionCall = NULL;
  nonLinearSystemData[4].analyticalJacobianColumn = OM_Result_functionJacNLSJac4_column;
  nonLinearSystemData[4].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac4;
  nonLinearSystemData[4].jacobianIndex = 4;
  nonLinearSystemData[4].initializeStaticNLSData = initializeStaticDataNLS100;
  nonLinearSystemData[4].getIterationVars = getIterationVarsNLS100;
  nonLinearSystemData[4].checkConstraints = NULL;
  
  
  nonLinearSystemData[5].equationIndex = 116;
  nonLinearSystemData[5].size = 1;
  nonLinearSystemData[5].homotopySupport = 0;
  nonLinearSystemData[5].mixedSystem = 0;
  nonLinearSystemData[5].residualFunc = residualFunc116;
  nonLinearSystemData[5].strictTearingFunctionCall = NULL;
  nonLinearSystemData[5].analyticalJacobianColumn = OM_Result_functionJacNLSJac5_column;
  nonLinearSystemData[5].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac5;
  nonLinearSystemData[5].jacobianIndex = 5;
  nonLinearSystemData[5].initializeStaticNLSData = initializeStaticDataNLS116;
  nonLinearSystemData[5].getIterationVars = getIterationVarsNLS116;
  nonLinearSystemData[5].checkConstraints = NULL;
  
  
  nonLinearSystemData[6].equationIndex = 132;
  nonLinearSystemData[6].size = 1;
  nonLinearSystemData[6].homotopySupport = 0;
  nonLinearSystemData[6].mixedSystem = 0;
  nonLinearSystemData[6].residualFunc = residualFunc132;
  nonLinearSystemData[6].strictTearingFunctionCall = NULL;
  nonLinearSystemData[6].analyticalJacobianColumn = OM_Result_functionJacNLSJac6_column;
  nonLinearSystemData[6].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac6;
  nonLinearSystemData[6].jacobianIndex = 6;
  nonLinearSystemData[6].initializeStaticNLSData = initializeStaticDataNLS132;
  nonLinearSystemData[6].getIterationVars = getIterationVarsNLS132;
  nonLinearSystemData[6].checkConstraints = NULL;
  
  
  nonLinearSystemData[7].equationIndex = 150;
  nonLinearSystemData[7].size = 1;
  nonLinearSystemData[7].homotopySupport = 0;
  nonLinearSystemData[7].mixedSystem = 0;
  nonLinearSystemData[7].residualFunc = residualFunc150;
  nonLinearSystemData[7].strictTearingFunctionCall = NULL;
  nonLinearSystemData[7].analyticalJacobianColumn = OM_Result_functionJacNLSJac7_column;
  nonLinearSystemData[7].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac7;
  nonLinearSystemData[7].jacobianIndex = 7;
  nonLinearSystemData[7].initializeStaticNLSData = initializeStaticDataNLS150;
  nonLinearSystemData[7].getIterationVars = getIterationVarsNLS150;
  nonLinearSystemData[7].checkConstraints = NULL;
  
  nonLinearSystemData[8].equationIndex = 236;
  nonLinearSystemData[8].size = 1;
  nonLinearSystemData[8].homotopySupport = 0;
  nonLinearSystemData[8].mixedSystem = 0;
  nonLinearSystemData[8].residualFunc = residualFunc236;
  nonLinearSystemData[8].strictTearingFunctionCall = NULL;
  nonLinearSystemData[8].analyticalJacobianColumn = OM_Result_functionJacNLSJac8_column;
  nonLinearSystemData[8].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac8;
  nonLinearSystemData[8].jacobianIndex = 8;
  nonLinearSystemData[8].initializeStaticNLSData = initializeStaticDataNLS236;
  nonLinearSystemData[8].getIterationVars = getIterationVarsNLS236;
  nonLinearSystemData[8].checkConstraints = NULL;
  
  
  nonLinearSystemData[9].equationIndex = 249;
  nonLinearSystemData[9].size = 1;
  nonLinearSystemData[9].homotopySupport = 0;
  nonLinearSystemData[9].mixedSystem = 0;
  nonLinearSystemData[9].residualFunc = residualFunc249;
  nonLinearSystemData[9].strictTearingFunctionCall = NULL;
  nonLinearSystemData[9].analyticalJacobianColumn = OM_Result_functionJacNLSJac9_column;
  nonLinearSystemData[9].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac9;
  nonLinearSystemData[9].jacobianIndex = 9;
  nonLinearSystemData[9].initializeStaticNLSData = initializeStaticDataNLS249;
  nonLinearSystemData[9].getIterationVars = getIterationVarsNLS249;
  nonLinearSystemData[9].checkConstraints = NULL;
  
  
  nonLinearSystemData[10].equationIndex = 265;
  nonLinearSystemData[10].size = 1;
  nonLinearSystemData[10].homotopySupport = 0;
  nonLinearSystemData[10].mixedSystem = 0;
  nonLinearSystemData[10].residualFunc = residualFunc265;
  nonLinearSystemData[10].strictTearingFunctionCall = NULL;
  nonLinearSystemData[10].analyticalJacobianColumn = OM_Result_functionJacNLSJac10_column;
  nonLinearSystemData[10].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac10;
  nonLinearSystemData[10].jacobianIndex = 10;
  nonLinearSystemData[10].initializeStaticNLSData = initializeStaticDataNLS265;
  nonLinearSystemData[10].getIterationVars = getIterationVarsNLS265;
  nonLinearSystemData[10].checkConstraints = NULL;
  
  
  nonLinearSystemData[11].equationIndex = 278;
  nonLinearSystemData[11].size = 1;
  nonLinearSystemData[11].homotopySupport = 0;
  nonLinearSystemData[11].mixedSystem = 0;
  nonLinearSystemData[11].residualFunc = residualFunc278;
  nonLinearSystemData[11].strictTearingFunctionCall = NULL;
  nonLinearSystemData[11].analyticalJacobianColumn = OM_Result_functionJacNLSJac11_column;
  nonLinearSystemData[11].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac11;
  nonLinearSystemData[11].jacobianIndex = 11;
  nonLinearSystemData[11].initializeStaticNLSData = initializeStaticDataNLS278;
  nonLinearSystemData[11].getIterationVars = getIterationVarsNLS278;
  nonLinearSystemData[11].checkConstraints = NULL;
  
  
  nonLinearSystemData[12].equationIndex = 294;
  nonLinearSystemData[12].size = 1;
  nonLinearSystemData[12].homotopySupport = 0;
  nonLinearSystemData[12].mixedSystem = 0;
  nonLinearSystemData[12].residualFunc = residualFunc294;
  nonLinearSystemData[12].strictTearingFunctionCall = NULL;
  nonLinearSystemData[12].analyticalJacobianColumn = OM_Result_functionJacNLSJac12_column;
  nonLinearSystemData[12].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac12;
  nonLinearSystemData[12].jacobianIndex = 12;
  nonLinearSystemData[12].initializeStaticNLSData = initializeStaticDataNLS294;
  nonLinearSystemData[12].getIterationVars = getIterationVarsNLS294;
  nonLinearSystemData[12].checkConstraints = NULL;
  
  
  nonLinearSystemData[13].equationIndex = 309;
  nonLinearSystemData[13].size = 1;
  nonLinearSystemData[13].homotopySupport = 0;
  nonLinearSystemData[13].mixedSystem = 0;
  nonLinearSystemData[13].residualFunc = residualFunc309;
  nonLinearSystemData[13].strictTearingFunctionCall = NULL;
  nonLinearSystemData[13].analyticalJacobianColumn = OM_Result_functionJacNLSJac13_column;
  nonLinearSystemData[13].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac13;
  nonLinearSystemData[13].jacobianIndex = 13;
  nonLinearSystemData[13].initializeStaticNLSData = initializeStaticDataNLS309;
  nonLinearSystemData[13].getIterationVars = getIterationVarsNLS309;
  nonLinearSystemData[13].checkConstraints = NULL;
  
  
  nonLinearSystemData[14].equationIndex = 325;
  nonLinearSystemData[14].size = 1;
  nonLinearSystemData[14].homotopySupport = 0;
  nonLinearSystemData[14].mixedSystem = 0;
  nonLinearSystemData[14].residualFunc = residualFunc325;
  nonLinearSystemData[14].strictTearingFunctionCall = NULL;
  nonLinearSystemData[14].analyticalJacobianColumn = OM_Result_functionJacNLSJac14_column;
  nonLinearSystemData[14].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac14;
  nonLinearSystemData[14].jacobianIndex = 14;
  nonLinearSystemData[14].initializeStaticNLSData = initializeStaticDataNLS325;
  nonLinearSystemData[14].getIterationVars = getIterationVarsNLS325;
  nonLinearSystemData[14].checkConstraints = NULL;
  
  
  nonLinearSystemData[15].equationIndex = 339;
  nonLinearSystemData[15].size = 1;
  nonLinearSystemData[15].homotopySupport = 0;
  nonLinearSystemData[15].mixedSystem = 0;
  nonLinearSystemData[15].residualFunc = residualFunc339;
  nonLinearSystemData[15].strictTearingFunctionCall = NULL;
  nonLinearSystemData[15].analyticalJacobianColumn = OM_Result_functionJacNLSJac15_column;
  nonLinearSystemData[15].initialAnalyticalJacobian = OM_Result_initialAnalyticJacobianNLSJac15;
  nonLinearSystemData[15].jacobianIndex = 15;
  nonLinearSystemData[15].initializeStaticNLSData = initializeStaticDataNLS339;
  nonLinearSystemData[15].getIterationVars = getIterationVarsNLS339;
  nonLinearSystemData[15].checkConstraints = NULL;
}

#if defined(__cplusplus)
}
#endif


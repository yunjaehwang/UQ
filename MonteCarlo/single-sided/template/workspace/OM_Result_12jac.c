/* Jacobians */
#include "OM_Result_model.h"
#include "OM_Result_12jac.h"

int OM_Result_initialAnalyticJacobianNLSJac15(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac15;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 6;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(6,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac14(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac14;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 6;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(6,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac13(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac13;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 7;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(7,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac12(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac12;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 7;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(7,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac11(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac11;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 6;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(6,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac10(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac10;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 6;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(6,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac9(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac9;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 6;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(6,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac8(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac8;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 6;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(6,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac7(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac7;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 7;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(7,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac6(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac6;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 6;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(6,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac5(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac5;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 6;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(6,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac4(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac4;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 6;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(6,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac3(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac3;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 7;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(7,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac2(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac2;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 6;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(6,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac1(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac1;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 6;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(6,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianNLSJac0(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 6;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(6,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int OM_Result_initialAnalyticJacobianA(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_A;
  const int colPtrIndex[1+5] = {0,5,2,2,2,2};
  const int rowIndex[13] = {0,1,2,3,4,0,1,0,2,0,3,0,4};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 5;
  data->simulationInfo->analyticJacobians[index].sizeRows = 5;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 0;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((5+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(13*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 13;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(5*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 5;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (5+1)*sizeof(int));
  
  for(i=2;i<5+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 13*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[4] = 2;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[3] = 3;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[2] = 4;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 5;
  TRACE_POP
  return 0;
}
int OM_Result_initialAnalyticJacobianB(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int OM_Result_initialAnalyticJacobianC(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int OM_Result_initialAnalyticJacobianD(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}


/*
 equation index: 376
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._Q_flow._$pDERNLSJac15._dummyVarNLSJac15 = Convection_coef_wall1_inner.k * Conduction_wall1_inner_port_b_TSeedNLSJac15
 */
void OM_Result_eqFunction_376(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,376};
  $PConvection_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15 = (data->simulationInfo->realParameter[21]) * ($PConduction_wall1_inner_port_b_TSeedNLSJac15);
  TRACE_POP
}

/*
 equation index: 377
 type: SIMPLE_ASSIGN
 Radiation_wall1_inner._Q_flow._$pDERNLSJac15._dummyVarNLSJac15 = 2.2681468e-07 * Radiation_wall1_inner.Gr * Conduction_wall1_inner.port_b.T ^ 3.0 * Conduction_wall1_inner_port_b_TSeedNLSJac15
 */
void OM_Result_eqFunction_377(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,377};
  modelica_real tmp0;
  tmp0 = data->localData[0]->realVars[34] /* Conduction_wall1_inner._port_b._T variable */;
  $PRadiation_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15 = (2.2681468e-07) * ((data->simulationInfo->realParameter[69]) * (((tmp0 * tmp0 * tmp0)) * ($PConduction_wall1_inner_port_b_TSeedNLSJac15)));
  TRACE_POP
}

/*
 equation index: 378
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._Q_flow._$pDERNLSJac15._dummyVarNLSJac15 = Radiation_wall1_inner.Q_flow.$pDERNLSJac15.dummyVarNLSJac15 + Convection_wall1_inner.Q_flow.$pDERNLSJac15.dummyVarNLSJac15
 */
void OM_Result_eqFunction_378(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,378};
  $PConduction_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15 = $PRadiation_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15 + $PConvection_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15;
  TRACE_POP
}

/*
 equation index: 379
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._dT._$pDERNLSJac15._dummyVarNLSJac15 = DIVISION(Conduction_wall1_inner.Q_flow.$pDERNLSJac15.dummyVarNLSJac15, Conduction_wall1_inner.G)
 */
void OM_Result_eqFunction_379(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,379};
  $PConduction_wall1_inner$PdT$P$pDERNLSJac15$PdummyVarNLSJac15 = DIVISION_SIM($PConduction_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15,data->simulationInfo->realParameter[11],"Conduction_wall1_inner.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 380
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac15._dummyVarNLSJac15 = (-Conduction_wall1_inner_port_b_TSeedNLSJac15) - Conduction_wall1_inner.dT.$pDERNLSJac15.dummyVarNLSJac15
 */
void OM_Result_eqFunction_380(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,380};
  $P$res$P1$P$pDERNLSJac15$PdummyVarNLSJac15 = (-$PConduction_wall1_inner_port_b_TSeedNLSJac15) - $PConduction_wall1_inner$PdT$P$pDERNLSJac15$PdummyVarNLSJac15;
  TRACE_POP
}
int OM_Result_functionJacNLSJac15_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac15;
  OM_Result_eqFunction_376(data, threadData);

  OM_Result_eqFunction_377(data, threadData);

  OM_Result_eqFunction_378(data, threadData);

  OM_Result_eqFunction_379(data, threadData);

  OM_Result_eqFunction_380(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 362
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Q_flow._$pDERNLSJac14._dummyVarNLSJac14 = (-Convection_wall1_outer.Gc) * Conduction_wall1_outer_port_a_TSeedNLSJac14
 */
void OM_Result_eqFunction_362(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,362};
  $PConvection_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14 = ((-data->localData[0]->realVars[59] /* Convection_wall1_outer._Gc variable */)) * ($PConduction_wall1_outer_port_a_TSeedNLSJac14);
  TRACE_POP
}

/*
 equation index: 363
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._Q_flow._$pDERNLSJac14._dummyVarNLSJac14 = -2.2681468e-07 * Radiation_wall1_outer.Gr * Conduction_wall1_outer.port_a.T ^ 3.0 * Conduction_wall1_outer_port_a_TSeedNLSJac14
 */
void OM_Result_eqFunction_363(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,363};
  modelica_real tmp1;
  tmp1 = data->localData[0]->realVars[37] /* Conduction_wall1_outer._port_a._T variable */;
  $PRadiation_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[70]) * (((tmp1 * tmp1 * tmp1)) * ($PConduction_wall1_outer_port_a_TSeedNLSJac14)));
  TRACE_POP
}

/*
 equation index: 364
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._Q_flow._$pDERNLSJac14._dummyVarNLSJac14 = Radiation_wall1_outer.Q_flow.$pDERNLSJac14.dummyVarNLSJac14 + Convection_wall1_outer.Q_flow.$pDERNLSJac14.dummyVarNLSJac14
 */
void OM_Result_eqFunction_364(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,364};
  $PConduction_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14 = $PRadiation_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14 + $PConvection_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14;
  TRACE_POP
}

/*
 equation index: 365
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._dT._$pDERNLSJac14._dummyVarNLSJac14 = DIVISION(Conduction_wall1_outer.Q_flow.$pDERNLSJac14.dummyVarNLSJac14, Conduction_wall1_outer.G)
 */
void OM_Result_eqFunction_365(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,365};
  $PConduction_wall1_outer$PdT$P$pDERNLSJac14$PdummyVarNLSJac14 = DIVISION_SIM($PConduction_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14,data->simulationInfo->realParameter[12],"Conduction_wall1_outer.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 366
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac14._dummyVarNLSJac14 = Conduction_wall1_outer_port_a_TSeedNLSJac14 - Conduction_wall1_outer.dT.$pDERNLSJac14.dummyVarNLSJac14
 */
void OM_Result_eqFunction_366(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,366};
  $P$res$P1$P$pDERNLSJac14$PdummyVarNLSJac14 = $PConduction_wall1_outer_port_a_TSeedNLSJac14 - $PConduction_wall1_outer$PdT$P$pDERNLSJac14$PdummyVarNLSJac14;
  TRACE_POP
}
int OM_Result_functionJacNLSJac14_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac14;
  OM_Result_eqFunction_362(data, threadData);

  OM_Result_eqFunction_363(data, threadData);

  OM_Result_eqFunction_364(data, threadData);

  OM_Result_eqFunction_365(data, threadData);

  OM_Result_eqFunction_366(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 345
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Q_flow._$pDERNLSJac13._dummyVarNLSJac13 = (-Convection_roof_outer.Gc) * Conduction_roof_outer_port_a_TSeedNLSJac13
 */
void OM_Result_eqFunction_345(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,345};
  $PConvection_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 = ((-data->localData[0]->realVars[54] /* Convection_roof_outer._Gc variable */)) * ($PConduction_roof_outer_port_a_TSeedNLSJac13);
  TRACE_POP
}

/*
 equation index: 346
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._port._Q_flow._$pDERNLSJac13._dummyVarNLSJac13 = (-Heatflow_solar_radiation.Q_flow) * Heatflow_solar_radiation.alpha * Conduction_roof_outer_port_a_TSeedNLSJac13
 */
void OM_Result_eqFunction_346(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,346};
  $PHeatflow_solar_radiation$Pport$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 = ((-data->localData[0]->realVars[82] /* Heatflow_solar_radiation._Q_flow variable */)) * ((data->simulationInfo->realParameter[61]) * ($PConduction_roof_outer_port_a_TSeedNLSJac13));
  TRACE_POP
}

/*
 equation index: 347
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._Q_flow._$pDERNLSJac13._dummyVarNLSJac13 = -2.2681468e-07 * Radiation_roof_outer.Gr * Conduction_roof_outer.port_a.T ^ 3.0 * Conduction_roof_outer_port_a_TSeedNLSJac13
 */
void OM_Result_eqFunction_347(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,347};
  modelica_real tmp2;
  tmp2 = data->localData[0]->realVars[31] /* Conduction_roof_outer._port_a._T variable */;
  $PRadiation_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[67]) * (((tmp2 * tmp2 * tmp2)) * ($PConduction_roof_outer_port_a_TSeedNLSJac13)));
  TRACE_POP
}

/*
 equation index: 348
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._Q_flow._$pDERNLSJac13._dummyVarNLSJac13 = Convection_roof_outer.Q_flow.$pDERNLSJac13.dummyVarNLSJac13 - (Heatflow_solar_radiation.port.Q_flow.$pDERNLSJac13.dummyVarNLSJac13 - Radiation_roof_outer.Q_flow.$pDERNLSJac13.dummyVarNLSJac13)
 */
void OM_Result_eqFunction_348(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,348};
  $PConduction_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 = $PConvection_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 - ($PHeatflow_solar_radiation$Pport$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 - $PRadiation_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13);
  TRACE_POP
}

/*
 equation index: 349
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._dT._$pDERNLSJac13._dummyVarNLSJac13 = DIVISION(Conduction_roof_outer.Q_flow.$pDERNLSJac13.dummyVarNLSJac13, Conduction_roof_outer.G)
 */
void OM_Result_eqFunction_349(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,349};
  $PConduction_roof_outer$PdT$P$pDERNLSJac13$PdummyVarNLSJac13 = DIVISION_SIM($PConduction_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13,data->simulationInfo->realParameter[10],"Conduction_roof_outer.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 350
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac13._dummyVarNLSJac13 = Conduction_roof_outer_port_a_TSeedNLSJac13 - Conduction_roof_outer.dT.$pDERNLSJac13.dummyVarNLSJac13
 */
void OM_Result_eqFunction_350(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,350};
  $P$res$P1$P$pDERNLSJac13$PdummyVarNLSJac13 = $PConduction_roof_outer_port_a_TSeedNLSJac13 - $PConduction_roof_outer$PdT$P$pDERNLSJac13$PdummyVarNLSJac13;
  TRACE_POP
}
int OM_Result_functionJacNLSJac13_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac13;
  OM_Result_eqFunction_345(data, threadData);

  OM_Result_eqFunction_346(data, threadData);

  OM_Result_eqFunction_347(data, threadData);

  OM_Result_eqFunction_348(data, threadData);

  OM_Result_eqFunction_349(data, threadData);

  OM_Result_eqFunction_350(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 328
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._Q_flow._$pDERNLSJac12._dummyVarNLSJac12 = (-Conduction_roof_inner.G) * Conduction_roof_inner_port_b_TSeedNLSJac12
 */
void OM_Result_eqFunction_328(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,328};
  $PConduction_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 = ((-data->simulationInfo->realParameter[9])) * ($PConduction_roof_inner_port_b_TSeedNLSJac12);
  TRACE_POP
}

/*
 equation index: 329
 type: SIMPLE_ASSIGN
 Radiation_roof_inner._Q_flow._$pDERNLSJac12._dummyVarNLSJac12 = 2.2681468e-07 * Radiation_roof_inner.Gr * Conduction_roof_inner.port_b.T ^ 3.0 * Conduction_roof_inner_port_b_TSeedNLSJac12
 */
void OM_Result_eqFunction_329(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,329};
  modelica_real tmp3;
  tmp3 = data->localData[0]->realVars[28] /* Conduction_roof_inner._port_b._T variable */;
  $PRadiation_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 = (2.2681468e-07) * ((data->simulationInfo->realParameter[66]) * (((tmp3 * tmp3 * tmp3)) * ($PConduction_roof_inner_port_b_TSeedNLSJac12)));
  TRACE_POP
}

/*
 equation index: 330
 type: SIMPLE_ASSIGN
 Radiation_roof_to_floor._Q_flow._$pDERNLSJac12._dummyVarNLSJac12 = 2.2681468e-07 * Radiation_roof_to_floor.Gr * Conduction_roof_inner.port_b.T ^ 3.0 * Conduction_roof_inner_port_b_TSeedNLSJac12
 */
void OM_Result_eqFunction_330(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,330};
  modelica_real tmp4;
  tmp4 = data->localData[0]->realVars[28] /* Conduction_roof_inner._port_b._T variable */;
  $PRadiation_roof_to_floor$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 = (2.2681468e-07) * ((data->simulationInfo->realParameter[68]) * (((tmp4 * tmp4 * tmp4)) * ($PConduction_roof_inner_port_b_TSeedNLSJac12)));
  TRACE_POP
}

/*
 equation index: 331
 type: SIMPLE_ASSIGN
 Convection_roof_inner._Q_flow._$pDERNLSJac12._dummyVarNLSJac12 = Conduction_roof_inner.Q_flow.$pDERNLSJac12.dummyVarNLSJac12 - (Radiation_roof_inner.Q_flow.$pDERNLSJac12.dummyVarNLSJac12 + Radiation_roof_to_floor.Q_flow.$pDERNLSJac12.dummyVarNLSJac12)
 */
void OM_Result_eqFunction_331(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,331};
  $PConvection_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 = $PConduction_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 - ($PRadiation_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 + $PRadiation_roof_to_floor$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12);
  TRACE_POP
}

/*
 equation index: 332
 type: SIMPLE_ASSIGN
 Convection_roof_inner._dT._$pDERNLSJac12._dummyVarNLSJac12 = DIVISION(Convection_roof_inner.Q_flow.$pDERNLSJac12.dummyVarNLSJac12, Convection_coef_roof_inner.k)
 */
void OM_Result_eqFunction_332(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,332};
  $PConvection_roof_inner$PdT$P$pDERNLSJac12$PdummyVarNLSJac12 = DIVISION_SIM($PConvection_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12,data->simulationInfo->realParameter[20],"Convection_coef_roof_inner.k",equationIndexes);
  TRACE_POP
}

/*
 equation index: 333
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac12._dummyVarNLSJac12 = Conduction_roof_inner_port_b_TSeedNLSJac12 - Convection_roof_inner.dT.$pDERNLSJac12.dummyVarNLSJac12
 */
void OM_Result_eqFunction_333(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,333};
  $P$res$P1$P$pDERNLSJac12$PdummyVarNLSJac12 = $PConduction_roof_inner_port_b_TSeedNLSJac12 - $PConvection_roof_inner$PdT$P$pDERNLSJac12$PdummyVarNLSJac12;
  TRACE_POP
}
int OM_Result_functionJacNLSJac12_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac12;
  OM_Result_eqFunction_328(data, threadData);

  OM_Result_eqFunction_329(data, threadData);

  OM_Result_eqFunction_330(data, threadData);

  OM_Result_eqFunction_331(data, threadData);

  OM_Result_eqFunction_332(data, threadData);

  OM_Result_eqFunction_333(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 311
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Q_flow._$pDERNLSJac11._dummyVarNLSJac11 = (-Convection_wall3_outer.Gc) * Conduction_wall3_outer_port_a_TSeedNLSJac11
 */
void OM_Result_eqFunction_311(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,311};
  $PConvection_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11 = ((-data->localData[0]->realVars[64] /* Convection_wall3_outer._Gc variable */)) * ($PConduction_wall3_outer_port_a_TSeedNLSJac11);
  TRACE_POP
}

/*
 equation index: 312
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._Q_flow._$pDERNLSJac11._dummyVarNLSJac11 = -2.2681468e-07 * Radiation_wall3_outer.Gr * Conduction_wall3_outer.port_a.T ^ 3.0 * Conduction_wall3_outer_port_a_TSeedNLSJac11
 */
void OM_Result_eqFunction_312(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,312};
  modelica_real tmp5;
  tmp5 = data->localData[0]->realVars[43] /* Conduction_wall3_outer._port_a._T variable */;
  $PRadiation_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[72]) * (((tmp5 * tmp5 * tmp5)) * ($PConduction_wall3_outer_port_a_TSeedNLSJac11)));
  TRACE_POP
}

/*
 equation index: 313
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._Q_flow._$pDERNLSJac11._dummyVarNLSJac11 = Radiation_wall3_outer.Q_flow.$pDERNLSJac11.dummyVarNLSJac11 + Convection_wall3_outer.Q_flow.$pDERNLSJac11.dummyVarNLSJac11
 */
void OM_Result_eqFunction_313(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,313};
  $PConduction_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11 = $PRadiation_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11 + $PConvection_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11;
  TRACE_POP
}

/*
 equation index: 314
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._dT._$pDERNLSJac11._dummyVarNLSJac11 = DIVISION(Conduction_wall3_outer.Q_flow.$pDERNLSJac11.dummyVarNLSJac11, Conduction_wall3_outer.G)
 */
void OM_Result_eqFunction_314(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,314};
  $PConduction_wall3_outer$PdT$P$pDERNLSJac11$PdummyVarNLSJac11 = DIVISION_SIM($PConduction_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11,data->simulationInfo->realParameter[14],"Conduction_wall3_outer.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 315
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac11._dummyVarNLSJac11 = Conduction_wall3_outer_port_a_TSeedNLSJac11 - Conduction_wall3_outer.dT.$pDERNLSJac11.dummyVarNLSJac11
 */
void OM_Result_eqFunction_315(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,315};
  $P$res$P1$P$pDERNLSJac11$PdummyVarNLSJac11 = $PConduction_wall3_outer_port_a_TSeedNLSJac11 - $PConduction_wall3_outer$PdT$P$pDERNLSJac11$PdummyVarNLSJac11;
  TRACE_POP
}
int OM_Result_functionJacNLSJac11_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac11;
  OM_Result_eqFunction_311(data, threadData);

  OM_Result_eqFunction_312(data, threadData);

  OM_Result_eqFunction_313(data, threadData);

  OM_Result_eqFunction_314(data, threadData);

  OM_Result_eqFunction_315(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 298
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._Q_flow._$pDERNLSJac10._dummyVarNLSJac10 = (-Conduction_wall3_inner.G) * Conduction_wall3_inner_port_b_TSeedNLSJac10
 */
void OM_Result_eqFunction_298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,298};
  $PConduction_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10 = ((-data->simulationInfo->realParameter[13])) * ($PConduction_wall3_inner_port_b_TSeedNLSJac10);
  TRACE_POP
}

/*
 equation index: 299
 type: SIMPLE_ASSIGN
 Radiation_wall3_inner._Q_flow._$pDERNLSJac10._dummyVarNLSJac10 = 2.2681468e-07 * Radiation_wall3_inner.Gr * Conduction_wall3_inner.port_b.T ^ 3.0 * Conduction_wall3_inner_port_b_TSeedNLSJac10
 */
void OM_Result_eqFunction_299(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,299};
  modelica_real tmp6;
  tmp6 = data->localData[0]->realVars[40] /* Conduction_wall3_inner._port_b._T variable */;
  $PRadiation_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10 = (2.2681468e-07) * ((data->simulationInfo->realParameter[71]) * (((tmp6 * tmp6 * tmp6)) * ($PConduction_wall3_inner_port_b_TSeedNLSJac10)));
  TRACE_POP
}

/*
 equation index: 300
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._Q_flow._$pDERNLSJac10._dummyVarNLSJac10 = Conduction_wall3_inner.Q_flow.$pDERNLSJac10.dummyVarNLSJac10 - Radiation_wall3_inner.Q_flow.$pDERNLSJac10.dummyVarNLSJac10
 */
void OM_Result_eqFunction_300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,300};
  $PConvection_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10 = $PConduction_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10 - $PRadiation_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10;
  TRACE_POP
}

/*
 equation index: 301
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._dT._$pDERNLSJac10._dummyVarNLSJac10 = DIVISION(Convection_wall3_inner.Q_flow.$pDERNLSJac10.dummyVarNLSJac10, Convection_coef_wall3_inner.k)
 */
void OM_Result_eqFunction_301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,301};
  $PConvection_wall3_inner$PdT$P$pDERNLSJac10$PdummyVarNLSJac10 = DIVISION_SIM($PConvection_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10,data->simulationInfo->realParameter[22],"Convection_coef_wall3_inner.k",equationIndexes);
  TRACE_POP
}

/*
 equation index: 302
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac10._dummyVarNLSJac10 = Conduction_wall3_inner_port_b_TSeedNLSJac10 - Convection_wall3_inner.dT.$pDERNLSJac10.dummyVarNLSJac10
 */
void OM_Result_eqFunction_302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,302};
  $P$res$P1$P$pDERNLSJac10$PdummyVarNLSJac10 = $PConduction_wall3_inner_port_b_TSeedNLSJac10 - $PConvection_wall3_inner$PdT$P$pDERNLSJac10$PdummyVarNLSJac10;
  TRACE_POP
}
int OM_Result_functionJacNLSJac10_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac10;
  OM_Result_eqFunction_298(data, threadData);

  OM_Result_eqFunction_299(data, threadData);

  OM_Result_eqFunction_300(data, threadData);

  OM_Result_eqFunction_301(data, threadData);

  OM_Result_eqFunction_302(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 282
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Q_flow._$pDERNLSJac9._dummyVarNLSJac9 = (-Convection_wall4_outer.Gc) * Conduction_wall4_outer_port_a_TSeedNLSJac9
 */
void OM_Result_eqFunction_282(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,282};
  $PConvection_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9 = ((-data->localData[0]->realVars[69] /* Convection_wall4_outer._Gc variable */)) * ($PConduction_wall4_outer_port_a_TSeedNLSJac9);
  TRACE_POP
}

/*
 equation index: 283
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._Q_flow._$pDERNLSJac9._dummyVarNLSJac9 = -2.2681468e-07 * Radiation_wall4_outer.Gr * Conduction_wall4_outer.port_a.T ^ 3.0 * Conduction_wall4_outer_port_a_TSeedNLSJac9
 */
void OM_Result_eqFunction_283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,283};
  modelica_real tmp7;
  tmp7 = data->localData[0]->realVars[49] /* Conduction_wall4_outer._port_a._T variable */;
  $PRadiation_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[74]) * (((tmp7 * tmp7 * tmp7)) * ($PConduction_wall4_outer_port_a_TSeedNLSJac9)));
  TRACE_POP
}

/*
 equation index: 284
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._Q_flow._$pDERNLSJac9._dummyVarNLSJac9 = Radiation_wall4_outer.Q_flow.$pDERNLSJac9.dummyVarNLSJac9 + Convection_wall4_outer.Q_flow.$pDERNLSJac9.dummyVarNLSJac9
 */
void OM_Result_eqFunction_284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,284};
  $PConduction_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9 = $PRadiation_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9 + $PConvection_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9;
  TRACE_POP
}

/*
 equation index: 285
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._dT._$pDERNLSJac9._dummyVarNLSJac9 = DIVISION(Conduction_wall4_outer.Q_flow.$pDERNLSJac9.dummyVarNLSJac9, Conduction_wall4_outer.G)
 */
void OM_Result_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,285};
  $PConduction_wall4_outer$PdT$P$pDERNLSJac9$PdummyVarNLSJac9 = DIVISION_SIM($PConduction_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9,data->simulationInfo->realParameter[16],"Conduction_wall4_outer.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 286
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac9._dummyVarNLSJac9 = Conduction_wall4_outer_port_a_TSeedNLSJac9 - Conduction_wall4_outer.dT.$pDERNLSJac9.dummyVarNLSJac9
 */
void OM_Result_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,286};
  $P$res$P1$P$pDERNLSJac9$PdummyVarNLSJac9 = $PConduction_wall4_outer_port_a_TSeedNLSJac9 - $PConduction_wall4_outer$PdT$P$pDERNLSJac9$PdummyVarNLSJac9;
  TRACE_POP
}
int OM_Result_functionJacNLSJac9_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac9;
  OM_Result_eqFunction_282(data, threadData);

  OM_Result_eqFunction_283(data, threadData);

  OM_Result_eqFunction_284(data, threadData);

  OM_Result_eqFunction_285(data, threadData);

  OM_Result_eqFunction_286(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 269
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._Q_flow._$pDERNLSJac8._dummyVarNLSJac8 = Convection_coef_wall4_inner.k * Conduction_wall4_inner_port_b_TSeedNLSJac8
 */
void OM_Result_eqFunction_269(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,269};
  $PConvection_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8 = (data->simulationInfo->realParameter[23]) * ($PConduction_wall4_inner_port_b_TSeedNLSJac8);
  TRACE_POP
}

/*
 equation index: 270
 type: SIMPLE_ASSIGN
 Radiation_wall4_inner._Q_flow._$pDERNLSJac8._dummyVarNLSJac8 = 2.2681468e-07 * Radiation_wall4_inner.Gr * Conduction_wall4_inner.port_b.T ^ 3.0 * Conduction_wall4_inner_port_b_TSeedNLSJac8
 */
void OM_Result_eqFunction_270(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,270};
  modelica_real tmp8;
  tmp8 = data->localData[0]->realVars[46] /* Conduction_wall4_inner._port_b._T variable */;
  $PRadiation_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8 = (2.2681468e-07) * ((data->simulationInfo->realParameter[73]) * (((tmp8 * tmp8 * tmp8)) * ($PConduction_wall4_inner_port_b_TSeedNLSJac8)));
  TRACE_POP
}

/*
 equation index: 271
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._Q_flow._$pDERNLSJac8._dummyVarNLSJac8 = Radiation_wall4_inner.Q_flow.$pDERNLSJac8.dummyVarNLSJac8 + Convection_wall4_inner.Q_flow.$pDERNLSJac8.dummyVarNLSJac8
 */
void OM_Result_eqFunction_271(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,271};
  $PConduction_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8 = $PRadiation_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8 + $PConvection_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8;
  TRACE_POP
}

/*
 equation index: 272
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._dT._$pDERNLSJac8._dummyVarNLSJac8 = DIVISION(Conduction_wall4_inner.Q_flow.$pDERNLSJac8.dummyVarNLSJac8, Conduction_wall4_inner.G)
 */
void OM_Result_eqFunction_272(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,272};
  $PConduction_wall4_inner$PdT$P$pDERNLSJac8$PdummyVarNLSJac8 = DIVISION_SIM($PConduction_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8,data->simulationInfo->realParameter[15],"Conduction_wall4_inner.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 273
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac8._dummyVarNLSJac8 = (-Conduction_wall4_inner_port_b_TSeedNLSJac8) - Conduction_wall4_inner.dT.$pDERNLSJac8.dummyVarNLSJac8
 */
void OM_Result_eqFunction_273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,273};
  $P$res$P1$P$pDERNLSJac8$PdummyVarNLSJac8 = (-$PConduction_wall4_inner_port_b_TSeedNLSJac8) - $PConduction_wall4_inner$PdT$P$pDERNLSJac8$PdummyVarNLSJac8;
  TRACE_POP
}
int OM_Result_functionJacNLSJac8_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac8;
  OM_Result_eqFunction_269(data, threadData);

  OM_Result_eqFunction_270(data, threadData);

  OM_Result_eqFunction_271(data, threadData);

  OM_Result_eqFunction_272(data, threadData);

  OM_Result_eqFunction_273(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 165
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Q_flow._$pDERNLSJac7._dummyVarNLSJac7 = (-Convection_roof_outer.Gc) * Conduction_roof_outer_port_a_TSeedNLSJac7
 */
void OM_Result_eqFunction_165(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,165};
  $PConvection_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 = ((-data->localData[0]->realVars[54] /* Convection_roof_outer._Gc variable */)) * ($PConduction_roof_outer_port_a_TSeedNLSJac7);
  TRACE_POP
}

/*
 equation index: 166
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._port._Q_flow._$pDERNLSJac7._dummyVarNLSJac7 = (-Heatflow_solar_radiation.Q_flow) * Heatflow_solar_radiation.alpha * Conduction_roof_outer_port_a_TSeedNLSJac7
 */
void OM_Result_eqFunction_166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,166};
  $PHeatflow_solar_radiation$Pport$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 = ((-data->localData[0]->realVars[82] /* Heatflow_solar_radiation._Q_flow variable */)) * ((data->simulationInfo->realParameter[61]) * ($PConduction_roof_outer_port_a_TSeedNLSJac7));
  TRACE_POP
}

/*
 equation index: 167
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._Q_flow._$pDERNLSJac7._dummyVarNLSJac7 = -2.2681468e-07 * Radiation_roof_outer.Gr * Conduction_roof_outer.port_a.T ^ 3.0 * Conduction_roof_outer_port_a_TSeedNLSJac7
 */
void OM_Result_eqFunction_167(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,167};
  modelica_real tmp9;
  tmp9 = data->localData[0]->realVars[31] /* Conduction_roof_outer._port_a._T variable */;
  $PRadiation_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[67]) * (((tmp9 * tmp9 * tmp9)) * ($PConduction_roof_outer_port_a_TSeedNLSJac7)));
  TRACE_POP
}

/*
 equation index: 168
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._Q_flow._$pDERNLSJac7._dummyVarNLSJac7 = Convection_roof_outer.Q_flow.$pDERNLSJac7.dummyVarNLSJac7 - (Heatflow_solar_radiation.port.Q_flow.$pDERNLSJac7.dummyVarNLSJac7 - Radiation_roof_outer.Q_flow.$pDERNLSJac7.dummyVarNLSJac7)
 */
void OM_Result_eqFunction_168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,168};
  $PConduction_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 = $PConvection_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 - ($PHeatflow_solar_radiation$Pport$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 - $PRadiation_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7);
  TRACE_POP
}

/*
 equation index: 169
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._dT._$pDERNLSJac7._dummyVarNLSJac7 = DIVISION(Conduction_roof_outer.Q_flow.$pDERNLSJac7.dummyVarNLSJac7, Conduction_roof_outer.G)
 */
void OM_Result_eqFunction_169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,169};
  $PConduction_roof_outer$PdT$P$pDERNLSJac7$PdummyVarNLSJac7 = DIVISION_SIM($PConduction_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7,data->simulationInfo->realParameter[10],"Conduction_roof_outer.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 170
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac7._dummyVarNLSJac7 = Conduction_roof_outer_port_a_TSeedNLSJac7 - Conduction_roof_outer.dT.$pDERNLSJac7.dummyVarNLSJac7
 */
void OM_Result_eqFunction_170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,170};
  $P$res$P1$P$pDERNLSJac7$PdummyVarNLSJac7 = $PConduction_roof_outer_port_a_TSeedNLSJac7 - $PConduction_roof_outer$PdT$P$pDERNLSJac7$PdummyVarNLSJac7;
  TRACE_POP
}
int OM_Result_functionJacNLSJac7_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac7;
  OM_Result_eqFunction_165(data, threadData);

  OM_Result_eqFunction_166(data, threadData);

  OM_Result_eqFunction_167(data, threadData);

  OM_Result_eqFunction_168(data, threadData);

  OM_Result_eqFunction_169(data, threadData);

  OM_Result_eqFunction_170(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 147
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Q_flow._$pDERNLSJac6._dummyVarNLSJac6 = (-Convection_wall1_outer.Gc) * Conduction_wall1_outer_port_a_TSeedNLSJac6
 */
void OM_Result_eqFunction_147(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,147};
  $PConvection_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6 = ((-data->localData[0]->realVars[59] /* Convection_wall1_outer._Gc variable */)) * ($PConduction_wall1_outer_port_a_TSeedNLSJac6);
  TRACE_POP
}

/*
 equation index: 148
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._Q_flow._$pDERNLSJac6._dummyVarNLSJac6 = -2.2681468e-07 * Radiation_wall1_outer.Gr * Conduction_wall1_outer.port_a.T ^ 3.0 * Conduction_wall1_outer_port_a_TSeedNLSJac6
 */
void OM_Result_eqFunction_148(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,148};
  modelica_real tmp10;
  tmp10 = data->localData[0]->realVars[37] /* Conduction_wall1_outer._port_a._T variable */;
  $PRadiation_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[70]) * (((tmp10 * tmp10 * tmp10)) * ($PConduction_wall1_outer_port_a_TSeedNLSJac6)));
  TRACE_POP
}

/*
 equation index: 149
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._Q_flow._$pDERNLSJac6._dummyVarNLSJac6 = Radiation_wall1_outer.Q_flow.$pDERNLSJac6.dummyVarNLSJac6 + Convection_wall1_outer.Q_flow.$pDERNLSJac6.dummyVarNLSJac6
 */
void OM_Result_eqFunction_149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,149};
  $PConduction_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6 = $PRadiation_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6 + $PConvection_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6;
  TRACE_POP
}

/*
 equation index: 150
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._dT._$pDERNLSJac6._dummyVarNLSJac6 = DIVISION(Conduction_wall1_outer.Q_flow.$pDERNLSJac6.dummyVarNLSJac6, Conduction_wall1_outer.G)
 */
void OM_Result_eqFunction_150(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,150};
  $PConduction_wall1_outer$PdT$P$pDERNLSJac6$PdummyVarNLSJac6 = DIVISION_SIM($PConduction_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6,data->simulationInfo->realParameter[12],"Conduction_wall1_outer.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 151
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac6._dummyVarNLSJac6 = Conduction_wall1_outer_port_a_TSeedNLSJac6 - Conduction_wall1_outer.dT.$pDERNLSJac6.dummyVarNLSJac6
 */
void OM_Result_eqFunction_151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,151};
  $P$res$P1$P$pDERNLSJac6$PdummyVarNLSJac6 = $PConduction_wall1_outer_port_a_TSeedNLSJac6 - $PConduction_wall1_outer$PdT$P$pDERNLSJac6$PdummyVarNLSJac6;
  TRACE_POP
}
int OM_Result_functionJacNLSJac6_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac6;
  OM_Result_eqFunction_147(data, threadData);

  OM_Result_eqFunction_148(data, threadData);

  OM_Result_eqFunction_149(data, threadData);

  OM_Result_eqFunction_150(data, threadData);

  OM_Result_eqFunction_151(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 130
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Q_flow._$pDERNLSJac5._dummyVarNLSJac5 = (-Convection_wall3_outer.Gc) * Conduction_wall3_outer_port_a_TSeedNLSJac5
 */
void OM_Result_eqFunction_130(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,130};
  $PConvection_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5 = ((-data->localData[0]->realVars[64] /* Convection_wall3_outer._Gc variable */)) * ($PConduction_wall3_outer_port_a_TSeedNLSJac5);
  TRACE_POP
}

/*
 equation index: 131
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._Q_flow._$pDERNLSJac5._dummyVarNLSJac5 = -2.2681468e-07 * Radiation_wall3_outer.Gr * Conduction_wall3_outer.port_a.T ^ 3.0 * Conduction_wall3_outer_port_a_TSeedNLSJac5
 */
void OM_Result_eqFunction_131(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,131};
  modelica_real tmp11;
  tmp11 = data->localData[0]->realVars[43] /* Conduction_wall3_outer._port_a._T variable */;
  $PRadiation_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[72]) * (((tmp11 * tmp11 * tmp11)) * ($PConduction_wall3_outer_port_a_TSeedNLSJac5)));
  TRACE_POP
}

/*
 equation index: 132
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._Q_flow._$pDERNLSJac5._dummyVarNLSJac5 = Radiation_wall3_outer.Q_flow.$pDERNLSJac5.dummyVarNLSJac5 + Convection_wall3_outer.Q_flow.$pDERNLSJac5.dummyVarNLSJac5
 */
void OM_Result_eqFunction_132(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,132};
  $PConduction_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5 = $PRadiation_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5 + $PConvection_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5;
  TRACE_POP
}

/*
 equation index: 133
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._dT._$pDERNLSJac5._dummyVarNLSJac5 = DIVISION(Conduction_wall3_outer.Q_flow.$pDERNLSJac5.dummyVarNLSJac5, Conduction_wall3_outer.G)
 */
void OM_Result_eqFunction_133(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,133};
  $PConduction_wall3_outer$PdT$P$pDERNLSJac5$PdummyVarNLSJac5 = DIVISION_SIM($PConduction_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5,data->simulationInfo->realParameter[14],"Conduction_wall3_outer.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 134
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac5._dummyVarNLSJac5 = Conduction_wall3_outer_port_a_TSeedNLSJac5 - Conduction_wall3_outer.dT.$pDERNLSJac5.dummyVarNLSJac5
 */
void OM_Result_eqFunction_134(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,134};
  $P$res$P1$P$pDERNLSJac5$PdummyVarNLSJac5 = $PConduction_wall3_outer_port_a_TSeedNLSJac5 - $PConduction_wall3_outer$PdT$P$pDERNLSJac5$PdummyVarNLSJac5;
  TRACE_POP
}
int OM_Result_functionJacNLSJac5_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac5;
  OM_Result_eqFunction_130(data, threadData);

  OM_Result_eqFunction_131(data, threadData);

  OM_Result_eqFunction_132(data, threadData);

  OM_Result_eqFunction_133(data, threadData);

  OM_Result_eqFunction_134(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 113
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Q_flow._$pDERNLSJac4._dummyVarNLSJac4 = (-Convection_wall4_outer.Gc) * Conduction_wall4_outer_port_a_TSeedNLSJac4
 */
void OM_Result_eqFunction_113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,113};
  $PConvection_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4 = ((-data->localData[0]->realVars[69] /* Convection_wall4_outer._Gc variable */)) * ($PConduction_wall4_outer_port_a_TSeedNLSJac4);
  TRACE_POP
}

/*
 equation index: 114
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._Q_flow._$pDERNLSJac4._dummyVarNLSJac4 = -2.2681468e-07 * Radiation_wall4_outer.Gr * Conduction_wall4_outer.port_a.T ^ 3.0 * Conduction_wall4_outer_port_a_TSeedNLSJac4
 */
void OM_Result_eqFunction_114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,114};
  modelica_real tmp12;
  tmp12 = data->localData[0]->realVars[49] /* Conduction_wall4_outer._port_a._T variable */;
  $PRadiation_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[74]) * (((tmp12 * tmp12 * tmp12)) * ($PConduction_wall4_outer_port_a_TSeedNLSJac4)));
  TRACE_POP
}

/*
 equation index: 115
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._Q_flow._$pDERNLSJac4._dummyVarNLSJac4 = Radiation_wall4_outer.Q_flow.$pDERNLSJac4.dummyVarNLSJac4 + Convection_wall4_outer.Q_flow.$pDERNLSJac4.dummyVarNLSJac4
 */
void OM_Result_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,115};
  $PConduction_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4 = $PRadiation_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4 + $PConvection_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4;
  TRACE_POP
}

/*
 equation index: 116
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._dT._$pDERNLSJac4._dummyVarNLSJac4 = DIVISION(Conduction_wall4_outer.Q_flow.$pDERNLSJac4.dummyVarNLSJac4, Conduction_wall4_outer.G)
 */
void OM_Result_eqFunction_116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,116};
  $PConduction_wall4_outer$PdT$P$pDERNLSJac4$PdummyVarNLSJac4 = DIVISION_SIM($PConduction_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4,data->simulationInfo->realParameter[16],"Conduction_wall4_outer.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 117
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac4._dummyVarNLSJac4 = Conduction_wall4_outer_port_a_TSeedNLSJac4 - Conduction_wall4_outer.dT.$pDERNLSJac4.dummyVarNLSJac4
 */
void OM_Result_eqFunction_117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,117};
  $P$res$P1$P$pDERNLSJac4$PdummyVarNLSJac4 = $PConduction_wall4_outer_port_a_TSeedNLSJac4 - $PConduction_wall4_outer$PdT$P$pDERNLSJac4$PdummyVarNLSJac4;
  TRACE_POP
}
int OM_Result_functionJacNLSJac4_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac4;
  OM_Result_eqFunction_113(data, threadData);

  OM_Result_eqFunction_114(data, threadData);

  OM_Result_eqFunction_115(data, threadData);

  OM_Result_eqFunction_116(data, threadData);

  OM_Result_eqFunction_117(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 67
 type: SIMPLE_ASSIGN
 Convection_roof_inner._Q_flow._$pDERNLSJac3._dummyVarNLSJac3 = Convection_coef_roof_inner.k * Conduction_roof_inner_port_b_TSeedNLSJac3
 */
void OM_Result_eqFunction_67(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,67};
  $PConvection_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3 = (data->simulationInfo->realParameter[20]) * ($PConduction_roof_inner_port_b_TSeedNLSJac3);
  TRACE_POP
}

/*
 equation index: 68
 type: SIMPLE_ASSIGN
 Radiation_roof_to_floor._Q_flow._$pDERNLSJac3._dummyVarNLSJac3 = 2.2681468e-07 * Radiation_roof_to_floor.Gr * Conduction_roof_inner.port_b.T ^ 3.0 * Conduction_roof_inner_port_b_TSeedNLSJac3
 */
void OM_Result_eqFunction_68(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,68};
  modelica_real tmp13;
  tmp13 = data->localData[0]->realVars[28] /* Conduction_roof_inner._port_b._T variable */;
  $PRadiation_roof_to_floor$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3 = (2.2681468e-07) * ((data->simulationInfo->realParameter[68]) * (((tmp13 * tmp13 * tmp13)) * ($PConduction_roof_inner_port_b_TSeedNLSJac3)));
  TRACE_POP
}

/*
 equation index: 69
 type: SIMPLE_ASSIGN
 Radiation_roof_inner._Q_flow._$pDERNLSJac3._dummyVarNLSJac3 = 2.2681468e-07 * Radiation_roof_inner.Gr * Conduction_roof_inner.port_b.T ^ 3.0 * Conduction_roof_inner_port_b_TSeedNLSJac3
 */
void OM_Result_eqFunction_69(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,69};
  modelica_real tmp14;
  tmp14 = data->localData[0]->realVars[28] /* Conduction_roof_inner._port_b._T variable */;
  $PRadiation_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3 = (2.2681468e-07) * ((data->simulationInfo->realParameter[66]) * (((tmp14 * tmp14 * tmp14)) * ($PConduction_roof_inner_port_b_TSeedNLSJac3)));
  TRACE_POP
}

/*
 equation index: 70
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._Q_flow._$pDERNLSJac3._dummyVarNLSJac3 = Radiation_roof_to_floor.Q_flow.$pDERNLSJac3.dummyVarNLSJac3 - ((-Convection_roof_inner.Q_flow.$pDERNLSJac3.dummyVarNLSJac3) - Radiation_roof_inner.Q_flow.$pDERNLSJac3.dummyVarNLSJac3)
 */
void OM_Result_eqFunction_70(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,70};
  $PConduction_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3 = $PRadiation_roof_to_floor$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3 - ((-$PConvection_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3) - $PRadiation_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3);
  TRACE_POP
}

/*
 equation index: 71
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._dT._$pDERNLSJac3._dummyVarNLSJac3 = DIVISION(Conduction_roof_inner.Q_flow.$pDERNLSJac3.dummyVarNLSJac3, Conduction_roof_inner.G)
 */
void OM_Result_eqFunction_71(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,71};
  $PConduction_roof_inner$PdT$P$pDERNLSJac3$PdummyVarNLSJac3 = DIVISION_SIM($PConduction_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3,data->simulationInfo->realParameter[9],"Conduction_roof_inner.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 72
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac3._dummyVarNLSJac3 = (-Conduction_roof_inner_port_b_TSeedNLSJac3) - Conduction_roof_inner.dT.$pDERNLSJac3.dummyVarNLSJac3
 */
void OM_Result_eqFunction_72(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,72};
  $P$res$P1$P$pDERNLSJac3$PdummyVarNLSJac3 = (-$PConduction_roof_inner_port_b_TSeedNLSJac3) - $PConduction_roof_inner$PdT$P$pDERNLSJac3$PdummyVarNLSJac3;
  TRACE_POP
}
int OM_Result_functionJacNLSJac3_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac3;
  OM_Result_eqFunction_67(data, threadData);

  OM_Result_eqFunction_68(data, threadData);

  OM_Result_eqFunction_69(data, threadData);

  OM_Result_eqFunction_70(data, threadData);

  OM_Result_eqFunction_71(data, threadData);

  OM_Result_eqFunction_72(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 53
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._Q_flow._$pDERNLSJac2._dummyVarNLSJac2 = Convection_coef_wall1_inner.k * Conduction_wall1_inner_port_b_TSeedNLSJac2
 */
void OM_Result_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,53};
  $PConvection_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2 = (data->simulationInfo->realParameter[21]) * ($PConduction_wall1_inner_port_b_TSeedNLSJac2);
  TRACE_POP
}

/*
 equation index: 54
 type: SIMPLE_ASSIGN
 Radiation_wall1_inner._Q_flow._$pDERNLSJac2._dummyVarNLSJac2 = 2.2681468e-07 * Radiation_wall1_inner.Gr * Conduction_wall1_inner.port_b.T ^ 3.0 * Conduction_wall1_inner_port_b_TSeedNLSJac2
 */
void OM_Result_eqFunction_54(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,54};
  modelica_real tmp15;
  tmp15 = data->localData[0]->realVars[34] /* Conduction_wall1_inner._port_b._T variable */;
  $PRadiation_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2 = (2.2681468e-07) * ((data->simulationInfo->realParameter[69]) * (((tmp15 * tmp15 * tmp15)) * ($PConduction_wall1_inner_port_b_TSeedNLSJac2)));
  TRACE_POP
}

/*
 equation index: 55
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._Q_flow._$pDERNLSJac2._dummyVarNLSJac2 = Radiation_wall1_inner.Q_flow.$pDERNLSJac2.dummyVarNLSJac2 + Convection_wall1_inner.Q_flow.$pDERNLSJac2.dummyVarNLSJac2
 */
void OM_Result_eqFunction_55(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,55};
  $PConduction_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2 = $PRadiation_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2 + $PConvection_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2;
  TRACE_POP
}

/*
 equation index: 56
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._dT._$pDERNLSJac2._dummyVarNLSJac2 = DIVISION(Conduction_wall1_inner.Q_flow.$pDERNLSJac2.dummyVarNLSJac2, Conduction_wall1_inner.G)
 */
void OM_Result_eqFunction_56(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,56};
  $PConduction_wall1_inner$PdT$P$pDERNLSJac2$PdummyVarNLSJac2 = DIVISION_SIM($PConduction_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2,data->simulationInfo->realParameter[11],"Conduction_wall1_inner.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 57
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac2._dummyVarNLSJac2 = (-Conduction_wall1_inner_port_b_TSeedNLSJac2) - Conduction_wall1_inner.dT.$pDERNLSJac2.dummyVarNLSJac2
 */
void OM_Result_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,57};
  $P$res$P1$P$pDERNLSJac2$PdummyVarNLSJac2 = (-$PConduction_wall1_inner_port_b_TSeedNLSJac2) - $PConduction_wall1_inner$PdT$P$pDERNLSJac2$PdummyVarNLSJac2;
  TRACE_POP
}
int OM_Result_functionJacNLSJac2_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac2;
  OM_Result_eqFunction_53(data, threadData);

  OM_Result_eqFunction_54(data, threadData);

  OM_Result_eqFunction_55(data, threadData);

  OM_Result_eqFunction_56(data, threadData);

  OM_Result_eqFunction_57(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 40
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._Q_flow._$pDERNLSJac1._dummyVarNLSJac1 = Convection_coef_wall3_inner.k * Conduction_wall3_inner_port_b_TSeedNLSJac1
 */
void OM_Result_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,40};
  $PConvection_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1 = (data->simulationInfo->realParameter[22]) * ($PConduction_wall3_inner_port_b_TSeedNLSJac1);
  TRACE_POP
}

/*
 equation index: 41
 type: SIMPLE_ASSIGN
 Radiation_wall3_inner._Q_flow._$pDERNLSJac1._dummyVarNLSJac1 = 2.2681468e-07 * Radiation_wall3_inner.Gr * Conduction_wall3_inner.port_b.T ^ 3.0 * Conduction_wall3_inner_port_b_TSeedNLSJac1
 */
void OM_Result_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,41};
  modelica_real tmp16;
  tmp16 = data->localData[0]->realVars[40] /* Conduction_wall3_inner._port_b._T variable */;
  $PRadiation_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1 = (2.2681468e-07) * ((data->simulationInfo->realParameter[71]) * (((tmp16 * tmp16 * tmp16)) * ($PConduction_wall3_inner_port_b_TSeedNLSJac1)));
  TRACE_POP
}

/*
 equation index: 42
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._Q_flow._$pDERNLSJac1._dummyVarNLSJac1 = Radiation_wall3_inner.Q_flow.$pDERNLSJac1.dummyVarNLSJac1 + Convection_wall3_inner.Q_flow.$pDERNLSJac1.dummyVarNLSJac1
 */
void OM_Result_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,42};
  $PConduction_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1 = $PRadiation_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1 + $PConvection_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1;
  TRACE_POP
}

/*
 equation index: 43
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._dT._$pDERNLSJac1._dummyVarNLSJac1 = DIVISION(Conduction_wall3_inner.Q_flow.$pDERNLSJac1.dummyVarNLSJac1, Conduction_wall3_inner.G)
 */
void OM_Result_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,43};
  $PConduction_wall3_inner$PdT$P$pDERNLSJac1$PdummyVarNLSJac1 = DIVISION_SIM($PConduction_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1,data->simulationInfo->realParameter[13],"Conduction_wall3_inner.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 44
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac1._dummyVarNLSJac1 = (-Conduction_wall3_inner_port_b_TSeedNLSJac1) - Conduction_wall3_inner.dT.$pDERNLSJac1.dummyVarNLSJac1
 */
void OM_Result_eqFunction_44(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,44};
  $P$res$P1$P$pDERNLSJac1$PdummyVarNLSJac1 = (-$PConduction_wall3_inner_port_b_TSeedNLSJac1) - $PConduction_wall3_inner$PdT$P$pDERNLSJac1$PdummyVarNLSJac1;
  TRACE_POP
}
int OM_Result_functionJacNLSJac1_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac1;
  OM_Result_eqFunction_40(data, threadData);

  OM_Result_eqFunction_41(data, threadData);

  OM_Result_eqFunction_42(data, threadData);

  OM_Result_eqFunction_43(data, threadData);

  OM_Result_eqFunction_44(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 27
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._Q_flow._$pDERNLSJac0._dummyVarNLSJac0 = Convection_coef_wall4_inner.k * Conduction_wall4_inner_port_b_TSeedNLSJac0
 */
void OM_Result_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,27};
  $PConvection_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0 = (data->simulationInfo->realParameter[23]) * ($PConduction_wall4_inner_port_b_TSeedNLSJac0);
  TRACE_POP
}

/*
 equation index: 28
 type: SIMPLE_ASSIGN
 Radiation_wall4_inner._Q_flow._$pDERNLSJac0._dummyVarNLSJac0 = 2.2681468e-07 * Radiation_wall4_inner.Gr * Conduction_wall4_inner.port_b.T ^ 3.0 * Conduction_wall4_inner_port_b_TSeedNLSJac0
 */
void OM_Result_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,28};
  modelica_real tmp17;
  tmp17 = data->localData[0]->realVars[46] /* Conduction_wall4_inner._port_b._T variable */;
  $PRadiation_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0 = (2.2681468e-07) * ((data->simulationInfo->realParameter[73]) * (((tmp17 * tmp17 * tmp17)) * ($PConduction_wall4_inner_port_b_TSeedNLSJac0)));
  TRACE_POP
}

/*
 equation index: 29
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._Q_flow._$pDERNLSJac0._dummyVarNLSJac0 = Radiation_wall4_inner.Q_flow.$pDERNLSJac0.dummyVarNLSJac0 + Convection_wall4_inner.Q_flow.$pDERNLSJac0.dummyVarNLSJac0
 */
void OM_Result_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,29};
  $PConduction_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0 = $PRadiation_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0 + $PConvection_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0;
  TRACE_POP
}

/*
 equation index: 30
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._dT._$pDERNLSJac0._dummyVarNLSJac0 = DIVISION(Conduction_wall4_inner.Q_flow.$pDERNLSJac0.dummyVarNLSJac0, Conduction_wall4_inner.G)
 */
void OM_Result_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,30};
  $PConduction_wall4_inner$PdT$P$pDERNLSJac0$PdummyVarNLSJac0 = DIVISION_SIM($PConduction_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0,data->simulationInfo->realParameter[15],"Conduction_wall4_inner.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 31
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac0._dummyVarNLSJac0 = (-Conduction_wall4_inner_port_b_TSeedNLSJac0) - Conduction_wall4_inner.dT.$pDERNLSJac0.dummyVarNLSJac0
 */
void OM_Result_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,31};
  $P$res$P1$P$pDERNLSJac0$PdummyVarNLSJac0 = (-$PConduction_wall4_inner_port_b_TSeedNLSJac0) - $PConduction_wall4_inner$PdT$P$pDERNLSJac0$PdummyVarNLSJac0;
  TRACE_POP
}
int OM_Result_functionJacNLSJac0_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac0;
  OM_Result_eqFunction_27(data, threadData);

  OM_Result_eqFunction_28(data, threadData);

  OM_Result_eqFunction_29(data, threadData);

  OM_Result_eqFunction_30(data, threadData);

  OM_Result_eqFunction_31(data, threadData);
  
  TRACE_POP
  return 0;
}
int OM_Result_functionJacA_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_A;
  
  TRACE_POP
  return 0;
}
int OM_Result_functionJacB_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int OM_Result_functionJacC_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int OM_Result_functionJacD_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}



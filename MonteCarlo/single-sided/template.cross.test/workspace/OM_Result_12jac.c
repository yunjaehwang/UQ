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
 equation index: 357
 type: SIMPLE_ASSIGN
 Convection_wall1_inner._Q_flow._$pDERNLSJac15._dummyVarNLSJac15 = Convection_coef_wall1_inner.k * Conduction_wall1_inner_port_b_TSeedNLSJac15
 */
void OM_Result_eqFunction_357(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,357};
  $PConvection_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15 = (data->simulationInfo->realParameter[21]) * ($PConduction_wall1_inner_port_b_TSeedNLSJac15);
  TRACE_POP
}

/*
 equation index: 358
 type: SIMPLE_ASSIGN
 Radiation_wall1_inner._Q_flow._$pDERNLSJac15._dummyVarNLSJac15 = 2.2681468e-07 * Radiation_wall1_inner.Gr * Conduction_wall1_inner.port_b.T ^ 3.0 * Conduction_wall1_inner_port_b_TSeedNLSJac15
 */
void OM_Result_eqFunction_358(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,358};
  modelica_real tmp21;
  tmp21 = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */;
  $PRadiation_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15 = (2.2681468e-07) * ((data->simulationInfo->realParameter[63]) * (((tmp21 * tmp21 * tmp21)) * ($PConduction_wall1_inner_port_b_TSeedNLSJac15)));
  TRACE_POP
}

/*
 equation index: 359
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._Q_flow._$pDERNLSJac15._dummyVarNLSJac15 = Radiation_wall1_inner.Q_flow.$pDERNLSJac15.dummyVarNLSJac15 + Convection_wall1_inner.Q_flow.$pDERNLSJac15.dummyVarNLSJac15
 */
void OM_Result_eqFunction_359(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,359};
  $PConduction_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15 = $PRadiation_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15 + $PConvection_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15;
  TRACE_POP
}

/*
 equation index: 360
 type: SIMPLE_ASSIGN
 Conduction_wall1_inner._dT._$pDERNLSJac15._dummyVarNLSJac15 = DIVISION(Conduction_wall1_inner.Q_flow.$pDERNLSJac15.dummyVarNLSJac15, Conduction_wall1_inner.G)
 */
void OM_Result_eqFunction_360(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,360};
  $PConduction_wall1_inner$PdT$P$pDERNLSJac15$PdummyVarNLSJac15 = DIVISION_SIM($PConduction_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15,data->simulationInfo->realParameter[11],"Conduction_wall1_inner.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 361
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac15._dummyVarNLSJac15 = (-Conduction_wall1_inner_port_b_TSeedNLSJac15) - Conduction_wall1_inner.dT.$pDERNLSJac15.dummyVarNLSJac15
 */
void OM_Result_eqFunction_361(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,361};
  $P$res$P1$P$pDERNLSJac15$PdummyVarNLSJac15 = (-$PConduction_wall1_inner_port_b_TSeedNLSJac15) - $PConduction_wall1_inner$PdT$P$pDERNLSJac15$PdummyVarNLSJac15;
  TRACE_POP
}
int OM_Result_functionJacNLSJac15_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac15;
  OM_Result_eqFunction_357(data, threadData);

  OM_Result_eqFunction_358(data, threadData);

  OM_Result_eqFunction_359(data, threadData);

  OM_Result_eqFunction_360(data, threadData);

  OM_Result_eqFunction_361(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 342
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Q_flow._$pDERNLSJac14._dummyVarNLSJac14 = (-Convection_wall1_outer.Gc) * Conduction_wall1_outer_port_a_TSeedNLSJac14
 */
void OM_Result_eqFunction_342(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,342};
  $PConvection_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14 = ((-data->localData[0]->realVars[56] /* Convection_wall1_outer._Gc variable */)) * ($PConduction_wall1_outer_port_a_TSeedNLSJac14);
  TRACE_POP
}

/*
 equation index: 343
 type: SIMPLE_ASSIGN
 Heatflow_solar_wall1._port._Q_flow._$pDERNLSJac14._dummyVarNLSJac14 = (-Heatflow_solar_wall1.Q_flow) * Heatflow_solar_wall1.alpha * Conduction_wall1_outer_port_a_TSeedNLSJac14
 */
void OM_Result_eqFunction_343(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,343};
  $PHeatflow_solar_wall1$Pport$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14 = ((-data->localData[0]->realVars[78] /* Heatflow_solar_wall1._Q_flow variable */)) * ((data->simulationInfo->realParameter[57]) * ($PConduction_wall1_outer_port_a_TSeedNLSJac14));
  TRACE_POP
}

/*
 equation index: 344
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._Q_flow._$pDERNLSJac14._dummyVarNLSJac14 = -2.2681468e-07 * Radiation_wall1_outer.Gr * Conduction_wall1_outer.port_a.T ^ 3.0 * Conduction_wall1_outer_port_a_TSeedNLSJac14
 */
void OM_Result_eqFunction_344(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,344};
  modelica_real tmp22;
  tmp22 = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
  $PRadiation_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[64]) * (((tmp22 * tmp22 * tmp22)) * ($PConduction_wall1_outer_port_a_TSeedNLSJac14)));
  TRACE_POP
}

/*
 equation index: 345
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._Q_flow._$pDERNLSJac14._dummyVarNLSJac14 = Convection_wall1_outer.Q_flow.$pDERNLSJac14.dummyVarNLSJac14 - (Heatflow_solar_wall1.port.Q_flow.$pDERNLSJac14.dummyVarNLSJac14 - Radiation_wall1_outer.Q_flow.$pDERNLSJac14.dummyVarNLSJac14)
 */
void OM_Result_eqFunction_345(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,345};
  $PConduction_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14 = $PConvection_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14 - ($PHeatflow_solar_wall1$Pport$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14 - $PRadiation_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14);
  TRACE_POP
}

/*
 equation index: 346
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._dT._$pDERNLSJac14._dummyVarNLSJac14 = DIVISION(Conduction_wall1_outer.Q_flow.$pDERNLSJac14.dummyVarNLSJac14, Conduction_wall1_outer.G)
 */
void OM_Result_eqFunction_346(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,346};
  $PConduction_wall1_outer$PdT$P$pDERNLSJac14$PdummyVarNLSJac14 = DIVISION_SIM($PConduction_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14,data->simulationInfo->realParameter[12],"Conduction_wall1_outer.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 347
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac14._dummyVarNLSJac14 = Conduction_wall1_outer_port_a_TSeedNLSJac14 - Conduction_wall1_outer.dT.$pDERNLSJac14.dummyVarNLSJac14
 */
void OM_Result_eqFunction_347(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,347};
  $P$res$P1$P$pDERNLSJac14$PdummyVarNLSJac14 = $PConduction_wall1_outer_port_a_TSeedNLSJac14 - $PConduction_wall1_outer$PdT$P$pDERNLSJac14$PdummyVarNLSJac14;
  TRACE_POP
}
int OM_Result_functionJacNLSJac14_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac14;
  OM_Result_eqFunction_342(data, threadData);

  OM_Result_eqFunction_343(data, threadData);

  OM_Result_eqFunction_344(data, threadData);

  OM_Result_eqFunction_345(data, threadData);

  OM_Result_eqFunction_346(data, threadData);

  OM_Result_eqFunction_347(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 324
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Q_flow._$pDERNLSJac13._dummyVarNLSJac13 = (-Convection_roof_outer.Gc) * Conduction_roof_outer_port_a_TSeedNLSJac13
 */
void OM_Result_eqFunction_324(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,324};
  $PConvection_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 = ((-data->localData[0]->realVars[51] /* Convection_roof_outer._Gc variable */)) * ($PConduction_roof_outer_port_a_TSeedNLSJac13);
  TRACE_POP
}

/*
 equation index: 325
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._port._Q_flow._$pDERNLSJac13._dummyVarNLSJac13 = (-Heatflow_solar_radiation.Q_flow) * Heatflow_solar_radiation.alpha * Conduction_roof_outer_port_a_TSeedNLSJac13
 */
void OM_Result_eqFunction_325(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,325};
  $PHeatflow_solar_radiation$Pport$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 = ((-data->localData[0]->realVars[76] /* Heatflow_solar_radiation._Q_flow variable */)) * ((data->simulationInfo->realParameter[55]) * ($PConduction_roof_outer_port_a_TSeedNLSJac13));
  TRACE_POP
}

/*
 equation index: 326
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._Q_flow._$pDERNLSJac13._dummyVarNLSJac13 = -2.2681468e-07 * Radiation_roof_outer.Gr * Conduction_roof_outer.port_a.T ^ 3.0 * Conduction_roof_outer_port_a_TSeedNLSJac13
 */
void OM_Result_eqFunction_326(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,326};
  modelica_real tmp23;
  tmp23 = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
  $PRadiation_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[61]) * (((tmp23 * tmp23 * tmp23)) * ($PConduction_roof_outer_port_a_TSeedNLSJac13)));
  TRACE_POP
}

/*
 equation index: 327
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._Q_flow._$pDERNLSJac13._dummyVarNLSJac13 = Convection_roof_outer.Q_flow.$pDERNLSJac13.dummyVarNLSJac13 - (Heatflow_solar_radiation.port.Q_flow.$pDERNLSJac13.dummyVarNLSJac13 - Radiation_roof_outer.Q_flow.$pDERNLSJac13.dummyVarNLSJac13)
 */
void OM_Result_eqFunction_327(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,327};
  $PConduction_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 = $PConvection_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 - ($PHeatflow_solar_radiation$Pport$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 - $PRadiation_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13);
  TRACE_POP
}

/*
 equation index: 328
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._dT._$pDERNLSJac13._dummyVarNLSJac13 = DIVISION(Conduction_roof_outer.Q_flow.$pDERNLSJac13.dummyVarNLSJac13, Conduction_roof_outer.G)
 */
void OM_Result_eqFunction_328(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,328};
  $PConduction_roof_outer$PdT$P$pDERNLSJac13$PdummyVarNLSJac13 = DIVISION_SIM($PConduction_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13,data->simulationInfo->realParameter[10],"Conduction_roof_outer.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 329
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac13._dummyVarNLSJac13 = Conduction_roof_outer_port_a_TSeedNLSJac13 - Conduction_roof_outer.dT.$pDERNLSJac13.dummyVarNLSJac13
 */
void OM_Result_eqFunction_329(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,329};
  $P$res$P1$P$pDERNLSJac13$PdummyVarNLSJac13 = $PConduction_roof_outer_port_a_TSeedNLSJac13 - $PConduction_roof_outer$PdT$P$pDERNLSJac13$PdummyVarNLSJac13;
  TRACE_POP
}
int OM_Result_functionJacNLSJac13_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac13;
  OM_Result_eqFunction_324(data, threadData);

  OM_Result_eqFunction_325(data, threadData);

  OM_Result_eqFunction_326(data, threadData);

  OM_Result_eqFunction_327(data, threadData);

  OM_Result_eqFunction_328(data, threadData);

  OM_Result_eqFunction_329(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 307
 type: SIMPLE_ASSIGN
 Conduction_roof_inner._Q_flow._$pDERNLSJac12._dummyVarNLSJac12 = (-Conduction_roof_inner.G) * Conduction_roof_inner_port_b_TSeedNLSJac12
 */
void OM_Result_eqFunction_307(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,307};
  $PConduction_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 = ((-data->simulationInfo->realParameter[9])) * ($PConduction_roof_inner_port_b_TSeedNLSJac12);
  TRACE_POP
}

/*
 equation index: 308
 type: SIMPLE_ASSIGN
 Radiation_roof_inner._Q_flow._$pDERNLSJac12._dummyVarNLSJac12 = 2.2681468e-07 * Radiation_roof_inner.Gr * Conduction_roof_inner.port_b.T ^ 3.0 * Conduction_roof_inner_port_b_TSeedNLSJac12
 */
void OM_Result_eqFunction_308(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,308};
  modelica_real tmp24;
  tmp24 = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  $PRadiation_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 = (2.2681468e-07) * ((data->simulationInfo->realParameter[60]) * (((tmp24 * tmp24 * tmp24)) * ($PConduction_roof_inner_port_b_TSeedNLSJac12)));
  TRACE_POP
}

/*
 equation index: 309
 type: SIMPLE_ASSIGN
 Radiation_roof_to_floor._Q_flow._$pDERNLSJac12._dummyVarNLSJac12 = 2.2681468e-07 * Radiation_roof_to_floor.Gr * Conduction_roof_inner.port_b.T ^ 3.0 * Conduction_roof_inner_port_b_TSeedNLSJac12
 */
void OM_Result_eqFunction_309(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,309};
  modelica_real tmp25;
  tmp25 = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  $PRadiation_roof_to_floor$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 = (2.2681468e-07) * ((data->simulationInfo->realParameter[62]) * (((tmp25 * tmp25 * tmp25)) * ($PConduction_roof_inner_port_b_TSeedNLSJac12)));
  TRACE_POP
}

/*
 equation index: 310
 type: SIMPLE_ASSIGN
 Convection_roof_inner._Q_flow._$pDERNLSJac12._dummyVarNLSJac12 = Conduction_roof_inner.Q_flow.$pDERNLSJac12.dummyVarNLSJac12 - (Radiation_roof_inner.Q_flow.$pDERNLSJac12.dummyVarNLSJac12 + Radiation_roof_to_floor.Q_flow.$pDERNLSJac12.dummyVarNLSJac12)
 */
void OM_Result_eqFunction_310(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,310};
  $PConvection_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 = $PConduction_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 - ($PRadiation_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 + $PRadiation_roof_to_floor$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12);
  TRACE_POP
}

/*
 equation index: 311
 type: SIMPLE_ASSIGN
 Convection_roof_inner._dT._$pDERNLSJac12._dummyVarNLSJac12 = DIVISION(Convection_roof_inner.Q_flow.$pDERNLSJac12.dummyVarNLSJac12, Convection_coef_roof_inner.k)
 */
void OM_Result_eqFunction_311(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,311};
  $PConvection_roof_inner$PdT$P$pDERNLSJac12$PdummyVarNLSJac12 = DIVISION_SIM($PConvection_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12,data->simulationInfo->realParameter[20],"Convection_coef_roof_inner.k",equationIndexes);
  TRACE_POP
}

/*
 equation index: 312
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac12._dummyVarNLSJac12 = Conduction_roof_inner_port_b_TSeedNLSJac12 - Convection_roof_inner.dT.$pDERNLSJac12.dummyVarNLSJac12
 */
void OM_Result_eqFunction_312(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,312};
  $P$res$P1$P$pDERNLSJac12$PdummyVarNLSJac12 = $PConduction_roof_inner_port_b_TSeedNLSJac12 - $PConvection_roof_inner$PdT$P$pDERNLSJac12$PdummyVarNLSJac12;
  TRACE_POP
}
int OM_Result_functionJacNLSJac12_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac12;
  OM_Result_eqFunction_307(data, threadData);

  OM_Result_eqFunction_308(data, threadData);

  OM_Result_eqFunction_309(data, threadData);

  OM_Result_eqFunction_310(data, threadData);

  OM_Result_eqFunction_311(data, threadData);

  OM_Result_eqFunction_312(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 290
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Q_flow._$pDERNLSJac11._dummyVarNLSJac11 = (-Convection_wall3_outer.Gc) * Conduction_wall3_outer_port_a_TSeedNLSJac11
 */
void OM_Result_eqFunction_290(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,290};
  $PConvection_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11 = ((-data->localData[0]->realVars[61] /* Convection_wall3_outer._Gc variable */)) * ($PConduction_wall3_outer_port_a_TSeedNLSJac11);
  TRACE_POP
}

/*
 equation index: 291
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._Q_flow._$pDERNLSJac11._dummyVarNLSJac11 = -2.2681468e-07 * Radiation_wall3_outer.Gr * Conduction_wall3_outer.port_a.T ^ 3.0 * Conduction_wall3_outer_port_a_TSeedNLSJac11
 */
void OM_Result_eqFunction_291(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,291};
  modelica_real tmp26;
  tmp26 = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
  $PRadiation_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[66]) * (((tmp26 * tmp26 * tmp26)) * ($PConduction_wall3_outer_port_a_TSeedNLSJac11)));
  TRACE_POP
}

/*
 equation index: 292
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._Q_flow._$pDERNLSJac11._dummyVarNLSJac11 = Radiation_wall3_outer.Q_flow.$pDERNLSJac11.dummyVarNLSJac11 + Convection_wall3_outer.Q_flow.$pDERNLSJac11.dummyVarNLSJac11
 */
void OM_Result_eqFunction_292(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,292};
  $PConduction_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11 = $PRadiation_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11 + $PConvection_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11;
  TRACE_POP
}

/*
 equation index: 293
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._dT._$pDERNLSJac11._dummyVarNLSJac11 = DIVISION(Conduction_wall3_outer.Q_flow.$pDERNLSJac11.dummyVarNLSJac11, Conduction_wall3_outer.G)
 */
void OM_Result_eqFunction_293(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,293};
  $PConduction_wall3_outer$PdT$P$pDERNLSJac11$PdummyVarNLSJac11 = DIVISION_SIM($PConduction_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11,data->simulationInfo->realParameter[14],"Conduction_wall3_outer.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 294
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac11._dummyVarNLSJac11 = Conduction_wall3_outer_port_a_TSeedNLSJac11 - Conduction_wall3_outer.dT.$pDERNLSJac11.dummyVarNLSJac11
 */
void OM_Result_eqFunction_294(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,294};
  $P$res$P1$P$pDERNLSJac11$PdummyVarNLSJac11 = $PConduction_wall3_outer_port_a_TSeedNLSJac11 - $PConduction_wall3_outer$PdT$P$pDERNLSJac11$PdummyVarNLSJac11;
  TRACE_POP
}
int OM_Result_functionJacNLSJac11_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac11;
  OM_Result_eqFunction_290(data, threadData);

  OM_Result_eqFunction_291(data, threadData);

  OM_Result_eqFunction_292(data, threadData);

  OM_Result_eqFunction_293(data, threadData);

  OM_Result_eqFunction_294(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 277
 type: SIMPLE_ASSIGN
 Convection_wall3_inner._Q_flow._$pDERNLSJac10._dummyVarNLSJac10 = Convection_coef_wall3_inner.k * Conduction_wall3_inner_port_b_TSeedNLSJac10
 */
void OM_Result_eqFunction_277(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,277};
  $PConvection_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10 = (data->simulationInfo->realParameter[22]) * ($PConduction_wall3_inner_port_b_TSeedNLSJac10);
  TRACE_POP
}

/*
 equation index: 278
 type: SIMPLE_ASSIGN
 Radiation_wall3_inner._Q_flow._$pDERNLSJac10._dummyVarNLSJac10 = 2.2681468e-07 * Radiation_wall3_inner.Gr * Conduction_wall3_inner.port_b.T ^ 3.0 * Conduction_wall3_inner_port_b_TSeedNLSJac10
 */
void OM_Result_eqFunction_278(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,278};
  modelica_real tmp27;
  tmp27 = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
  $PRadiation_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10 = (2.2681468e-07) * ((data->simulationInfo->realParameter[65]) * (((tmp27 * tmp27 * tmp27)) * ($PConduction_wall3_inner_port_b_TSeedNLSJac10)));
  TRACE_POP
}

/*
 equation index: 279
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._Q_flow._$pDERNLSJac10._dummyVarNLSJac10 = Radiation_wall3_inner.Q_flow.$pDERNLSJac10.dummyVarNLSJac10 + Convection_wall3_inner.Q_flow.$pDERNLSJac10.dummyVarNLSJac10
 */
void OM_Result_eqFunction_279(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,279};
  $PConduction_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10 = $PRadiation_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10 + $PConvection_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10;
  TRACE_POP
}

/*
 equation index: 280
 type: SIMPLE_ASSIGN
 Conduction_wall3_inner._dT._$pDERNLSJac10._dummyVarNLSJac10 = DIVISION(Conduction_wall3_inner.Q_flow.$pDERNLSJac10.dummyVarNLSJac10, Conduction_wall3_inner.G)
 */
void OM_Result_eqFunction_280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,280};
  $PConduction_wall3_inner$PdT$P$pDERNLSJac10$PdummyVarNLSJac10 = DIVISION_SIM($PConduction_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10,data->simulationInfo->realParameter[13],"Conduction_wall3_inner.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 281
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac10._dummyVarNLSJac10 = (-Conduction_wall3_inner_port_b_TSeedNLSJac10) - Conduction_wall3_inner.dT.$pDERNLSJac10.dummyVarNLSJac10
 */
void OM_Result_eqFunction_281(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,281};
  $P$res$P1$P$pDERNLSJac10$PdummyVarNLSJac10 = (-$PConduction_wall3_inner_port_b_TSeedNLSJac10) - $PConduction_wall3_inner$PdT$P$pDERNLSJac10$PdummyVarNLSJac10;
  TRACE_POP
}
int OM_Result_functionJacNLSJac10_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac10;
  OM_Result_eqFunction_277(data, threadData);

  OM_Result_eqFunction_278(data, threadData);

  OM_Result_eqFunction_279(data, threadData);

  OM_Result_eqFunction_280(data, threadData);

  OM_Result_eqFunction_281(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 262
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._Q_flow._$pDERNLSJac9._dummyVarNLSJac9 = Conduction_wall4_outer.G * Conduction_wall4_outer_port_a_TSeedNLSJac9
 */
void OM_Result_eqFunction_262(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,262};
  $PConduction_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9 = (data->simulationInfo->realParameter[16]) * ($PConduction_wall4_outer_port_a_TSeedNLSJac9);
  TRACE_POP
}

/*
 equation index: 263
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._Q_flow._$pDERNLSJac9._dummyVarNLSJac9 = -2.2681468e-07 * Radiation_wall4_outer.Gr * Conduction_wall4_outer.port_a.T ^ 3.0 * Conduction_wall4_outer_port_a_TSeedNLSJac9
 */
void OM_Result_eqFunction_263(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,263};
  modelica_real tmp28;
  tmp28 = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
  $PRadiation_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[68]) * (((tmp28 * tmp28 * tmp28)) * ($PConduction_wall4_outer_port_a_TSeedNLSJac9)));
  TRACE_POP
}

/*
 equation index: 264
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Q_flow._$pDERNLSJac9._dummyVarNLSJac9 = Conduction_wall4_outer.Q_flow.$pDERNLSJac9.dummyVarNLSJac9 - Radiation_wall4_outer.Q_flow.$pDERNLSJac9.dummyVarNLSJac9
 */
void OM_Result_eqFunction_264(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,264};
  $PConvection_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9 = $PConduction_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9 - $PRadiation_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9;
  TRACE_POP
}

/*
 equation index: 265
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac9._dummyVarNLSJac9 = (-Convection_wall4_outer.Gc) * Conduction_wall4_outer_port_a_TSeedNLSJac9 - Convection_wall4_outer.Q_flow.$pDERNLSJac9.dummyVarNLSJac9
 */
void OM_Result_eqFunction_265(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,265};
  $P$res$P1$P$pDERNLSJac9$PdummyVarNLSJac9 = ((-data->localData[0]->realVars[66] /* Convection_wall4_outer._Gc variable */)) * ($PConduction_wall4_outer_port_a_TSeedNLSJac9) - $PConvection_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9;
  TRACE_POP
}
int OM_Result_functionJacNLSJac9_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac9;
  OM_Result_eqFunction_262(data, threadData);

  OM_Result_eqFunction_263(data, threadData);

  OM_Result_eqFunction_264(data, threadData);

  OM_Result_eqFunction_265(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 249
 type: SIMPLE_ASSIGN
 Convection_wall4_inner._Q_flow._$pDERNLSJac8._dummyVarNLSJac8 = Convection_coef_wall4_inner.k * Conduction_wall4_inner_port_b_TSeedNLSJac8
 */
void OM_Result_eqFunction_249(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,249};
  $PConvection_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8 = (data->simulationInfo->realParameter[23]) * ($PConduction_wall4_inner_port_b_TSeedNLSJac8);
  TRACE_POP
}

/*
 equation index: 250
 type: SIMPLE_ASSIGN
 Radiation_wall4_inner._Q_flow._$pDERNLSJac8._dummyVarNLSJac8 = 2.2681468e-07 * Radiation_wall4_inner.Gr * Conduction_wall4_inner.port_b.T ^ 3.0 * Conduction_wall4_inner_port_b_TSeedNLSJac8
 */
void OM_Result_eqFunction_250(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,250};
  modelica_real tmp29;
  tmp29 = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */;
  $PRadiation_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8 = (2.2681468e-07) * ((data->simulationInfo->realParameter[67]) * (((tmp29 * tmp29 * tmp29)) * ($PConduction_wall4_inner_port_b_TSeedNLSJac8)));
  TRACE_POP
}

/*
 equation index: 251
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._Q_flow._$pDERNLSJac8._dummyVarNLSJac8 = Radiation_wall4_inner.Q_flow.$pDERNLSJac8.dummyVarNLSJac8 + Convection_wall4_inner.Q_flow.$pDERNLSJac8.dummyVarNLSJac8
 */
void OM_Result_eqFunction_251(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,251};
  $PConduction_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8 = $PRadiation_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8 + $PConvection_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8;
  TRACE_POP
}

/*
 equation index: 252
 type: SIMPLE_ASSIGN
 Conduction_wall4_inner._dT._$pDERNLSJac8._dummyVarNLSJac8 = DIVISION(Conduction_wall4_inner.Q_flow.$pDERNLSJac8.dummyVarNLSJac8, Conduction_wall4_inner.G)
 */
void OM_Result_eqFunction_252(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,252};
  $PConduction_wall4_inner$PdT$P$pDERNLSJac8$PdummyVarNLSJac8 = DIVISION_SIM($PConduction_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8,data->simulationInfo->realParameter[15],"Conduction_wall4_inner.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 253
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac8._dummyVarNLSJac8 = (-Conduction_wall4_inner_port_b_TSeedNLSJac8) - Conduction_wall4_inner.dT.$pDERNLSJac8.dummyVarNLSJac8
 */
void OM_Result_eqFunction_253(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,253};
  $P$res$P1$P$pDERNLSJac8$PdummyVarNLSJac8 = (-$PConduction_wall4_inner_port_b_TSeedNLSJac8) - $PConduction_wall4_inner$PdT$P$pDERNLSJac8$PdummyVarNLSJac8;
  TRACE_POP
}
int OM_Result_functionJacNLSJac8_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac8;
  OM_Result_eqFunction_249(data, threadData);

  OM_Result_eqFunction_250(data, threadData);

  OM_Result_eqFunction_251(data, threadData);

  OM_Result_eqFunction_252(data, threadData);

  OM_Result_eqFunction_253(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 157
 type: SIMPLE_ASSIGN
 Conduction_roof_outer._Q_flow._$pDERNLSJac7._dummyVarNLSJac7 = Conduction_roof_outer.G * Conduction_roof_outer_port_a_TSeedNLSJac7
 */
void OM_Result_eqFunction_157(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,157};
  $PConduction_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 = (data->simulationInfo->realParameter[10]) * ($PConduction_roof_outer_port_a_TSeedNLSJac7);
  TRACE_POP
}

/*
 equation index: 158
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._port._Q_flow._$pDERNLSJac7._dummyVarNLSJac7 = (-Heatflow_solar_radiation.Q_flow) * Heatflow_solar_radiation.alpha * Conduction_roof_outer_port_a_TSeedNLSJac7
 */
void OM_Result_eqFunction_158(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,158};
  $PHeatflow_solar_radiation$Pport$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 = ((-data->localData[0]->realVars[76] /* Heatflow_solar_radiation._Q_flow variable */)) * ((data->simulationInfo->realParameter[55]) * ($PConduction_roof_outer_port_a_TSeedNLSJac7));
  TRACE_POP
}

/*
 equation index: 159
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._Q_flow._$pDERNLSJac7._dummyVarNLSJac7 = -2.2681468e-07 * Radiation_roof_outer.Gr * Conduction_roof_outer.port_a.T ^ 3.0 * Conduction_roof_outer_port_a_TSeedNLSJac7
 */
void OM_Result_eqFunction_159(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,159};
  modelica_real tmp30;
  tmp30 = data->localData[0]->realVars[28] /* Conduction_roof_outer._port_a._T variable */;
  $PRadiation_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[61]) * (((tmp30 * tmp30 * tmp30)) * ($PConduction_roof_outer_port_a_TSeedNLSJac7)));
  TRACE_POP
}

/*
 equation index: 160
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Q_flow._$pDERNLSJac7._dummyVarNLSJac7 = Conduction_roof_outer.Q_flow.$pDERNLSJac7.dummyVarNLSJac7 + Heatflow_solar_radiation.port.Q_flow.$pDERNLSJac7.dummyVarNLSJac7 - Radiation_roof_outer.Q_flow.$pDERNLSJac7.dummyVarNLSJac7
 */
void OM_Result_eqFunction_160(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,160};
  $PConvection_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 = $PConduction_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 + $PHeatflow_solar_radiation$Pport$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 - $PRadiation_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7;
  TRACE_POP
}

/*
 equation index: 161
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac7._dummyVarNLSJac7 = (-Convection_roof_outer.Gc) * Conduction_roof_outer_port_a_TSeedNLSJac7 - Convection_roof_outer.Q_flow.$pDERNLSJac7.dummyVarNLSJac7
 */
void OM_Result_eqFunction_161(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,161};
  $P$res$P1$P$pDERNLSJac7$PdummyVarNLSJac7 = ((-data->localData[0]->realVars[51] /* Convection_roof_outer._Gc variable */)) * ($PConduction_roof_outer_port_a_TSeedNLSJac7) - $PConvection_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7;
  TRACE_POP
}
int OM_Result_functionJacNLSJac7_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac7;
  OM_Result_eqFunction_157(data, threadData);

  OM_Result_eqFunction_158(data, threadData);

  OM_Result_eqFunction_159(data, threadData);

  OM_Result_eqFunction_160(data, threadData);

  OM_Result_eqFunction_161(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 139
 type: SIMPLE_ASSIGN
 Conduction_wall1_outer._Q_flow._$pDERNLSJac6._dummyVarNLSJac6 = Conduction_wall1_outer.G * Conduction_wall1_outer_port_a_TSeedNLSJac6
 */
void OM_Result_eqFunction_139(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,139};
  $PConduction_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6 = (data->simulationInfo->realParameter[12]) * ($PConduction_wall1_outer_port_a_TSeedNLSJac6);
  TRACE_POP
}

/*
 equation index: 140
 type: SIMPLE_ASSIGN
 Heatflow_solar_wall1._port._Q_flow._$pDERNLSJac6._dummyVarNLSJac6 = (-Heatflow_solar_wall1.Q_flow) * Heatflow_solar_wall1.alpha * Conduction_wall1_outer_port_a_TSeedNLSJac6
 */
void OM_Result_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,140};
  $PHeatflow_solar_wall1$Pport$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6 = ((-data->localData[0]->realVars[78] /* Heatflow_solar_wall1._Q_flow variable */)) * ((data->simulationInfo->realParameter[57]) * ($PConduction_wall1_outer_port_a_TSeedNLSJac6));
  TRACE_POP
}

/*
 equation index: 141
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._Q_flow._$pDERNLSJac6._dummyVarNLSJac6 = -2.2681468e-07 * Radiation_wall1_outer.Gr * Conduction_wall1_outer.port_a.T ^ 3.0 * Conduction_wall1_outer_port_a_TSeedNLSJac6
 */
void OM_Result_eqFunction_141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,141};
  modelica_real tmp31;
  tmp31 = data->localData[0]->realVars[34] /* Conduction_wall1_outer._port_a._T variable */;
  $PRadiation_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[64]) * (((tmp31 * tmp31 * tmp31)) * ($PConduction_wall1_outer_port_a_TSeedNLSJac6)));
  TRACE_POP
}

/*
 equation index: 142
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Q_flow._$pDERNLSJac6._dummyVarNLSJac6 = Conduction_wall1_outer.Q_flow.$pDERNLSJac6.dummyVarNLSJac6 + Heatflow_solar_wall1.port.Q_flow.$pDERNLSJac6.dummyVarNLSJac6 - Radiation_wall1_outer.Q_flow.$pDERNLSJac6.dummyVarNLSJac6
 */
void OM_Result_eqFunction_142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,142};
  $PConvection_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6 = $PConduction_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6 + $PHeatflow_solar_wall1$Pport$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6 - $PRadiation_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6;
  TRACE_POP
}

/*
 equation index: 143
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac6._dummyVarNLSJac6 = (-Convection_wall1_outer.Gc) * Conduction_wall1_outer_port_a_TSeedNLSJac6 - Convection_wall1_outer.Q_flow.$pDERNLSJac6.dummyVarNLSJac6
 */
void OM_Result_eqFunction_143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,143};
  $P$res$P1$P$pDERNLSJac6$PdummyVarNLSJac6 = ((-data->localData[0]->realVars[56] /* Convection_wall1_outer._Gc variable */)) * ($PConduction_wall1_outer_port_a_TSeedNLSJac6) - $PConvection_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6;
  TRACE_POP
}
int OM_Result_functionJacNLSJac6_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac6;
  OM_Result_eqFunction_139(data, threadData);

  OM_Result_eqFunction_140(data, threadData);

  OM_Result_eqFunction_141(data, threadData);

  OM_Result_eqFunction_142(data, threadData);

  OM_Result_eqFunction_143(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 121
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Q_flow._$pDERNLSJac5._dummyVarNLSJac5 = (-Convection_wall3_outer.Gc) * Conduction_wall3_outer_port_a_TSeedNLSJac5
 */
void OM_Result_eqFunction_121(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,121};
  $PConvection_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5 = ((-data->localData[0]->realVars[61] /* Convection_wall3_outer._Gc variable */)) * ($PConduction_wall3_outer_port_a_TSeedNLSJac5);
  TRACE_POP
}

/*
 equation index: 122
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._Q_flow._$pDERNLSJac5._dummyVarNLSJac5 = -2.2681468e-07 * Radiation_wall3_outer.Gr * Conduction_wall3_outer.port_a.T ^ 3.0 * Conduction_wall3_outer_port_a_TSeedNLSJac5
 */
void OM_Result_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,122};
  modelica_real tmp32;
  tmp32 = data->localData[0]->realVars[40] /* Conduction_wall3_outer._port_a._T variable */;
  $PRadiation_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[66]) * (((tmp32 * tmp32 * tmp32)) * ($PConduction_wall3_outer_port_a_TSeedNLSJac5)));
  TRACE_POP
}

/*
 equation index: 123
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._Q_flow._$pDERNLSJac5._dummyVarNLSJac5 = Radiation_wall3_outer.Q_flow.$pDERNLSJac5.dummyVarNLSJac5 + Convection_wall3_outer.Q_flow.$pDERNLSJac5.dummyVarNLSJac5
 */
void OM_Result_eqFunction_123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,123};
  $PConduction_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5 = $PRadiation_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5 + $PConvection_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5;
  TRACE_POP
}

/*
 equation index: 124
 type: SIMPLE_ASSIGN
 Conduction_wall3_outer._dT._$pDERNLSJac5._dummyVarNLSJac5 = DIVISION(Conduction_wall3_outer.Q_flow.$pDERNLSJac5.dummyVarNLSJac5, Conduction_wall3_outer.G)
 */
void OM_Result_eqFunction_124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,124};
  $PConduction_wall3_outer$PdT$P$pDERNLSJac5$PdummyVarNLSJac5 = DIVISION_SIM($PConduction_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5,data->simulationInfo->realParameter[14],"Conduction_wall3_outer.G",equationIndexes);
  TRACE_POP
}

/*
 equation index: 125
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac5._dummyVarNLSJac5 = Conduction_wall3_outer_port_a_TSeedNLSJac5 - Conduction_wall3_outer.dT.$pDERNLSJac5.dummyVarNLSJac5
 */
void OM_Result_eqFunction_125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,125};
  $P$res$P1$P$pDERNLSJac5$PdummyVarNLSJac5 = $PConduction_wall3_outer_port_a_TSeedNLSJac5 - $PConduction_wall3_outer$PdT$P$pDERNLSJac5$PdummyVarNLSJac5;
  TRACE_POP
}
int OM_Result_functionJacNLSJac5_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac5;
  OM_Result_eqFunction_121(data, threadData);

  OM_Result_eqFunction_122(data, threadData);

  OM_Result_eqFunction_123(data, threadData);

  OM_Result_eqFunction_124(data, threadData);

  OM_Result_eqFunction_125(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 105
 type: SIMPLE_ASSIGN
 Conduction_wall4_outer._Q_flow._$pDERNLSJac4._dummyVarNLSJac4 = Conduction_wall4_outer.G * Conduction_wall4_outer_port_a_TSeedNLSJac4
 */
void OM_Result_eqFunction_105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,105};
  $PConduction_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4 = (data->simulationInfo->realParameter[16]) * ($PConduction_wall4_outer_port_a_TSeedNLSJac4);
  TRACE_POP
}

/*
 equation index: 106
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._Q_flow._$pDERNLSJac4._dummyVarNLSJac4 = -2.2681468e-07 * Radiation_wall4_outer.Gr * Conduction_wall4_outer.port_a.T ^ 3.0 * Conduction_wall4_outer_port_a_TSeedNLSJac4
 */
void OM_Result_eqFunction_106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,106};
  modelica_real tmp33;
  tmp33 = data->localData[0]->realVars[46] /* Conduction_wall4_outer._port_a._T variable */;
  $PRadiation_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4 = (-2.2681468e-07) * ((data->simulationInfo->realParameter[68]) * (((tmp33 * tmp33 * tmp33)) * ($PConduction_wall4_outer_port_a_TSeedNLSJac4)));
  TRACE_POP
}

/*
 equation index: 107
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Q_flow._$pDERNLSJac4._dummyVarNLSJac4 = Conduction_wall4_outer.Q_flow.$pDERNLSJac4.dummyVarNLSJac4 - Radiation_wall4_outer.Q_flow.$pDERNLSJac4.dummyVarNLSJac4
 */
void OM_Result_eqFunction_107(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,107};
  $PConvection_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4 = $PConduction_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4 - $PRadiation_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4;
  TRACE_POP
}

/*
 equation index: 108
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac4._dummyVarNLSJac4 = (-Convection_wall4_outer.Gc) * Conduction_wall4_outer_port_a_TSeedNLSJac4 - Convection_wall4_outer.Q_flow.$pDERNLSJac4.dummyVarNLSJac4
 */
void OM_Result_eqFunction_108(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,108};
  $P$res$P1$P$pDERNLSJac4$PdummyVarNLSJac4 = ((-data->localData[0]->realVars[66] /* Convection_wall4_outer._Gc variable */)) * ($PConduction_wall4_outer_port_a_TSeedNLSJac4) - $PConvection_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4;
  TRACE_POP
}
int OM_Result_functionJacNLSJac4_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = OM_Result_INDEX_JAC_NLSJac4;
  OM_Result_eqFunction_105(data, threadData);

  OM_Result_eqFunction_106(data, threadData);

  OM_Result_eqFunction_107(data, threadData);

  OM_Result_eqFunction_108(data, threadData);
  
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
  modelica_real tmp34;
  tmp34 = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  $PRadiation_roof_to_floor$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3 = (2.2681468e-07) * ((data->simulationInfo->realParameter[62]) * (((tmp34 * tmp34 * tmp34)) * ($PConduction_roof_inner_port_b_TSeedNLSJac3)));
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
  modelica_real tmp35;
  tmp35 = data->localData[0]->realVars[25] /* Conduction_roof_inner._port_b._T variable */;
  $PRadiation_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3 = (2.2681468e-07) * ((data->simulationInfo->realParameter[60]) * (((tmp35 * tmp35 * tmp35)) * ($PConduction_roof_inner_port_b_TSeedNLSJac3)));
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
  modelica_real tmp36;
  tmp36 = data->localData[0]->realVars[31] /* Conduction_wall1_inner._port_b._T variable */;
  $PRadiation_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2 = (2.2681468e-07) * ((data->simulationInfo->realParameter[63]) * (((tmp36 * tmp36 * tmp36)) * ($PConduction_wall1_inner_port_b_TSeedNLSJac2)));
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
  modelica_real tmp37;
  tmp37 = data->localData[0]->realVars[37] /* Conduction_wall3_inner._port_b._T variable */;
  $PRadiation_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1 = (2.2681468e-07) * ((data->simulationInfo->realParameter[65]) * (((tmp37 * tmp37 * tmp37)) * ($PConduction_wall3_inner_port_b_TSeedNLSJac1)));
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
  modelica_real tmp38;
  tmp38 = data->localData[0]->realVars[43] /* Conduction_wall4_inner._port_b._T variable */;
  $PRadiation_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0 = (2.2681468e-07) * ((data->simulationInfo->realParameter[67]) * (((tmp38 * tmp38 * tmp38)) * ($PConduction_wall4_inner_port_b_TSeedNLSJac0)));
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



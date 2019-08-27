/* Algebraic */
#include "OM_Result_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void OM_Result_eqFunction_206(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_251(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_264(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_280(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_293(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_311(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_312(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_313(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_328(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_344(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_345(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_364(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_367(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_366(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_365(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  OM_Result_eqFunction_206(data, threadData);

  OM_Result_eqFunction_251(data, threadData);

  OM_Result_eqFunction_264(data, threadData);

  OM_Result_eqFunction_280(data, threadData);

  OM_Result_eqFunction_293(data, threadData);

  OM_Result_eqFunction_311(data, threadData);

  OM_Result_eqFunction_312(data, threadData);

  OM_Result_eqFunction_313(data, threadData);

  OM_Result_eqFunction_328(data, threadData);

  OM_Result_eqFunction_344(data, threadData);

  OM_Result_eqFunction_345(data, threadData);

  OM_Result_eqFunction_364(data, threadData);

  OM_Result_eqFunction_367(data, threadData);

  OM_Result_eqFunction_366(data, threadData);

  OM_Result_eqFunction_365(data, threadData);
}
/* for continuous time variables */
int OM_Result_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  
  data->simulationInfo->callStatistics.functionAlgebraics++;
  
  functionAlg_system0(data, threadData);

  OM_Result_function_savePreSynchronous(data, threadData);
  
  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif

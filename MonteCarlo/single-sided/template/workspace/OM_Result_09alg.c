/* Algebraic */
#include "OM_Result_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void OM_Result_eqFunction_217(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_268(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_284(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_297(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_313(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_328(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_329(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_330(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_348(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_361(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_362(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_381(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_384(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_383(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_382(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  OM_Result_eqFunction_217(data, threadData);

  OM_Result_eqFunction_268(data, threadData);

  OM_Result_eqFunction_284(data, threadData);

  OM_Result_eqFunction_297(data, threadData);

  OM_Result_eqFunction_313(data, threadData);

  OM_Result_eqFunction_328(data, threadData);

  OM_Result_eqFunction_329(data, threadData);

  OM_Result_eqFunction_330(data, threadData);

  OM_Result_eqFunction_348(data, threadData);

  OM_Result_eqFunction_361(data, threadData);

  OM_Result_eqFunction_362(data, threadData);

  OM_Result_eqFunction_381(data, threadData);

  OM_Result_eqFunction_384(data, threadData);

  OM_Result_eqFunction_383(data, threadData);

  OM_Result_eqFunction_382(data, threadData);
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

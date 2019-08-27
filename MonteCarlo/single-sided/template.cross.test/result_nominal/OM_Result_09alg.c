/* Algebraic */
#include "OM_Result_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void OM_Result_eqFunction_190(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_223(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_236(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_249(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_265(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_278(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_294(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_309(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_325(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_326(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_342(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_348(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_347(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_346(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  OM_Result_eqFunction_190(data, threadData);

  OM_Result_eqFunction_223(data, threadData);

  OM_Result_eqFunction_236(data, threadData);

  OM_Result_eqFunction_249(data, threadData);

  OM_Result_eqFunction_265(data, threadData);

  OM_Result_eqFunction_278(data, threadData);

  OM_Result_eqFunction_294(data, threadData);

  OM_Result_eqFunction_309(data, threadData);

  OM_Result_eqFunction_325(data, threadData);

  OM_Result_eqFunction_326(data, threadData);

  OM_Result_eqFunction_342(data, threadData);

  OM_Result_eqFunction_348(data, threadData);

  OM_Result_eqFunction_347(data, threadData);

  OM_Result_eqFunction_346(data, threadData);
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

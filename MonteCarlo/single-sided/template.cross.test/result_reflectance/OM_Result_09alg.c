/* Algebraic */
#include "OM_Result_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void OM_Result_eqFunction_193(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_238(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_251(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_267(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_280(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_298(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_299(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_300(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_315(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_331(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_332(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_348(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_354(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_353(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_352(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  OM_Result_eqFunction_193(data, threadData);

  OM_Result_eqFunction_238(data, threadData);

  OM_Result_eqFunction_251(data, threadData);

  OM_Result_eqFunction_267(data, threadData);

  OM_Result_eqFunction_280(data, threadData);

  OM_Result_eqFunction_298(data, threadData);

  OM_Result_eqFunction_299(data, threadData);

  OM_Result_eqFunction_300(data, threadData);

  OM_Result_eqFunction_315(data, threadData);

  OM_Result_eqFunction_331(data, threadData);

  OM_Result_eqFunction_332(data, threadData);

  OM_Result_eqFunction_348(data, threadData);

  OM_Result_eqFunction_354(data, threadData);

  OM_Result_eqFunction_353(data, threadData);

  OM_Result_eqFunction_352(data, threadData);
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

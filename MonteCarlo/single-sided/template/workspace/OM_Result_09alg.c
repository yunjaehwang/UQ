/* Algebraic */
#include "OM_Result_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void OM_Result_eqFunction_222(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_275(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_288(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_304(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_317(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_335(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_336(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_337(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_352(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_368(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_369(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_385(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_391(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_390(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_389(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  OM_Result_eqFunction_222(data, threadData);

  OM_Result_eqFunction_275(data, threadData);

  OM_Result_eqFunction_288(data, threadData);

  OM_Result_eqFunction_304(data, threadData);

  OM_Result_eqFunction_317(data, threadData);

  OM_Result_eqFunction_335(data, threadData);

  OM_Result_eqFunction_336(data, threadData);

  OM_Result_eqFunction_337(data, threadData);

  OM_Result_eqFunction_352(data, threadData);

  OM_Result_eqFunction_368(data, threadData);

  OM_Result_eqFunction_369(data, threadData);

  OM_Result_eqFunction_385(data, threadData);

  OM_Result_eqFunction_391(data, threadData);

  OM_Result_eqFunction_390(data, threadData);

  OM_Result_eqFunction_389(data, threadData);
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

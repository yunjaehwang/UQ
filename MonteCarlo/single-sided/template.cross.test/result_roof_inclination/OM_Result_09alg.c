/* Algebraic */
#include "OM_Result_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void OM_Result_eqFunction_191(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_198(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_199(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_224(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_237(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_250(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_266(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_279(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_295(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_310(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_326(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_327(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_343(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_349(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_348(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_347(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  OM_Result_eqFunction_191(data, threadData);

  OM_Result_eqFunction_198(data, threadData);

  OM_Result_eqFunction_199(data, threadData);

  OM_Result_eqFunction_224(data, threadData);

  OM_Result_eqFunction_237(data, threadData);

  OM_Result_eqFunction_250(data, threadData);

  OM_Result_eqFunction_266(data, threadData);

  OM_Result_eqFunction_279(data, threadData);

  OM_Result_eqFunction_295(data, threadData);

  OM_Result_eqFunction_310(data, threadData);

  OM_Result_eqFunction_326(data, threadData);

  OM_Result_eqFunction_327(data, threadData);

  OM_Result_eqFunction_343(data, threadData);

  OM_Result_eqFunction_349(data, threadData);

  OM_Result_eqFunction_348(data, threadData);

  OM_Result_eqFunction_347(data, threadData);
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

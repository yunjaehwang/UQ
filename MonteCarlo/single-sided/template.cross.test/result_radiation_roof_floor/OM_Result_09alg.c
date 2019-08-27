/* Algebraic */
#include "OM_Result_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void OM_Result_eqFunction_194(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_201(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_202(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_239(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_252(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_268(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_281(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_299(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_300(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_301(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_316(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_332(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_333(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_349(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_355(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_354(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_353(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  OM_Result_eqFunction_194(data, threadData);

  OM_Result_eqFunction_201(data, threadData);

  OM_Result_eqFunction_202(data, threadData);

  OM_Result_eqFunction_239(data, threadData);

  OM_Result_eqFunction_252(data, threadData);

  OM_Result_eqFunction_268(data, threadData);

  OM_Result_eqFunction_281(data, threadData);

  OM_Result_eqFunction_299(data, threadData);

  OM_Result_eqFunction_300(data, threadData);

  OM_Result_eqFunction_301(data, threadData);

  OM_Result_eqFunction_316(data, threadData);

  OM_Result_eqFunction_332(data, threadData);

  OM_Result_eqFunction_333(data, threadData);

  OM_Result_eqFunction_349(data, threadData);

  OM_Result_eqFunction_355(data, threadData);

  OM_Result_eqFunction_354(data, threadData);

  OM_Result_eqFunction_353(data, threadData);
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

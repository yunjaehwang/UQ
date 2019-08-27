/* Algebraic */
#include "OM_Result_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void OM_Result_eqFunction_209(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_255(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_270(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_283(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_296(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_314(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_315(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_316(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_331(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_349(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_350(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_369(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_372(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_371(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_370(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  OM_Result_eqFunction_209(data, threadData);

  OM_Result_eqFunction_255(data, threadData);

  OM_Result_eqFunction_270(data, threadData);

  OM_Result_eqFunction_283(data, threadData);

  OM_Result_eqFunction_296(data, threadData);

  OM_Result_eqFunction_314(data, threadData);

  OM_Result_eqFunction_315(data, threadData);

  OM_Result_eqFunction_316(data, threadData);

  OM_Result_eqFunction_331(data, threadData);

  OM_Result_eqFunction_349(data, threadData);

  OM_Result_eqFunction_350(data, threadData);

  OM_Result_eqFunction_369(data, threadData);

  OM_Result_eqFunction_372(data, threadData);

  OM_Result_eqFunction_371(data, threadData);

  OM_Result_eqFunction_370(data, threadData);
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

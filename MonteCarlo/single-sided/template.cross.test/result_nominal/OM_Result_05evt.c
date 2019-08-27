/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "OM_Result_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void OM_Result_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *OM_Result_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"time >= pre(Data_wind_speed.nextTimeEvent)",
  "time >= pre(Data_outdoor_temperature.nextTimeEvent)",
  "time >= pre(Data_solar_radiation.nextTimeEvent)"};
  static const int occurEqs0[] = {1,182};
  static const int occurEqs1[] = {1,181};
  static const int occurEqs2[] = {1,180};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */

int OM_Result_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  
  TRACE_POP
  return 0;
}

int OM_Result_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  
  data->simulationInfo->callStatistics.functionZeroCrossings++;
  
  tmp0 = GreaterEqZC(data->localData[0]->timeValue, data->simulationInfo->realVarsPre[119] /* Data_wind_speed._nextTimeEvent DISCRETE */, data->simulationInfo->storedRelations[0]);
  gout[0] = (tmp0) ? 1 : -1;
  tmp1 = GreaterEqZC(data->localData[0]->timeValue, data->simulationInfo->realVarsPre[115] /* Data_outdoor_temperature._nextTimeEvent DISCRETE */, data->simulationInfo->storedRelations[1]);
  gout[1] = (tmp1) ? 1 : -1;
  tmp2 = GreaterEqZC(data->localData[0]->timeValue, data->simulationInfo->realVarsPre[117] /* Data_solar_radiation._nextTimeEvent DISCRETE */, data->simulationInfo->storedRelations[2]);
  gout[2] = (tmp2) ? 1 : -1;
  
  TRACE_POP
  return 0;
}

const char *OM_Result_relationDescription(int i)
{
  const char *res[] = {"time >= pre(Data_wind_speed.nextTimeEvent)",
  "time >= pre(Data_outdoor_temperature.nextTimeEvent)",
  "time >= pre(Data_solar_radiation.nextTimeEvent)"};
  return res[i];
}

int OM_Result_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  modelica_boolean tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  
  if(evalforZeroCross) {
    tmp3 = GreaterEqZC(data->localData[0]->timeValue, data->simulationInfo->realVarsPre[119] /* Data_wind_speed._nextTimeEvent DISCRETE */, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp3;
    tmp4 = GreaterEqZC(data->localData[0]->timeValue, data->simulationInfo->realVarsPre[115] /* Data_outdoor_temperature._nextTimeEvent DISCRETE */, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[1] = tmp4;
    tmp5 = GreaterEqZC(data->localData[0]->timeValue, data->simulationInfo->realVarsPre[117] /* Data_solar_radiation._nextTimeEvent DISCRETE */, data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[2] = tmp5;
  } else {
    data->simulationInfo->relations[0] = (data->localData[0]->timeValue >= data->simulationInfo->realVarsPre[119] /* Data_wind_speed._nextTimeEvent DISCRETE */);
    data->simulationInfo->relations[1] = (data->localData[0]->timeValue >= data->simulationInfo->realVarsPre[115] /* Data_outdoor_temperature._nextTimeEvent DISCRETE */);
    data->simulationInfo->relations[2] = (data->localData[0]->timeValue >= data->simulationInfo->realVarsPre[117] /* Data_solar_radiation._nextTimeEvent DISCRETE */);
  }
  
  TRACE_POP
  return 0;
}

int OM_Result_checkForDiscreteChanges(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int needToIterate = 0;

  infoStreamPrint(LOG_EVENTS_V, 1, "check for discrete changes at time=%.12g", data->localData[0]->timeValue);
  if(data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */ != data->simulationInfo->booleanVarsPre[2] /* $whenCondition3 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[2].info /* $whenCondition3 */.name, data->simulationInfo->booleanVarsPre[2] /* $whenCondition3 DISCRETE */, data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */ != data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[1].info /* $whenCondition2 */.name, data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */, data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ != data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[0].info /* $whenCondition1 */.name, data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */, data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->realVars[117] /* Data_solar_radiation._nextTimeEvent DISCRETE */ != data->simulationInfo->realVarsPre[117] /* Data_solar_radiation._nextTimeEvent DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %g to %g", data->modelData->realVarsData[117].info /* Data_solar_radiation._nextTimeEvent */.name, data->simulationInfo->realVarsPre[117] /* Data_solar_radiation._nextTimeEvent DISCRETE */, data->localData[0]->realVars[117] /* Data_solar_radiation._nextTimeEvent DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->realVars[118] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */ != data->simulationInfo->realVarsPre[118] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %g to %g", data->modelData->realVarsData[118].info /* Data_solar_radiation._nextTimeEventScaled */.name, data->simulationInfo->realVarsPre[118] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */, data->localData[0]->realVars[118] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->realVars[115] /* Data_outdoor_temperature._nextTimeEvent DISCRETE */ != data->simulationInfo->realVarsPre[115] /* Data_outdoor_temperature._nextTimeEvent DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %g to %g", data->modelData->realVarsData[115].info /* Data_outdoor_temperature._nextTimeEvent */.name, data->simulationInfo->realVarsPre[115] /* Data_outdoor_temperature._nextTimeEvent DISCRETE */, data->localData[0]->realVars[115] /* Data_outdoor_temperature._nextTimeEvent DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->realVars[116] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */ != data->simulationInfo->realVarsPre[116] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %g to %g", data->modelData->realVarsData[116].info /* Data_outdoor_temperature._nextTimeEventScaled */.name, data->simulationInfo->realVarsPre[116] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */, data->localData[0]->realVars[116] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->realVars[119] /* Data_wind_speed._nextTimeEvent DISCRETE */ != data->simulationInfo->realVarsPre[119] /* Data_wind_speed._nextTimeEvent DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %g to %g", data->modelData->realVarsData[119].info /* Data_wind_speed._nextTimeEvent */.name, data->simulationInfo->realVarsPre[119] /* Data_wind_speed._nextTimeEvent DISCRETE */, data->localData[0]->realVars[119] /* Data_wind_speed._nextTimeEvent DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->realVars[120] /* Data_wind_speed._nextTimeEventScaled DISCRETE */ != data->simulationInfo->realVarsPre[120] /* Data_wind_speed._nextTimeEventScaled DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %g to %g", data->modelData->realVarsData[120].info /* Data_wind_speed._nextTimeEventScaled */.name, data->simulationInfo->realVarsPre[120] /* Data_wind_speed._nextTimeEventScaled DISCRETE */, data->localData[0]->realVars[120] /* Data_wind_speed._nextTimeEventScaled DISCRETE */);
    needToIterate = 1;
  }
  if (ACTIVE_STREAM(LOG_EVENTS_V)) messageClose(LOG_EVENTS_V);
  
  TRACE_POP
  return needToIterate;
}

#if defined(__cplusplus)
}
#endif


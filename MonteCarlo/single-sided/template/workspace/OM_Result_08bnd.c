/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "OM_Result_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

int OM_Result_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating min-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* max ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating max-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* nominal **************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating nominal-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(LOG_INIT, 1, "updating primary start-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  TRACE_POP
  return 0;
}


/*
 equation index: 392
 type: SIMPLE_ASSIGN
 Data_solar_radiation._shiftTime = Data_solar_radiation.startTime
 */
void OM_Result_eqFunction_392(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,392};
  data->simulationInfo->realParameter[37] = data->simulationInfo->realParameter[38];
  TRACE_POP
}

/*
 equation index: 393
 type: SIMPLE_ASSIGN
 Data_solar_radiation._tableID = Modelica.Blocks.Types.ExternalCombiTimeTable.constructor(Data_solar_radiation.tableName, if Data_solar_radiation.fileName <> "NoName" and not Modelica.Utilities.Strings.isEmpty(Data_solar_radiation.fileName) then Data_solar_radiation.fileName else "NoName", {{}}, Data_solar_radiation.startTime / 60.0, {Data_solar_radiation.columns[1], Data_solar_radiation.columns[2]}, Modelica.Blocks.Types.Smoothness.LinearSegments, Data_solar_radiation.extrapolation, Data_solar_radiation.shiftTime / 60.0, Data_solar_radiation.timeEvents, Data_solar_radiation.verboseRead)
 */
void OM_Result_eqFunction_393(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,393};
  modelica_real tmp1;
  integer_array tmp2;
  modelica_real tmp3;
  tmp1 = 60.0;
  if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Data_solar_radiation.startTime / 60.0");}
  array_alloc_scalar_integer_array(&tmp2, 2, (modelica_integer)(modelica_integer)data->simulationInfo->integerParameter[6], (modelica_integer)(modelica_integer)data->simulationInfo->integerParameter[7]);
  tmp3 = 60.0;
  if (tmp3 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Data_solar_radiation.shiftTime / 60.0");}
  data->simulationInfo->extObjs[1] = omc_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor(threadData, data->simulationInfo->stringParameter[3], (((!stringEqual(data->simulationInfo->stringParameter[2], _OMC_LIT5)) && (!omc_Modelica_Utilities_Strings_isEmpty(threadData, data->simulationInfo->stringParameter[2])))?data->simulationInfo->stringParameter[2]:_OMC_LIT5), _OMC_LIT6, (data->simulationInfo->realParameter[38]) / tmp1, tmp2, 1, (modelica_integer)data->simulationInfo->integerParameter[8], (data->simulationInfo->realParameter[37]) / tmp3, (modelica_integer)data->simulationInfo->integerParameter[11], data->simulationInfo->booleanParameter[5]);
  TRACE_POP
}

/*
 equation index: 394
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._shiftTime = Data_outdoor_temperature.startTime
 */
void OM_Result_eqFunction_394(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,394};
  data->simulationInfo->realParameter[27] = data->simulationInfo->realParameter[28];
  TRACE_POP
}

/*
 equation index: 395
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._tableID = Modelica.Blocks.Types.ExternalCombiTimeTable.constructor(Data_outdoor_temperature.tableName, if Data_outdoor_temperature.fileName <> "NoName" and not Modelica.Utilities.Strings.isEmpty(Data_outdoor_temperature.fileName) then Data_outdoor_temperature.fileName else "NoName", {{}}, Data_outdoor_temperature.startTime / 60.0, {Data_outdoor_temperature.columns[1], Data_outdoor_temperature.columns[2]}, Modelica.Blocks.Types.Smoothness.LinearSegments, Data_outdoor_temperature.extrapolation, Data_outdoor_temperature.shiftTime / 60.0, Data_outdoor_temperature.timeEvents, Data_outdoor_temperature.verboseRead)
 */
void OM_Result_eqFunction_395(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,395};
  modelica_real tmp5;
  integer_array tmp6;
  modelica_real tmp7;
  tmp5 = 60.0;
  if (tmp5 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Data_outdoor_temperature.startTime / 60.0");}
  array_alloc_scalar_integer_array(&tmp6, 2, (modelica_integer)(modelica_integer)data->simulationInfo->integerParameter[0], (modelica_integer)(modelica_integer)data->simulationInfo->integerParameter[1]);
  tmp7 = 60.0;
  if (tmp7 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Data_outdoor_temperature.shiftTime / 60.0");}
  data->simulationInfo->extObjs[0] = omc_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor(threadData, data->simulationInfo->stringParameter[1], (((!stringEqual(data->simulationInfo->stringParameter[0], _OMC_LIT5)) && (!omc_Modelica_Utilities_Strings_isEmpty(threadData, data->simulationInfo->stringParameter[0])))?data->simulationInfo->stringParameter[0]:_OMC_LIT5), _OMC_LIT6, (data->simulationInfo->realParameter[28]) / tmp5, tmp6, 1, (modelica_integer)data->simulationInfo->integerParameter[2], (data->simulationInfo->realParameter[27]) / tmp7, (modelica_integer)data->simulationInfo->integerParameter[5], data->simulationInfo->booleanParameter[2]);
  TRACE_POP
}

/*
 equation index: 396
 type: SIMPLE_ASSIGN
 Data_wind_speed._shiftTime = Data_wind_speed.startTime
 */
void OM_Result_eqFunction_396(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,396};
  data->simulationInfo->realParameter[47] = data->simulationInfo->realParameter[48];
  TRACE_POP
}

/*
 equation index: 397
 type: SIMPLE_ASSIGN
 Data_wind_speed._tableID = Modelica.Blocks.Types.ExternalCombiTimeTable.constructor(Data_wind_speed.tableName, if Data_wind_speed.fileName <> "NoName" and not Modelica.Utilities.Strings.isEmpty(Data_wind_speed.fileName) then Data_wind_speed.fileName else "NoName", {{}}, Data_wind_speed.startTime / 60.0, {Data_wind_speed.columns[1], Data_wind_speed.columns[2]}, Modelica.Blocks.Types.Smoothness.LinearSegments, Data_wind_speed.extrapolation, Data_wind_speed.shiftTime / 60.0, Data_wind_speed.timeEvents, Data_wind_speed.verboseRead)
 */
void OM_Result_eqFunction_397(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,397};
  modelica_real tmp9;
  integer_array tmp10;
  modelica_real tmp11;
  tmp9 = 60.0;
  if (tmp9 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Data_wind_speed.startTime / 60.0");}
  array_alloc_scalar_integer_array(&tmp10, 2, (modelica_integer)(modelica_integer)data->simulationInfo->integerParameter[12], (modelica_integer)(modelica_integer)data->simulationInfo->integerParameter[13]);
  tmp11 = 60.0;
  if (tmp11 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Data_wind_speed.shiftTime / 60.0");}
  data->simulationInfo->extObjs[2] = omc_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor(threadData, data->simulationInfo->stringParameter[5], (((!stringEqual(data->simulationInfo->stringParameter[4], _OMC_LIT5)) && (!omc_Modelica_Utilities_Strings_isEmpty(threadData, data->simulationInfo->stringParameter[4])))?data->simulationInfo->stringParameter[4]:_OMC_LIT5), _OMC_LIT6, (data->simulationInfo->realParameter[48]) / tmp9, tmp10, 1, (modelica_integer)data->simulationInfo->integerParameter[14], (data->simulationInfo->realParameter[47]) / tmp11, (modelica_integer)data->simulationInfo->integerParameter[17], data->simulationInfo->booleanParameter[8]);
  TRACE_POP
}

/*
 equation index: 398
 type: SIMPLE_ASSIGN
 log1._base = 2.718281828459045
 */
void OM_Result_eqFunction_398(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,398};
  data->simulationInfo->realParameter[82] = 2.718281828459045;
  TRACE_POP
}

/*
 equation index: 399
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct5._nu = 3
 */
void OM_Result_eqFunction_399(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,399};
  data->simulationInfo->integerParameter[29] = ((modelica_integer) 3);
  TRACE_POP
}

/*
 equation index: 400
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct4._nu = 3
 */
void OM_Result_eqFunction_400(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,400};
  data->simulationInfo->integerParameter[27] = ((modelica_integer) 3);
  TRACE_POP
}

/*
 equation index: 401
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct3._nu = 3
 */
void OM_Result_eqFunction_401(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,401};
  data->simulationInfo->integerParameter[25] = ((modelica_integer) 3);
  TRACE_POP
}

/*
 equation index: 402
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum2._nu = 3
 */
void OM_Result_eqFunction_402(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,402};
  data->simulationInfo->integerParameter[33] = ((modelica_integer) 3);
  TRACE_POP
}

/*
 equation index: 403
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum1._nu = 3
 */
void OM_Result_eqFunction_403(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,403};
  data->simulationInfo->integerParameter[31] = ((modelica_integer) 3);
  TRACE_POP
}

/*
 equation index: 404
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct2._nu = 3
 */
void OM_Result_eqFunction_404(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,404};
  data->simulationInfo->integerParameter[23] = ((modelica_integer) 3);
  TRACE_POP
}

/*
 equation index: 405
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct1._nu = 3
 */
void OM_Result_eqFunction_405(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,405};
  data->simulationInfo->integerParameter[21] = ((modelica_integer) 3);
  TRACE_POP
}

/*
 equation index: 406
 type: SIMPLE_ASSIGN
 two_single_ventilation1._abs1._generateEvent = false
 */
void OM_Result_eqFunction_406(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,406};
  data->simulationInfo->booleanParameter[9] = 0;
  TRACE_POP
}

/*
 equation index: 407
 type: SIMPLE_ASSIGN
 Data_wind_speed._p_offset[2] = Data_wind_speed.offset[1]
 */
void OM_Result_eqFunction_407(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,407};
  data->simulationInfo->realParameter[46] = data->simulationInfo->realParameter[44];
  TRACE_POP
}

/*
 equation index: 408
 type: SIMPLE_ASSIGN
 Data_wind_speed._p_offset[1] = Data_wind_speed.offset[1]
 */
void OM_Result_eqFunction_408(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,408};
  data->simulationInfo->realParameter[45] = data->simulationInfo->realParameter[44];
  TRACE_POP
}

/*
 equation index: 409
 type: SIMPLE_ASSIGN
 Data_wind_speed._t_maxScaled = Modelica.Blocks.Tables.Internal.getTimeTableTmax(Data_wind_speed.tableID)
 */
void OM_Result_eqFunction_409(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,409};
  data->simulationInfo->realParameter[50] = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmax(threadData, data->simulationInfo->extObjs[2]);
  TRACE_POP
}

/*
 equation index: 410
 type: SIMPLE_ASSIGN
 Data_wind_speed._t_minScaled = Modelica.Blocks.Tables.Internal.getTimeTableTmin(Data_wind_speed.tableID)
 */
void OM_Result_eqFunction_410(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,410};
  data->simulationInfo->realParameter[52] = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmin(threadData, data->simulationInfo->extObjs[2]);
  TRACE_POP
}

/*
 equation index: 411
 type: SIMPLE_ASSIGN
 Data_wind_speed._t_max = 60.0 * Data_wind_speed.t_maxScaled
 */
void OM_Result_eqFunction_411(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,411};
  data->simulationInfo->realParameter[49] = (60.0) * (data->simulationInfo->realParameter[50]);
  TRACE_POP
}

/*
 equation index: 412
 type: SIMPLE_ASSIGN
 Data_wind_speed._t_min = 60.0 * Data_wind_speed.t_minScaled
 */
void OM_Result_eqFunction_412(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,412};
  data->simulationInfo->realParameter[51] = (60.0) * (data->simulationInfo->realParameter[52]);
  TRACE_POP
}

/*
 equation index: 413
 type: SIMPLE_ASSIGN
 Data_wind_speed._verboseExtrapolation = false
 */
void OM_Result_eqFunction_413(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,413};
  data->simulationInfo->booleanParameter[7] = 0;
  TRACE_POP
}

/*
 equation index: 414
 type: SIMPLE_ASSIGN
 Data_wind_speed._timeScale = 60.0
 */
void OM_Result_eqFunction_414(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,414};
  data->simulationInfo->realParameter[53] = 60.0;
  TRACE_POP
}

/*
 equation index: 415
 type: SIMPLE_ASSIGN
 Data_wind_speed._smoothness = Modelica.Blocks.Types.Smoothness.LinearSegments
 */
void OM_Result_eqFunction_415(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,415};
  data->simulationInfo->integerParameter[16] = 1;
  TRACE_POP
}

/*
 equation index: 416
 type: SIMPLE_ASSIGN
 Data_wind_speed._tableOnFile = true
 */
void OM_Result_eqFunction_416(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,416};
  data->simulationInfo->booleanParameter[6] = 1;
  TRACE_POP
}

/*
 equation index: 417
 type: SIMPLE_ASSIGN
 Data_wind_speed._nout = 2
 */
void OM_Result_eqFunction_417(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,417};
  data->simulationInfo->integerParameter[15] = ((modelica_integer) 2);
  TRACE_POP
}

/*
 equation index: 418
 type: SIMPLE_ASSIGN
 multiProduct1._nu = 3
 */
void OM_Result_eqFunction_418(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,418};
  data->simulationInfo->integerParameter[18] = ((modelica_integer) 3);
  TRACE_POP
}

/*
 equation index: 419
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._p_offset[2] = Data_outdoor_temperature.offset[1]
 */
void OM_Result_eqFunction_419(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,419};
  data->simulationInfo->realParameter[26] = data->simulationInfo->realParameter[24];
  TRACE_POP
}

/*
 equation index: 420
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._p_offset[1] = Data_outdoor_temperature.offset[1]
 */
void OM_Result_eqFunction_420(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,420};
  data->simulationInfo->realParameter[25] = data->simulationInfo->realParameter[24];
  TRACE_POP
}

/*
 equation index: 421
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._t_maxScaled = Modelica.Blocks.Tables.Internal.getTimeTableTmax(Data_outdoor_temperature.tableID)
 */
void OM_Result_eqFunction_421(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,421};
  data->simulationInfo->realParameter[30] = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmax(threadData, data->simulationInfo->extObjs[0]);
  TRACE_POP
}

/*
 equation index: 422
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._t_minScaled = Modelica.Blocks.Tables.Internal.getTimeTableTmin(Data_outdoor_temperature.tableID)
 */
void OM_Result_eqFunction_422(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,422};
  data->simulationInfo->realParameter[32] = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmin(threadData, data->simulationInfo->extObjs[0]);
  TRACE_POP
}

/*
 equation index: 423
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._t_max = 60.0 * Data_outdoor_temperature.t_maxScaled
 */
void OM_Result_eqFunction_423(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,423};
  data->simulationInfo->realParameter[29] = (60.0) * (data->simulationInfo->realParameter[30]);
  TRACE_POP
}

/*
 equation index: 424
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._t_min = 60.0 * Data_outdoor_temperature.t_minScaled
 */
void OM_Result_eqFunction_424(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,424};
  data->simulationInfo->realParameter[31] = (60.0) * (data->simulationInfo->realParameter[32]);
  TRACE_POP
}

/*
 equation index: 425
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._verboseExtrapolation = false
 */
void OM_Result_eqFunction_425(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,425};
  data->simulationInfo->booleanParameter[1] = 0;
  TRACE_POP
}

/*
 equation index: 426
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._timeScale = 60.0
 */
void OM_Result_eqFunction_426(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,426};
  data->simulationInfo->realParameter[33] = 60.0;
  TRACE_POP
}

/*
 equation index: 427
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._smoothness = Modelica.Blocks.Types.Smoothness.LinearSegments
 */
void OM_Result_eqFunction_427(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,427};
  data->simulationInfo->integerParameter[4] = 1;
  TRACE_POP
}

/*
 equation index: 428
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._tableOnFile = true
 */
void OM_Result_eqFunction_428(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,428};
  data->simulationInfo->booleanParameter[0] = 1;
  TRACE_POP
}

/*
 equation index: 429
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._nout = 2
 */
void OM_Result_eqFunction_429(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,429};
  data->simulationInfo->integerParameter[3] = ((modelica_integer) 2);
  TRACE_POP
}

/*
 equation index: 430
 type: SIMPLE_ASSIGN
 Data_solar_radiation._p_offset[2] = Data_solar_radiation.offset[1]
 */
void OM_Result_eqFunction_430(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,430};
  data->simulationInfo->realParameter[36] = data->simulationInfo->realParameter[34];
  TRACE_POP
}

/*
 equation index: 431
 type: SIMPLE_ASSIGN
 Data_solar_radiation._p_offset[1] = Data_solar_radiation.offset[1]
 */
void OM_Result_eqFunction_431(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,431};
  data->simulationInfo->realParameter[35] = data->simulationInfo->realParameter[34];
  TRACE_POP
}

/*
 equation index: 432
 type: SIMPLE_ASSIGN
 Data_solar_radiation._t_maxScaled = Modelica.Blocks.Tables.Internal.getTimeTableTmax(Data_solar_radiation.tableID)
 */
void OM_Result_eqFunction_432(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,432};
  data->simulationInfo->realParameter[40] = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmax(threadData, data->simulationInfo->extObjs[1]);
  TRACE_POP
}

/*
 equation index: 433
 type: SIMPLE_ASSIGN
 Data_solar_radiation._t_minScaled = Modelica.Blocks.Tables.Internal.getTimeTableTmin(Data_solar_radiation.tableID)
 */
void OM_Result_eqFunction_433(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,433};
  data->simulationInfo->realParameter[42] = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmin(threadData, data->simulationInfo->extObjs[1]);
  TRACE_POP
}

/*
 equation index: 434
 type: SIMPLE_ASSIGN
 Data_solar_radiation._t_max = 60.0 * Data_solar_radiation.t_maxScaled
 */
void OM_Result_eqFunction_434(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,434};
  data->simulationInfo->realParameter[39] = (60.0) * (data->simulationInfo->realParameter[40]);
  TRACE_POP
}

/*
 equation index: 435
 type: SIMPLE_ASSIGN
 Data_solar_radiation._t_min = 60.0 * Data_solar_radiation.t_minScaled
 */
void OM_Result_eqFunction_435(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,435};
  data->simulationInfo->realParameter[41] = (60.0) * (data->simulationInfo->realParameter[42]);
  TRACE_POP
}

/*
 equation index: 436
 type: SIMPLE_ASSIGN
 Data_solar_radiation._verboseExtrapolation = false
 */
void OM_Result_eqFunction_436(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,436};
  data->simulationInfo->booleanParameter[4] = 0;
  TRACE_POP
}

/*
 equation index: 437
 type: SIMPLE_ASSIGN
 Data_solar_radiation._timeScale = 60.0
 */
void OM_Result_eqFunction_437(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,437};
  data->simulationInfo->realParameter[43] = 60.0;
  TRACE_POP
}

/*
 equation index: 438
 type: SIMPLE_ASSIGN
 Data_solar_radiation._smoothness = Modelica.Blocks.Types.Smoothness.LinearSegments
 */
void OM_Result_eqFunction_438(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,438};
  data->simulationInfo->integerParameter[10] = 1;
  TRACE_POP
}

/*
 equation index: 439
 type: SIMPLE_ASSIGN
 Data_solar_radiation._tableOnFile = true
 */
void OM_Result_eqFunction_439(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,439};
  data->simulationInfo->booleanParameter[3] = 1;
  TRACE_POP
}

/*
 equation index: 440
 type: SIMPLE_ASSIGN
 Data_solar_radiation._nout = 2
 */
void OM_Result_eqFunction_440(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,440};
  data->simulationInfo->integerParameter[9] = ((modelica_integer) 2);
  TRACE_POP
}

/*
 equation index: 441
 type: SIMPLE_ASSIGN
 thermalCollector1._m = 12
 */
void OM_Result_eqFunction_441(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,441};
  data->simulationInfo->integerParameter[20] = ((modelica_integer) 12);
  TRACE_POP
}

/*
 equation index: 442
 type: SIMPLE_ASSIGN
 two_single_ventilation1._Indoor_temperature._port._Q_flow = 0.0
 */
void OM_Result_eqFunction_442(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,442};
  data->localData[0]->realVars[123] /* two_single_ventilation1._Indoor_temperature._port._Q_flow variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 443
 type: SIMPLE_ASSIGN
 Temperature_Indoor._port._Q_flow = 0.0
 */
void OM_Result_eqFunction_443(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,443};
  data->localData[0]->realVars[110] /* Temperature_Indoor._port._Q_flow variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 444
 type: ALGORITHM
 
   assert(Data_solar_radiation.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and Data_solar_radiation.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, "Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= Data_solar_radiation.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: " + String(Data_solar_radiation.extrapolation, "d"));
 */
void OM_Result_eqFunction_444(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,444};
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  static const MMC_DEFSTRINGLIT(tmp14,194,"Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= Data_solar_radiation.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: ");
  modelica_string tmp15;
  static int tmp16 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp16)
  {
    tmp12 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[8],1);
    tmp13 = LessEq((modelica_integer)data->simulationInfo->integerParameter[8],4);
    if(!(tmp12 && tmp13))
    {
      tmp15 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[8], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp14),tmp15);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2155,5,2157,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_solar_radiation.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and Data_solar_radiation.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp16 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 445
 type: ALGORITHM
 
   assert(Data_solar_radiation.timeEvents >= Modelica.Blocks.Types.TimeEvents.Always and Data_solar_radiation.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, "Variable violating min/max constraint: Modelica.Blocks.Types.TimeEvents.Always <= Data_solar_radiation.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, has value: " + String(Data_solar_radiation.timeEvents, "d"));
 */
void OM_Result_eqFunction_445(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,445};
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  static const MMC_DEFSTRINGLIT(tmp19,175,"Variable violating min/max constraint: Modelica.Blocks.Types.TimeEvents.Always <= Data_solar_radiation.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, has value: ");
  modelica_string tmp20;
  static int tmp21 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp21)
  {
    tmp17 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[11],1);
    tmp18 = LessEq((modelica_integer)data->simulationInfo->integerParameter[11],3);
    if(!(tmp17 && tmp18))
    {
      tmp20 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[11], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp19),tmp20);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2169,5,2171,131,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_solar_radiation.timeEvents >= Modelica.Blocks.Types.TimeEvents.Always and Data_solar_radiation.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp21 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 446
 type: ALGORITHM
 
   assert(Data_outdoor_temperature.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and Data_outdoor_temperature.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, "Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= Data_outdoor_temperature.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: " + String(Data_outdoor_temperature.extrapolation, "d"));
 */
void OM_Result_eqFunction_446(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,446};
  modelica_boolean tmp22;
  modelica_boolean tmp23;
  static const MMC_DEFSTRINGLIT(tmp24,198,"Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= Data_outdoor_temperature.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: ");
  modelica_string tmp25;
  static int tmp26 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp26)
  {
    tmp22 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[2],1);
    tmp23 = LessEq((modelica_integer)data->simulationInfo->integerParameter[2],4);
    if(!(tmp22 && tmp23))
    {
      tmp25 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[2], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp24),tmp25);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2155,5,2157,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_outdoor_temperature.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and Data_outdoor_temperature.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp26 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 447
 type: ALGORITHM
 
   assert(Data_outdoor_temperature.timeEvents >= Modelica.Blocks.Types.TimeEvents.Always and Data_outdoor_temperature.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, "Variable violating min/max constraint: Modelica.Blocks.Types.TimeEvents.Always <= Data_outdoor_temperature.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, has value: " + String(Data_outdoor_temperature.timeEvents, "d"));
 */
void OM_Result_eqFunction_447(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,447};
  modelica_boolean tmp27;
  modelica_boolean tmp28;
  static const MMC_DEFSTRINGLIT(tmp29,179,"Variable violating min/max constraint: Modelica.Blocks.Types.TimeEvents.Always <= Data_outdoor_temperature.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, has value: ");
  modelica_string tmp30;
  static int tmp31 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp31)
  {
    tmp27 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[5],1);
    tmp28 = LessEq((modelica_integer)data->simulationInfo->integerParameter[5],3);
    if(!(tmp27 && tmp28))
    {
      tmp30 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[5], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp29),tmp30);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2169,5,2171,131,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_outdoor_temperature.timeEvents >= Modelica.Blocks.Types.TimeEvents.Always and Data_outdoor_temperature.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp31 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 448
 type: ALGORITHM
 
   assert(Data_wind_speed.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and Data_wind_speed.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, "Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= Data_wind_speed.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: " + String(Data_wind_speed.extrapolation, "d"));
 */
void OM_Result_eqFunction_448(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,448};
  modelica_boolean tmp32;
  modelica_boolean tmp33;
  static const MMC_DEFSTRINGLIT(tmp34,189,"Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= Data_wind_speed.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: ");
  modelica_string tmp35;
  static int tmp36 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp36)
  {
    tmp32 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[14],1);
    tmp33 = LessEq((modelica_integer)data->simulationInfo->integerParameter[14],4);
    if(!(tmp32 && tmp33))
    {
      tmp35 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[14], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp34),tmp35);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2155,5,2157,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_wind_speed.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and Data_wind_speed.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp36 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 449
 type: ALGORITHM
 
   assert(Data_wind_speed.timeEvents >= Modelica.Blocks.Types.TimeEvents.Always and Data_wind_speed.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, "Variable violating min/max constraint: Modelica.Blocks.Types.TimeEvents.Always <= Data_wind_speed.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, has value: " + String(Data_wind_speed.timeEvents, "d"));
 */
void OM_Result_eqFunction_449(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,449};
  modelica_boolean tmp37;
  modelica_boolean tmp38;
  static const MMC_DEFSTRINGLIT(tmp39,170,"Variable violating min/max constraint: Modelica.Blocks.Types.TimeEvents.Always <= Data_wind_speed.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, has value: ");
  modelica_string tmp40;
  static int tmp41 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp41)
  {
    tmp37 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[17],1);
    tmp38 = LessEq((modelica_integer)data->simulationInfo->integerParameter[17],3);
    if(!(tmp37 && tmp38))
    {
      tmp40 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[17], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp39),tmp40);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2169,5,2171,131,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_wind_speed.timeEvents >= Modelica.Blocks.Types.TimeEvents.Always and Data_wind_speed.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp41 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 450
 type: ALGORITHM
 
   assert(two_single_ventilation1.multiProduct5.nu >= 0, "Variable violating min constraint: 0 <= two_single_ventilation1.multiProduct5.nu, has value: " + String(two_single_ventilation1.multiProduct5.nu, "d"));
 */
void OM_Result_eqFunction_450(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,450};
  modelica_boolean tmp42;
  static const MMC_DEFSTRINGLIT(tmp43,93,"Variable violating min constraint: 0 <= two_single_ventilation1.multiProduct5.nu, has value: ");
  modelica_string tmp44;
  static int tmp45 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp45)
  {
    tmp42 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[29],((modelica_integer) 0));
    if(!tmp42)
    {
      tmp44 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[29], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp43),tmp44);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",395,5,396,65,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.multiProduct5.nu >= 0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp45 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 451
 type: ALGORITHM
 
   assert(two_single_ventilation1.multiProduct5.significantDigits >= 1, "Variable violating min constraint: 1 <= two_single_ventilation1.multiProduct5.significantDigits, has value: " + String(two_single_ventilation1.multiProduct5.significantDigits, "d"));
 */
void OM_Result_eqFunction_451(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,451};
  modelica_boolean tmp46;
  static const MMC_DEFSTRINGLIT(tmp47,108,"Variable violating min constraint: 1 <= two_single_ventilation1.multiProduct5.significantDigits, has value: ");
  modelica_string tmp48;
  static int tmp49 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp49)
  {
    tmp46 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[30],((modelica_integer) 1));
    if(!tmp46)
    {
      tmp48 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[30], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp47),tmp48);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",392,5,394,42,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.multiProduct5.significantDigits >= 1", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp49 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 452
 type: ALGORITHM
 
   assert(two_single_ventilation1.Heat_flow_NV.T_ref >= 0.0, "Variable violating min constraint: 0.0 <= two_single_ventilation1.Heat_flow_NV.T_ref, has value: " + String(two_single_ventilation1.Heat_flow_NV.T_ref, "g"));
 */
void OM_Result_eqFunction_452(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,452};
  modelica_boolean tmp50;
  static const MMC_DEFSTRINGLIT(tmp51,97,"Variable violating min constraint: 0.0 <= two_single_ventilation1.Heat_flow_NV.T_ref, has value: ");
  modelica_string tmp52;
  static int tmp53 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp53)
  {
    tmp50 = GreaterEq(data->simulationInfo->realParameter[89],0.0);
    if(!tmp50)
    {
      tmp52 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[89], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp51),tmp52);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",1879,7,1880,32,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.Heat_flow_NV.T_ref >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp53 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 453
 type: ALGORITHM
 
   assert(two_single_ventilation1.multiProduct4.nu >= 0, "Variable violating min constraint: 0 <= two_single_ventilation1.multiProduct4.nu, has value: " + String(two_single_ventilation1.multiProduct4.nu, "d"));
 */
void OM_Result_eqFunction_453(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,453};
  modelica_boolean tmp54;
  static const MMC_DEFSTRINGLIT(tmp55,93,"Variable violating min constraint: 0 <= two_single_ventilation1.multiProduct4.nu, has value: ");
  modelica_string tmp56;
  static int tmp57 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp57)
  {
    tmp54 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[27],((modelica_integer) 0));
    if(!tmp54)
    {
      tmp56 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[27], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp55),tmp56);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",395,5,396,65,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.multiProduct4.nu >= 0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp57 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 454
 type: ALGORITHM
 
   assert(two_single_ventilation1.multiProduct4.significantDigits >= 1, "Variable violating min constraint: 1 <= two_single_ventilation1.multiProduct4.significantDigits, has value: " + String(two_single_ventilation1.multiProduct4.significantDigits, "d"));
 */
void OM_Result_eqFunction_454(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,454};
  modelica_boolean tmp58;
  static const MMC_DEFSTRINGLIT(tmp59,108,"Variable violating min constraint: 1 <= two_single_ventilation1.multiProduct4.significantDigits, has value: ");
  modelica_string tmp60;
  static int tmp61 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp61)
  {
    tmp58 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[28],((modelica_integer) 1));
    if(!tmp58)
    {
      tmp60 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[28], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp59),tmp60);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",392,5,394,42,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.multiProduct4.significantDigits >= 1", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp61 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 455
 type: ALGORITHM
 
   assert(two_single_ventilation1.multiProduct3.nu >= 0, "Variable violating min constraint: 0 <= two_single_ventilation1.multiProduct3.nu, has value: " + String(two_single_ventilation1.multiProduct3.nu, "d"));
 */
void OM_Result_eqFunction_455(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,455};
  modelica_boolean tmp62;
  static const MMC_DEFSTRINGLIT(tmp63,93,"Variable violating min constraint: 0 <= two_single_ventilation1.multiProduct3.nu, has value: ");
  modelica_string tmp64;
  static int tmp65 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp65)
  {
    tmp62 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[25],((modelica_integer) 0));
    if(!tmp62)
    {
      tmp64 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[25], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp63),tmp64);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",395,5,396,65,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.multiProduct3.nu >= 0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp65 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 456
 type: ALGORITHM
 
   assert(two_single_ventilation1.multiProduct3.significantDigits >= 1, "Variable violating min constraint: 1 <= two_single_ventilation1.multiProduct3.significantDigits, has value: " + String(two_single_ventilation1.multiProduct3.significantDigits, "d"));
 */
void OM_Result_eqFunction_456(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,456};
  modelica_boolean tmp66;
  static const MMC_DEFSTRINGLIT(tmp67,108,"Variable violating min constraint: 1 <= two_single_ventilation1.multiProduct3.significantDigits, has value: ");
  modelica_string tmp68;
  static int tmp69 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp69)
  {
    tmp66 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[26],((modelica_integer) 1));
    if(!tmp66)
    {
      tmp68 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[26], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp67),tmp68);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",392,5,394,42,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.multiProduct3.significantDigits >= 1", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp69 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 457
 type: ALGORITHM
 
   assert(two_single_ventilation1.multiSum2.nu >= 0, "Variable violating min constraint: 0 <= two_single_ventilation1.multiSum2.nu, has value: " + String(two_single_ventilation1.multiSum2.nu, "d"));
 */
void OM_Result_eqFunction_457(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,457};
  modelica_boolean tmp70;
  static const MMC_DEFSTRINGLIT(tmp71,89,"Variable violating min constraint: 0 <= two_single_ventilation1.multiSum2.nu, has value: ");
  modelica_string tmp72;
  static int tmp73 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp73)
  {
    tmp70 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[33],((modelica_integer) 0));
    if(!tmp70)
    {
      tmp72 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[33], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp71),tmp72);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",395,5,396,65,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.multiSum2.nu >= 0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp73 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 458
 type: ALGORITHM
 
   assert(two_single_ventilation1.multiSum2.significantDigits >= 1, "Variable violating min constraint: 1 <= two_single_ventilation1.multiSum2.significantDigits, has value: " + String(two_single_ventilation1.multiSum2.significantDigits, "d"));
 */
void OM_Result_eqFunction_458(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,458};
  modelica_boolean tmp74;
  static const MMC_DEFSTRINGLIT(tmp75,104,"Variable violating min constraint: 1 <= two_single_ventilation1.multiSum2.significantDigits, has value: ");
  modelica_string tmp76;
  static int tmp77 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp77)
  {
    tmp74 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[34],((modelica_integer) 1));
    if(!tmp74)
    {
      tmp76 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[34], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp75),tmp76);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",392,5,394,42,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.multiSum2.significantDigits >= 1", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp77 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 459
 type: ALGORITHM
 
   assert(two_single_ventilation1.multiSum1.nu >= 0, "Variable violating min constraint: 0 <= two_single_ventilation1.multiSum1.nu, has value: " + String(two_single_ventilation1.multiSum1.nu, "d"));
 */
void OM_Result_eqFunction_459(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,459};
  modelica_boolean tmp78;
  static const MMC_DEFSTRINGLIT(tmp79,89,"Variable violating min constraint: 0 <= two_single_ventilation1.multiSum1.nu, has value: ");
  modelica_string tmp80;
  static int tmp81 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp81)
  {
    tmp78 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[31],((modelica_integer) 0));
    if(!tmp78)
    {
      tmp80 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[31], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp79),tmp80);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",395,5,396,65,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.multiSum1.nu >= 0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp81 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 460
 type: ALGORITHM
 
   assert(two_single_ventilation1.multiSum1.significantDigits >= 1, "Variable violating min constraint: 1 <= two_single_ventilation1.multiSum1.significantDigits, has value: " + String(two_single_ventilation1.multiSum1.significantDigits, "d"));
 */
void OM_Result_eqFunction_460(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,460};
  modelica_boolean tmp82;
  static const MMC_DEFSTRINGLIT(tmp83,104,"Variable violating min constraint: 1 <= two_single_ventilation1.multiSum1.significantDigits, has value: ");
  modelica_string tmp84;
  static int tmp85 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp85)
  {
    tmp82 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[32],((modelica_integer) 1));
    if(!tmp82)
    {
      tmp84 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[32], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp83),tmp84);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",392,5,394,42,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.multiSum1.significantDigits >= 1", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp85 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 461
 type: ALGORITHM
 
   assert(two_single_ventilation1.multiProduct2.nu >= 0, "Variable violating min constraint: 0 <= two_single_ventilation1.multiProduct2.nu, has value: " + String(two_single_ventilation1.multiProduct2.nu, "d"));
 */
void OM_Result_eqFunction_461(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,461};
  modelica_boolean tmp86;
  static const MMC_DEFSTRINGLIT(tmp87,93,"Variable violating min constraint: 0 <= two_single_ventilation1.multiProduct2.nu, has value: ");
  modelica_string tmp88;
  static int tmp89 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp89)
  {
    tmp86 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[23],((modelica_integer) 0));
    if(!tmp86)
    {
      tmp88 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[23], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp87),tmp88);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",395,5,396,65,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.multiProduct2.nu >= 0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp89 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 462
 type: ALGORITHM
 
   assert(two_single_ventilation1.multiProduct2.significantDigits >= 1, "Variable violating min constraint: 1 <= two_single_ventilation1.multiProduct2.significantDigits, has value: " + String(two_single_ventilation1.multiProduct2.significantDigits, "d"));
 */
void OM_Result_eqFunction_462(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,462};
  modelica_boolean tmp90;
  static const MMC_DEFSTRINGLIT(tmp91,108,"Variable violating min constraint: 1 <= two_single_ventilation1.multiProduct2.significantDigits, has value: ");
  modelica_string tmp92;
  static int tmp93 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp93)
  {
    tmp90 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[24],((modelica_integer) 1));
    if(!tmp90)
    {
      tmp92 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[24], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp91),tmp92);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",392,5,394,42,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.multiProduct2.significantDigits >= 1", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp93 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 463
 type: ALGORITHM
 
   assert(two_single_ventilation1.multiProduct1.nu >= 0, "Variable violating min constraint: 0 <= two_single_ventilation1.multiProduct1.nu, has value: " + String(two_single_ventilation1.multiProduct1.nu, "d"));
 */
void OM_Result_eqFunction_463(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,463};
  modelica_boolean tmp94;
  static const MMC_DEFSTRINGLIT(tmp95,93,"Variable violating min constraint: 0 <= two_single_ventilation1.multiProduct1.nu, has value: ");
  modelica_string tmp96;
  static int tmp97 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp97)
  {
    tmp94 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[21],((modelica_integer) 0));
    if(!tmp94)
    {
      tmp96 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[21], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp95),tmp96);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",395,5,396,65,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.multiProduct1.nu >= 0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp97 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 464
 type: ALGORITHM
 
   assert(two_single_ventilation1.multiProduct1.significantDigits >= 1, "Variable violating min constraint: 1 <= two_single_ventilation1.multiProduct1.significantDigits, has value: " + String(two_single_ventilation1.multiProduct1.significantDigits, "d"));
 */
void OM_Result_eqFunction_464(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,464};
  modelica_boolean tmp98;
  static const MMC_DEFSTRINGLIT(tmp99,108,"Variable violating min constraint: 1 <= two_single_ventilation1.multiProduct1.significantDigits, has value: ");
  modelica_string tmp100;
  static int tmp101 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp101)
  {
    tmp98 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[22],((modelica_integer) 1));
    if(!tmp98)
    {
      tmp100 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[22], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp99),tmp100);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",392,5,394,42,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntwo_single_ventilation1.multiProduct1.significantDigits >= 1", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp101 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 465
 type: ALGORITHM
 
   assert(Data_wind_speed.timeScale >= 1e-15, "Variable violating min constraint: 1e-15 <= Data_wind_speed.timeScale, has value: " + String(Data_wind_speed.timeScale, "g"));
 */
void OM_Result_eqFunction_465(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,465};
  modelica_boolean tmp102;
  static const MMC_DEFSTRINGLIT(tmp103,82,"Variable violating min constraint: 1e-15 <= Data_wind_speed.timeScale, has value: ");
  modelica_string tmp104;
  static int tmp105 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp105)
  {
    tmp102 = GreaterEq(data->simulationInfo->realParameter[53],1e-15);
    if(!tmp102)
    {
      tmp104 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[53], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp103),tmp104);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2158,5,2160,76,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_wind_speed.timeScale >= 1e-15", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp105 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 466
 type: ALGORITHM
 
   assert(Data_wind_speed.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and Data_wind_speed.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, "Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= Data_wind_speed.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: " + String(Data_wind_speed.smoothness, "d"));
 */
void OM_Result_eqFunction_466(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,466};
  modelica_boolean tmp106;
  modelica_boolean tmp107;
  static const MMC_DEFSTRINGLIT(tmp108,195,"Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= Data_wind_speed.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: ");
  modelica_string tmp109;
  static int tmp110 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp110)
  {
    tmp106 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[16],1);
    tmp107 = LessEq((modelica_integer)data->simulationInfo->integerParameter[16],5);
    if(!(tmp106 && tmp107))
    {
      tmp109 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[16], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp108),tmp109);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2152,5,2154,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_wind_speed.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and Data_wind_speed.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp110 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 467
 type: ALGORITHM
 
   assert(Data_wind_speed.nout >= 1, "Variable violating min constraint: 1 <= Data_wind_speed.nout, has value: " + String(Data_wind_speed.nout, "d"));
 */
void OM_Result_eqFunction_467(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,467};
  modelica_boolean tmp111;
  static const MMC_DEFSTRINGLIT(tmp112,73,"Variable violating min constraint: 1 <= Data_wind_speed.nout, has value: ");
  modelica_string tmp113;
  static int tmp114 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp114)
  {
    tmp111 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[15],((modelica_integer) 1));
    if(!tmp111)
    {
      tmp113 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[15], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp112),tmp113);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",313,5,313,58,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_wind_speed.nout >= 1", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp114 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 468
 type: ALGORITHM
 
   assert(multiProduct1.nu >= 0, "Variable violating min constraint: 0 <= multiProduct1.nu, has value: " + String(multiProduct1.nu, "d"));
 */
void OM_Result_eqFunction_468(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,468};
  modelica_boolean tmp115;
  static const MMC_DEFSTRINGLIT(tmp116,69,"Variable violating min constraint: 0 <= multiProduct1.nu, has value: ");
  modelica_string tmp117;
  static int tmp118 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp118)
  {
    tmp115 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[18],((modelica_integer) 0));
    if(!tmp115)
    {
      tmp117 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[18], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp116),tmp117);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",395,5,396,65,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nmultiProduct1.nu >= 0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp118 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 469
 type: ALGORITHM
 
   assert(multiProduct1.significantDigits >= 1, "Variable violating min constraint: 1 <= multiProduct1.significantDigits, has value: " + String(multiProduct1.significantDigits, "d"));
 */
void OM_Result_eqFunction_469(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,469};
  modelica_boolean tmp119;
  static const MMC_DEFSTRINGLIT(tmp120,84,"Variable violating min constraint: 1 <= multiProduct1.significantDigits, has value: ");
  modelica_string tmp121;
  static int tmp122 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp122)
  {
    tmp119 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[19],((modelica_integer) 1));
    if(!tmp119)
    {
      tmp121 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[19], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp120),tmp121);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",392,5,394,42,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nmultiProduct1.significantDigits >= 1", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp122 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 470
 type: ALGORITHM
 
   assert(Data_outdoor_temperature.timeScale >= 1e-15, "Variable violating min constraint: 1e-15 <= Data_outdoor_temperature.timeScale, has value: " + String(Data_outdoor_temperature.timeScale, "g"));
 */
void OM_Result_eqFunction_470(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,470};
  modelica_boolean tmp123;
  static const MMC_DEFSTRINGLIT(tmp124,91,"Variable violating min constraint: 1e-15 <= Data_outdoor_temperature.timeScale, has value: ");
  modelica_string tmp125;
  static int tmp126 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp126)
  {
    tmp123 = GreaterEq(data->simulationInfo->realParameter[33],1e-15);
    if(!tmp123)
    {
      tmp125 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[33], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp124),tmp125);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2158,5,2160,76,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_outdoor_temperature.timeScale >= 1e-15", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp126 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 471
 type: ALGORITHM
 
   assert(Data_outdoor_temperature.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and Data_outdoor_temperature.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, "Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= Data_outdoor_temperature.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: " + String(Data_outdoor_temperature.smoothness, "d"));
 */
void OM_Result_eqFunction_471(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,471};
  modelica_boolean tmp127;
  modelica_boolean tmp128;
  static const MMC_DEFSTRINGLIT(tmp129,204,"Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= Data_outdoor_temperature.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: ");
  modelica_string tmp130;
  static int tmp131 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp131)
  {
    tmp127 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[4],1);
    tmp128 = LessEq((modelica_integer)data->simulationInfo->integerParameter[4],5);
    if(!(tmp127 && tmp128))
    {
      tmp130 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[4], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp129),tmp130);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2152,5,2154,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_outdoor_temperature.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and Data_outdoor_temperature.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp131 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 472
 type: ALGORITHM
 
   assert(Data_outdoor_temperature.nout >= 1, "Variable violating min constraint: 1 <= Data_outdoor_temperature.nout, has value: " + String(Data_outdoor_temperature.nout, "d"));
 */
void OM_Result_eqFunction_472(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,472};
  modelica_boolean tmp132;
  static const MMC_DEFSTRINGLIT(tmp133,82,"Variable violating min constraint: 1 <= Data_outdoor_temperature.nout, has value: ");
  modelica_string tmp134;
  static int tmp135 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp135)
  {
    tmp132 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[3],((modelica_integer) 1));
    if(!tmp132)
    {
      tmp134 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[3], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp133),tmp134);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",313,5,313,58,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_outdoor_temperature.nout >= 1", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp135 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 473
 type: ALGORITHM
 
   assert(Data_solar_radiation.timeScale >= 1e-15, "Variable violating min constraint: 1e-15 <= Data_solar_radiation.timeScale, has value: " + String(Data_solar_radiation.timeScale, "g"));
 */
void OM_Result_eqFunction_473(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,473};
  modelica_boolean tmp136;
  static const MMC_DEFSTRINGLIT(tmp137,87,"Variable violating min constraint: 1e-15 <= Data_solar_radiation.timeScale, has value: ");
  modelica_string tmp138;
  static int tmp139 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp139)
  {
    tmp136 = GreaterEq(data->simulationInfo->realParameter[43],1e-15);
    if(!tmp136)
    {
      tmp138 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[43], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp137),tmp138);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2158,5,2160,76,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_solar_radiation.timeScale >= 1e-15", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp139 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 474
 type: ALGORITHM
 
   assert(Data_solar_radiation.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and Data_solar_radiation.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, "Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= Data_solar_radiation.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: " + String(Data_solar_radiation.smoothness, "d"));
 */
void OM_Result_eqFunction_474(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,474};
  modelica_boolean tmp140;
  modelica_boolean tmp141;
  static const MMC_DEFSTRINGLIT(tmp142,200,"Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= Data_solar_radiation.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: ");
  modelica_string tmp143;
  static int tmp144 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp144)
  {
    tmp140 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[10],1);
    tmp141 = LessEq((modelica_integer)data->simulationInfo->integerParameter[10],5);
    if(!(tmp140 && tmp141))
    {
      tmp143 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[10], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp142),tmp143);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2152,5,2154,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_solar_radiation.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and Data_solar_radiation.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp144 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 475
 type: ALGORITHM
 
   assert(Data_solar_radiation.nout >= 1, "Variable violating min constraint: 1 <= Data_solar_radiation.nout, has value: " + String(Data_solar_radiation.nout, "d"));
 */
void OM_Result_eqFunction_475(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,475};
  modelica_boolean tmp145;
  static const MMC_DEFSTRINGLIT(tmp146,78,"Variable violating min constraint: 1 <= Data_solar_radiation.nout, has value: ");
  modelica_string tmp147;
  static int tmp148 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp148)
  {
    tmp145 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[9],((modelica_integer) 1));
    if(!tmp145)
    {
      tmp147 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[9], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp146),tmp147);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",313,5,313,58,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_solar_radiation.nout >= 1", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp148 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 476
 type: ALGORITHM
 
   assert(Heatflow_infiltration.T_ref >= 0.0, "Variable violating min constraint: 0.0 <= Heatflow_infiltration.T_ref, has value: " + String(Heatflow_infiltration.T_ref, "g"));
 */
void OM_Result_eqFunction_476(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,476};
  modelica_boolean tmp149;
  static const MMC_DEFSTRINGLIT(tmp150,82,"Variable violating min constraint: 0.0 <= Heatflow_infiltration.T_ref, has value: ");
  modelica_string tmp151;
  static int tmp152 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp152)
  {
    tmp149 = GreaterEq(data->simulationInfo->realParameter[58],0.0);
    if(!tmp149)
    {
      tmp151 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[58], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp150),tmp151);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",1879,7,1880,32,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nHeatflow_infiltration.T_ref >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp152 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 477
 type: ALGORITHM
 
   assert(Heatflow_solar_radiation.T_ref >= 0.0, "Variable violating min constraint: 0.0 <= Heatflow_solar_radiation.T_ref, has value: " + String(Heatflow_solar_radiation.T_ref, "g"));
 */
void OM_Result_eqFunction_477(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,477};
  modelica_boolean tmp153;
  static const MMC_DEFSTRINGLIT(tmp154,85,"Variable violating min constraint: 0.0 <= Heatflow_solar_radiation.T_ref, has value: ");
  modelica_string tmp155;
  static int tmp156 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp156)
  {
    tmp153 = GreaterEq(data->simulationInfo->realParameter[60],0.0);
    if(!tmp153)
    {
      tmp155 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[60], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp154),tmp155);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",1879,7,1880,32,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nHeatflow_solar_radiation.T_ref >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp156 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 478
 type: ALGORITHM
 
   assert(thermalCollector1.m >= 1, "Variable violating min constraint: 1 <= thermalCollector1.m, has value: " + String(thermalCollector1.m, "d"));
 */
void OM_Result_eqFunction_478(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,478};
  modelica_boolean tmp157;
  static const MMC_DEFSTRINGLIT(tmp158,72,"Variable violating min constraint: 1 <= thermalCollector1.m, has value: ");
  modelica_string tmp159;
  static int tmp160 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp160)
  {
    tmp157 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[20],((modelica_integer) 1));
    if(!tmp157)
    {
      tmp159 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[20], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp158),tmp159);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",1202,7,1202,68,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nthermalCollector1.m >= 1", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp160 = 1;
    }
  }
  TRACE_POP
}
int OM_Result_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  OM_Result_eqFunction_392(data, threadData);

  OM_Result_eqFunction_393(data, threadData);

  OM_Result_eqFunction_394(data, threadData);

  OM_Result_eqFunction_395(data, threadData);

  OM_Result_eqFunction_396(data, threadData);

  OM_Result_eqFunction_397(data, threadData);

  OM_Result_eqFunction_398(data, threadData);

  OM_Result_eqFunction_399(data, threadData);

  OM_Result_eqFunction_400(data, threadData);

  OM_Result_eqFunction_401(data, threadData);

  OM_Result_eqFunction_402(data, threadData);

  OM_Result_eqFunction_403(data, threadData);

  OM_Result_eqFunction_404(data, threadData);

  OM_Result_eqFunction_405(data, threadData);

  OM_Result_eqFunction_406(data, threadData);

  OM_Result_eqFunction_407(data, threadData);

  OM_Result_eqFunction_408(data, threadData);

  OM_Result_eqFunction_409(data, threadData);

  OM_Result_eqFunction_410(data, threadData);

  OM_Result_eqFunction_411(data, threadData);

  OM_Result_eqFunction_412(data, threadData);

  OM_Result_eqFunction_413(data, threadData);

  OM_Result_eqFunction_414(data, threadData);

  OM_Result_eqFunction_415(data, threadData);

  OM_Result_eqFunction_416(data, threadData);

  OM_Result_eqFunction_417(data, threadData);

  OM_Result_eqFunction_418(data, threadData);

  OM_Result_eqFunction_419(data, threadData);

  OM_Result_eqFunction_420(data, threadData);

  OM_Result_eqFunction_421(data, threadData);

  OM_Result_eqFunction_422(data, threadData);

  OM_Result_eqFunction_423(data, threadData);

  OM_Result_eqFunction_424(data, threadData);

  OM_Result_eqFunction_425(data, threadData);

  OM_Result_eqFunction_426(data, threadData);

  OM_Result_eqFunction_427(data, threadData);

  OM_Result_eqFunction_428(data, threadData);

  OM_Result_eqFunction_429(data, threadData);

  OM_Result_eqFunction_430(data, threadData);

  OM_Result_eqFunction_431(data, threadData);

  OM_Result_eqFunction_432(data, threadData);

  OM_Result_eqFunction_433(data, threadData);

  OM_Result_eqFunction_434(data, threadData);

  OM_Result_eqFunction_435(data, threadData);

  OM_Result_eqFunction_436(data, threadData);

  OM_Result_eqFunction_437(data, threadData);

  OM_Result_eqFunction_438(data, threadData);

  OM_Result_eqFunction_439(data, threadData);

  OM_Result_eqFunction_440(data, threadData);

  OM_Result_eqFunction_441(data, threadData);

  OM_Result_eqFunction_442(data, threadData);

  OM_Result_eqFunction_443(data, threadData);

  OM_Result_eqFunction_444(data, threadData);

  OM_Result_eqFunction_445(data, threadData);

  OM_Result_eqFunction_446(data, threadData);

  OM_Result_eqFunction_447(data, threadData);

  OM_Result_eqFunction_448(data, threadData);

  OM_Result_eqFunction_449(data, threadData);

  OM_Result_eqFunction_450(data, threadData);

  OM_Result_eqFunction_451(data, threadData);

  OM_Result_eqFunction_452(data, threadData);

  OM_Result_eqFunction_453(data, threadData);

  OM_Result_eqFunction_454(data, threadData);

  OM_Result_eqFunction_455(data, threadData);

  OM_Result_eqFunction_456(data, threadData);

  OM_Result_eqFunction_457(data, threadData);

  OM_Result_eqFunction_458(data, threadData);

  OM_Result_eqFunction_459(data, threadData);

  OM_Result_eqFunction_460(data, threadData);

  OM_Result_eqFunction_461(data, threadData);

  OM_Result_eqFunction_462(data, threadData);

  OM_Result_eqFunction_463(data, threadData);

  OM_Result_eqFunction_464(data, threadData);

  OM_Result_eqFunction_465(data, threadData);

  OM_Result_eqFunction_466(data, threadData);

  OM_Result_eqFunction_467(data, threadData);

  OM_Result_eqFunction_468(data, threadData);

  OM_Result_eqFunction_469(data, threadData);

  OM_Result_eqFunction_470(data, threadData);

  OM_Result_eqFunction_471(data, threadData);

  OM_Result_eqFunction_472(data, threadData);

  OM_Result_eqFunction_473(data, threadData);

  OM_Result_eqFunction_474(data, threadData);

  OM_Result_eqFunction_475(data, threadData);

  OM_Result_eqFunction_476(data, threadData);

  OM_Result_eqFunction_477(data, threadData);

  OM_Result_eqFunction_478(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif


/* Main Simulation File */
#include "OM_Result_model.h"

#define prefixedName_performSimulation OM_Result_performSimulation
#define prefixedName_updateContinuousSystem OM_Result_updateContinuousSystem
#include <simulation/solver/perform_simulation.c>

#define prefixedName_performQSSSimulation OM_Result_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c>

/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;
#if defined(__cplusplus)
extern "C" {
#endif

int OM_Result_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int OM_Result_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int OM_Result_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int OM_Result_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int OM_Result_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
 equation index: 200
 type: SIMPLE_ASSIGN
 $whenCondition3 = time >= pre(Data_solar_radiation.nextTimeEvent)
 */
void OM_Result_eqFunction_200(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,200};
  modelica_boolean tmp0;
  RELATIONHYSTERESIS(tmp0, data->localData[0]->timeValue, data->simulationInfo->realVarsPre[139] /* Data_solar_radiation._nextTimeEvent DISCRETE */, 2, GreaterEq);
  data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */ = tmp0;
  TRACE_POP
}
/*
 equation index: 201
 type: SIMPLE_ASSIGN
 $whenCondition2 = time >= pre(Data_outdoor_temperature.nextTimeEvent)
 */
void OM_Result_eqFunction_201(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,201};
  modelica_boolean tmp1;
  RELATIONHYSTERESIS(tmp1, data->localData[0]->timeValue, data->simulationInfo->realVarsPre[137] /* Data_outdoor_temperature._nextTimeEvent DISCRETE */, 1, GreaterEq);
  data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */ = tmp1;
  TRACE_POP
}
/*
 equation index: 202
 type: SIMPLE_ASSIGN
 $whenCondition1 = time >= pre(Data_wind_speed.nextTimeEvent)
 */
void OM_Result_eqFunction_202(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,202};
  modelica_boolean tmp2;
  RELATIONHYSTERESIS(tmp2, data->localData[0]->timeValue, data->simulationInfo->realVarsPre[141] /* Data_wind_speed._nextTimeEvent DISCRETE */, 0, GreaterEq);
  data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ = tmp2;
  TRACE_POP
}
/*
 equation index: 203
 type: SIMPLE_ASSIGN
 Data_wind_speed._timeScaled = 0.01666666666666667 * time
 */
void OM_Result_eqFunction_203(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,203};
  data->localData[0]->realVars[78] /* Data_wind_speed._timeScaled variable */ = (0.01666666666666667) * (data->localData[0]->timeValue);
  TRACE_POP
}
/*
 equation index: 204
 type: WHEN
 
 when {$whenCondition1} then
   Data_wind_speed._nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Data_wind_speed.tableID, Data_wind_speed.timeScaled);
 end when;
 */
void OM_Result_eqFunction_204(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,204};
  if((data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ && !data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[142] /* Data_wind_speed._nextTimeEventScaled DISCRETE */ = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, data->simulationInfo->extObjs[2], data->localData[0]->realVars[78] /* Data_wind_speed._timeScaled variable */);
  }
  TRACE_POP
}
/*
 equation index: 205
 type: WHEN
 
 when {$whenCondition1} then
   Data_wind_speed._nextTimeEvent = if Data_wind_speed.nextTimeEventScaled < 9.999999999999999e+59 then Data_wind_speed.nextTimeEventScaled * 60.0 else 9.999999999999999e+59;
 end when;
 */
void OM_Result_eqFunction_205(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,205};
  modelica_boolean tmp3;
  if((data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ && !data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */ /* edge */))
  {
    tmp3 = Less(data->localData[0]->realVars[142] /* Data_wind_speed._nextTimeEventScaled DISCRETE */,9.999999999999999e+59);
    data->localData[0]->realVars[141] /* Data_wind_speed._nextTimeEvent DISCRETE */ = (tmp3?(data->localData[0]->realVars[142] /* Data_wind_speed._nextTimeEventScaled DISCRETE */) * (60.0):9.999999999999999e+59);
  }
  TRACE_POP
}
/*
 equation index: 206
 type: SIMPLE_ASSIGN
 $cse6 = Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_wind_speed.tableID, 2, Data_wind_speed.timeScaled, Data_wind_speed.nextTimeEventScaled, pre(Data_wind_speed.nextTimeEventScaled))
 */
void OM_Result_eqFunction_206(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,206};
  data->localData[0]->realVars[15] /* $cse6 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[2], ((modelica_integer) 2), data->localData[0]->realVars[78] /* Data_wind_speed._timeScaled variable */, data->localData[0]->realVars[142] /* Data_wind_speed._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[142] /* Data_wind_speed._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
 equation index: 207
 type: SIMPLE_ASSIGN
 Data_wind_speed._y[2] = Data_wind_speed.p_offset[2] + $cse6
 */
void OM_Result_eqFunction_207(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,207};
  data->localData[0]->realVars[80] /* Data_wind_speed._y[2] variable */ = data->simulationInfo->realParameter[46] + data->localData[0]->realVars[15] /* $cse6 variable */;
  TRACE_POP
}
/*
 equation index: 208
 type: SIMPLE_ASSIGN
 StdWindSpeed._y = FactorStdWindSpeed.k * Data_wind_speed.y[2]
 */
void OM_Result_eqFunction_208(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,208};
  data->localData[0]->realVars[109] /* StdWindSpeed._y variable */ = (data->simulationInfo->realParameter[56]) * (data->localData[0]->realVars[80] /* Data_wind_speed._y[2] variable */);
  TRACE_POP
}
/*
 equation index: 209
 type: SIMPLE_ASSIGN
 $cse5 = Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_wind_speed.tableID, 1, Data_wind_speed.timeScaled, Data_wind_speed.nextTimeEventScaled, pre(Data_wind_speed.nextTimeEventScaled))
 */
void OM_Result_eqFunction_209(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,209};
  data->localData[0]->realVars[14] /* $cse5 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[2], ((modelica_integer) 1), data->localData[0]->realVars[78] /* Data_wind_speed._timeScaled variable */, data->localData[0]->realVars[142] /* Data_wind_speed._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[142] /* Data_wind_speed._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
 equation index: 210
 type: SIMPLE_ASSIGN
 Data_wind_speed._y[1] = Data_wind_speed.p_offset[1] + $cse5
 */
void OM_Result_eqFunction_210(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,210};
  data->localData[0]->realVars[79] /* Data_wind_speed._y[1] variable */ = data->simulationInfo->realParameter[45] + data->localData[0]->realVars[14] /* $cse5 variable */;
  TRACE_POP
}
/*
 equation index: 211
 type: SIMPLE_ASSIGN
 WindSpeed._y = WindSpeed.k1 * StdWindSpeed.y + WindSpeed.k2 * Data_wind_speed.y[1]
 */
void OM_Result_eqFunction_211(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,211};
  data->localData[0]->realVars[113] /* WindSpeed._y variable */ = (data->simulationInfo->realParameter[79]) * (data->localData[0]->realVars[109] /* StdWindSpeed._y variable */) + (data->simulationInfo->realParameter[80]) * (data->localData[0]->realVars[79] /* Data_wind_speed._y[1] variable */);
  TRACE_POP
}
/*
 equation index: 212
 type: SIMPLE_ASSIGN
 two_single_ventilation1._U_square._y = WindSpeed.y ^ 2.0
 */
void OM_Result_eqFunction_212(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,212};
  modelica_real tmp4;
  tmp4 = data->localData[0]->realVars[113] /* WindSpeed._y variable */;
  data->localData[0]->realVars[124] /* two_single_ventilation1._U_square._y variable */ = (tmp4 * tmp4);
  TRACE_POP
}
/*
 equation index: 213
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum1._u[1] = two_single_ventilation1.C1.k * two_single_ventilation1.U_square.y
 */
void OM_Result_eqFunction_213(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,213};
  data->localData[0]->realVars[132] /* two_single_ventilation1._multiSum1._u[1] variable */ = (data->simulationInfo->realParameter[86]) * (data->localData[0]->realVars[124] /* two_single_ventilation1._U_square._y variable */);
  TRACE_POP
}
/*
 equation index: 214
 type: SIMPLE_ASSIGN
 log1._y = log(WindSpeed.y)
 */
void OM_Result_eqFunction_214(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,214};
  modelica_real tmp5;
  tmp5 = data->localData[0]->realVars[113] /* WindSpeed._y variable */;
  if(!(tmp5 > 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of log(WindSpeed.y) was %g should be > 0", tmp5);
  }
  data->localData[0]->realVars[116] /* log1._y variable */ = log(tmp5);
  TRACE_POP
}
/*
 equation index: 215
 type: SIMPLE_ASSIGN
 exp1._u = log1.y * Convection_B.k
 */
void OM_Result_eqFunction_215(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,215};
  data->localData[0]->realVars[114] /* exp1._u variable */ = (data->localData[0]->realVars[116] /* log1._y variable */) * (data->simulationInfo->realParameter[18]);
  TRACE_POP
}
/*
 equation index: 216
 type: SIMPLE_ASSIGN
 exp1._y = exp(exp1.u)
 */
void OM_Result_eqFunction_216(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,216};
  data->localData[0]->realVars[115] /* exp1._y variable */ = exp(data->localData[0]->realVars[114] /* exp1._u variable */);
  TRACE_POP
}
/*
 equation index: 217
 type: SIMPLE_ASSIGN
 product4._y = exp1.y * Convection_A.k
 */
void OM_Result_eqFunction_217(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,217};
  data->localData[0]->realVars[119] /* product4._y variable */ = (data->localData[0]->realVars[115] /* exp1._y variable */) * (data->simulationInfo->realParameter[17]);
  TRACE_POP
}
/*
 equation index: 218
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Gc = Area_roof.k * product4.y
 */
void OM_Result_eqFunction_218(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,218};
  data->localData[0]->realVars[54] /* Convection_roof_outer._Gc variable */ = (data->simulationInfo->realParameter[0]) * (data->localData[0]->realVars[119] /* product4._y variable */);
  TRACE_POP
}
/*
 equation index: 219
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Gc = Area_wall1.k * product4.y
 */
void OM_Result_eqFunction_219(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,219};
  data->localData[0]->realVars[59] /* Convection_wall1_outer._Gc variable */ = (data->simulationInfo->realParameter[1]) * (data->localData[0]->realVars[119] /* product4._y variable */);
  TRACE_POP
}
/*
 equation index: 220
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Gc = Area_wall3.k * product4.y
 */
void OM_Result_eqFunction_220(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,220};
  data->localData[0]->realVars[64] /* Convection_wall3_outer._Gc variable */ = (data->simulationInfo->realParameter[2]) * (data->localData[0]->realVars[119] /* product4._y variable */);
  TRACE_POP
}
/*
 equation index: 221
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Gc = Area_wall4.k * product4.y
 */
void OM_Result_eqFunction_221(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,221};
  data->localData[0]->realVars[69] /* Convection_wall4_outer._Gc variable */ = (data->simulationInfo->realParameter[3]) * (data->localData[0]->realVars[119] /* product4._y variable */);
  TRACE_POP
}
/*
 equation index: 222
 type: SIMPLE_ASSIGN
 Radiation_floor._dT = Floor_temperature.k - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_222(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,222};
  data->localData[0]->realVars[87] /* Radiation_floor._dT variable */ = data->simulationInfo->realParameter[57] - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 223
 type: SIMPLE_ASSIGN
 Radiation_floor._Q_flow = 5.670367e-08 * Radiation_floor.Gr * (Floor_temperature.k ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_223(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,223};
  modelica_real tmp6;
  modelica_real tmp7;
  tmp6 = data->simulationInfo->realParameter[57];
  tmp6 *= tmp6;tmp7 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp7 *= tmp7;
  data->localData[0]->realVars[86] /* Radiation_floor._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[65]) * ((tmp6 * tmp6) - ((tmp7 * tmp7))));
  TRACE_POP
}
/*
 equation index: 224
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._timeScaled = 0.01666666666666667 * time
 */
void OM_Result_eqFunction_224(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,224};
  data->localData[0]->realVars[72] /* Data_outdoor_temperature._timeScaled variable */ = (0.01666666666666667) * (data->localData[0]->timeValue);
  TRACE_POP
}
/*
 equation index: 225
 type: WHEN
 
 when {$whenCondition2} then
   Data_outdoor_temperature._nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Data_outdoor_temperature.tableID, Data_outdoor_temperature.timeScaled);
 end when;
 */
void OM_Result_eqFunction_225(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,225};
  if((data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */ && !data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[138] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */ = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, data->simulationInfo->extObjs[0], data->localData[0]->realVars[72] /* Data_outdoor_temperature._timeScaled variable */);
  }
  TRACE_POP
}
/*
 equation index: 226
 type: WHEN
 
 when {$whenCondition2} then
   Data_outdoor_temperature._nextTimeEvent = if Data_outdoor_temperature.nextTimeEventScaled < 9.999999999999999e+59 then Data_outdoor_temperature.nextTimeEventScaled * 60.0 else 9.999999999999999e+59;
 end when;
 */
void OM_Result_eqFunction_226(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,226};
  modelica_boolean tmp8;
  if((data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */ && !data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */ /* edge */))
  {
    tmp8 = Less(data->localData[0]->realVars[138] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */,9.999999999999999e+59);
    data->localData[0]->realVars[137] /* Data_outdoor_temperature._nextTimeEvent DISCRETE */ = (tmp8?(data->localData[0]->realVars[138] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */) * (60.0):9.999999999999999e+59);
  }
  TRACE_POP
}
/*
 equation index: 227
 type: SIMPLE_ASSIGN
 $cse4 = Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_outdoor_temperature.tableID, 2, Data_outdoor_temperature.timeScaled, Data_outdoor_temperature.nextTimeEventScaled, pre(Data_outdoor_temperature.nextTimeEventScaled))
 */
void OM_Result_eqFunction_227(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,227};
  data->localData[0]->realVars[13] /* $cse4 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 2), data->localData[0]->realVars[72] /* Data_outdoor_temperature._timeScaled variable */, data->localData[0]->realVars[138] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[138] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
 equation index: 228
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._y[2] = Data_outdoor_temperature.p_offset[2] + $cse4
 */
void OM_Result_eqFunction_228(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,228};
  data->localData[0]->realVars[74] /* Data_outdoor_temperature._y[2] variable */ = data->simulationInfo->realParameter[26] + data->localData[0]->realVars[13] /* $cse4 variable */;
  TRACE_POP
}
/*
 equation index: 229
 type: SIMPLE_ASSIGN
 OutdoorTemperature._u1 = FactorStdTemperature.k * Data_outdoor_temperature.y[2]
 */
void OM_Result_eqFunction_229(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,229};
  data->localData[0]->realVars[84] /* OutdoorTemperature._u1 variable */ = (data->simulationInfo->realParameter[55]) * (data->localData[0]->realVars[74] /* Data_outdoor_temperature._y[2] variable */);
  TRACE_POP
}
/*
 equation index: 230
 type: SIMPLE_ASSIGN
 $cse3 = Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_outdoor_temperature.tableID, 1, Data_outdoor_temperature.timeScaled, Data_outdoor_temperature.nextTimeEventScaled, pre(Data_outdoor_temperature.nextTimeEventScaled))
 */
void OM_Result_eqFunction_230(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,230};
  data->localData[0]->realVars[12] /* $cse3 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 1), data->localData[0]->realVars[72] /* Data_outdoor_temperature._timeScaled variable */, data->localData[0]->realVars[138] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[138] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
 equation index: 231
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._y[1] = Data_outdoor_temperature.p_offset[1] + $cse3
 */
void OM_Result_eqFunction_231(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,231};
  data->localData[0]->realVars[73] /* Data_outdoor_temperature._y[1] variable */ = data->simulationInfo->realParameter[25] + data->localData[0]->realVars[12] /* $cse3 variable */;
  TRACE_POP
}
/*
 equation index: 232
 type: SIMPLE_ASSIGN
 multiProduct1._u[3] = OutdoorTemperature.k1 * OutdoorTemperature.u1 + OutdoorTemperature.k2 * Data_outdoor_temperature.y[1]
 */
void OM_Result_eqFunction_232(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,232};
  data->localData[0]->realVars[118] /* multiProduct1._u[3] variable */ = (data->simulationInfo->realParameter[63]) * (data->localData[0]->realVars[84] /* OutdoorTemperature._u1 variable */) + (data->simulationInfo->realParameter[64]) * (data->localData[0]->realVars[73] /* Data_outdoor_temperature._y[1] variable */);
  TRACE_POP
}
/*
 equation index: 233
 type: SIMPLE_ASSIGN
 multiProduct1._u[2] = sqrt(multiProduct1.u[3])
 */
void OM_Result_eqFunction_233(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,233};
  modelica_real tmp9;
  tmp9 = data->localData[0]->realVars[118] /* multiProduct1._u[3] variable */;
  if(!(tmp9 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(multiProduct1.u[3]) was %g should be >= 0", tmp9);
  }
  data->localData[0]->realVars[117] /* multiProduct1._u[2] variable */ = sqrt(tmp9);
  TRACE_POP
}
/*
 equation index: 234
 type: SIMPLE_ASSIGN
 SkyTemperatureToK._T = const.k * multiProduct1.u[2] * multiProduct1.u[3]
 */
void OM_Result_eqFunction_234(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,234};
  data->localData[0]->realVars[106] /* SkyTemperatureToK._T variable */ = (data->simulationInfo->realParameter[81]) * ((data->localData[0]->realVars[117] /* multiProduct1._u[2] variable */) * (data->localData[0]->realVars[118] /* multiProduct1._u[3] variable */));
  TRACE_POP
}
/*
 equation index: 235
 type: SIMPLE_ASSIGN
 Temperature_difference._y = Temperature_difference.k1 * multiProduct1.u[3] + Temperature_difference.k2 * Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_235(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,235};
  data->localData[0]->realVars[111] /* Temperature_difference._y variable */ = (data->simulationInfo->realParameter[77]) * (data->localData[0]->realVars[118] /* multiProduct1._u[3] variable */) + (data->simulationInfo->realParameter[78]) * (data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */);
  TRACE_POP
}
/*
 equation index: 236
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct5._u[3] = two_single_ventilation1.add1.k1 * multiProduct1.u[3] + two_single_ventilation1.add1.k2 * Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_236(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,236};
  data->localData[0]->realVars[131] /* two_single_ventilation1._multiProduct5._u[3] variable */ = (data->simulationInfo->realParameter[96]) * (data->localData[0]->realVars[118] /* multiProduct1._u[3] variable */) + (data->simulationInfo->realParameter[97]) * (data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */);
  TRACE_POP
}
/*
 equation index: 237
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct1._u[3] = if noEvent(two_single_ventilation1.multiProduct5.u[3] >= 0.0) then two_single_ventilation1.multiProduct5.u[3] else -two_single_ventilation1.multiProduct5.u[3]
 */
void OM_Result_eqFunction_237(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,237};
  modelica_boolean tmp10;
  tmp10 = GreaterEq(data->localData[0]->realVars[131] /* two_single_ventilation1._multiProduct5._u[3] variable */,0.0);
  data->localData[0]->realVars[127] /* two_single_ventilation1._multiProduct1._u[3] variable */ = (tmp10?data->localData[0]->realVars[131] /* two_single_ventilation1._multiProduct5._u[3] variable */:(-data->localData[0]->realVars[131] /* two_single_ventilation1._multiProduct5._u[3] variable */));
  TRACE_POP
}
/*
 equation index: 238
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum1._u[2] = two_single_ventilation1.C2.k * two_single_ventilation1.Height_1.k * two_single_ventilation1.multiProduct1.u[3]
 */
void OM_Result_eqFunction_238(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,238};
  data->localData[0]->realVars[133] /* two_single_ventilation1._multiSum1._u[2] variable */ = (data->simulationInfo->realParameter[87]) * ((data->simulationInfo->realParameter[91]) * (data->localData[0]->realVars[127] /* two_single_ventilation1._multiProduct1._u[3] variable */));
  TRACE_POP
}
/*
 equation index: 239
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum1._y = two_single_ventilation1.multiSum1.k[1] * two_single_ventilation1.multiSum1.u[1] + two_single_ventilation1.multiSum1.k[2] * two_single_ventilation1.multiSum1.u[2] + two_single_ventilation1.multiSum1.k[3] * two_single_ventilation1.C3.k
 */
void OM_Result_eqFunction_239(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,239};
  data->localData[0]->realVars[134] /* two_single_ventilation1._multiSum1._y variable */ = (data->simulationInfo->realParameter[99]) * (data->localData[0]->realVars[132] /* two_single_ventilation1._multiSum1._u[1] variable */) + (data->simulationInfo->realParameter[100]) * (data->localData[0]->realVars[133] /* two_single_ventilation1._multiSum1._u[2] variable */) + (data->simulationInfo->realParameter[101]) * (data->simulationInfo->realParameter[88]);
  TRACE_POP
}
/*
 equation index: 240
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct3._u[3] = sqrt(two_single_ventilation1.multiSum1.y)
 */
void OM_Result_eqFunction_240(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,240};
  modelica_real tmp11;
  tmp11 = data->localData[0]->realVars[134] /* two_single_ventilation1._multiSum1._y variable */;
  if(!(tmp11 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(two_single_ventilation1.multiSum1.y) was %g should be >= 0", tmp11);
  }
  data->localData[0]->realVars[128] /* two_single_ventilation1._multiProduct3._u[3] variable */ = sqrt(tmp11);
  TRACE_POP
}
/*
 equation index: 241
 type: SIMPLE_ASSIGN
 two_single_ventilation1._Ventilation_rate._u1 = two_single_ventilation1.const.k * two_single_ventilation1.Area_1.k * two_single_ventilation1.multiProduct3.u[3]
 */
void OM_Result_eqFunction_241(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,241};
  data->localData[0]->realVars[125] /* two_single_ventilation1._Ventilation_rate._u1 variable */ = (data->simulationInfo->realParameter[98]) * ((data->simulationInfo->realParameter[84]) * (data->localData[0]->realVars[128] /* two_single_ventilation1._multiProduct3._u[3] variable */));
  TRACE_POP
}
/*
 equation index: 242
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum2._u[2] = two_single_ventilation1.C2.k * two_single_ventilation1.Height_2.k * two_single_ventilation1.multiProduct1.u[3]
 */
void OM_Result_eqFunction_242(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,242};
  data->localData[0]->realVars[135] /* two_single_ventilation1._multiSum2._u[2] variable */ = (data->simulationInfo->realParameter[87]) * ((data->simulationInfo->realParameter[92]) * (data->localData[0]->realVars[127] /* two_single_ventilation1._multiProduct1._u[3] variable */));
  TRACE_POP
}
/*
 equation index: 243
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum2._y = two_single_ventilation1.multiSum2.k[1] * two_single_ventilation1.multiSum1.u[1] + two_single_ventilation1.multiSum2.k[2] * two_single_ventilation1.multiSum2.u[2] + two_single_ventilation1.multiSum2.k[3] * two_single_ventilation1.C3.k
 */
void OM_Result_eqFunction_243(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,243};
  data->localData[0]->realVars[136] /* two_single_ventilation1._multiSum2._y variable */ = (data->simulationInfo->realParameter[102]) * (data->localData[0]->realVars[132] /* two_single_ventilation1._multiSum1._u[1] variable */) + (data->simulationInfo->realParameter[103]) * (data->localData[0]->realVars[135] /* two_single_ventilation1._multiSum2._u[2] variable */) + (data->simulationInfo->realParameter[104]) * (data->simulationInfo->realParameter[88]);
  TRACE_POP
}
/*
 equation index: 244
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct4._u[3] = sqrt(two_single_ventilation1.multiSum2.y)
 */
void OM_Result_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
  modelica_real tmp12;
  tmp12 = data->localData[0]->realVars[136] /* two_single_ventilation1._multiSum2._y variable */;
  if(!(tmp12 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(two_single_ventilation1.multiSum2.y) was %g should be >= 0", tmp12);
  }
  data->localData[0]->realVars[129] /* two_single_ventilation1._multiProduct4._u[3] variable */ = sqrt(tmp12);
  TRACE_POP
}
/*
 equation index: 245
 type: SIMPLE_ASSIGN
 two_single_ventilation1._Ventilation_rate._u2 = two_single_ventilation1.const.k * two_single_ventilation1.Area_2.k * two_single_ventilation1.multiProduct4.u[3]
 */
void OM_Result_eqFunction_245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,245};
  data->localData[0]->realVars[126] /* two_single_ventilation1._Ventilation_rate._u2 variable */ = (data->simulationInfo->realParameter[98]) * ((data->simulationInfo->realParameter[85]) * (data->localData[0]->realVars[129] /* two_single_ventilation1._multiProduct4._u[3] variable */));
  TRACE_POP
}
/*
 equation index: 246
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct5._u[2] = two_single_ventilation1.Ventilation_rate.k1 * two_single_ventilation1.Ventilation_rate.u1 + two_single_ventilation1.Ventilation_rate.k2 * two_single_ventilation1.Ventilation_rate.u2
 */
void OM_Result_eqFunction_246(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,246};
  data->localData[0]->realVars[130] /* two_single_ventilation1._multiProduct5._u[2] variable */ = (data->simulationInfo->realParameter[94]) * (data->localData[0]->realVars[125] /* two_single_ventilation1._Ventilation_rate._u1 variable */) + (data->simulationInfo->realParameter[95]) * (data->localData[0]->realVars[126] /* two_single_ventilation1._Ventilation_rate._u2 variable */);
  TRACE_POP
}
/*
 equation index: 247
 type: SIMPLE_ASSIGN
 two_single_ventilation1._Heat_flow_NV._Q_flow = two_single_ventilation1.Ventilation_param.k * two_single_ventilation1.multiProduct5.u[2] * two_single_ventilation1.multiProduct5.u[3]
 */
void OM_Result_eqFunction_247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,247};
  data->localData[0]->realVars[122] /* two_single_ventilation1._Heat_flow_NV._Q_flow variable */ = (data->simulationInfo->realParameter[93]) * ((data->localData[0]->realVars[130] /* two_single_ventilation1._multiProduct5._u[2] variable */) * (data->localData[0]->realVars[131] /* two_single_ventilation1._multiProduct5._u[3] variable */));
  TRACE_POP
}
/*
 equation index: 248
 type: SIMPLE_ASSIGN
 thermalCollector1._port_a[11]._Q_flow = two_single_ventilation1.Heat_flow_NV.Q_flow * (1.0 + two_single_ventilation1.Heat_flow_NV.alpha * (Capacitor_indoor_air.T - two_single_ventilation1.Heat_flow_NV.T_ref))
 */
void OM_Result_eqFunction_248(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,248};
  data->localData[0]->realVars[120] /* thermalCollector1._port_a[11]._Q_flow variable */ = (data->localData[0]->realVars[122] /* two_single_ventilation1._Heat_flow_NV._Q_flow variable */) * (1.0 + (data->simulationInfo->realParameter[90]) * (data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */ - data->simulationInfo->realParameter[89]));
  TRACE_POP
}
/*
 equation index: 249
 type: SIMPLE_ASSIGN
 Data_solar_radiation._timeScaled = 0.01666666666666667 * time
 */
void OM_Result_eqFunction_249(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,249};
  data->localData[0]->realVars[75] /* Data_solar_radiation._timeScaled variable */ = (0.01666666666666667) * (data->localData[0]->timeValue);
  TRACE_POP
}
/*
 equation index: 250
 type: WHEN
 
 when {$whenCondition3} then
   Data_solar_radiation._nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Data_solar_radiation.tableID, Data_solar_radiation.timeScaled);
 end when;
 */
void OM_Result_eqFunction_250(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,250};
  if((data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */ && !data->simulationInfo->booleanVarsPre[2] /* $whenCondition3 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[140] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */ = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, data->simulationInfo->extObjs[1], data->localData[0]->realVars[75] /* Data_solar_radiation._timeScaled variable */);
  }
  TRACE_POP
}
/*
 equation index: 251
 type: WHEN
 
 when {$whenCondition3} then
   Data_solar_radiation._nextTimeEvent = if Data_solar_radiation.nextTimeEventScaled < 9.999999999999999e+59 then Data_solar_radiation.nextTimeEventScaled * 60.0 else 9.999999999999999e+59;
 end when;
 */
void OM_Result_eqFunction_251(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,251};
  modelica_boolean tmp13;
  if((data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */ && !data->simulationInfo->booleanVarsPre[2] /* $whenCondition3 DISCRETE */ /* edge */))
  {
    tmp13 = Less(data->localData[0]->realVars[140] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */,9.999999999999999e+59);
    data->localData[0]->realVars[139] /* Data_solar_radiation._nextTimeEvent DISCRETE */ = (tmp13?(data->localData[0]->realVars[140] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */) * (60.0):9.999999999999999e+59);
  }
  TRACE_POP
}
/*
 equation index: 252
 type: SIMPLE_ASSIGN
 $cse2 = Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_solar_radiation.tableID, 2, Data_solar_radiation.timeScaled, Data_solar_radiation.nextTimeEventScaled, pre(Data_solar_radiation.nextTimeEventScaled))
 */
void OM_Result_eqFunction_252(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,252};
  data->localData[0]->realVars[11] /* $cse2 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[1], ((modelica_integer) 2), data->localData[0]->realVars[75] /* Data_solar_radiation._timeScaled variable */, data->localData[0]->realVars[140] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[140] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
 equation index: 253
 type: SIMPLE_ASSIGN
 Data_solar_radiation._y[2] = Data_solar_radiation.p_offset[2] + $cse2
 */
void OM_Result_eqFunction_253(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,253};
  data->localData[0]->realVars[77] /* Data_solar_radiation._y[2] variable */ = data->simulationInfo->realParameter[36] + data->localData[0]->realVars[11] /* $cse2 variable */;
  TRACE_POP
}
/*
 equation index: 254
 type: SIMPLE_ASSIGN
 SolarRadiation._u1 = FactorStdSolarRadiation.k * Data_solar_radiation.y[2]
 */
void OM_Result_eqFunction_254(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,254};
  data->localData[0]->realVars[107] /* SolarRadiation._u1 variable */ = (data->simulationInfo->realParameter[54]) * (data->localData[0]->realVars[77] /* Data_solar_radiation._y[2] variable */);
  TRACE_POP
}
/*
 equation index: 255
 type: SIMPLE_ASSIGN
 $cse1 = Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_solar_radiation.tableID, 1, Data_solar_radiation.timeScaled, Data_solar_radiation.nextTimeEventScaled, pre(Data_solar_radiation.nextTimeEventScaled))
 */
void OM_Result_eqFunction_255(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,255};
  data->localData[0]->realVars[10] /* $cse1 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[1], ((modelica_integer) 1), data->localData[0]->realVars[75] /* Data_solar_radiation._timeScaled variable */, data->localData[0]->realVars[140] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[140] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
 equation index: 256
 type: SIMPLE_ASSIGN
 Data_solar_radiation._y[1] = Data_solar_radiation.p_offset[1] + $cse1
 */
void OM_Result_eqFunction_256(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,256};
  data->localData[0]->realVars[76] /* Data_solar_radiation._y[1] variable */ = data->simulationInfo->realParameter[35] + data->localData[0]->realVars[10] /* $cse1 variable */;
  TRACE_POP
}
/*
 equation index: 257
 type: SIMPLE_ASSIGN
 SolarRadiation._y = SolarRadiation.k1 * SolarRadiation.u1 + SolarRadiation.k2 * Data_solar_radiation.y[1]
 */
void OM_Result_eqFunction_257(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,257};
  data->localData[0]->realVars[108] /* SolarRadiation._y variable */ = (data->simulationInfo->realParameter[75]) * (data->localData[0]->realVars[107] /* SolarRadiation._u1 variable */) + (data->simulationInfo->realParameter[76]) * (data->localData[0]->realVars[76] /* Data_solar_radiation._y[1] variable */);
  TRACE_POP
}
/*
 equation index: 258
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._Q_flow = SolarRadiation.y * roof_emissivity.k
 */
void OM_Result_eqFunction_258(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,258};
  data->localData[0]->realVars[82] /* Heatflow_solar_radiation._Q_flow variable */ = (data->localData[0]->realVars[108] /* SolarRadiation._y variable */) * (data->simulationInfo->realParameter[83]);
  TRACE_POP
}
/*
 equation index: 259
 type: SIMPLE_ASSIGN
 Heatflow_infiltration._Q_flow = Temperature_difference.y * Infiltration.k
 */
void OM_Result_eqFunction_259(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,259};
  data->localData[0]->realVars[81] /* Heatflow_infiltration._Q_flow variable */ = (data->localData[0]->realVars[111] /* Temperature_difference._y variable */) * (data->simulationInfo->realParameter[62]);
  TRACE_POP
}
/*
 equation index: 260
 type: SIMPLE_ASSIGN
 thermalCollector1._port_a[12]._Q_flow = Heatflow_infiltration.Q_flow * (1.0 + Heatflow_infiltration.alpha * (Capacitor_indoor_air.T - Heatflow_infiltration.T_ref))
 */
void OM_Result_eqFunction_260(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,260};
  data->localData[0]->realVars[121] /* thermalCollector1._port_a[12]._Q_flow variable */ = (data->localData[0]->realVars[81] /* Heatflow_infiltration._Q_flow variable */) * (1.0 + (data->simulationInfo->realParameter[59]) * (data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */ - data->simulationInfo->realParameter[58]));
  TRACE_POP
}
/*
 equation index: 261
 type: SIMPLE_ASSIGN
 Convection_floor._dT = Floor_temperature.k - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_261(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,261};
  data->localData[0]->realVars[51] /* Convection_floor._dT variable */ = data->simulationInfo->realParameter[57] - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 262
 type: SIMPLE_ASSIGN
 Convection_floor._Q_flow = Convection_coef_floor.k * Convection_floor.dT
 */
void OM_Result_eqFunction_262(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,262};
  data->localData[0]->realVars[50] /* Convection_floor._Q_flow variable */ = (data->simulationInfo->realParameter[19]) * (data->localData[0]->realVars[51] /* Convection_floor._dT variable */);
  TRACE_POP
}
void OM_Result_eqFunction_263(DATA*,threadData_t*);
void OM_Result_eqFunction_264(DATA*,threadData_t*);
void OM_Result_eqFunction_265(DATA*,threadData_t*);
void OM_Result_eqFunction_266(DATA*,threadData_t*);
void OM_Result_eqFunction_267(DATA*,threadData_t*);
void OM_Result_eqFunction_268(DATA*,threadData_t*);
/*
 equation index: 274
 indexNonlinear: 8
 type: NONLINEAR
 
 vars: {Conduction_wall4_inner._port_b._T}
 eqns: {263, 264, 265, 266, 267, 268}
 */
void OM_Result_eqFunction_274(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,274};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 274 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[8].nlsxOld[0] = data->localData[0]->realVars[46] /* Conduction_wall4_inner._port_b._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 8);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,274};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 274 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[46] /* Conduction_wall4_inner._port_b._T variable */ = data->simulationInfo->nonlinearSystemData[8].nlsx[0];
  TRACE_POP
}
/*
 equation index: 275
 type: SIMPLE_ASSIGN
 Radiation_wall4_inner._dT = Conduction_wall4_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,275};
  data->localData[0]->realVars[103] /* Radiation_wall4_inner._dT variable */ = data->localData[0]->realVars[46] /* Conduction_wall4_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
void OM_Result_eqFunction_276(DATA*,threadData_t*);
void OM_Result_eqFunction_277(DATA*,threadData_t*);
void OM_Result_eqFunction_278(DATA*,threadData_t*);
void OM_Result_eqFunction_279(DATA*,threadData_t*);
void OM_Result_eqFunction_280(DATA*,threadData_t*);
void OM_Result_eqFunction_281(DATA*,threadData_t*);
/*
 equation index: 287
 indexNonlinear: 9
 type: NONLINEAR
 
 vars: {Conduction_wall4_outer._port_a._T}
 eqns: {276, 277, 278, 279, 280, 281}
 */
void OM_Result_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 287 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[9].nlsxOld[0] = data->localData[0]->realVars[49] /* Conduction_wall4_outer._port_a._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 9);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,287};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 287 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[49] /* Conduction_wall4_outer._port_a._T variable */ = data->simulationInfo->nonlinearSystemData[9].nlsx[0];
  TRACE_POP
}
/*
 equation index: 288
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._dT = multiProduct1.u[3] - Conduction_wall4_outer.port_a.T
 */
void OM_Result_eqFunction_288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,288};
  data->localData[0]->realVars[105] /* Radiation_wall4_outer._dT variable */ = data->localData[0]->realVars[118] /* multiProduct1._u[3] variable */ - data->localData[0]->realVars[49] /* Conduction_wall4_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 289
 type: SIMPLE_ASSIGN
 Capacitor_wall4._port._Q_flow = Conduction_wall4_outer.Q_flow - Conduction_wall4_inner.Q_flow
 */
void OM_Result_eqFunction_289(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,289};
  data->localData[0]->realVars[25] /* Capacitor_wall4._port._Q_flow variable */ = data->localData[0]->realVars[47] /* Conduction_wall4_outer._Q_flow variable */ - data->localData[0]->realVars[44] /* Conduction_wall4_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 290
 type: SIMPLE_ASSIGN
 Capacitor_wall4._der_T = DIVISION(Capacitor_wall4.port.Q_flow, Capacitor_wall4.C)
 */
void OM_Result_eqFunction_290(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,290};
  data->localData[0]->realVars[24] /* Capacitor_wall4._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[25] /* Capacitor_wall4._port._Q_flow variable */,data->simulationInfo->realParameter[8],"Capacitor_wall4.C",equationIndexes);
  TRACE_POP
}
/*
 equation index: 291
 type: SIMPLE_ASSIGN
 der(Capacitor_wall4._T) = Capacitor_wall4.der_T
 */
void OM_Result_eqFunction_291(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,291};
  data->localData[0]->realVars[9] /* der(Capacitor_wall4._T) STATE_DER */ = data->localData[0]->realVars[24] /* Capacitor_wall4._der_T variable */;
  TRACE_POP
}
void OM_Result_eqFunction_292(DATA*,threadData_t*);
void OM_Result_eqFunction_293(DATA*,threadData_t*);
void OM_Result_eqFunction_294(DATA*,threadData_t*);
void OM_Result_eqFunction_295(DATA*,threadData_t*);
void OM_Result_eqFunction_296(DATA*,threadData_t*);
void OM_Result_eqFunction_297(DATA*,threadData_t*);
/*
 equation index: 303
 indexNonlinear: 10
 type: NONLINEAR
 
 vars: {Conduction_wall3_inner._port_b._T}
 eqns: {292, 293, 294, 295, 296, 297}
 */
void OM_Result_eqFunction_303(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,303};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 303 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[10].nlsxOld[0] = data->localData[0]->realVars[40] /* Conduction_wall3_inner._port_b._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 10);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,303};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 303 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[40] /* Conduction_wall3_inner._port_b._T variable */ = data->simulationInfo->nonlinearSystemData[10].nlsx[0];
  TRACE_POP
}
/*
 equation index: 304
 type: SIMPLE_ASSIGN
 Radiation_wall3_inner._dT = Conduction_wall3_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_304(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,304};
  data->localData[0]->realVars[99] /* Radiation_wall3_inner._dT variable */ = data->localData[0]->realVars[40] /* Conduction_wall3_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
void OM_Result_eqFunction_305(DATA*,threadData_t*);
void OM_Result_eqFunction_306(DATA*,threadData_t*);
void OM_Result_eqFunction_307(DATA*,threadData_t*);
void OM_Result_eqFunction_308(DATA*,threadData_t*);
void OM_Result_eqFunction_309(DATA*,threadData_t*);
void OM_Result_eqFunction_310(DATA*,threadData_t*);
/*
 equation index: 316
 indexNonlinear: 11
 type: NONLINEAR
 
 vars: {Conduction_wall3_outer._port_a._T}
 eqns: {305, 306, 307, 308, 309, 310}
 */
void OM_Result_eqFunction_316(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,316};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 316 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[11].nlsxOld[0] = data->localData[0]->realVars[43] /* Conduction_wall3_outer._port_a._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 11);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,316};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 316 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[43] /* Conduction_wall3_outer._port_a._T variable */ = data->simulationInfo->nonlinearSystemData[11].nlsx[0];
  TRACE_POP
}
/*
 equation index: 317
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._dT = multiProduct1.u[3] - Conduction_wall3_outer.port_a.T
 */
void OM_Result_eqFunction_317(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,317};
  data->localData[0]->realVars[101] /* Radiation_wall3_outer._dT variable */ = data->localData[0]->realVars[118] /* multiProduct1._u[3] variable */ - data->localData[0]->realVars[43] /* Conduction_wall3_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 318
 type: SIMPLE_ASSIGN
 Capacitor_wall3._port._Q_flow = Conduction_wall3_outer.Q_flow - Conduction_wall3_inner.Q_flow
 */
void OM_Result_eqFunction_318(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,318};
  data->localData[0]->realVars[23] /* Capacitor_wall3._port._Q_flow variable */ = data->localData[0]->realVars[41] /* Conduction_wall3_outer._Q_flow variable */ - data->localData[0]->realVars[38] /* Conduction_wall3_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 319
 type: SIMPLE_ASSIGN
 Capacitor_wall3._der_T = DIVISION(Capacitor_wall3.port.Q_flow, Capacitor_wall3.C)
 */
void OM_Result_eqFunction_319(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,319};
  data->localData[0]->realVars[22] /* Capacitor_wall3._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[23] /* Capacitor_wall3._port._Q_flow variable */,data->simulationInfo->realParameter[7],"Capacitor_wall3.C",equationIndexes);
  TRACE_POP
}
/*
 equation index: 320
 type: SIMPLE_ASSIGN
 der(Capacitor_wall3._T) = Capacitor_wall3.der_T
 */
void OM_Result_eqFunction_320(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,320};
  data->localData[0]->realVars[8] /* der(Capacitor_wall3._T) STATE_DER */ = data->localData[0]->realVars[22] /* Capacitor_wall3._der_T variable */;
  TRACE_POP
}
void OM_Result_eqFunction_321(DATA*,threadData_t*);
void OM_Result_eqFunction_322(DATA*,threadData_t*);
void OM_Result_eqFunction_323(DATA*,threadData_t*);
void OM_Result_eqFunction_324(DATA*,threadData_t*);
void OM_Result_eqFunction_325(DATA*,threadData_t*);
void OM_Result_eqFunction_326(DATA*,threadData_t*);
void OM_Result_eqFunction_327(DATA*,threadData_t*);
/*
 equation index: 334
 indexNonlinear: 12
 type: NONLINEAR
 
 vars: {Conduction_roof_inner._port_b._T}
 eqns: {321, 322, 323, 324, 325, 326, 327}
 */
void OM_Result_eqFunction_334(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,334};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 334 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[12].nlsxOld[0] = data->localData[0]->realVars[28] /* Conduction_roof_inner._port_b._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 12);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,334};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 334 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[28] /* Conduction_roof_inner._port_b._T variable */ = data->simulationInfo->nonlinearSystemData[12].nlsx[0];
  TRACE_POP
}
/*
 equation index: 335
 type: SIMPLE_ASSIGN
 Radiation_roof_inner._dT = Conduction_roof_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_335(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,335};
  data->localData[0]->realVars[89] /* Radiation_roof_inner._dT variable */ = data->localData[0]->realVars[28] /* Conduction_roof_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 336
 type: SIMPLE_ASSIGN
 Temperature_floor._port._Q_flow = Radiation_roof_to_floor.Q_flow - (Convection_floor.Q_flow + Radiation_floor.Q_flow)
 */
void OM_Result_eqFunction_336(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,336};
  data->localData[0]->realVars[112] /* Temperature_floor._port._Q_flow variable */ = data->localData[0]->realVars[92] /* Radiation_roof_to_floor._Q_flow variable */ - (data->localData[0]->realVars[50] /* Convection_floor._Q_flow variable */ + data->localData[0]->realVars[86] /* Radiation_floor._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 337
 type: SIMPLE_ASSIGN
 Radiation_roof_to_floor._dT = Conduction_roof_inner.port_b.T - Floor_temperature.k
 */
void OM_Result_eqFunction_337(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,337};
  data->localData[0]->realVars[93] /* Radiation_roof_to_floor._dT variable */ = data->localData[0]->realVars[28] /* Conduction_roof_inner._port_b._T variable */ - data->simulationInfo->realParameter[57];
  TRACE_POP
}
void OM_Result_eqFunction_338(DATA*,threadData_t*);
void OM_Result_eqFunction_339(DATA*,threadData_t*);
void OM_Result_eqFunction_340(DATA*,threadData_t*);
void OM_Result_eqFunction_341(DATA*,threadData_t*);
void OM_Result_eqFunction_342(DATA*,threadData_t*);
void OM_Result_eqFunction_343(DATA*,threadData_t*);
void OM_Result_eqFunction_344(DATA*,threadData_t*);
/*
 equation index: 351
 indexNonlinear: 13
 type: NONLINEAR
 
 vars: {Conduction_roof_outer._port_a._T}
 eqns: {338, 339, 340, 341, 342, 343, 344}
 */
void OM_Result_eqFunction_351(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,351};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 351 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[13].nlsxOld[0] = data->localData[0]->realVars[31] /* Conduction_roof_outer._port_a._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 13);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,351};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 351 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[31] /* Conduction_roof_outer._port_a._T variable */ = data->simulationInfo->nonlinearSystemData[13].nlsx[0];
  TRACE_POP
}
/*
 equation index: 352
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._dT = SkyTemperatureToK.T - Conduction_roof_outer.port_a.T
 */
void OM_Result_eqFunction_352(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,352};
  data->localData[0]->realVars[91] /* Radiation_roof_outer._dT variable */ = data->localData[0]->realVars[106] /* SkyTemperatureToK._T variable */ - data->localData[0]->realVars[31] /* Conduction_roof_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 353
 type: SIMPLE_ASSIGN
 Capacitor_roof._port._Q_flow = Conduction_roof_outer.Q_flow - Conduction_roof_inner.Q_flow
 */
void OM_Result_eqFunction_353(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,353};
  data->localData[0]->realVars[19] /* Capacitor_roof._port._Q_flow variable */ = data->localData[0]->realVars[29] /* Conduction_roof_outer._Q_flow variable */ - data->localData[0]->realVars[26] /* Conduction_roof_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 354
 type: SIMPLE_ASSIGN
 Capacitor_roof._der_T = DIVISION(Capacitor_roof.port.Q_flow, Capacitor_roof.C)
 */
void OM_Result_eqFunction_354(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,354};
  data->localData[0]->realVars[18] /* Capacitor_roof._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[19] /* Capacitor_roof._port._Q_flow variable */,data->simulationInfo->realParameter[5],"Capacitor_roof.C",equationIndexes);
  TRACE_POP
}
/*
 equation index: 355
 type: SIMPLE_ASSIGN
 der(Capacitor_roof._T) = Capacitor_roof.der_T
 */
void OM_Result_eqFunction_355(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,355};
  data->localData[0]->realVars[6] /* der(Capacitor_roof._T) STATE_DER */ = data->localData[0]->realVars[18] /* Capacitor_roof._der_T variable */;
  TRACE_POP
}
void OM_Result_eqFunction_356(DATA*,threadData_t*);
void OM_Result_eqFunction_357(DATA*,threadData_t*);
void OM_Result_eqFunction_358(DATA*,threadData_t*);
void OM_Result_eqFunction_359(DATA*,threadData_t*);
void OM_Result_eqFunction_360(DATA*,threadData_t*);
void OM_Result_eqFunction_361(DATA*,threadData_t*);
/*
 equation index: 367
 indexNonlinear: 14
 type: NONLINEAR
 
 vars: {Conduction_wall1_outer._port_a._T}
 eqns: {356, 357, 358, 359, 360, 361}
 */
void OM_Result_eqFunction_367(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,367};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 367 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[14].nlsxOld[0] = data->localData[0]->realVars[37] /* Conduction_wall1_outer._port_a._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 14);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,367};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 367 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[37] /* Conduction_wall1_outer._port_a._T variable */ = data->simulationInfo->nonlinearSystemData[14].nlsx[0];
  TRACE_POP
}
/*
 equation index: 368
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._dT = multiProduct1.u[3] - Conduction_wall1_outer.port_a.T
 */
void OM_Result_eqFunction_368(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,368};
  data->localData[0]->realVars[97] /* Radiation_wall1_outer._dT variable */ = data->localData[0]->realVars[118] /* multiProduct1._u[3] variable */ - data->localData[0]->realVars[37] /* Conduction_wall1_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 369
 type: SIMPLE_ASSIGN
 OutdoorTemperatureToK._port._Q_flow = (-Convection_roof_outer.Q_flow) - Convection_wall1_outer.Q_flow - Convection_wall4_outer.Q_flow - Convection_wall3_outer.Q_flow - Radiation_wall1_outer.Q_flow - Radiation_wall3_outer.Q_flow - Radiation_wall4_outer.Q_flow
 */
void OM_Result_eqFunction_369(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,369};
  data->localData[0]->realVars[85] /* OutdoorTemperatureToK._port._Q_flow variable */ = (-data->localData[0]->realVars[55] /* Convection_roof_outer._Q_flow variable */) - data->localData[0]->realVars[60] /* Convection_wall1_outer._Q_flow variable */ - data->localData[0]->realVars[70] /* Convection_wall4_outer._Q_flow variable */ - data->localData[0]->realVars[65] /* Convection_wall3_outer._Q_flow variable */ - data->localData[0]->realVars[96] /* Radiation_wall1_outer._Q_flow variable */ - data->localData[0]->realVars[100] /* Radiation_wall3_outer._Q_flow variable */ - data->localData[0]->realVars[104] /* Radiation_wall4_outer._Q_flow variable */;
  TRACE_POP
}
void OM_Result_eqFunction_370(DATA*,threadData_t*);
void OM_Result_eqFunction_371(DATA*,threadData_t*);
void OM_Result_eqFunction_372(DATA*,threadData_t*);
void OM_Result_eqFunction_373(DATA*,threadData_t*);
void OM_Result_eqFunction_374(DATA*,threadData_t*);
void OM_Result_eqFunction_375(DATA*,threadData_t*);
/*
 equation index: 381
 indexNonlinear: 15
 type: NONLINEAR
 
 vars: {Conduction_wall1_inner._port_b._T}
 eqns: {370, 371, 372, 373, 374, 375}
 */
void OM_Result_eqFunction_381(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,381};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 381 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[15].nlsxOld[0] = data->localData[0]->realVars[34] /* Conduction_wall1_inner._port_b._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 15);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,381};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 381 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[34] /* Conduction_wall1_inner._port_b._T variable */ = data->simulationInfo->nonlinearSystemData[15].nlsx[0];
  TRACE_POP
}
/*
 equation index: 382
 type: SIMPLE_ASSIGN
 Capacitor_wall1._port._Q_flow = Conduction_wall1_outer.Q_flow - Conduction_wall1_inner.Q_flow
 */
void OM_Result_eqFunction_382(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,382};
  data->localData[0]->realVars[21] /* Capacitor_wall1._port._Q_flow variable */ = data->localData[0]->realVars[35] /* Conduction_wall1_outer._Q_flow variable */ - data->localData[0]->realVars[32] /* Conduction_wall1_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 383
 type: SIMPLE_ASSIGN
 Capacitor_wall1._der_T = DIVISION(Capacitor_wall1.port.Q_flow, Capacitor_wall1.C)
 */
void OM_Result_eqFunction_383(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,383};
  data->localData[0]->realVars[20] /* Capacitor_wall1._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[21] /* Capacitor_wall1._port._Q_flow variable */,data->simulationInfo->realParameter[6],"Capacitor_wall1.C",equationIndexes);
  TRACE_POP
}
/*
 equation index: 384
 type: SIMPLE_ASSIGN
 der(Capacitor_wall1._T) = Capacitor_wall1.der_T
 */
void OM_Result_eqFunction_384(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,384};
  data->localData[0]->realVars[7] /* der(Capacitor_wall1._T) STATE_DER */ = data->localData[0]->realVars[20] /* Capacitor_wall1._der_T variable */;
  TRACE_POP
}
/*
 equation index: 385
 type: SIMPLE_ASSIGN
 Radiation_wall1_inner._dT = Conduction_wall1_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_385(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,385};
  data->localData[0]->realVars[95] /* Radiation_wall1_inner._dT variable */ = data->localData[0]->realVars[34] /* Conduction_wall1_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 386
 type: SIMPLE_ASSIGN
 Capacitor_indoor_air._port._Q_flow = thermalCollector1.port_a[12].Q_flow - ((-Convection_roof_inner.Q_flow) - Radiation_roof_inner.Q_flow - Convection_wall1_inner.Q_flow - Radiation_wall1_inner.Q_flow - Convection_wall3_inner.Q_flow - Radiation_wall3_inner.Q_flow - Convection_wall4_inner.Q_flow - Radiation_wall4_inner.Q_flow - Convection_floor.Q_flow - Radiation_floor.Q_flow - thermalCollector1.port_a[11].Q_flow)
 */
void OM_Result_eqFunction_386(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,386};
  data->localData[0]->realVars[17] /* Capacitor_indoor_air._port._Q_flow variable */ = data->localData[0]->realVars[121] /* thermalCollector1._port_a[12]._Q_flow variable */ - ((-data->localData[0]->realVars[52] /* Convection_roof_inner._Q_flow variable */) - data->localData[0]->realVars[88] /* Radiation_roof_inner._Q_flow variable */ - data->localData[0]->realVars[57] /* Convection_wall1_inner._Q_flow variable */ - data->localData[0]->realVars[94] /* Radiation_wall1_inner._Q_flow variable */ - data->localData[0]->realVars[62] /* Convection_wall3_inner._Q_flow variable */ - data->localData[0]->realVars[98] /* Radiation_wall3_inner._Q_flow variable */ - data->localData[0]->realVars[67] /* Convection_wall4_inner._Q_flow variable */ - data->localData[0]->realVars[102] /* Radiation_wall4_inner._Q_flow variable */ - data->localData[0]->realVars[50] /* Convection_floor._Q_flow variable */ - data->localData[0]->realVars[86] /* Radiation_floor._Q_flow variable */ - data->localData[0]->realVars[120] /* thermalCollector1._port_a[11]._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 387
 type: SIMPLE_ASSIGN
 Capacitor_indoor_air._der_T = DIVISION(Capacitor_indoor_air.port.Q_flow, Capacitor_indoor_air.C)
 */
void OM_Result_eqFunction_387(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,387};
  data->localData[0]->realVars[16] /* Capacitor_indoor_air._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[17] /* Capacitor_indoor_air._port._Q_flow variable */,data->simulationInfo->realParameter[4],"Capacitor_indoor_air.C",equationIndexes);
  TRACE_POP
}
/*
 equation index: 388
 type: SIMPLE_ASSIGN
 der(Capacitor_indoor_air._T) = Capacitor_indoor_air.der_T
 */
void OM_Result_eqFunction_388(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,388};
  data->localData[0]->realVars[5] /* der(Capacitor_indoor_air._T) STATE_DER */ = data->localData[0]->realVars[16] /* Capacitor_indoor_air._der_T variable */;
  TRACE_POP
}
/*
 equation index: 391
 type: ALGORITHM
 
   assert(Data_solar_radiation.tableName <> "NoName", "tableOnFile = true and no table name given");
 */
void OM_Result_eqFunction_391(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,391};
  static const MMC_DEFSTRINGLIT(tmp2,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp3,42,"tableOnFile = true and no table name given");
  static int tmp4 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[3], MMC_REFSTRINGLIT(tmp2))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2207,7,2208,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_solar_radiation.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp3)));
      }
    }
  }
  TRACE_POP
}
/*
 equation index: 390
 type: ALGORITHM
 
   assert(Data_outdoor_temperature.tableName <> "NoName", "tableOnFile = true and no table name given");
 */
void OM_Result_eqFunction_390(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,390};
  static const MMC_DEFSTRINGLIT(tmp7,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp8,42,"tableOnFile = true and no table name given");
  static int tmp9 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[1], MMC_REFSTRINGLIT(tmp7))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2207,7,2208,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_outdoor_temperature.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp8)));
      }
    }
  }
  TRACE_POP
}
/*
 equation index: 389
 type: ALGORITHM
 
   assert(Data_wind_speed.tableName <> "NoName", "tableOnFile = true and no table name given");
 */
void OM_Result_eqFunction_389(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,389};
  static const MMC_DEFSTRINGLIT(tmp12,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp13,42,"tableOnFile = true and no table name given");
  static int tmp14 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[5], MMC_REFSTRINGLIT(tmp12))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2207,7,2208,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nData_wind_speed.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp13)));
      }
    }
  }
  TRACE_POP
}


int OM_Result_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  OM_Result_functionLocalKnownVars(data, threadData);
  OM_Result_eqFunction_200(data, threadData);

  OM_Result_eqFunction_201(data, threadData);

  OM_Result_eqFunction_202(data, threadData);

  OM_Result_eqFunction_203(data, threadData);

  OM_Result_eqFunction_204(data, threadData);

  OM_Result_eqFunction_205(data, threadData);

  OM_Result_eqFunction_206(data, threadData);

  OM_Result_eqFunction_207(data, threadData);

  OM_Result_eqFunction_208(data, threadData);

  OM_Result_eqFunction_209(data, threadData);

  OM_Result_eqFunction_210(data, threadData);

  OM_Result_eqFunction_211(data, threadData);

  OM_Result_eqFunction_212(data, threadData);

  OM_Result_eqFunction_213(data, threadData);

  OM_Result_eqFunction_214(data, threadData);

  OM_Result_eqFunction_215(data, threadData);

  OM_Result_eqFunction_216(data, threadData);

  OM_Result_eqFunction_217(data, threadData);

  OM_Result_eqFunction_218(data, threadData);

  OM_Result_eqFunction_219(data, threadData);

  OM_Result_eqFunction_220(data, threadData);

  OM_Result_eqFunction_221(data, threadData);

  OM_Result_eqFunction_222(data, threadData);

  OM_Result_eqFunction_223(data, threadData);

  OM_Result_eqFunction_224(data, threadData);

  OM_Result_eqFunction_225(data, threadData);

  OM_Result_eqFunction_226(data, threadData);

  OM_Result_eqFunction_227(data, threadData);

  OM_Result_eqFunction_228(data, threadData);

  OM_Result_eqFunction_229(data, threadData);

  OM_Result_eqFunction_230(data, threadData);

  OM_Result_eqFunction_231(data, threadData);

  OM_Result_eqFunction_232(data, threadData);

  OM_Result_eqFunction_233(data, threadData);

  OM_Result_eqFunction_234(data, threadData);

  OM_Result_eqFunction_235(data, threadData);

  OM_Result_eqFunction_236(data, threadData);

  OM_Result_eqFunction_237(data, threadData);

  OM_Result_eqFunction_238(data, threadData);

  OM_Result_eqFunction_239(data, threadData);

  OM_Result_eqFunction_240(data, threadData);

  OM_Result_eqFunction_241(data, threadData);

  OM_Result_eqFunction_242(data, threadData);

  OM_Result_eqFunction_243(data, threadData);

  OM_Result_eqFunction_244(data, threadData);

  OM_Result_eqFunction_245(data, threadData);

  OM_Result_eqFunction_246(data, threadData);

  OM_Result_eqFunction_247(data, threadData);

  OM_Result_eqFunction_248(data, threadData);

  OM_Result_eqFunction_249(data, threadData);

  OM_Result_eqFunction_250(data, threadData);

  OM_Result_eqFunction_251(data, threadData);

  OM_Result_eqFunction_252(data, threadData);

  OM_Result_eqFunction_253(data, threadData);

  OM_Result_eqFunction_254(data, threadData);

  OM_Result_eqFunction_255(data, threadData);

  OM_Result_eqFunction_256(data, threadData);

  OM_Result_eqFunction_257(data, threadData);

  OM_Result_eqFunction_258(data, threadData);

  OM_Result_eqFunction_259(data, threadData);

  OM_Result_eqFunction_260(data, threadData);

  OM_Result_eqFunction_261(data, threadData);

  OM_Result_eqFunction_262(data, threadData);

  OM_Result_eqFunction_274(data, threadData);

  OM_Result_eqFunction_275(data, threadData);

  OM_Result_eqFunction_287(data, threadData);

  OM_Result_eqFunction_288(data, threadData);

  OM_Result_eqFunction_289(data, threadData);

  OM_Result_eqFunction_290(data, threadData);

  OM_Result_eqFunction_291(data, threadData);

  OM_Result_eqFunction_303(data, threadData);

  OM_Result_eqFunction_304(data, threadData);

  OM_Result_eqFunction_316(data, threadData);

  OM_Result_eqFunction_317(data, threadData);

  OM_Result_eqFunction_318(data, threadData);

  OM_Result_eqFunction_319(data, threadData);

  OM_Result_eqFunction_320(data, threadData);

  OM_Result_eqFunction_334(data, threadData);

  OM_Result_eqFunction_335(data, threadData);

  OM_Result_eqFunction_336(data, threadData);

  OM_Result_eqFunction_337(data, threadData);

  OM_Result_eqFunction_351(data, threadData);

  OM_Result_eqFunction_352(data, threadData);

  OM_Result_eqFunction_353(data, threadData);

  OM_Result_eqFunction_354(data, threadData);

  OM_Result_eqFunction_355(data, threadData);

  OM_Result_eqFunction_367(data, threadData);

  OM_Result_eqFunction_368(data, threadData);

  OM_Result_eqFunction_369(data, threadData);

  OM_Result_eqFunction_381(data, threadData);

  OM_Result_eqFunction_382(data, threadData);

  OM_Result_eqFunction_383(data, threadData);

  OM_Result_eqFunction_384(data, threadData);

  OM_Result_eqFunction_385(data, threadData);

  OM_Result_eqFunction_386(data, threadData);

  OM_Result_eqFunction_387(data, threadData);

  OM_Result_eqFunction_388(data, threadData);

  OM_Result_eqFunction_391(data, threadData);

  OM_Result_eqFunction_390(data, threadData);

  OM_Result_eqFunction_389(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int OM_Result_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void OM_Result_eqFunction_200(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_201(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_202(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_203(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_206(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_207(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_208(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_209(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_210(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_211(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_212(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_213(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_214(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_215(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_216(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_217(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_218(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_219(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_220(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_221(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_223(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_224(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_227(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_228(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_229(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_230(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_231(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_232(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_233(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_234(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_235(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_236(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_237(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_238(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_239(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_240(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_241(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_242(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_243(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_244(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_245(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_246(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_247(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_248(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_249(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_252(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_253(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_254(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_255(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_256(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_257(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_258(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_259(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_260(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_261(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_262(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_274(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_287(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_289(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_290(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_291(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_303(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_316(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_318(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_319(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_320(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_334(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_351(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_353(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_354(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_355(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_367(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_381(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_382(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_383(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_384(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_386(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_387(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_388(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  OM_Result_eqFunction_200(data, threadData);

  OM_Result_eqFunction_201(data, threadData);

  OM_Result_eqFunction_202(data, threadData);

  OM_Result_eqFunction_203(data, threadData);

  OM_Result_eqFunction_206(data, threadData);

  OM_Result_eqFunction_207(data, threadData);

  OM_Result_eqFunction_208(data, threadData);

  OM_Result_eqFunction_209(data, threadData);

  OM_Result_eqFunction_210(data, threadData);

  OM_Result_eqFunction_211(data, threadData);

  OM_Result_eqFunction_212(data, threadData);

  OM_Result_eqFunction_213(data, threadData);

  OM_Result_eqFunction_214(data, threadData);

  OM_Result_eqFunction_215(data, threadData);

  OM_Result_eqFunction_216(data, threadData);

  OM_Result_eqFunction_217(data, threadData);

  OM_Result_eqFunction_218(data, threadData);

  OM_Result_eqFunction_219(data, threadData);

  OM_Result_eqFunction_220(data, threadData);

  OM_Result_eqFunction_221(data, threadData);

  OM_Result_eqFunction_223(data, threadData);

  OM_Result_eqFunction_224(data, threadData);

  OM_Result_eqFunction_227(data, threadData);

  OM_Result_eqFunction_228(data, threadData);

  OM_Result_eqFunction_229(data, threadData);

  OM_Result_eqFunction_230(data, threadData);

  OM_Result_eqFunction_231(data, threadData);

  OM_Result_eqFunction_232(data, threadData);

  OM_Result_eqFunction_233(data, threadData);

  OM_Result_eqFunction_234(data, threadData);

  OM_Result_eqFunction_235(data, threadData);

  OM_Result_eqFunction_236(data, threadData);

  OM_Result_eqFunction_237(data, threadData);

  OM_Result_eqFunction_238(data, threadData);

  OM_Result_eqFunction_239(data, threadData);

  OM_Result_eqFunction_240(data, threadData);

  OM_Result_eqFunction_241(data, threadData);

  OM_Result_eqFunction_242(data, threadData);

  OM_Result_eqFunction_243(data, threadData);

  OM_Result_eqFunction_244(data, threadData);

  OM_Result_eqFunction_245(data, threadData);

  OM_Result_eqFunction_246(data, threadData);

  OM_Result_eqFunction_247(data, threadData);

  OM_Result_eqFunction_248(data, threadData);

  OM_Result_eqFunction_249(data, threadData);

  OM_Result_eqFunction_252(data, threadData);

  OM_Result_eqFunction_253(data, threadData);

  OM_Result_eqFunction_254(data, threadData);

  OM_Result_eqFunction_255(data, threadData);

  OM_Result_eqFunction_256(data, threadData);

  OM_Result_eqFunction_257(data, threadData);

  OM_Result_eqFunction_258(data, threadData);

  OM_Result_eqFunction_259(data, threadData);

  OM_Result_eqFunction_260(data, threadData);

  OM_Result_eqFunction_261(data, threadData);

  OM_Result_eqFunction_262(data, threadData);

  OM_Result_eqFunction_274(data, threadData);

  OM_Result_eqFunction_287(data, threadData);

  OM_Result_eqFunction_289(data, threadData);

  OM_Result_eqFunction_290(data, threadData);

  OM_Result_eqFunction_291(data, threadData);

  OM_Result_eqFunction_303(data, threadData);

  OM_Result_eqFunction_316(data, threadData);

  OM_Result_eqFunction_318(data, threadData);

  OM_Result_eqFunction_319(data, threadData);

  OM_Result_eqFunction_320(data, threadData);

  OM_Result_eqFunction_334(data, threadData);

  OM_Result_eqFunction_351(data, threadData);

  OM_Result_eqFunction_353(data, threadData);

  OM_Result_eqFunction_354(data, threadData);

  OM_Result_eqFunction_355(data, threadData);

  OM_Result_eqFunction_367(data, threadData);

  OM_Result_eqFunction_381(data, threadData);

  OM_Result_eqFunction_382(data, threadData);

  OM_Result_eqFunction_383(data, threadData);

  OM_Result_eqFunction_384(data, threadData);

  OM_Result_eqFunction_386(data, threadData);

  OM_Result_eqFunction_387(data, threadData);

  OM_Result_eqFunction_388(data, threadData);
}

int OM_Result_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  OM_Result_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

  
  TRACE_POP
  return 0;
}

#ifdef FMU_EXPERIMENTAL
#endif
/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "OM_Result_12jac.h"
#include "OM_Result_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks OM_Result_callback = {
   (int (*)(DATA *, threadData_t *, void *)) OM_Result_performSimulation,
   (int (*)(DATA *, threadData_t *, void *)) OM_Result_performQSSSimulation,
   OM_Result_updateContinuousSystem,
   OM_Result_callExternalObjectDestructors,
   OM_Result_initialNonLinearSystem,
   NULL,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   OM_Result_initializeStateSets,
   #else
   NULL,
   #endif
   OM_Result_initializeDAEmodeData,
   OM_Result_functionODE,
   OM_Result_functionAlgebraics,
   OM_Result_functionDAE,
   OM_Result_functionLocalKnownVars,
   OM_Result_input_function,
   OM_Result_input_function_init,
   OM_Result_input_function_updateStartValues,
   OM_Result_output_function,
   OM_Result_function_storeDelayed,
   OM_Result_updateBoundVariableAttributes,
   OM_Result_functionInitialEquations,
   0, /* useHomotopy - 0: no homotopy or local homotopy, 1: global homotopy, 2: new global homotopy approach */
   OM_Result_functionInitialEquations_lambda0,
   OM_Result_functionRemovedInitialEquations,
   OM_Result_updateBoundParameters,
   OM_Result_checkForAsserts,
   OM_Result_function_ZeroCrossingsEquations,
   OM_Result_function_ZeroCrossings,
   OM_Result_function_updateRelations,
   OM_Result_checkForDiscreteChanges,
   OM_Result_zeroCrossingDescription,
   OM_Result_relationDescription,
   OM_Result_function_initSample,
   OM_Result_INDEX_JAC_A,
   OM_Result_INDEX_JAC_B,
   OM_Result_INDEX_JAC_C,
   OM_Result_INDEX_JAC_D,
   OM_Result_initialAnalyticJacobianA,
   OM_Result_initialAnalyticJacobianB,
   OM_Result_initialAnalyticJacobianC,
   OM_Result_initialAnalyticJacobianD,
   OM_Result_functionJacA_column,
   OM_Result_functionJacB_column,
   OM_Result_functionJacC_column,
   OM_Result_functionJacD_column,
   OM_Result_linear_model_frame,
   OM_Result_linear_model_datarecovery_frame,
   OM_Result_mayer,
   OM_Result_lagrange,
   OM_Result_pickUpBoundsForInputsInOptimization,
   OM_Result_setInputData,
   OM_Result_getTimeGrid,
   OM_Result_symbolicInlineSystem,
   OM_Result_function_initSynchronous,
   OM_Result_function_updateSynchronous,
   OM_Result_function_equationsSynchronous,
   NULL,
   #ifdef FMU_EXPERIMENTAL
   OM_Result_functionODE_Partial,
   OM_Result_functionFMIJacobian,
   #endif
   OM_Result_inputNames
};

void OM_Result_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  data->callback = &OM_Result_callback;
  data->modelData->modelName = "Outfall";
  data->modelData->modelFilePrefix = "OM_Result";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/yunjaeh/github/UQ/MonteCarlo/single-sided/template";
  data->modelData->modelGUID = "{8c4e810f-3df3-4a00-8276-176fa3c9f9e0}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "OM_Result_init.c"
    ;
  static const char contents_info[] =
    #include "OM_Result_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "OM_Result_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "OM_Result_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  
  data->modelData->nStates = 5;
  data->modelData->nVariablesReal = 143;
  data->modelData->nDiscreteReal = 6;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 3;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 105;
  data->modelData->nParametersInteger = 35;
  data->modelData->nParametersBoolean = 10;
  data->modelData->nParametersString = 6;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 256;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 3;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 3;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 3;
  data->modelData->modelDataXml.fileName = "OM_Result_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 9;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 494;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 16;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 20;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  
  data->modelData->nDelayExpressions = 0;
  
  data->modelData->nClocks = 0;
  data->modelData->nSubClocks = 0;
  
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
}

#ifdef __cplusplus
}
#endif

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

#if defined(threadData)
#undef threadData
#endif
/* call the simulation runtime main from our main! */
int main(int argc, char**argv)
{
  int res;
  DATA data;
  MODEL_DATA modelData;
  SIMULATION_INFO simInfo;
  data.modelData = &modelData;
  data.simulationInfo = &simInfo;
  measure_time_flag = 0;
  compiledInDAEMode = 0;
  compiledWithSymSolver = 0;
  MMC_INIT(0);
  omc_alloc_interface.init();
  {
    MMC_TRY_TOP()
  
    MMC_TRY_STACK()
  
    OM_Result_setupDataStruc(&data, threadData);
    res = _main_SimulationRuntime(argc, argv, &data, threadData);
    
    MMC_ELSE()
    rml_execution_failed();
    fprintf(stderr, "Stack overflow detected and was not caught.\nSend us a bug report at https://trac.openmodelica.org/OpenModelica/newticket\n    Include the following trace:\n");
    printStacktraceMessages();
    fflush(NULL);
    return 1;
    MMC_CATCH_STACK()
    
    MMC_CATCH_TOP(return rml_execution_failed());
  }

  fflush(NULL);
  EXIT(res);
  return res;
}


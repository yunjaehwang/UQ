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
 equation index: 195
 type: SIMPLE_ASSIGN
 $whenCondition3 = time >= pre(Data_solar_radiation.nextTimeEvent)
 */
void OM_Result_eqFunction_195(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,195};
  modelica_boolean tmp0;
  RELATIONHYSTERESIS(tmp0, data->localData[0]->timeValue, data->simulationInfo->realVarsPre[137] /* Data_solar_radiation._nextTimeEvent DISCRETE */, 2, GreaterEq);
  data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */ = tmp0;
  TRACE_POP
}
/*
 equation index: 196
 type: SIMPLE_ASSIGN
 $whenCondition2 = time >= pre(Data_outdoor_temperature.nextTimeEvent)
 */
void OM_Result_eqFunction_196(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,196};
  modelica_boolean tmp1;
  RELATIONHYSTERESIS(tmp1, data->localData[0]->timeValue, data->simulationInfo->realVarsPre[135] /* Data_outdoor_temperature._nextTimeEvent DISCRETE */, 1, GreaterEq);
  data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */ = tmp1;
  TRACE_POP
}
/*
 equation index: 197
 type: SIMPLE_ASSIGN
 $whenCondition1 = time >= pre(Data_wind_speed.nextTimeEvent)
 */
void OM_Result_eqFunction_197(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,197};
  modelica_boolean tmp2;
  RELATIONHYSTERESIS(tmp2, data->localData[0]->timeValue, data->simulationInfo->realVarsPre[139] /* Data_wind_speed._nextTimeEvent DISCRETE */, 0, GreaterEq);
  data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ = tmp2;
  TRACE_POP
}
/*
 equation index: 198
 type: SIMPLE_ASSIGN
 Data_wind_speed._timeScaled = 0.01666666666666667 * time
 */
void OM_Result_eqFunction_198(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,198};
  data->localData[0]->realVars[79] /* Data_wind_speed._timeScaled variable */ = (0.01666666666666667) * (data->localData[0]->timeValue);
  TRACE_POP
}
/*
 equation index: 199
 type: WHEN
 
 when {$whenCondition1} then
   Data_wind_speed._nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Data_wind_speed.tableID, Data_wind_speed.timeScaled);
 end when;
 */
void OM_Result_eqFunction_199(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,199};
  if((data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ && !data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */ = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, data->simulationInfo->extObjs[2], data->localData[0]->realVars[79] /* Data_wind_speed._timeScaled variable */);
  }
  TRACE_POP
}
/*
 equation index: 200
 type: WHEN
 
 when {$whenCondition1} then
   Data_wind_speed._nextTimeEvent = if Data_wind_speed.nextTimeEventScaled < 9.999999999999999e+59 then Data_wind_speed.nextTimeEventScaled * 60.0 else 9.999999999999999e+59;
 end when;
 */
void OM_Result_eqFunction_200(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,200};
  modelica_boolean tmp3;
  if((data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ && !data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */ /* edge */))
  {
    tmp3 = Less(data->localData[0]->realVars[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */,9.999999999999999e+59);
    data->localData[0]->realVars[139] /* Data_wind_speed._nextTimeEvent DISCRETE */ = (tmp3?(data->localData[0]->realVars[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */) * (60.0):9.999999999999999e+59);
  }
  TRACE_POP
}
/*
 equation index: 201
 type: SIMPLE_ASSIGN
 $cse6 = Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_wind_speed.tableID, 2, Data_wind_speed.timeScaled, Data_wind_speed.nextTimeEventScaled, pre(Data_wind_speed.nextTimeEventScaled))
 */
void OM_Result_eqFunction_201(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,201};
  data->localData[0]->realVars[15] /* $cse6 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[2], ((modelica_integer) 2), data->localData[0]->realVars[79] /* Data_wind_speed._timeScaled variable */, data->localData[0]->realVars[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
 equation index: 202
 type: SIMPLE_ASSIGN
 Data_wind_speed._y[2] = Data_wind_speed.p_offset[2] + $cse6
 */
void OM_Result_eqFunction_202(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,202};
  data->localData[0]->realVars[81] /* Data_wind_speed._y[2] variable */ = data->simulationInfo->realParameter[46] + data->localData[0]->realVars[15] /* $cse6 variable */;
  TRACE_POP
}
/*
 equation index: 203
 type: SIMPLE_ASSIGN
 $cse5 = Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_wind_speed.tableID, 1, Data_wind_speed.timeScaled, Data_wind_speed.nextTimeEventScaled, pre(Data_wind_speed.nextTimeEventScaled))
 */
void OM_Result_eqFunction_203(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,203};
  data->localData[0]->realVars[14] /* $cse5 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[2], ((modelica_integer) 1), data->localData[0]->realVars[79] /* Data_wind_speed._timeScaled variable */, data->localData[0]->realVars[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[140] /* Data_wind_speed._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
 equation index: 204
 type: SIMPLE_ASSIGN
 Data_wind_speed._y[1] = Data_wind_speed.p_offset[1] + $cse5
 */
void OM_Result_eqFunction_204(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,204};
  data->localData[0]->realVars[80] /* Data_wind_speed._y[1] variable */ = data->simulationInfo->realParameter[45] + data->localData[0]->realVars[14] /* $cse5 variable */;
  TRACE_POP
}
/*
 equation index: 205
 type: SIMPLE_ASSIGN
 $cse7 = Outfall.invWeibull(0.3386, Data_wind_speed.y[1], Data_wind_speed.y[2])
 */
void OM_Result_eqFunction_205(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,205};
  data->localData[0]->realVars[16] /* $cse7 variable */ = omc_Outfall_invWeibull(threadData, 0.3386, data->localData[0]->realVars[80] /* Data_wind_speed._y[1] variable */, data->localData[0]->realVars[81] /* Data_wind_speed._y[2] variable */);
  TRACE_POP
}
/*
 equation index: 206
 type: SIMPLE_ASSIGN
 WindSpeed = max(0.01, $cse7)
 */
void OM_Result_eqFunction_206(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,206};
  data->localData[0]->realVars[112] /* WindSpeed variable */ = fmax(0.01,data->localData[0]->realVars[16] /* $cse7 variable */);
  TRACE_POP
}
/*
 equation index: 207
 type: SIMPLE_ASSIGN
 two_single_ventilation1._U_square._y = WindSpeed ^ 2.0
 */
void OM_Result_eqFunction_207(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,207};
  modelica_real tmp4;
  tmp4 = data->localData[0]->realVars[112] /* WindSpeed variable */;
  data->localData[0]->realVars[122] /* two_single_ventilation1._U_square._y variable */ = (tmp4 * tmp4);
  TRACE_POP
}
/*
 equation index: 208
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum1._u[1] = two_single_ventilation1.C1.k * two_single_ventilation1.U_square.y
 */
void OM_Result_eqFunction_208(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,208};
  data->localData[0]->realVars[130] /* two_single_ventilation1._multiSum1._u[1] variable */ = (data->simulationInfo->realParameter[77]) * (data->localData[0]->realVars[122] /* two_single_ventilation1._U_square._y variable */);
  TRACE_POP
}
/*
 equation index: 209
 type: SIMPLE_ASSIGN
 log1._y = log(WindSpeed)
 */
void OM_Result_eqFunction_209(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,209};
  modelica_real tmp5;
  tmp5 = data->localData[0]->realVars[112] /* WindSpeed variable */;
  if(!(tmp5 > 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of log(WindSpeed) was %g should be > 0", tmp5);
  }
  data->localData[0]->realVars[115] /* log1._y variable */ = log(tmp5);
  TRACE_POP
}
/*
 equation index: 210
 type: SIMPLE_ASSIGN
 exp1._u = log1.y * Convection_B.k
 */
void OM_Result_eqFunction_210(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,210};
  data->localData[0]->realVars[113] /* exp1._u variable */ = (data->localData[0]->realVars[115] /* log1._y variable */) * (data->simulationInfo->realParameter[18]);
  TRACE_POP
}
/*
 equation index: 211
 type: SIMPLE_ASSIGN
 exp1._y = exp(exp1.u)
 */
void OM_Result_eqFunction_211(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,211};
  data->localData[0]->realVars[114] /* exp1._y variable */ = exp(data->localData[0]->realVars[113] /* exp1._u variable */);
  TRACE_POP
}
/*
 equation index: 212
 type: SIMPLE_ASSIGN
 product4._y = exp1.y * Convection_A.k
 */
void OM_Result_eqFunction_212(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,212};
  data->localData[0]->realVars[117] /* product4._y variable */ = (data->localData[0]->realVars[114] /* exp1._y variable */) * (data->simulationInfo->realParameter[17]);
  TRACE_POP
}
/*
 equation index: 213
 type: SIMPLE_ASSIGN
 Convection_roof_outer._Gc = Area_roof.k * product4.y
 */
void OM_Result_eqFunction_213(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,213};
  data->localData[0]->realVars[55] /* Convection_roof_outer._Gc variable */ = (data->simulationInfo->realParameter[0]) * (data->localData[0]->realVars[117] /* product4._y variable */);
  TRACE_POP
}
/*
 equation index: 214
 type: SIMPLE_ASSIGN
 Convection_wall1_outer._Gc = Area_wall1.k * product4.y
 */
void OM_Result_eqFunction_214(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,214};
  data->localData[0]->realVars[60] /* Convection_wall1_outer._Gc variable */ = (data->simulationInfo->realParameter[1]) * (data->localData[0]->realVars[117] /* product4._y variable */);
  TRACE_POP
}
/*
 equation index: 215
 type: SIMPLE_ASSIGN
 Convection_wall3_outer._Gc = Area_wall3.k * product4.y
 */
void OM_Result_eqFunction_215(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,215};
  data->localData[0]->realVars[65] /* Convection_wall3_outer._Gc variable */ = (data->simulationInfo->realParameter[2]) * (data->localData[0]->realVars[117] /* product4._y variable */);
  TRACE_POP
}
/*
 equation index: 216
 type: SIMPLE_ASSIGN
 Convection_wall4_outer._Gc = Area_wall4.k * product4.y
 */
void OM_Result_eqFunction_216(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,216};
  data->localData[0]->realVars[70] /* Convection_wall4_outer._Gc variable */ = (data->simulationInfo->realParameter[3]) * (data->localData[0]->realVars[117] /* product4._y variable */);
  TRACE_POP
}
/*
 equation index: 217
 type: SIMPLE_ASSIGN
 Radiation_floor._dT = Floor_temperature.k - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_217(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,217};
  data->localData[0]->realVars[88] /* Radiation_floor._dT variable */ = data->simulationInfo->realParameter[54] - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 218
 type: SIMPLE_ASSIGN
 Radiation_floor._Q_flow = 5.670367e-08 * Radiation_floor.Gr * (Floor_temperature.k ^ 4.0 - Capacitor_indoor_air.T ^ 4.0)
 */
void OM_Result_eqFunction_218(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,218};
  modelica_real tmp6;
  modelica_real tmp7;
  tmp6 = data->simulationInfo->realParameter[54];
  tmp6 *= tmp6;tmp7 = data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  tmp7 *= tmp7;
  data->localData[0]->realVars[87] /* Radiation_floor._Q_flow variable */ = (5.670367e-08) * ((data->simulationInfo->realParameter[60]) * ((tmp6 * tmp6) - ((tmp7 * tmp7))));
  TRACE_POP
}
/*
 equation index: 219
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._timeScaled = 0.01666666666666667 * time
 */
void OM_Result_eqFunction_219(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,219};
  data->localData[0]->realVars[73] /* Data_outdoor_temperature._timeScaled variable */ = (0.01666666666666667) * (data->localData[0]->timeValue);
  TRACE_POP
}
/*
 equation index: 220
 type: WHEN
 
 when {$whenCondition2} then
   Data_outdoor_temperature._nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Data_outdoor_temperature.tableID, Data_outdoor_temperature.timeScaled);
 end when;
 */
void OM_Result_eqFunction_220(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,220};
  if((data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */ && !data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */ = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, data->simulationInfo->extObjs[0], data->localData[0]->realVars[73] /* Data_outdoor_temperature._timeScaled variable */);
  }
  TRACE_POP
}
/*
 equation index: 221
 type: WHEN
 
 when {$whenCondition2} then
   Data_outdoor_temperature._nextTimeEvent = if Data_outdoor_temperature.nextTimeEventScaled < 9.999999999999999e+59 then Data_outdoor_temperature.nextTimeEventScaled * 60.0 else 9.999999999999999e+59;
 end when;
 */
void OM_Result_eqFunction_221(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,221};
  modelica_boolean tmp8;
  if((data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */ && !data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */ /* edge */))
  {
    tmp8 = Less(data->localData[0]->realVars[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */,9.999999999999999e+59);
    data->localData[0]->realVars[135] /* Data_outdoor_temperature._nextTimeEvent DISCRETE */ = (tmp8?(data->localData[0]->realVars[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */) * (60.0):9.999999999999999e+59);
  }
  TRACE_POP
}
/*
 equation index: 222
 type: SIMPLE_ASSIGN
 $cse4 = Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_outdoor_temperature.tableID, 2, Data_outdoor_temperature.timeScaled, Data_outdoor_temperature.nextTimeEventScaled, pre(Data_outdoor_temperature.nextTimeEventScaled))
 */
void OM_Result_eqFunction_222(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,222};
  data->localData[0]->realVars[13] /* $cse4 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 2), data->localData[0]->realVars[73] /* Data_outdoor_temperature._timeScaled variable */, data->localData[0]->realVars[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
 equation index: 223
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._y[2] = Data_outdoor_temperature.p_offset[2] + $cse4
 */
void OM_Result_eqFunction_223(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,223};
  data->localData[0]->realVars[75] /* Data_outdoor_temperature._y[2] variable */ = data->simulationInfo->realParameter[26] + data->localData[0]->realVars[13] /* $cse4 variable */;
  TRACE_POP
}
/*
 equation index: 224
 type: SIMPLE_ASSIGN
 $cse3 = Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_outdoor_temperature.tableID, 1, Data_outdoor_temperature.timeScaled, Data_outdoor_temperature.nextTimeEventScaled, pre(Data_outdoor_temperature.nextTimeEventScaled))
 */
void OM_Result_eqFunction_224(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,224};
  data->localData[0]->realVars[12] /* $cse3 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 1), data->localData[0]->realVars[73] /* Data_outdoor_temperature._timeScaled variable */, data->localData[0]->realVars[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[136] /* Data_outdoor_temperature._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
 equation index: 225
 type: SIMPLE_ASSIGN
 Data_outdoor_temperature._y[1] = Data_outdoor_temperature.p_offset[1] + $cse3
 */
void OM_Result_eqFunction_225(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,225};
  data->localData[0]->realVars[74] /* Data_outdoor_temperature._y[1] variable */ = data->simulationInfo->realParameter[25] + data->localData[0]->realVars[12] /* $cse3 variable */;
  TRACE_POP
}
/*
 equation index: 226
 type: SIMPLE_ASSIGN
 OutdoorTemperature = Outfall.invNormal(0.47349, Data_outdoor_temperature.y[1], Data_outdoor_temperature.y[2])
 */
void OM_Result_eqFunction_226(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,226};
  data->localData[0]->realVars[85] /* OutdoorTemperature variable */ = omc_Outfall_invNormal(threadData, 0.47349, data->localData[0]->realVars[74] /* Data_outdoor_temperature._y[1] variable */, data->localData[0]->realVars[75] /* Data_outdoor_temperature._y[2] variable */);
  TRACE_POP
}
/*
 equation index: 227
 type: SIMPLE_ASSIGN
 multiProduct1._u[2] = sqrt(OutdoorTemperature)
 */
void OM_Result_eqFunction_227(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,227};
  modelica_real tmp9;
  tmp9 = data->localData[0]->realVars[85] /* OutdoorTemperature variable */;
  if(!(tmp9 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(OutdoorTemperature) was %g should be >= 0", tmp9);
  }
  data->localData[0]->realVars[116] /* multiProduct1._u[2] variable */ = sqrt(tmp9);
  TRACE_POP
}
/*
 equation index: 228
 type: SIMPLE_ASSIGN
 SkyTemperatureToK._T = const.k * multiProduct1.u[2] * OutdoorTemperature
 */
void OM_Result_eqFunction_228(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,228};
  data->localData[0]->realVars[107] /* SkyTemperatureToK._T variable */ = (data->simulationInfo->realParameter[72]) * ((data->localData[0]->realVars[116] /* multiProduct1._u[2] variable */) * (data->localData[0]->realVars[85] /* OutdoorTemperature variable */));
  TRACE_POP
}
/*
 equation index: 229
 type: SIMPLE_ASSIGN
 Temperature_difference._y = Temperature_difference.k1 * OutdoorTemperature + Temperature_difference.k2 * Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_229(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,229};
  data->localData[0]->realVars[110] /* Temperature_difference._y variable */ = (data->simulationInfo->realParameter[70]) * (data->localData[0]->realVars[85] /* OutdoorTemperature variable */) + (data->simulationInfo->realParameter[71]) * (data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */);
  TRACE_POP
}
/*
 equation index: 230
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct5._u[3] = two_single_ventilation1.add1.k1 * OutdoorTemperature + two_single_ventilation1.add1.k2 * Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_230(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,230};
  data->localData[0]->realVars[129] /* two_single_ventilation1._multiProduct5._u[3] variable */ = (data->simulationInfo->realParameter[87]) * (data->localData[0]->realVars[85] /* OutdoorTemperature variable */) + (data->simulationInfo->realParameter[88]) * (data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */);
  TRACE_POP
}
/*
 equation index: 231
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct1._u[3] = if noEvent(two_single_ventilation1.multiProduct5.u[3] >= 0.0) then two_single_ventilation1.multiProduct5.u[3] else -two_single_ventilation1.multiProduct5.u[3]
 */
void OM_Result_eqFunction_231(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,231};
  modelica_boolean tmp10;
  tmp10 = GreaterEq(data->localData[0]->realVars[129] /* two_single_ventilation1._multiProduct5._u[3] variable */,0.0);
  data->localData[0]->realVars[125] /* two_single_ventilation1._multiProduct1._u[3] variable */ = (tmp10?data->localData[0]->realVars[129] /* two_single_ventilation1._multiProduct5._u[3] variable */:(-data->localData[0]->realVars[129] /* two_single_ventilation1._multiProduct5._u[3] variable */));
  TRACE_POP
}
/*
 equation index: 232
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum1._u[2] = two_single_ventilation1.C2.k * two_single_ventilation1.Height_1.k * two_single_ventilation1.multiProduct1.u[3]
 */
void OM_Result_eqFunction_232(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,232};
  data->localData[0]->realVars[131] /* two_single_ventilation1._multiSum1._u[2] variable */ = (data->simulationInfo->realParameter[78]) * ((data->simulationInfo->realParameter[82]) * (data->localData[0]->realVars[125] /* two_single_ventilation1._multiProduct1._u[3] variable */));
  TRACE_POP
}
/*
 equation index: 233
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum1._y = two_single_ventilation1.multiSum1.k[1] * two_single_ventilation1.multiSum1.u[1] + two_single_ventilation1.multiSum1.k[2] * two_single_ventilation1.multiSum1.u[2] + two_single_ventilation1.multiSum1.k[3] * two_single_ventilation1.C3.k
 */
void OM_Result_eqFunction_233(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,233};
  data->localData[0]->realVars[132] /* two_single_ventilation1._multiSum1._y variable */ = (data->simulationInfo->realParameter[90]) * (data->localData[0]->realVars[130] /* two_single_ventilation1._multiSum1._u[1] variable */) + (data->simulationInfo->realParameter[91]) * (data->localData[0]->realVars[131] /* two_single_ventilation1._multiSum1._u[2] variable */) + (data->simulationInfo->realParameter[92]) * (data->simulationInfo->realParameter[79]);
  TRACE_POP
}
/*
 equation index: 234
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct3._u[3] = sqrt(two_single_ventilation1.multiSum1.y)
 */
void OM_Result_eqFunction_234(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,234};
  modelica_real tmp11;
  tmp11 = data->localData[0]->realVars[132] /* two_single_ventilation1._multiSum1._y variable */;
  if(!(tmp11 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(two_single_ventilation1.multiSum1.y) was %g should be >= 0", tmp11);
  }
  data->localData[0]->realVars[126] /* two_single_ventilation1._multiProduct3._u[3] variable */ = sqrt(tmp11);
  TRACE_POP
}
/*
 equation index: 235
 type: SIMPLE_ASSIGN
 two_single_ventilation1._Ventilation_rate._u1 = two_single_ventilation1.const.k * two_single_ventilation1.Area_1.k * two_single_ventilation1.multiProduct3.u[3]
 */
void OM_Result_eqFunction_235(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,235};
  data->localData[0]->realVars[123] /* two_single_ventilation1._Ventilation_rate._u1 variable */ = (data->simulationInfo->realParameter[89]) * ((data->simulationInfo->realParameter[75]) * (data->localData[0]->realVars[126] /* two_single_ventilation1._multiProduct3._u[3] variable */));
  TRACE_POP
}
/*
 equation index: 236
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum2._u[2] = two_single_ventilation1.C2.k * two_single_ventilation1.Height_2.k * two_single_ventilation1.multiProduct1.u[3]
 */
void OM_Result_eqFunction_236(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,236};
  data->localData[0]->realVars[133] /* two_single_ventilation1._multiSum2._u[2] variable */ = (data->simulationInfo->realParameter[78]) * ((data->simulationInfo->realParameter[83]) * (data->localData[0]->realVars[125] /* two_single_ventilation1._multiProduct1._u[3] variable */));
  TRACE_POP
}
/*
 equation index: 237
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiSum2._y = two_single_ventilation1.multiSum2.k[1] * two_single_ventilation1.multiSum1.u[1] + two_single_ventilation1.multiSum2.k[2] * two_single_ventilation1.multiSum2.u[2] + two_single_ventilation1.multiSum2.k[3] * two_single_ventilation1.C3.k
 */
void OM_Result_eqFunction_237(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,237};
  data->localData[0]->realVars[134] /* two_single_ventilation1._multiSum2._y variable */ = (data->simulationInfo->realParameter[93]) * (data->localData[0]->realVars[130] /* two_single_ventilation1._multiSum1._u[1] variable */) + (data->simulationInfo->realParameter[94]) * (data->localData[0]->realVars[133] /* two_single_ventilation1._multiSum2._u[2] variable */) + (data->simulationInfo->realParameter[95]) * (data->simulationInfo->realParameter[79]);
  TRACE_POP
}
/*
 equation index: 238
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct4._u[3] = sqrt(two_single_ventilation1.multiSum2.y)
 */
void OM_Result_eqFunction_238(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,238};
  modelica_real tmp12;
  tmp12 = data->localData[0]->realVars[134] /* two_single_ventilation1._multiSum2._y variable */;
  if(!(tmp12 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(two_single_ventilation1.multiSum2.y) was %g should be >= 0", tmp12);
  }
  data->localData[0]->realVars[127] /* two_single_ventilation1._multiProduct4._u[3] variable */ = sqrt(tmp12);
  TRACE_POP
}
/*
 equation index: 239
 type: SIMPLE_ASSIGN
 two_single_ventilation1._Ventilation_rate._u2 = two_single_ventilation1.const.k * two_single_ventilation1.Area_2.k * two_single_ventilation1.multiProduct4.u[3]
 */
void OM_Result_eqFunction_239(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,239};
  data->localData[0]->realVars[124] /* two_single_ventilation1._Ventilation_rate._u2 variable */ = (data->simulationInfo->realParameter[89]) * ((data->simulationInfo->realParameter[76]) * (data->localData[0]->realVars[127] /* two_single_ventilation1._multiProduct4._u[3] variable */));
  TRACE_POP
}
/*
 equation index: 240
 type: SIMPLE_ASSIGN
 two_single_ventilation1._multiProduct5._u[2] = two_single_ventilation1.Ventilation_rate.k1 * two_single_ventilation1.Ventilation_rate.u1 + two_single_ventilation1.Ventilation_rate.k2 * two_single_ventilation1.Ventilation_rate.u2
 */
void OM_Result_eqFunction_240(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,240};
  data->localData[0]->realVars[128] /* two_single_ventilation1._multiProduct5._u[2] variable */ = (data->simulationInfo->realParameter[85]) * (data->localData[0]->realVars[123] /* two_single_ventilation1._Ventilation_rate._u1 variable */) + (data->simulationInfo->realParameter[86]) * (data->localData[0]->realVars[124] /* two_single_ventilation1._Ventilation_rate._u2 variable */);
  TRACE_POP
}
/*
 equation index: 241
 type: SIMPLE_ASSIGN
 two_single_ventilation1._Heat_flow_NV._Q_flow = two_single_ventilation1.Ventilation_param.k * two_single_ventilation1.multiProduct5.u[2] * two_single_ventilation1.multiProduct5.u[3]
 */
void OM_Result_eqFunction_241(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,241};
  data->localData[0]->realVars[120] /* two_single_ventilation1._Heat_flow_NV._Q_flow variable */ = (data->simulationInfo->realParameter[84]) * ((data->localData[0]->realVars[128] /* two_single_ventilation1._multiProduct5._u[2] variable */) * (data->localData[0]->realVars[129] /* two_single_ventilation1._multiProduct5._u[3] variable */));
  TRACE_POP
}
/*
 equation index: 242
 type: SIMPLE_ASSIGN
 thermalCollector1._port_a[11]._Q_flow = two_single_ventilation1.Heat_flow_NV.Q_flow * (1.0 + two_single_ventilation1.Heat_flow_NV.alpha * (Capacitor_indoor_air.T - two_single_ventilation1.Heat_flow_NV.T_ref))
 */
void OM_Result_eqFunction_242(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,242};
  data->localData[0]->realVars[118] /* thermalCollector1._port_a[11]._Q_flow variable */ = (data->localData[0]->realVars[120] /* two_single_ventilation1._Heat_flow_NV._Q_flow variable */) * (1.0 + (data->simulationInfo->realParameter[81]) * (data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */ - data->simulationInfo->realParameter[80]));
  TRACE_POP
}
/*
 equation index: 243
 type: SIMPLE_ASSIGN
 Data_solar_radiation._timeScaled = 0.01666666666666667 * time
 */
void OM_Result_eqFunction_243(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,243};
  data->localData[0]->realVars[76] /* Data_solar_radiation._timeScaled variable */ = (0.01666666666666667) * (data->localData[0]->timeValue);
  TRACE_POP
}
/*
 equation index: 244
 type: WHEN
 
 when {$whenCondition3} then
   Data_solar_radiation._nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Data_solar_radiation.tableID, Data_solar_radiation.timeScaled);
 end when;
 */
void OM_Result_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
  if((data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */ && !data->simulationInfo->booleanVarsPre[2] /* $whenCondition3 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */ = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, data->simulationInfo->extObjs[1], data->localData[0]->realVars[76] /* Data_solar_radiation._timeScaled variable */);
  }
  TRACE_POP
}
/*
 equation index: 245
 type: WHEN
 
 when {$whenCondition3} then
   Data_solar_radiation._nextTimeEvent = if Data_solar_radiation.nextTimeEventScaled < 9.999999999999999e+59 then Data_solar_radiation.nextTimeEventScaled * 60.0 else 9.999999999999999e+59;
 end when;
 */
void OM_Result_eqFunction_245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,245};
  modelica_boolean tmp13;
  if((data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */ && !data->simulationInfo->booleanVarsPre[2] /* $whenCondition3 DISCRETE */ /* edge */))
  {
    tmp13 = Less(data->localData[0]->realVars[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */,9.999999999999999e+59);
    data->localData[0]->realVars[137] /* Data_solar_radiation._nextTimeEvent DISCRETE */ = (tmp13?(data->localData[0]->realVars[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */) * (60.0):9.999999999999999e+59);
  }
  TRACE_POP
}
/*
 equation index: 246
 type: SIMPLE_ASSIGN
 $cse2 = Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_solar_radiation.tableID, 2, Data_solar_radiation.timeScaled, Data_solar_radiation.nextTimeEventScaled, pre(Data_solar_radiation.nextTimeEventScaled))
 */
void OM_Result_eqFunction_246(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,246};
  data->localData[0]->realVars[11] /* $cse2 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[1], ((modelica_integer) 2), data->localData[0]->realVars[76] /* Data_solar_radiation._timeScaled variable */, data->localData[0]->realVars[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
 equation index: 247
 type: SIMPLE_ASSIGN
 Data_solar_radiation._y[2] = Data_solar_radiation.p_offset[2] + $cse2
 */
void OM_Result_eqFunction_247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,247};
  data->localData[0]->realVars[78] /* Data_solar_radiation._y[2] variable */ = data->simulationInfo->realParameter[36] + data->localData[0]->realVars[11] /* $cse2 variable */;
  TRACE_POP
}
/*
 equation index: 248
 type: SIMPLE_ASSIGN
 $cse1 = Modelica.Blocks.Tables.Internal.getTimeTableValue(Data_solar_radiation.tableID, 1, Data_solar_radiation.timeScaled, Data_solar_radiation.nextTimeEventScaled, pre(Data_solar_radiation.nextTimeEventScaled))
 */
void OM_Result_eqFunction_248(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,248};
  data->localData[0]->realVars[10] /* $cse1 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[1], ((modelica_integer) 1), data->localData[0]->realVars[76] /* Data_solar_radiation._timeScaled variable */, data->localData[0]->realVars[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[138] /* Data_solar_radiation._nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
 equation index: 249
 type: SIMPLE_ASSIGN
 Data_solar_radiation._y[1] = Data_solar_radiation.p_offset[1] + $cse1
 */
void OM_Result_eqFunction_249(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,249};
  data->localData[0]->realVars[77] /* Data_solar_radiation._y[1] variable */ = data->simulationInfo->realParameter[35] + data->localData[0]->realVars[10] /* $cse1 variable */;
  TRACE_POP
}
/*
 equation index: 250
 type: SIMPLE_ASSIGN
 SolarRadiation = Outfall.invUniform(0.41438, Data_solar_radiation.y[1], Data_solar_radiation.y[2])
 */
void OM_Result_eqFunction_250(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,250};
  data->localData[0]->realVars[108] /* SolarRadiation variable */ = omc_Outfall_invUniform(threadData, 0.41438, data->localData[0]->realVars[77] /* Data_solar_radiation._y[1] variable */, data->localData[0]->realVars[78] /* Data_solar_radiation._y[2] variable */);
  TRACE_POP
}
/*
 equation index: 251
 type: SIMPLE_ASSIGN
 Heatflow_solar_radiation._Q_flow = SolarRadiation * roof_emissivity.k
 */
void OM_Result_eqFunction_251(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,251};
  data->localData[0]->realVars[83] /* Heatflow_solar_radiation._Q_flow variable */ = (data->localData[0]->realVars[108] /* SolarRadiation variable */) * (data->simulationInfo->realParameter[74]);
  TRACE_POP
}
/*
 equation index: 252
 type: SIMPLE_ASSIGN
 Heatflow_infiltration._Q_flow = Temperature_difference.y * Infiltration.k
 */
void OM_Result_eqFunction_252(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,252};
  data->localData[0]->realVars[82] /* Heatflow_infiltration._Q_flow variable */ = (data->localData[0]->realVars[110] /* Temperature_difference._y variable */) * (data->simulationInfo->realParameter[59]);
  TRACE_POP
}
/*
 equation index: 253
 type: SIMPLE_ASSIGN
 thermalCollector1._port_a[12]._Q_flow = Heatflow_infiltration.Q_flow * (1.0 + Heatflow_infiltration.alpha * (Capacitor_indoor_air.T - Heatflow_infiltration.T_ref))
 */
void OM_Result_eqFunction_253(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,253};
  data->localData[0]->realVars[119] /* thermalCollector1._port_a[12]._Q_flow variable */ = (data->localData[0]->realVars[82] /* Heatflow_infiltration._Q_flow variable */) * (1.0 + (data->simulationInfo->realParameter[56]) * (data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */ - data->simulationInfo->realParameter[55]));
  TRACE_POP
}
/*
 equation index: 254
 type: SIMPLE_ASSIGN
 Convection_floor._dT = Floor_temperature.k - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_254(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,254};
  data->localData[0]->realVars[52] /* Convection_floor._dT variable */ = data->simulationInfo->realParameter[54] - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 255
 type: SIMPLE_ASSIGN
 Convection_floor._Q_flow = Convection_coef_floor.k * Convection_floor.dT
 */
void OM_Result_eqFunction_255(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,255};
  data->localData[0]->realVars[51] /* Convection_floor._Q_flow variable */ = (data->simulationInfo->realParameter[19]) * (data->localData[0]->realVars[52] /* Convection_floor._dT variable */);
  TRACE_POP
}
void OM_Result_eqFunction_256(DATA*,threadData_t*);
void OM_Result_eqFunction_257(DATA*,threadData_t*);
void OM_Result_eqFunction_258(DATA*,threadData_t*);
void OM_Result_eqFunction_259(DATA*,threadData_t*);
void OM_Result_eqFunction_260(DATA*,threadData_t*);
void OM_Result_eqFunction_261(DATA*,threadData_t*);
/*
 equation index: 267
 indexNonlinear: 8
 type: NONLINEAR
 
 vars: {Conduction_wall4_inner._port_b._T}
 eqns: {256, 257, 258, 259, 260, 261}
 */
void OM_Result_eqFunction_267(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,267};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 267 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[8].nlsxOld[0] = data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 8);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,267};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 267 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */ = data->simulationInfo->nonlinearSystemData[8].nlsx[0];
  TRACE_POP
}
/*
 equation index: 268
 type: SIMPLE_ASSIGN
 Radiation_wall4_inner._dT = Conduction_wall4_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_268(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,268};
  data->localData[0]->realVars[104] /* Radiation_wall4_inner._dT variable */ = data->localData[0]->realVars[47] /* Conduction_wall4_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
void OM_Result_eqFunction_269(DATA*,threadData_t*);
void OM_Result_eqFunction_270(DATA*,threadData_t*);
void OM_Result_eqFunction_271(DATA*,threadData_t*);
void OM_Result_eqFunction_272(DATA*,threadData_t*);
void OM_Result_eqFunction_273(DATA*,threadData_t*);
void OM_Result_eqFunction_274(DATA*,threadData_t*);
/*
 equation index: 280
 indexNonlinear: 9
 type: NONLINEAR
 
 vars: {Conduction_wall4_outer._port_a._T}
 eqns: {269, 270, 271, 272, 273, 274}
 */
void OM_Result_eqFunction_280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,280};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 280 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[9].nlsxOld[0] = data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 9);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,280};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 280 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */ = data->simulationInfo->nonlinearSystemData[9].nlsx[0];
  TRACE_POP
}
/*
 equation index: 281
 type: SIMPLE_ASSIGN
 Capacitor_wall4._port._Q_flow = Conduction_wall4_outer.Q_flow - Conduction_wall4_inner.Q_flow
 */
void OM_Result_eqFunction_281(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,281};
  data->localData[0]->realVars[26] /* Capacitor_wall4._port._Q_flow variable */ = data->localData[0]->realVars[48] /* Conduction_wall4_outer._Q_flow variable */ - data->localData[0]->realVars[45] /* Conduction_wall4_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 282
 type: SIMPLE_ASSIGN
 Capacitor_wall4._der_T = DIVISION(Capacitor_wall4.port.Q_flow, Capacitor_wall4.C)
 */
void OM_Result_eqFunction_282(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,282};
  data->localData[0]->realVars[25] /* Capacitor_wall4._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[26] /* Capacitor_wall4._port._Q_flow variable */,data->simulationInfo->realParameter[8],"Capacitor_wall4.C",equationIndexes);
  TRACE_POP
}
/*
 equation index: 283
 type: SIMPLE_ASSIGN
 der(Capacitor_wall4._T) = Capacitor_wall4.der_T
 */
void OM_Result_eqFunction_283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,283};
  data->localData[0]->realVars[9] /* der(Capacitor_wall4._T) STATE_DER */ = data->localData[0]->realVars[25] /* Capacitor_wall4._der_T variable */;
  TRACE_POP
}
/*
 equation index: 284
 type: SIMPLE_ASSIGN
 Radiation_wall4_outer._dT = OutdoorTemperature - Conduction_wall4_outer.port_a.T
 */
void OM_Result_eqFunction_284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,284};
  data->localData[0]->realVars[106] /* Radiation_wall4_outer._dT variable */ = data->localData[0]->realVars[85] /* OutdoorTemperature variable */ - data->localData[0]->realVars[50] /* Conduction_wall4_outer._port_a._T variable */;
  TRACE_POP
}
void OM_Result_eqFunction_285(DATA*,threadData_t*);
void OM_Result_eqFunction_286(DATA*,threadData_t*);
void OM_Result_eqFunction_287(DATA*,threadData_t*);
void OM_Result_eqFunction_288(DATA*,threadData_t*);
void OM_Result_eqFunction_289(DATA*,threadData_t*);
void OM_Result_eqFunction_290(DATA*,threadData_t*);
/*
 equation index: 296
 indexNonlinear: 10
 type: NONLINEAR
 
 vars: {Conduction_wall3_inner._port_b._T}
 eqns: {285, 286, 287, 288, 289, 290}
 */
void OM_Result_eqFunction_296(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,296};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 296 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[10].nlsxOld[0] = data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 10);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,296};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 296 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */ = data->simulationInfo->nonlinearSystemData[10].nlsx[0];
  TRACE_POP
}
/*
 equation index: 297
 type: SIMPLE_ASSIGN
 Radiation_wall3_inner._dT = Conduction_wall3_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_297(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,297};
  data->localData[0]->realVars[100] /* Radiation_wall3_inner._dT variable */ = data->localData[0]->realVars[41] /* Conduction_wall3_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
void OM_Result_eqFunction_298(DATA*,threadData_t*);
void OM_Result_eqFunction_299(DATA*,threadData_t*);
void OM_Result_eqFunction_300(DATA*,threadData_t*);
void OM_Result_eqFunction_301(DATA*,threadData_t*);
void OM_Result_eqFunction_302(DATA*,threadData_t*);
void OM_Result_eqFunction_303(DATA*,threadData_t*);
/*
 equation index: 309
 indexNonlinear: 11
 type: NONLINEAR
 
 vars: {Conduction_wall3_outer._port_a._T}
 eqns: {298, 299, 300, 301, 302, 303}
 */
void OM_Result_eqFunction_309(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,309};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 309 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[11].nlsxOld[0] = data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 11);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,309};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 309 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */ = data->simulationInfo->nonlinearSystemData[11].nlsx[0];
  TRACE_POP
}
/*
 equation index: 310
 type: SIMPLE_ASSIGN
 Capacitor_wall3._port._Q_flow = Conduction_wall3_outer.Q_flow - Conduction_wall3_inner.Q_flow
 */
void OM_Result_eqFunction_310(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,310};
  data->localData[0]->realVars[24] /* Capacitor_wall3._port._Q_flow variable */ = data->localData[0]->realVars[42] /* Conduction_wall3_outer._Q_flow variable */ - data->localData[0]->realVars[39] /* Conduction_wall3_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 311
 type: SIMPLE_ASSIGN
 Capacitor_wall3._der_T = DIVISION(Capacitor_wall3.port.Q_flow, Capacitor_wall3.C)
 */
void OM_Result_eqFunction_311(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,311};
  data->localData[0]->realVars[23] /* Capacitor_wall3._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[24] /* Capacitor_wall3._port._Q_flow variable */,data->simulationInfo->realParameter[7],"Capacitor_wall3.C",equationIndexes);
  TRACE_POP
}
/*
 equation index: 312
 type: SIMPLE_ASSIGN
 der(Capacitor_wall3._T) = Capacitor_wall3.der_T
 */
void OM_Result_eqFunction_312(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,312};
  data->localData[0]->realVars[8] /* der(Capacitor_wall3._T) STATE_DER */ = data->localData[0]->realVars[23] /* Capacitor_wall3._der_T variable */;
  TRACE_POP
}
/*
 equation index: 313
 type: SIMPLE_ASSIGN
 Radiation_wall3_outer._dT = OutdoorTemperature - Conduction_wall3_outer.port_a.T
 */
void OM_Result_eqFunction_313(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,313};
  data->localData[0]->realVars[102] /* Radiation_wall3_outer._dT variable */ = data->localData[0]->realVars[85] /* OutdoorTemperature variable */ - data->localData[0]->realVars[44] /* Conduction_wall3_outer._port_a._T variable */;
  TRACE_POP
}
void OM_Result_eqFunction_314(DATA*,threadData_t*);
void OM_Result_eqFunction_315(DATA*,threadData_t*);
void OM_Result_eqFunction_316(DATA*,threadData_t*);
void OM_Result_eqFunction_317(DATA*,threadData_t*);
void OM_Result_eqFunction_318(DATA*,threadData_t*);
void OM_Result_eqFunction_319(DATA*,threadData_t*);
void OM_Result_eqFunction_320(DATA*,threadData_t*);
/*
 equation index: 327
 indexNonlinear: 12
 type: NONLINEAR
 
 vars: {Conduction_roof_inner._port_b._T}
 eqns: {314, 315, 316, 317, 318, 319, 320}
 */
void OM_Result_eqFunction_327(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,327};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 327 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[12].nlsxOld[0] = data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 12);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,327};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 327 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */ = data->simulationInfo->nonlinearSystemData[12].nlsx[0];
  TRACE_POP
}
/*
 equation index: 328
 type: SIMPLE_ASSIGN
 Radiation_roof_inner._dT = Conduction_roof_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_328(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,328};
  data->localData[0]->realVars[90] /* Radiation_roof_inner._dT variable */ = data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 329
 type: SIMPLE_ASSIGN
 Temperature_floor._port._Q_flow = Radiation_roof_to_floor.Q_flow - (Convection_floor.Q_flow + Radiation_floor.Q_flow)
 */
void OM_Result_eqFunction_329(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,329};
  data->localData[0]->realVars[111] /* Temperature_floor._port._Q_flow variable */ = data->localData[0]->realVars[93] /* Radiation_roof_to_floor._Q_flow variable */ - (data->localData[0]->realVars[51] /* Convection_floor._Q_flow variable */ + data->localData[0]->realVars[87] /* Radiation_floor._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 330
 type: SIMPLE_ASSIGN
 Radiation_roof_to_floor._dT = Conduction_roof_inner.port_b.T - Floor_temperature.k
 */
void OM_Result_eqFunction_330(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,330};
  data->localData[0]->realVars[94] /* Radiation_roof_to_floor._dT variable */ = data->localData[0]->realVars[29] /* Conduction_roof_inner._port_b._T variable */ - data->simulationInfo->realParameter[54];
  TRACE_POP
}
void OM_Result_eqFunction_331(DATA*,threadData_t*);
void OM_Result_eqFunction_332(DATA*,threadData_t*);
void OM_Result_eqFunction_333(DATA*,threadData_t*);
void OM_Result_eqFunction_334(DATA*,threadData_t*);
void OM_Result_eqFunction_335(DATA*,threadData_t*);
void OM_Result_eqFunction_336(DATA*,threadData_t*);
void OM_Result_eqFunction_337(DATA*,threadData_t*);
/*
 equation index: 344
 indexNonlinear: 13
 type: NONLINEAR
 
 vars: {Conduction_roof_outer._port_a._T}
 eqns: {331, 332, 333, 334, 335, 336, 337}
 */
void OM_Result_eqFunction_344(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,344};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 344 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[13].nlsxOld[0] = data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 13);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,344};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 344 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */ = data->simulationInfo->nonlinearSystemData[13].nlsx[0];
  TRACE_POP
}
/*
 equation index: 345
 type: SIMPLE_ASSIGN
 Capacitor_roof._port._Q_flow = Conduction_roof_outer.Q_flow - Conduction_roof_inner.Q_flow
 */
void OM_Result_eqFunction_345(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,345};
  data->localData[0]->realVars[20] /* Capacitor_roof._port._Q_flow variable */ = data->localData[0]->realVars[30] /* Conduction_roof_outer._Q_flow variable */ - data->localData[0]->realVars[27] /* Conduction_roof_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 346
 type: SIMPLE_ASSIGN
 Capacitor_roof._der_T = DIVISION(Capacitor_roof.port.Q_flow, Capacitor_roof.C)
 */
void OM_Result_eqFunction_346(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,346};
  data->localData[0]->realVars[19] /* Capacitor_roof._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[20] /* Capacitor_roof._port._Q_flow variable */,data->simulationInfo->realParameter[5],"Capacitor_roof.C",equationIndexes);
  TRACE_POP
}
/*
 equation index: 347
 type: SIMPLE_ASSIGN
 der(Capacitor_roof._T) = Capacitor_roof.der_T
 */
void OM_Result_eqFunction_347(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,347};
  data->localData[0]->realVars[6] /* der(Capacitor_roof._T) STATE_DER */ = data->localData[0]->realVars[19] /* Capacitor_roof._der_T variable */;
  TRACE_POP
}
/*
 equation index: 348
 type: SIMPLE_ASSIGN
 Radiation_roof_outer._dT = SkyTemperatureToK.T - Conduction_roof_outer.port_a.T
 */
void OM_Result_eqFunction_348(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,348};
  data->localData[0]->realVars[92] /* Radiation_roof_outer._dT variable */ = data->localData[0]->realVars[107] /* SkyTemperatureToK._T variable */ - data->localData[0]->realVars[32] /* Conduction_roof_outer._port_a._T variable */;
  TRACE_POP
}
void OM_Result_eqFunction_349(DATA*,threadData_t*);
void OM_Result_eqFunction_350(DATA*,threadData_t*);
void OM_Result_eqFunction_351(DATA*,threadData_t*);
void OM_Result_eqFunction_352(DATA*,threadData_t*);
void OM_Result_eqFunction_353(DATA*,threadData_t*);
void OM_Result_eqFunction_354(DATA*,threadData_t*);
/*
 equation index: 360
 indexNonlinear: 14
 type: NONLINEAR
 
 vars: {Conduction_wall1_outer._port_a._T}
 eqns: {349, 350, 351, 352, 353, 354}
 */
void OM_Result_eqFunction_360(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,360};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 360 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[14].nlsxOld[0] = data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 14);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,360};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 360 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */ = data->simulationInfo->nonlinearSystemData[14].nlsx[0];
  TRACE_POP
}
/*
 equation index: 361
 type: SIMPLE_ASSIGN
 Radiation_wall1_outer._dT = OutdoorTemperature - Conduction_wall1_outer.port_a.T
 */
void OM_Result_eqFunction_361(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,361};
  data->localData[0]->realVars[98] /* Radiation_wall1_outer._dT variable */ = data->localData[0]->realVars[85] /* OutdoorTemperature variable */ - data->localData[0]->realVars[38] /* Conduction_wall1_outer._port_a._T variable */;
  TRACE_POP
}
/*
 equation index: 362
 type: SIMPLE_ASSIGN
 OutdoorTemperatureToK._port._Q_flow = (-Convection_roof_outer.Q_flow) - Convection_wall1_outer.Q_flow - Convection_wall4_outer.Q_flow - Convection_wall3_outer.Q_flow - Radiation_wall1_outer.Q_flow - Radiation_wall3_outer.Q_flow - Radiation_wall4_outer.Q_flow
 */
void OM_Result_eqFunction_362(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,362};
  data->localData[0]->realVars[86] /* OutdoorTemperatureToK._port._Q_flow variable */ = (-data->localData[0]->realVars[56] /* Convection_roof_outer._Q_flow variable */) - data->localData[0]->realVars[61] /* Convection_wall1_outer._Q_flow variable */ - data->localData[0]->realVars[71] /* Convection_wall4_outer._Q_flow variable */ - data->localData[0]->realVars[66] /* Convection_wall3_outer._Q_flow variable */ - data->localData[0]->realVars[97] /* Radiation_wall1_outer._Q_flow variable */ - data->localData[0]->realVars[101] /* Radiation_wall3_outer._Q_flow variable */ - data->localData[0]->realVars[105] /* Radiation_wall4_outer._Q_flow variable */;
  TRACE_POP
}
void OM_Result_eqFunction_363(DATA*,threadData_t*);
void OM_Result_eqFunction_364(DATA*,threadData_t*);
void OM_Result_eqFunction_365(DATA*,threadData_t*);
void OM_Result_eqFunction_366(DATA*,threadData_t*);
void OM_Result_eqFunction_367(DATA*,threadData_t*);
void OM_Result_eqFunction_368(DATA*,threadData_t*);
/*
 equation index: 374
 indexNonlinear: 15
 type: NONLINEAR
 
 vars: {Conduction_wall1_inner._port_b._T}
 eqns: {363, 364, 365, 366, 367, 368}
 */
void OM_Result_eqFunction_374(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,374};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 374 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[15].nlsxOld[0] = data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 15);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,374};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 374 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */ = data->simulationInfo->nonlinearSystemData[15].nlsx[0];
  TRACE_POP
}
/*
 equation index: 375
 type: SIMPLE_ASSIGN
 Capacitor_wall1._port._Q_flow = Conduction_wall1_outer.Q_flow - Conduction_wall1_inner.Q_flow
 */
void OM_Result_eqFunction_375(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,375};
  data->localData[0]->realVars[22] /* Capacitor_wall1._port._Q_flow variable */ = data->localData[0]->realVars[36] /* Conduction_wall1_outer._Q_flow variable */ - data->localData[0]->realVars[33] /* Conduction_wall1_inner._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 376
 type: SIMPLE_ASSIGN
 Capacitor_wall1._der_T = DIVISION(Capacitor_wall1.port.Q_flow, Capacitor_wall1.C)
 */
void OM_Result_eqFunction_376(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,376};
  data->localData[0]->realVars[21] /* Capacitor_wall1._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[22] /* Capacitor_wall1._port._Q_flow variable */,data->simulationInfo->realParameter[6],"Capacitor_wall1.C",equationIndexes);
  TRACE_POP
}
/*
 equation index: 377
 type: SIMPLE_ASSIGN
 der(Capacitor_wall1._T) = Capacitor_wall1.der_T
 */
void OM_Result_eqFunction_377(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,377};
  data->localData[0]->realVars[7] /* der(Capacitor_wall1._T) STATE_DER */ = data->localData[0]->realVars[21] /* Capacitor_wall1._der_T variable */;
  TRACE_POP
}
/*
 equation index: 378
 type: SIMPLE_ASSIGN
 Capacitor_indoor_air._port._Q_flow = thermalCollector1.port_a[12].Q_flow - ((-Convection_roof_inner.Q_flow) - Radiation_roof_inner.Q_flow - Convection_wall1_inner.Q_flow - Radiation_wall1_inner.Q_flow - Convection_wall3_inner.Q_flow - Radiation_wall3_inner.Q_flow - Convection_wall4_inner.Q_flow - Radiation_wall4_inner.Q_flow - Convection_floor.Q_flow - Radiation_floor.Q_flow - thermalCollector1.port_a[11].Q_flow)
 */
void OM_Result_eqFunction_378(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,378};
  data->localData[0]->realVars[18] /* Capacitor_indoor_air._port._Q_flow variable */ = data->localData[0]->realVars[119] /* thermalCollector1._port_a[12]._Q_flow variable */ - ((-data->localData[0]->realVars[53] /* Convection_roof_inner._Q_flow variable */) - data->localData[0]->realVars[89] /* Radiation_roof_inner._Q_flow variable */ - data->localData[0]->realVars[58] /* Convection_wall1_inner._Q_flow variable */ - data->localData[0]->realVars[95] /* Radiation_wall1_inner._Q_flow variable */ - data->localData[0]->realVars[63] /* Convection_wall3_inner._Q_flow variable */ - data->localData[0]->realVars[99] /* Radiation_wall3_inner._Q_flow variable */ - data->localData[0]->realVars[68] /* Convection_wall4_inner._Q_flow variable */ - data->localData[0]->realVars[103] /* Radiation_wall4_inner._Q_flow variable */ - data->localData[0]->realVars[51] /* Convection_floor._Q_flow variable */ - data->localData[0]->realVars[87] /* Radiation_floor._Q_flow variable */ - data->localData[0]->realVars[118] /* thermalCollector1._port_a[11]._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 379
 type: SIMPLE_ASSIGN
 Capacitor_indoor_air._der_T = DIVISION(Capacitor_indoor_air.port.Q_flow, Capacitor_indoor_air.C)
 */
void OM_Result_eqFunction_379(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,379};
  data->localData[0]->realVars[17] /* Capacitor_indoor_air._der_T variable */ = DIVISION_SIM(data->localData[0]->realVars[18] /* Capacitor_indoor_air._port._Q_flow variable */,data->simulationInfo->realParameter[4],"Capacitor_indoor_air.C",equationIndexes);
  TRACE_POP
}
/*
 equation index: 380
 type: SIMPLE_ASSIGN
 der(Capacitor_indoor_air._T) = Capacitor_indoor_air.der_T
 */
void OM_Result_eqFunction_380(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,380};
  data->localData[0]->realVars[5] /* der(Capacitor_indoor_air._T) STATE_DER */ = data->localData[0]->realVars[17] /* Capacitor_indoor_air._der_T variable */;
  TRACE_POP
}
/*
 equation index: 381
 type: SIMPLE_ASSIGN
 Radiation_wall1_inner._dT = Conduction_wall1_inner.port_b.T - Capacitor_indoor_air.T
 */
void OM_Result_eqFunction_381(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,381};
  data->localData[0]->realVars[96] /* Radiation_wall1_inner._dT variable */ = data->localData[0]->realVars[35] /* Conduction_wall1_inner._port_b._T variable */ - data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */;
  TRACE_POP
}
/*
 equation index: 384
 type: ALGORITHM
 
   assert(Data_solar_radiation.tableName <> "NoName", "tableOnFile = true and no table name given");
 */
void OM_Result_eqFunction_384(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,384};
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
 equation index: 383
 type: ALGORITHM
 
   assert(Data_outdoor_temperature.tableName <> "NoName", "tableOnFile = true and no table name given");
 */
void OM_Result_eqFunction_383(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,383};
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
 equation index: 382
 type: ALGORITHM
 
   assert(Data_wind_speed.tableName <> "NoName", "tableOnFile = true and no table name given");
 */
void OM_Result_eqFunction_382(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,382};
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
  OM_Result_eqFunction_195(data, threadData);

  OM_Result_eqFunction_196(data, threadData);

  OM_Result_eqFunction_197(data, threadData);

  OM_Result_eqFunction_198(data, threadData);

  OM_Result_eqFunction_199(data, threadData);

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

  OM_Result_eqFunction_267(data, threadData);

  OM_Result_eqFunction_268(data, threadData);

  OM_Result_eqFunction_280(data, threadData);

  OM_Result_eqFunction_281(data, threadData);

  OM_Result_eqFunction_282(data, threadData);

  OM_Result_eqFunction_283(data, threadData);

  OM_Result_eqFunction_284(data, threadData);

  OM_Result_eqFunction_296(data, threadData);

  OM_Result_eqFunction_297(data, threadData);

  OM_Result_eqFunction_309(data, threadData);

  OM_Result_eqFunction_310(data, threadData);

  OM_Result_eqFunction_311(data, threadData);

  OM_Result_eqFunction_312(data, threadData);

  OM_Result_eqFunction_313(data, threadData);

  OM_Result_eqFunction_327(data, threadData);

  OM_Result_eqFunction_328(data, threadData);

  OM_Result_eqFunction_329(data, threadData);

  OM_Result_eqFunction_330(data, threadData);

  OM_Result_eqFunction_344(data, threadData);

  OM_Result_eqFunction_345(data, threadData);

  OM_Result_eqFunction_346(data, threadData);

  OM_Result_eqFunction_347(data, threadData);

  OM_Result_eqFunction_348(data, threadData);

  OM_Result_eqFunction_360(data, threadData);

  OM_Result_eqFunction_361(data, threadData);

  OM_Result_eqFunction_362(data, threadData);

  OM_Result_eqFunction_374(data, threadData);

  OM_Result_eqFunction_375(data, threadData);

  OM_Result_eqFunction_376(data, threadData);

  OM_Result_eqFunction_377(data, threadData);

  OM_Result_eqFunction_378(data, threadData);

  OM_Result_eqFunction_379(data, threadData);

  OM_Result_eqFunction_380(data, threadData);

  OM_Result_eqFunction_381(data, threadData);

  OM_Result_eqFunction_384(data, threadData);

  OM_Result_eqFunction_383(data, threadData);

  OM_Result_eqFunction_382(data, threadData);
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
extern void OM_Result_eqFunction_195(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_196(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_197(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_198(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_201(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_202(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_203(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_204(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_205(DATA* data, threadData_t *threadData);
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
extern void OM_Result_eqFunction_218(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_219(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_222(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_223(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_224(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_225(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_226(DATA* data, threadData_t *threadData);
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
extern void OM_Result_eqFunction_246(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_247(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_248(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_249(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_250(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_251(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_252(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_253(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_254(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_255(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_267(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_280(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_281(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_282(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_283(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_296(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_309(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_310(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_311(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_312(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_327(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_344(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_345(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_346(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_347(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_360(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_374(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_375(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_376(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_377(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_378(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_379(DATA* data, threadData_t *threadData);
extern void OM_Result_eqFunction_380(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  OM_Result_eqFunction_195(data, threadData);

  OM_Result_eqFunction_196(data, threadData);

  OM_Result_eqFunction_197(data, threadData);

  OM_Result_eqFunction_198(data, threadData);

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

  OM_Result_eqFunction_218(data, threadData);

  OM_Result_eqFunction_219(data, threadData);

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

  OM_Result_eqFunction_267(data, threadData);

  OM_Result_eqFunction_280(data, threadData);

  OM_Result_eqFunction_281(data, threadData);

  OM_Result_eqFunction_282(data, threadData);

  OM_Result_eqFunction_283(data, threadData);

  OM_Result_eqFunction_296(data, threadData);

  OM_Result_eqFunction_309(data, threadData);

  OM_Result_eqFunction_310(data, threadData);

  OM_Result_eqFunction_311(data, threadData);

  OM_Result_eqFunction_312(data, threadData);

  OM_Result_eqFunction_327(data, threadData);

  OM_Result_eqFunction_344(data, threadData);

  OM_Result_eqFunction_345(data, threadData);

  OM_Result_eqFunction_346(data, threadData);

  OM_Result_eqFunction_347(data, threadData);

  OM_Result_eqFunction_360(data, threadData);

  OM_Result_eqFunction_374(data, threadData);

  OM_Result_eqFunction_375(data, threadData);

  OM_Result_eqFunction_376(data, threadData);

  OM_Result_eqFunction_377(data, threadData);

  OM_Result_eqFunction_378(data, threadData);

  OM_Result_eqFunction_379(data, threadData);

  OM_Result_eqFunction_380(data, threadData);
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
  data->modelData->nVariablesReal = 141;
  data->modelData->nDiscreteReal = 6;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 3;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 96;
  data->modelData->nParametersInteger = 35;
  data->modelData->nParametersBoolean = 10;
  data->modelData->nParametersString = 6;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 241;
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
  data->modelData->modelDataXml.nFunctions = 15;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 487;
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


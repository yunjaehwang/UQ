#ifndef OM_Result__H
#define OM_Result__H
#include "meta/meta_modelica.h"
#include "util/modelica.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "simulation/simulation_runtime.h"
#ifdef __cplusplus
extern "C" {
#endif


DLLExport
modelica_real omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData_t *threadData, modelica_complex _tableID, modelica_real _timeIn);
DLLExport
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _timeIn);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Tables_Internal_getNextTimeEvent,2,0) {(void*) boxptr_Modelica_Blocks_Tables_Internal_getNextTimeEvent,0}};
#define boxvar_Modelica_Blocks_Tables_Internal_getNextTimeEvent MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Tables_Internal_getNextTimeEvent)

extern double ModelicaStandardTables_CombiTimeTable_nextTimeEvent(void * /*_tableID*/, double /*_timeIn*/);


DLLExport
modelica_real omc_Modelica_Blocks_Tables_Internal_getTimeTableTmax(threadData_t *threadData, modelica_complex _tableID);
DLLExport
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTimeTableTmax(threadData_t *threadData, modelica_metatype _tableID);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Tables_Internal_getTimeTableTmax,2,0) {(void*) boxptr_Modelica_Blocks_Tables_Internal_getTimeTableTmax,0}};
#define boxvar_Modelica_Blocks_Tables_Internal_getTimeTableTmax MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Tables_Internal_getTimeTableTmax)

extern double ModelicaStandardTables_CombiTimeTable_maximumTime(void * /*_tableID*/);


DLLExport
modelica_real omc_Modelica_Blocks_Tables_Internal_getTimeTableTmin(threadData_t *threadData, modelica_complex _tableID);
DLLExport
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTimeTableTmin(threadData_t *threadData, modelica_metatype _tableID);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Tables_Internal_getTimeTableTmin,2,0) {(void*) boxptr_Modelica_Blocks_Tables_Internal_getTimeTableTmin,0}};
#define boxvar_Modelica_Blocks_Tables_Internal_getTimeTableTmin MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Tables_Internal_getTimeTableTmin)

extern double ModelicaStandardTables_CombiTimeTable_minimumTime(void * /*_tableID*/);


DLLExport
modelica_real omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData_t *threadData, modelica_complex _tableID, modelica_integer _icol, modelica_real _timeIn, modelica_real _nextTimeEvent, modelica_real _pre_nextTimeEvent);
DLLExport
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _icol, modelica_metatype _timeIn, modelica_metatype _nextTimeEvent, modelica_metatype _pre_nextTimeEvent);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Tables_Internal_getTimeTableValue,2,0) {(void*) boxptr_Modelica_Blocks_Tables_Internal_getTimeTableValue,0}};
#define boxvar_Modelica_Blocks_Tables_Internal_getTimeTableValue MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Tables_Internal_getTimeTableValue)

extern double ModelicaStandardTables_CombiTimeTable_getValue(void * /*_tableID*/, int /*_icol*/, double /*_timeIn*/, double /*_nextTimeEvent*/, double /*_pre_nextTimeEvent*/);


DLLExport
modelica_complex omc_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor(threadData_t *threadData, modelica_string _tableName, modelica_string _fileName, real_array _table, modelica_real _startTime, integer_array _columns, modelica_integer _smoothness, modelica_integer _extrapolation, modelica_real _shiftTime, modelica_integer _timeEvents, modelica_boolean _verboseRead);
DLLExport
modelica_metatype boxptr_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor(threadData_t *threadData, modelica_metatype _tableName, modelica_metatype _fileName, modelica_metatype _table, modelica_metatype _startTime, modelica_metatype _columns, modelica_metatype _smoothness, modelica_metatype _extrapolation, modelica_metatype _shiftTime, modelica_metatype _timeEvents, modelica_metatype _verboseRead);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor,2,0) {(void*) boxptr_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor,0}};
#define boxvar_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor)

extern void * ModelicaStandardTables_CombiTimeTable_init2(const char* /*_fileName*/, const char* /*_tableName*/, const double* /*_table*/, size_t, size_t, double /*_startTime*/, const int* /*_columns*/, size_t, int /*_smoothness*/, int /*_extrapolation*/, double /*_shiftTime*/, int /*_timeEvents*/, int /*_verboseRead*/);


DLLExport
void omc_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData_t *threadData, modelica_complex _externalCombiTimeTable);
DLLExport
void boxptr_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData_t *threadData, modelica_metatype _externalCombiTimeTable);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor,2,0) {(void*) boxptr_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor,0}};
#define boxvar_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor)

extern void ModelicaStandardTables_CombiTimeTable_close(void * /*_externalCombiTimeTable*/);


DLLExport
modelica_real omc_Modelica_Math_Special_erfInv(threadData_t *threadData, modelica_real _u);
DLLExport
modelica_metatype boxptr_Modelica_Math_Special_erfInv(threadData_t *threadData, modelica_metatype _u);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Math_Special_erfInv,2,0) {(void*) boxptr_Modelica_Math_Special_erfInv,0}};
#define boxvar_Modelica_Math_Special_erfInv MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Math_Special_erfInv)


DLLExport
modelica_real omc_Modelica_Math_Special_Internal_erfInvUtil(threadData_t *threadData, modelica_real _p, modelica_real _q);
DLLExport
modelica_metatype boxptr_Modelica_Math_Special_Internal_erfInvUtil(threadData_t *threadData, modelica_metatype _p, modelica_metatype _q);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Math_Special_Internal_erfInvUtil,2,0) {(void*) boxptr_Modelica_Math_Special_Internal_erfInvUtil,0}};
#define boxvar_Modelica_Math_Special_Internal_erfInvUtil MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Math_Special_Internal_erfInvUtil)


DLLExport
modelica_real omc_Modelica_Math_Special_Internal_polyEval(threadData_t *threadData, real_array _c, modelica_real _u);
DLLExport
modelica_metatype boxptr_Modelica_Math_Special_Internal_polyEval(threadData_t *threadData, modelica_metatype _c, modelica_metatype _u);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Math_Special_Internal_polyEval,2,0) {(void*) boxptr_Modelica_Math_Special_Internal_polyEval,0}};
#define boxvar_Modelica_Math_Special_Internal_polyEval MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Math_Special_Internal_polyEval)


DLLExport
modelica_boolean omc_Modelica_Utilities_Strings_isEmpty(threadData_t *threadData, modelica_string _string);
DLLExport
modelica_metatype boxptr_Modelica_Utilities_Strings_isEmpty(threadData_t *threadData, modelica_metatype _string);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Utilities_Strings_isEmpty,2,0) {(void*) boxptr_Modelica_Utilities_Strings_isEmpty,0}};
#define boxvar_Modelica_Utilities_Strings_isEmpty MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Utilities_Strings_isEmpty)


DLLExport
modelica_integer omc_Modelica_Utilities_Strings_length(threadData_t *threadData, modelica_string _string);
DLLExport
modelica_metatype boxptr_Modelica_Utilities_Strings_length(threadData_t *threadData, modelica_metatype _string);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Utilities_Strings_length,2,0) {(void*) boxptr_Modelica_Utilities_Strings_length,0}};
#define boxvar_Modelica_Utilities_Strings_length MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Utilities_Strings_length)

extern int ModelicaStrings_length(const char* /*_string*/);


DLLExport
modelica_integer omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData_t *threadData, modelica_string _string, modelica_integer _startIndex);
DLLExport
modelica_metatype boxptr_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData_t *threadData, modelica_metatype _string, modelica_metatype _startIndex);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Utilities_Strings_Advanced_skipWhiteSpace,2,0) {(void*) boxptr_Modelica_Utilities_Strings_Advanced_skipWhiteSpace,0}};
#define boxvar_Modelica_Utilities_Strings_Advanced_skipWhiteSpace MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Utilities_Strings_Advanced_skipWhiteSpace)

extern int ModelicaStrings_skipWhiteSpace(const char* /*_string*/, int /*_startIndex*/);


DLLExport
modelica_real omc_Outfall_invNormal(threadData_t *threadData, modelica_real _u, modelica_real _mu, modelica_real _sigma);
DLLExport
modelica_metatype boxptr_Outfall_invNormal(threadData_t *threadData, modelica_metatype _u, modelica_metatype _mu, modelica_metatype _sigma);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Outfall_invNormal,2,0) {(void*) boxptr_Outfall_invNormal,0}};
#define boxvar_Outfall_invNormal MMC_REFSTRUCTLIT(boxvar_lit_Outfall_invNormal)


DLLExport
modelica_real omc_Outfall_invUniform(threadData_t *threadData, modelica_real _u, modelica_real _y_min, modelica_real _y_max);
DLLExport
modelica_metatype boxptr_Outfall_invUniform(threadData_t *threadData, modelica_metatype _u, modelica_metatype _y_min, modelica_metatype _y_max);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Outfall_invUniform,2,0) {(void*) boxptr_Outfall_invUniform,0}};
#define boxvar_Outfall_invUniform MMC_REFSTRUCTLIT(boxvar_lit_Outfall_invUniform)


DLLExport
modelica_real omc_Outfall_invWeibull(threadData_t *threadData, modelica_real _u, modelica_real _lambda, modelica_real _k);
DLLExport
modelica_metatype boxptr_Outfall_invWeibull(threadData_t *threadData, modelica_metatype _u, modelica_metatype _lambda, modelica_metatype _k);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Outfall_invWeibull,2,0) {(void*) boxptr_Outfall_invWeibull,0}};
#define boxvar_Outfall_invWeibull MMC_REFSTRUCTLIT(boxvar_lit_Outfall_invWeibull)
#include "OM_Result_model.h"


#ifdef __cplusplus
}
#endif
#endif


#include "OM_Result_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "OM_Result_includes.h"


modelica_real omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData_t *threadData, modelica_complex _tableID, modelica_real _timeIn)
{
  void * _tableID_ext;
  double _timeIn_ext;
  double _nextTimeEvent_ext;
  modelica_real _nextTimeEvent;
  _tableID_ext = (void *)_tableID;
  _timeIn_ext = (double)_timeIn;
  _nextTimeEvent_ext = ModelicaStandardTables_CombiTimeTable_nextTimeEvent(_tableID_ext, _timeIn_ext);
  _nextTimeEvent = (modelica_real)_nextTimeEvent_ext;
  return _nextTimeEvent;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _timeIn)
{
  modelica_real tmp1;
  modelica_real _nextTimeEvent;
  modelica_metatype out_nextTimeEvent;
  tmp1 = mmc_unbox_real(_timeIn);
  _nextTimeEvent = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, _tableID, tmp1);
  out_nextTimeEvent = mmc_mk_rcon(_nextTimeEvent);
  return out_nextTimeEvent;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTimeTableTmax(threadData_t *threadData, modelica_complex _tableID)
{
  void * _tableID_ext;
  double _timeMax_ext;
  modelica_real _timeMax;
  _tableID_ext = (void *)_tableID;
  _timeMax_ext = ModelicaStandardTables_CombiTimeTable_maximumTime(_tableID_ext);
  _timeMax = (modelica_real)_timeMax_ext;
  return _timeMax;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTimeTableTmax(threadData_t *threadData, modelica_metatype _tableID)
{
  modelica_real _timeMax;
  modelica_metatype out_timeMax;
  _timeMax = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmax(threadData, _tableID);
  out_timeMax = mmc_mk_rcon(_timeMax);
  return out_timeMax;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTimeTableTmin(threadData_t *threadData, modelica_complex _tableID)
{
  void * _tableID_ext;
  double _timeMin_ext;
  modelica_real _timeMin;
  _tableID_ext = (void *)_tableID;
  _timeMin_ext = ModelicaStandardTables_CombiTimeTable_minimumTime(_tableID_ext);
  _timeMin = (modelica_real)_timeMin_ext;
  return _timeMin;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTimeTableTmin(threadData_t *threadData, modelica_metatype _tableID)
{
  modelica_real _timeMin;
  modelica_metatype out_timeMin;
  _timeMin = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmin(threadData, _tableID);
  out_timeMin = mmc_mk_rcon(_timeMin);
  return out_timeMin;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData_t *threadData, modelica_complex _tableID, modelica_integer _icol, modelica_real _timeIn, modelica_real _nextTimeEvent, modelica_real _pre_nextTimeEvent)
{
  void * _tableID_ext;
  int _icol_ext;
  double _timeIn_ext;
  double _nextTimeEvent_ext;
  double _pre_nextTimeEvent_ext;
  double _y_ext;
  modelica_real _y;
  _tableID_ext = (void *)_tableID;
  _icol_ext = (int)_icol;
  _timeIn_ext = (double)_timeIn;
  _nextTimeEvent_ext = (double)_nextTimeEvent;
  _pre_nextTimeEvent_ext = (double)_pre_nextTimeEvent;
  _y_ext = ModelicaStandardTables_CombiTimeTable_getValue(_tableID_ext, _icol_ext, _timeIn_ext, _nextTimeEvent_ext, _pre_nextTimeEvent_ext);
  _y = (modelica_real)_y_ext;
  return _y;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _icol, modelica_metatype _timeIn, modelica_metatype _nextTimeEvent, modelica_metatype _pre_nextTimeEvent)
{
  modelica_integer tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_integer(_icol);
  tmp2 = mmc_unbox_real(_timeIn);
  tmp3 = mmc_unbox_real(_nextTimeEvent);
  tmp4 = mmc_unbox_real(_pre_nextTimeEvent);
  _y = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, _tableID, tmp1, tmp2, tmp3, tmp4);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

modelica_complex omc_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor(threadData_t *threadData, modelica_string _tableName, modelica_string _fileName, real_array _table, modelica_real _startTime, integer_array _columns, modelica_integer _smoothness, modelica_integer _extrapolation, modelica_real _shiftTime, modelica_integer _timeEvents, modelica_boolean _verboseRead)
{
  double _startTime_ext;
  int _smoothness_ext;
  int _extrapolation_ext;
  double _shiftTime_ext;
  int _timeEvents_ext;
  int _verboseRead_ext;
  void *_table_c89;
  void *_columns_c89;
  void * _externalCombiTimeTable_ext;
  modelica_complex _externalCombiTimeTable;
  _startTime_ext = (double)_startTime;
  pack_integer_array(&_columns);
  _smoothness_ext = (int)_smoothness;
  _extrapolation_ext = (int)_extrapolation;
  _shiftTime_ext = (double)_shiftTime;
  _timeEvents_ext = (int)_timeEvents;
  _verboseRead_ext = (int)_verboseRead;_table_c89 = (void*) data_of_real_c89_array(&(_table));
  _columns_c89 = (void*) data_of_integer_c89_array(&(_columns));
  _externalCombiTimeTable_ext = ModelicaStandardTables_CombiTimeTable_init2(MMC_STRINGDATA(_fileName), MMC_STRINGDATA(_tableName), (const double*) _table_c89, size_of_dimension_base_array(_table, ((modelica_integer) 1)), size_of_dimension_base_array(_table, ((modelica_integer) 2)), _startTime_ext, (const int*) _columns_c89, size_of_dimension_base_array(_columns, ((modelica_integer) 1)), _smoothness_ext, _extrapolation_ext, _shiftTime_ext, _timeEvents_ext, _verboseRead_ext);
  _externalCombiTimeTable = (modelica_complex)_externalCombiTimeTable_ext;
  return _externalCombiTimeTable;
}
modelica_metatype boxptr_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor(threadData_t *threadData, modelica_metatype _tableName, modelica_metatype _fileName, modelica_metatype _table, modelica_metatype _startTime, modelica_metatype _columns, modelica_metatype _smoothness, modelica_metatype _extrapolation, modelica_metatype _shiftTime, modelica_metatype _timeEvents, modelica_metatype _verboseRead)
{
  modelica_real tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_real tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_complex _externalCombiTimeTable;
  tmp1 = mmc_unbox_real(_startTime);
  tmp2 = mmc_unbox_integer(_smoothness);
  tmp3 = mmc_unbox_integer(_extrapolation);
  tmp4 = mmc_unbox_real(_shiftTime);
  tmp5 = mmc_unbox_integer(_timeEvents);
  tmp6 = mmc_unbox_integer(_verboseRead);
  _externalCombiTimeTable = omc_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor(threadData, _tableName, _fileName, *((base_array_t*)_table), tmp1, *((base_array_t*)_columns), tmp2, tmp3, tmp4, tmp5, tmp6);
  /* skip box _externalCombiTimeTable; ExternalObject Modelica.Blocks.Types.ExternalCombiTimeTable */
  return _externalCombiTimeTable;
}

void omc_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData_t *threadData, modelica_complex _externalCombiTimeTable)
{
  void * _externalCombiTimeTable_ext;
  _externalCombiTimeTable_ext = (void *)_externalCombiTimeTable;
  ModelicaStandardTables_CombiTimeTable_close(_externalCombiTimeTable_ext);
  return;
}
void boxptr_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData_t *threadData, modelica_metatype _externalCombiTimeTable)
{
  omc_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData, _externalCombiTimeTable);
  return;
}

DLLExport
modelica_real omc_Modelica_Math_Special_erfInv(threadData_t *threadData, modelica_real _u)
{
  modelica_real _y;
  _tailrecursive: OMC_LABEL_UNUSED
  if((_u >= 1.0))
  {
    _y = 9.999999999999999e+59;
  }
  else
  {
    if((_u <= -1.0))
    {
      _y = -9.999999999999999e+59;
    }
    else
    {
      if((_u == 0.0))
      {
        _y = 0.0;
      }
      else
      {
        if((_u < 0.0))
        {
          _y = (-omc_Modelica_Math_Special_Internal_erfInvUtil(threadData, (-_u), 1.0 + _u));
        }
        else
        {
          _y = omc_Modelica_Math_Special_Internal_erfInvUtil(threadData, _u, 1.0 - _u);
        }
      }
    }
  }
  _return: OMC_LABEL_UNUSED
  return _y;
}
modelica_metatype boxptr_Modelica_Math_Special_erfInv(threadData_t *threadData, modelica_metatype _u)
{
  modelica_real tmp1;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_u);
  _y = omc_Modelica_Math_Special_erfInv(threadData, tmp1);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

DLLExport
modelica_real omc_Modelica_Math_Special_Internal_erfInvUtil(threadData_t *threadData, modelica_real _p, modelica_real _q)
{
  modelica_real _y;
  modelica_real _g;
  modelica_real _r;
  modelica_real _xs;
  modelica_real _x;
  modelica_real _y1;
  real_array _P1;
  real_array _Q1;
  modelica_real _y2;
  real_array _P2;
  real_array _Q2;
  modelica_real _y3;
  real_array _P3;
  real_array _Q3;
  modelica_real _y4;
  real_array _P4;
  real_array _Q4;
  modelica_real _y5;
  real_array _P5;
  real_array _Q5;
  modelica_real _y6;
  real_array _P6;
  real_array _Q6;
  modelica_real _y7;
  real_array _P7;
  real_array _Q7;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  _tailrecursive: OMC_LABEL_UNUSED
  _y1 = 0.08913147449493408;
  _P1 = _OMC_LIT6;
  _Q1 = _OMC_LIT7;
  _y2 = 2.249481201171875;
  _P2 = _OMC_LIT8;
  _Q2 = _OMC_LIT9;
  _y3 = 0.807220458984375;
  _P3 = _OMC_LIT10;
  _Q3 = _OMC_LIT11;
  _y4 = 0.9399557113647461;
  _P4 = _OMC_LIT12;
  _Q4 = _OMC_LIT13;
  _y5 = 0.9836282730102539;
  _P5 = _OMC_LIT14;
  _Q5 = _OMC_LIT15;
  _y6 = 0.9971456527709961;
  _P6 = _OMC_LIT16;
  _Q6 = _OMC_LIT17;
  _y7 = 0.9994134902954102;
  _P7 = _OMC_LIT18;
  _Q7 = _OMC_LIT19;
  if((_p <= 0.5))
  {
    _g = (_p) * (10.0 + _p);

    tmp1 = omc_Modelica_Math_Special_Internal_polyEval(threadData, _OMC_LIT7, _p);
    if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Modelica.Math.Special.Internal.polyEval({-0.0005087819496582806, -0.008368748197417368, 0.03348066254097446, -0.0126926147662974, -0.03656379714117627, 0.02198786811111689, 0.008226878746769157, -0.005387729650712429}, p) / Modelica.Math.Special.Internal.polyEval({1.0, -0.9700050433032906, -1.565745582341759, 1.56221558398423, 0.662328840472003, -0.7122890234154284, -0.05273963823400997, 0.07952836873415717, -0.0023339375937419, 0.0008862163904564247}, p)");}
    _r = (omc_Modelica_Math_Special_Internal_polyEval(threadData, _OMC_LIT6, _p)) / tmp1;

    _y = (_g) * (0.08913147449493408 + _r);
  }
  else
  {
    if((_q >= 0.25))
    {
      tmp2 = _q;
      if(!(tmp2 > 0.0))
      {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert(threadData, info, "Model error: Argument of log(q) was %g should be > 0", tmp2);
      }tmp3 = (-2.0) * (log(tmp2));
      if(!(tmp3 >= 0.0))
      {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert(threadData, info, "Model error: Argument of sqrt(-2.0 * log(q)) was %g should be >= 0", tmp3);
      }
      _g = sqrt(tmp3);

      _xs = -0.25 + _q;

      tmp4 = omc_Modelica_Math_Special_Internal_polyEval(threadData, _OMC_LIT9, _xs);
      if (tmp4 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Modelica.Math.Special.Internal.polyEval({-0.2024335083559388, 0.1052646806993917, 8.3705032834312, 17.6447298408374, -18.85106480587142, -44.6382324441787, 17.44538598557087, 21.12946554483405, -3.671922547077294}, xs) / Modelica.Math.Special.Internal.polyEval({1.0, 6.242641248542475, 3.971343795334387, -28.66081804998, -20.14326346804852, 48.56092131087399, 10.82686673554602, -22.64369334131397, 1.721147657612003}, xs)");}
      _r = (omc_Modelica_Math_Special_Internal_polyEval(threadData, _OMC_LIT8, _xs)) / tmp4;

      tmp5 = 2.249481201171875 + _r;
      if (tmp5 == 0) {throwStreamPrint(threadData, "Division by zero %s", "g / (2.249481201171875 + r)");}
      _y = (_g) / tmp5;
    }
    else
    {
      tmp6 = _q;
      if(!(tmp6 > 0.0))
      {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert(threadData, info, "Model error: Argument of log(q) was %g should be > 0", tmp6);
      }tmp7 = (-log(tmp6));
      if(!(tmp7 >= 0.0))
      {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert(threadData, info, "Model error: Argument of sqrt(-log(q)) was %g should be >= 0", tmp7);
      }
      _x = sqrt(tmp7);

      if((_x < 3.0))
      {
        _xs = -1.125 + _x;

        tmp8 = omc_Modelica_Math_Special_Internal_polyEval(threadData, _OMC_LIT11, _xs);
        if (tmp8 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Modelica.Math.Special.Internal.polyEval({-0.1311027816799519, -0.1637940471933171, 0.1170301563419952, 0.3870797389726043, 0.3377855389120359, 0.1428695344081572, 0.02901579100053291, 0.002145589953888053, -6.794655751811263e-07, 2.85225331782217e-08, -6.81149956853777e-10}, xs) / Modelica.Math.Special.Internal.polyEval({1.0, 3.466254072425672, 5.381683457070069, 4.778465929458438, 2.593019216236203, 0.848854343457902, 0.1522643382953318, 0.01105924229346489}, xs)");}
        _r = (omc_Modelica_Math_Special_Internal_polyEval(threadData, _OMC_LIT10, _xs)) / tmp8;

        _y = (_x) * (0.807220458984375 + _r);
      }
      else
      {
        if((_x < 6.0))
        {
          _xs = -3.0 + _x;

          tmp9 = omc_Modelica_Math_Special_Internal_polyEval(threadData, _OMC_LIT13, _xs);
          if (tmp9 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Modelica.Math.Special.Internal.polyEval({-0.0350353787183178, -0.002224265292134479, 0.01855733065142311, 0.009508047013259196, 0.001871234928195592, 0.0001575446174249605, 4.60469890584318e-06, -2.304047769118826e-10, 2.66339227425782e-12}, xs) / Modelica.Math.Special.Internal.polyEval({1.0, 1.365334981755406, 0.7620591645536234, 0.2200911057641312, 0.03415891436709477, 0.00263861676657016, 7.646752923027944e-05}, xs)");}
          _r = (omc_Modelica_Math_Special_Internal_polyEval(threadData, _OMC_LIT12, _xs)) / tmp9;

          _y = (_x) * (0.9399557113647461 + _r);
        }
        else
        {
          if((_x < 18.0))
          {
            _xs = -6.0 + _x;

            tmp10 = omc_Modelica_Math_Special_Internal_polyEval(threadData, _OMC_LIT15, _xs);
            if (tmp10 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Modelica.Math.Special.Internal.polyEval({-0.01674310050766337, -0.001129514387455803, 0.001056288621524929, 0.0002093863174875881, 1.496247837583424e-05, 4.496967899277064e-07, 4.625961635228786e-09, -2.811287356288318e-14, 9.905570997331033e-17}, xs) / Modelica.Math.Special.Internal.polyEval({1.0, 0.5914293448864175, 0.1381518657490833, 0.01607460870936765, 0.0009640118070051656, 2.75335474764726e-05, 2.82243172016108e-07}, xs)");}
            _r = (omc_Modelica_Math_Special_Internal_polyEval(threadData, _OMC_LIT14, _xs)) / tmp10;

            _y = (_x) * (0.9836282730102539 + _r);
          }
          else
          {
            if((_x < 44.0))
            {
              _xs = -18.0 + _x;

              tmp11 = omc_Modelica_Math_Special_Internal_polyEval(threadData, _OMC_LIT17, _xs);
              if (tmp11 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Modelica.Math.Special.Internal.polyEval({-0.002497821279189813, -7.79190719229054e-06, 2.547230374130275e-05, 1.623977773425109e-06, 3.963410113048012e-08, 4.116328311909442e-10, 1.45596286718675e-12, -1.167650123971843e-18}, xs) / Modelica.Math.Special.Internal.polyEval({1.0, 0.2071231122144225, 0.01694108381209759, 0.0006905382656226846, 1.450073598182326e-05, 1.444377566281441e-07, 5.097612765997785e-10}, xs)");}
              _r = (omc_Modelica_Math_Special_Internal_polyEval(threadData, _OMC_LIT16, _xs)) / tmp11;

              _y = (_x) * (0.9971456527709961 + _r);
            }
            else
            {
              _xs = -44.0 + _x;

              tmp12 = omc_Modelica_Math_Special_Internal_polyEval(threadData, _OMC_LIT19, _xs);
              if (tmp12 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Modelica.Math.Special.Internal.polyEval({-0.0005390429110190785, -2.839875900472772e-07, 8.994651148922914e-07, 2.293458592659209e-08, 2.255614448635001e-10, 9.478466275030226e-13, 1.358801301089249e-15, -3.488903933999489e-22}, xs) / Modelica.Math.Special.Internal.polyEval({1.0, 0.08457462340018994, 0.002820929847262647, 4.682929219408942e-05, 3.999688121938621e-07, 1.618092908879045e-09, 2.315586083102596e-12}, xs)");}
              _r = (omc_Modelica_Math_Special_Internal_polyEval(threadData, _OMC_LIT18, _xs)) / tmp12;

              _y = (_x) * (0.9994134902954102 + _r);
            }
          }
        }
      }
    }
  }
  _return: OMC_LABEL_UNUSED
  return _y;
}
modelica_metatype boxptr_Modelica_Math_Special_Internal_erfInvUtil(threadData_t *threadData, modelica_metatype _p, modelica_metatype _q)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_p);
  tmp2 = mmc_unbox_real(_q);
  _y = omc_Modelica_Math_Special_Internal_erfInvUtil(threadData, tmp1, tmp2);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

DLLExport
modelica_real omc_Modelica_Math_Special_Internal_polyEval(threadData_t *threadData, real_array _c, modelica_real _u)
{
  modelica_real _y;
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  _tailrecursive: OMC_LABEL_UNUSED
  tmp1 = size_of_dimension_base_array(_c, ((modelica_integer) 1));
  _y = (*real_array_element_addr1(&_c, 1, /* modelica_integer */ tmp1));

  tmp5 = size_of_dimension_base_array(_c, ((modelica_integer) 1));
  tmp2 = ((modelica_integer) -1) + tmp5; tmp3 = ((modelica_integer) -1); tmp4 = ((modelica_integer) 1);
  if(!tmp3)
  {
    FILE_INFO info = omc_dummyFileInfo;
    omc_assert(threadData, info, "assertion range step != 0 failed");
  }
  else if(!(((tmp3 > 0) && (tmp2 > tmp4)) || ((tmp3 < 0) && (tmp2 < tmp4))))
  {
    modelica_integer _j;
    for(_j = ((modelica_integer) -1) + tmp5; in_range_integer(_j, tmp2, tmp4); _j += tmp3)
    {
      _y = (*real_array_element_addr1(&_c, 1, /* modelica_integer */ (modelica_integer)_j)) + (_u) * (_y);
    }
  }
  _return: OMC_LABEL_UNUSED
  return _y;
}
modelica_metatype boxptr_Modelica_Math_Special_Internal_polyEval(threadData_t *threadData, modelica_metatype _c, modelica_metatype _u)
{
  modelica_real tmp1;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_u);
  _y = omc_Modelica_Math_Special_Internal_polyEval(threadData, *((base_array_t*)_c), tmp1);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

DLLExport
modelica_boolean omc_Modelica_Utilities_Strings_isEmpty(threadData_t *threadData, modelica_string _string)
{
  modelica_boolean _result;
  modelica_integer _nextIndex;
  modelica_integer _len;
  _tailrecursive: OMC_LABEL_UNUSED
  _nextIndex = omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData, _string, ((modelica_integer) 1));

  _len = omc_Modelica_Utilities_Strings_length(threadData, _string);

  if((((modelica_integer)_len < ((modelica_integer) 1)) || ((modelica_integer)_nextIndex > (modelica_integer)_len)))
  {
    _result = 1;
  }
  else
  {
    _result = 0;
  }
  _return: OMC_LABEL_UNUSED
  return _result;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_isEmpty(threadData_t *threadData, modelica_metatype _string)
{
  modelica_boolean _result;
  modelica_metatype out_result;
  _result = omc_Modelica_Utilities_Strings_isEmpty(threadData, _string);
  out_result = mmc_mk_icon(_result);
  return out_result;
}

modelica_integer omc_Modelica_Utilities_Strings_length(threadData_t *threadData, modelica_string _string)
{
  int _result_ext;
  modelica_integer _result;
  _result_ext = ModelicaStrings_length(MMC_STRINGDATA(_string));
  _result = (modelica_integer)_result_ext;
  return _result;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_length(threadData_t *threadData, modelica_metatype _string)
{
  modelica_integer _result;
  modelica_metatype out_result;
  _result = omc_Modelica_Utilities_Strings_length(threadData, _string);
  out_result = mmc_mk_icon(_result);
  return out_result;
}

modelica_integer omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData_t *threadData, modelica_string _string, modelica_integer _startIndex)
{
  int _startIndex_ext;
  int _nextIndex_ext;
  modelica_integer _nextIndex;
  _startIndex_ext = (int)_startIndex;
  _nextIndex_ext = ModelicaStrings_skipWhiteSpace(MMC_STRINGDATA(_string), _startIndex_ext);
  _nextIndex = (modelica_integer)_nextIndex_ext;
  return _nextIndex;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData_t *threadData, modelica_metatype _string, modelica_metatype _startIndex)
{
  modelica_integer tmp1;
  modelica_integer _nextIndex;
  modelica_metatype out_nextIndex;
  tmp1 = mmc_unbox_integer(_startIndex);
  _nextIndex = omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData, _string, tmp1);
  out_nextIndex = mmc_mk_icon(_nextIndex);
  return out_nextIndex;
}

DLLExport
modelica_real omc_Outfall_invNormal(threadData_t *threadData, modelica_real _u, modelica_real _mu, modelica_real _sigma)
{
  modelica_real _y;
  _tailrecursive: OMC_LABEL_UNUSED
  _y = _mu + (1.414213562373095) * ((_sigma) * (omc_Modelica_Math_Special_erfInv(threadData, -1.0 + (2.0) * (_u))));
  _return: OMC_LABEL_UNUSED
  return _y;
}
modelica_metatype boxptr_Outfall_invNormal(threadData_t *threadData, modelica_metatype _u, modelica_metatype _mu, modelica_metatype _sigma)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_u);
  tmp2 = mmc_unbox_real(_mu);
  tmp3 = mmc_unbox_real(_sigma);
  _y = omc_Outfall_invNormal(threadData, tmp1, tmp2, tmp3);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

DLLExport
modelica_real omc_Outfall_invUniform(threadData_t *threadData, modelica_real _u, modelica_real _y_min, modelica_real _y_max)
{
  modelica_real _y;
  _tailrecursive: OMC_LABEL_UNUSED
  _y = (_u) * (_y_max - _y_min) + _y_min;
  _return: OMC_LABEL_UNUSED
  return _y;
}
modelica_metatype boxptr_Outfall_invUniform(threadData_t *threadData, modelica_metatype _u, modelica_metatype _y_min, modelica_metatype _y_max)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_u);
  tmp2 = mmc_unbox_real(_y_min);
  tmp3 = mmc_unbox_real(_y_max);
  _y = omc_Outfall_invUniform(threadData, tmp1, tmp2, tmp3);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

DLLExport
modelica_real omc_Outfall_invWeibull(threadData_t *threadData, modelica_real _u, modelica_real _lambda, modelica_real _k)
{
  modelica_real _y;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  _tailrecursive: OMC_LABEL_UNUSED
  tmp1 = 1.0 - _u;
  if(!(tmp1 > 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of log(1.0 - u) was %g should be > 0", tmp1);
  }tmp2 = _k;
  if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s", "1.0 / k");}
  tmp3 = (-log(tmp1));
  tmp4 = (1.0) / tmp2;
  if(tmp3 < 0.0 && tmp4 != 0.0)
  {
    tmp6 = modf(tmp4, &tmp7);
    
    if(tmp6 > 0.5)
    {
      tmp6 -= 1.0;
      tmp7 += 1.0;
    }
    else if(tmp6 < -0.5)
    {
      tmp6 += 1.0;
      tmp7 -= 1.0;
    }
    
    if(fabs(tmp6) < 1e-10)
      tmp5 = pow(tmp3, tmp7);
    else
    {
      tmp9 = modf(1.0/tmp4, &tmp8);
      if(tmp9 > 0.5)
      {
        tmp9 -= 1.0;
        tmp8 += 1.0;
      }
      else if(tmp9 < -0.5)
      {
        tmp9 += 1.0;
        tmp8 -= 1.0;
      }
      if(fabs(tmp9) < 1e-10 && ((unsigned long)tmp8 & 1))
      {
        tmp5 = -pow(-tmp3, tmp6)*pow(tmp3, tmp7);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp3, tmp4);
      }
    }
  }
  else
  {
    tmp5 = pow(tmp3, tmp4);
  }
  if(isnan(tmp5) || isinf(tmp5))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp3, tmp4);
  }
  _y = (_lambda) * (tmp5);
  _return: OMC_LABEL_UNUSED
  return _y;
}
modelica_metatype boxptr_Outfall_invWeibull(threadData_t *threadData, modelica_metatype _u, modelica_metatype _lambda, modelica_metatype _k)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_u);
  tmp2 = mmc_unbox_real(_lambda);
  tmp3 = mmc_unbox_real(_k);
  _y = omc_Outfall_invWeibull(threadData, tmp1, tmp2, tmp3);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

#ifdef __cplusplus
}
#endif

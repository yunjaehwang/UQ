/* Asserts */
#include "OM_Result_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
 equation index: 479
 type: ALGORITHM
 
   assert(Conduction_wall1_inner.port_b.T >= 0.0, "Variable violating min constraint: 0.0 <= Conduction_wall1_inner.port_b.T, has value: " + String(Conduction_wall1_inner.port_b.T, "g"));
 */
void OM_Result_eqFunction_479(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,479};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,86,"Variable violating min constraint: 0.0 <= Conduction_wall1_inner.port_b.T, has value: ");
  modelica_string tmp2;
  static int tmp3 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp3)
  {
    tmp0 = GreaterEq(data->localData[0]->realVars[34] /* Conduction_wall1_inner._port_b._T variable */,0.0);
    if(!tmp0)
    {
      tmp2 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[34] /* Conduction_wall1_inner._port_b._T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp1),tmp2);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",2989,7,2989,56,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nConduction_wall1_inner.port_b.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp3 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 480
 type: ALGORITHM
 
   assert(Conduction_wall1_outer.port_a.T >= 0.0, "Variable violating min constraint: 0.0 <= Conduction_wall1_outer.port_a.T, has value: " + String(Conduction_wall1_outer.port_a.T, "g"));
 */
void OM_Result_eqFunction_480(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,480};
  modelica_boolean tmp4;
  static const MMC_DEFSTRINGLIT(tmp5,86,"Variable violating min constraint: 0.0 <= Conduction_wall1_outer.port_a.T, has value: ");
  modelica_string tmp6;
  static int tmp7 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp7)
  {
    tmp4 = GreaterEq(data->localData[0]->realVars[37] /* Conduction_wall1_outer._port_a._T variable */,0.0);
    if(!tmp4)
    {
      tmp6 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[37] /* Conduction_wall1_outer._port_a._T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp5),tmp6);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",2989,7,2989,56,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nConduction_wall1_outer.port_a.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp7 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 481
 type: ALGORITHM
 
   assert(Conduction_roof_outer.port_a.T >= 0.0, "Variable violating min constraint: 0.0 <= Conduction_roof_outer.port_a.T, has value: " + String(Conduction_roof_outer.port_a.T, "g"));
 */
void OM_Result_eqFunction_481(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,481};
  modelica_boolean tmp8;
  static const MMC_DEFSTRINGLIT(tmp9,85,"Variable violating min constraint: 0.0 <= Conduction_roof_outer.port_a.T, has value: ");
  modelica_string tmp10;
  static int tmp11 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp11)
  {
    tmp8 = GreaterEq(data->localData[0]->realVars[31] /* Conduction_roof_outer._port_a._T variable */,0.0);
    if(!tmp8)
    {
      tmp10 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[31] /* Conduction_roof_outer._port_a._T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp9),tmp10);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",2989,7,2989,56,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nConduction_roof_outer.port_a.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp11 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 482
 type: ALGORITHM
 
   assert(Conduction_roof_inner.port_b.T >= 0.0, "Variable violating min constraint: 0.0 <= Conduction_roof_inner.port_b.T, has value: " + String(Conduction_roof_inner.port_b.T, "g"));
 */
void OM_Result_eqFunction_482(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,482};
  modelica_boolean tmp12;
  static const MMC_DEFSTRINGLIT(tmp13,85,"Variable violating min constraint: 0.0 <= Conduction_roof_inner.port_b.T, has value: ");
  modelica_string tmp14;
  static int tmp15 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp15)
  {
    tmp12 = GreaterEq(data->localData[0]->realVars[28] /* Conduction_roof_inner._port_b._T variable */,0.0);
    if(!tmp12)
    {
      tmp14 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[28] /* Conduction_roof_inner._port_b._T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp13),tmp14);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",2989,7,2989,56,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nConduction_roof_inner.port_b.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp15 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 483
 type: ALGORITHM
 
   assert(Conduction_wall3_outer.port_a.T >= 0.0, "Variable violating min constraint: 0.0 <= Conduction_wall3_outer.port_a.T, has value: " + String(Conduction_wall3_outer.port_a.T, "g"));
 */
void OM_Result_eqFunction_483(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,483};
  modelica_boolean tmp16;
  static const MMC_DEFSTRINGLIT(tmp17,86,"Variable violating min constraint: 0.0 <= Conduction_wall3_outer.port_a.T, has value: ");
  modelica_string tmp18;
  static int tmp19 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp19)
  {
    tmp16 = GreaterEq(data->localData[0]->realVars[43] /* Conduction_wall3_outer._port_a._T variable */,0.0);
    if(!tmp16)
    {
      tmp18 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[43] /* Conduction_wall3_outer._port_a._T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp17),tmp18);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",2989,7,2989,56,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nConduction_wall3_outer.port_a.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp19 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 484
 type: ALGORITHM
 
   assert(Conduction_wall3_inner.port_b.T >= 0.0, "Variable violating min constraint: 0.0 <= Conduction_wall3_inner.port_b.T, has value: " + String(Conduction_wall3_inner.port_b.T, "g"));
 */
void OM_Result_eqFunction_484(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,484};
  modelica_boolean tmp20;
  static const MMC_DEFSTRINGLIT(tmp21,86,"Variable violating min constraint: 0.0 <= Conduction_wall3_inner.port_b.T, has value: ");
  modelica_string tmp22;
  static int tmp23 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp23)
  {
    tmp20 = GreaterEq(data->localData[0]->realVars[40] /* Conduction_wall3_inner._port_b._T variable */,0.0);
    if(!tmp20)
    {
      tmp22 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[40] /* Conduction_wall3_inner._port_b._T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp21),tmp22);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",2989,7,2989,56,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nConduction_wall3_inner.port_b.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp23 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 485
 type: ALGORITHM
 
   assert(Conduction_wall4_outer.port_a.T >= 0.0, "Variable violating min constraint: 0.0 <= Conduction_wall4_outer.port_a.T, has value: " + String(Conduction_wall4_outer.port_a.T, "g"));
 */
void OM_Result_eqFunction_485(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,485};
  modelica_boolean tmp24;
  static const MMC_DEFSTRINGLIT(tmp25,86,"Variable violating min constraint: 0.0 <= Conduction_wall4_outer.port_a.T, has value: ");
  modelica_string tmp26;
  static int tmp27 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp27)
  {
    tmp24 = GreaterEq(data->localData[0]->realVars[49] /* Conduction_wall4_outer._port_a._T variable */,0.0);
    if(!tmp24)
    {
      tmp26 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[49] /* Conduction_wall4_outer._port_a._T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp25),tmp26);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",2989,7,2989,56,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nConduction_wall4_outer.port_a.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp27 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 486
 type: ALGORITHM
 
   assert(Conduction_wall4_inner.port_b.T >= 0.0, "Variable violating min constraint: 0.0 <= Conduction_wall4_inner.port_b.T, has value: " + String(Conduction_wall4_inner.port_b.T, "g"));
 */
void OM_Result_eqFunction_486(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,486};
  modelica_boolean tmp28;
  static const MMC_DEFSTRINGLIT(tmp29,86,"Variable violating min constraint: 0.0 <= Conduction_wall4_inner.port_b.T, has value: ");
  modelica_string tmp30;
  static int tmp31 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp31)
  {
    tmp28 = GreaterEq(data->localData[0]->realVars[46] /* Conduction_wall4_inner._port_b._T variable */,0.0);
    if(!tmp28)
    {
      tmp30 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[46] /* Conduction_wall4_inner._port_b._T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp29),tmp30);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",2989,7,2989,56,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nConduction_wall4_inner.port_b.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp31 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 487
 type: ALGORITHM
 
   assert(Capacitor_roof.T >= 0.0, "Variable violating min constraint: 0.0 <= Capacitor_roof.T, has value: " + String(Capacitor_roof.T, "g"));
 */
void OM_Result_eqFunction_487(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,487};
  modelica_boolean tmp32;
  static const MMC_DEFSTRINGLIT(tmp33,71,"Variable violating min constraint: 0.0 <= Capacitor_roof.T, has value: ");
  modelica_string tmp34;
  static int tmp35 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp35)
  {
    tmp32 = GreaterEq(data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */,0.0);
    if(!tmp32)
    {
      tmp34 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[1] /* Capacitor_roof._T STATE(1,Capacitor_roof.der_T) */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp33),tmp34);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",541,7,542,33,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nCapacitor_roof.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp35 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 488
 type: ALGORITHM
 
   assert(Capacitor_wall1.T >= 0.0, "Variable violating min constraint: 0.0 <= Capacitor_wall1.T, has value: " + String(Capacitor_wall1.T, "g"));
 */
void OM_Result_eqFunction_488(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,488};
  modelica_boolean tmp36;
  static const MMC_DEFSTRINGLIT(tmp37,72,"Variable violating min constraint: 0.0 <= Capacitor_wall1.T, has value: ");
  modelica_string tmp38;
  static int tmp39 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp39)
  {
    tmp36 = GreaterEq(data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */,0.0);
    if(!tmp36)
    {
      tmp38 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[2] /* Capacitor_wall1._T STATE(1,Capacitor_wall1.der_T) */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp37),tmp38);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",541,7,542,33,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nCapacitor_wall1.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp39 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 489
 type: ALGORITHM
 
   assert(Capacitor_wall3.T >= 0.0, "Variable violating min constraint: 0.0 <= Capacitor_wall3.T, has value: " + String(Capacitor_wall3.T, "g"));
 */
void OM_Result_eqFunction_489(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,489};
  modelica_boolean tmp40;
  static const MMC_DEFSTRINGLIT(tmp41,72,"Variable violating min constraint: 0.0 <= Capacitor_wall3.T, has value: ");
  modelica_string tmp42;
  static int tmp43 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp43)
  {
    tmp40 = GreaterEq(data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */,0.0);
    if(!tmp40)
    {
      tmp42 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[3] /* Capacitor_wall3._T STATE(1,Capacitor_wall3.der_T) */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp41),tmp42);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",541,7,542,33,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nCapacitor_wall3.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp43 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 490
 type: ALGORITHM
 
   assert(Capacitor_wall4.T >= 0.0, "Variable violating min constraint: 0.0 <= Capacitor_wall4.T, has value: " + String(Capacitor_wall4.T, "g"));
 */
void OM_Result_eqFunction_490(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,490};
  modelica_boolean tmp44;
  static const MMC_DEFSTRINGLIT(tmp45,72,"Variable violating min constraint: 0.0 <= Capacitor_wall4.T, has value: ");
  modelica_string tmp46;
  static int tmp47 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp47)
  {
    tmp44 = GreaterEq(data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */,0.0);
    if(!tmp44)
    {
      tmp46 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[4] /* Capacitor_wall4._T STATE(1,Capacitor_wall4.der_T) */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp45),tmp46);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",541,7,542,33,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nCapacitor_wall4.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp47 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 491
 type: ALGORITHM
 
   assert(Capacitor_indoor_air.T >= 0.0, "Variable violating min constraint: 0.0 <= Capacitor_indoor_air.T, has value: " + String(Capacitor_indoor_air.T, "g"));
 */
void OM_Result_eqFunction_491(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,491};
  modelica_boolean tmp48;
  static const MMC_DEFSTRINGLIT(tmp49,77,"Variable violating min constraint: 0.0 <= Capacitor_indoor_air.T, has value: ");
  modelica_string tmp50;
  static int tmp51 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp51)
  {
    tmp48 = GreaterEq(data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */,0.0);
    if(!tmp48)
    {
      tmp50 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[0] /* Capacitor_indoor_air._T STATE(1,Capacitor_indoor_air.der_T) */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp49),tmp50);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",541,7,542,33,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nCapacitor_indoor_air.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp51 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 492
 type: ALGORITHM
 
   assert(multiProduct1.u[3] >= 0.0, "Variable violating min constraint: 0.0 <= multiProduct1.u[3], has value: " + String(multiProduct1.u[3], "g"));
 */
void OM_Result_eqFunction_492(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,492};
  modelica_boolean tmp52;
  static const MMC_DEFSTRINGLIT(tmp53,73,"Variable violating min constraint: 0.0 <= multiProduct1.u[3], has value: ");
  modelica_string tmp54;
  static int tmp55 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp55)
  {
    tmp52 = GreaterEq(data->localData[0]->realVars[118] /* multiProduct1._u[3] variable */,0.0);
    if(!tmp52)
    {
      tmp54 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[118] /* multiProduct1._u[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp53),tmp54);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",397,5,398,75,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nmultiProduct1.u[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp55 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 493
 type: ALGORITHM
 
   assert(SkyTemperatureToK.T >= 0.0, "Variable violating min constraint: 0.0 <= SkyTemperatureToK.T, has value: " + String(SkyTemperatureToK.T, "g"));
 */
void OM_Result_eqFunction_493(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,493};
  modelica_boolean tmp56;
  static const MMC_DEFSTRINGLIT(tmp57,74,"Variable violating min constraint: 0.0 <= SkyTemperatureToK.T, has value: ");
  modelica_string tmp58;
  static int tmp59 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp59)
  {
    tmp56 = GreaterEq(data->localData[0]->realVars[106] /* SkyTemperatureToK._T variable */,0.0);
    if(!tmp56)
    {
      tmp58 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[106] /* SkyTemperatureToK._T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp57),tmp58);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Thermal/HeatTransfer.mo",1739,7,1740,47,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nSkyTemperatureToK.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp59 = 1;
    }
  }
  TRACE_POP
}
/* function to check assert after a step is done */
int OM_Result_checkForAsserts(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  OM_Result_eqFunction_479(data, threadData);

  OM_Result_eqFunction_480(data, threadData);

  OM_Result_eqFunction_481(data, threadData);

  OM_Result_eqFunction_482(data, threadData);

  OM_Result_eqFunction_483(data, threadData);

  OM_Result_eqFunction_484(data, threadData);

  OM_Result_eqFunction_485(data, threadData);

  OM_Result_eqFunction_486(data, threadData);

  OM_Result_eqFunction_487(data, threadData);

  OM_Result_eqFunction_488(data, threadData);

  OM_Result_eqFunction_489(data, threadData);

  OM_Result_eqFunction_490(data, threadData);

  OM_Result_eqFunction_491(data, threadData);

  OM_Result_eqFunction_492(data, threadData);

  OM_Result_eqFunction_493(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif


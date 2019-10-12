/* Linearization */
#include "OM_Result_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

const char *OM_Result_linear_model_frame()
{
  return "model linear_Outfall\n  parameter Integer n = 5; // states\n  parameter Integer k = 0; // top-level inputs\n  parameter Integer l = 0; // top-level outputs\n"
  "  parameter Real x0[5] = {%s};\n"
  "  parameter Real u0[0] = {%s};\n"
  "  parameter Real A[5,5] = [%s];\n"
  "  parameter Real B[5,0] = zeros(5,0);%s\n"
  "  parameter Real C[0,5] = zeros(0,5);%s\n"
  "  parameter Real D[0,0] = zeros(0,0);%s\n"
  "  Real x[5](start=x0);\n"
  "  input Real u[0];\n"
  "  output Real y[0];\n"
  "\n  Real 'x_Capacitor_indoor_air.T' = x[1];\nReal 'x_Capacitor_roof.T' = x[2];\nReal 'x_Capacitor_wall1.T' = x[3];\nReal 'x_Capacitor_wall3.T' = x[4];\nReal 'x_Capacitor_wall4.T' = x[5];\n\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linear_Outfall;\n";
}
const char *OM_Result_linear_model_datarecovery_frame()
{
  return "model linear_Outfall\n  parameter Integer n = 5; // states\n  parameter Integer k = 0; // top-level inputs\n  parameter Integer l = 0; // top-level outputs\n  parameter Integer nz = 125; // data recovery variables\n"
  "  parameter Real x0[5] = {%s};\n"
  "  parameter Real u0[0] = {%s};\n"
  "  parameter Real z0[125] = {%s};\n"
  "  parameter Real A[5,5] = [%s];\n"
  "  parameter Real B[5,0] = zeros(5,0);%s\n"
  "  parameter Real C[0,5] = zeros(0,5);%s\n"
  "  parameter Real D[0,0] = zeros(0,0);%s\n"
  "  parameter Real Cz[125,5] = [%s];\n"
  "  parameter Real Dz[125,0] = zeros(125,0);%s\n"
  "  Real x[5](start=x0);\n"
  "  input Real u[0];\n"
  "  output Real y[0];\n"
  "  output Real z[125];\n"
  "\nReal 'x_Capacitor_indoor_air.T' = x[1];\nReal 'x_Capacitor_roof.T' = x[2];\nReal 'x_Capacitor_wall1.T' = x[3];\nReal 'x_Capacitor_wall3.T' = x[4];\nReal 'x_Capacitor_wall4.T' = x[5];\nReal 'z_$cse1' = z[1];\nReal 'z_$cse2' = z[2];\nReal 'z_$cse3' = z[3];\nReal 'z_$cse4' = z[4];\nReal 'z_$cse5' = z[5];\nReal 'z_$cse6' = z[6];\nReal 'z_$cse7' = z[7];\nReal 'z_Capacitor_indoor_air.der_T' = z[8];\nReal 'z_Capacitor_indoor_air.port.Q_flow' = z[9];\nReal 'z_Capacitor_roof.der_T' = z[10];\nReal 'z_Capacitor_roof.port.Q_flow' = z[11];\nReal 'z_Capacitor_wall1.der_T' = z[12];\nReal 'z_Capacitor_wall1.port.Q_flow' = z[13];\nReal 'z_Capacitor_wall3.der_T' = z[14];\nReal 'z_Capacitor_wall3.port.Q_flow' = z[15];\nReal 'z_Capacitor_wall4.der_T' = z[16];\nReal 'z_Capacitor_wall4.port.Q_flow' = z[17];\nReal 'z_Conduction_roof_inner.Q_flow' = z[18];\nReal 'z_Conduction_roof_inner.dT' = z[19];\nReal 'z_Conduction_roof_inner.port_b.T' = z[20];\nReal 'z_Conduction_roof_outer.Q_flow' = z[21];\nReal 'z_Conduction_roof_outer.dT' = z[22];\nReal 'z_Conduction_roof_outer.port_a.T' = z[23];\nReal 'z_Conduction_wall1_inner.Q_flow' = z[24];\nReal 'z_Conduction_wall1_inner.dT' = z[25];\nReal 'z_Conduction_wall1_inner.port_b.T' = z[26];\nReal 'z_Conduction_wall1_outer.Q_flow' = z[27];\nReal 'z_Conduction_wall1_outer.dT' = z[28];\nReal 'z_Conduction_wall1_outer.port_a.T' = z[29];\nReal 'z_Conduction_wall3_inner.Q_flow' = z[30];\nReal 'z_Conduction_wall3_inner.dT' = z[31];\nReal 'z_Conduction_wall3_inner.port_b.T' = z[32];\nReal 'z_Conduction_wall3_outer.Q_flow' = z[33];\nReal 'z_Conduction_wall3_outer.dT' = z[34];\nReal 'z_Conduction_wall3_outer.port_a.T' = z[35];\nReal 'z_Conduction_wall4_inner.Q_flow' = z[36];\nReal 'z_Conduction_wall4_inner.dT' = z[37];\nReal 'z_Conduction_wall4_inner.port_b.T' = z[38];\nReal 'z_Conduction_wall4_outer.Q_flow' = z[39];\nReal 'z_Conduction_wall4_outer.dT' = z[40];\nReal 'z_Conduction_wall4_outer.port_a.T' = z[41];\nReal 'z_Convection_floor.Q_flow' = z[42];\nReal 'z_Convection_floor.dT' = z[43];\nReal 'z_Convection_roof_inner.Q_flow' = z[44];\nReal 'z_Convection_roof_inner.dT' = z[45];\nReal 'z_Convection_roof_outer.Gc' = z[46];\nReal 'z_Convection_roof_outer.Q_flow' = z[47];\nReal 'z_Convection_roof_outer.dT' = z[48];\nReal 'z_Convection_wall1_inner.Q_flow' = z[49];\nReal 'z_Convection_wall1_inner.dT' = z[50];\nReal 'z_Convection_wall1_outer.Gc' = z[51];\nReal 'z_Convection_wall1_outer.Q_flow' = z[52];\nReal 'z_Convection_wall1_outer.dT' = z[53];\nReal 'z_Convection_wall3_inner.Q_flow' = z[54];\nReal 'z_Convection_wall3_inner.dT' = z[55];\nReal 'z_Convection_wall3_outer.Gc' = z[56];\nReal 'z_Convection_wall3_outer.Q_flow' = z[57];\nReal 'z_Convection_wall3_outer.dT' = z[58];\nReal 'z_Convection_wall4_inner.Q_flow' = z[59];\nReal 'z_Convection_wall4_inner.dT' = z[60];\nReal 'z_Convection_wall4_outer.Gc' = z[61];\nReal 'z_Convection_wall4_outer.Q_flow' = z[62];\nReal 'z_Convection_wall4_outer.dT' = z[63];\nReal 'z_Data_outdoor_temperature.timeScaled' = z[64];\nReal 'z_Data_outdoor_temperature.y[1]' = z[65];\nReal 'z_Data_outdoor_temperature.y[2]' = z[66];\nReal 'z_Data_solar_radiation.timeScaled' = z[67];\nReal 'z_Data_solar_radiation.y[1]' = z[68];\nReal 'z_Data_solar_radiation.y[2]' = z[69];\nReal 'z_Data_wind_speed.timeScaled' = z[70];\nReal 'z_Data_wind_speed.y[1]' = z[71];\nReal 'z_Data_wind_speed.y[2]' = z[72];\nReal 'z_Heatflow_infiltration.Q_flow' = z[73];\nReal 'z_Heatflow_solar_radiation.Q_flow' = z[74];\nReal 'z_Heatflow_solar_radiation.port.Q_flow' = z[75];\nReal 'z_OutdoorTemperature' = z[76];\nReal 'z_OutdoorTemperatureToK.port.Q_flow' = z[77];\nReal 'z_Radiation_floor.Q_flow' = z[78];\nReal 'z_Radiation_floor.dT' = z[79];\nReal 'z_Radiation_roof_inner.Q_flow' = z[80];\nReal 'z_Radiation_roof_inner.dT' = z[81];\nReal 'z_Radiation_roof_outer.Q_flow' = z[82];\nReal 'z_Radiation_roof_outer.dT' = z[83];\nReal 'z_Radiation_roof_to_floor.Q_flow' = z[84];\nReal 'z_Radiation_roof_to_floor.dT' = z[85];\nReal 'z_Radiation_wall1_inner.Q_flow' = z[86];\nReal 'z_Radiation_wall1_inner.dT' = z[87];\nReal 'z_Radiation_wall1_outer.Q_flow' = z[88];\nReal 'z_Radiation_wall1_outer.dT' = z[89];\nReal 'z_Radiation_wall3_inner.Q_flow' = z[90];\nReal 'z_Radiation_wall3_inner.dT' = z[91];\nReal 'z_Radiation_wall3_outer.Q_flow' = z[92];\nReal 'z_Radiation_wall3_outer.dT' = z[93];\nReal 'z_Radiation_wall4_inner.Q_flow' = z[94];\nReal 'z_Radiation_wall4_inner.dT' = z[95];\nReal 'z_Radiation_wall4_outer.Q_flow' = z[96];\nReal 'z_Radiation_wall4_outer.dT' = z[97];\nReal 'z_SkyTemperatureToK.T' = z[98];\nReal 'z_SolarRadiation' = z[99];\nReal 'z_Temperature_Indoor.port.Q_flow' = z[100];\nReal 'z_Temperature_difference.y' = z[101];\nReal 'z_Temperature_floor.port.Q_flow' = z[102];\nReal 'z_WindSpeed' = z[103];\nReal 'z_exp1.u' = z[104];\nReal 'z_exp1.y' = z[105];\nReal 'z_log1.y' = z[106];\nReal 'z_multiProduct1.u[2]' = z[107];\nReal 'z_product4.y' = z[108];\nReal 'z_thermalCollector1.port_a[11].Q_flow' = z[109];\nReal 'z_thermalCollector1.port_a[12].Q_flow' = z[110];\nReal 'z_two_single_ventilation1.Heat_flow_NV.Q_flow' = z[111];\nReal 'z_two_single_ventilation1.Indoor_temperature.port.Q_flow' = z[112];\nReal 'z_two_single_ventilation1.U_square.y' = z[113];\nReal 'z_two_single_ventilation1.Ventilation_rate.u1' = z[114];\nReal 'z_two_single_ventilation1.Ventilation_rate.u2' = z[115];\nReal 'z_two_single_ventilation1.multiProduct1.u[3]' = z[116];\nReal 'z_two_single_ventilation1.multiProduct3.u[3]' = z[117];\nReal 'z_two_single_ventilation1.multiProduct4.u[3]' = z[118];\nReal 'z_two_single_ventilation1.multiProduct5.u[2]' = z[119];\nReal 'z_two_single_ventilation1.multiProduct5.u[3]' = z[120];\nReal 'z_two_single_ventilation1.multiSum1.u[1]' = z[121];\nReal 'z_two_single_ventilation1.multiSum1.u[2]' = z[122];\nReal 'z_two_single_ventilation1.multiSum1.y' = z[123];\nReal 'z_two_single_ventilation1.multiSum2.u[2]' = z[124];\nReal 'z_two_single_ventilation1.multiSum2.y' = z[125];\n\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linear_Outfall;\n";
}
#if defined(__cplusplus)
}
#endif


model Outfall
  Modelica.Thermal.HeatTransfer.Sensors.TemperatureSensor Temperature_Indoor annotation(
    Placement(visible = true, transformation(origin = {136, 82}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_wall1_inner(G = 33.10 * 54.0832) annotation(
    Placement(visible = true, transformation(origin = {-46, 44}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_wall1_outer(G = 33.10 * 54.0832) annotation(
    Placement(visible = true, transformation(origin = {-86, 44}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_roof_outer(G = 122861.25 * 1.0575) annotation(
    Placement(visible = true, transformation(origin = {-94, 102}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_roof_inner(G = 122861.25 * 1.0575) annotation(
    Placement(visible = true, transformation(origin = {-46, 102}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_wall3_outer(G = 30.86 * 54.0832) annotation(
    Placement(visible = true, transformation(origin = {-86, -6}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_wall3_inner(G = 30.86 * 54.0832) annotation(
    Placement(visible = true, transformation(origin = {-46, -6}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_wall4_outer(G = 23.73 * 54.0832) annotation(
    Placement(visible = true, transformation(origin = {-86, -46}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_wall4_inner(G = 23.73 * 54.0832) annotation(
    Placement(visible = true, transformation(origin = {-46, -46}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.HeatCapacitor Capacitor_roof(C = 22427, T(fixed = true, start = 313.15)) annotation(
    Placement(visible = true, transformation(origin = {-66, 112}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.HeatCapacitor Capacitor_wall1(C = 1700 * 800 * 3.14 * 2.51 * 0.125, T(fixed = true, start = 301.15)) annotation(
    Placement(visible = true, transformation(origin = {-66, 54}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.HeatCapacitor Capacitor_wall3(C = 1700 * 800 * 3.14 * 2.33 * 0.125, T(fixed = true, start = 301.15)) annotation(
    Placement(visible = true, transformation(origin = {-66, 4}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.HeatCapacitor Capacitor_wall4(C = 1700 * 800 * 2.43 * 2.33 * 0.125, T(fixed = true, start = 301.15)) annotation(
    Placement(visible = true, transformation(origin = {-66, -36}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.Convection Convection_roof_inner annotation(
    Placement(visible = true, transformation(origin = {-6, 120}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.Convection Convection_wall1_inner annotation(
    Placement(visible = true, transformation(origin = {-6, 54}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.Convection Convection_wall3_inner annotation(
    Placement(visible = true, transformation(origin = {-6, 8}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.Convection Convection_wall4_inner annotation(
    Placement(visible = true, transformation(origin = {-6, -46}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.Convection Convection_roof_outer annotation(
    Placement(visible = true, transformation(origin = {-126, 116}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.Convection Convection_wall1_outer annotation(
    Placement(visible = true, transformation(origin = {-126, 58}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.Convection Convection_wall4_outer annotation(
    Placement(visible = true, transformation(origin = {-126, -46}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.Convection Convection_wall3_outer annotation(
    Placement(visible = true, transformation(origin = {-126, 4}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_roof_outer(Gr = 7.335 * 0.14229) annotation(
    Placement(visible = true, transformation(origin = {-128, 98}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_wall1_outer(Gr = 7.881 * 0.85822) annotation(
    Placement(visible = true, transformation(origin = {-126, 34}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_wall3_outer(Gr = 7.348 * 0.85822) annotation(
    Placement(visible = true, transformation(origin = {-126, -14}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_wall4_outer(Gr = 5.650 * 0.85822) annotation(
    Placement(visible = true, transformation(origin = {-124, -72}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.HeatCapacitor Capacitor_indoor_air(C = 21841, T(fixed = true, start = 301.15)) annotation(
    Placement(visible = true, transformation(origin = {114, 112}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalCollector thermalCollector1(m = 12) annotation(
    Placement(visible = true, transformation(origin = {92, 88}, extent = {{-10, -10}, {10, 10}}, rotation = 90)));
  Modelica.Thermal.HeatTransfer.Components.Convection Convection_floor annotation(
    Placement(visible = true, transformation(origin = {-2, -92}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow Heatflow_solar_radiation annotation(
    Placement(visible = true, transformation(origin = {-122, 154}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedTemperature Temperature_floor annotation(
    Placement(visible = true, transformation(origin = {-106, -114}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Infiltration(k = 4.75 * 17.74 / 3600 * 1005 * 1.225 * 1.1403) annotation(
    Placement(visible = true, transformation(origin = {118, -54}, extent = {{-10, -10}, {10, 10}}, rotation = 90)));
  Modelica.Blocks.Math.Product product1 annotation(
    Placement(visible = true, transformation(origin = {98, -16}, extent = {{-10, -10}, {10, 10}}, rotation = 90)));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow Heatflow_infiltration annotation(
    Placement(visible = true, transformation(origin = {96, 16}, extent = {{10, 10}, {-10, -10}}, rotation = -90)));
  Modelica.Blocks.Sources.CombiTimeTable Data_solar_radiation(columns = 2:3,fileName = "/home/yunjaeh/github/UQ/MonteCarlo/weatherInputs/Night_0206.mat", tableName = "RADIATION", tableOnFile = true, timeScale = 60) annotation(
    Placement(visible = true, transformation(origin = {-352, 146}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.CombiTimeTable Data_outdoor_temperature(columns = 2:3,fileName = "/home/yunjaeh/github/UQ/MonteCarlo/weatherInputs/Night_0206.mat", tableName = "TEMPERATURE", tableOnFile = true, timeScale = 60) annotation(
    Placement(visible = true, transformation(origin = {-374, -46}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Convection_coef_roof_inner(k = 7.335 * 3.4442) annotation(
    Placement(visible = true, transformation(origin = {-32, 142}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Convection_coef_wall4_inner(k = 5.650 * 3.4442) annotation(
    Placement(visible = true, transformation(origin = {-26, -30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Convection_coef_floor(k = 7.316 * 3.4442) annotation(
    Placement(visible = true, transformation(origin = {-52, -78}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_roof_inner(Gr = 7.335 * 0.14229) annotation(
    Placement(visible = true, transformation(origin = {-6, 92}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_wall1_inner(Gr = 7.881 * 0.85822) annotation(
    Placement(visible = true, transformation(origin = {-6, 34}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_wall3_inner(Gr = 7.348 * 0.85822) annotation(
    Placement(visible = true, transformation(origin = {-6, -16}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_wall4_inner(Gr = 5.650 * 0.85822) annotation(
    Placement(visible = true, transformation(origin = {-6, -66}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_floor(Gr = 7.316 * 0.85) annotation(
    Placement(visible = true, transformation(origin = {-2, -122}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Convection_coef_wall1_inner(k = 7.881 * 3.4442) annotation(
    Placement(visible = true, transformation(origin = {-32, 74}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Convection_coef_wall3_inner(k = 7.348 * 3.4442) annotation(
    Placement(visible = true, transformation(origin = {-38, 20}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product2 annotation(
    Placement(visible = true, transformation(origin = {-232, 152}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant roof_emissivity(k = 7.3162 * 14.86 / 20.0 * (1 - 0.6)) annotation(
    Placement(visible = true, transformation(origin = {-266, 130}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Floor_temperature(k = 299.15) annotation(
    Placement(visible = true, transformation(origin = {-148, -112}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Sqrt sqrt1 annotation(
    Placement(visible = true, transformation(origin = {-312, 62}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant const(k = 0.0552) annotation(
    Placement(visible = true, transformation(origin = {-312, 92}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.MultiProduct multiProduct1(nu = 3) annotation(
    Placement(visible = true, transformation(origin = {-278, 90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.CombiTimeTable Data_wind_speed(columns = 2:3,fileName = "/home/yunjaeh/github/UQ/MonteCarlo/weatherInputs/Night_0206.mat", tableName = "WIND", tableOnFile = true, timeScale = 60) annotation(
    Placement(visible = true, transformation(origin = {-378, -122}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Add Temperature_difference(k1 = +1, k2 = -1) annotation(
    Placement(visible = true, transformation(origin = {90, -76}, extent = {{-10, -10}, {10, 10}}, rotation = 90)));
  Two_single_ventilation two_single_ventilation1 annotation(
    Placement(visible = true, transformation(origin = {62, -36}, extent = {{-10, -10}, {10, 10}}, rotation = 90)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_roof_to_floor(Gr = 7.22 * 0.85 * 0.14229) annotation(
    Placement(visible = true, transformation(origin = {32, 134}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Convection_A(k = 3.64 * 2.4596) annotation(
    Placement(visible = true, transformation(origin = {-220, -180}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Convection_B(k = 0.84) annotation(
    Placement(visible = true, transformation(origin = {-286, -168}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Exp exp1 annotation(
    Placement(visible = true, transformation(origin = {-220, -152}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Log log1 annotation(
    Placement(visible = true, transformation(origin = {-284, -142}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product3 annotation(
    Placement(visible = true, transformation(origin = {-252, -152}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product4 annotation(
    Placement(visible = true, transformation(origin = {-194, -164}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product5 annotation(
    Placement(visible = true, transformation(origin = {-156, 134}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product6 annotation(
    Placement(visible = true, transformation(origin = {-156, 78}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product7 annotation(
    Placement(visible = true, transformation(origin = {-162, 22}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product8 annotation(
    Placement(visible = true, transformation(origin = {-158, -30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Area_roof(k = 7.335) annotation(
    Placement(visible = true, transformation(origin = {-184, 134}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Area_wall1(k = 7.881) annotation(
    Placement(visible = true, transformation(origin = {-186, 78}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Area_wall3(k = 7.348) annotation(
    Placement(visible = true, transformation(origin = {-192, 28}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Area_wall4(k = 5.650) annotation(
    Placement(visible = true, transformation(origin = {-192, -28}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product StdTemperature annotation(
    Placement(visible = true, transformation(origin = {-342, -20}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Add OutdoorTemperature annotation(
    Placement(visible = true, transformation(origin = {-308, -28}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Add WindSpeed annotation(
    Placement(visible = true, transformation(origin = {-308, -108}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Add SolarRadiation annotation(
    Placement(visible = true, transformation(origin = {-282, 164}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product StdWindSpeed annotation(
    Placement(visible = true, transformation(origin = {-340, -102}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product StdSolarRadiation annotation(
    Placement(visible = true, transformation(origin = {-316, 170}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant FactorStdTemperature(k = 1.0) annotation(
    Placement(visible = true, transformation(origin = {-374, -12}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant FactorStdWindSpeed(k = 1.0) annotation(
    Placement(visible = true, transformation(origin = {-368, -90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant FactorStdSolarRadiation(k = 1.0)  annotation(
    Placement(visible = true, transformation(origin = {-344, 176}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedTemperature OutdoorTemperatureToK annotation(
    Placement(visible = true, transformation(origin = {-266, -28}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedTemperature SkyTemperatureToK annotation(
    Placement(visible = true, transformation(origin = {-242, 90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(OutdoorTemperature.y, multiProduct1.u[3]) annotation(
    Line(points = {{-296, -28}, {-300, -28}, {-300, 88}, {-288, 88}, {-288, 90}}, color = {0, 0, 127}));
  connect(Infiltration.y, product1.u2) annotation(
    Line(points = {{118, -43}, {104, -43}, {104, -28}}, color = {0, 0, 127}));
  connect(product1.y, Heatflow_infiltration.Q_flow) annotation(
    Line(points = {{98, -5}, {98, 1.5}, {96, 1.5}, {96, 6}}, color = {0, 0, 127}));
  connect(Temperature_difference.y, product1.u1) annotation(
    Line(points = {{90, -65}, {90, -45.5}, {92, -45.5}, {92, -28}}, color = {0, 0, 127}));
  connect(Data_wind_speed.y[2], StdWindSpeed.u2) annotation(
    Line(points = {{-367, -122}, {-366, -122}, {-366, -108}, {-352, -108}}, color = {0, 0, 127}, thickness = 0.5));
  connect(Data_wind_speed.y[1], WindSpeed.u2) annotation(
    Line(points = {{-367, -122}, {-320, -122}, {-320, -114}}, color = {0, 0, 127}, thickness = 0.5));
  connect(OutdoorTemperatureToK.port, Convection_wall1_outer.solid) annotation(
    Line(points = {{-256, -28}, {-236, -28}, {-236, 58}, {-136, 58}}, color = {191, 0, 0}));
  connect(Convection_wall1_outer.fluid, Conduction_wall1_outer.port_a) annotation(
    Line(points = {{-116, 58}, {-96, 58}, {-96, 44}}, color = {191, 0, 0}));
  connect(product6.y, Convection_wall1_outer.Gc) annotation(
    Line(points = {{-144, 78}, {-128, 78}, {-128, 68}, {-126, 68}}, color = {0, 0, 127}));
  connect(Radiation_roof_to_floor.port_b, Temperature_floor.port) annotation(
    Line(points = {{42, 134}, {46, 134}, {46, -114}, {-96, -114}}, color = {191, 0, 0}));
  connect(Conduction_roof_inner.port_b, Radiation_roof_to_floor.port_a) annotation(
    Line(points = {{-36, 102}, {22, 102}, {22, 134}}, color = {191, 0, 0}));
  connect(Capacitor_indoor_air.port, Temperature_Indoor.port) annotation(
    Line(points = {{114, 102}, {114, 90}, {126, 90}, {126, 82}}, color = {191, 0, 0}));
  connect(thermalCollector1.port_b, Capacitor_indoor_air.port) annotation(
    Line(points = {{102, 88}, {114, 88}, {114, 102}}, color = {191, 0, 0}));
  connect(OutdoorTemperature.y, two_single_ventilation1.Port_outdoor) annotation(
    Line(points = {{-296, -28}, {-264, -28}, {-264, -126}, {68, -126}, {68, -46}}, color = {0, 0, 127}));
  connect(WindSpeed.y, two_single_ventilation1.U) annotation(
    Line(points = {{-297, -108}, {-168, -108}, {-168, -142}, {56, -142}, {56, -46}}, color = {0, 0, 127}));
  connect(two_single_ventilation1.Port_indoor, thermalCollector1.port_a[11]) annotation(
    Line(points = {{62, -26}, {57, -26}, {57, -20}, {64, -20}, {64, 85}, {70, 85}, {70, 88}, {82, 88}}, color = {191, 0, 0}));
  connect(Convection_roof_inner.fluid, thermalCollector1.port_a[1]) annotation(
    Line(points = {{4, 120}, {40, 120}, {40, 88}, {82, 88}}, color = {191, 0, 0}));
  connect(Convection_wall4_inner.fluid, thermalCollector1.port_a[7]) annotation(
    Line(points = {{4, -46}, {40, -46}, {40, 88}, {82, 88}}, color = {191, 0, 0}));
  connect(Convection_wall3_inner.fluid, thermalCollector1.port_a[5]) annotation(
    Line(points = {{4, 8}, {40, 8}, {40, 88}, {82, 88}}, color = {191, 0, 0}));
  connect(Convection_wall1_inner.fluid, thermalCollector1.port_a[3]) annotation(
    Line(points = {{4, 54}, {40, 54}, {40, 88}, {82, 88}}, color = {191, 0, 0}));
  connect(Convection_floor.fluid, thermalCollector1.port_a[9]) annotation(
    Line(points = {{8, -92}, {40, -92}, {40, 88}, {82, 88}}, color = {191, 0, 0}));
  connect(Heatflow_infiltration.port, thermalCollector1.port_a[12]) annotation(
    Line(points = {{96, 26}, {82, 26}, {82, 88}}, color = {191, 0, 0}));
  connect(Radiation_roof_inner.port_b, thermalCollector1.port_a[2]) annotation(
    Line(points = {{4, 92}, {32, 92}, {32, 88}, {82, 88}}, color = {191, 0, 0}));
  connect(Radiation_wall1_inner.port_b, thermalCollector1.port_a[4]) annotation(
    Line(points = {{4, 34}, {40, 34}, {40, 88}, {82, 88}}, color = {191, 0, 0}));
  connect(Radiation_wall3_inner.port_b, thermalCollector1.port_a[6]) annotation(
    Line(points = {{4, -16}, {40, -16}, {40, 88}, {82, 88}}, color = {191, 0, 0}));
  connect(Radiation_wall4_inner.port_b, thermalCollector1.port_a[8]) annotation(
    Line(points = {{4, -66}, {40, -66}, {40, 88}, {82, 88}}, color = {191, 0, 0}));
  connect(Radiation_floor.port_b, thermalCollector1.port_a[10]) annotation(
    Line(points = {{8, -122}, {40, -122}, {40, 88}, {82, 88}}, color = {191, 0, 0}));
  connect(OutdoorTemperature.y, Temperature_difference.u1) annotation(
    Line(points = {{-296, -28}, {-286, -28}, {-286, -134}, {84, -134}, {84, -88}, {84, -88}}, color = {0, 0, 127}));
  connect(OutdoorTemperatureToK.port, Convection_roof_outer.solid) annotation(
    Line(points = {{-256, -28}, {-218, -28}, {-218, 116}, {-136, 116}, {-136, 116}}, color = {191, 0, 0}));
  connect(OutdoorTemperatureToK.port, Radiation_wall1_outer.port_a) annotation(
    Line(points = {{-256, -28}, {-236, -28}, {-236, 34}, {-136, 34}, {-136, 34}}, color = {191, 0, 0}));
  connect(OutdoorTemperatureToK.port, Convection_wall3_outer.solid) annotation(
    Line(points = {{-256, -28}, {-228, -28}, {-228, 4}, {-136, 4}}, color = {191, 0, 0}));
  connect(OutdoorTemperatureToK.port, Radiation_wall3_outer.port_a) annotation(
    Line(points = {{-256, -28}, {-228, -28}, {-228, -14}, {-136, -14}, {-136, -14}}, color = {191, 0, 0}));
  connect(OutdoorTemperatureToK.port, Convection_wall4_outer.solid) annotation(
    Line(points = {{-256, -28}, {-220, -28}, {-220, -46}, {-136, -46}, {-136, -46}, {-136, -46}}, color = {191, 0, 0}));
  connect(OutdoorTemperatureToK.port, Radiation_wall4_outer.port_a) annotation(
    Line(points = {{-256, -28}, {-238, -28}, {-238, -72}, {-134, -72}, {-134, -72}}, color = {191, 0, 0}));
  connect(Area_wall4.y, product8.u1) annotation(
    Line(points = {{-181, -28}, {-172, -28}, {-172, -24}, {-170, -24}}, color = {0, 0, 127}));
  connect(SkyTemperatureToK.port, Radiation_roof_outer.port_a) annotation(
    Line(points = {{-232, 90}, {-210, 90}, {-210, 98}, {-138, 98}, {-138, 98}}, color = {191, 0, 0}));
  connect(multiProduct1.y, SkyTemperatureToK.T) annotation(
    Line(points = {{-266, 90}, {-256, 90}, {-256, 90}, {-254, 90}}, color = {0, 0, 127}));
  connect(const.y, multiProduct1.u[1]) annotation(
    Line(points = {{-301, 92}, {-294.5, 92}, {-294.5, 90}, {-288, 90}}, color = {0, 0, 127}));
  connect(OutdoorTemperature.y, sqrt1.u) annotation(
    Line(points = {{-296, -28}, {-290, -28}, {-290, 42}, {-330, 42}, {-330, 62}, {-324, 62}}, color = {0, 0, 127}));
  connect(sqrt1.y, multiProduct1.u[2]) annotation(
    Line(points = {{-301, 62}, {-288, 62}, {-288, 90}}, color = {0, 0, 127}));
  connect(OutdoorTemperature.y, OutdoorTemperatureToK.T) annotation(
    Line(points = {{-296, -28}, {-278, -28}, {-278, -28}, {-278, -28}}, color = {0, 0, 127}));
  connect(WindSpeed.y, log1.u) annotation(
    Line(points = {{-297, -108}, {-306, -108}, {-306, -142}, {-296, -142}}, color = {0, 0, 127}));
  connect(log1.y, product3.u1) annotation(
    Line(points = {{-273, -142}, {-273, -144}, {-265, -144}, {-265, -146}}, color = {0, 0, 127}));
  connect(Area_wall3.y, product7.u1) annotation(
    Line(points = {{-181, 28}, {-174, 28}}, color = {0, 0, 127}));
  connect(Radiation_wall4_outer.port_b, Conduction_wall4_outer.port_a) annotation(
    Line(points = {{-114, -72}, {-96, -72}, {-96, -46}}, color = {191, 0, 0}));
  connect(SolarRadiation.y, product2.u1) annotation(
    Line(points = {{-270, 164}, {-254, 164}, {-254, 158}, {-244, 158}, {-244, 158}}, color = {0, 0, 127}));
  connect(FactorStdSolarRadiation.y, StdSolarRadiation.u1) annotation(
    Line(points = {{-332, 176}, {-328, 176}, {-328, 176}, {-328, 176}}, color = {0, 0, 127}));
  connect(StdSolarRadiation.y, SolarRadiation.u1) annotation(
    Line(points = {{-304, 170}, {-294, 170}, {-294, 170}, {-294, 170}}, color = {0, 0, 127}));
  connect(Data_solar_radiation.y[1], SolarRadiation.u2) annotation(
    Line(points = {{-340, 146}, {-314, 146}, {-314, 158}, {-294, 158}, {-294, 158}}, color = {0, 0, 127}, thickness = 0.5));
  connect(Data_solar_radiation.y[2], StdSolarRadiation.u2) annotation(
    Line(points = {{-340, 146}, {-332, 146}, {-332, 164}, {-328, 164}, {-328, 164}}, color = {0, 0, 127}, thickness = 0.5));
  connect(StdWindSpeed.y, WindSpeed.u1) annotation(
    Line(points = {{-328, -102}, {-320, -102}, {-320, -102}, {-320, -102}}, color = {0, 0, 127}));
  connect(exp1.y, product4.u1) annotation(
    Line(points = {{-209, -152}, {-207, -152}, {-207, -155}, {-207, -155}, {-207, -158}}, color = {0, 0, 127}));
  connect(Convection_A.y, product4.u2) annotation(
    Line(points = {{-209, -180}, {-208, -180}, {-208, -180}, {-207, -180}, {-207, -175}, {-207, -175}, {-207, -170}}, color = {0, 0, 127}));
  connect(product4.y, product8.u2) annotation(
    Line(points = {{-183, -164}, {-174, -164}, {-174, -36}, {-170, -36}}, color = {0, 0, 127}));
  connect(product4.y, product7.u2) annotation(
    Line(points = {{-183, -164}, {-174, -164}, {-174, 16}}, color = {0, 0, 127}));
  connect(product4.y, product6.u2) annotation(
    Line(points = {{-183, -164}, {-170, -164}, {-170, 72}, {-168, 72}}, color = {0, 0, 127}));
  connect(product4.y, product5.u2) annotation(
    Line(points = {{-183, -164}, {-172, -164}, {-172, 128}, {-168, 128}}, color = {0, 0, 127}));
  connect(Convection_B.y, product3.u2) annotation(
    Line(points = {{-275, -168}, {-274.5, -168}, {-274.5, -168}, {-274, -168}, {-274, -168}, {-269, -168}, {-269, -158}, {-263, -158}, {-263, -158}, {-265, -158}, {-265, -158}, {-265, -158}, {-265, -158}}, color = {0, 0, 127}));
  connect(product3.y, exp1.u) annotation(
    Line(points = {{-241, -152}, {-237, -152}, {-237, -152}, {-231, -152}, {-231, -152}, {-234, -152}, {-234, -152}, {-233, -152}}, color = {0, 0, 127}));
  connect(FactorStdWindSpeed.y, StdWindSpeed.u1) annotation(
    Line(points = {{-357, -90}, {-351.5, -90}, {-351.5, -96}, {-352, -96}}, color = {0, 0, 127}));
  connect(FactorStdTemperature.y, StdTemperature.u1) annotation(
    Line(points = {{-363, -12}, {-359, -12}, {-359, -12}, {-353, -12}, {-353, -14}, {-355, -14}, {-355, -14}, {-355, -14}}, color = {0, 0, 127}));
  connect(Data_outdoor_temperature.y[1], OutdoorTemperature.u2) annotation(
    Line(points = {{-363, -46}, {-341, -46}, {-341, -34}, {-319, -34}, {-319, -32}, {-321, -32}, {-321, -34}}, color = {0, 0, 127}, thickness = 0.5));
  connect(StdTemperature.y, OutdoorTemperature.u1) annotation(
    Line(points = {{-331, -20}, {-329, -20}, {-329, -20}, {-325, -20}, {-325, -22}, {-319, -22}, {-319, -21}, {-321, -21}, {-321, -22}}, color = {0, 0, 127}));
  connect(Data_outdoor_temperature.y[2], StdTemperature.u2) annotation(
    Line(points = {{-363, -46}, {-356, -46}, {-356, -26}, {-355, -26}, {-355, -26}, {-354, -26}}, color = {0, 0, 127}, thickness = 0.5));
  connect(roof_emissivity.y, product2.u2) annotation(
    Line(points = {{-255, 130}, {-250.5, 130}, {-250.5, 146}, {-244, 146}}, color = {0, 0, 127}));
  connect(product5.y, Convection_roof_outer.Gc) annotation(
    Line(points = {{-144, 134}, {-126, 134}, {-126, 126}, {-126, 126}}, color = {0, 0, 127}));
  connect(product7.y, Convection_wall3_outer.Gc) annotation(
    Line(points = {{-150, 22}, {-126, 22}, {-126, 14}, {-126, 14}}, color = {0, 0, 127}));
  connect(product8.y, Convection_wall4_outer.Gc) annotation(
    Line(points = {{-146, -30}, {-130, -30}, {-130, -36}, {-126, -36}, {-126, -36}}, color = {0, 0, 127}));
  connect(Area_wall1.y, product6.u1) annotation(
    Line(points = {{-174, 78}, {-170, 78}, {-170, 84}, {-168, 84}}, color = {0, 0, 127}));
  connect(Area_roof.y, product5.u1) annotation(
    Line(points = {{-172, 134}, {-170, 134}, {-170, 140}, {-168, 140}}, color = {0, 0, 127}));
  connect(Temperature_Indoor.T, Temperature_difference.u2) annotation(
    Line(points = {{146, 82}, {153, 82}, {153, 82}, {158, 82}, {158, -106}, {96, -106}, {96, -97}, {96, -97}, {96, -88}}, color = {0, 0, 127}));
  connect(Floor_temperature.y, Temperature_floor.T) annotation(
    Line(points = {{-137, -112}, {-132.25, -112}, {-132.25, -112}, {-127.5, -112}, {-127.5, -114}, {-118, -114}}, color = {0, 0, 127}));
  connect(Convection_coef_wall3_inner.y, Convection_wall3_inner.Gc) annotation(
    Line(points = {{-27, 20}, {-21.75, 20}, {-21.75, 20}, {-16.5, 20}, {-16.5, 20}, {-6, 20}, {-6, 20}, {-6, 20}, {-6, 18}}, color = {0, 0, 127}));
  connect(Convection_coef_wall1_inner.y, Convection_wall1_inner.Gc) annotation(
    Line(points = {{-21, 74}, {-3, 74}, {-3, 74}, {-5, 74}, {-5, 64}, {-5, 64}, {-5, 64}, {-7, 64}}, color = {0, 0, 127}));
  connect(Temperature_floor.port, Radiation_floor.port_a) annotation(
    Line(points = {{-96, -114}, {-53, -114}, {-53, -114}, {-12, -114}, {-12, -118}, {-12, -118}, {-12, -122}}, color = {191, 0, 0}));
  connect(Conduction_wall4_inner.port_b, Radiation_wall4_inner.port_a) annotation(
    Line(points = {{-36, -46}, {-30, -46}, {-30, -46}, {-26, -46}, {-26, -66}, {-16, -66}, {-16, -66}, {-16, -66}, {-16, -66}}, color = {191, 0, 0}));
  connect(Conduction_wall3_inner.port_b, Radiation_wall3_inner.port_a) annotation(
    Line(points = {{-36, -6}, {-33.5, -6}, {-33.5, -6}, {-31, -6}, {-31, -6}, {-26, -6}, {-26, -16}, {-16, -16}, {-16, -15}, {-16, -15}, {-16, -16}}, color = {191, 0, 0}));
  connect(Conduction_wall1_inner.port_b, Radiation_wall1_inner.port_a) annotation(
    Line(points = {{-36, 44}, {-26, 44}, {-26, 34}, {-16, 34}, {-16, 34}}, color = {191, 0, 0}));
  connect(Conduction_roof_inner.port_b, Radiation_roof_inner.port_a) annotation(
    Line(points = {{-36, 102}, {-30, 102}, {-30, 102}, {-26, 102}, {-26, 92}, {-16, 92}, {-16, 92}, {-16, 92}, {-16, 92}}, color = {191, 0, 0}));
  connect(Convection_coef_floor.y, Convection_floor.Gc) annotation(
    Line(points = {{-41, -78}, {-19.25, -78}, {-19.25, -78}, {-17.5, -78}, {-17.5, -82}, {-8.75, -82}, {-8.75, -82}, {-2, -82}}, color = {0, 0, 127}));
  connect(Convection_coef_wall4_inner.y, Convection_wall4_inner.Gc) annotation(
    Line(points = {{-15, -30}, {-13, -30}, {-13, -30}, {-11, -30}, {-11, -30}, {-5, -30}, {-5, -36}, {-6, -36}, {-6, -36}, {-7, -36}}, color = {0, 0, 127}));
  connect(Convection_coef_roof_inner.y, Convection_roof_inner.Gc) annotation(
    Line(points = {{-21, 142}, {-5, 142}, {-5, 130}, {-6, 130}}, color = {0, 0, 127}));
  connect(Temperature_floor.port, Convection_floor.solid) annotation(
    Line(points = {{-96, -114}, {-68.5, -114}, {-68.5, -114}, {-43, -114}, {-43, -92}, {-17.5, -92}, {-17.5, -92}, {-12, -92}}, color = {191, 0, 0}));
  connect(Heatflow_solar_radiation.port, Conduction_roof_outer.port_a) annotation(
    Line(points = {{-112, 154}, {-107, 154}, {-107, 154}, {-102, 154}, {-102, 129}, {-102, 129}, {-102, 102}}, color = {191, 0, 0}));
  connect(product2.y, Heatflow_solar_radiation.Q_flow) annotation(
    Line(points = {{-221, 152}, {-199.5, 152}, {-199.5, 154}, {-132, 154}}, color = {0, 0, 127}));
  connect(Radiation_wall3_outer.port_b, Conduction_wall3_outer.port_a) annotation(
    Line(points = {{-116, -14}, {-105, -14}, {-105, -14}, {-96, -14}, {-96, -6}, {-96, -6}, {-96, -6}, {-96, -6}}, color = {191, 0, 0}));
  connect(Radiation_wall1_outer.port_b, Conduction_wall1_outer.port_a) annotation(
    Line(points = {{-116, 34}, {-110.5, 34}, {-110.5, 34}, {-107, 34}, {-107, 34}, {-98, 34}, {-98, 44}, {-97, 44}, {-97, 44}, {-96.5, 44}, {-96.5, 44}, {-96, 44}}, color = {191, 0, 0}));
  connect(Radiation_roof_outer.port_b, Conduction_roof_outer.port_a) annotation(
    Line(points = {{-118, 98}, {-109, 98}, {-109, 102}, {-102, 102}}, color = {191, 0, 0}));
  connect(Convection_wall3_outer.fluid, Conduction_wall3_outer.port_a) annotation(
    Line(points = {{-116, 4}, {-96, 4}, {-96, 4}, {-96, 4}, {-96, -6}, {-95, -6}, {-95, -6}, {-96, -6}}, color = {191, 0, 0}));
  connect(Convection_wall4_outer.fluid, Conduction_wall4_outer.port_a) annotation(
    Line(points = {{-116, -46}, {-96, -46}, {-96, -46}, {-96, -46}}, color = {191, 0, 0}));
  connect(Convection_roof_outer.fluid, Conduction_roof_outer.port_a) annotation(
    Line(points = {{-116, 116}, {-108, 116}, {-108, 116}, {-102, 116}, {-102, 109}, {-102, 109}, {-102, 102}}, color = {191, 0, 0}));
  connect(Conduction_wall4_inner.port_b, Convection_wall4_inner.solid) annotation(
    Line(points = {{-36, -46}, {-26, -46}, {-26, -46}, {-16, -46}, {-16, -46}, {-16, -46}, {-16, -46}, {-15, -46}, {-15, -46}, {-16, -46}}, color = {191, 0, 0}));
  connect(Conduction_wall3_inner.port_b, Convection_wall3_inner.solid) annotation(
    Line(points = {{-36, -6}, {-31, -6}, {-31, -6}, {-26, -6}, {-26, 8}, {-21, 8}, {-21, 8}, {-16, 8}}, color = {191, 0, 0}));
  connect(Conduction_wall1_inner.port_b, Convection_wall1_inner.solid) annotation(
    Line(points = {{-36, 44}, {-26, 44}, {-26, 54}, {-14, 54}}, color = {191, 0, 0}));
  connect(Conduction_roof_inner.port_b, Convection_roof_inner.solid) annotation(
    Line(points = {{-36, 102}, {-30, 102}, {-30, 102}, {-26, 102}, {-26, 120}, {-11, 120}, {-11, 120}, {-16, 120}}, color = {191, 0, 0}));
  connect(Capacitor_wall4.port, Conduction_wall4_inner.port_a) annotation(
    Line(points = {{-66, -46}, {-61, -46}, {-61, -46}, {-56, -46}, {-56, -46}, {-56, -46}}, color = {191, 0, 0}));
  connect(Conduction_wall4_outer.port_b, Capacitor_wall4.port) annotation(
    Line(points = {{-76, -46}, {-66, -46}, {-66, -46}, {-66, -46}}, color = {191, 0, 0}));
  connect(Capacitor_wall3.port, Conduction_wall3_inner.port_a) annotation(
    Line(points = {{-66, -6}, {-62, -6}, {-62, -6}, {-58, -6}, {-58, -6}, {-57, -6}, {-57, -6}, {-56, -6}}, color = {191, 0, 0}));
  connect(Conduction_wall3_outer.port_b, Capacitor_wall3.port) annotation(
    Line(points = {{-76, -6}, {-66, -6}, {-66, -6}, {-66, -6}, {-66, -6}, {-66, -6}}, color = {191, 0, 0}));
  connect(Capacitor_wall1.port, Conduction_wall1_inner.port_a) annotation(
    Line(points = {{-66, 44}, {-61, 44}, {-61, 44}, {-56, 44}, {-56, 44}, {-56, 44}, {-56, 44}, {-56, 44}, {-56, 44}, {-56, 44}}, color = {191, 0, 0}));
  connect(Conduction_wall1_outer.port_b, Capacitor_wall1.port) annotation(
    Line(points = {{-76, 44}, {-72.5, 44}, {-72.5, 44}, {-71, 44}, {-71, 44}, {-66, 44}, {-66, 44}, {-66, 44}, {-66, 44}, {-66, 44}}, color = {191, 0, 0}));
  connect(Conduction_roof_outer.port_b, Capacitor_roof.port) annotation(
    Line(points = {{-84, 102}, {-68, 102}}, color = {191, 0, 0}));
  connect(Capacitor_roof.port, Conduction_roof_inner.port_a) annotation(
    Line(points = {{-66, 102}, {-62.5, 102}, {-62.5, 102}, {-61, 102}, {-61, 102}, {-56, 102}, {-56, 102}, {-56, 102}, {-56, 102}, {-46, 102}, {-46, 102}, {-56, 102}}, color = {191, 0, 0}));
  annotation(
    uses(Modelica(version = "3.2.2")),
    experiment(StartTime = 0, StopTime = 86400, Tolerance = 1e-6, Interval = 173.494),
    __OpenModelica_simulationFlags(lv = "LOG_STATS", s = "dassl"));
end Outfall;
model Outfall
  Modelica.Thermal.HeatTransfer.Sensors.TemperatureSensor Temperature_Indoor annotation(
    Placement(visible = true, transformation(origin = {136, 82}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_wall1_inner(G = 33.10 * 0.95) annotation(
    Placement(visible = true, transformation(origin = {-46, 44}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_wall1_outer(G = 33.10 * 0.95) annotation(
    Placement(visible = true, transformation(origin = {-86, 44}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_roof_outer(G = 122861.25 * 64.3) annotation(
    Placement(visible = true, transformation(origin = {-94, 102}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_roof_inner(G = 122861.25 * 64.3) annotation(
    Placement(visible = true, transformation(origin = {-46, 102}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_wall3_outer(G = 30.86 * 0.95) annotation(
    Placement(visible = true, transformation(origin = {-86, -6}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_wall3_inner(G = 30.86 * 0.95) annotation(
    Placement(visible = true, transformation(origin = {-46, -6}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_wall4_outer(G = 23.73 * 0.95) annotation(
    Placement(visible = true, transformation(origin = {-86, -46}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Conduction_wall4_inner(G = 23.73 * 0.95) annotation(
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
    Placement(visible = true, transformation(origin = {-126, 54}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.Convection Convection_wall4_outer annotation(
    Placement(visible = true, transformation(origin = {-126, -46}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.Convection Convection_wall3_outer annotation(
    Placement(visible = true, transformation(origin = {-126, 4}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_roof_outer(Gr = 7.335 * 0.15) annotation(
    Placement(visible = true, transformation(origin = {-128, 98}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_wall1_outer(Gr = 7.881 * 0.85) annotation(
    Placement(visible = true, transformation(origin = {-126, 34}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_wall3_outer(Gr = 7.348 * 0.85) annotation(
    Placement(visible = true, transformation(origin = {-126, -14}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_wall4_outer(Gr = 5.650 * 0.85) annotation(
    Placement(visible = true, transformation(origin = {-126, -66}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.HeatCapacitor Capacitor_indoor_air(C = 21841, T(fixed = true, start = 301.15)) annotation(
    Placement(visible = true, transformation(origin = {118, 110}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalCollector thermalCollector1(m = 12) annotation(
    Placement(visible = true, transformation(origin = {94, 86}, extent = {{-10, -10}, {10, 10}}, rotation = 90)));
  Modelica.Thermal.HeatTransfer.Components.Convection Convection_floor annotation(
    Placement(visible = true, transformation(origin = {-2, -92}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow Heatflow_solar_radiation annotation(
    Placement(visible = true, transformation(origin = {-158, 162}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedTemperature Temperature_outdoor annotation(
    Placement(visible = true, transformation(origin = {-250, -56}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedTemperature Temperature_floor annotation(
    Placement(visible = true, transformation(origin = {-106, -114}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Infiltration(k = 4.75 * 17.74 / 3600 * 1005 * 1.225 * 1.0) annotation(
    Placement(visible = true, transformation(origin = {118, -54}, extent = {{-10, -10}, {10, 10}}, rotation = 90)));
  Modelica.Blocks.Math.Product product1 annotation(
    Placement(visible = true, transformation(origin = {96, -16}, extent = {{-10, -10}, {10, 10}}, rotation = 90)));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow Heatflow_infiltration annotation(
    Placement(visible = true, transformation(origin = {96, 16}, extent = {{10, 10}, {-10, -10}}, rotation = -90)));
  Modelica.Blocks.Sources.CombiTimeTable Data_solar_radiation(fileName = "/home/yunjaeh/OpenFOAM/yunjaeh-4.0/run/UQ/uq_2019/weather_input/night_0206.mat", tableName = "RADIATION", tableOnFile = true, timeScale = 60) annotation(
    Placement(visible = true, transformation(origin = {-326, 186}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.CombiTimeTable Data_outdoor_temperature(fileName = "/home/yunjaeh/OpenFOAM/yunjaeh-4.0/run/UQ/uq_2019/weather_input/night_0206.mat", tableName = "TEMPERATURE", tableOnFile = true, timeScale = 60) annotation(
    Placement(visible = true, transformation(origin = {-336, -96}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Convection_coef_roof_inner(k = 7.335 * 2.5) annotation(
    Placement(visible = true, transformation(origin = {-32, 142}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Convection_coef_wall4_inner(k = 5.650 * 2.5) annotation(
    Placement(visible = true, transformation(origin = {-26, -30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Convection_coef_floor(k = 7.316 * 2.5) annotation(
    Placement(visible = true, transformation(origin = {-52, -78}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_roof_inner(Gr = 7.335 * 0.15) annotation(
    Placement(visible = true, transformation(origin = {-6, 92}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_wall1_inner(Gr = 7.881 * 0.85) annotation(
    Placement(visible = true, transformation(origin = {-6, 34}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_wall3_inner(Gr = 7.348 * 0.85) annotation(
    Placement(visible = true, transformation(origin = {-6, -16}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_wall4_inner(Gr = 5.650 * 0.85) annotation(
    Placement(visible = true, transformation(origin = {-6, -66}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_floor(Gr = 7.316 * 0.85) annotation(
    Placement(visible = true, transformation(origin = {-2, -122}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Convection_coef_wall1_inner(k = 7.881 * 2.5) annotation(
    Placement(visible = true, transformation(origin = {-32, 74}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Convection_coef_wall3_inner(k = 7.348 * 2.5) annotation(
    Placement(visible = true, transformation(origin = {-38, 20}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product2 annotation(
    Placement(visible = true, transformation(origin = {-230, 174}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant roof_emissivity(k = 7.3162 * 14.86 / 20.0 * 0.40 ) annotation(
    Placement(visible = true, transformation(origin = {-264, 160}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedTemperature Temperature_sky annotation(
    Placement(visible = true, transformation(origin = {-248, 90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Floor_temperature(k = 299.15) annotation(
    Placement(visible = true, transformation(origin = {-148, -112}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Sqrt sqrt1 annotation(
    Placement(visible = true, transformation(origin = {-302, 6}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant const(k = 0.0552) annotation(
    Placement(visible = true, transformation(origin = {-308, 90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.MultiProduct multiProduct1(nu = 3) annotation(
    Placement(visible = true, transformation(origin = {-278, 90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.CombiTimeTable Data_wind_speed(fileName = "/home/yunjaeh/OpenFOAM/yunjaeh-4.0/run/UQ/uq_2019/weather_input/night_0206.mat", tableName = "WIND", tableOnFile = true, timeScale = 60) annotation(
    Placement(visible = true, transformation(origin = {-338, -148}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Add Temperature_difference(k1 = +1, k2 = -1)  annotation(
    Placement(visible = true, transformation(origin = {90, -76}, extent = {{-10, -10}, {10, 10}}, rotation = 90)));
  Two_single_ventilation two_single_ventilation1 annotation(
    Placement(visible = true, transformation(origin = {58, -38}, extent = {{-10, -10}, {10, 10}}, rotation = 90)));
  Modelica.Thermal.HeatTransfer.Components.BodyRadiation Radiation_roof_to_floor(Gr = 7.22 *0.85 * 0.15)  annotation(
    Placement(visible = true, transformation(origin = {44, 128}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Convection_A(k = 3.64*1.0)  annotation(
    Placement(visible = true, transformation(origin = {-218, -218}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Convection_B(k = 0.84)  annotation(
    Placement(visible = true, transformation(origin = {-284, -206}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Exp exp1 annotation(
    Placement(visible = true, transformation(origin = {-218, -190}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Log log1 annotation(
    Placement(visible = true, transformation(origin = {-284, -176}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product3 annotation(
    Placement(visible = true, transformation(origin = {-250, -190}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product4 annotation(
    Placement(visible = true, transformation(origin = {-192, -202}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product5 annotation(
    Placement(visible = true, transformation(origin = {-156, 134}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product6 annotation(
    Placement(visible = true, transformation(origin = {-156, 78}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product7 annotation(
    Placement(visible = true, transformation(origin = {-162, 22}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product8 annotation(
    Placement(visible = true, transformation(origin = {-158, -30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Area_roof(k = 7.335)  annotation(
    Placement(visible = true, transformation(origin = {-190, 134}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Area_wall1(k = 7.881)  annotation(
    Placement(visible = true, transformation(origin = {-186, 78}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Area_wall3(k = 7.348)  annotation(
    Placement(visible = true, transformation(origin = {-190, 22}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Area_wall4(k = 5.650)  annotation(
    Placement(visible = true, transformation(origin = {-188, -30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow Heatflow_solar_wall1 annotation(
    Placement(visible = true, transformation(origin = {-242, 134}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product9 annotation(
    Placement(visible = true, transformation(origin = {-284, 134}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant const1(k = 7.881 * 11.76 / 20 * 0.5 * 0.3)  annotation(
    Placement(visible = true, transformation(origin = {-326, 126}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(Area_roof.y, product5.u1) annotation(
    Line(points = {{-179, 134}, {-170, 134}, {-170, 140}, {-168, 140}}, color = {0, 0, 127}));
  connect(Heatflow_solar_wall1.port, Conduction_wall1_outer.port_a) annotation(
    Line(points = {{-232, 134}, {-204, 134}, {-204, 44}, {-96, 44}, {-96, 44}}, color = {191, 0, 0}));
  connect(Data_solar_radiation.y[1], product9.u1) annotation(
    Line(points = {{-314, 186}, {-308, 186}, {-308, 142}, {-296, 142}, {-296, 140}}, color = {0, 0, 127}, thickness = 0.5));
  connect(Data_solar_radiation.y[1], product2.u1) annotation(
    Line(points = {{-315, 186}, {-273.5, 186}, {-273.5, 180}, {-242, 180}}, color = {0, 0, 127}, thickness = 0.5));
  connect(product9.y, Heatflow_solar_wall1.Q_flow) annotation(
    Line(points = {{-272, 134}, {-254, 134}, {-254, 134}, {-252, 134}}, color = {0, 0, 127}));
  connect(const1.y, product9.u2) annotation(
    Line(points = {{-314, 126}, {-296, 126}, {-296, 128}, {-296, 128}}, color = {0, 0, 127}));
  connect(roof_emissivity.y, product2.u2) annotation(
    Line(points = {{-253, 160}, {-250.75, 160}, {-250.75, 160}, {-248.5, 160}, {-248.5, 168}, {-245.25, 168}, {-245.25, 168}, {-243.625, 168}, {-243.625, 168}, {-242, 168}}, color = {0, 0, 127}));
  connect(product2.y, Heatflow_solar_radiation.Q_flow) annotation(
    Line(points = {{-219, 174}, {-196.5, 174}, {-196.5, 162}, {-168, 162}}, color = {0, 0, 127}));
  connect(Heatflow_solar_radiation.port, Conduction_roof_outer.port_a) annotation(
    Line(points = {{-148, 162}, {-102, 162}, {-102, 102}}, color = {191, 0, 0}));
  connect(const.y, multiProduct1.u[1]) annotation(
    Line(points = {{-297, 90}, {-288, 90}}, color = {0, 0, 127}));
  connect(sqrt1.y, multiProduct1.u[2]) annotation(
    Line(points = {{-291, 6}, {-288, 6}, {-288, 90}}, color = {0, 0, 127}));
  connect(multiProduct1.y, Temperature_sky.T) annotation(
    Line(points = {{-266, 90}, {-260, 90}}, color = {0, 0, 127}));
  connect(Data_outdoor_temperature.y[1], multiProduct1.u[3]) annotation(
    Line(points = {{-325, -96}, {-288, -96}, {-288, 90}}, color = {0, 0, 127}, thickness = 0.5));
  connect(product5.y, Convection_roof_outer.Gc) annotation(
    Line(points = {{-144, 134}, {-126, 134}, {-126, 126}, {-126, 126}}, color = {0, 0, 127}));
  connect(product6.y, Convection_wall1_outer.Gc) annotation(
    Line(points = {{-144, 78}, {-128, 78}, {-128, 64}, {-126, 64}}, color = {0, 0, 127}));
  connect(product7.y, Convection_wall3_outer.Gc) annotation(
    Line(points = {{-150, 22}, {-126, 22}, {-126, 14}, {-126, 14}}, color = {0, 0, 127}));
  connect(product8.y, Convection_wall4_outer.Gc) annotation(
    Line(points = {{-146, -30}, {-130, -30}, {-130, -36}, {-126, -36}, {-126, -36}}, color = {0, 0, 127}));
  connect(Area_wall3.y, product7.u1) annotation(
    Line(points = {{-178, 22}, {-176, 22}, {-176, 28}, {-174, 28}}, color = {0, 0, 127}));
  connect(Area_wall1.y, product6.u1) annotation(
    Line(points = {{-174, 78}, {-170, 78}, {-170, 84}, {-168, 84}}, color = {0, 0, 127}));
  connect(product4.y, product5.u2) annotation(
    Line(points = {{-180, -202}, {-168, -202}, {-168, 128}, {-168, 128}}, color = {0, 0, 127}));
  connect(product4.y, product6.u2) annotation(
    Line(points = {{-180, -202}, {-170, -202}, {-170, 72}, {-168, 72}}, color = {0, 0, 127}));
  connect(product4.y, product7.u2) annotation(
    Line(points = {{-180, -202}, {-174, -202}, {-174, 16}, {-174, 16}}, color = {0, 0, 127}));
  connect(Area_wall4.y, product8.u1) annotation(
    Line(points = {{-176, -30}, {-172, -30}, {-172, -24}, {-170, -24}}, color = {0, 0, 127}));
  connect(product4.y, product8.u2) annotation(
    Line(points = {{-180, -202}, {-174, -202}, {-174, -36}, {-170, -36}, {-170, -36}}, color = {0, 0, 127}));
  connect(Convection_A.y, product4.u2) annotation(
    Line(points = {{-206, -218}, {-204, -218}, {-204, -208}}, color = {0, 0, 127}));
  connect(exp1.y, product4.u1) annotation(
    Line(points = {{-206, -190}, {-204, -190}, {-204, -196}}, color = {0, 0, 127}));
  connect(Conduction_roof_inner.port_b, Radiation_roof_to_floor.port_a) annotation(
    Line(points = {{-36, 102}, {24, 102}, {24, 128}, {34, 128}, {34, 128}, {34, 128}, {34, 128}}, color = {191, 0, 0}));
  connect(Radiation_roof_to_floor.port_b, Temperature_floor.port) annotation(
    Line(points = {{54, 128}, {51, 128}, {51, 128}, {46, 128}, {46, -114}, {-15, -114}, {-15, -114}, {-96, -114}}, color = {191, 0, 0}));
  connect(two_single_ventilation1.Port_indoor, thermalCollector1.port_a[11]) annotation(
    Line(points = {{58, -38}, {57, -38}, {57, -20}, {64, -20}, {64, 85}, {70, 85}, {70, 67}, {76, 67}}, color = {191, 0, 0}));
  connect(Data_outdoor_temperature.y[1], two_single_ventilation1.Port_outdoor) annotation(
    Line(points = {{-324, -96}, {-278, -96}, {-278, -160}, {58, -160}, {58, -38}}, color = {0, 0, 127}, thickness = 0.5));
  connect(Data_wind_speed.y[1], two_single_ventilation1.U) annotation(
    Line(points = {{-327, -148}, {58, -148}, {58, -38}}, color = {0, 0, 127}, thickness = 0.5));
  connect(Temperature_difference.y, product1.u1) annotation(
    Line(points = {{90, -65}, {90, -28}}, color = {0, 0, 127}));
  connect(Data_outdoor_temperature.y[1], Temperature_difference.u1) annotation(
    Line(points = {{-325, -96}, {-278, -96}, {-278, -160}, {84, -160}, {84, -88}}, color = {0, 0, 127}, thickness = 0.5));
  connect(Temperature_Indoor.T, Temperature_difference.u2) annotation(
    Line(points = {{146, 82}, {153, 82}, {153, 82}, {158, 82}, {158, -106}, {96, -106}, {96, -97}, {96, -97}, {96, -88}}, color = {0, 0, 127}));
  connect(Floor_temperature.y, Temperature_floor.T) annotation(
    Line(points = {{-137, -112}, {-132.25, -112}, {-132.25, -112}, {-127.5, -112}, {-127.5, -114}, {-118, -114}}, color = {0, 0, 127}));
  connect(Convection_coef_wall3_inner.y, Convection_wall3_inner.Gc) annotation(
    Line(points = {{-27, 20}, {-21.75, 20}, {-21.75, 20}, {-16.5, 20}, {-16.5, 20}, {-6, 20}, {-6, 20}, {-6, 20}, {-6, 18}}, color = {0, 0, 127}));
  connect(Convection_coef_wall1_inner.y, Convection_wall1_inner.Gc) annotation(
    Line(points = {{-21, 74}, {-3, 74}, {-3, 74}, {-5, 74}, {-5, 64}, {-5, 64}, {-5, 64}, {-7, 64}}, color = {0, 0, 127}));
  connect(Radiation_floor.port_b, thermalCollector1.port_a[10]) annotation(
    Line(points = {{8, -122}, {24, -122}, {24, -122}, {40, -122}, {40, 86}, {84, 86}, {84, 86}, {84, 86}, {84, 86}}, color = {191, 0, 0}));
  connect(Temperature_floor.port, Radiation_floor.port_a) annotation(
    Line(points = {{-96, -114}, {-53, -114}, {-53, -114}, {-12, -114}, {-12, -118}, {-12, -118}, {-12, -122}}, color = {191, 0, 0}));
  connect(Conduction_wall4_inner.port_b, Radiation_wall4_inner.port_a) annotation(
    Line(points = {{-36, -46}, {-30, -46}, {-30, -46}, {-26, -46}, {-26, -66}, {-16, -66}, {-16, -66}, {-16, -66}, {-16, -66}}, color = {191, 0, 0}));
  connect(Radiation_wall4_inner.port_b, thermalCollector1.port_a[8]) annotation(
    Line(points = {{4, -66}, {23, -66}, {23, -66}, {40, -66}, {40, 88}, {84, 88}, {84, 87}, {84, 87}, {84, 86}}, color = {191, 0, 0}));
  connect(Conduction_wall3_inner.port_b, Radiation_wall3_inner.port_a) annotation(
    Line(points = {{-36, -6}, {-33.5, -6}, {-33.5, -6}, {-31, -6}, {-31, -6}, {-26, -6}, {-26, -16}, {-16, -16}, {-16, -15}, {-16, -15}, {-16, -16}}, color = {191, 0, 0}));
  connect(Radiation_wall3_inner.port_b, thermalCollector1.port_a[6]) annotation(
    Line(points = {{4, -16}, {22, -16}, {22, -16}, {40, -16}, {40, 86}, {84, 86}, {84, 86}}, color = {191, 0, 0}));
  connect(Conduction_wall1_inner.port_b, Radiation_wall1_inner.port_a) annotation(
    Line(points = {{-36, 44}, {-26, 44}, {-26, 34}, {-16, 34}, {-16, 34}}, color = {191, 0, 0}));
  connect(Radiation_wall1_inner.port_b, thermalCollector1.port_a[4]) annotation(
    Line(points = {{4, 34}, {23, 34}, {23, 34}, {40, 34}, {40, 86}, {84, 86}, {84, 86}, {84, 86}, {84, 86}}, color = {191, 0, 0}));
  connect(Conduction_roof_inner.port_b, Radiation_roof_inner.port_a) annotation(
    Line(points = {{-36, 102}, {-30, 102}, {-30, 102}, {-26, 102}, {-26, 92}, {-16, 92}, {-16, 92}, {-16, 92}, {-16, 92}}, color = {191, 0, 0}));
  connect(Radiation_roof_inner.port_b, thermalCollector1.port_a[2]) annotation(
    Line(points = {{4, 92}, {19, 92}, {19, 92}, {32, 92}, {32, 86}, {84, 86}, {84, 86}}, color = {191, 0, 0}));
  connect(Convection_coef_floor.y, Convection_floor.Gc) annotation(
    Line(points = {{-41, -78}, {-19.25, -78}, {-19.25, -78}, {-17.5, -78}, {-17.5, -82}, {-8.75, -82}, {-8.75, -82}, {-2, -82}}, color = {0, 0, 127}));
  connect(Convection_coef_wall4_inner.y, Convection_wall4_inner.Gc) annotation(
    Line(points = {{-15, -30}, {-13, -30}, {-13, -30}, {-11, -30}, {-11, -30}, {-5, -30}, {-5, -36}, {-6, -36}, {-6, -36}, {-7, -36}}, color = {0, 0, 127}));
  connect(Convection_coef_roof_inner.y, Convection_roof_inner.Gc) annotation(
    Line(points = {{-21, 142}, {-5, 142}, {-5, 130}, {-6, 130}}, color = {0, 0, 127}));
  connect(Heatflow_infiltration.port, thermalCollector1.port_a[12]) annotation(
    Line(points = {{96, 26}, {84, 26}, {84, 86}}, color = {191, 0, 0}));
  connect(product1.y, Heatflow_infiltration.Q_flow) annotation(
    Line(points = {{96, -5}, {96, 6}}, color = {0, 0, 127}));
  connect(Infiltration.y, product1.u2) annotation(
    Line(points = {{118, -43}, {111, -43}, {111, -43}, {102, -43}, {102, -29}, {112, -29}, {112, -29}, {102, -29}}, color = {0, 0, 127}));
  connect(Temperature_floor.port, Convection_floor.solid) annotation(
    Line(points = {{-96, -114}, {-68.5, -114}, {-68.5, -114}, {-43, -114}, {-43, -92}, {-17.5, -92}, {-17.5, -92}, {-12, -92}}, color = {191, 0, 0}));
  connect(Convection_floor.fluid, thermalCollector1.port_a[9]) annotation(
    Line(points = {{8, -92}, {40, -92}, {40, 86}, {84, 86}, {84, 86}, {84, 86}, {84, 86}}, color = {191, 0, 0}));
  connect(thermalCollector1.port_b, Capacitor_indoor_air.port) annotation(
    Line(points = {{104, 86}, {112, 86}, {112, 86}, {118, 86}, {118, 93}, {118, 93}, {118, 100}}, color = {191, 0, 0}));
  connect(Convection_wall1_inner.fluid, thermalCollector1.port_a[3]) annotation(
    Line(points = {{4, 54}, {40, 54}, {40, 86}, {84, 86}, {84, 86}, {84, 86}}, color = {191, 0, 0}));
  connect(Convection_wall3_inner.fluid, thermalCollector1.port_a[5]) annotation(
    Line(points = {{4, 8}, {40, 8}, {40, 86}, {84, 86}, {84, 86}}, color = {191, 0, 0}));
  connect(Convection_wall4_inner.fluid, thermalCollector1.port_a[7]) annotation(
    Line(points = {{4, -46}, {32, -46}, {32, -46}, {40, -46}, {40, 86}, {84, 86}, {84, 86}, {84, 86}, {84, 86}}, color = {191, 0, 0}));
  connect(Convection_roof_inner.fluid, thermalCollector1.port_a[1]) annotation(
    Line(points = {{4, 120}, {32, 120}, {32, 120}, {40, 120}, {40, 86}, {63, 86}, {63, 86}, {84, 86}}, color = {191, 0, 0}));
  connect(Capacitor_indoor_air.port, Temperature_Indoor.port) annotation(
    Line(points = {{118, 100}, {118, 95}, {118, 95}, {118, 90}, {126, 90}, {126, 86}, {126, 86}, {126, 82}}, color = {191, 0, 0}));
  connect(Radiation_wall4_outer.port_b, Conduction_wall4_outer.port_a) annotation(
    Line(points = {{-116, -66}, {-111, -66}, {-111, -66}, {-106, -66}, {-106, -66}, {-96, -66}, {-96, -46}, {-96, -46}, {-96, -46}, {-96, -46}}, color = {191, 0, 0}));
  connect(Temperature_outdoor.port, Radiation_wall4_outer.port_a) annotation(
    Line(points = {{-240, -56}, {-218, -56}, {-218, -66}, {-136, -66}}, color = {191, 0, 0}));
  connect(Radiation_wall3_outer.port_b, Conduction_wall3_outer.port_a) annotation(
    Line(points = {{-116, -14}, {-105, -14}, {-105, -14}, {-96, -14}, {-96, -6}, {-96, -6}, {-96, -6}, {-96, -6}}, color = {191, 0, 0}));
  connect(Temperature_outdoor.port, Radiation_wall3_outer.port_a) annotation(
    Line(points = {{-240, -56}, {-215, -56}, {-215, -14}, {-136, -14}}, color = {191, 0, 0}));
  connect(Radiation_wall1_outer.port_b, Conduction_wall1_outer.port_a) annotation(
    Line(points = {{-116, 34}, {-110.5, 34}, {-110.5, 34}, {-107, 34}, {-107, 34}, {-98, 34}, {-98, 44}, {-97, 44}, {-97, 44}, {-96.5, 44}, {-96.5, 44}, {-96, 44}}, color = {191, 0, 0}));
  connect(Temperature_outdoor.port, Radiation_wall1_outer.port_a) annotation(
    Line(points = {{-240, -56}, {-220, -56}, {-220, 34}, {-136, 34}}, color = {191, 0, 0}));
  connect(Radiation_roof_outer.port_b, Conduction_roof_outer.port_a) annotation(
    Line(points = {{-118, 98}, {-109, 98}, {-109, 102}, {-102, 102}}, color = {191, 0, 0}));
  connect(Temperature_sky.port, Radiation_roof_outer.port_a) annotation(
    Line(points = {{-238, 90}, {-210, 90}, {-210, 98}, {-138, 98}}, color = {191, 0, 0}));
  connect(Convection_wall3_outer.fluid, Conduction_wall3_outer.port_a) annotation(
    Line(points = {{-116, 4}, {-96, 4}, {-96, 4}, {-96, 4}, {-96, -6}, {-95, -6}, {-95, -6}, {-96, -6}}, color = {191, 0, 0}));
  connect(Temperature_outdoor.port, Convection_wall3_outer.solid) annotation(
    Line(points = {{-240, -56}, {-215, -56}, {-215, 4}, {-136, 4}}, color = {191, 0, 0}));
  connect(Convection_wall4_outer.fluid, Conduction_wall4_outer.port_a) annotation(
    Line(points = {{-116, -46}, {-96, -46}, {-96, -46}, {-96, -46}}, color = {191, 0, 0}));
  connect(Temperature_outdoor.port, Convection_wall4_outer.solid) annotation(
    Line(points = {{-240, -56}, {-215, -56}, {-215, -46}, {-136, -46}}, color = {191, 0, 0}));
  connect(Convection_wall1_outer.fluid, Conduction_wall1_outer.port_a) annotation(
    Line(points = {{-116, 54}, {-106, 54}, {-106, 54}, {-96, 54}, {-96, 44}, {-96, 44}}, color = {191, 0, 0}));
  connect(Temperature_outdoor.port, Convection_wall1_outer.solid) annotation(
    Line(points = {{-240, -56}, {-230, -56}, {-230, 54}, {-136, 54}}, color = {191, 0, 0}));
  connect(Convection_roof_outer.fluid, Conduction_roof_outer.port_a) annotation(
    Line(points = {{-116, 116}, {-108, 116}, {-108, 116}, {-102, 116}, {-102, 109}, {-102, 109}, {-102, 102}}, color = {191, 0, 0}));
  connect(Temperature_outdoor.port, Convection_roof_outer.solid) annotation(
    Line(points = {{-240, -56}, {-230, -56}, {-230, 116}, {-136, 116}}, color = {191, 0, 0}));
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
  connect(product3.y, exp1.u) annotation(
    Line(points = {{-238, -190}, {-230, -190}, {-230, -190}, {-230, -190}}, color = {0, 0, 127}));
  connect(Convection_B.y, product3.u2) annotation(
    Line(points = {{-272, -206}, {-268, -206}, {-268, -196}, {-262, -196}, {-262, -196}}, color = {0, 0, 127}));
  connect(log1.y, product3.u1) annotation(
    Line(points = {{-272, -176}, {-270, -176}, {-270, -182}, {-262, -182}, {-262, -184}}, color = {0, 0, 127}));
  connect(Data_wind_speed.y[1], log1.u) annotation(
    Line(points = {{-326, -148}, {-316, -148}, {-316, -176}, {-296, -176}, {-296, -176}}, color = {0, 0, 127}, thickness = 0.5));
  connect(Data_outdoor_temperature.y[1], sqrt1.u) annotation(
    Line(points = {{-325, -96}, {-319.5, -96}, {-319.5, -96}, {-314, -96}, {-314, -44}, {-314, -44}, {-314, 6}}, color = {0, 0, 127}, thickness = 0.5));
  connect(Data_outdoor_temperature.y[1], Temperature_outdoor.T) annotation(
    Line(points = {{-325, -96}, {-307.25, -96}, {-307.25, -96}, {-289.5, -96}, {-289.5, -56}, {-275.75, -56}, {-275.75, -56}, {-262, -56}}, color = {0, 0, 127}, thickness = 0.5));
  annotation(
    uses(Modelica(version = "3.2.2")),
    experiment(StartTime = 0, StopTime = 86400, Tolerance = 1e-6, Interval = 173.494),
    __OpenModelica_simulationFlags(lv = "LOG_STATS", s = "dassl"));
end Outfall;
model Two_single_ventilation
  Modelica.Blocks.Math.Add add1(k1 = +1, k2 = -1) annotation(
    Placement(visible = true, transformation(origin = {-98, -90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant C1(k = 0.001) annotation(
    Placement(visible = true, transformation(origin = {-90, 106}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant C2(k = 0.0035) annotation(
    Placement(visible = true, transformation(origin = {-90, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant C3(k = 0.01) annotation(
    Placement(visible = true, transformation(origin = {-42, 4}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Sqrt sqrt1 annotation(
    Placement(visible = true, transformation(origin = {50, 50}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Abs abs1 annotation(
    Placement(visible = true, transformation(origin = {-70, -76}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant const(k = 0.5) annotation(
    Placement(visible = true, transformation(origin = {50, 10}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product U_square annotation(
    Placement(visible = true, transformation(origin = {-90, 70}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput U annotation(
    Placement(visible = true, transformation(origin = {-140, 70}, extent = {{-20, -20}, {20, 20}}, rotation = 0), iconTransformation(origin = {-100, 60}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product product1 annotation(
    Placement(visible = true, transformation(origin = {-58, 84}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.MultiProduct multiProduct1(nu = 3) annotation(
    Placement(visible = true, transformation(origin = {-42, 30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.MultiProduct multiProduct2(nu = 3) annotation(
    Placement(visible = true, transformation(origin = {-40, -30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Area_1(k = 0.62)  annotation(
    Placement(visible = true, transformation(origin = {50, 82}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Area_2(k = 0.05)  annotation(
    Placement(visible = true, transformation(origin = {50, -60}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Height_1(k = 0.91)  annotation(
    Placement(visible = true, transformation(origin = {-90, 30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Height_2(k = 0.43)  annotation(
    Placement(visible = true, transformation(origin = {-90, -30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.MultiSum multiSum1(nu = 3)  annotation(
    Placement(visible = true, transformation(origin = {10, 50}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.MultiSum multiSum2(nu = 3)  annotation(
    Placement(visible = true, transformation(origin = {10, -30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Sqrt sqrt2 annotation(
    Placement(visible = true, transformation(origin = {50, -30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.MultiProduct multiProduct3(nu = 3) annotation(
    Placement(visible = true, transformation(origin = {88, 64}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.MultiProduct multiProduct4(nu = 3) annotation(
    Placement(visible = true, transformation(origin = {86, -28}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Interfaces.HeatPort_b Port_indoor annotation(
    Placement(visible = true, transformation(origin = {186, -84}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {100, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Sensors.TemperatureSensor Indoor_temperature annotation(
    Placement(visible = true, transformation(origin = {-72, -114}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow Heat_flow_NV annotation(
    Placement(visible = true, transformation(origin = {186, -48}, extent = {{-10, -10}, {10, 10}}, rotation = -90)));
  Modelica.Blocks.Interfaces.RealInput Port_outdoor annotation(
    Placement(visible = true, transformation(origin = {-150, -42}, extent = {{-20, -20}, {20, 20}}, rotation = 0), iconTransformation(origin = {-100, -60}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Ventilation_param(k = 1005 * 1.225)  annotation(
    Placement(visible = true, transformation(origin = {120, 46}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.MultiProduct multiProduct5(nu = 3)  annotation(
    Placement(visible = true, transformation(origin = {168, -16}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Add Ventilation_rate(k1 = 1.02, k2 = 1.3)  annotation(
    Placement(visible = true, transformation(origin = {122, 12}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(const.y, multiProduct3.u[1]) annotation(
    Line(points = {{62, 10}, {74, 10}, {74, 64}, {78, 64}}, color = {0, 0, 127}));
  connect(Area_1.y, multiProduct3.u[2]) annotation(
    Line(points = {{62, 82}, {74, 82}, {74, 64}, {78, 64}}, color = {0, 0, 127}));
  connect(sqrt1.y, multiProduct3.u[3]) annotation(
    Line(points = {{62, 50}, {78, 50}, {78, 64}}, color = {0, 0, 127}));
  connect(multiProduct3.y, Ventilation_rate.u1) annotation(
    Line(points = {{100, 64}, {100, 18}, {110, 18}}, color = {0, 0, 127}));
  connect(Ventilation_param.y, multiProduct5.u[1]) annotation(
    Line(points = {{131, 46}, {148, 46}, {148, -12}, {158, -12}, {158, -16}}, color = {0, 0, 127}));
  connect(add1.y, multiProduct5.u[3]) annotation(
    Line(points = {{-86, -90}, {158, -90}, {158, -20}, {158, -20}, {158, -16}}, color = {0, 0, 127}));
  connect(Ventilation_rate.y, multiProduct5.u[2]) annotation(
    Line(points = {{134, 12}, {144, 12}, {144, -16}, {158, -16}, {158, -16}}, color = {0, 0, 127}));
  connect(multiProduct5.y, Heat_flow_NV.Q_flow) annotation(
    Line(points = {{180, -16}, {186, -16}, {186, -38}, {186, -38}}, color = {0, 0, 127}));
  connect(add1.y, abs1.u) annotation(
    Line(points = {{-87, -90}, {-85.5, -90}, {-85.5, -76}, {-82, -76}}, color = {0, 0, 127}));
  connect(Port_outdoor, add1.u1) annotation(
    Line(points = {{-150, -42}, {-122, -42}, {-122, -84}, {-110, -84}}, color = {0, 0, 127}));
  connect(add1.u2, Indoor_temperature.T) annotation(
    Line(points = {{-110, -96}, {-122, -96}, {-122, -114}, {-82, -114}}, color = {0, 0, 127}));
  connect(Heat_flow_NV.port, Port_indoor) annotation(
    Line(points = {{186, -58}, {186, -84}}, color = {191, 0, 0}));
  connect(Indoor_temperature.port, Port_indoor) annotation(
    Line(points = {{-62, -114}, {186, -114}, {186, -84}}, color = {191, 0, 0}));
  connect(multiProduct4.y, Ventilation_rate.u2) annotation(
    Line(points = {{98, -28}, {102, -28}, {102, 6}, {110, 6}, {110, 6}}, color = {0, 0, 127}));
  connect(sqrt2.y, multiProduct4.u[3]) annotation(
    Line(points = {{62, -30}, {76, -30}, {76, -28}, {76, -28}}, color = {0, 0, 127}));
  connect(Area_2.y, multiProduct4.u[2]) annotation(
    Line(points = {{62, -60}, {76, -60}, {76, -28}, {76, -28}}, color = {0, 0, 127}));
  connect(const.y, multiProduct4.u[1]) annotation(
    Line(points = {{62, 10}, {74, 10}, {74, -28}, {76, -28}}, color = {0, 0, 127}));
  connect(multiSum2.y, sqrt2.u) annotation(
    Line(points = {{22, -30}, {38, -30}, {38, -30}, {38, -30}}, color = {0, 0, 127}));
  connect(multiSum1.y, sqrt1.u) annotation(
    Line(points = {{22, 50}, {38, 50}, {38, 50}, {38, 50}}, color = {0, 0, 127}));
  connect(C3.y, multiSum2.u[3]) annotation(
    Line(points = {{-30, 4}, {-18, 4}, {-18, -34}, {0, -34}, {0, -30}}, color = {0, 0, 127}));
  connect(multiProduct2.y, multiSum2.u[2]) annotation(
    Line(points = {{-28, -30}, {0, -30}, {0, -30}, {0, -30}}, color = {0, 0, 127}));
  connect(product1.y, multiSum2.u[1]) annotation(
    Line(points = {{-46, 84}, {-18, 84}, {-18, -28}, {0, -28}, {0, -30}}, color = {0, 0, 127}));
  connect(abs1.y, multiProduct2.u[3]) annotation(
    Line(points = {{-58, -76}, {-50, -76}, {-50, -30}}, color = {0, 0, 127}));
  connect(C2.y, multiProduct2.u[1]) annotation(
    Line(points = {{-78, 0}, {-64, 0}, {-64, -30}, {-50, -30}}, color = {0, 0, 127}));
  connect(Height_2.y, multiProduct2.u[2]) annotation(
    Line(points = {{-78, -30}, {-50, -30}}, color = {0, 0, 127}));
  connect(C3.y, multiSum1.u[3]) annotation(
    Line(points = {{-30, 4}, {-18, 4}, {-18, 46}, {0, 46}, {0, 50}}, color = {0, 0, 127}));
  connect(multiProduct1.y, multiSum1.u[2]) annotation(
    Line(points = {{-30, 30}, {-18, 30}, {-18, 50}, {0, 50}, {0, 50}}, color = {0, 0, 127}));
  connect(product1.y, multiSum1.u[1]) annotation(
    Line(points = {{-46, 84}, {-18, 84}, {-18, 52}, {0, 52}, {0, 50}}, color = {0, 0, 127}));
  connect(abs1.y, multiProduct1.u[3]) annotation(
    Line(points = {{-58, -76}, {-58, -76}, {-58, 30}, {-52, 30}, {-52, 30}}, color = {0, 0, 127}));
  connect(C2.y, multiProduct1.u[1]) annotation(
    Line(points = {{-78, 0}, {-64, 0}, {-64, 30}, {-52, 30}}, color = {0, 0, 127}));
  connect(Height_1.y, multiProduct1.u[2]) annotation(
    Line(points = {{-78, 30}, {-52, 30}}, color = {0, 0, 127}));
  connect(U, U_square.u2) annotation(
    Line(points = {{-140, 70}, {-114, 70}, {-114, 64}, {-102, 64}}, color = {0, 0, 127}));
  connect(U, U_square.u1) annotation(
    Line(points = {{-140, 70}, {-119, 70}, {-119, 76}, {-102, 76}}, color = {0, 0, 127}));
  connect(C1.y, product1.u1) annotation(
    Line(points = {{-79, 106}, {-78, 106}, {-78, 90}, {-70, 90}}, color = {0, 0, 127}));
  connect(U_square.y, product1.u2) annotation(
    Line(points = {{-79, 70}, {-76, 70}, {-76, 78}, {-70, 78}}, color = {0, 0, 127}));
  annotation(
    uses(Modelica(version = "3.2.2")),
    Icon(graphics = {Text(origin = {9, -60}, extent = {{-81, -26}, {65, 6}}, textString = "Single-sided"), Text(origin = {5, -94}, extent = {{-81, -26}, {75, 20}}, textString = "Ventilation"), Text(origin = {-101, 90}, extent = {{-19, 10}, {21, -20}}, textString = "U"), Text(origin = {-101, -80}, extent = {{-19, 10}, {21, -20}}, textString = "T"), Rectangle(origin = {-14,-10}, lineThickness = 0.5, extent = {{-46, 50}, {74, -30}}), Polygon(origin = {-26, 57}, lineThickness = 0.5, points = {{26, 23}, {-46, -17}, {98, -17}, {26, 23}, {26, 23}}), Line(origin = {-62.45, -29.14}, points = {{-11, 0}, {15, 0}}, color = {32, 74, 135}, thickness = 0.5, arrow = {Arrow.Open, Arrow.Open}, arrowSize = 1), Line(origin = {58.6873, 28.2466}, points = {{-11, 0}, {15, 0}}, color = {32, 74, 135}, thickness = 0.5, arrow = {Arrow.Open, Arrow.Open}, arrowSize = 1)}, coordinateSystem(initialScale = 0.1)),
    experiment(StartTime = 0, StopTime = 86400, Tolerance = 1e-06, Interval = 173.146));
end Two_single_ventilation;

model Single_ventilation
  Modelica.Blocks.Math.Add add1(k1 = +1, k2 = -1) annotation(
    Placement(visible = true, transformation(origin = {-78, -54}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant C1(k = 0.001)  annotation(
    Placement(visible = true, transformation(origin = {-50, 78}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant C2(k = 0.0035)  annotation(
    Placement(visible = true, transformation(origin = {-52, 8}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant C3(k = 0.01)  annotation(
    Placement(visible = true, transformation(origin = {-50, -90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Sqrt sqrt1 annotation(
    Placement(visible = true, transformation(origin = {48, -50}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.MultiSum multiSum1(nu = 3)  annotation(
    Placement(visible = true, transformation(origin = {10, -50}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Abs abs1 annotation(
    Placement(visible = true, transformation(origin = {-50, -54}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Height(k= Opening_Height) annotation(
    Placement(visible = true, transformation(origin = {-50, -22}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant Area(k= Opening_Area) annotation(
    Placement(visible = true, transformation(origin = {48, -20}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant const(k = 0.5)  annotation(
    Placement(visible = true, transformation(origin = {48, 10}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Product U_square annotation(
    Placement(visible = true, transformation(origin = {-50, 48}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput U annotation(
    Placement(visible = true, transformation(origin = {-140, 50}, extent = {{-20, -20}, {20, 20}}, rotation = 0), iconTransformation(origin = {-99, 59}, extent = {{-15, -15}, {15, 15}}, rotation = 0)));
  Modelica.Blocks.Math.Product product1 annotation(
    Placement(visible = true, transformation(origin = {-20, 64}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.MultiProduct multiProduct1(nu = 3)  annotation(
    Placement(visible = true, transformation(origin = {-20,-22}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Math.MultiProduct multiProduct2(nu = 3)  annotation(
    Placement(visible = true, transformation(origin = {82, -18}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput Port_indoor annotation(
    Placement(visible = true, transformation(origin = {-140, -40}, extent = {{-20, -20}, {20, 20}}, rotation = 0), iconTransformation(origin = {-100, -60}, extent = {{-14, -14}, {14, 14}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput Port_outdoor annotation(
    Placement(visible = true, transformation(origin = {144, -2}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {144, -2}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(C2.y, multiProduct1.u[1]) annotation(
    Line(points = {{-41, 8}, {-28, 8}, {-28, -22}, {-30, -22}}, color = {0, 0, 127}));
  connect(const.y, multiProduct2.u[1]) annotation(
    Line(points = {{60, 10}, {72, 10}, {72, -18}, {72, -18}}, color = {0, 0, 127}));
  connect(sqrt1.y, multiProduct2.u[3]) annotation(
    Line(points = {{60, -50}, {72, -50}, {72, -18}, {72, -18}}, color = {0, 0, 127}));
  connect(U, U_square.u1) annotation(
    Line(points = {{-140, 50}, {-90, 50}, {-90, 54}, {-62, 54}}, color = {0, 0, 127}));
  connect(U, U_square.u2) annotation(
    Line(points = {{-140, 50}, {-90, 50}, {-90, 42}, {-62, 42}}, color = {0, 0, 127}));
  connect(U_square.y, product1.u2) annotation(
    Line(points = {{-39, 48}, {-35, 48}, {-35, 58}, {-33, 58}}, color = {0, 0, 127}));
  connect(Port_indoor, add1.u1) annotation(
    Line(points = {{-140, -40}, {-92, -40}, {-92, -48}, {-90, -48}}, color = {0, 0, 127}));
  connect(add1.u2, Port_outdoor) annotation(
    Line(points = {{-90, -60}, {-102, -60}, {-102, -114}, {138, -114}, {138, -2}, {144, -2}}, color = {0, 0, 127}));
  connect(Port_outdoor, multiProduct2.y) annotation(
    Line(points = {{144, -2}, {94, -2}, {94, -18}, {94, -18}}, color = {0, 0, 127}));
  connect(abs1.y, multiProduct1.u[3]) annotation(
    Line(points = {{-38, -54}, {-30, -54}, {-30, -22}, {-30, -22}}, color = {0, 0, 127}));
  connect(multiProduct1.y, multiSum1.u[2]) annotation(
    Line(points = {{-8, -22}, {0, -22}, {0, -50}, {0, -50}}, color = {0, 0, 127}));
  connect(product1.y, multiSum1.u[1]) annotation(
    Line(points = {{-8, 64}, {0, 64}, {0, -50}, {0, -50}}, color = {0, 0, 127}));
  connect(C1.y, product1.u1) annotation(
    Line(points = {{-39, 78}, {-38, 78}, {-38, 78}, {-35, 78}, {-35, 70}, {-33, 70}}, color = {0, 0, 127}));
  connect(C3.y, multiSum1.u[3]) annotation(
    Line(points = {{-39, -90}, {0, -90}, {0, -50}}, color = {0, 0, 127}));
  connect(multiSum1.y, sqrt1.u) annotation(
    Line(points = {{22, -50}, {36, -50}}, color = {0, 0, 127}));
  connect(add1.y, abs1.u) annotation(
    Line(points = {{-67, -54}, {-62, -54}}, color = {0, 0, 127}));
  annotation(
    uses(Modelica(version = "3.2.2")),
    Icon(graphics = {Text(origin = {7, 34}, extent = {{-81, -26}, {65, 6}}, textString = "Single-sided"), Text(origin = {3, -22}, extent = {{-81, -26}, {81, 26}}, textString = "Ventilation"), Text(origin = {-87, 78}, extent = {{-19, 10}, {19, -10}}, textString = "U"), Text(origin = {-81, -80}, extent = {{-19, 10}, {19, -10}}, textString = "T")}, coordinateSystem(initialScale = 0.1)),
  experiment(StartTime = 0, StopTime = 86400, Tolerance = 1e-06, Interval = 173.146));
end Single_ventilation;
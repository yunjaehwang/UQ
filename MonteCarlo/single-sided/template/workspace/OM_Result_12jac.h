/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac15 15
  int OM_Result_functionJacNLSJac15_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac15(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac15 */
#define $PConduction_wall1_inner_port_b_TSeedNLSJac15 data->simulationInfo->analyticJacobians[15].seedVars[0]
#define _$PConduction_wall1_inner$PdT$P$pDERNLSJac15$PdummyVarNLSJac15(i) data->simulationInfo->analyticJacobians[15].tmpVars[0]
#define $PConduction_wall1_inner$PdT$P$pDERNLSJac15$PdummyVarNLSJac15 _$PConduction_wall1_inner$PdT$P$pDERNLSJac15$PdummyVarNLSJac15(0)

#define _$PConduction_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15(i) data->simulationInfo->analyticJacobians[15].tmpVars[1]
#define $PConduction_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15 _$PConduction_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15(0)

#define _$PConvection_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15(i) data->simulationInfo->analyticJacobians[15].tmpVars[2]
#define $PConvection_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15 _$PConvection_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15(0)

#define _$PConvection_wall1_inner$PdT$P$pDERNLSJac15$PdummyVarNLSJac15(i) data->simulationInfo->analyticJacobians[15].tmpVars[3]
#define $PConvection_wall1_inner$PdT$P$pDERNLSJac15$PdummyVarNLSJac15 _$PConvection_wall1_inner$PdT$P$pDERNLSJac15$PdummyVarNLSJac15(0)

#define _$PRadiation_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15(i) data->simulationInfo->analyticJacobians[15].tmpVars[4]
#define $PRadiation_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15 _$PRadiation_wall1_inner$PQ_flow$P$pDERNLSJac15$PdummyVarNLSJac15(0)

#define _$P$res$P1$P$pDERNLSJac15$PdummyVarNLSJac15(i) data->simulationInfo->analyticJacobians[15].resultVars[0]
#define $P$res$P1$P$pDERNLSJac15$PdummyVarNLSJac15 _$P$res$P1$P$pDERNLSJac15$PdummyVarNLSJac15(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac14 14
  int OM_Result_functionJacNLSJac14_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac14(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac14 */
#define $PConduction_wall1_outer_port_a_TSeedNLSJac14 data->simulationInfo->analyticJacobians[14].seedVars[0]
#define _$PConduction_wall1_outer$PdT$P$pDERNLSJac14$PdummyVarNLSJac14(i) data->simulationInfo->analyticJacobians[14].tmpVars[0]
#define $PConduction_wall1_outer$PdT$P$pDERNLSJac14$PdummyVarNLSJac14 _$PConduction_wall1_outer$PdT$P$pDERNLSJac14$PdummyVarNLSJac14(0)

#define _$PConduction_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14(i) data->simulationInfo->analyticJacobians[14].tmpVars[1]
#define $PConduction_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14 _$PConduction_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14(0)

#define _$PConvection_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14(i) data->simulationInfo->analyticJacobians[14].tmpVars[2]
#define $PConvection_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14 _$PConvection_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14(0)

#define _$PConvection_wall1_outer$PdT$P$pDERNLSJac14$PdummyVarNLSJac14(i) data->simulationInfo->analyticJacobians[14].tmpVars[3]
#define $PConvection_wall1_outer$PdT$P$pDERNLSJac14$PdummyVarNLSJac14 _$PConvection_wall1_outer$PdT$P$pDERNLSJac14$PdummyVarNLSJac14(0)

#define _$PRadiation_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14(i) data->simulationInfo->analyticJacobians[14].tmpVars[4]
#define $PRadiation_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14 _$PRadiation_wall1_outer$PQ_flow$P$pDERNLSJac14$PdummyVarNLSJac14(0)

#define _$P$res$P1$P$pDERNLSJac14$PdummyVarNLSJac14(i) data->simulationInfo->analyticJacobians[14].resultVars[0]
#define $P$res$P1$P$pDERNLSJac14$PdummyVarNLSJac14 _$P$res$P1$P$pDERNLSJac14$PdummyVarNLSJac14(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac13 13
  int OM_Result_functionJacNLSJac13_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac13(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac13 */
#define $PConduction_roof_outer_port_a_TSeedNLSJac13 data->simulationInfo->analyticJacobians[13].seedVars[0]
#define _$PConduction_roof_outer$PdT$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[13].tmpVars[0]
#define $PConduction_roof_outer$PdT$P$pDERNLSJac13$PdummyVarNLSJac13 _$PConduction_roof_outer$PdT$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#define _$PConduction_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[13].tmpVars[1]
#define $PConduction_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 _$PConduction_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#define _$PConvection_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[13].tmpVars[2]
#define $PConvection_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 _$PConvection_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#define _$PConvection_roof_outer$PdT$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[13].tmpVars[3]
#define $PConvection_roof_outer$PdT$P$pDERNLSJac13$PdummyVarNLSJac13 _$PConvection_roof_outer$PdT$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#define _$PHeatflow_solar_radiation$Pport$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[13].tmpVars[4]
#define $PHeatflow_solar_radiation$Pport$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 _$PHeatflow_solar_radiation$Pport$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#define _$PRadiation_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[13].tmpVars[5]
#define $PRadiation_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13 _$PRadiation_roof_outer$PQ_flow$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#define _$P$res$P1$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[13].resultVars[0]
#define $P$res$P1$P$pDERNLSJac13$PdummyVarNLSJac13 _$P$res$P1$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac12 12
  int OM_Result_functionJacNLSJac12_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac12(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac12 */
#define $PConduction_roof_inner_port_b_TSeedNLSJac12 data->simulationInfo->analyticJacobians[12].seedVars[0]
#define _$PConduction_roof_inner$PdT$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[12].tmpVars[0]
#define $PConduction_roof_inner$PdT$P$pDERNLSJac12$PdummyVarNLSJac12 _$PConduction_roof_inner$PdT$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$PConduction_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[12].tmpVars[1]
#define $PConduction_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 _$PConduction_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$PConvection_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[12].tmpVars[2]
#define $PConvection_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 _$PConvection_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$PConvection_roof_inner$PdT$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[12].tmpVars[3]
#define $PConvection_roof_inner$PdT$P$pDERNLSJac12$PdummyVarNLSJac12 _$PConvection_roof_inner$PdT$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$PRadiation_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[12].tmpVars[4]
#define $PRadiation_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 _$PRadiation_roof_inner$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$PRadiation_roof_to_floor$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[12].tmpVars[5]
#define $PRadiation_roof_to_floor$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12 _$PRadiation_roof_to_floor$PQ_flow$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$P$res$P1$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[12].resultVars[0]
#define $P$res$P1$P$pDERNLSJac12$PdummyVarNLSJac12 _$P$res$P1$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac11 11
  int OM_Result_functionJacNLSJac11_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac11(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac11 */
#define $PConduction_wall3_outer_port_a_TSeedNLSJac11 data->simulationInfo->analyticJacobians[11].seedVars[0]
#define _$PConduction_wall3_outer$PdT$P$pDERNLSJac11$PdummyVarNLSJac11(i) data->simulationInfo->analyticJacobians[11].tmpVars[0]
#define $PConduction_wall3_outer$PdT$P$pDERNLSJac11$PdummyVarNLSJac11 _$PConduction_wall3_outer$PdT$P$pDERNLSJac11$PdummyVarNLSJac11(0)

#define _$PConduction_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11(i) data->simulationInfo->analyticJacobians[11].tmpVars[1]
#define $PConduction_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11 _$PConduction_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11(0)

#define _$PConvection_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11(i) data->simulationInfo->analyticJacobians[11].tmpVars[2]
#define $PConvection_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11 _$PConvection_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11(0)

#define _$PConvection_wall3_outer$PdT$P$pDERNLSJac11$PdummyVarNLSJac11(i) data->simulationInfo->analyticJacobians[11].tmpVars[3]
#define $PConvection_wall3_outer$PdT$P$pDERNLSJac11$PdummyVarNLSJac11 _$PConvection_wall3_outer$PdT$P$pDERNLSJac11$PdummyVarNLSJac11(0)

#define _$PRadiation_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11(i) data->simulationInfo->analyticJacobians[11].tmpVars[4]
#define $PRadiation_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11 _$PRadiation_wall3_outer$PQ_flow$P$pDERNLSJac11$PdummyVarNLSJac11(0)

#define _$P$res$P1$P$pDERNLSJac11$PdummyVarNLSJac11(i) data->simulationInfo->analyticJacobians[11].resultVars[0]
#define $P$res$P1$P$pDERNLSJac11$PdummyVarNLSJac11 _$P$res$P1$P$pDERNLSJac11$PdummyVarNLSJac11(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac10 10
  int OM_Result_functionJacNLSJac10_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac10(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac10 */
#define $PConduction_wall3_inner_port_b_TSeedNLSJac10 data->simulationInfo->analyticJacobians[10].seedVars[0]
#define _$PConduction_wall3_inner$PdT$P$pDERNLSJac10$PdummyVarNLSJac10(i) data->simulationInfo->analyticJacobians[10].tmpVars[0]
#define $PConduction_wall3_inner$PdT$P$pDERNLSJac10$PdummyVarNLSJac10 _$PConduction_wall3_inner$PdT$P$pDERNLSJac10$PdummyVarNLSJac10(0)

#define _$PConduction_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10(i) data->simulationInfo->analyticJacobians[10].tmpVars[1]
#define $PConduction_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10 _$PConduction_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10(0)

#define _$PConvection_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10(i) data->simulationInfo->analyticJacobians[10].tmpVars[2]
#define $PConvection_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10 _$PConvection_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10(0)

#define _$PConvection_wall3_inner$PdT$P$pDERNLSJac10$PdummyVarNLSJac10(i) data->simulationInfo->analyticJacobians[10].tmpVars[3]
#define $PConvection_wall3_inner$PdT$P$pDERNLSJac10$PdummyVarNLSJac10 _$PConvection_wall3_inner$PdT$P$pDERNLSJac10$PdummyVarNLSJac10(0)

#define _$PRadiation_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10(i) data->simulationInfo->analyticJacobians[10].tmpVars[4]
#define $PRadiation_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10 _$PRadiation_wall3_inner$PQ_flow$P$pDERNLSJac10$PdummyVarNLSJac10(0)

#define _$P$res$P1$P$pDERNLSJac10$PdummyVarNLSJac10(i) data->simulationInfo->analyticJacobians[10].resultVars[0]
#define $P$res$P1$P$pDERNLSJac10$PdummyVarNLSJac10 _$P$res$P1$P$pDERNLSJac10$PdummyVarNLSJac10(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac9 9
  int OM_Result_functionJacNLSJac9_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac9(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac9 */
#define $PConduction_wall4_outer_port_a_TSeedNLSJac9 data->simulationInfo->analyticJacobians[9].seedVars[0]
#define _$PConduction_wall4_outer$PdT$P$pDERNLSJac9$PdummyVarNLSJac9(i) data->simulationInfo->analyticJacobians[9].tmpVars[0]
#define $PConduction_wall4_outer$PdT$P$pDERNLSJac9$PdummyVarNLSJac9 _$PConduction_wall4_outer$PdT$P$pDERNLSJac9$PdummyVarNLSJac9(0)

#define _$PConduction_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9(i) data->simulationInfo->analyticJacobians[9].tmpVars[1]
#define $PConduction_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9 _$PConduction_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9(0)

#define _$PConvection_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9(i) data->simulationInfo->analyticJacobians[9].tmpVars[2]
#define $PConvection_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9 _$PConvection_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9(0)

#define _$PConvection_wall4_outer$PdT$P$pDERNLSJac9$PdummyVarNLSJac9(i) data->simulationInfo->analyticJacobians[9].tmpVars[3]
#define $PConvection_wall4_outer$PdT$P$pDERNLSJac9$PdummyVarNLSJac9 _$PConvection_wall4_outer$PdT$P$pDERNLSJac9$PdummyVarNLSJac9(0)

#define _$PRadiation_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9(i) data->simulationInfo->analyticJacobians[9].tmpVars[4]
#define $PRadiation_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9 _$PRadiation_wall4_outer$PQ_flow$P$pDERNLSJac9$PdummyVarNLSJac9(0)

#define _$P$res$P1$P$pDERNLSJac9$PdummyVarNLSJac9(i) data->simulationInfo->analyticJacobians[9].resultVars[0]
#define $P$res$P1$P$pDERNLSJac9$PdummyVarNLSJac9 _$P$res$P1$P$pDERNLSJac9$PdummyVarNLSJac9(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac8 8
  int OM_Result_functionJacNLSJac8_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac8(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac8 */
#define $PConduction_wall4_inner_port_b_TSeedNLSJac8 data->simulationInfo->analyticJacobians[8].seedVars[0]
#define _$PConvection_wall4_inner$PdT$P$pDERNLSJac8$PdummyVarNLSJac8(i) data->simulationInfo->analyticJacobians[8].tmpVars[0]
#define $PConvection_wall4_inner$PdT$P$pDERNLSJac8$PdummyVarNLSJac8 _$PConvection_wall4_inner$PdT$P$pDERNLSJac8$PdummyVarNLSJac8(0)

#define _$PConvection_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8(i) data->simulationInfo->analyticJacobians[8].tmpVars[1]
#define $PConvection_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8 _$PConvection_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8(0)

#define _$PConduction_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8(i) data->simulationInfo->analyticJacobians[8].tmpVars[2]
#define $PConduction_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8 _$PConduction_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8(0)

#define _$PConduction_wall4_inner$PdT$P$pDERNLSJac8$PdummyVarNLSJac8(i) data->simulationInfo->analyticJacobians[8].tmpVars[3]
#define $PConduction_wall4_inner$PdT$P$pDERNLSJac8$PdummyVarNLSJac8 _$PConduction_wall4_inner$PdT$P$pDERNLSJac8$PdummyVarNLSJac8(0)

#define _$PRadiation_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8(i) data->simulationInfo->analyticJacobians[8].tmpVars[4]
#define $PRadiation_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8 _$PRadiation_wall4_inner$PQ_flow$P$pDERNLSJac8$PdummyVarNLSJac8(0)

#define _$P$res$P1$P$pDERNLSJac8$PdummyVarNLSJac8(i) data->simulationInfo->analyticJacobians[8].resultVars[0]
#define $P$res$P1$P$pDERNLSJac8$PdummyVarNLSJac8 _$P$res$P1$P$pDERNLSJac8$PdummyVarNLSJac8(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac7 7
  int OM_Result_functionJacNLSJac7_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac7(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac7 */
#define $PConduction_roof_outer_port_a_TSeedNLSJac7 data->simulationInfo->analyticJacobians[7].seedVars[0]
#define _$PConduction_roof_outer$PdT$P$pDERNLSJac7$PdummyVarNLSJac7(i) data->simulationInfo->analyticJacobians[7].tmpVars[0]
#define $PConduction_roof_outer$PdT$P$pDERNLSJac7$PdummyVarNLSJac7 _$PConduction_roof_outer$PdT$P$pDERNLSJac7$PdummyVarNLSJac7(0)

#define _$PConduction_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7(i) data->simulationInfo->analyticJacobians[7].tmpVars[1]
#define $PConduction_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 _$PConduction_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7(0)

#define _$PConvection_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7(i) data->simulationInfo->analyticJacobians[7].tmpVars[2]
#define $PConvection_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 _$PConvection_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7(0)

#define _$PConvection_roof_outer$PdT$P$pDERNLSJac7$PdummyVarNLSJac7(i) data->simulationInfo->analyticJacobians[7].tmpVars[3]
#define $PConvection_roof_outer$PdT$P$pDERNLSJac7$PdummyVarNLSJac7 _$PConvection_roof_outer$PdT$P$pDERNLSJac7$PdummyVarNLSJac7(0)

#define _$PHeatflow_solar_radiation$Pport$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7(i) data->simulationInfo->analyticJacobians[7].tmpVars[4]
#define $PHeatflow_solar_radiation$Pport$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 _$PHeatflow_solar_radiation$Pport$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7(0)

#define _$PRadiation_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7(i) data->simulationInfo->analyticJacobians[7].tmpVars[5]
#define $PRadiation_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7 _$PRadiation_roof_outer$PQ_flow$P$pDERNLSJac7$PdummyVarNLSJac7(0)

#define _$P$res$P1$P$pDERNLSJac7$PdummyVarNLSJac7(i) data->simulationInfo->analyticJacobians[7].resultVars[0]
#define $P$res$P1$P$pDERNLSJac7$PdummyVarNLSJac7 _$P$res$P1$P$pDERNLSJac7$PdummyVarNLSJac7(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac6 6
  int OM_Result_functionJacNLSJac6_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac6(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac6 */
#define $PConduction_wall1_outer_port_a_TSeedNLSJac6 data->simulationInfo->analyticJacobians[6].seedVars[0]
#define _$PConvection_wall1_outer$PdT$P$pDERNLSJac6$PdummyVarNLSJac6(i) data->simulationInfo->analyticJacobians[6].tmpVars[0]
#define $PConvection_wall1_outer$PdT$P$pDERNLSJac6$PdummyVarNLSJac6 _$PConvection_wall1_outer$PdT$P$pDERNLSJac6$PdummyVarNLSJac6(0)

#define _$PConvection_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6(i) data->simulationInfo->analyticJacobians[6].tmpVars[1]
#define $PConvection_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6 _$PConvection_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6(0)

#define _$PConduction_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6(i) data->simulationInfo->analyticJacobians[6].tmpVars[2]
#define $PConduction_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6 _$PConduction_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6(0)

#define _$PConduction_wall1_outer$PdT$P$pDERNLSJac6$PdummyVarNLSJac6(i) data->simulationInfo->analyticJacobians[6].tmpVars[3]
#define $PConduction_wall1_outer$PdT$P$pDERNLSJac6$PdummyVarNLSJac6 _$PConduction_wall1_outer$PdT$P$pDERNLSJac6$PdummyVarNLSJac6(0)

#define _$PRadiation_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6(i) data->simulationInfo->analyticJacobians[6].tmpVars[4]
#define $PRadiation_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6 _$PRadiation_wall1_outer$PQ_flow$P$pDERNLSJac6$PdummyVarNLSJac6(0)

#define _$P$res$P1$P$pDERNLSJac6$PdummyVarNLSJac6(i) data->simulationInfo->analyticJacobians[6].resultVars[0]
#define $P$res$P1$P$pDERNLSJac6$PdummyVarNLSJac6 _$P$res$P1$P$pDERNLSJac6$PdummyVarNLSJac6(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac5 5
  int OM_Result_functionJacNLSJac5_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac5(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac5 */
#define $PConduction_wall3_outer_port_a_TSeedNLSJac5 data->simulationInfo->analyticJacobians[5].seedVars[0]
#define _$PConduction_wall3_outer$PdT$P$pDERNLSJac5$PdummyVarNLSJac5(i) data->simulationInfo->analyticJacobians[5].tmpVars[0]
#define $PConduction_wall3_outer$PdT$P$pDERNLSJac5$PdummyVarNLSJac5 _$PConduction_wall3_outer$PdT$P$pDERNLSJac5$PdummyVarNLSJac5(0)

#define _$PConduction_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5(i) data->simulationInfo->analyticJacobians[5].tmpVars[1]
#define $PConduction_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5 _$PConduction_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5(0)

#define _$PConvection_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5(i) data->simulationInfo->analyticJacobians[5].tmpVars[2]
#define $PConvection_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5 _$PConvection_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5(0)

#define _$PConvection_wall3_outer$PdT$P$pDERNLSJac5$PdummyVarNLSJac5(i) data->simulationInfo->analyticJacobians[5].tmpVars[3]
#define $PConvection_wall3_outer$PdT$P$pDERNLSJac5$PdummyVarNLSJac5 _$PConvection_wall3_outer$PdT$P$pDERNLSJac5$PdummyVarNLSJac5(0)

#define _$PRadiation_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5(i) data->simulationInfo->analyticJacobians[5].tmpVars[4]
#define $PRadiation_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5 _$PRadiation_wall3_outer$PQ_flow$P$pDERNLSJac5$PdummyVarNLSJac5(0)

#define _$P$res$P1$P$pDERNLSJac5$PdummyVarNLSJac5(i) data->simulationInfo->analyticJacobians[5].resultVars[0]
#define $P$res$P1$P$pDERNLSJac5$PdummyVarNLSJac5 _$P$res$P1$P$pDERNLSJac5$PdummyVarNLSJac5(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac4 4
  int OM_Result_functionJacNLSJac4_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac4(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac4 */
#define $PConduction_wall4_outer_port_a_TSeedNLSJac4 data->simulationInfo->analyticJacobians[4].seedVars[0]
#define _$PConvection_wall4_outer$PdT$P$pDERNLSJac4$PdummyVarNLSJac4(i) data->simulationInfo->analyticJacobians[4].tmpVars[0]
#define $PConvection_wall4_outer$PdT$P$pDERNLSJac4$PdummyVarNLSJac4 _$PConvection_wall4_outer$PdT$P$pDERNLSJac4$PdummyVarNLSJac4(0)

#define _$PConvection_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4(i) data->simulationInfo->analyticJacobians[4].tmpVars[1]
#define $PConvection_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4 _$PConvection_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4(0)

#define _$PConduction_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4(i) data->simulationInfo->analyticJacobians[4].tmpVars[2]
#define $PConduction_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4 _$PConduction_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4(0)

#define _$PConduction_wall4_outer$PdT$P$pDERNLSJac4$PdummyVarNLSJac4(i) data->simulationInfo->analyticJacobians[4].tmpVars[3]
#define $PConduction_wall4_outer$PdT$P$pDERNLSJac4$PdummyVarNLSJac4 _$PConduction_wall4_outer$PdT$P$pDERNLSJac4$PdummyVarNLSJac4(0)

#define _$PRadiation_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4(i) data->simulationInfo->analyticJacobians[4].tmpVars[4]
#define $PRadiation_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4 _$PRadiation_wall4_outer$PQ_flow$P$pDERNLSJac4$PdummyVarNLSJac4(0)

#define _$P$res$P1$P$pDERNLSJac4$PdummyVarNLSJac4(i) data->simulationInfo->analyticJacobians[4].resultVars[0]
#define $P$res$P1$P$pDERNLSJac4$PdummyVarNLSJac4 _$P$res$P1$P$pDERNLSJac4$PdummyVarNLSJac4(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac3 3
  int OM_Result_functionJacNLSJac3_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac3(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac3 */
#define $PConduction_roof_inner_port_b_TSeedNLSJac3 data->simulationInfo->analyticJacobians[3].seedVars[0]
#define _$PConduction_roof_inner$PdT$P$pDERNLSJac3$PdummyVarNLSJac3(i) data->simulationInfo->analyticJacobians[3].tmpVars[0]
#define $PConduction_roof_inner$PdT$P$pDERNLSJac3$PdummyVarNLSJac3 _$PConduction_roof_inner$PdT$P$pDERNLSJac3$PdummyVarNLSJac3(0)

#define _$PConduction_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3(i) data->simulationInfo->analyticJacobians[3].tmpVars[1]
#define $PConduction_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3 _$PConduction_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3(0)

#define _$PConvection_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3(i) data->simulationInfo->analyticJacobians[3].tmpVars[2]
#define $PConvection_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3 _$PConvection_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3(0)

#define _$PConvection_roof_inner$PdT$P$pDERNLSJac3$PdummyVarNLSJac3(i) data->simulationInfo->analyticJacobians[3].tmpVars[3]
#define $PConvection_roof_inner$PdT$P$pDERNLSJac3$PdummyVarNLSJac3 _$PConvection_roof_inner$PdT$P$pDERNLSJac3$PdummyVarNLSJac3(0)

#define _$PRadiation_roof_to_floor$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3(i) data->simulationInfo->analyticJacobians[3].tmpVars[4]
#define $PRadiation_roof_to_floor$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3 _$PRadiation_roof_to_floor$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3(0)

#define _$PRadiation_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3(i) data->simulationInfo->analyticJacobians[3].tmpVars[5]
#define $PRadiation_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3 _$PRadiation_roof_inner$PQ_flow$P$pDERNLSJac3$PdummyVarNLSJac3(0)

#define _$P$res$P1$P$pDERNLSJac3$PdummyVarNLSJac3(i) data->simulationInfo->analyticJacobians[3].resultVars[0]
#define $P$res$P1$P$pDERNLSJac3$PdummyVarNLSJac3 _$P$res$P1$P$pDERNLSJac3$PdummyVarNLSJac3(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac2 2
  int OM_Result_functionJacNLSJac2_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac2(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac2 */
#define $PConduction_wall1_inner_port_b_TSeedNLSJac2 data->simulationInfo->analyticJacobians[2].seedVars[0]
#define _$PConduction_wall1_inner$PdT$P$pDERNLSJac2$PdummyVarNLSJac2(i) data->simulationInfo->analyticJacobians[2].tmpVars[0]
#define $PConduction_wall1_inner$PdT$P$pDERNLSJac2$PdummyVarNLSJac2 _$PConduction_wall1_inner$PdT$P$pDERNLSJac2$PdummyVarNLSJac2(0)

#define _$PConduction_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2(i) data->simulationInfo->analyticJacobians[2].tmpVars[1]
#define $PConduction_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2 _$PConduction_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2(0)

#define _$PConvection_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2(i) data->simulationInfo->analyticJacobians[2].tmpVars[2]
#define $PConvection_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2 _$PConvection_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2(0)

#define _$PConvection_wall1_inner$PdT$P$pDERNLSJac2$PdummyVarNLSJac2(i) data->simulationInfo->analyticJacobians[2].tmpVars[3]
#define $PConvection_wall1_inner$PdT$P$pDERNLSJac2$PdummyVarNLSJac2 _$PConvection_wall1_inner$PdT$P$pDERNLSJac2$PdummyVarNLSJac2(0)

#define _$PRadiation_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2(i) data->simulationInfo->analyticJacobians[2].tmpVars[4]
#define $PRadiation_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2 _$PRadiation_wall1_inner$PQ_flow$P$pDERNLSJac2$PdummyVarNLSJac2(0)

#define _$P$res$P1$P$pDERNLSJac2$PdummyVarNLSJac2(i) data->simulationInfo->analyticJacobians[2].resultVars[0]
#define $P$res$P1$P$pDERNLSJac2$PdummyVarNLSJac2 _$P$res$P1$P$pDERNLSJac2$PdummyVarNLSJac2(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac1 1
  int OM_Result_functionJacNLSJac1_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac1(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac1 */
#define $PConduction_wall3_inner_port_b_TSeedNLSJac1 data->simulationInfo->analyticJacobians[1].seedVars[0]
#define _$PConduction_wall3_inner$PdT$P$pDERNLSJac1$PdummyVarNLSJac1(i) data->simulationInfo->analyticJacobians[1].tmpVars[0]
#define $PConduction_wall3_inner$PdT$P$pDERNLSJac1$PdummyVarNLSJac1 _$PConduction_wall3_inner$PdT$P$pDERNLSJac1$PdummyVarNLSJac1(0)

#define _$PConduction_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1(i) data->simulationInfo->analyticJacobians[1].tmpVars[1]
#define $PConduction_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1 _$PConduction_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1(0)

#define _$PConvection_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1(i) data->simulationInfo->analyticJacobians[1].tmpVars[2]
#define $PConvection_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1 _$PConvection_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1(0)

#define _$PConvection_wall3_inner$PdT$P$pDERNLSJac1$PdummyVarNLSJac1(i) data->simulationInfo->analyticJacobians[1].tmpVars[3]
#define $PConvection_wall3_inner$PdT$P$pDERNLSJac1$PdummyVarNLSJac1 _$PConvection_wall3_inner$PdT$P$pDERNLSJac1$PdummyVarNLSJac1(0)

#define _$PRadiation_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1(i) data->simulationInfo->analyticJacobians[1].tmpVars[4]
#define $PRadiation_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1 _$PRadiation_wall3_inner$PQ_flow$P$pDERNLSJac1$PdummyVarNLSJac1(0)

#define _$P$res$P1$P$pDERNLSJac1$PdummyVarNLSJac1(i) data->simulationInfo->analyticJacobians[1].resultVars[0]
#define $P$res$P1$P$pDERNLSJac1$PdummyVarNLSJac1 _$P$res$P1$P$pDERNLSJac1$PdummyVarNLSJac1(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_NLSJac0 0
  int OM_Result_functionJacNLSJac0_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianNLSJac0(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac0 */
#define $PConduction_wall4_inner_port_b_TSeedNLSJac0 data->simulationInfo->analyticJacobians[0].seedVars[0]
#define _$PConduction_wall4_inner$PdT$P$pDERNLSJac0$PdummyVarNLSJac0(i) data->simulationInfo->analyticJacobians[0].tmpVars[0]
#define $PConduction_wall4_inner$PdT$P$pDERNLSJac0$PdummyVarNLSJac0 _$PConduction_wall4_inner$PdT$P$pDERNLSJac0$PdummyVarNLSJac0(0)

#define _$PConduction_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0(i) data->simulationInfo->analyticJacobians[0].tmpVars[1]
#define $PConduction_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0 _$PConduction_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0(0)

#define _$PConvection_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0(i) data->simulationInfo->analyticJacobians[0].tmpVars[2]
#define $PConvection_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0 _$PConvection_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0(0)

#define _$PConvection_wall4_inner$PdT$P$pDERNLSJac0$PdummyVarNLSJac0(i) data->simulationInfo->analyticJacobians[0].tmpVars[3]
#define $PConvection_wall4_inner$PdT$P$pDERNLSJac0$PdummyVarNLSJac0 _$PConvection_wall4_inner$PdT$P$pDERNLSJac0$PdummyVarNLSJac0(0)

#define _$PRadiation_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0(i) data->simulationInfo->analyticJacobians[0].tmpVars[4]
#define $PRadiation_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0 _$PRadiation_wall4_inner$PQ_flow$P$pDERNLSJac0$PdummyVarNLSJac0(0)

#define _$P$res$P1$P$pDERNLSJac0$PdummyVarNLSJac0(i) data->simulationInfo->analyticJacobians[0].resultVars[0]
#define $P$res$P1$P$pDERNLSJac0$PdummyVarNLSJac0 _$P$res$P1$P$pDERNLSJac0$PdummyVarNLSJac0(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_A 19
  int OM_Result_functionJacA_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianA(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* A */
#define $PCapacitor_indoor_air_TSeedA data->simulationInfo->analyticJacobians[19].seedVars[0]
#define $PCapacitor_roof_TSeedA data->simulationInfo->analyticJacobians[19].seedVars[1]
#define $PCapacitor_wall1_TSeedA data->simulationInfo->analyticJacobians[19].seedVars[2]
#define $PCapacitor_wall3_TSeedA data->simulationInfo->analyticJacobians[19].seedVars[3]
#define $PCapacitor_wall4_TSeedA data->simulationInfo->analyticJacobians[19].seedVars[4]

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_B 18
  int OM_Result_functionJacB_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianB(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* B */

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_C 17
  int OM_Result_functionJacC_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianC(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* C */

#if defined(__cplusplus)
extern "C" {
#endif
  #define OM_Result_INDEX_JAC_D 16
  int OM_Result_functionJacD_column(void* data, threadData_t *threadData);
  int OM_Result_initialAnalyticJacobianD(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* D */



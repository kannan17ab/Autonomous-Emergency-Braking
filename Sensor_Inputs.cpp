//
// File: Sensor_Inputs.cpp
//
// Code generated for Simulink model 'Sensor_Inputs'.
//
// Model version                  : 1.1
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Sat May  3 13:19:19 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Sensor_Inputs.h"
#include "rtwtypes.h"

// Named constants for Chart: '<S1>/Chart'
const uint8_T Sensor_Inputs_IN_Full_brake{ 1U };

const uint8_T Sensor_Inputs_IN_Half_brake{ 2U };

const uint8_T Sensor_Inputs_IN_Warning{ 3U };

// Model step function
void Sensor_Inputs::step()
{
  real_T g_out_tmp;
  boolean_T f_out;
  boolean_T guard1;
  boolean_T guard2;

  // Outputs for Atomic SubSystem: '<Root>/Sensor_Inputs'
  // Chart: '<S1>/Chart' incorporates:
  //   Inport: '<Root>/Camera_Object_Type'
  //   Inport: '<Root>/Radar_Distance'
  //   Inport: '<Root>/Vehicle_Speed'

  if (Sensor_Inputs_DW.is_active_c2_Sensor_Inputs == 0U) {
    Sensor_Inputs_DW.is_active_c2_Sensor_Inputs = 1U;
    Sensor_Inputs_DW.is_c2_Sensor_Inputs = Sensor_Inputs_IN_Warning;

    // Outport: '<Root>/Risk_Level'
    Sensor_Inputs_Y.Risk_Level = 1.0;
  } else {
    guard1 = false;
    guard2 = false;
    switch (Sensor_Inputs_DW.is_c2_Sensor_Inputs) {
     case Sensor_Inputs_IN_Full_brake:
      // Outport: '<Root>/Risk_Level'
      Sensor_Inputs_Y.Risk_Level = 3.0;
      if (Sensor_Inputs_U.Camera_Object_Type > 0.0) {
        f_out = (Sensor_Inputs_U.Radar_Distance / (Sensor_Inputs_U.Vehicle_Speed
                  + 0.1) > 1.5);
      } else {
        f_out = false;
      }

      if (f_out) {
        guard2 = true;
      } else {
        if (Sensor_Inputs_U.Camera_Object_Type > 0.0) {
          g_out_tmp = Sensor_Inputs_U.Radar_Distance /
            (Sensor_Inputs_U.Vehicle_Speed + 0.1);
          f_out = ((g_out_tmp > 0.5) && (g_out_tmp < 1.5));
        } else {
          f_out = false;
        }

        if (f_out) {
          Sensor_Inputs_DW.is_c2_Sensor_Inputs = Sensor_Inputs_IN_Half_brake;

          // Outport: '<Root>/Risk_Level'
          Sensor_Inputs_Y.Risk_Level = 2.0;
        } else {
          if (Sensor_Inputs_U.Camera_Object_Type > 0.0) {
            f_out = (Sensor_Inputs_U.Radar_Distance /
                     (Sensor_Inputs_U.Vehicle_Speed + 0.1) > 1.5);
          } else {
            f_out = false;
          }

          if (f_out) {
            guard2 = true;
          } else {
            // Outport: '<Root>/AEB_Brake_Pressure'
            Sensor_Inputs_Y.AEB_Brake_Pressure = 100.0;
          }
        }
      }
      break;

     case Sensor_Inputs_IN_Half_brake:
      // Outport: '<Root>/Risk_Level'
      Sensor_Inputs_Y.Risk_Level = 2.0;
      if (Sensor_Inputs_U.Camera_Object_Type > 0.0) {
        f_out = (Sensor_Inputs_U.Radar_Distance / (Sensor_Inputs_U.Vehicle_Speed
                  + 0.1) < 0.5);
      } else {
        f_out = false;
      }

      if (f_out) {
        Sensor_Inputs_DW.is_c2_Sensor_Inputs = Sensor_Inputs_IN_Full_brake;

        // Outport: '<Root>/Risk_Level'
        Sensor_Inputs_Y.Risk_Level = 3.0;
      } else {
        if (Sensor_Inputs_U.Camera_Object_Type > 0.0) {
          f_out = (Sensor_Inputs_U.Radar_Distance /
                   (Sensor_Inputs_U.Vehicle_Speed + 0.1) > 1.5);
        } else {
          f_out = false;
        }

        if (f_out) {
          Sensor_Inputs_DW.is_c2_Sensor_Inputs = Sensor_Inputs_IN_Warning;

          // Outport: '<Root>/Risk_Level'
          Sensor_Inputs_Y.Risk_Level = 1.0;
        } else {
          // Outport: '<Root>/AEB_Brake_Pressure'
          Sensor_Inputs_Y.AEB_Brake_Pressure = 50.0;
        }
      }
      break;

     default:
      // Outport: '<Root>/Risk_Level'
      // case IN_Warning:
      Sensor_Inputs_Y.Risk_Level = 1.0;
      if (Sensor_Inputs_U.Camera_Object_Type > 0.0) {
        f_out = (Sensor_Inputs_U.Radar_Distance / (Sensor_Inputs_U.Vehicle_Speed
                  + 0.1) < 0.5);
      } else {
        f_out = false;
      }

      if (f_out) {
        guard1 = true;
      } else {
        if (Sensor_Inputs_U.Camera_Object_Type > 0.0) {
          g_out_tmp = Sensor_Inputs_U.Radar_Distance /
            (Sensor_Inputs_U.Vehicle_Speed + 0.1);
          f_out = ((g_out_tmp > 0.5) && (g_out_tmp < 1.5));
        } else {
          f_out = false;
        }

        if (f_out) {
          Sensor_Inputs_DW.is_c2_Sensor_Inputs = Sensor_Inputs_IN_Half_brake;

          // Outport: '<Root>/Risk_Level'
          Sensor_Inputs_Y.Risk_Level = 2.0;
        } else {
          if (Sensor_Inputs_U.Camera_Object_Type > 0.0) {
            f_out = (Sensor_Inputs_U.Radar_Distance /
                     (Sensor_Inputs_U.Vehicle_Speed + 0.1) < 0.5);
          } else {
            f_out = false;
          }

          if (f_out) {
            guard1 = true;
          } else {
            // Outport: '<Root>/AEB_Brake_Pressure' incorporates:
            //   Inport: '<Root>/Driver_Brake_Input'

            Sensor_Inputs_Y.AEB_Brake_Pressure =
              Sensor_Inputs_U.Driver_Brake_Input;
          }
        }
      }
      break;
    }

    if (guard2) {
      Sensor_Inputs_DW.is_c2_Sensor_Inputs = Sensor_Inputs_IN_Warning;

      // Outport: '<Root>/Risk_Level'
      Sensor_Inputs_Y.Risk_Level = 1.0;
    }

    if (guard1) {
      Sensor_Inputs_DW.is_c2_Sensor_Inputs = Sensor_Inputs_IN_Full_brake;

      // Outport: '<Root>/Risk_Level'
      Sensor_Inputs_Y.Risk_Level = 3.0;
    }
  }

  // End of Chart: '<S1>/Chart'
  // End of Outputs for SubSystem: '<Root>/Sensor_Inputs'
}

// Model initialize function
void Sensor_Inputs::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void Sensor_Inputs::terminate()
{
  // (no terminate code required)
}

// Constructor
Sensor_Inputs::Sensor_Inputs() :
  Sensor_Inputs_U(),
  Sensor_Inputs_Y(),
  Sensor_Inputs_DW(),
  Sensor_Inputs_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Sensor_Inputs::~Sensor_Inputs() = default;

// Real-Time Model get method
Sensor_Inputs::RT_MODEL_Sensor_Inputs_T * Sensor_Inputs::getRTM()
{
  return (&Sensor_Inputs_M);
}

//
// File trailer for generated code.
//
// [EOF]
//

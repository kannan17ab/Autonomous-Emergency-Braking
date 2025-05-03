//
// File: Sensor_Inputs.h
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
#ifndef Sensor_Inputs_h_
#define Sensor_Inputs_h_
#include <cmath>
#include "rtwtypes.h"
#include "Sensor_Inputs_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model Sensor_Inputs
class Sensor_Inputs final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_Sensor_Inputs_T {
    uint8_T is_active_c2_Sensor_Inputs;// '<S1>/Chart'
    uint8_T is_c2_Sensor_Inputs;       // '<S1>/Chart'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_Sensor_Inputs_T {
    real_T Radar_Distance;             // '<Root>/Radar_Distance'
    real_T Camera_Object_Type;         // '<Root>/Camera_Object_Type'
    real_T Vehicle_Speed;              // '<Root>/Vehicle_Speed'
    real_T Driver_Brake_Input;         // '<Root>/Driver_Brake_Input'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_Sensor_Inputs_T {
    real_T Risk_Level;                 // '<Root>/Risk_Level'
    real_T AEB_Brake_Pressure;         // '<Root>/AEB_Brake_Pressure'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_Sensor_Inputs_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  Sensor_Inputs(Sensor_Inputs const&) = delete;

  // Assignment Operator
  Sensor_Inputs& operator= (Sensor_Inputs const&) & = delete;

  // Move Constructor
  Sensor_Inputs(Sensor_Inputs &&) = delete;

  // Move Assignment Operator
  Sensor_Inputs& operator= (Sensor_Inputs &&) = delete;

  // Real-Time Model get method
  Sensor_Inputs::RT_MODEL_Sensor_Inputs_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_Sensor_Inputs_T *pExtU_Sensor_Inputs_T)
  {
    Sensor_Inputs_U = *pExtU_Sensor_Inputs_T;
  }

  // Root outports get method
  const ExtY_Sensor_Inputs_T &getExternalOutputs() const
  {
    return Sensor_Inputs_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  Sensor_Inputs();

  // Destructor
  ~Sensor_Inputs();

  // private data and function members
 private:
  // External inputs
  ExtU_Sensor_Inputs_T Sensor_Inputs_U;

  // External outputs
  ExtY_Sensor_Inputs_T Sensor_Inputs_Y;

  // Block states
  DW_Sensor_Inputs_T Sensor_Inputs_DW;

  // Real-Time Model
  RT_MODEL_Sensor_Inputs_T Sensor_Inputs_M;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Note that this particular code originates from a subsystem build,
//  and has its own system numbers different from the parent model.
//  Refer to the system hierarchy for this subsystem below, and use the
//  MATLAB hilite_system command to trace the generated code back
//  to the parent model.  For example,
//
//  hilite_system('Autonomous_Emergency_Braking/Sensor_Inputs')    - opens subsystem Autonomous_Emergency_Braking/Sensor_Inputs
//  hilite_system('Autonomous_Emergency_Braking/Sensor_Inputs/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Autonomous_Emergency_Braking'
//  '<S1>'   : 'Autonomous_Emergency_Braking/Sensor_Inputs'
//  '<S2>'   : 'Autonomous_Emergency_Braking/Sensor_Inputs/Chart'

#endif                                 // Sensor_Inputs_h_

//
// File trailer for generated code.
//
// [EOF]
//

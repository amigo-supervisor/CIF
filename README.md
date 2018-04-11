# CIF
CIF models of the robot and its requirements, also included are the tools to convert a C99 supervisor library to a python module. This is a partial model of the robot and its requirements, designed for the thesis.

## Robot model
This folder contains the CIF specification of the Amigo model/plant

## Safety requirements
This folder contains the CIF specification of the Safety requirements

## Skill requirements
This folder contains the CIF specification of the Skill requirements

## Task requirements
This folder contains the CIF specification of the Task requirements

## C99
This folder contains the C99 library of the supervisor synthesized in CIF, it also included the script to convert this C99 library to a python module.

## Step-by-step from CIF specification to Python module

- Combine the required CIF specifications in one file, e.g: Amigo_model.cif; Amigo_safety.cif; Amigo_grab_skill.cif; Amigo_navigate_skill.cif; Amigo_place_skill.cif; Amigo_pickup_task.cif. This will form the basis for the synthesis of the supervisor, in this case for case study 1.

- Apply data-based synthesis in with the CIF tool set in Eclipse. See cif.se.wtb.tue.nl

- Optionally run the event-disabler. This disables events that are not present in the alphabet of the supervisor. This could be useful when creating a controller for a part of the modelled robot.

- Convert the synthesized supervisor to a C99 library with the CIF tool set in Eclipse. Provide the Amigo prefix

- Copy Amigo_library.h, Amigo_library.c, Amigo_engine.h, Amigo_engine.c to the C99 folder.

- We are now going to use CFFI to convert the C99 library to a python module. A script called cffi_amigo_engine.py is included to facilitate this conversion, but some things have to be taken care of first:
   + install cffi with `pip2 install cffi`
   + from Amigo_engine.h remove all directives (#if, #define, etc)
   + from Amigo_engine.h remove all extern functions
   + from Amigo_engine.h remove all includes
   + to make sure Amigo_engine.h knows of all the CIF specific types, paste this at the top of the header:
         
       ```c
       typedef _Bool BoolType;
       typedef int32_t IntType;
       typedef double RealType;
       ```

    + Add the following to Amigo_engine.c to forward declare the callbacks and force event output

        ```c
        #ifndef EVENT_OUTPUT
        #define EVENT_OUTPUT 1
        #endif

        static void Amigo_InfoEvent(Amigo_Event_ event, BoolType pre);
        static void Amigo_AssignInputVariables();
        ```

    + Do not include Amigo\_engine.h anymore, but include Amigo\_library.h

        ```c
        // #include "Amigo_engine.h"
        #include "Amigo_library.h"
        ```

- Now run the following in the C99 folder: `python2 cffi_amigo_engine.py`
- This will create `_amigo_engine.so`, copy this file to challenge\_supervisor/src/cif/ in the tue\_robocup repo
- We can now execute `roslaunch challenge_supervisor.launch` in the amigo_brinhup/launch/state_machines folder on the robot

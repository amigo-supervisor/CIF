/* Cif to C translation of Amigo.cif
 * Generated file, DO NOT EDIT
 */

#include <stdio.h>
#include <stdlib.h>
// #include "Amigo_engine.h"
#include "Amigo_library.h"


#ifndef MAX_NUM_EVENTS
#define MAX_NUM_EVENTS 30
#endif

#ifndef EVENT_OUTPUT
#define EVENT_OUTPUT 1
#endif
/* What to do if a range error is found in an assignment? */
#ifdef KEEP_RUNNING
static inline void RangeErrorDetected(void) { /* Do nothing, error is already reported. */ }
#else
static inline void RangeErrorDetected(void) { exit(1); }
#endif

/* Type support code. */
int EnumTypePrint(AmigoEnum value, char *dest, int start, int end) {
    int last = end - 1;
    const char *lit_name = enum_names[value];
    while (start < last && *lit_name) {
        dest[start++] = *lit_name;
        lit_name++;
    }
    dest[start] = '\0';
    return start;
}

static void Amigo_InfoEvent(Amigo_Event_ event, BoolType pre);
static void Amigo_AssignInputVariables();


/** Event names. */
const char *Amigo_event_names[] = {
    "initial-step",                  /**< Initial step. */
    "delay-step",                    /**< Delay step. */
    "tau",                           /**< Tau step. */
    "goto_phase2",                   /**< Event goto_phase2. */
    "arm_left_idle",                 /**< Event arm_left_idle. */
    "arm_left_move",                 /**< Event arm_left_move. */
    "arm_left_plan",                 /**< Event arm_left_plan. */
    "arm_left_replan",               /**< Event arm_left_replan. */
    "arm_left_plan_to_grab",         /**< Event arm_left_plan_to_grab. */
    "arm_left_grab",                 /**< Event arm_left_grab. */
    "arm_right_idle",                /**< Event arm_right_idle. */
    "arm_right_move",                /**< Event arm_right_move. */
    "arm_right_plan",                /**< Event arm_right_plan. */
    "arm_right_replan",              /**< Event arm_right_replan. */
    "arm_right_plan_to_grab",        /**< Event arm_right_plan_to_grab. */
    "arm_right_grab",                /**< Event arm_right_grab. */
    "base_idle",                     /**< Event base_idle. */
    "base_move",                     /**< Event base_move. */
    "base_plan",                     /**< Event base_plan. */
    "grab_skill_grab",               /**< Event grab_skill_grab. */
    "grab_skill_determine_grab_arm", /**< Event grab_skill_determine_grab_arm. */
    "left_grab_exec_check_in_WS",    /**< Event left_grab_exec_check_in_WS. */
    "left_grab_exec_start",          /**< Event left_grab_exec_start. */
    "left_grab_exec_complete",       /**< Event left_grab_exec_complete. */
    "left_grab_exec_idle",           /**< Event left_grab_exec_idle. */
    "navigation_skill_move_to",      /**< Event navigation_skill_move_to. */
    "right_grab_exec_check_in_WS",   /**< Event right_grab_exec_check_in_WS. */
    "right_grab_exec_start",         /**< Event right_grab_exec_start. */
    "right_grab_exec_complete",      /**< Event right_grab_exec_complete. */
    "right_grab_exec_idle",          /**< Event right_grab_exec_idle. */
    "task_waiting",                  /**< Event task_waiting. */
};

/** Enumeration names. */
const char *enum_names[] = {
    "completing",
    "grabbing",
    "idle",
    "idling",
    "moving",
    "moving_to",
    "phase1",
    "phase2",
    "planning",
    "planning_to_grab",
    "replanning",
    "starting",
    "wait",
    "X",
};

/* Constants. */


/* Functions. */


/* Input variables. */
IntType arm_left_plan_viable_;         /**< Input variable "int[0..2] arm_left.plan_viable". */
BoolType arm_left_collision_on_path_;  /**< Input variable "bool arm_left.collision_on_path". */
BoolType arm_left_moving_arm_;         /**< Input variable "bool arm_left.moving_arm". */
BoolType arm_left_goal_reached_;       /**< Input variable "bool arm_left.goal_reached". */
BoolType arm_left_object_in_arm_;      /**< Input variable "bool arm_left.object_in_arm". */
IntType arm_right_plan_viable_;        /**< Input variable "int[0..2] arm_right.plan_viable". */
BoolType arm_right_collision_on_path_; /**< Input variable "bool arm_right.collision_on_path". */
BoolType arm_right_moving_arm_;        /**< Input variable "bool arm_right.moving_arm". */
BoolType arm_right_goal_reached_;      /**< Input variable "bool arm_right.goal_reached". */
BoolType arm_right_object_in_arm_;     /**< Input variable "bool arm_right.object_in_arm". */
IntType base_plan_viable_;             /**< Input variable "int[0..2] base.plan_viable". */
BoolType base_collision_on_path_;      /**< Input variable "bool base.collision_on_path". */
BoolType base_moving_base_;            /**< Input variable "bool base.moving_base". */
BoolType base_goal_reached_;           /**< Input variable "bool base.goal_reached". */
IntType grab_skill_use_arm_;           /**< Input variable "int[0..2] grab_skill.use_arm". */
IntType left_grab_exec_object_in_WS_;  /**< Input variable "int[0..2] left_grab_exec.object_in_WS". */
IntType right_grab_exec_object_in_WS_; /**< Input variable "int[0..2] right_grab_exec.object_in_WS". */
BoolType task_object_grabbed_;         /**< Input variable "bool task.object_grabbed". */

/* State variables. */
AmigoEnum arm_left_;              /**< Discrete variable "E arm_left". */
AmigoEnum arm_right_;             /**< Discrete variable "E arm_right". */
AmigoEnum base_;                  /**< Discrete variable "E base". */
AmigoEnum grab_skill_;            /**< Discrete variable "E grab_skill". */
AmigoEnum left_grab_exec_;        /**< Discrete variable "E left_grab_exec". */
AmigoEnum navigation_skill_;      /**< Discrete variable "E navigation_skill". */
AmigoEnum requirement_arm_left_;  /**< Discrete variable "E requirement_arm_left". */
AmigoEnum requirement_arm_right_; /**< Discrete variable "E requirement_arm_right". */
AmigoEnum right_grab_exec_;       /**< Discrete variable "E right_grab_exec". */
AmigoEnum SafeBaseMovement_;      /**< Discrete variable "E SafeBaseMovement". */
AmigoEnum sup_;                   /**< Discrete variable "E sup". */
BoolType task_navigating_;        /**< Discrete variable "bool task.navigating". */
BoolType task_grabbing_;          /**< Discrete variable "bool task.grabbing". */
AmigoEnum task_;                  /**< Discrete variable "E task". */

RealType model_time; /**< Current model time. */

/** Initialize constants. */
static void InitConstants(void) {

}

/** Print function. */
#if PRINT_OUTPUT
static void PrintOutput(Amigo_Event_ event, BoolType pre) {
}
#endif

/* Event execution code. */

/**
 * Execute code for event "arm_left.grab".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent0(void) {
    BoolType guard = ((((arm_left_) == (_Amigo_planning_to_grab)) || ((arm_left_) == (_Amigo_replanning))) && (((requirement_arm_left_) == (_Amigo_X)) && ((arm_left_plan_viable_) == (1)))) && ((!(arm_left_collision_on_path_)) && ((sup_) == (_Amigo_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_left_grab_, TRUE);
    #endif

    if ((arm_left_) == (_Amigo_planning_to_grab)) {
        arm_left_ = _Amigo_grabbing;
    } else if ((arm_left_) == (_Amigo_replanning)) {
        arm_left_ = _Amigo_grabbing;
    }

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_left_grab_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "arm_left.idle".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent1(void) {
    BoolType guard = (((((arm_left_) == (_Amigo_planning)) || ((arm_left_) == (_Amigo_planning_to_grab))) || (((arm_left_) == (_Amigo_replanning)) || ((((arm_left_) == (_Amigo_moving)) && ((arm_left_goal_reached_) || ((arm_left_moving_arm_) != (TRUE)))) || (((arm_left_) == (_Amigo_grabbing)) && ((arm_left_object_in_arm_) || ((arm_left_moving_arm_) != (TRUE))))))) && ((requirement_arm_left_) == (_Amigo_X))) && ((((arm_left_plan_viable_) == (2)) || ((arm_left_goal_reached_) || (((arm_left_) == (_Amigo_moving)) && ((arm_left_moving_arm_) == (FALSE))))) && ((sup_) == (_Amigo_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_left_idle_, TRUE);
    #endif

    if ((arm_left_) == (_Amigo_planning)) {
        arm_left_ = _Amigo_idling;
    } else if ((arm_left_) == (_Amigo_planning_to_grab)) {
        arm_left_ = _Amigo_idling;
    } else if ((arm_left_) == (_Amigo_replanning)) {
        arm_left_ = _Amigo_idling;
    } else if (((arm_left_) == (_Amigo_moving)) && ((arm_left_goal_reached_) || ((arm_left_moving_arm_) != (TRUE)))) {
        arm_left_ = _Amigo_idling;
    } else if (((arm_left_) == (_Amigo_grabbing)) && ((arm_left_object_in_arm_) || ((arm_left_moving_arm_) != (TRUE)))) {
        arm_left_ = _Amigo_idling;
    }

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_left_idle_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "arm_left.move".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent2(void) {
    BoolType guard = ((((arm_left_) == (_Amigo_planning)) || ((arm_left_) == (_Amigo_replanning))) && (((requirement_arm_left_) == (_Amigo_X)) && ((arm_left_plan_viable_) == (1)))) && ((!(arm_left_collision_on_path_)) && ((sup_) == (_Amigo_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_left_move_, TRUE);
    #endif

    if ((arm_left_) == (_Amigo_planning)) {
        arm_left_ = _Amigo_moving;
    } else if ((arm_left_) == (_Amigo_replanning)) {
        arm_left_ = _Amigo_moving;
    }

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_left_move_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "arm_left.plan".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent3(void) {
    BoolType guard = ((((arm_left_) == (_Amigo_idling)) || ((arm_left_) == (_Amigo_grabbing))) && (((left_grab_exec_) == (_Amigo_starting)) && ((left_grab_exec_object_in_WS_) == (1)))) && ((sup_) == (_Amigo_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_left_plan_, TRUE);
    #endif

    if ((arm_left_) == (_Amigo_idling)) {
        arm_left_ = _Amigo_planning;
    } else if ((arm_left_) == (_Amigo_grabbing)) {
        arm_left_ = _Amigo_planning;
    }

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_left_plan_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "arm_left.plan_to_grab".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent4(void) {
    BoolType guard = ((((arm_left_) == (_Amigo_idling)) || ((arm_left_) == (_Amigo_moving))) && (((left_grab_exec_) == (_Amigo_starting)) && ((left_grab_exec_object_in_WS_) == (2)))) && ((sup_) == (_Amigo_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_left_plan_to_grab_, TRUE);
    #endif

    if ((arm_left_) == (_Amigo_idling)) {
        arm_left_ = _Amigo_planning_to_grab;
    } else if ((arm_left_) == (_Amigo_moving)) {
        arm_left_ = _Amigo_planning_to_grab;
    }

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_left_plan_to_grab_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "arm_left.replan".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent5(void) {
    BoolType guard = ((((arm_left_) == (_Amigo_moving)) || ((arm_left_) == (_Amigo_grabbing))) && ((requirement_arm_left_) == (_Amigo_X))) && (((arm_left_collision_on_path_) || ((arm_left_plan_viable_) != (1))) && ((sup_) == (_Amigo_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_left_replan_, TRUE);
    #endif

    if ((arm_left_) == (_Amigo_moving)) {
        arm_left_ = _Amigo_replanning;
    } else if ((arm_left_) == (_Amigo_grabbing)) {
        arm_left_ = _Amigo_replanning;
    }

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_left_replan_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "arm_right.grab".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent6(void) {
    BoolType guard = ((((arm_right_) == (_Amigo_planning_to_grab)) || ((arm_right_) == (_Amigo_replanning))) && (((requirement_arm_right_) == (_Amigo_X)) && ((arm_right_plan_viable_) == (1)))) && ((!(arm_right_collision_on_path_)) && ((sup_) == (_Amigo_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_right_grab_, TRUE);
    #endif

    if ((arm_right_) == (_Amigo_planning_to_grab)) {
        arm_right_ = _Amigo_grabbing;
    } else if ((arm_right_) == (_Amigo_replanning)) {
        arm_right_ = _Amigo_grabbing;
    }

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_right_grab_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "arm_right.idle".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent7(void) {
    BoolType guard = (((((arm_right_) == (_Amigo_planning)) || ((arm_right_) == (_Amigo_planning_to_grab))) || (((arm_right_) == (_Amigo_replanning)) || ((((arm_right_) == (_Amigo_moving)) && ((arm_right_goal_reached_) || ((arm_right_moving_arm_) != (TRUE)))) || (((arm_right_) == (_Amigo_grabbing)) && ((arm_right_object_in_arm_) || ((arm_right_moving_arm_) != (TRUE))))))) && ((requirement_arm_right_) == (_Amigo_X))) && ((((arm_right_plan_viable_) == (2)) || ((arm_right_goal_reached_) || (((arm_right_) == (_Amigo_moving)) && ((arm_right_moving_arm_) == (FALSE))))) && ((sup_) == (_Amigo_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_right_idle_, TRUE);
    #endif

    if ((arm_right_) == (_Amigo_planning)) {
        arm_right_ = _Amigo_idling;
    } else if ((arm_right_) == (_Amigo_planning_to_grab)) {
        arm_right_ = _Amigo_idling;
    } else if ((arm_right_) == (_Amigo_replanning)) {
        arm_right_ = _Amigo_idling;
    } else if (((arm_right_) == (_Amigo_moving)) && ((arm_right_goal_reached_) || ((arm_right_moving_arm_) != (TRUE)))) {
        arm_right_ = _Amigo_idling;
    } else if (((arm_right_) == (_Amigo_grabbing)) && ((arm_right_object_in_arm_) || ((arm_right_moving_arm_) != (TRUE)))) {
        arm_right_ = _Amigo_idling;
    }

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_right_idle_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "arm_right.move".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent8(void) {
    BoolType guard = ((((arm_right_) == (_Amigo_planning)) || ((arm_right_) == (_Amigo_replanning))) && (((requirement_arm_right_) == (_Amigo_X)) && ((arm_right_plan_viable_) == (1)))) && ((!(arm_right_collision_on_path_)) && ((sup_) == (_Amigo_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_right_move_, TRUE);
    #endif

    if ((arm_right_) == (_Amigo_planning)) {
        arm_right_ = _Amigo_moving;
    } else if ((arm_right_) == (_Amigo_replanning)) {
        arm_right_ = _Amigo_moving;
    }

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_right_move_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "arm_right.plan".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent9(void) {
    BoolType guard = ((((arm_right_) == (_Amigo_idling)) || ((arm_right_) == (_Amigo_grabbing))) && (((right_grab_exec_) == (_Amigo_starting)) && ((right_grab_exec_object_in_WS_) == (1)))) && ((sup_) == (_Amigo_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_right_plan_, TRUE);
    #endif

    if ((arm_right_) == (_Amigo_idling)) {
        arm_right_ = _Amigo_planning;
    } else if ((arm_right_) == (_Amigo_grabbing)) {
        arm_right_ = _Amigo_planning;
    }

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_right_plan_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "arm_right.plan_to_grab".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent10(void) {
    BoolType guard = ((((arm_right_) == (_Amigo_idling)) || ((arm_right_) == (_Amigo_moving))) && (((right_grab_exec_) == (_Amigo_starting)) && ((right_grab_exec_object_in_WS_) == (2)))) && ((sup_) == (_Amigo_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_right_plan_to_grab_, TRUE);
    #endif

    if ((arm_right_) == (_Amigo_idling)) {
        arm_right_ = _Amigo_planning_to_grab;
    } else if ((arm_right_) == (_Amigo_moving)) {
        arm_right_ = _Amigo_planning_to_grab;
    }

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_right_plan_to_grab_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "arm_right.replan".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent11(void) {
    BoolType guard = ((((arm_right_) == (_Amigo_moving)) || ((arm_right_) == (_Amigo_grabbing))) && ((requirement_arm_right_) == (_Amigo_X))) && (((arm_right_collision_on_path_) || ((arm_right_plan_viable_) != (1))) && ((sup_) == (_Amigo_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_right_replan_, TRUE);
    #endif

    if ((arm_right_) == (_Amigo_moving)) {
        arm_right_ = _Amigo_replanning;
    } else if ((arm_right_) == (_Amigo_grabbing)) {
        arm_right_ = _Amigo_replanning;
    }

    #if EVENT_OUTPUT
        Amigo_InfoEvent(arm_right_replan_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "base.idle".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent12(void) {
    BoolType guard = (((((base_) == (_Amigo_planning)) && ((base_plan_viable_) == (2))) || (((base_) == (_Amigo_moving)) && ((base_goal_reached_) || ((base_moving_base_) != (TRUE))))) && ((SafeBaseMovement_) == (_Amigo_X))) && ((((base_plan_viable_) == (2)) || ((base_goal_reached_) || (((base_) == (_Amigo_moving)) && ((base_moving_base_) == (FALSE))))) && ((sup_) == (_Amigo_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(base_idle_, TRUE);
    #endif

    if (((base_) == (_Amigo_planning)) && ((base_plan_viable_) == (2))) {
        base_ = _Amigo_idling;
    } else if (((base_) == (_Amigo_moving)) && ((base_goal_reached_) || ((base_moving_base_) != (TRUE)))) {
        base_ = _Amigo_idling;
    }

    #if EVENT_OUTPUT
        Amigo_InfoEvent(base_idle_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "base.move".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent13(void) {
    BoolType guard = (((base_) == (_Amigo_planning)) && (((SafeBaseMovement_) == (_Amigo_X)) && ((base_plan_viable_) == (1)))) && ((!(base_collision_on_path_)) && ((sup_) == (_Amigo_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(base_move_, TRUE);
    #endif

    base_ = _Amigo_moving;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(base_move_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "base.plan".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent14(void) {
    BoolType guard = ((((base_) == (_Amigo_idling)) || (((base_) == (_Amigo_moving)) && ((base_plan_viable_) != (1)))) && (((navigation_skill_) == (_Amigo_moving_to)) && ((SafeBaseMovement_) == (_Amigo_X)))) && (((base_collision_on_path_) || ((base_plan_viable_) != (1))) && ((sup_) == (_Amigo_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(base_plan_, TRUE);
    #endif

    if ((base_) == (_Amigo_idling)) {
        base_ = _Amigo_planning;
    } else if (((base_) == (_Amigo_moving)) && ((base_plan_viable_) != (1))) {
        base_ = _Amigo_planning;
    }
    navigation_skill_ = _Amigo_idle;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(base_plan_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "goto_phase2".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent15(void) {
    BoolType guard = ((sup_) == (_Amigo_X)) && (((task_) == (_Amigo_wait)) && ((task_object_grabbed_) == (TRUE)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(goto_phase2_, TRUE);
    #endif

    task_ = _Amigo_phase2;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(goto_phase2_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "grab_skill.determine_grab_arm".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent16(void) {
    BoolType guard = (((grab_skill_) == (_Amigo_grabbing)) && ((grab_skill_use_arm_) == (0))) && ((sup_) == (_Amigo_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(grab_skill_determine_grab_arm_, TRUE);
    #endif

    #if EVENT_OUTPUT
        Amigo_InfoEvent(grab_skill_determine_grab_arm_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "grab_skill.grab".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent17(void) {
    BoolType guard = (((grab_skill_) == (_Amigo_idling)) && ((sup_) == (_Amigo_X))) && (((task_) == (_Amigo_phase1)) && ((task_grabbing_) == (FALSE)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(grab_skill_grab_, TRUE);
    #endif

    grab_skill_ = _Amigo_grabbing;
    task_grabbing_ = TRUE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(grab_skill_grab_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "left_grab_exec.check_in_WS".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent18(void) {
    BoolType guard = (((left_grab_exec_) == (_Amigo_starting)) && ((left_grab_exec_object_in_WS_) == (0))) && ((sup_) == (_Amigo_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(left_grab_exec_check_in_WS_, TRUE);
    #endif

    #if EVENT_OUTPUT
        Amigo_InfoEvent(left_grab_exec_check_in_WS_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "left_grab_exec.complete".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent19(void) {
    BoolType guard = (((left_grab_exec_) == (_Amigo_starting)) && (arm_left_object_in_arm_)) && ((sup_) == (_Amigo_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(left_grab_exec_complete_, TRUE);
    #endif

    left_grab_exec_ = _Amigo_completing;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(left_grab_exec_complete_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "left_grab_exec.idle".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent20(void) {
    BoolType guard = ((left_grab_exec_) == (_Amigo_completing)) && ((sup_) == (_Amigo_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(left_grab_exec_idle_, TRUE);
    #endif

    left_grab_exec_ = _Amigo_idling;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(left_grab_exec_idle_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "left_grab_exec.start".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent21(void) {
    BoolType guard = ((((grab_skill_) == (_Amigo_grabbing)) && ((grab_skill_use_arm_) == (1))) && ((left_grab_exec_) == (_Amigo_idling))) && ((sup_) == (_Amigo_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(left_grab_exec_start_, TRUE);
    #endif

    grab_skill_ = _Amigo_idling;
    left_grab_exec_ = _Amigo_starting;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(left_grab_exec_start_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "navigation_skill.move_to".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent22(void) {
    BoolType guard = (((navigation_skill_) == (_Amigo_idle)) && ((sup_) == (_Amigo_X))) && ((((task_) == (_Amigo_phase1)) && ((task_navigating_) == (FALSE))) || ((task_) == (_Amigo_phase2)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(navigation_skill_move_to_, TRUE);
    #endif

    navigation_skill_ = _Amigo_moving_to;
    if (((task_) == (_Amigo_phase1)) && ((task_navigating_) == (FALSE))) {
        task_navigating_ = TRUE;
    } else if ((task_) == (_Amigo_phase2)) {
        task_ = _Amigo_phase2;
    }

    #if EVENT_OUTPUT
        Amigo_InfoEvent(navigation_skill_move_to_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "right_grab_exec.check_in_WS".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent23(void) {
    BoolType guard = (((right_grab_exec_) == (_Amigo_starting)) && ((right_grab_exec_object_in_WS_) == (0))) && ((sup_) == (_Amigo_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(right_grab_exec_check_in_WS_, TRUE);
    #endif

    #if EVENT_OUTPUT
        Amigo_InfoEvent(right_grab_exec_check_in_WS_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "right_grab_exec.complete".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent24(void) {
    BoolType guard = (((right_grab_exec_) == (_Amigo_starting)) && (arm_right_object_in_arm_)) && ((sup_) == (_Amigo_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(right_grab_exec_complete_, TRUE);
    #endif

    right_grab_exec_ = _Amigo_completing;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(right_grab_exec_complete_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "right_grab_exec.idle".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent25(void) {
    BoolType guard = ((right_grab_exec_) == (_Amigo_completing)) && ((sup_) == (_Amigo_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(right_grab_exec_idle_, TRUE);
    #endif

    right_grab_exec_ = _Amigo_idling;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(right_grab_exec_idle_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "right_grab_exec.start".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent26(void) {
    BoolType guard = ((((grab_skill_) == (_Amigo_grabbing)) && ((grab_skill_use_arm_) == (2))) && ((right_grab_exec_) == (_Amigo_idling))) && ((sup_) == (_Amigo_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(right_grab_exec_start_, TRUE);
    #endif

    grab_skill_ = _Amigo_idling;
    right_grab_exec_ = _Amigo_starting;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(right_grab_exec_start_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "task.waiting".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent27(void) {
    BoolType guard = ((sup_) == (_Amigo_X)) && (((task_) == (_Amigo_phase1)) && (((task_navigating_) == (TRUE)) && ((task_grabbing_) == (TRUE))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(task_waiting_, TRUE);
    #endif

    task_ = _Amigo_wait;

    #if EVENT_OUTPUT
        Amigo_InfoEvent(task_waiting_, FALSE);
    #endif
    return TRUE;
}

/**
 * Normalize and check the new value of a continuous variable after an update.
 * @param new_value Unnormalized new value of the continuous variable.
 * @param var_name Name of the continuous variabl ein the CIF model.
 * @return The normalized new value of the continuous variable.
 */
static inline RealType UpdateContValue(RealType new_value, const char *var_name) {
    if (isfinite(new_value)) {
        return (new_value == -0.0) ? 0.0 : new_value;
    }

    const char *err_type;
    if (isnan(new_value)) {
        err_type = "NaN";
    } else if (new_value > 0) {
        err_type = "+inf";
    } else {
        err_type = "-inf";
    }
    fprintf(stderr, "Continuous variable \"%s\" has become %s.\n", var_name, err_type);

#ifdef KEEP_RUNNING
    return 0.0;
#else
    exit(1);
#endif
}

/** Repeatedly perform discrete event steps, until no progress can be made any more. */
static void PerformEvents(void) {
    int count = 0;
    for (;;) {
        count++;
        if (count > MAX_NUM_EVENTS) { /* 'Infinite' loop detection. */
            fprintf(stderr, "Warning: Quitting after performing %d events, infinite loop?\n", count);
            break;
        }

        if (execEvent0()) continue;  /* (Try to) perform event "arm_left.grab". */
        if (execEvent1()) continue;  /* (Try to) perform event "arm_left.idle". */
        if (execEvent2()) continue;  /* (Try to) perform event "arm_left.move". */
        if (execEvent3()) continue;  /* (Try to) perform event "arm_left.plan". */
        if (execEvent4()) continue;  /* (Try to) perform event "arm_left.plan_to_grab". */
        if (execEvent5()) continue;  /* (Try to) perform event "arm_left.replan". */
        if (execEvent6()) continue;  /* (Try to) perform event "arm_right.grab". */
        if (execEvent7()) continue;  /* (Try to) perform event "arm_right.idle". */
        if (execEvent8()) continue;  /* (Try to) perform event "arm_right.move". */
        if (execEvent9()) continue;  /* (Try to) perform event "arm_right.plan". */
        if (execEvent10()) continue;  /* (Try to) perform event "arm_right.plan_to_grab". */
        if (execEvent11()) continue;  /* (Try to) perform event "arm_right.replan". */
        if (execEvent12()) continue;  /* (Try to) perform event "base.idle". */
        if (execEvent13()) continue;  /* (Try to) perform event "base.move". */
        if (execEvent14()) continue;  /* (Try to) perform event "base.plan". */
        if (execEvent15()) continue;  /* (Try to) perform event "goto_phase2". */
        if (execEvent16()) continue;  /* (Try to) perform event "grab_skill.determine_grab_arm". */
        if (execEvent17()) continue;  /* (Try to) perform event "grab_skill.grab". */
        if (execEvent18()) continue;  /* (Try to) perform event "left_grab_exec.check_in_WS". */
        if (execEvent19()) continue;  /* (Try to) perform event "left_grab_exec.complete". */
        if (execEvent20()) continue;  /* (Try to) perform event "left_grab_exec.idle". */
        if (execEvent21()) continue;  /* (Try to) perform event "left_grab_exec.start". */
        if (execEvent22()) continue;  /* (Try to) perform event "navigation_skill.move_to". */
        if (execEvent23()) continue;  /* (Try to) perform event "right_grab_exec.check_in_WS". */
        if (execEvent24()) continue;  /* (Try to) perform event "right_grab_exec.complete". */
        if (execEvent25()) continue;  /* (Try to) perform event "right_grab_exec.idle". */
        if (execEvent26()) continue;  /* (Try to) perform event "right_grab_exec.start". */
        if (execEvent27()) continue;  /* (Try to) perform event "task.waiting". */
        break; /* No event fired, done with discrete steps. */
    }
}

/** First model call, initializing, and performing discrete events before the first time step. */
void Amigo_EngineFirstStep(void) {
    InitConstants();

    model_time = 0.0;
    Amigo_AssignInputVariables();
    arm_left_ = _Amigo_idling;
    arm_right_ = _Amigo_idling;
    base_ = _Amigo_idling;
    grab_skill_ = _Amigo_idling;
    left_grab_exec_ = _Amigo_idling;
    navigation_skill_ = _Amigo_idle;
    requirement_arm_left_ = _Amigo_X;
    requirement_arm_right_ = _Amigo_X;
    right_grab_exec_ = _Amigo_idling;
    SafeBaseMovement_ = _Amigo_X;
    sup_ = _Amigo_X;
    task_navigating_ = FALSE;
    task_grabbing_ = FALSE;
    task_ = _Amigo_phase1;

    #if PRINT_OUTPUT
        /* pre-initial and post-initial prints. */
        PrintOutput(EVT_INITIAL_, TRUE);
        PrintOutput(EVT_INITIAL_, FALSE);
    #endif

    PerformEvents();

    #if PRINT_OUTPUT
        /* pre-timestep print. */
        PrintOutput(EVT_DELAY_, TRUE);
    #endif
}

/**
 * Engine takes a time step of length \a delta.
 * @param delta Length of the time step.
 */
void Amigo_EngineTimeStep(double delta) {
    Amigo_AssignInputVariables();

    /* Update continuous variables. */
    if (delta > 0.0) {

        model_time += delta;
    }

    #if PRINT_OUTPUT
        /* post-timestep print. */
        PrintOutput(EVT_DELAY_, FALSE);
    #endif

    PerformEvents();

    #if PRINT_OUTPUT
        /* pre-timestep print. */
        PrintOutput(EVT_DELAY_, TRUE);
    #endif
}


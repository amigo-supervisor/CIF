/* Headers for the Cif to C translation of Amigo.cif
 * Generated file, DO NOT EDIT
 */
typedef _Bool BoolType;
typedef int32_t IntType;
typedef double RealType;

/* Types of the specification.
 * Note that integer ranges are ignored in C.
 */
enum EnumAmigo_ {
    _Amigo_completing,
    _Amigo_grabbing,
    _Amigo_idle,
    _Amigo_idling,
    _Amigo_moving,
    _Amigo_moving_to,
    _Amigo_phase1,
    _Amigo_phase2,
    _Amigo_planning,
    _Amigo_planning_to_grab,
    _Amigo_replanning,
    _Amigo_starting,
    _Amigo_wait,
    _Amigo_X,
};
typedef enum EnumAmigo_ AmigoEnum;

extern const char *enum_names[];
extern int EnumTypePrint(AmigoEnum value, char *dest, int start, int end);


/* Event declarations. */
enum AmigoEventEnum_ {
    EVT_INITIAL_,                   /**< Initial step. */
    EVT_DELAY_,                     /**< Delay step. */
    EVT_TAU_,                       /**< Tau step. */
    goto_phase2_,                   /**< Event goto_phase2. */
    arm_left_idle_,                 /**< Event arm_left_idle. */
    arm_left_move_,                 /**< Event arm_left_move. */
    arm_left_plan_,                 /**< Event arm_left_plan. */
    arm_left_replan_,               /**< Event arm_left_replan. */
    arm_left_plan_to_grab_,         /**< Event arm_left_plan_to_grab. */
    arm_left_grab_,                 /**< Event arm_left_grab. */
    arm_right_idle_,                /**< Event arm_right_idle. */
    arm_right_move_,                /**< Event arm_right_move. */
    arm_right_plan_,                /**< Event arm_right_plan. */
    arm_right_replan_,              /**< Event arm_right_replan. */
    arm_right_plan_to_grab_,        /**< Event arm_right_plan_to_grab. */
    arm_right_grab_,                /**< Event arm_right_grab. */
    base_idle_,                     /**< Event base_idle. */
    base_move_,                     /**< Event base_move. */
    base_plan_,                     /**< Event base_plan. */
    grab_skill_grab_,               /**< Event grab_skill_grab. */
    grab_skill_determine_grab_arm_, /**< Event grab_skill_determine_grab_arm. */
    left_grab_exec_check_in_WS_,    /**< Event left_grab_exec_check_in_WS. */
    left_grab_exec_start_,          /**< Event left_grab_exec_start. */
    left_grab_exec_complete_,       /**< Event left_grab_exec_complete. */
    left_grab_exec_idle_,           /**< Event left_grab_exec_idle. */
    navigation_skill_move_to_,      /**< Event navigation_skill_move_to. */
    right_grab_exec_check_in_WS_,   /**< Event right_grab_exec_check_in_WS. */
    right_grab_exec_start_,         /**< Event right_grab_exec_start. */
    right_grab_exec_complete_,      /**< Event right_grab_exec_complete. */
    right_grab_exec_idle_,          /**< Event right_grab_exec_idle. */
    task_waiting_,                  /**< Event task_waiting. */
};
typedef enum AmigoEventEnum_ Amigo_Event_;

/** Names of all the events. */
extern const char *Amigo_event_names[];

/* Constants. */


/* Input variables. */
extern IntType arm_left_plan_viable_;         /**< Input variable "int[0..2] arm_left.plan_viable". */
extern BoolType arm_left_collision_on_path_;  /**< Input variable "bool arm_left.collision_on_path". */
extern BoolType arm_left_moving_arm_;         /**< Input variable "bool arm_left.moving_arm". */
extern BoolType arm_left_goal_reached_;       /**< Input variable "bool arm_left.goal_reached". */
extern BoolType arm_left_object_in_arm_;      /**< Input variable "bool arm_left.object_in_arm". */
extern IntType arm_right_plan_viable_;        /**< Input variable "int[0..2] arm_right.plan_viable". */
extern BoolType arm_right_collision_on_path_; /**< Input variable "bool arm_right.collision_on_path". */
extern BoolType arm_right_moving_arm_;        /**< Input variable "bool arm_right.moving_arm". */
extern BoolType arm_right_goal_reached_;      /**< Input variable "bool arm_right.goal_reached". */
extern BoolType arm_right_object_in_arm_;     /**< Input variable "bool arm_right.object_in_arm". */
extern IntType base_plan_viable_;             /**< Input variable "int[0..2] base.plan_viable". */
extern BoolType base_collision_on_path_;      /**< Input variable "bool base.collision_on_path". */
extern BoolType base_moving_base_;            /**< Input variable "bool base.moving_base". */
extern BoolType base_goal_reached_;           /**< Input variable "bool base.goal_reached". */
extern IntType grab_skill_use_arm_;           /**< Input variable "int[0..2] grab_skill.use_arm". */
extern IntType left_grab_exec_object_in_WS_;  /**< Input variable "int[0..2] left_grab_exec.object_in_WS". */
extern IntType right_grab_exec_object_in_WS_; /**< Input variable "int[0..2] right_grab_exec.object_in_WS". */
extern BoolType task_object_grabbed_;         /**< Input variable "bool task.object_grabbed". */

// extern void Amigo_AssignInputVariables();

/* Declaration of internal functions. */


/* State variables (use for output only). */
extern RealType model_time; /**< Current model time. */
extern AmigoEnum arm_left_;              /**< Discrete variable "E arm_left". */
extern AmigoEnum arm_right_;             /**< Discrete variable "E arm_right". */
extern AmigoEnum base_;                  /**< Discrete variable "E base". */
extern AmigoEnum grab_skill_;            /**< Discrete variable "E grab_skill". */
extern AmigoEnum left_grab_exec_;        /**< Discrete variable "E left_grab_exec". */
extern AmigoEnum navigation_skill_;      /**< Discrete variable "E navigation_skill". */
extern AmigoEnum requirement_arm_left_;  /**< Discrete variable "E requirement_arm_left". */
extern AmigoEnum requirement_arm_right_; /**< Discrete variable "E requirement_arm_right". */
extern AmigoEnum right_grab_exec_;       /**< Discrete variable "E right_grab_exec". */
extern AmigoEnum SafeBaseMovement_;      /**< Discrete variable "E SafeBaseMovement". */
extern AmigoEnum sup_;                   /**< Discrete variable "E sup". */
extern BoolType task_navigating_;        /**< Discrete variable "bool task.navigating". */
extern BoolType task_grabbing_;          /**< Discrete variable "bool task.grabbing". */
extern AmigoEnum task_;                  /**< Discrete variable "E task". */

/* Algebraic and derivative functions (use for output only). */






/* Code entry points. */
void Amigo_EngineFirstStep(void);
void Amigo_EngineTimeStep(double delta);

// #if EVENT_OUTPUT
// /**
//  * External callback function reporting about the execution of an event.
//  * @param event Event veing executed.
//  * @param pre If \c TRUE, event is about to be executed. If \c FALSE, event has been executed.
//  * @note Function must be implemented externally.
//  */
// extern void Amigo_InfoEvent(Amigo_Event_ event, BoolType pre);
// #endif

// #if PRINT_OUTPUT
// /**
//  * External callback function to output the given text-line to the given filename.
//  * @param text Text to print (does not have a EOL character).
//  * @param fname Name of the file to print to.
//  */
// extern void Amigo_PrintOutput(const char *text, const char *fname);
// #endif

// #endif


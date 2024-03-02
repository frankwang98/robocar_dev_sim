########################################
# CONSTANTS 常量
########################################
# Bumper states (states are combined, when multiple bumpers are pressed)
uint8 BUMPER_FORWARD  = 1
uint8 BUMPER_BACKWARD = 2

# Cliff sensor states (states are combined, when multiple cliff sensors are triggered)
uint8 CLIFF = 1

# Sonar sensor states (states are combined, when multiple sonar sensors are triggered)
uint8 SONAR = 1

# Illumination sensor (states are combined, when multiple illumination sensors are triggered) 
uint8 ILLUMINATION = 1

# Button states (states are combined, when multiple buttons are pressed)
uint8 BUTTON0 = 1
uint8 BUTTON1 = 2

# Motor errors
uint8 ERROR_LEFT_MOTOR  = 1
uint8 ERROR_RIGHT_MOTOR = 2

# Motor torque 电机力矩
uint8 TORQUE_ON  = 1
uint8 TORQUE_OFF = 2

########################################
# Messages 消息
########################################
Header  header
uint8   bumper
float32 cliff
float32 sonar
float32 illumination
uint8   led
uint8  button
bool   torque # 力矩
int32  left_encoder    # (-2,147,483,648 ~ 2,147,483,647)
int32  right_encoder   # (-2,147,483,648 ~ 2,147,483,647)
float32  battery # 电量

#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED


#include "stdio.h"
#include "stdlib.h"
#include "sdl.h"
#include "SDL2_gfxPrimitives.h"
#include "formulas.h"
#include "time.h"
#include "wall.h"
#include "math.h"

//Setup
void setup_robot(struct Robot *robot);

//Error/Finish Checking
int robot_off_screen(struct Robot * robot);
int checkRobotHitWall(struct Robot * robot, struct Wall * wall);
int checkRobotHitWalls(struct Robot * robot, struct Wall_collection * head);
int checkRobotReachedEnd(struct Robot * robot, int x, int y, int width, int height);
void robotCrash(struct Robot * robot);
void robotSuccess(struct Robot * robot, int msec);

//Sensor Checking
int checkRobotSensor(int x, int y, int sensorSensitivityLength, struct Wall * wall) ;
int checkRobotSensorFrontRightAllWalls(struct Robot * robot, struct Wall_collection * head);
int checkRobotSensorFrontLeftAllWalls(struct Robot * robot, struct Wall_collection * head);

int checkRobotSensorFrontLeftAllWalls(struct Robot * robot, struct Wall_collection * head); //added
int checkRobotSensorFrontLeftAllWalls(struct Robot * robot, struct Wall_collection * head); //added

//Visual Display
void robotUpdate(struct SDL_Renderer * renderer, struct Robot * robot);

//Movement
void robotMotorMove(struct Robot * robot);
void robotAutoMotorMove(struct Robot * robot, int front_left_sensor, int front_right_sensor, int right_front_sensor, int right_back_sensor);
//void robotAutoMotorMove(struct Robot * robot, int front_left_sensor, int front_right_sensor, int side_left_sensor, int side_right_sensor); //added

#endif // ROBOT_H_INCLUDED
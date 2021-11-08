#include "stdio.h"
#include "stdlib.h"
#include "sdl.h"
#include "SDL2_gfxPrimitives.h"
#include "time.h"

#include "formulas.h"
#include "wall.h"
#include "robot.h"

int done = 0;


int main(int argc, char *argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        return 1;
    }

    window = SDL_CreateWindow("Robot Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, OVERALL_WINDOW_WIDTH, OVERALL_WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    window = SDL_CreateWindow("Robot Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, OVERALL_WINDOW_WIDTH, OVERALL_WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, 0);

    struct Robot robot;
    struct Wall_collection *head = NULL;
    int front_left_sensor, front_right_sensor, right_front_sensor, right_back_sensor=0;
    clock_t start_time, end_time;
    int msec;
    int i;

   //MAZE 1

 /*  insertAndSetFirstWall(&head,1,0,0,550,10); //top
    insertAndSetFirstWall(&head,2,0,0,10,1000); //left
    insertAndSetFirstWall(&head,3,630,0,10,1000); //right
    insertAndSetFirstWall(&head,4,0,470,1000,10); //bottom


    i = 0;

    while (i < 50)
    {
        insertAndSetFirstWall(&head,5,300-i,150+i, 5, 5); //TOP V
        insertAndSetFirstWall(&head,5,300+i,150+i, 5, 5);


        insertAndSetFirstWall(&head,5,300-i,300-i, 5, 5); //BOTTOM V
        insertAndSetFirstWall(&head,5,300+i,300-i, 5, 5);


        i = i + 1;
    }

    i = 0;

    while (i < 70)
    {
        insertAndSetFirstWall(&head,5,120+i,220-i, 5, 5); //left side V
        insertAndSetFirstWall(&head,5,120+i,220+i, 5, 5);

        insertAndSetFirstWall(&head,5,480-i,220-i, 5, 5); //right side V
        insertAndSetFirstWall(&head,5,480-i,220+i, 5, 5);

        i = i + 1;
    }

    i = 0;

    while (i < 70)
    {
        insertAndSetFirstWall(&head,5,300-i,35+i,5,5); //OUTER TOP V
        insertAndSetFirstWall(&head,5,300+i,35+i,5,5);


       insertAndSetFirstWall(&head,5,300-i,400-i, 5,5); //OUTER BOTTOM V
       insertAndSetFirstWall(&head,5,300+i,400-i, 5,5);


        i = i + 1;
    }


        i = 0;

    while (i < 100)
    {
        insertAndSetFirstWall(&head,5,30+i,220-i, 5, 5); //OUTER left side V
        insertAndSetFirstWall(&head,5,30+i,220+i, 5, 5);

        insertAndSetFirstWall(&head,5,580-i,220-i, 5, 5); //OUTER right side V
        insertAndSetFirstWall(&head,5,580-i,220+i, 5, 5);

        i = i + 1;
    }


   //MAZE 2

   // border

                insertAndSetFirstWall(&head,1,0,0,550,10); //top
                insertAndSetFirstWall(&head,2,0,0,10,1000); //left
                insertAndSetFirstWall(&head,3,630,0,10,1000); //right
                insertAndSetFirstWall(&head,4,0,470,1000,10); //bottom

                // top row


                insertAndSetFirstWall(&head,5,50,50, 40, 40);
                insertAndSetFirstWall(&head,6,150,50, 40, 40);
                insertAndSetFirstWall(&head,7,250,50, 40, 40);
                insertAndSetFirstWall(&head,8,350,50, 40, 40);
                insertAndSetFirstWall(&head,9,450,50, 40, 40);
                insertAndSetFirstWall(&head,10,550,50, 40, 40);


                // 2nd row


                insertAndSetFirstWall(&head,5,50,150, 40, 40);
                insertAndSetFirstWall(&head,6,150,150, 40, 40);
                insertAndSetFirstWall(&head,7,250,150, 40, 40);
                insertAndSetFirstWall(&head,8,350,150, 40, 40);
                insertAndSetFirstWall(&head,9,450,150, 40, 40);
                insertAndSetFirstWall(&head,9,550,150, 40, 40);

                // 3rd row

                insertAndSetFirstWall(&head,5,50,250, 40, 40);
                insertAndSetFirstWall(&head,6,150,250, 40, 40);
                insertAndSetFirstWall(&head,7,250,250, 40, 40);
                insertAndSetFirstWall(&head,8,350,250, 40, 40);
                insertAndSetFirstWall(&head,9,450,250, 40, 40);
                insertAndSetFirstWall(&head,9,550,250, 40, 40);

                // 4th row

                insertAndSetFirstWall(&head,5,50,350, 40, 40);
                insertAndSetFirstWall(&head,6,150,350, 40, 40);
                insertAndSetFirstWall(&head,7,250,350, 40, 40);
                insertAndSetFirstWall(&head,8,350,350, 40, 40);
                insertAndSetFirstWall(&head,9,450,350, 40, 40);
                insertAndSetFirstWall(&head,9,550,350, 40, 40);

                // last row

                insertAndSetFirstWall(&head,5,50,450, 40, 40);
                insertAndSetFirstWall(&head,6,150,450, 40, 40);
                insertAndSetFirstWall(&head,7,250,450, 40, 40);
                insertAndSetFirstWall(&head,8,350,450, 40, 40);
                insertAndSetFirstWall(&head,9,450,450, 40, 40);
                insertAndSetFirstWall(&head,9,550,450, 40, 40); */



   //MAZE 3

    // Borders

    insertAndSetFirstWall(&head,1,0,0,650,10); //top
    insertAndSetFirstWall(&head,2,0,0,10,1000); //left
    insertAndSetFirstWall(&head,3,630,75,12,1000); //right
    insertAndSetFirstWall(&head,4,0,470,1000,10); //bottom


    insertAndSetFirstWall(&head,1,100,0,5,260);
    insertAndSetFirstWall(&head,1,0,100,50,5);
    insertAndSetFirstWall(&head,1,100,150,260,5);
    insertAndSetFirstWall(&head,1,45,100,5,300);
    insertAndSetFirstWall(&head,1,195,250,5,350);
    insertAndSetFirstWall(&head,1,360,150,5,100);
    insertAndSetFirstWall(&head,1,280,250,150,5);
    insertAndSetFirstWall(&head,1,525,245,150,5);


    i = 0;

    while (i < 75){
        insertAndSetFirstWall(&head,1,45+i,400-i,5,5);

        insertAndSetFirstWall(&head,1,195+i,250+i,5,5);

        insertAndSetFirstWall(&head,1,280+i,250+i,5,5);
        insertAndSetFirstWall(&head,1,355+i,325-i,5,5);

        insertAndSetFirstWall(&head,1,300+i,470-i,5,5);
        insertAndSetFirstWall(&head,1,375+i,395-i,5,5);
        insertAndSetFirstWall(&head,1,450+i,320-i,5,5);

        insertAndSetFirstWall(&head,1,280+i,0+i,5,5);
        insertAndSetFirstWall(&head,1,355+i,75-i,5,5);

        insertAndSetFirstWall(&head,1,550+i,150-i,5,5);
        insertAndSetFirstWall(&head,1,550+i,150+i,5,5);

        i = i + 1;

    }


    setup_robot(&robot);
    updateAllWalls(head, renderer);

    SDL_Event event;
    while(!done){
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_RenderClear(renderer);

        //Move robot based on user input commands/auto commands
        if (robot.auto_mode == 1)

            robotAutoMotorMove(&robot, front_left_sensor, front_right_sensor, right_front_sensor, right_back_sensor);
        robotMotorMove(&robot);

        //Check if robot reaches endpoint. and check sensor values

        //MAZE 1

        /*if (checkRobotReachedEnd(&robot, 550, 0, 550,10)){

        //MAZE 2

        if (checkRobotReachedEnd(&robot, 550, 0, 550,10)){  */

        //MAZE 3

        if (checkRobotReachedEnd(&robot, 640, 10, 10, 100)){

            end_time = clock();
            msec = (end_time-start_time) * 1000 / CLOCKS_PER_SEC;
            robotSuccess(&robot, msec);
        }
        else if(checkRobotHitWalls(&robot, head))
            robotCrash(&robot);
        //Otherwise compute sensor information
        else {
            front_left_sensor = checkRobotSensorFrontLeftAllWalls(&robot, head);
            if (front_left_sensor>0)
                printf("Getting close on the front-left. Score = %d\n", front_left_sensor);

            front_right_sensor = checkRobotSensorFrontRightAllWalls(&robot, head);
            if (front_right_sensor>0)
                printf("Getting close on the front-right. Score = %d\n", front_right_sensor);

            // right
            right_front_sensor = checkRobotSensorRightFrontAllWalls(&robot, head);
            if (right_front_sensor>0)
                printf("Getting close on the right-front. Score = %d\n", right_front_sensor);

            right_back_sensor = checkRobotSensorRightBackAllWalls(&robot, head);
            if (right_back_sensor>0)
                printf("Getting close on the right-back. Score = %d\n", right_back_sensor);
        }
        robotUpdate(renderer, &robot);
        updateAllWalls(head, renderer);

        // Check for user input
        SDL_RenderPresent(renderer);
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                done = 1;
            }
            const Uint8 *state = SDL_GetKeyboardState(NULL);
            if(state[SDL_SCANCODE_UP] && robot.direction != DOWN){
                robot.direction = UP;
            }
            if(state[SDL_SCANCODE_DOWN] && robot.direction != UP){
                robot.direction = DOWN;
            }
            if(state[SDL_SCANCODE_LEFT] && robot.direction != RIGHT){
                robot.direction = LEFT;
            }
            if(state[SDL_SCANCODE_RIGHT] && robot.direction != LEFT){
                robot.direction = RIGHT;
            }
            if(state[SDL_SCANCODE_SPACE]){
                setup_robot(&robot);
            }
            if(state[SDL_SCANCODE_RETURN]){
                robot.auto_mode = 1;
                start_time = clock();

                }
        }

        SDL_Delay(120);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    printf("DEAD\n");
}






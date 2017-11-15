/* 
 * File:   main.c
 * Author: aifrsantos12
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "colors.h"
#include <math.h> // needed to make some mathematical calculations
#include <time.h> // clock access (Allows to generate ramdom numbers)

/*
 * 
 */



/*
 TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO 
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO 
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO 
 * 
 * MAKE THE GAME MODE TO WORK; CANT RETURN THE VALUE OF THE BOOLS
 
 */

#define gravity 9.8 // Default value of gravity in a realistic environment

int getImpact(double angle, int speed, double impact){
    
    impact = ( (speed * speed) / gravity ) * (sin( 2 * angle));
    
    return impact;
}

int getDistance(){
    int distance;
    srand(time(NULL));
    while(distance<100){
        distance = rand() % 200;
        //TODO : Random numbers both up and down
    }
    return distance;
    
}

int getGameMode(bool easy,bool hard,bool pvp){
    /* Ask the player what level of difficulty they want to play against(CPU)
       Or if you play against another player (PVP) */
    
    int mode;
        printf("What is the level of difficulty? ?\n");
        printf("[1] Easy Mode\n");
        printf("[2] Hard Mode\n");
        printf("[3] Player vs Player\n");
        
    scanf("%d", &mode);
    switch (mode) {
            case 1: 
                printf("Game Mode: " CGREEN "Easy" CNORMAL);
                bool easy = true;
                break;
            case 2: 
                printf("Game Mode: " CRED"Hard" CNORMAL); 
                bool hard = true;
                break;
            case 3:
                printf("Game Mode: " CBLUE "PVP" CNORMAL); 
                bool pvp = true;
                break;
            default:
                printf("Default Mode: " CGREEN "Easy" CNORMAL);
                 /* Default mode is the easy mode. */
                
                /* TODO: Review the default because of boolean */
        }
    
    // TODO: Define the easy and hard parameters of the game modes
}


int getBlast(){
    /* Ask the player which type of missile they want to use
       and returns the zone of impact of the explosion */
    
    int zone;
    
        printf("\n----------------------------------\n");
        printf("What type of " CRED"missile " CNORMAL "you want to use?\n" CNORMAL);
        printf("[1] Fire Missile\n");
        printf("[2] Super Missile\n");
        printf("[3] Nuclear Missile\n");
        
        //TODO: Credits or values change
        
    scanf("%d", &zone);
    switch(zone) {
            case 1:
                printf("Missile: " CRED"Fire Missile\n" CNORMAL); 
                return 5;
            case 2:
                printf("Missile: " CRED"Super Missile\n" CNORMAL); 
                return 10;
            case 3:
                printf("Missile: " CRED"Nuclear Missile\n" CNORMAL); 
                return 15;
            default:
                printf("Missile: " CRED"Fire Missile\n" CNORMAL); 
                return 5; // The Missile Fire is chosen by default
    }
}

int easyMode(){
    printf("1");
}

int hardMode(){
    printf("2");
}

int pvpMode(){
    printf("3");
}

int Game(int distance, int blast_zone, bool easy, bool hard, bool pvp){
    /* Main game code
       If the player wins, returns 1 and adds victory to the score
       If the player loses, returns 0 and does not add victory. */
    
        double angle; // angle of the shot
        int speed; // speed of the shot
        double shot_distance; // distance tracked to inform player
        double impact = 0; // Zone of final impact of the missile - Calculated by the formula getImpact
        
        
            
        
        
            printf("Enter a Projection Angle: ");
            scanf("%lf", &angle);
            
            
            angle = (angle * M_PI) / 180; /* Converts degrees to radians to calculate the impact zoma
                                          *  Need to convert because the math.h library works in radians */
            
            
            printf("Enter the projection speed: ");
            scanf("%d", &speed);
            
            impact = getImpact(angle, speed, impact);
            
            printf("Your shot hit the %.lf Kms of ur position\n", impact);
        
            
            if(distance >= impact && distance <= impact+blast_zone || distance <= impact && distance >= impact-blast_zone)
            {
                printf("Win");
                return 1;
            }
            else
            {
                printf("Miss!");
                return 0;
            }
        
            
            if(easy == true){
                printf("CPU Easy turn");
            }
            else if(hard == true ){
                printf("CPU Hard turn");
            }
            else if (pvp == true){
                printf("Other player turn");
            }
        
        // TODO: Another cycle to return 0 (if player does not hit, try again) - when trying
        // again add the number of attempts
        // ALSO MAKE THE ACCOUNTS ACCOUNTING THE EXPLOSION AREA
        
}


int main() {
    bool counter = true; // Counter of victories (While true continues to play)
    int gamemode;
    int distance; // Distance from player to enemy
    int blast_zone; // Area of ​​explosion damage
    int round = 0; // Total games played
    int wins = 0;
    int impact;
    char y; // Validation of the player on whether he wants to continue playing or not
    bool easy = false;
    bool hard = false;
    bool pvp = false;

        printf(CGREEN "TANK WARS" CNORMAL " - WELCOME!""\n");

        gamemode = getGameMode(easy, hard, pvp);

        
        /* Main cycle of the game. Will continue until the player cancel */
        do {
            blast_zone = getBlast();
            // Generates a random distance between 100 and 200 meters.
            distance = getDistance();
            printf("*******************************************\n");
            printf(CNORMAL "The enemy is at" CBLUE " %d" CNORMAL " Kms\n" CNORMAL, distance);
            printf("*******************************************\n");

            wins = wins + Game(distance, blast_zone, easy, hard, pvp); /* If the player wins, a victory is added */
            printf("%d",wins);
            round = round + 1;

            
            printf(" Do you want to play again? (y/n)\n");
            scanf(" %c", &y);
            
            if (y == 'n'){
                counter = false;
            }
            else if (y == 'y'){
                
            }
            else{
                printf("ERROR! NO OPTION");
            }
        
        
        } while (counter == true);
         
         
         
         
         
    return 0;
}


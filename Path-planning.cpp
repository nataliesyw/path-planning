//
//  Assignment 2 Task 2 template
//  Copyright © 2019 HKU ENGG1340. All rights reserved.
//


#include <iostream>

using namespace std;

const int MAX_SIZE = 1000;


///////// DO NOT MODIFY ANYTHING ABOVE THIS LINE /////////

// IMPORTANT:  Do NOT change any of the function headers already provided to you
//             It means that you will need to use the function headers as is


// You may implement additional functions here



// Function: find the smallest number of steps to go from the starting point
//           to the destination in a given map.
//
// Input: int map[][]: 2D-array map
//        int map_h: the height of the map
//        int map_w: the width of the map
// Output: return true if a path is found, and store the smallest number of
//                      steps taken in &num_steps (pass-by-reference)
//         return false if there is no path
// ==============================================================
bool FindPath(int map[][MAX_SIZE], int map_h, int map_w, int &num_steps)
{

    bool reach_end = false; // a boolean flag to check if finishing point is reached
    bool can_update = true; // a boolean flag to check if there is 0
    int steps = 1;  // declare the step starting from 1


    while (! reach_end && can_update){
      can_update = false;
      // for loop thats loop through every point on the map
      for (int i = 0; i < map_h; i++){
        for (int j = 0; j < map_w; j++){
          // locate the current step
          if (map[i][j] == steps){
            if(i-1 >= 0){  // index of min row must be greater or equal to one
              if(map[i-1][j] == -2){
                reach_end = true;
              }
              if(map[i-1][j] == 0){
                map[i-1][j] = steps + 1; // add the steps
                can_update = true; // continue to update
              }
            }
            if (j+1 < map_w){ // index of max col must be smaller than the width
              if (map[i][j+1] == -2){
                reach_end = true;
              }
              if (map[i][j+1] == 0){
                map[i][j+1] = steps + 1;
                can_update = true;  // continue to update
              }
            }
            if (i + 1 < map_h ){
              if (map[i+1][j] == -2){
                reach_end = true; // reach the finishing point
              }
              if (map[i+1][j] == 0){
                map[i+1][j] = steps + 1;
                can_update = true;  // continue to update
              }
            }
            if ( j-1 >= 0 ){
              if (map[i][j-1] == -2){
                reach_end = true; // reach the finishing point
              }
              if (map[i][j-1] == 0){
                map[i][j-1] = steps + 1;
                can_update = true;  // continue to update
              }
            }
          }
        }
      }
      steps++;
    }

    if (reach_end){
      num_steps = steps - 1;
      return true;
    }
    else{
      return false;
    }
}


///////// DO NOT MODIFY ANYTHING BELOW THIS LINE /////////

// Function: main function
// ==============================================================
int main()
{
  int map_h;
  int map_w;
  cin >> map_h >> map_w;

  int map[MAX_SIZE][MAX_SIZE];

  // initialize map
  for (int i=0; i<MAX_SIZE; i++)
    for (int j=0; j<MAX_SIZE; j++)
      map[i][j] = -1;

  // read map from standard input
  for (int i=0; i<map_h; i++)
    for (int j=0; j<map_w; j++)
      cin >> map[i][j];

  int steps;
  // print to screen number of steps if a path is found, otherwise print "No"
  if (FindPath(map, map_h, map_w, steps))
    cout << steps << endl;
  else
    cout << "No" << endl;

}

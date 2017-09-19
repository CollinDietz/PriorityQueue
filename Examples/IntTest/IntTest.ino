#include<PriorityQueue.h>

/*
 * Author: Collin Dietz
 * Date: 9/19/2017
 * Desc: 
 * A simple example of the PriorityQueue library
 * Pushes 10 out of order ints into a PriorityQueue and then
 * empties the queue to show the sorting based on the compare function
 */

 #define LENGTH (10)

/*
 * boolean function passed to the priotity queue to sort ints in increasing order
 */
bool compare(int a, int b)
{
  return a < b;
}

PriorityQueue<int> queue = PriorityQueue<int>(compare); //priority queue for ints sorted on compare function

void setup() {
    Serial.begin(9600);
    while(!Serial);

    //numbers to be pushed into the queue
    int list[] = {0, 9, 5, 2, 4, 3, 1, 8, 7, 6};
    Serial.println("Pushing the following list into the queue (in sequence)");
    
    for(int i = 0; i < LENGTH; i++)
    {
      Serial.print(list[i]);
      if(i != LENGTH-1)
      {
        Serial.print(", ");
      }
      //push the numbers into the list
      queue.push(list[i]);
    }
    
    Serial.println();
    Serial.println("Emptying the queue");

    //until the queue is empty...
    while(!queue.isEmpty())
    {
      //pop out and print the highest priority item
      Serial.print(queue.pop());
      Serial.print(", ");
    }
    
}

void loop() {
  //run loop code
}

#include<PriorityQueue.h>

/*
 * Author: Collin Dietz
 * Date: 12/20/2017
 * Desc: 
 * A simple example of the PriorityQueue library
 * Pushes 10 out of order chars into a PriorityQueue and then
 * empties the queue to show the sorting based two functions
 * The first uses simple ASCII values to sort
 * The second sorts so that all letters are alphabetic with Uppercase before lower
 * case of same character
 * 
 * i.e. compare1 produces
 * {A,B....Z,a,b,...z}
 * compare 2 produces
 * {A,a,B,b,C,c,..Z,z}
 */

#define LENGTH (10)

bool compare1(char a, char b) //sort by ASCII value
{
  return a < b;
}

bool compare2(char a, char b) //sort alphabetically, upper before lower for same character
{
  bool isAlw=false, isBlw=false; //flags to remmber if a or b is lowercase
  //normalize
  if(a >= 97 && a <= 122)
  {
    isAlw = true;
    a -= 'a'-'A';
  }
  
  if(b >= 97 && b <= 122)
  {
    isBlw = true;
    b -= 'a'-'A';
  }
  //if they are the same char compare cases
  if (a == b)
  {
    //if a is lowercase and b is upper case b has preference
    if( isAlw && !isBlw)
    {
      return false;
    }
    else //every other case a gets preference
    {
      return true;
    }
  }
  else //if they arent the same
  {
    //see which has alphabetic preference
    return a < b;
  }
 
}

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    while(!Serial);

    PriorityQueue<char> queue = PriorityQueue<char>(compare1);
    char list[]={'A', 'C', 'a', 'b', '!', '?', 'k', 'B', 'R', '1'};
    Serial.println("Using comparison one");
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
    Serial.println();
    Serial.println();

    queue = PriorityQueue<char>(compare2);
    Serial.println("Using comparison two");
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
  // put your main code here, to run repeatedly:

}

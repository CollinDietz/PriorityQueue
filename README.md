# Priority Queue for Arduino
A generic (i.e. templated) priority queue for Arduino. Works with arbitrary data types and arbitrary priority schemes. Created by extending a slightly modified version of the popular [QueueList](https://playground.arduino.cc/Code/QueueList) library. 

## Installing
Included with the source files for the priority queue are the files for the modified
[QueueList](https://playground.arduino.cc/Code/QueueList) files in the [QueueList](./QueueList) directory. Simply
move the [QueueList](./QueueList) directory out of the cloned repo and into your Arduino Libraries folder, and then move
the cloned repo into the same libraries folder. This will install both QueueList and PriorityQueue. (The modified
library is only for variable access on inheritance, it behaves exactly like the original)

## Version

- 1.0 - Initial Version


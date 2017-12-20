# Priority Queue for Arduino
A generic (i.e. templated) priority queue for Arduino. Works with arbitrary data types and arbitrary priority schemes. Created by extending a slightly modified version of the popular [QueueList](https://playground.arduino.cc/Code/QueueList) library. 

## Installing
Simply copy the folder of source files to your Arduino/libraries directory.

Note: Included with the source files for this library are the files for the modified
[QueueList](https://playground.arduino.cc/Code/QueueList) class ([Queuelist_Modified.h](./QueueList_Modified.h)), installing this library does
not conflict with a previous installation of the QueueList library. However, the modified library functions just like the
original, and can be accessed by including the [Queuelist_Modified.h](./QueueList_Modified.h) if you don't have the
actual library installed. 

## Version

- 1.1 - Optimized Insert (binary insert)
	- The push function now uses a binary search for the correct position in the queue, reducing calls of the compare
	function from O(n) to O(log(n))
	- fixed bug where size was not tracked correctly
	- added an example showing two ways to organize char's with different priority functions

- 1.0 - Initial Version


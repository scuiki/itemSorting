# itemSorting

  A C application that's similar to a store catalogue. It works through tags, each tag has a prime number associated with it; one item can have multiple tags in it. The logic behind it works thanks to a pretty simple math concept: the result of a multiplication of prime numbers can only return the division remainder equal 0 if it's divided by the same prime numbers used in the multiplication. 
  With the previous paragraph in mind, it's possible to multiply all the tags contained in one item and generate an "item code"; that way, if the user searches for a single tag, all items containing that tag will show up, even if they contain extra tags aswell.

PS.: It's the first version, so there are a few improvements to be made, for instance: Adding a file system for storing the tags created, as well as adding a way to register, mid-program, more tags for the system;

reference for library <stdarg.h> : tutorialspoint.com/cprogramming/c_variable_arguments.htm

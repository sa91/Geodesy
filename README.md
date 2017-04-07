# ProficiencyTest

## Code:
 
   Header File : distance.hpp
  
   Library Code File : distance.cpp

   Test BasicDistance() Function : runBasic.cpp
    
   Test Distance() Function : run.cpp


## Todo:

Test the library/code
 
  @ BasicDistance() ==> More testcase to be addded
  
  @ Distance() ==> More accurate testdata to check the accuracy. 

Add more ways to instantiate point in class Point ==> Pending

write the makefile ==> Done

## Description of each Test 

 1st line : latitude,longitude of first point in degrees;

 2nd line : latitude,longitude of second point in degrees;

## Makefile

make runBasic (to executable "runBasic" for running BasicDistance Fuction)

make run (to executable "run" for running Distance Fuction)

## BasicDistance() Testing ::

Test : TestBasic.in 

Expected outcome : TestBasic.data  (Data is collected from http://www.movable-type.co.uk/scripts/latlong.html (Uses the simple trignometric formula, considering earth to be sphere ));

Output : TestBasic.out (Output in meters )

## Distance() Testing ::

Test : TestBasic.in 

Expected outcome : TestBasic.data  (Data is collected from http://www.movable-type.co.uk/scripts/latlong.html (Uses the simple trignometric formula, considering earth to be sphere ));

Output : TestDistance.out (Output in meters)


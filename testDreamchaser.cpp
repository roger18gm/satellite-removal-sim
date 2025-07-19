/***********************************************************************
 * Source File:
 *    TEST DREAM CHASER
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The unit tests for the ship
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "dreamchaser.h"
#include "testDreamChaser.h"
#include <math.h>

 /*************************************
  * DEFAULT CONSTRUCTOR
  * input: nothing
  * output: position(-450.0, 450.0), velocity(0.0, 0.0), dead(false), angularVelocity(1.0), radius(0.0)
  **************************************/
void TestDreamChaser::defaultConstructor()
{
   // SETUP

   // EXERCISE
   Dreamchaser d;

   // VERIFY
   assertEquals(d.position.x, -450.0 * 40.0);
   assertEquals(d.position.y, 450.0 * 40.0); // x40 because of pixel to meter conversion
   assertEquals(d.velocity.dx, 0.0);
   assertEquals(d.velocity.dy, -2000.0);
   assertEquals(d.dead, false);
   assertEquals(d.angularVelocity, 0.0);
   assertEquals(d.radius, 10.0);
   assertEquals(d.direction.radians, M_PI);

   // TEARDOWN
}

/*********************************************
 * name:    THRUST COMPONENT
 * input:   p(100,100) v(100,100) d(45deg) acceleration(3) t(10)
 * output:  v(121.213, 121.213)
 *********************************************/
void TestDreamChaser::thrust_once()
{
   // SETUP
   Dreamchaser d;
   d.position.x = 100.0;
   d.position.y = 100.0;
   d.velocity.dx = 100.0;
   d.velocity.dy = 100.0;
   d.direction.radians = M_PI_4;
   double magnitude = 3.0;
   double time = 10.0;

   // EXERCISE
   d.thrust(magnitude, time);

   // VERIFY
   assertEquals(d.position.x, 100.0);
   assertEquals(d.position.y, 100.0);
   assertEquals(d.velocity.dx, 121.2132034);    // dx = 100 + (3 * sin(45deg) * 10)
   assertEquals(d.velocity.dy, 121.2132034);    // dy = 100 + (3 * cos(45deg) * 10)
   assertEquals(d.direction.radians, M_PI / 4); // 45 degrees
   assertEquals(magnitude, 3.0);
   assertEquals(time, 10.0);

   // TEARDOWN
}

/*********************************************
 * name:  ROTATE LEFT
 * input: ship direction = M_PI,  -0.5 radians
 * output: direction = M_PI - 0.5
 *********************************************/
void TestDreamChaser::rotate_left()
{
   // SETUP
   Dreamchaser d;
   d.direction.radians = M_PI;
   double radians = -0.5;

   // EXERCISE
   d.rotate(radians);

   // VERIFY
   assertEquals(d.direction.radians, M_PI - 0.5);

   // TEARDOWN
}

/*********************************************
 * name:  ROTATE RIGHT
 * input: ship direction = M_PI,  0.5 radians
 * output: direction = M_PI + 0.5
 *********************************************/
void TestDreamChaser::rotate_right()
{
   // SETUP
   Dreamchaser d;
   d.direction.radians = M_PI;
   double radians = 0.5;

   // EXERCISE
   d.rotate(radians);

   // VERIFY
   assertEquals(d.direction.radians, M_PI + 0.5);

   // TEARDOWN
}

/*********************************************
 * name:    INPUT NOTHING
 * input:   none
 * output:  zero
 *********************************************/
void TestDreamChaser::input_none()
{
   // SETUP
   Dreamchaser d;
   Interface ui; // test dreamchaser is friend of interface class
   ui.isDownPress = 0;
   ui.isLeftPress = 0;
   ui.isRightPress = 0;
   d.position.x = 0.0;
   d.position.y = 0.0;
   d.velocity.dx = 0.0;
   d.velocity.dy = 0.0;
   d.direction.radians = 0.0;

   // EXERCISE
   d.input(&ui);

   // VERIFY
   assertEquals(d.position.x, 0.0);      // did not move
   assertEquals(d.position.y, 0.0);
   assertEquals(d.velocity.dx, 0.0);
   assertEquals(d.velocity.dy, 0.0);
   assertEquals(ui.isDownPress, 0.0);     // nada happens
   assertEquals(ui.isLeftPress, 0.0);
   assertEquals(ui.isRightPress, 0.0);

   // TEARDOWN
}

/*********************************************
 * name:    INPUT DOWN
 * input: downPress(1)
 * output:  downPress(1)
 *********************************************/
void TestDreamChaser::input_downKeyPressed()
{
   // SETUP
   Dreamchaser d;
   Interface ui;
   ui.isDownPress = 1;
   ui.isLeftPress = 0;
   ui.isRightPress = 0;
   d.position.x = 0.0;
   d.position.y = 0.0;
   d.velocity.dx = 0.0;
   d.velocity.dy = 0.0;
   d.direction.radians = 0.0;

   // EXERCISE
   d.input(&ui);

   // VERIFY
   assertEquals(d.position.x, 0.0);
   assertEquals(d.position.y, 0.0);
   assertEquals(d.velocity.dx, 0.0);
   assertEquals(d.velocity.dy, 96.0);        // v.dy = 0.0(dy) + 2.0(ddy) * 48.0(t)
   assertEquals(d.direction.radians, 0.0);
   assertEquals(ui.isDownPress, 1);          // down arrow pressed
   assertEquals(ui.isLeftPress, 0);
   assertEquals(ui.isRightPress, 0);

   // TEARDOWN
   ui.isDownPress = 0.0;
}

/*********************************************
 * name:    SHIP INPUT LEFT
 * input:   v=(0, 0), p=(0,0) d=(0.0) isLeftPress(1)
 * output: d(2PI - 0.1 radians)
 *********************************************/
void TestDreamChaser::input_leftKeyPressed()
{
   // SETUP
   Dreamchaser d;
   Interface ui;
   ui.isDownPress = 0;
   ui.isLeftPress = 1;
   ui.isRightPress = 0;
   d.position.x = 0.0;
   d.position.y = 0.0;
   d.velocity.dx = 0.0;
   d.velocity.dy = 0.0;
   d.direction.radians = 0.0;

   // EXERCISE
   d.input(&ui);

   // VERIFY
   assertEquals(d.position.x, 0.0);
   assertEquals(d.position.y, 0.0);
   assertEquals(d.velocity.dx, 0.0);
   assertEquals(d.velocity.dy, 0.0);
   assertEquals(d.direction.radians, M_PI + M_PI - 0.1); // 2PI - 0.1rad
   assertEquals(ui.isDownPress, 0);
   assertEquals(ui.isLeftPress, 1); // left arrow pressed
   assertEquals(ui.isRightPress, 0);

   // TEARDOWN
   ui.isLeftPress = 0.0;
}

/*********************************************
 * name:    SHIP INPUT RIGHT
 * input:   v=(0, 0), p=(0,0) d=(0.0) isRightPress(1)
 * output:  d=(0.1)
 *********************************************/
void TestDreamChaser::input_rightKeyPressed()
{
   // SETUP
   Dreamchaser d;
   Interface ui;
   ui.isDownPress = 0;
   ui.isLeftPress = 0;
   ui.isRightPress = 1;
   d.position.x = 0.0;
   d.position.y = 0.0;
   d.velocity.dx = 0.0;
   d.velocity.dy = 0.0;
   d.direction.radians = 0.0;

   // EXERCISE
   d.input(&ui);

   // VERIFY
   assertEquals(d.position.x, 0.0);
   assertEquals(d.position.y, 0.0);
   assertEquals(d.velocity.dx, 0.0);
   assertEquals(d.velocity.dy, 0.0);
   assertEquals(d.direction.radians, 0.1); // right rotation
   assertEquals(ui.isDownPress, 0);
   assertEquals(ui.isLeftPress, 0);
   assertEquals(ui.isRightPress, 1); // right arrow pressed

   // TEARDOWN
   ui.isRightPress = 0.0;
}
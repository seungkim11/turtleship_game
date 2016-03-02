Seung Kim
CIN: 303214644

CS550 OpenGL++ Project - Turtle Ship Game
---------------------
Files:
background.h
camera.cpp
camera.h
collision.h
controls.h
enemy.cpp
enemy.h
item.cpp
item.h
Lab-Camera.h
lighting.h
main.cpp
mainHeader.h
material.h
Point3.h
robot.cpp
robot.h
Vector3.h
----------------------
Please have these files in the same folder.
Must include opengl.



Goal of the game: Move a teapot and a donut to Gold table on the opposite side.

===== Game Control Key ======
---- Robot Control ----
Up key : move forward
Down key : move backward
Left key : turn left
Right key : turn right
'a' key : rotate upper arm down
's' key : rotate upper arm up
'z' key : rotate lower arm down
'x' key : rotate lower arm up
'q' key : rotate wrist down
'w' key : rotate wrist up
'd' key : open hand
'f' key : close hand 
Space Bar : attack
SHIFT KEY + mouse : control robot body
CONTROL KEY + mouse : control robot head


---- Camera Control ----- (only works in Camera view mode 1)
'c' key : change camera view
Mouse left click : move camera
Mouse right click : pitch, yaw camera
ALT KEY + Mouse left click : zoom camera
ALT KEY + Mouse right click : roll camera
'y, r, p' : yaw, pitch, roll camera


'esc' key : quit game

======= Game Rules ========
-Robot gets 10 lives.
-Enemies get 3 lives.
-If robot is attacked(enemy gets close to robot), lose life.
-If enemy is attacked by SPACE BAR and is hit by robot's head, enemy loses life.

-Mouth has to be closed, so that an item will be picked up.
-Open mouth will drop items.
-If teapot/donut is dropped, pick it up again.

-Move Teapot and Donut to other table and win the game!!!







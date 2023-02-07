# PIDPlugin_UE5

Adds a "PIDComponent" ActorComponent that can be used in any actor, Blueprint or C++. The PID class itself is written in plain C++ and doesn't contain any complex logic. But it does add a new Node Function to Blueprints, "Calculate". The function takes a few variables (setPoint, processValue, PID coeffs, deltaTime) and outputs a new correction value. The project contains 1 level with example implementations of a cube(both C++ and BP), hovering using AddForce with different P, I, and D constants. 

![Demo2](Demo2.gif)

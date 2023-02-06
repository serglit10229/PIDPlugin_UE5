# PIDPlugin_UE5

Adds a "PIDComponent" ActorComponent that can be used in any actor, Blueprint or C++. The PID class itself is written in plain C++ and doesn't contain any complex logic. But it does add a new Node Function to Blueprints, "Calculate". The function takes a few variables (setPoint, processValue, PID coeffs, deltaTime) and outputs a new correction value. The project contains 1 level with example implementations of a cube(both C++ and BP), hovering using AddForce with different P, I, and D constants. I wanted to publish this plugin on UE4 marketplace a long time ago. However, Epic rejected it because they set the minimum price to $5, and I just wanted it to be open source. I've used this plugin myself in several other projects since then.

![Drag Racing](Demo2.gif)

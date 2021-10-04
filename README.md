# Godot AreaProber 2D
## _Checking for neighbour colliders made easy_



**AreaProber** allows you to probe for colliders anywhere in your 2D game's world, no need to set-up an area2d, nor raycasts!
It's pretty straight forward to use:
- Create a new `AreaProber` object and assign it to a variable
- Add it as a child of the scene (or other object, it does not really matter as far as i can tell)
- Create any `CollisionShape2D`object, i usually like to use `CircleShape2D`
- Set it extents, radius or other delimiting property that the shape may have, in the circle `CircleShape2D` you'll use `.set_radius(radius:float)`
- Assign the shape to `AreaProber` using `.set_collision_shape(shape:Shape2d)`
- Optionally you can also configure the probe
-- For collision mask using `.set_collision_mask(mask:int)`
-- For allowing or denying collisions with bodies and areas you can use `.set_collision_detect_bodies(value:bool)` and `.set_collision_detect_areas(value:bool)` respectively
- After that you just use `.probe(position:Vector2)`, the function will return an empty array if there is no avaliable colliders in the give area and will return an array of arrays if there is, each element of the returning array is an array with a fixed size of 2, the first element is the collider reference and the second is which shape of that given collider was detected.
 

## Note from Strauji
For a while now i've been making VoidStrike: The Online Space Shooter, and one recurring problem i had is that i needed to get the closests bodies to the player ship, or to another given body, until now i used an Area2D as a child of that node and called it a night, but over the time that started to take it's toll on the game performance, so i had to find an way to make this process easier and lighter
I know that this module is very small and is not a gamechanging thing but i'm really happy to have accomplished that, given that i've never coded in C++ for Godot before, and i'm thankful for stumbling upon [quinnvoker's qurobullet](https://github.com/quinnvoker/qurobullet), which i'm using in VoidStrike AND helped me to learn how to make a proper module for Godot.

Hope you enjoy!

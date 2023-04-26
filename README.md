# stingray
Ray Tracer implemented in C and python (seperately just because) following Peter Shirley's ray tracing in one weekend [tutorial](raytraing.github.io)
(PS - it took way more than one weekend 👀)

### Stuff I'm planning on adding 
- Positionable camera in C - version (came up with a messy implementation of the hittable object to model OO behaviour and it'll make this pretty difficult)
- Multithreaded rendering in python - Python is really slow, since each pixel rendered is mostly unaffected by other pixels this could work 
- Switch up PPM rendering for SDL - i'll probably just end up doing this in pygame or something (using sdl directly is a pain)


### Generated 

- Diffuse image with gamma correction
<img src = "https://github.com/abundance-io/stingray/blob/main/Images/diffuse_with_gamma.png?raw=true">

- Bunch of spheres with different materials (metal, lambertian(pretty much plastic))
<img src = "https://github.com/abundance-io/stingray/blob/main/Images/material_class_4_spheres.png?raw=true">

- Added Defocus Blur On the Camera
![image](https://user-images.githubusercontent.com/76886969/234548312-25658105-fcf3-4cd1-83b7-134a98a1224b.png)

- Cover photo of the book (took hours to render 🥲)
<img src = "https://github.com/abundance-io/stingray/blob/main/Images/last_scene_4.png?raw=true">

# Sphere-RayCasting
Sphere 3D-image generation
---
Firstly, I made a choose which graphics library I'd prefer to use. It was SFML because of its simple syntax and well reputation.

Secondly, I tried to drow just a red circle by equation `x^2 + y^2 = r^2` with white ambient light.

And the result was:
![Alt Text](https://github.com/romasheck/Sphere-RayCasting/blob/51914f218247e1ca1487a05135fc8a1e3b285dcd/sources%20for%20git/Screenshot%20from%202022-10-01%2022-34-39.png)


Thirdly, I tried to drow red circle only with white diffusion light.

And the result was:
![Alt Text](https://github.com/romasheck/Sphere-RayCasting/blob/51914f218247e1ca1487a05135fc8a1e3b285dcd/sources%20for%20git/Screenshot%20from%202022-10-01%2022-36-06.png)


Fourthly, I tried to drow red circle only with white specular light.

And the result was:
![Alt Text](https://github.com/romasheck/Sphere-RayCasting/blob/51914f218247e1ca1487a05135fc8a1e3b285dcd/sources%20for%20git/Screenshot%20from%202022-10-01%2022-37-10.png)

Finally, I combined all of this.

And recieved:

![Alt Text](https://github.com/romasheck/Sphere-RayCasting/blob/51914f218247e1ca1487a05135fc8a1e3b285dcd/sources%20for%20git/Screenshot%20from%202022-10-01%2022-38-11.png)

**Not so bad, isn't it?**


About realization.
---

**Using graphics library**

All interactions with SFML are hidden by the libDrow.h. There is needed because somewho can use another library and he won't have to rewrite the whole project - only "libDrow.hpp" and "libDrow.cpp".


**Geometrical part**

"Vector.hpp" and "Geom.hpp" was writen for the work with geometrical abstractions. In the "Vector.hpp" discribed class Vector, which show up common 3 dimensional vector.


**Phisical part**

Ambient light illuminate all object on the scene just because it exists. 

Diffusion illumination depend on place of light source and object. There is general reason why we percieve image volume. Resulted color depend on objects color and light source color. 

Specular illumination also depend on place of ... There is reason of flare existance. Resulted color depend only on light source color.

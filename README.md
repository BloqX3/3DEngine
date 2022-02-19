
# Real Time 3D Engine (beta)

High performance software engine built from the ground up (for education purposes, and fun of course) 


# Features 🔥

- Developer-friendly Api
- Wirefram rendering
- Rasterization rendering (beta)
- .Obj Loader (beta)
- programmable screen object
  - rendering to console screen is used by default (windows)
  - you can handle getPixel, setPixel, etc by inherting from IScreen<T> interface
- camera & object Orientation
- Projections & backface Cutting
- carefully optimized for maximum performance possible
- no memory leaks or expensive memory handeling


# Engine Settings ⚙️

| Setting           | Value          | Reason                                           |
| :----------       | :---------     | :-----                                           |
| `Triangles Order` | Anti-ClockWise | .obj files are anti-clockwise by default         |
| `convention`      | left-Handed    | prespective projection is left-handed by default |
| `object space`| -0.5 -> 0.5 boundry on all dimensions | space side length is 1, translating it to screen space is simple |

# Upcoming Features 🚀
under development:
- Enhanced Rasterization algorithm

- optimized (isClockWise) algorithm

- Enhanced Multi-object rendering

- Dynamic Pipeline functions

- better consoleScreen control

for the Future:

- colorful Vertices support

- textures Support

- lighting

- window Screen support

- customizable Shader unites

- enhanced Objects Loader

- parallel Processing

- cross-Platform Screens




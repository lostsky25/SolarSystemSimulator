# Solar System Simulator

![Sandbox with planets](https://repository-images.githubusercontent.com/221542182/36dee280-066d-11ea-9f2c-c779ebf9b9ca)

It's a Solar System Simulator, in this application you can create planets with defferent properties. This is application uses for demonstration Newton's gravity. 

![formula](https://user-images.githubusercontent.com/57411317/72094461-8bc66e80-3327-11ea-9fe5-0b55ffb4c9ec.PNG)

Available a few opportunities for change:
  * Change background or solid color.
  * Radius of the created planet.
  * Radius of rest planets (visually).
  * Vectors of speed (x0, y0).

![screen1](https://user-images.githubusercontent.com/57411317/72093745-15753c80-3326-11ea-9834-8967cc99c250.png)

Classes descriptions:
## Planet -  The planet is a object, which keeps a few characteristics.
Values are changing with _CHANGE_NAME(param) macros, it's reduced to abstract units. Units are proportional to real values.
   * Mass
   * Radius
   * Position (x, y)
   * Acceleration
   * Velocity
   * Texture
   
## PlanetActions - The PlanetActions is a object, which interacts with Planet objects.
   * Calculate positions - Calculates positions of planets
   * Force vector - Force vector between two planets
   * (std::vector) Planets - Keeps Planet objects
   * Add planet - Allow to add some planet
   
## AbstractMenu - polymorphic class.
   * Draw - gets a window in which the menu will be drawn
   * Update Parallax - parallax effect is associcated with mouse movements

## Menu <- AbstractMenu

## Pause <- AbstractMenu
   * Keeps some overload methods
   
## Render <- sf::RenderWindow

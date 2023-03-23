# OpenGL Example using C

In this repository, there's a simple OpenGL usage with one `Vertex Buffer Object` (VBO),
`Vertex Array Object` (VAO) and `Element Buffer Object` (EBO).

## Simple Triangle:

- 3 Vertices
- Showcase of regular drawing with one VBO.

<img src="/resources/static_image.png" alt="Showcase of a simple triangle"/>

## Moving triangle

- A Simple triangle but indexed to show more vertex even inside it.
- 6 Vertices
- And a simple animation example changing the lower left triangle vertex normalized position

<img src="/resources/openggif.gif" alt="Showcase of a simple triangle"/>

## Vector Implementation

- Simple Vector2D point using default window size.

<img src="/resources/vector.png" alt="Showcase of a equilateral Vector2D Triangle"/>

- In order to put it into the Window "object", needed to normalize and calculate an
  equilateral triangle to act as "placeholder".
- Simple moving calculating and converting:
    1. Create the Vector2D point: `Vector2 p1 = CreateVector(50, 400);`
    2. Create the Triangle Placeholder for it: `TriangleVector2 tv2 = CreateTriangle(&p1, HEIGHT, WIDTH);`
    3. Create now the `float` array that contains the vertices of the
       triangle: `GenerateFloatArray(&tv2, vectorVertex);`
    4. Now show the vertices using your Buffer Object.
- This will be used as a base PoC to the <a href="https://github.com/Beloin/SwarmEngine">Swarm Engine</a>.

<img src="/resources/vector.gif" alt="Showcase of a moving Vector2D"/>

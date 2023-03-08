# A Mandelbrot set visualizer

I want to draw an approxiamtion of the Mandelbrot set, meaning that for a rectangular region of the 
complex plane, I will map each point to a color, depending on how fast it shoots off to infinity
when iterated under the iterated function
$$f_c(x) = x^2 + c$$
where $c$ is the complex number in consideration, and $x$ is the result of the previous iteration,
with an initial value of $0$.

In a more program-oriented view, this function can be recursively described as
$$f(x, i)=
\begin{cases}
    f(x^2 + c, i-1), & \text{if } i > 0 \\
    x, & \text{if } i = 0
\end{cases}
$$
and the initial call is 
$f(c, \text{iteration-count})$


## Coloring the outputs of this function
We are aiming only for an approximation of this set. As such, we can consider that a number
has shot off to infinity with reasonable confidence if its absolute value has surpassed a certain number, say, $N$. Thus, our map could be 
$$
\text{color}(c) = 
\begin{cases}
    \text{white}, & \text{if } |f(c, \text{ iterations})| \ge N \\
    \text{black}, & \text{otherwise}
\end{cases}
$$

## Rendering time
Drawing from previous experiments, rendering such a visualization can take a significant amount of time,
especially if one has zoomed into the picture. (Time was on the order of seconds)

* Previous calculations could be reused if the picture has only been panned (moved in a certain direction)

I want to draw this visualization to a window of fixed dimensions $X \text{ and } Y$.
The visualization will work on a rectangular region centered on a point $c \in \mathbf{C}$,
$c = x + yi$, having a height of $2 \cdot h$ and a width of $2 \cdot w$.

In effect, what zooming does is that it multiplies $h$ and $w$ by a certain factor, $z$.

Panning changes the values of $x$ and $y$. (the value by which they are changed should depend on $z$).

Mapping this rectangular region to the window can be acomplished by splitting it into $X \times Y$
squares, running one point from each square through the color-mapping function, and setting the color
of each pixel of the window based on that.

* The window and the rectangular region should have the same aspect ratio $\frac{X}{Y}$.
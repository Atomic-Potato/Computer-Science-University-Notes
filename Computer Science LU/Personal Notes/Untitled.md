
# General Equation
$$\large (\frac{speed}{steepness} - shifting)^2 + min = max$$
`min` and `max` are constants _(i.e. are set in the inspector)_
## Speed
$$speed = (\sqrt{ max-min }- shift) * steepness$$
## Steepness
$$\large steepness = \frac{maxspeed}{\sqrt{ max-min }- shift}$$
## Shift
$$\large shift = \frac{max - min - \sqrt{ max-min }}{2} $$
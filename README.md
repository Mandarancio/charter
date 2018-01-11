# CHARTER
A simple markdown **DSL** and **C Library** to generate svg plot from a minimal syntax.

## Example

Simple syntax example:

```
plot:
    y: 0, 2, 4, 9
    label: x^2
```

Resutls in:

![result](test/test.svg)

## Syntax

| syntax | description |
| :----- | :------  |
|```plot```| create a new line plot|
|```scatter```| create a new scatter plot|
|```x-axis```| parameters for the x axis |
|```y-axsi```| parameters for the y axis |
|```label``` | label for axis or plot |
|```x```| x values of a plot |
|```y```| y values of a plot | 
|```color```| colour of a plot |  
|```line-width``` or ```lw```| plot line width |
|```line-style``` or ```ls```| plot line style ('--' or 'dashed', '-' or 'normal', ':' or dotted, '/' or 'none')|
|```marker```| marker style of a plot ('o', 'x', '+', 's', ' ')|
|```range```| min and max value for an axis |
|```mode``` | axis mode ('linear' or 'log') |
|```title```| plot title |
|```width```| plot width |
|```height```| plot height |
|```csv://file_path#tag```| load a csv and use column ```tag``` as values |

**commas** and **spaces** are valid separator for arrays and the sytax in general.
For the definitions **spaces**, **tabs** and **:** are equivalents. So ```x: 1 2 3``` is equal to ```x 1,2,3```.

## Future improvements

In the next future I will improve the svg quality, the memory performance, and the look and feel of the output plus the following features:
 
 - better log scales
 - bar plot
 - more styling options

## Marker integration
At the moment _charter_ is integrated in [Marker](https://github.com/fabiocolacio/Marker/)!

![marker and charter](marker_charter_support.png)

## Credits

[csv_parser](https://github.com/JamesRamm/csv_parserhttps://github.com/JamesRamm/csv_parser) 

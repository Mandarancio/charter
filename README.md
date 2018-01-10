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
|```x-axis```| parameters for the x axis |
|```y-axsi```| parameters for the y axis |
|```label``` | label for axis or plot |
|```x```| x values of a plot |
|```y```| y values of a plot | 
|```color```| colour of a plot |  
|```marker```| marker style of a plot ('o', 'x', '+', 's', ' ')|
|```range```| min and max value for an axis |
|```title```| plot title |
|```width```| plot width |
|```height```| plot height |
|```csv://file_path#tag```| load a csv and use column ```tag``` as values |

## Marker integration
At the moment _charter_ is integrated in [Marker](https://github.com/fabiocolacio/Marker/)!

![marker and charter](marker_charter_support.png)

## Credits

[csv_parser](https://github.com/JamesRamm/csv_parserhttps://github.com/JamesRamm/csv_parser) 

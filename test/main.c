#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

#include "parser.h"
#include "renderer.h"
#include "printer.h"

char*  generate_input()
{
    char * buffer = malloc(10000*sizeof(char));
    memset(buffer, 0, 10000);
    sprintf(buffer,  "x-axis(\n\
            label: compression rate\n\
            range: 0, 4\n\
        )\n\
        y-axis(\n\
            label: mse \n\
        )\
        plot(\n\
            x: csv://data.csv#X\n\
            y: csv://data.csv#Y\n\
        )\n\
        plot(\n\
            x: 0, 4\n\
            y: -1, 1\n\
        )");
    printf("%s<br>\n",buffer);
    return buffer;
}

int main(int argc, char* argv[])
{   

    
    chart * chart = parse_chart(
        generate_input()
    );
    char * svg = chart_to_svg(chart);
    printf("%s\n", print_chart(chart));
    printf("<hr>\n<figure>\n");
    printf("%s\n",svg);
    printf("<figcaption>This is a plot</figcaption>\n"
           "</figure>\n");
    return 0;
}
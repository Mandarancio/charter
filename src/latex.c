#include "renderer.h"
#include "charter_string.h"

#include <stdlib.h>

void render_axis   (cstr  *str,
                    chart *crt);

void render_plot   (cstr  *str,
                    plot  *plt);

void close_axis    (cstr  *str,
                    chart *crt);

void render_color  (cstr *str,
                    plot *crt);

char*
chart_to_latex(chart * chart)
{
  cstr * str = cstr_new();
  cstr_add(str, "\\begin{tikzpicture}\n");
  render_axis(str, chart);

  clist * it = NULL;

  for (it = chart->plots; it != NULL; it = it->next) {
    plot * p = (plot *)it->data;
    render_plot(str, p);
  }

  close_axis(str, chart);
  cstr_add(str, "\\end{tikzpicture}\n");
  return str->data;
}

void
close_axis  (cstr  *str,
             chart *crt)
{
  if (crt->x_axis.mode == NORMAL && crt->y_axis.mode == NORMAL) {
    cstr_add(str, "\\end{axis}\n");
  } else if (crt->x_axis.mode == NORMAL && crt->y_axis.mode == LOG) {
    cstr_add(str, "\\end{semilogyaxis}\n");
  } else if (crt->x_axis.mode == LOG && crt->y_axis.mode == NORMAL) {
    cstr_add(str, "\\end{semilogxaxis}\n");
  } else {
    cstr_add(str, "\\end{loglogaxis}\n");
  }
}


void
render_axis (cstr  *str,
             chart *crt)
{
  if (crt->x_axis.mode == NORMAL && crt->y_axis.mode == NORMAL) {
    cstr_add(str, "\\begin{axis}[\n");
  } else if (crt->x_axis.mode == NORMAL && crt->y_axis.mode == LOG) {
    cstr_add(str, "\\begin{semilogyaxis}[\n");
  } else if (crt->x_axis.mode == LOG && crt->y_axis.mode == NORMAL) {
    cstr_add(str, "\\begin{semilogxaxis}[\n");
  } else {
    cstr_add(str, "\\begin{loglogaxis}[\n");
  }
  cstr_add(str, "\tgrid=both,\n");

  if (crt->title) {
    cstr_printf(str, "\ttitle={%s},\n", crt->title);
  }
  if (!crt->x_axis.autoscale) {
    cstr_printf(str, "\txmin=%f, xmax=%f,\n", crt->x_axis.range_min, crt->x_axis.range_max);
  }
  if (!crt->y_axis.autoscale) {
    cstr_printf(str, "\tymin=%f, ymax=%f,\n", crt->y_axis.range_min, crt->y_axis.range_max);
  }
  if (crt->x_axis.label) {
    cstr_printf(str, "\txlabel={%s},\n", crt->x_axis.label);
  }
  if (crt->y_axis.label) {
    cstr_printf(str, "\tylabel={%s},\n", crt->y_axis.label);
  }

  cstr_add(str, "]\n");
}

void
render_plot(cstr *str,
            plot *plot)
{
  cstr_add(str, "\\addplot[\n");

  switch (plot->type)
  {
  case SCATTER:
    cstr_add(str, "\tscatter, only marks,\n");
    break;
  case LINE:
    break;
  case BAR:
    cstr_add(str, "\tybar,\n");
    break;
  }

  if (plot->type == BAR)
  {
    barPref * pref = plot->extra_data;
    cstr_printf(str, "\tbar width=%f,\n", pref->bar_width);
  }
  cstr_printf(str, "\tline width = %fpt,\n", plot->line_width/2);

  switch (plot->line_style)
  {
  case NORMAL:
    cstr_add(str, "\tsolid,\n");
    break;
  case DOTTED:
    cstr_add(str, "\tdotted,\n");
    break;
  case DASHED:
    cstr_add(str, "\tdashed,\n");
    break;
  case DOT_DASH:
    cstr_add(str, "\tdash pattern=on 1pt off 3pt on 3pt off 3pt,\n");
    break;
  case NOLINE:
    cstr_add(str, "\tonly marks,\n");
    break;
  }
  switch (plot->marker_style)
  {
    case 'o':
        cstr_add(str, "\tmark=*,\n");
        break;
    case 's':
        cstr_add(str, "\tmark=square*,\n");
        break;
    case 'x':
        cstr_add(str, "\tmark=x,\n");
        break;
    case '+':
        cstr_add(str, "\tmark=+,\n");
        break;
    default:
        break;
  }

  cstr_add(str, "] table {\n");
  int i;

  double * y_data = plot_eval_y(plot);

  for (i = 0; i < plot->n; i++) {
    double x = plot->x_data ? plot->x_data[i] : (i + 1);
    double y = y_data[i];
    cstr_printf(str,"\t%f %f\n",x, y);
  }

  free(y_data);
  cstr_add(str, "};\n");

  if (plot->label) {
    cstr_printf(str, "\\addlegendentry{%s}\n", plot->label);
  }
}

void
render_color (cstr *str,
              plot *plt)
{
}

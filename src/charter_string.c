#include "charter_string.h"

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

cstr*
cstr_new()
{
  cstr * str = malloc(sizeof(cstr));
  str->size = 0;
  str->data = malloc(sizeof(char));
  str->data[0] = 0;

  return str;
}

void
cstr_free(cstr* str)
{
  if (str->data)
    free(str->data);
  free(str);
}

cstr*
cstr_add(cstr *str,
         char *data)
{
  int n = strlen(data);
  if (n > 0)
  {
    int m = n + str->size;
    str->data = realloc(str->data, (m+1)*sizeof(char));
    memcpy(str->data + str->size, data, n);
    str->data[m] = 0;
    str->size = m;
  }
  return str;
}


void
cstr_printf (cstr       *str,
             const char *fmt,
             ...)
{
    va_list ap;
	int n;
    char buff[1024];
	va_start(ap, fmt);

	n = vsnprintf(buff, 1024, fmt, ap);

	va_end(ap);

	if (n < 0) {
    	return;
	}
    cstr_add(str, buff);
}

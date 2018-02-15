#ifndef __CHARTER_STRING_H__
#define __CHARTER_STRING_H__

struct {
  int    size;
  char  *data;
} typedef cstr;

cstr* cstr_new   (void);
void  cstr_free  (cstr        *str);

cstr* cstr_add   (cstr        *str,
                  char        *data);

void  cstr_printf (cstr       *str,
                   const char *fmt,
                   ...) __attribute__ ((format (printf, 2, 3)));
#endif

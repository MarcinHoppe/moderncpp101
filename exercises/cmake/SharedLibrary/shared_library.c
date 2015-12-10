#include "shared_library.h"

#include <stdio.h>
#include <stdlib.h>

int * g_ret_val_ptr;

void Init()
{
  g_ret_val_ptr = (int *) malloc(sizeof(int));
  *g_ret_val_ptr = 42;
}

void Release()
{
  free(g_ret_val_ptr);
}

int SharedFoo()
{
  printf("SharedFoo() returns %d\n", *g_ret_val_ptr);
  return *g_ret_val_ptr;
}
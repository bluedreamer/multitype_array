#include <stdio.h>
#include <assert.h>
#include "multiarray.h"

void test_alloc_free_array();
void test_int_array();
void test_double_array();
void test_char_array();
void test_resize();

void test_int_array()
{
   printf("Enter %s\n", __func__);
   const int  max_size = 10;
   MultiArray *array   = CreateArray(type_int32_e, max_size);

   for(size_t i = 0; i<array->array_size; ++i)
   {
      int32_t val = i*10;
      if(PushArray(array, &val))
      {
         printf("Error: some thing\n");
         exit(1);
      }
   }

   for(size_t i = 0; i<max_size; ++i)
   {
      printf("element %zu = %d\n", i, GetElementAt_int32(array, i));
   }
   DestroyArray(&array);
   printf("Exit  %s\n", __func__);
}

void test_double_array()
{
   printf("Enter %s\n", __func__);
   const int  max_size = 20;
   MultiArray *array   = CreateArray(type_double_e, max_size);

   for(size_t i = 0; i<array->array_size; ++i)
   {
      double val = i*3.142;
      if(PushArray(array, &val))
      {
         printf("Error: some thing\n");
         exit(1);
      }
   }

   for(size_t i = 0; i<array->array_size; ++i)
   {
      printf("element %zu = %f\n", i, GetElementAt_double(array, i));
   }
   DestroyArray(&array);
   printf("Exit  %s\n", __func__);
}

void test_char_array()
{
   printf("Enter %s\n", __func__);
   const int  max_size = 15;
   MultiArray *array   = CreateArray(type_int8_e, max_size);

   for(size_t i = 0; i<array->array_size; ++i)
   {
      char val = 'A'+i;
      if(PushArray(array, &val))
      {
         printf("Error: some thing\n");
         exit(1);
      }
   }

   for(size_t i = 0; i<max_size; ++i)
   {
      printf("element %zu = %c\n", i, GetElementAt_int8(array, i));
   }
   DestroyArray(&array);
   printf("Exit  %s\n", __func__);
}

void test_resize()
{
   printf("Resize test: Create array of 10\n");
   MultiArray *array = CreateArray(type_int32_e, 10);

   for(size_t i = 0; i<array->array_size; ++i)
   {
      int32_t val = 3+i*13;
      if(PushArray(array, &val))
      {
         printf("Error: some thing\n");
         exit(1);
      }
   }

   for(size_t i = 0; i<array->array_size; ++i)
   {
      printf("element %zu = %d\n", i, GetElementAt_int32(array, i));
   }

   printf("Resize test: Resize to 20\n");
   ResizeArray(array, 20);
   for(size_t i = 0; i<array->array_size; ++i)
   {
      printf("element %zu = %d\n", i, GetElementAt_int32(array, i));
   }

   printf("Resize test: Resize to 5\n");
   ResizeArray(array, 5);
   for(size_t i = 0; i<array->array_size; ++i)
   {
      printf("element %zu = %d\n", i, GetElementAt_int32(array, i));
   }

   DestroyArray(&array);
}

void test_alloc_free_array()
{
   printf("Enter %s\n", __func__);
   MultiArray *ptr= CreateArray(type_uint16_e, 5);
   assert(ptr);
   DestroyArray(&ptr);
   assert(ptr==NULL);
   printf("Exit  %s\n", __func__);
}

int main()
{
   test_alloc_free_array();
   test_int_array();
   test_double_array();
   test_char_array();
   test_resize();

   return 0;
}

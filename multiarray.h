#ifndef MULTITYPE_ARRAY_MULTIARRAY_H
#define MULTITYPE_ARRAY_MULTIARRAY_H

#include <stdint.h>
#include <stdlib.h>

typedef enum
{
   type_invalid_e = 0,
   type_int8_e,
   type_int16_e,
   type_int32_e,
   type_int64_e,
   type_uint8_e,
   type_uint16_e,
   type_uint32_e,
   type_uint64_e,
   type_double_e,
   type_float_e
} ArrayType;

typedef struct MultiArray
{
   ArrayType type;
   size_t  array_size;
   size_t  current_index;
   union Data
      {
      int8_t  *int8_data;
      int16_t *int16_data;
      int32_t *int32_data;
      int64_t *int64_data;

      uint8_t  *uint8_data;
      uint16_t *uint16_data;
      uint32_t *uint32_data;
      uint64_t *uint64_data;

      double *double_data;
      float  *float_data;
      } data;
   int32_t (*GetElementAt)(struct MultiArray *ptr, size_t);
} MultiArray;

uint32_t GetCountMax(MultiArray *ptr);
int PushArray(MultiArray *ptr, void *value);
MultiArray *CreateArray(ArrayType type, size_t size);
void DestroyArray(MultiArray **ptr);

void ResizeArray(MultiArray *ptr, size_t size);

int32_t GetElementAt_int32(MultiArray *ptr, size_t index);
int8_t GetElementAt_int8(MultiArray *ptr, size_t index);
double GetElementAt_double(MultiArray *ptr, size_t index);

void GetElementAt(MultiArray *ptr, size_t index, void *data);

#endif //MULTITYPE_ARRAY_MULTIARRAY_H

#include "multiarray.h"
#include <stdlib.h>
#include <assert.h>

uint32_t GetCountMax(MultiArray *ptr)
{
   assert(ptr);
   return ptr->array_size;
}

int PushArray(MultiArray *ptr, void *value)
{
   assert(ptr);
   if(ptr->array_size==ptr->current_index)
   {
      return -1;
   }

   switch(ptr->type)
   {
      case type_int8_e:
         ptr->data.int8_data[ptr->current_index++] = *(int8_t *)value;
         break;
      case type_int16_e:
         ptr->data.int16_data[ptr->current_index++] = *(int16_t *)value;
         break;
      case type_int32_e:
         ptr->data.int32_data[ptr->current_index++] = *(int32_t *)value;
         break;
      case type_int64_e:
         ptr->data.int64_data[ptr->current_index++] = *(int64_t *)value;
         break;
      case type_uint8_e:
         ptr->data.uint8_data[ptr->current_index++] = *(uint8_t *)value;
         break;
      case type_uint16_e:
         ptr->data.uint16_data[ptr->current_index++] = *(uint16_t *)value;
         break;
      case type_uint32_e:
         ptr->data.uint32_data[ptr->current_index++] = *(uint32_t *)value;
         break;
      case type_uint64_e:
         ptr->data.uint64_data[ptr->current_index++] = *(uint64_t *)value;
         break;
      case type_double_e:
         ptr->data.double_data[ptr->current_index++] = *(double *)value;
         break;
      case type_float_e:
         ptr->data.float_data[ptr->current_index++] = *(float *)value;
         break;
      default:
         assert(0);
         break;
   }
   return 0;
}

MultiArray *CreateArray(ArrayType type, size_t size)
{
   MultiArray *ptr = calloc(1, sizeof(MultiArray));
   ptr->type          = type;
   ptr->array_size    = size;
   ptr->current_index = 0;

   switch(ptr->type)
   {
      case type_int8_e:
         ptr->data.int8_data = calloc(size, sizeof(int8_t));
         break;
      case type_int16_e:
         ptr->data.int16_data = calloc(size, sizeof(int16_t));
         break;
      case type_int32_e:
         ptr->data.int32_data = calloc(size, sizeof(int32_t));
         ptr->GetElementAt    = GetElementAt_int32;
         break;
      case type_int64_e:
         ptr->data.int64_data = calloc(size, sizeof(int64_t));
         break;
      case type_uint8_e:
         ptr->data.uint8_data = calloc(size, sizeof(uint8_t));
         break;
      case type_uint16_e:
         ptr->data.uint16_data = calloc(size, sizeof(uint16_t));
         break;
      case type_uint32_e:
         ptr->data.uint32_data = calloc(size, sizeof(uint32_t));
         break;
      case type_uint64_e:
         ptr->data.uint64_data = calloc(size, sizeof(uint64_t));
         break;
      case type_double_e:
         ptr->data.double_data = calloc(size, sizeof(double));
         break;
      case type_float_e:
         ptr->data.float_data = calloc(size, sizeof(float));
         break;
      default:
         assert(0);
         break;
   }
   return ptr;
}

void DestroyArray(MultiArray **ptr)
{
   assert(ptr);
   assert(*ptr);
   MultiArray *tmp = *ptr;
   switch(tmp->type)
   {
      case type_int8_e:
         free(tmp->data.int8_data);
         break;
      case type_int16_e:
         free(tmp->data.int16_data);
         break;
      case type_int32_e:
         free(tmp->data.int32_data);
         break;
      case type_int64_e:
         free(tmp->data.int64_data);
         break;
      case type_uint8_e:
         free(tmp->data.uint8_data);
         break;
      case type_uint16_e:
         free(tmp->data.uint16_data);
         break;
      case type_uint32_e:
         free(tmp->data.uint32_data);
         break;
      case type_uint64_e:
         free(tmp->data.uint64_data);
         break;
      case type_double_e:
         free(tmp->data.double_data);
         break;
      case type_float_e:
         free(tmp->data.float_data);
         break;
      default:
         assert(0);
         break;
   }
   free(*ptr);
   *ptr = NULL;
}

void ResizeArray(MultiArray *ptr, size_t size)
{
   assert(ptr);
   assert(size);
   switch(ptr->type)
   {
      case type_int8_e:
         ptr->data.int8_data = realloc(ptr->data.int8_data, size*sizeof(int8_t));
         for(size_t i        = ptr->current_index; i<size; ++i)
         {
            ptr->data.int8_data[i] = 0;
         }
         break;
      case type_int16_e:
         ptr->data.int16_data = realloc(ptr->data.int16_data, size*sizeof(int16_t));
         for(size_t i = ptr->current_index; i<size; ++i)
         {
            ptr->data.int16_data[i] = 0;
         }
         break;
      case type_int32_e:
         ptr->data.int32_data = realloc(ptr->data.int32_data, size*sizeof(int32_t));
         for(size_t i = ptr->current_index; i<size; ++i)
         {
            ptr->data.int32_data[i] = 0;
         }
         break;
      case type_int64_e:
         ptr->data.int64_data = realloc(ptr->data.int64_data, size*sizeof(int64_t));
         for(size_t i = ptr->current_index; i<size; ++i)
         {
            ptr->data.int64_data[i] = 0;
         }
         break;
      case type_uint8_e:
         ptr->data.uint8_data = realloc(ptr->data.uint8_data, size*sizeof(uint8_t));
         for(size_t i = ptr->current_index; i<size; ++i)
         {
            ptr->data.uint8_data[i] = 0;
         }
         break;
      case type_uint16_e:
         ptr->data.uint16_data = realloc(ptr->data.uint16_data, size*sizeof(uint16_t));
         for(size_t i = ptr->current_index; i<size; ++i)
         {
            ptr->data.uint16_data[i] = 0;
         }
         break;
      case type_uint32_e:
         ptr->data.uint32_data = realloc(ptr->data.uint32_data, size*sizeof(uint32_t));
         for(size_t i = ptr->current_index; i<size; ++i)
         {
            ptr->data.uint32_data[i] = 0;
         }
         break;
      case type_uint64_e:
         ptr->data.uint64_data = realloc(ptr->data.uint64_data, size*sizeof(uint64_t));
         for(size_t i = ptr->current_index; i<size; ++i)
         {
            ptr->data.uint64_data[i] = 0;
         }
         break;
      case type_double_e:
         ptr->data.double_data = realloc(ptr->data.double_data, size*sizeof(double));
         for(size_t i = ptr->current_index; i<size; ++i)
         {
            ptr->data.double_data[i] = 0;
         }
         break;
      case type_float_e:
         ptr->data.float_data = realloc(ptr->data.float_data, size*sizeof(float));
         for(size_t i = ptr->current_index; i<size; ++i)
         {
            ptr->data.float_data[i] = 0;
         }
         break;
      default:
         assert(0);
         break;
   }
   ptr->array_size = size;
   if(ptr->current_index>=size)
   {
      ptr->current_index = size-1;
   }
}

void GetElementAt(MultiArray *ptr, size_t index, void *data)
{
   assert(ptr);
   assert(data);
   assert(ptr->array_size>index);
   switch(ptr->type)
   {
      case type_int8_e:
         *(int8_t*)data = ptr->data.int8_data[index];
         break;
      case type_int16_e:
         *(int16_t*)data = ptr->data.int16_data[index];
         break;
      case type_int32_e:
         *(int32_t*)data = ptr->data.int32_data[index];
         break;
      case type_int64_e:
         *(int64_t*)data = ptr->data.int64_data[index];
         break;
      case type_uint8_e:
         *(uint8_t*)data = ptr->data.uint8_data[index];
         break;
      case type_uint16_e:
         *(uint16_t*)data = ptr->data.uint16_data[index];
         break;
      case type_uint32_e:
         *(uint32_t*)data = ptr->data.uint32_data[index];
         break;
      case type_uint64_e:
         *(uint64_t*)data = ptr->data.uint64_data[index];
         break;
      case type_double_e:
         *(double*)data = ptr->data.double_data[index];
         break;
      case type_float_e:
         *(float*)data = ptr->data.float_data[index];
         break;
      default:
         assert(0);
         break;
   }
}

int32_t GetElementAt_int32(MultiArray *ptr, size_t index)
{
   assert(ptr->type==type_int32_e);
   assert(ptr->array_size>index);
   return ptr->data.int32_data[index];
}

int8_t GetElementAt_int8(MultiArray *ptr, size_t index)
{
   assert(ptr);
   assert(ptr->type==type_int8_e);
   assert(ptr->array_size>index);
   return ptr->data.int8_data[index];
}

double GetElementAt_double(MultiArray *ptr, size_t index)
{
   assert(ptr);
   assert(ptr->type==type_double_e);
   assert(ptr->array_size>index);
   return ptr->data.double_data[index];
}

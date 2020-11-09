#ifndef __REF_H__
#define __REF_H__

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

//参照値
typedef struct {
	size_t size;
	void* ptr;
} ref;

//フィールド情報
typedef struct {
	const char* name;
	const void* ptr;
	uint8_t size;
} field_info;

//構造体情報
typedef struct {
	const char* name;
	const field_info* fields;
} struct_info;

extern const struct_info* struct_get(const char* type_name);
extern const field_info* field_get(const struct_info* self, const char* field_name);
extern void ref_get(const field_info* self, void* obj, ref* result);
extern void ref_set(ref* self, size_t val);


#define const_field_val(type_name, field_name) { #field_name, &_. ## type_name ## . ## field_name, sizeof( _. ## type_name ## . ## field_name) }
#define const_field_ptr(type_name, field_name) { #field_name, &_. ## type_name ## . ## field_name, sizeof(*_. ## type_name ## . ## field_name) }
#define const_table(type_name) { #type_name, f_ ## type_name }




#endif//__REF_H__

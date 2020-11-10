#ifndef __REF_H__
#define __REF_H__

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

typedef enum {
	TYPE_VAL_INT,
	TYPE_VAL_NUM,
	TYPE_VAL_ARY,
	TYPE_VAL_REF,
	TYPE_PTR_INT,
	TYPE_PTR_NUM,
	TYPE_PTR_ARY,
	TYPE_PTR_REF,
} TYPE_KIND;

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
	uint8_t kind;
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

extern void json_serialize(struct_info* info, void* obj, char* result);
extern void json_deserialize(struct_info* info, const char* json, void* result);


#define const_field_val(type_name, field_name, kind) { #field_name, &_. ## type_name ## . ## field_name, sizeof( _. ## type_name ## . ## field_name), TYPE_VAL_ ## kind }
#define const_field_ptr(type_name, field_name, kind) { #field_name, &_. ## type_name ## . ## field_name, sizeof(*_. ## type_name ## . ## field_name), TYPE_PTR_ ## kind }
#define const_table(type_name) { #type_name, f_ ## type_name }




#endif//__REF_H__

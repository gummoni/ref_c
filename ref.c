#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "ref.h"
#include "comdef.h"

//=====================================================================
//型情報
//=====================================================================
typedef union {
	aaa aaa;
} type_info;

//=====================================================================
//型情報取得用
//=====================================================================
static const type_info _;

//=====================================================================
//フィールド情報
//=====================================================================
static const field_info f_aaa[] = {
	const_field_val(aaa, ch		, INT	),
	const_field_val(aaa, s16	, INT	),
	const_field_val(aaa, i32	, INT	),
	const_field_ptr(aaa, pi32	, INT	),
	const_field_ptr(aaa, msg	, ARY	),
	NULL,
};

//=====================================================================
//構造体情報
//=====================================================================
static const struct_info structs[] = {
	const_table(aaa),
	NULL,
};

//=====================================================================
//構造体情報取得
//=====================================================================
const struct_info* struct_get(const char* type_name) {
	for (const struct_info* info = structs; NULL != info; info++) {
		if (0 == strcmp(type_name, info->name)) {
			return info;
		}
	}
	return NULL;
}

//=====================================================================
//フィールド情報取得
//=====================================================================
const field_info* field_get(const struct_info* self, const char* field_name) {
	for (const field_info* info = self->fields; NULL != info; info++) {
		if (0 == strcmp(field_name, info->name)) {
			return info;
		}
	}
	return NULL;
}

//=====================================================================
//参照情報取得
//=====================================================================
void ref_get(const field_info* self, void* obj, ref* result) {
	result->size = self->size;
	result->ptr = (void*)((size_t)self->ptr - (size_t)&_ + (size_t)obj);
}

//=====================================================================
//参照情報書込
//=====================================================================
void ref_set(ref* self, size_t val) {
	switch (self->size) {
	case 1:
		*((uint8_t*)self->ptr) = (uint8_t)val;
		break;
	case 2:
		*((uint16_t*)self->ptr) = (uint16_t)val;
		break;
	case 4:
		*((uint32_t*)self->ptr) = (uint32_t)val;
		break;
	case 8:
		*((uint64_t*)self->ptr) = (uint64_t)val;
		break;
	}
}

//=====================================================================
//JSONシリアライズ
//=====================================================================
void json_serialize(struct_info* info, void* obj, char* result) {

}

//=====================================================================
//JSONデシリアライズ
//=====================================================================
void json_deserialize(struct_info* info, const char* json, void* result) {

}

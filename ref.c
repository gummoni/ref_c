#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "ref.h"
#include "comdef.h"

//=====================================================================
//�^���
//=====================================================================
typedef union {
	aaa aaa;
} type_info;

//=====================================================================
//�^���擾�p
//=====================================================================
static const type_info _;

//=====================================================================
//�t�B�[���h���
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
//�\���̏��
//=====================================================================
static const struct_info structs[] = {
	const_table(aaa),
	NULL,
};

//=====================================================================
//�\���̏��擾
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
//�t�B�[���h���擾
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
//�Q�Ə��擾
//=====================================================================
void ref_get(const field_info* self, void* obj, ref* result) {
	result->size = self->size;
	result->ptr = (void*)((size_t)self->ptr - (size_t)&_ + (size_t)obj);
}

//=====================================================================
//�Q�Ə�񏑍�
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
//JSON�V���A���C�Y
//=====================================================================
void json_serialize(struct_info* info, void* obj, char* result) {

}

//=====================================================================
//JSON�f�V���A���C�Y
//=====================================================================
void json_deserialize(struct_info* info, const char* json, void* result) {

}

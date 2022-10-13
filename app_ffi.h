
// ------------------------- Beginning of header -----------------------------
// WARNING: This file is auto-generated. DO NOT EDIT

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "microvium.h"

#ifdef __cplusplus
extern "C" {
#endif

extern mvm_VM* app_vm;

void app_restore(const uint8_t* snapshot, size_t snapshotSize);
void app_free();


void runRestoreEvents();
mvm_Value mvm_newObject();
void mvm_setProp(mvm_Value obj, const char* key, mvm_Value value);
mvm_Value mvm_getProp(mvm_Value obj, const char* key);
extern void print(const char* msg); // Must be implemented elsewhere

#ifdef __cplusplus
} // extern "C"
#endif

// --------------------------- End of header --------------------------------

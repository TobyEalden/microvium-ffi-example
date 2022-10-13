
// ------------------------- Beginning of implementation -----------------------------
// WARNING: This file is auto-generated. DO NOT EDIT

#include "app_ffi.h"

mvm_VM* app_vm = NULL;

static const mvm_VMExportID _vmExportsIDs[4] = {
  /*[0]*/ 65535, // runRestoreEvents
  /*[1]*/ 65534, // mvm_newObject
  /*[2]*/ 65533, // mvm_setProp
  /*[3]*/ 65532, // mvm_getProp
};

static mvm_Value _vmExports[4];

typedef struct ImportRecord {
  mvm_HostFunctionID id;
  mvm_TfHostFunction func;
} ImportRecord;

static mvm_TeError _print_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount);


static const ImportRecord _vmImports[1] = {
  /*[0]*/ {65535, _print_wrapper},
};

static mvm_TeError resolveImport(mvm_HostFunctionID hostFunctionID, void* context, mvm_TfHostFunction* out_hostFunction);

void app_restore(const uint8_t* snapshot, size_t snapshotSize) {
  mvm_TeError err;

  err = mvm_restore(&app_vm, (MVM_LONG_PTR_TYPE)snapshot, snapshotSize, NULL, resolveImport);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);

  err = mvm_resolveExports(app_vm, _vmExportsIDs, _vmExports, 4);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);

  runRestoreEvents();
}

void app_free() {
  if (!app_vm) return;
  mvm_free(app_vm);
  app_vm = NULL;
}

static mvm_TeError resolveImport(mvm_HostFunctionID hostFunctionID, void* context, mvm_TfHostFunction* out_hostFunction) {
  
  for (int i = 0; i < 1; i++) {
    if (_vmImports[i].id == hostFunctionID) {
      *out_hostFunction = _vmImports[i].func;
      return MVM_E_SUCCESS;
    }
  }
  return MVM_E_FUNCTION_NOT_FOUND;
  
}


void runRestoreEvents() {
  mvm_VM* _vm = app_vm;

  // Prepare the arguments
  
  
  mvm_Value _result;

  // Call the JS function
  mvm_TeError err = mvm_call(_vm, _vmExports[0], &_result, NULL, 0);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);

  // Convert/return the result
  return ;
}

mvm_Value mvm_newObject() {
  mvm_VM* _vm = app_vm;

  // Prepare the arguments
  
  
  mvm_Value _result;

  // Call the JS function
  mvm_TeError err = mvm_call(_vm, _vmExports[1], &_result, NULL, 0);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);

  // Convert/return the result
  return _result;
}

void mvm_setProp(mvm_Value obj, const char* key, mvm_Value value) {
  mvm_VM* _vm = app_vm;

  // Prepare the arguments
  mvm_Value _args[3];
  _args[0] = obj;
  _args[1] = mvm_newString(_vm, key, strlen(key));;
  _args[2] = value;
  mvm_Value _result;

  // Call the JS function
  mvm_TeError err = mvm_call(_vm, _vmExports[2], &_result, _args, 3);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);

  // Convert/return the result
  return ;
}

mvm_Value mvm_getProp(mvm_Value obj, const char* key) {
  mvm_VM* _vm = app_vm;

  // Prepare the arguments
  mvm_Value _args[2];
  _args[0] = obj;
  _args[1] = mvm_newString(_vm, key, strlen(key));;
  mvm_Value _result;

  // Call the JS function
  mvm_TeError err = mvm_call(_vm, _vmExports[3], &_result, _args, 2);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);

  // Convert/return the result
  return _result;
}

static mvm_TeError _print_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount) {
  // Prepare the arguments
  const char* msg = mvm_toStringUtf8(_vm, _argCount >= 1 ? _args[0] : mvm_undefined, NULL);;

  // Call the C function
  print(msg);

  // Convert the result
  *_result = mvm_undefined;

  return MVM_E_SUCCESS;
}

// ------------------------- End of implementation -----------------------------

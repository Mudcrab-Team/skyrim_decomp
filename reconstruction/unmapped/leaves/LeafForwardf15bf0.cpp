// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf15bf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf15bf0 LeafForwardf15bf0::Forward
#include "LeafForwardf15bf0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf15bf0::Forward() { return leaf_target(this); }

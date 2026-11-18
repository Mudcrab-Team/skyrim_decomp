// Source exposure: binary-analysis; no external implementation reused.
// LeafForward842b00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x842b00 LeafForward842b00::Forward
#include "LeafForward842b00.h"
extern "C" void* leaf_target(void*);
void* LeafForward842b00::Forward() { return leaf_target(this); }

// Source exposure: binary-analysis; no external implementation reused.
// LeafForward61ae00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x61ae00 LeafForward61ae00::Forward
#include "LeafForward61ae00.h"
extern "C" void* leaf_target(void*);
void* LeafForward61ae00::Forward() { return leaf_target(this); }

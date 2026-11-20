// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1085270, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1085270 LeafForward1085270::Forward
#include "LeafForward1085270.h"
extern "C" void* leaf_target(void*);
void* LeafForward1085270::Forward() { return leaf_target(this); }

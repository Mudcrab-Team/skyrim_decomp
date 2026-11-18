// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1230260, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1230260 LeafForward1230260::Forward
#include "LeafForward1230260.h"
extern "C" void* leaf_target(void*);
void* LeafForward1230260::Forward() { return leaf_target(this); }

// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1085290, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1085290 LeafForward1085290::Forward
#include "LeafForward1085290.h"
extern "C" void* leaf_target(void*);
void* LeafForward1085290::Forward() { return leaf_target(this); }

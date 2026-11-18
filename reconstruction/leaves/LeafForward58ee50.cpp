// Source exposure: binary-analysis; no external implementation reused.
// LeafForward58ee50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x58ee50 LeafForward58ee50::Forward
#include "LeafForward58ee50.h"
extern "C" void* leaf_target(void*);
void* LeafForward58ee50::Forward() { return leaf_target(this); }

// Source exposure: binary-analysis; no external implementation reused.
// LeafForward129e330, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x129e330 LeafForward129e330::Forward
#include "LeafForward129e330.h"
extern "C" void* leaf_target(void*);
void* LeafForward129e330::Forward() { return leaf_target(this); }

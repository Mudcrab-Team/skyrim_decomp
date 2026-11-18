// Source exposure: binary-analysis; no external implementation reused.
// LeafForward895260, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x895260 LeafForward895260::Forward
#include "LeafForward895260.h"
extern "C" void* leaf_target(void*);
void* LeafForward895260::Forward() { return leaf_target(this); }

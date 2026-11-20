// Source exposure: binary-analysis; no external implementation reused.
// LeafForward849540, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x849540 LeafForward849540::Forward
#include "LeafForward849540.h"
extern "C" void* leaf_target(void*);
void* LeafForward849540::Forward() { return leaf_target(this); }

// Source exposure: binary-analysis; no external implementation reused.
// VirtualTail80ff00, Dispatch, Invoke, object: GUESS(low) STANDIN
// Origin: nullable-virtual-tail v1
// 0x80ff00 VirtualTail80ff00::Dispatch
#include "VirtualTail80ff00.h"
void VirtualTail80ff00::Dispatch(VirtualTail80ff00* object) { if (object) object->Invoke(1); }

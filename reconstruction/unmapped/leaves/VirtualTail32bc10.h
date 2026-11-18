// Source exposure: binary-analysis; no external implementation reused.
// VirtualTail32bc10, Dispatch, Invoke, object: GUESS(low) STANDIN
// Origin: nullable-virtual-tail v1
#pragma once
class VirtualTail32bc10 {
public:
    virtual void Invoke(unsigned int);
    void Dispatch(VirtualTail32bc10* object);
};

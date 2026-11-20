// Source exposure: binary-analysis; no external implementation reused.
// VirtualTail82f800, Dispatch, Invoke, object: GUESS(low) STANDIN
// Origin: nullable-virtual-tail v1
#pragma once
class VirtualTail82f800 {
public:
    virtual void Invoke(unsigned int);
    void Dispatch(VirtualTail82f800* object);
};

// Source exposure: binary-analysis; no external implementation reused.
// VirtualTail816920, Dispatch, Invoke, object: GUESS(low) STANDIN
// Origin: nullable-virtual-tail v1
#pragma once
class VirtualTail816920 {
public:
    virtual void Invoke(unsigned int);
    void Dispatch(VirtualTail816920* object);
};

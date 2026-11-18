// Source exposure: binary-analysis; no external implementation reused.
// VirtualTail830610, Dispatch, Invoke, object: GUESS(low) STANDIN
// Origin: nullable-virtual-tail v1
#pragma once
class VirtualTail830610 {
public:
    virtual void Invoke(unsigned int);
    void Dispatch(VirtualTail830610* object);
};

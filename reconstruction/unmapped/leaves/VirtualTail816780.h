// Source exposure: binary-analysis; no external implementation reused.
// VirtualTail816780, Dispatch, Invoke, object: GUESS(low) STANDIN
// Origin: nullable-virtual-tail v1
#pragma once
class VirtualTail816780 {
public:
    virtual void Invoke(unsigned int);
    void Dispatch(VirtualTail816780* object);
};

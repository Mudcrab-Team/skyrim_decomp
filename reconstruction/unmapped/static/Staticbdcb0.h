// Source exposure: binary-analysis
// Staticbdcb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbdcb0;
extern void construct(Staticbdcb0*, const Descriptor*);
extern void destroy(Staticbdcb0*);
struct Staticbdcb0 {
    void* value;
    Staticbdcb0() { construct(this, &descriptor); }
    ~Staticbdcb0() { destroy(this); }
};

// Source exposure: binary-analysis
// Staticc55a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc55a0;
extern void construct(Staticc55a0*, const Descriptor*);
extern void destroy(Staticc55a0*);
struct Staticc55a0 {
    void* value;
    Staticc55a0() { construct(this, &descriptor); }
    ~Staticc55a0() { destroy(this); }
};

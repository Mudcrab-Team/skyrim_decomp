// Source exposure: binary-analysis
// Staticc55d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc55d0;
extern void construct(Staticc55d0*, const Descriptor*);
extern void destroy(Staticc55d0*);
struct Staticc55d0 {
    void* value;
    Staticc55d0() { construct(this, &descriptor); }
    ~Staticc55d0() { destroy(this); }
};

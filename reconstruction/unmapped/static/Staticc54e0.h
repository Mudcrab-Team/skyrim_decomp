// Source exposure: binary-analysis
// Staticc54e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc54e0;
extern void construct(Staticc54e0*, const Descriptor*);
extern void destroy(Staticc54e0*);
struct Staticc54e0 {
    void* value;
    Staticc54e0() { construct(this, &descriptor); }
    ~Staticc54e0() { destroy(this); }
};

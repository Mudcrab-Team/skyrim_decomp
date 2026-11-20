// Source exposure: binary-analysis
// Staticbb2d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbb2d0;
extern void construct(Staticbb2d0*, const Descriptor*);
extern void destroy(Staticbb2d0*);
struct Staticbb2d0 {
    void* value;
    Staticbb2d0() { construct(this, &descriptor); }
    ~Staticbb2d0() { destroy(this); }
};

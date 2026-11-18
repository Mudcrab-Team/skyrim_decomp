// Source exposure: binary-analysis
// Staticac9d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticac9d0;
extern void construct(Staticac9d0*, const Descriptor*);
extern void destroy(Staticac9d0*);
struct Staticac9d0 {
    void* value;
    Staticac9d0() { construct(this, &descriptor); }
    ~Staticac9d0() { destroy(this); }
};

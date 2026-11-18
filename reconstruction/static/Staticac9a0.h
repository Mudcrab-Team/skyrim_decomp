// Source exposure: binary-analysis
// Staticac9a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticac9a0;
extern void construct(Staticac9a0*, const Descriptor*);
extern void destroy(Staticac9a0*);
struct Staticac9a0 {
    void* value;
    Staticac9a0() { construct(this, &descriptor); }
    ~Staticac9a0() { destroy(this); }
};

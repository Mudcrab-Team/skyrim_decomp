// Source exposure: binary-analysis
// Staticac7a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticac7a0;
extern void construct(Staticac7a0*, const Descriptor*);
extern void destroy(Staticac7a0*);
struct Staticac7a0 {
    void* value;
    Staticac7a0() { construct(this, &descriptor); }
    ~Staticac7a0() { destroy(this); }
};

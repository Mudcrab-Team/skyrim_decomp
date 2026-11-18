// Source exposure: binary-analysis
// Staticef6a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef6a0;
extern void construct(Staticef6a0*, const Descriptor*);
extern void destroy(Staticef6a0*);
struct Staticef6a0 {
    void* value;
    Staticef6a0() { construct(this, &descriptor); }
    ~Staticef6a0() { destroy(this); }
};

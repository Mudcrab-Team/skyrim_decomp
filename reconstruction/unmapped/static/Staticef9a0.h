// Source exposure: binary-analysis
// Staticef9a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef9a0;
extern void construct(Staticef9a0*, const Descriptor*);
extern void destroy(Staticef9a0*);
struct Staticef9a0 {
    void* value;
    Staticef9a0() { construct(this, &descriptor); }
    ~Staticef9a0() { destroy(this); }
};

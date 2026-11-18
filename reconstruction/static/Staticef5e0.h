// Source exposure: binary-analysis
// Staticef5e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef5e0;
extern void construct(Staticef5e0*, const Descriptor*);
extern void destroy(Staticef5e0*);
struct Staticef5e0 {
    void* value;
    Staticef5e0() { construct(this, &descriptor); }
    ~Staticef5e0() { destroy(this); }
};

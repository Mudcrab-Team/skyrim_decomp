// Source exposure: binary-analysis
// Staticef5b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef5b0;
extern void construct(Staticef5b0*, const Descriptor*);
extern void destroy(Staticef5b0*);
struct Staticef5b0 {
    void* value;
    Staticef5b0() { construct(this, &descriptor); }
    ~Staticef5b0() { destroy(this); }
};

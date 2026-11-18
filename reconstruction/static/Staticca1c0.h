// Source exposure: binary-analysis
// Staticca1c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca1c0;
extern void construct(Staticca1c0*, const Descriptor*);
extern void destroy(Staticca1c0*);
struct Staticca1c0 {
    void* value;
    Staticca1c0() { construct(this, &descriptor); }
    ~Staticca1c0() { destroy(this); }
};

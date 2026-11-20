// Source exposure: binary-analysis
// Staticc9da0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9da0;
extern void construct(Staticc9da0*, const Descriptor*);
extern void destroy(Staticc9da0*);
struct Staticc9da0 {
    void* value;
    Staticc9da0() { construct(this, &descriptor); }
    ~Staticc9da0() { destroy(this); }
};

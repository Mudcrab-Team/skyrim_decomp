// Source exposure: binary-analysis
// Staticc2ea0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc2ea0;
extern void construct(Staticc2ea0*, const Descriptor*);
extern void destroy(Staticc2ea0*);
struct Staticc2ea0 {
    void* value;
    Staticc2ea0() { construct(this, &descriptor); }
    ~Staticc2ea0() { destroy(this); }
};

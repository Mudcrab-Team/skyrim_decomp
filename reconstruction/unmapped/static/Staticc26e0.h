// Source exposure: binary-analysis
// Staticc26e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc26e0;
extern void construct(Staticc26e0*, const Descriptor*);
extern void destroy(Staticc26e0*);
struct Staticc26e0 {
    void* value;
    Staticc26e0() { construct(this, &descriptor); }
    ~Staticc26e0() { destroy(this); }
};

// Source exposure: binary-analysis
// Staticc67c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc67c0;
extern void construct(Staticc67c0*, const Descriptor*);
extern void destroy(Staticc67c0*);
struct Staticc67c0 {
    void* value;
    Staticc67c0() { construct(this, &descriptor); }
    ~Staticc67c0() { destroy(this); }
};

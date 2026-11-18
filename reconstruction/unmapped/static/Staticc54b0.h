// Source exposure: binary-analysis
// Staticc54b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc54b0;
extern void construct(Staticc54b0*, const Descriptor*);
extern void destroy(Staticc54b0*);
struct Staticc54b0 {
    void* value;
    Staticc54b0() { construct(this, &descriptor); }
    ~Staticc54b0() { destroy(this); }
};

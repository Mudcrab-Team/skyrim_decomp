// Source exposure: binary-analysis
// Staticefbe0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefbe0;
extern void construct(Staticefbe0*, const Descriptor*);
extern void destroy(Staticefbe0*);
struct Staticefbe0 {
    void* value;
    Staticefbe0() { construct(this, &descriptor); }
    ~Staticefbe0() { destroy(this); }
};

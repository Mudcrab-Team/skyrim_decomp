// Source exposure: binary-analysis
// Staticcac20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcac20;
extern void construct(Staticcac20*, const Descriptor*);
extern void destroy(Staticcac20*);
struct Staticcac20 {
    void* value;
    Staticcac20() { construct(this, &descriptor); }
    ~Staticcac20() { destroy(this); }
};

// Source exposure: binary-analysis
// Staticdca0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticdca0;
extern void construct(Staticdca0*, const Descriptor*);
extern void destroy(Staticdca0*);
struct Staticdca0 {
    void* value;
    Staticdca0() { construct(this, &descriptor); }
    ~Staticdca0() { destroy(this); }
};

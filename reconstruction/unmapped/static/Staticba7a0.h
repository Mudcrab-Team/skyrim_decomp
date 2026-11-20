// Source exposure: binary-analysis
// Staticba7a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticba7a0;
extern void construct(Staticba7a0*, const Descriptor*);
extern void destroy(Staticba7a0*);
struct Staticba7a0 {
    void* value;
    Staticba7a0() { construct(this, &descriptor); }
    ~Staticba7a0() { destroy(this); }
};

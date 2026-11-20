// Source exposure: binary-analysis
// Staticb9330, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9330;
extern void construct(Staticb9330*, const Descriptor*);
extern void destroy(Staticb9330*);
struct Staticb9330 {
    void* value;
    Staticb9330() { construct(this, &descriptor); }
    ~Staticb9330() { destroy(this); }
};

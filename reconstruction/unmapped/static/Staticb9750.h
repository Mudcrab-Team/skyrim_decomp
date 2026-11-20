// Source exposure: binary-analysis
// Staticb9750, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9750;
extern void construct(Staticb9750*, const Descriptor*);
extern void destroy(Staticb9750*);
struct Staticb9750 {
    void* value;
    Staticb9750() { construct(this, &descriptor); }
    ~Staticb9750() { destroy(this); }
};

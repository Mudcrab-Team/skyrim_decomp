// Source exposure: binary-analysis
// Staticb7750, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7750;
extern void construct(Staticb7750*, const Descriptor*);
extern void destroy(Staticb7750*);
struct Staticb7750 {
    void* value;
    Staticb7750() { construct(this, &descriptor); }
    ~Staticb7750() { destroy(this); }
};

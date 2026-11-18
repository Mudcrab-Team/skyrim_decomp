// Source exposure: binary-analysis
// Staticb9840, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9840;
extern void construct(Staticb9840*, const Descriptor*);
extern void destroy(Staticb9840*);
struct Staticb9840 {
    void* value;
    Staticb9840() { construct(this, &descriptor); }
    ~Staticb9840() { destroy(this); }
};

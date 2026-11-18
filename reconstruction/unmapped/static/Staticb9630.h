// Source exposure: binary-analysis
// Staticb9630, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9630;
extern void construct(Staticb9630*, const Descriptor*);
extern void destroy(Staticb9630*);
struct Staticb9630 {
    void* value;
    Staticb9630() { construct(this, &descriptor); }
    ~Staticb9630() { destroy(this); }
};

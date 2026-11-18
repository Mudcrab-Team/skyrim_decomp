// Source exposure: binary-analysis
// Staticb9300, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9300;
extern void construct(Staticb9300*, const Descriptor*);
extern void destroy(Staticb9300*);
struct Staticb9300 {
    void* value;
    Staticb9300() { construct(this, &descriptor); }
    ~Staticb9300() { destroy(this); }
};

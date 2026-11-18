// Source exposure: binary-analysis
// Staticb7120, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7120;
extern void construct(Staticb7120*, const Descriptor*);
extern void destroy(Staticb7120*);
struct Staticb7120 {
    void* value;
    Staticb7120() { construct(this, &descriptor); }
    ~Staticb7120() { destroy(this); }
};

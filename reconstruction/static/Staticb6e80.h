// Source exposure: binary-analysis
// Staticb6e80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6e80;
extern void construct(Staticb6e80*, const Descriptor*);
extern void destroy(Staticb6e80*);
struct Staticb6e80 {
    void* value;
    Staticb6e80() { construct(this, &descriptor); }
    ~Staticb6e80() { destroy(this); }
};

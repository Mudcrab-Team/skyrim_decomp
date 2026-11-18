// Source exposure: binary-analysis
// Staticb8e80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb8e80;
extern void construct(Staticb8e80*, const Descriptor*);
extern void destroy(Staticb8e80*);
struct Staticb8e80 {
    void* value;
    Staticb8e80() { construct(this, &descriptor); }
    ~Staticb8e80() { destroy(this); }
};

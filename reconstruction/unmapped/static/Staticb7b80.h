// Source exposure: binary-analysis
// Staticb7b80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7b80;
extern void construct(Staticb7b80*, const Descriptor*);
extern void destroy(Staticb7b80*);
struct Staticb7b80 {
    void* value;
    Staticb7b80() { construct(this, &descriptor); }
    ~Staticb7b80() { destroy(this); }
};

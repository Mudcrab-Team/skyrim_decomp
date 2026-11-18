// Source exposure: binary-analysis
// Staticb4c80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4c80;
extern void construct(Staticb4c80*, const Descriptor*);
extern void destroy(Staticb4c80*);
struct Staticb4c80 {
    void* value;
    Staticb4c80() { construct(this, &descriptor); }
    ~Staticb4c80() { destroy(this); }
};

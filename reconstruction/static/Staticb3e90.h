// Source exposure: binary-analysis
// Staticb3e90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb3e90;
extern void construct(Staticb3e90*, const Descriptor*);
extern void destroy(Staticb3e90*);
struct Staticb3e90 {
    void* value;
    Staticb3e90() { construct(this, &descriptor); }
    ~Staticb3e90() { destroy(this); }
};

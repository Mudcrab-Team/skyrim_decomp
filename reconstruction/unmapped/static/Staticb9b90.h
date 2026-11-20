// Source exposure: binary-analysis
// Staticb9b90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9b90;
extern void construct(Staticb9b90*, const Descriptor*);
extern void destroy(Staticb9b90*);
struct Staticb9b90 {
    void* value;
    Staticb9b90() { construct(this, &descriptor); }
    ~Staticb9b90() { destroy(this); }
};

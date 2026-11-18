// Source exposure: binary-analysis
// Staticb9b30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9b30;
extern void construct(Staticb9b30*, const Descriptor*);
extern void destroy(Staticb9b30*);
struct Staticb9b30 {
    void* value;
    Staticb9b30() { construct(this, &descriptor); }
    ~Staticb9b30() { destroy(this); }
};

// Source exposure: binary-analysis
// Staticb7a30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7a30;
extern void construct(Staticb7a30*, const Descriptor*);
extern void destroy(Staticb7a30*);
struct Staticb7a30 {
    void* value;
    Staticb7a30() { construct(this, &descriptor); }
    ~Staticb7a30() { destroy(this); }
};

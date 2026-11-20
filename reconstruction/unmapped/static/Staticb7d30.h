// Source exposure: binary-analysis
// Staticb7d30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7d30;
extern void construct(Staticb7d30*, const Descriptor*);
extern void destroy(Staticb7d30*);
struct Staticb7d30 {
    void* value;
    Staticb7d30() { construct(this, &descriptor); }
    ~Staticb7d30() { destroy(this); }
};

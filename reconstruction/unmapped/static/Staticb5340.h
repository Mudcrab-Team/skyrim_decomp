// Source exposure: binary-analysis
// Staticb5340, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5340;
extern void construct(Staticb5340*, const Descriptor*);
extern void destroy(Staticb5340*);
struct Staticb5340 {
    void* value;
    Staticb5340() { construct(this, &descriptor); }
    ~Staticb5340() { destroy(this); }
};

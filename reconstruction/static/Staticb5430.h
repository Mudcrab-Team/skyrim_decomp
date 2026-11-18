// Source exposure: binary-analysis
// Staticb5430, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5430;
extern void construct(Staticb5430*, const Descriptor*);
extern void destroy(Staticb5430*);
struct Staticb5430 {
    void* value;
    Staticb5430() { construct(this, &descriptor); }
    ~Staticb5430() { destroy(this); }
};

// Source exposure: binary-analysis
// Staticb9660, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9660;
extern void construct(Staticb9660*, const Descriptor*);
extern void destroy(Staticb9660*);
struct Staticb9660 {
    void* value;
    Staticb9660() { construct(this, &descriptor); }
    ~Staticb9660() { destroy(this); }
};

// Source exposure: binary-analysis
// Staticb7270, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7270;
extern void construct(Staticb7270*, const Descriptor*);
extern void destroy(Staticb7270*);
struct Staticb7270 {
    void* value;
    Staticb7270() { construct(this, &descriptor); }
    ~Staticb7270() { destroy(this); }
};

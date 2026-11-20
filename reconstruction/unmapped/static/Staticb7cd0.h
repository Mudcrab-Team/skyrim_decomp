// Source exposure: binary-analysis
// Staticb7cd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7cd0;
extern void construct(Staticb7cd0*, const Descriptor*);
extern void destroy(Staticb7cd0*);
struct Staticb7cd0 {
    void* value;
    Staticb7cd0() { construct(this, &descriptor); }
    ~Staticb7cd0() { destroy(this); }
};

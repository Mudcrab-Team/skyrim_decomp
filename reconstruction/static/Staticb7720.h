// Source exposure: binary-analysis
// Staticb7720, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7720;
extern void construct(Staticb7720*, const Descriptor*);
extern void destroy(Staticb7720*);
struct Staticb7720 {
    void* value;
    Staticb7720() { construct(this, &descriptor); }
    ~Staticb7720() { destroy(this); }
};

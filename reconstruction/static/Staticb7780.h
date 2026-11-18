// Source exposure: binary-analysis
// Staticb7780, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7780;
extern void construct(Staticb7780*, const Descriptor*);
extern void destroy(Staticb7780*);
struct Staticb7780 {
    void* value;
    Staticb7780() { construct(this, &descriptor); }
    ~Staticb7780() { destroy(this); }
};

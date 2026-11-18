// Source exposure: binary-analysis
// Staticb9780, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9780;
extern void construct(Staticb9780*, const Descriptor*);
extern void destroy(Staticb9780*);
struct Staticb9780 {
    void* value;
    Staticb9780() { construct(this, &descriptor); }
    ~Staticb9780() { destroy(this); }
};

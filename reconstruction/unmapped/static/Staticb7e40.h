// Source exposure: binary-analysis
// Staticb7e40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7e40;
extern void construct(Staticb7e40*, const Descriptor*);
extern void destroy(Staticb7e40*);
struct Staticb7e40 {
    void* value;
    Staticb7e40() { construct(this, &descriptor); }
    ~Staticb7e40() { destroy(this); }
};

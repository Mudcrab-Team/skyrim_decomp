// Source exposure: binary-analysis
// Staticb4d40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4d40;
extern void construct(Staticb4d40*, const Descriptor*);
extern void destroy(Staticb4d40*);
struct Staticb4d40 {
    void* value;
    Staticb4d40() { construct(this, &descriptor); }
    ~Staticb4d40() { destroy(this); }
};

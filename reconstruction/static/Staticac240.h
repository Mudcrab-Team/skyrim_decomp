// Source exposure: binary-analysis
// Staticac240, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticac240;
extern void construct(Staticac240*, const Descriptor*);
extern void destroy(Staticac240*);
struct Staticac240 {
    void* value;
    Staticac240() { construct(this, &descriptor); }
    ~Staticac240() { destroy(this); }
};

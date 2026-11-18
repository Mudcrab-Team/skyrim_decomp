// Source exposure: binary-analysis
// Staticb6740, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6740;
extern void construct(Staticb6740*, const Descriptor*);
extern void destroy(Staticb6740*);
struct Staticb6740 {
    void* value;
    Staticb6740() { construct(this, &descriptor); }
    ~Staticb6740() { destroy(this); }
};

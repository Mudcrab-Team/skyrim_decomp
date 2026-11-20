// Source exposure: binary-analysis
// Staticbd250, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbd250;
extern void construct(Staticbd250*, const Descriptor*);
extern void destroy(Staticbd250*);
struct Staticbd250 {
    void* value;
    Staticbd250() { construct(this, &descriptor); }
    ~Staticbd250() { destroy(this); }
};

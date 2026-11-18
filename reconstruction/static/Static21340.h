// Source exposure: binary-analysis
// Static21340, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21340;
extern void construct(Static21340*, const Descriptor*);
extern void destroy(Static21340*);
struct Static21340 {
    void* value;
    Static21340() { construct(this, &descriptor); }
    ~Static21340() { destroy(this); }
};

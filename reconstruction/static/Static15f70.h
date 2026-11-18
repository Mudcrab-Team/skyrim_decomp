// Source exposure: binary-analysis
// Static15f70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15f70;
extern void construct(Static15f70*, const Descriptor*);
extern void destroy(Static15f70*);
struct Static15f70 {
    void* value;
    Static15f70() { construct(this, &descriptor); }
    ~Static15f70() { destroy(this); }
};

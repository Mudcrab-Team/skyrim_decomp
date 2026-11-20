// Source exposure: binary-analysis
// Static15130, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15130;
extern void construct(Static15130*, const Descriptor*);
extern void destroy(Static15130*);
struct Static15130 {
    void* value;
    Static15130() { construct(this, &descriptor); }
    ~Static15130() { destroy(this); }
};

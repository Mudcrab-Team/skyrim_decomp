// Source exposure: binary-analysis
// Static15280, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15280;
extern void construct(Static15280*, const Descriptor*);
extern void destroy(Static15280*);
struct Static15280 {
    void* value;
    Static15280() { construct(this, &descriptor); }
    ~Static15280() { destroy(this); }
};

// Source exposure: binary-analysis
// Static23990, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23990;
extern void construct(Static23990*, const Descriptor*);
extern void destroy(Static23990*);
struct Static23990 {
    void* value;
    Static23990() { construct(this, &descriptor); }
    ~Static23990() { destroy(this); }
};

// Source exposure: binary-analysis
// Static87c10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static87c10;
extern void construct(Static87c10*, const Descriptor*);
extern void destroy(Static87c10*);
struct Static87c10 {
    void* value;
    Static87c10() { construct(this, &descriptor); }
    ~Static87c10() { destroy(this); }
};

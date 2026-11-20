// Source exposure: binary-analysis
// Static101110, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101110;
extern void construct(Static101110*, const Descriptor*);
extern void destroy(Static101110*);
struct Static101110 {
    void* value;
    Static101110() { construct(this, &descriptor); }
    ~Static101110() { destroy(this); }
};

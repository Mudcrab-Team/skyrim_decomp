// Source exposure: binary-analysis
// Static101170, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101170;
extern void construct(Static101170*, const Descriptor*);
extern void destroy(Static101170*);
struct Static101170 {
    void* value;
    Static101170() { construct(this, &descriptor); }
    ~Static101170() { destroy(this); }
};

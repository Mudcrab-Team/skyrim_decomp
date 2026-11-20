// Source exposure: binary-analysis
// Static24170, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24170;
extern void construct(Static24170*, const Descriptor*);
extern void destroy(Static24170*);
struct Static24170 {
    void* value;
    Static24170() { construct(this, &descriptor); }
    ~Static24170() { destroy(this); }
};

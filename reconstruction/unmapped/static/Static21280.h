// Source exposure: binary-analysis
// Static21280, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21280;
extern void construct(Static21280*, const Descriptor*);
extern void destroy(Static21280*);
struct Static21280 {
    void* value;
    Static21280() { construct(this, &descriptor); }
    ~Static21280() { destroy(this); }
};

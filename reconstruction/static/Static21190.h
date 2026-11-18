// Source exposure: binary-analysis
// Static21190, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21190;
extern void construct(Static21190*, const Descriptor*);
extern void destroy(Static21190*);
struct Static21190 {
    void* value;
    Static21190() { construct(this, &descriptor); }
    ~Static21190() { destroy(this); }
};

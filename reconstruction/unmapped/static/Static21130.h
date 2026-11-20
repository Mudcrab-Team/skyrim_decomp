// Source exposure: binary-analysis
// Static21130, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21130;
extern void construct(Static21130*, const Descriptor*);
extern void destroy(Static21130*);
struct Static21130 {
    void* value;
    Static21130() { construct(this, &descriptor); }
    ~Static21130() { destroy(this); }
};

// Source exposure: binary-analysis
// Static8b600, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b600;
extern void construct(Static8b600*, const Descriptor*);
extern void destroy(Static8b600*);
struct Static8b600 {
    void* value;
    Static8b600() { construct(this, &descriptor); }
    ~Static8b600() { destroy(this); }
};

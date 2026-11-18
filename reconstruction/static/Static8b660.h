// Source exposure: binary-analysis
// Static8b660, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b660;
extern void construct(Static8b660*, const Descriptor*);
extern void destroy(Static8b660*);
struct Static8b660 {
    void* value;
    Static8b660() { construct(this, &descriptor); }
    ~Static8b660() { destroy(this); }
};

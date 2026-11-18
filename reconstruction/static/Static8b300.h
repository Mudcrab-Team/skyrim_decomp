// Source exposure: binary-analysis
// Static8b300, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b300;
extern void construct(Static8b300*, const Descriptor*);
extern void destroy(Static8b300*);
struct Static8b300 {
    void* value;
    Static8b300() { construct(this, &descriptor); }
    ~Static8b300() { destroy(this); }
};

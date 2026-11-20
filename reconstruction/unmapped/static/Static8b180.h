// Source exposure: binary-analysis
// Static8b180, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b180;
extern void construct(Static8b180*, const Descriptor*);
extern void destroy(Static8b180*);
struct Static8b180 {
    void* value;
    Static8b180() { construct(this, &descriptor); }
    ~Static8b180() { destroy(this); }
};

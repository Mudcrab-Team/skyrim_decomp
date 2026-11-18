// Source exposure: binary-analysis
// Static8b750, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b750;
extern void construct(Static8b750*, const Descriptor*);
extern void destroy(Static8b750*);
struct Static8b750 {
    void* value;
    Static8b750() { construct(this, &descriptor); }
    ~Static8b750() { destroy(this); }
};

// Source exposure: binary-analysis
// Static8fd30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fd30;
extern void construct(Static8fd30*, const Descriptor*);
extern void destroy(Static8fd30*);
struct Static8fd30 {
    void* value;
    Static8fd30() { construct(this, &descriptor); }
    ~Static8fd30() { destroy(this); }
};

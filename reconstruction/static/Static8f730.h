// Source exposure: binary-analysis
// Static8f730, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f730;
extern void construct(Static8f730*, const Descriptor*);
extern void destroy(Static8f730*);
struct Static8f730 {
    void* value;
    Static8f730() { construct(this, &descriptor); }
    ~Static8f730() { destroy(this); }
};

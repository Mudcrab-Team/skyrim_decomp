// Source exposure: binary-analysis
// Static8f820, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f820;
extern void construct(Static8f820*, const Descriptor*);
extern void destroy(Static8f820*);
struct Static8f820 {
    void* value;
    Static8f820() { construct(this, &descriptor); }
    ~Static8f820() { destroy(this); }
};

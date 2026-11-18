// Source exposure: binary-analysis
// Static8fa30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fa30;
extern void construct(Static8fa30*, const Descriptor*);
extern void destroy(Static8fa30*);
struct Static8fa30 {
    void* value;
    Static8fa30() { construct(this, &descriptor); }
    ~Static8fa30() { destroy(this); }
};

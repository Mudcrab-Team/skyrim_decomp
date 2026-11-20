// Source exposure: binary-analysis
// Static8b240, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b240;
extern void construct(Static8b240*, const Descriptor*);
extern void destroy(Static8b240*);
struct Static8b240 {
    void* value;
    Static8b240() { construct(this, &descriptor); }
    ~Static8b240() { destroy(this); }
};

// Source exposure: binary-analysis
// Static8f760, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f760;
extern void construct(Static8f760*, const Descriptor*);
extern void destroy(Static8f760*);
struct Static8f760 {
    void* value;
    Static8f760() { construct(this, &descriptor); }
    ~Static8f760() { destroy(this); }
};

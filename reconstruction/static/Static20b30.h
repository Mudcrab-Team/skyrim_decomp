// Source exposure: binary-analysis
// Static20b30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20b30;
extern void construct(Static20b30*, const Descriptor*);
extern void destroy(Static20b30*);
struct Static20b30 {
    void* value;
    Static20b30() { construct(this, &descriptor); }
    ~Static20b30() { destroy(this); }
};

// Source exposure: binary-analysis
// Statice5490, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice5490;
extern void construct(Statice5490*, const Descriptor*);
extern void destroy(Statice5490*);
struct Statice5490 {
    void* value;
    Statice5490() { construct(this, &descriptor); }
    ~Statice5490() { destroy(this); }
};

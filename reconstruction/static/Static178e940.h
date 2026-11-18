// Source exposure: binary-analysis; no external implementation source reused.
// Static178e940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178e940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178e940*);
    virtual void release(Static178e940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178e940*);
struct Static178e940 {
    void* value;
    Static178e940();
    ~Static178e940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

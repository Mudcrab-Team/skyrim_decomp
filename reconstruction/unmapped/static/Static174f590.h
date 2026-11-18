// Source exposure: binary-analysis; no external implementation source reused.
// Static174f590, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f590;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f590*);
    virtual void release(Static174f590*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f590*);
struct Static174f590 {
    void* value;
    Static174f590();
    ~Static174f590() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

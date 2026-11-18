// Source exposure: binary-analysis; no external implementation source reused.
// Static176e940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e940*);
    virtual void release(Static176e940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e940*);
struct Static176e940 {
    void* value;
    Static176e940();
    ~Static176e940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

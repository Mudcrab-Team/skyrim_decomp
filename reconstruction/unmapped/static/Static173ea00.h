// Source exposure: binary-analysis; no external implementation source reused.
// Static173ea00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ea00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ea00*);
    virtual void release(Static173ea00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ea00*);
struct Static173ea00 {
    void* value;
    Static173ea00();
    ~Static173ea00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

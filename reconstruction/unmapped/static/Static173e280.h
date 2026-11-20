// Source exposure: binary-analysis; no external implementation source reused.
// Static173e280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e280*);
    virtual void release(Static173e280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e280*);
struct Static173e280 {
    void* value;
    Static173e280();
    ~Static173e280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

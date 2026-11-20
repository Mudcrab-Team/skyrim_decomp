// Source exposure: binary-analysis; no external implementation source reused.
// Static173cc40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cc40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cc40*);
    virtual void release(Static173cc40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cc40*);
struct Static173cc40 {
    void* value;
    Static173cc40();
    ~Static173cc40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

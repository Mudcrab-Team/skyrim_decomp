// Source exposure: binary-analysis; no external implementation source reused.
// Static176be70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176be70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176be70*);
    virtual void release(Static176be70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176be70*);
struct Static176be70 {
    void* value;
    Static176be70();
    ~Static176be70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

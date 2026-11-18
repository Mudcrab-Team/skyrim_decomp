// Source exposure: binary-analysis; no external implementation source reused.
// Static173f140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f140*);
    virtual void release(Static173f140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f140*);
struct Static173f140 {
    void* value;
    Static173f140();
    ~Static173f140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

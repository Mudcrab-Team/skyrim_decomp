// Source exposure: binary-analysis; no external implementation source reused.
// Static173d510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d510*);
    virtual void release(Static173d510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d510*);
struct Static173d510 {
    void* value;
    Static173d510();
    ~Static173d510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

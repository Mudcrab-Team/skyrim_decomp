// Source exposure: binary-analysis; no external implementation source reused.
// Static173ec90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ec90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ec90*);
    virtual void release(Static173ec90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ec90*);
struct Static173ec90 {
    void* value;
    Static173ec90();
    ~Static173ec90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static176cb90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176cb90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176cb90*);
    virtual void release(Static176cb90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176cb90*);
struct Static176cb90 {
    void* value;
    Static176cb90();
    ~Static176cb90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

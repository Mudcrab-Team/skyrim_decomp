// Source exposure: binary-analysis; no external implementation source reused.
// Static176da90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176da90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176da90*);
    virtual void release(Static176da90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176da90*);
struct Static176da90 {
    void* value;
    Static176da90();
    ~Static176da90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

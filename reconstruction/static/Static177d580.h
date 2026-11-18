// Source exposure: binary-analysis; no external implementation source reused.
// Static177d580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d580*);
    virtual void release(Static177d580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d580*);
struct Static177d580 {
    void* value;
    Static177d580();
    ~Static177d580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static177d120, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d120;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d120*);
    virtual void release(Static177d120*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d120*);
struct Static177d120 {
    void* value;
    Static177d120();
    ~Static177d120() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static177d800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d800*);
    virtual void release(Static177d800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d800*);
struct Static177d800 {
    void* value;
    Static177d800();
    ~Static177d800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

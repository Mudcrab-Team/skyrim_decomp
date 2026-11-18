// Source exposure: binary-analysis; no external implementation source reused.
// Static177b870, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b870;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b870*);
    virtual void release(Static177b870*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b870*);
struct Static177b870 {
    void* value;
    Static177b870();
    ~Static177b870() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

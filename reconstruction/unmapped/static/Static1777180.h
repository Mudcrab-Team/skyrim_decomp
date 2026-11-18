// Source exposure: binary-analysis; no external implementation source reused.
// Static1777180, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777180;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777180*);
    virtual void release(Static1777180*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777180*);
struct Static1777180 {
    void* value;
    Static1777180();
    ~Static1777180() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

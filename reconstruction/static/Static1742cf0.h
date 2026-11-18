// Source exposure: binary-analysis; no external implementation source reused.
// Static1742cf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742cf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742cf0*);
    virtual void release(Static1742cf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742cf0*);
struct Static1742cf0 {
    void* value;
    Static1742cf0();
    ~Static1742cf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

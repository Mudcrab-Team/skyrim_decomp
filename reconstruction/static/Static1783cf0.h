// Source exposure: binary-analysis; no external implementation source reused.
// Static1783cf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783cf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783cf0*);
    virtual void release(Static1783cf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783cf0*);
struct Static1783cf0 {
    void* value;
    Static1783cf0();
    ~Static1783cf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

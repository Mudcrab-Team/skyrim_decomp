// Source exposure: binary-analysis; no external implementation source reused.
// Static1742660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742660*);
    virtual void release(Static1742660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742660*);
struct Static1742660 {
    void* value;
    Static1742660();
    ~Static1742660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

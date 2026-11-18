// Source exposure: binary-analysis; no external implementation source reused.
// Static1770010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770010*);
    virtual void release(Static1770010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770010*);
struct Static1770010 {
    void* value;
    Static1770010();
    ~Static1770010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

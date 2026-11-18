// Source exposure: binary-analysis; no external implementation source reused.
// Static1799010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799010*);
    virtual void release(Static1799010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799010*);
struct Static1799010 {
    void* value;
    Static1799010();
    ~Static1799010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

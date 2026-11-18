// Source exposure: binary-analysis; no external implementation source reused.
// Static1770100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770100*);
    virtual void release(Static1770100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770100*);
struct Static1770100 {
    void* value;
    Static1770100();
    ~Static1770100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

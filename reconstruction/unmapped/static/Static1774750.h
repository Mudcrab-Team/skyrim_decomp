// Source exposure: binary-analysis; no external implementation source reused.
// Static1774750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774750*);
    virtual void release(Static1774750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774750*);
struct Static1774750 {
    void* value;
    Static1774750();
    ~Static1774750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

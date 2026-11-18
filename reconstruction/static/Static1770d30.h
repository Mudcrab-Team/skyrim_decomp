// Source exposure: binary-analysis; no external implementation source reused.
// Static1770d30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770d30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770d30*);
    virtual void release(Static1770d30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770d30*);
struct Static1770d30 {
    void* value;
    Static1770d30();
    ~Static1770d30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

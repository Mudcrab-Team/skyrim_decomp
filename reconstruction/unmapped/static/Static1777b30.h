// Source exposure: binary-analysis; no external implementation source reused.
// Static1777b30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777b30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777b30*);
    virtual void release(Static1777b30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777b30*);
struct Static1777b30 {
    void* value;
    Static1777b30();
    ~Static1777b30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

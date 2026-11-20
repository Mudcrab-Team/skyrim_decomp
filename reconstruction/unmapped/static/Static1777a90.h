// Source exposure: binary-analysis; no external implementation source reused.
// Static1777a90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777a90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777a90*);
    virtual void release(Static1777a90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777a90*);
struct Static1777a90 {
    void* value;
    Static1777a90();
    ~Static1777a90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

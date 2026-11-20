// Source exposure: binary-analysis; no external implementation source reused.
// Static1794d90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1794d90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1794d90*);
    virtual void release(Static1794d90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1794d90*);
struct Static1794d90 {
    void* value;
    Static1794d90();
    ~Static1794d90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

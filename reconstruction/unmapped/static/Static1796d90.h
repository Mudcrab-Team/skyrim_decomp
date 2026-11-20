// Source exposure: binary-analysis; no external implementation source reused.
// Static1796d90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796d90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796d90*);
    virtual void release(Static1796d90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796d90*);
struct Static1796d90 {
    void* value;
    Static1796d90();
    ~Static1796d90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

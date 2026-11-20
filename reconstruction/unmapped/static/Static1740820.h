// Source exposure: binary-analysis; no external implementation source reused.
// Static1740820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740820*);
    virtual void release(Static1740820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740820*);
struct Static1740820 {
    void* value;
    Static1740820();
    ~Static1740820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

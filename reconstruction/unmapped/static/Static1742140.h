// Source exposure: binary-analysis; no external implementation source reused.
// Static1742140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742140*);
    virtual void release(Static1742140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742140*);
struct Static1742140 {
    void* value;
    Static1742140();
    ~Static1742140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

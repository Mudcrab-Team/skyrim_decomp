// Source exposure: binary-analysis; no external implementation source reused.
// Static1770920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770920*);
    virtual void release(Static1770920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770920*);
struct Static1770920 {
    void* value;
    Static1770920();
    ~Static1770920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

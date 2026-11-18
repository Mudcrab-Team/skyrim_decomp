// Source exposure: binary-analysis; no external implementation source reused.
// Static1788e80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788e80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788e80*);
    virtual void release(Static1788e80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788e80*);
struct Static1788e80 {
    void* value;
    Static1788e80();
    ~Static1788e80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

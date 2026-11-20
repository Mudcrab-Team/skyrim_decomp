// Source exposure: binary-analysis; no external implementation source reused.
// Static1743e80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743e80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743e80*);
    virtual void release(Static1743e80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743e80*);
struct Static1743e80 {
    void* value;
    Static1743e80();
    ~Static1743e80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static1740d80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740d80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740d80*);
    virtual void release(Static1740d80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740d80*);
struct Static1740d80 {
    void* value;
    Static1740d80();
    ~Static1740d80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

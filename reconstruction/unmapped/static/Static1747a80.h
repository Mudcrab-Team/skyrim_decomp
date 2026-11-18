// Source exposure: binary-analysis; no external implementation source reused.
// Static1747a80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747a80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747a80*);
    virtual void release(Static1747a80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747a80*);
struct Static1747a80 {
    void* value;
    Static1747a80();
    ~Static1747a80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

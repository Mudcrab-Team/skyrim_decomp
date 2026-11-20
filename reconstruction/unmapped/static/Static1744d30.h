// Source exposure: binary-analysis; no external implementation source reused.
// Static1744d30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744d30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744d30*);
    virtual void release(Static1744d30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744d30*);
struct Static1744d30 {
    void* value;
    Static1744d30();
    ~Static1744d30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

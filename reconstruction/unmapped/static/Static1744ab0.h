// Source exposure: binary-analysis; no external implementation source reused.
// Static1744ab0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744ab0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744ab0*);
    virtual void release(Static1744ab0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744ab0*);
struct Static1744ab0 {
    void* value;
    Static1744ab0();
    ~Static1744ab0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

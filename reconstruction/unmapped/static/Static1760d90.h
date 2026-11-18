// Source exposure: binary-analysis; no external implementation source reused.
// Static1760d90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760d90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760d90*);
    virtual void release(Static1760d90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760d90*);
struct Static1760d90 {
    void* value;
    Static1760d90();
    ~Static1760d90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

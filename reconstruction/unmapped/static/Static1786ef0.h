// Source exposure: binary-analysis; no external implementation source reused.
// Static1786ef0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786ef0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786ef0*);
    virtual void release(Static1786ef0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786ef0*);
struct Static1786ef0 {
    void* value;
    Static1786ef0();
    ~Static1786ef0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

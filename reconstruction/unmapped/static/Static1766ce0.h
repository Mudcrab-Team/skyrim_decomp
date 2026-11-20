// Source exposure: binary-analysis; no external implementation source reused.
// Static1766ce0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766ce0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766ce0*);
    virtual void release(Static1766ce0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766ce0*);
struct Static1766ce0 {
    void* value;
    Static1766ce0();
    ~Static1766ce0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

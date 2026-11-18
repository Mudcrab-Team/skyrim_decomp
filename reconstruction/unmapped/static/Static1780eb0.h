// Source exposure: binary-analysis; no external implementation source reused.
// Static1780eb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780eb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780eb0*);
    virtual void release(Static1780eb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780eb0*);
struct Static1780eb0 {
    void* value;
    Static1780eb0();
    ~Static1780eb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

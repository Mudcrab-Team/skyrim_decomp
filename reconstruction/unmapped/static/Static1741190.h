// Source exposure: binary-analysis; no external implementation source reused.
// Static1741190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741190*);
    virtual void release(Static1741190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741190*);
struct Static1741190 {
    void* value;
    Static1741190();
    ~Static1741190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

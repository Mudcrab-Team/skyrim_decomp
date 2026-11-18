// Source exposure: binary-analysis; no external implementation source reused.
// Static1771500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771500*);
    virtual void release(Static1771500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771500*);
struct Static1771500 {
    void* value;
    Static1771500();
    ~Static1771500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

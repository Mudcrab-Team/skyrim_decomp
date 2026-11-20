// Source exposure: binary-analysis; no external implementation source reused.
// Static1780140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780140*);
    virtual void release(Static1780140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780140*);
struct Static1780140 {
    void* value;
    Static1780140();
    ~Static1780140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

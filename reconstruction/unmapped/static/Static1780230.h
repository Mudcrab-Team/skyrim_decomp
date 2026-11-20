// Source exposure: binary-analysis; no external implementation source reused.
// Static1780230, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780230;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780230*);
    virtual void release(Static1780230*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780230*);
struct Static1780230 {
    void* value;
    Static1780230();
    ~Static1780230() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

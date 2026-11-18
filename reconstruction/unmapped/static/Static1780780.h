// Source exposure: binary-analysis; no external implementation source reused.
// Static1780780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780780*);
    virtual void release(Static1780780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780780*);
struct Static1780780 {
    void* value;
    Static1780780();
    ~Static1780780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

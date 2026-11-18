// Source exposure: binary-analysis; no external implementation source reused.
// Static1780960, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780960;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780960*);
    virtual void release(Static1780960*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780960*);
struct Static1780960 {
    void* value;
    Static1780960();
    ~Static1780960() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

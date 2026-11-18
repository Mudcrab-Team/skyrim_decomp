// Source exposure: binary-analysis; no external implementation source reused.
// Static1793960, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1793960;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1793960*);
    virtual void release(Static1793960*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1793960*);
struct Static1793960 {
    void* value;
    Static1793960();
    ~Static1793960() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

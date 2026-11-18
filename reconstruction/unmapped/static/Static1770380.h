// Source exposure: binary-analysis; no external implementation source reused.
// Static1770380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770380*);
    virtual void release(Static1770380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770380*);
struct Static1770380 {
    void* value;
    Static1770380();
    ~Static1770380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

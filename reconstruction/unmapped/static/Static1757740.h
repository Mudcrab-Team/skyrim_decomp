// Source exposure: binary-analysis; no external implementation source reused.
// Static1757740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757740*);
    virtual void release(Static1757740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757740*);
struct Static1757740 {
    void* value;
    Static1757740();
    ~Static1757740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

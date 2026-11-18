// Source exposure: binary-analysis; no external implementation source reused.
// Static1785780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785780*);
    virtual void release(Static1785780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785780*);
struct Static1785780 {
    void* value;
    Static1785780();
    ~Static1785780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

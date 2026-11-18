// Source exposure: binary-analysis; no external implementation source reused.
// Static1771780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771780*);
    virtual void release(Static1771780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771780*);
struct Static1771780 {
    void* value;
    Static1771780();
    ~Static1771780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

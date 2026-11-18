// Source exposure: binary-analysis; no external implementation source reused.
// Static1773a30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773a30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773a30*);
    virtual void release(Static1773a30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773a30*);
struct Static1773a30 {
    void* value;
    Static1773a30();
    ~Static1773a30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

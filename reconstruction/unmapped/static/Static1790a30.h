// Source exposure: binary-analysis; no external implementation source reused.
// Static1790a30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790a30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790a30*);
    virtual void release(Static1790a30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790a30*);
struct Static1790a30 {
    void* value;
    Static1790a30();
    ~Static1790a30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

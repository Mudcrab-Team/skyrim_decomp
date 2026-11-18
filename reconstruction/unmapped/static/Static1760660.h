// Source exposure: binary-analysis; no external implementation source reused.
// Static1760660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760660*);
    virtual void release(Static1760660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760660*);
struct Static1760660 {
    void* value;
    Static1760660();
    ~Static1760660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static1747660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747660*);
    virtual void release(Static1747660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747660*);
struct Static1747660 {
    void* value;
    Static1747660();
    ~Static1747660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

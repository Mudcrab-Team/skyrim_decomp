// Source exposure: binary-analysis; no external implementation source reused.
// Static1782a30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782a30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782a30*);
    virtual void release(Static1782a30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782a30*);
struct Static1782a30 {
    void* value;
    Static1782a30();
    ~Static1782a30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

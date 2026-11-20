// Source exposure: binary-analysis; no external implementation source reused.
// Static1786860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786860*);
    virtual void release(Static1786860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786860*);
struct Static1786860 {
    void* value;
    Static1786860();
    ~Static1786860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

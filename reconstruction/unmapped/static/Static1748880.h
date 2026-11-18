// Source exposure: binary-analysis; no external implementation source reused.
// Static1748880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1748880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1748880*);
    virtual void release(Static1748880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1748880*);
struct Static1748880 {
    void* value;
    Static1748880();
    ~Static1748880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

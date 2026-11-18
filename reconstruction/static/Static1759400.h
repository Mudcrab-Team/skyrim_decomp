// Source exposure: binary-analysis; no external implementation source reused.
// Static1759400, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759400;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759400*);
    virtual void release(Static1759400*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759400*);
struct Static1759400 {
    void* value;
    Static1759400();
    ~Static1759400() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

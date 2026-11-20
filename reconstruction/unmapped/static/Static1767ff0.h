// Source exposure: binary-analysis; no external implementation source reused.
// Static1767ff0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767ff0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767ff0*);
    virtual void release(Static1767ff0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767ff0*);
struct Static1767ff0 {
    void* value;
    Static1767ff0();
    ~Static1767ff0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static1767af0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767af0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767af0*);
    virtual void release(Static1767af0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767af0*);
struct Static1767af0 {
    void* value;
    Static1767af0();
    ~Static1767af0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

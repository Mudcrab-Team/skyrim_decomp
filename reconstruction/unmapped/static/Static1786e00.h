// Source exposure: binary-analysis; no external implementation source reused.
// Static1786e00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786e00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786e00*);
    virtual void release(Static1786e00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786e00*);
struct Static1786e00 {
    void* value;
    Static1786e00();
    ~Static1786e00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

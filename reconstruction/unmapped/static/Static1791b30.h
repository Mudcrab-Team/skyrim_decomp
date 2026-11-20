// Source exposure: binary-analysis; no external implementation source reused.
// Static1791b30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1791b30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1791b30*);
    virtual void release(Static1791b30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1791b30*);
struct Static1791b30 {
    void* value;
    Static1791b30();
    ~Static1791b30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

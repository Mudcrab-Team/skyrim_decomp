// Source exposure: binary-analysis; no external implementation source reused.
// Static1744100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744100*);
    virtual void release(Static1744100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744100*);
struct Static1744100 {
    void* value;
    Static1744100();
    ~Static1744100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

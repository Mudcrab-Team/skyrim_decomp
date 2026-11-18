// Source exposure: binary-analysis; no external implementation source reused.
// Static1799100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799100*);
    virtual void release(Static1799100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799100*);
struct Static1799100 {
    void* value;
    Static1799100();
    ~Static1799100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static1781d10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781d10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781d10*);
    virtual void release(Static1781d10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781d10*);
struct Static1781d10 {
    void* value;
    Static1781d10();
    ~Static1781d10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

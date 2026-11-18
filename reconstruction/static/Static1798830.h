// Source exposure: binary-analysis; no external implementation source reused.
// Static1798830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1798830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1798830*);
    virtual void release(Static1798830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1798830*);
struct Static1798830 {
    void* value;
    Static1798830();
    ~Static1798830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

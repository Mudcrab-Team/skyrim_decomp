// Source exposure: binary-analysis; no external implementation source reused.
// Static1799060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799060*);
    virtual void release(Static1799060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799060*);
struct Static1799060 {
    void* value;
    Static1799060();
    ~Static1799060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

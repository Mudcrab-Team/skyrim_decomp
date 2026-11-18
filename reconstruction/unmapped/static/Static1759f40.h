// Source exposure: binary-analysis; no external implementation source reused.
// Static1759f40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759f40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759f40*);
    virtual void release(Static1759f40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759f40*);
struct Static1759f40 {
    void* value;
    Static1759f40();
    ~Static1759f40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

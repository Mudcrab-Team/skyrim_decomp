// Source exposure: binary-analysis; no external implementation source reused.
// Static1787490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787490*);
    virtual void release(Static1787490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787490*);
struct Static1787490 {
    void* value;
    Static1787490();
    ~Static1787490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

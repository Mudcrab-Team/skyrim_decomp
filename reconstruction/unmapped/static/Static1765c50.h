// Source exposure: binary-analysis; no external implementation source reused.
// Static1765c50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765c50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765c50*);
    virtual void release(Static1765c50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765c50*);
struct Static1765c50 {
    void* value;
    Static1765c50();
    ~Static1765c50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

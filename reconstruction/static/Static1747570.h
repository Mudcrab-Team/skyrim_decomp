// Source exposure: binary-analysis; no external implementation source reused.
// Static1747570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747570*);
    virtual void release(Static1747570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747570*);
struct Static1747570 {
    void* value;
    Static1747570();
    ~Static1747570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

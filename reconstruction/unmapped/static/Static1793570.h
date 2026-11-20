// Source exposure: binary-analysis; no external implementation source reused.
// Static1793570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1793570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1793570*);
    virtual void release(Static1793570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1793570*);
struct Static1793570 {
    void* value;
    Static1793570();
    ~Static1793570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

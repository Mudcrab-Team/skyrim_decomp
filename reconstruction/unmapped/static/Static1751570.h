// Source exposure: binary-analysis; no external implementation source reused.
// Static1751570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751570*);
    virtual void release(Static1751570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751570*);
struct Static1751570 {
    void* value;
    Static1751570();
    ~Static1751570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

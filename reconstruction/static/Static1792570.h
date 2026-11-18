// Source exposure: binary-analysis; no external implementation source reused.
// Static1792570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1792570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1792570*);
    virtual void release(Static1792570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1792570*);
struct Static1792570 {
    void* value;
    Static1792570();
    ~Static1792570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

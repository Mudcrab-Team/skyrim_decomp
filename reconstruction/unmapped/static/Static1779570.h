// Source exposure: binary-analysis; no external implementation source reused.
// Static1779570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779570*);
    virtual void release(Static1779570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779570*);
struct Static1779570 {
    void* value;
    Static1779570();
    ~Static1779570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

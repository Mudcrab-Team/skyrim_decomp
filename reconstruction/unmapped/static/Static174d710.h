// Source exposure: binary-analysis; no external implementation source reused.
// Static174d710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d710*);
    virtual void release(Static174d710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d710*);
struct Static174d710 {
    void* value;
    Static174d710();
    ~Static174d710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

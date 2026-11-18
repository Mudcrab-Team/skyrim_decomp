// Source exposure: binary-analysis; no external implementation source reused.
// Static177d710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d710*);
    virtual void release(Static177d710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d710*);
struct Static177d710 {
    void* value;
    Static177d710();
    ~Static177d710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

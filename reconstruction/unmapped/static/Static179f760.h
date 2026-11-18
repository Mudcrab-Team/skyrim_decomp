// Source exposure: binary-analysis; no external implementation source reused.
// Static179f760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f760*);
    virtual void release(Static179f760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f760*);
struct Static179f760 {
    void* value;
    Static179f760();
    ~Static179f760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

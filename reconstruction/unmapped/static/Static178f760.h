// Source exposure: binary-analysis; no external implementation source reused.
// Static178f760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f760*);
    virtual void release(Static178f760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f760*);
struct Static178f760 {
    void* value;
    Static178f760();
    ~Static178f760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

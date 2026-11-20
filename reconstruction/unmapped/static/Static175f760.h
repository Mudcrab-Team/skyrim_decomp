// Source exposure: binary-analysis; no external implementation source reused.
// Static175f760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f760*);
    virtual void release(Static175f760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f760*);
struct Static175f760 {
    void* value;
    Static175f760();
    ~Static175f760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

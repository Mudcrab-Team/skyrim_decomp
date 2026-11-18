// Source exposure: binary-analysis; no external implementation source reused.
// Static1798560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1798560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1798560*);
    virtual void release(Static1798560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1798560*);
struct Static1798560 {
    void* value;
    Static1798560();
    ~Static1798560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

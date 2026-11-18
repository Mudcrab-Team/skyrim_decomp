// Source exposure: binary-analysis; no external implementation source reused.
// Static1746990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746990*);
    virtual void release(Static1746990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746990*);
struct Static1746990 {
    void* value;
    Static1746990();
    ~Static1746990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

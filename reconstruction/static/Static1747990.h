// Source exposure: binary-analysis; no external implementation source reused.
// Static1747990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747990*);
    virtual void release(Static1747990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747990*);
struct Static1747990 {
    void* value;
    Static1747990();
    ~Static1747990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
